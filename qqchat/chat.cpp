#include "chat.h"
#include "ui_chat.h"
#include<QDateTime>
#include<QtNetwork/QHostInfo>
#include<QMessageBox>
#include<QScrollBar>
#include<QtNetwork/QNetworkInterface>
#include<QProcess>
#include<QHostInfo>
#include<tcpclient.h>
#include<tcpserver.h>
#include<QFileDialog>
#include<QColorDialog>
#include<QMessageBox>
#include<QTextStream>>
chat::chat(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::chat)
{
    ui->setupUi(this);

    ui->messageTextEdit->setFocusPolicy(Qt::StrongFocus);
    ui->messageBrower->setFocusPolicy(Qt::NoFocus);
    ui->messageTextEdit->setFocus();
    ui->messageTextEdit->installEventFilter(this);

    server = new TcpServer(this);

    udpSocket = new QUdpSocket(this);
    port=45454;

    udpSocket->bind(port,QAbstractSocket::ShareAddress|QUdpSocket::ReuseAddressHint);

    connect(udpSocket,&QUdpSocket::readyRead,this,&chat::processPendingDatagrams);
    sendMessage(newParticipant);

    connect(server,SIGNAL(sendFileName(QString)),this,SLOT(getFileName(QString)));
}

chat::~chat()
{
    delete ui;
}

void chat::NewParticipant(QString userName, QString localHostName, QString ipAddress)
{
    bool isEmpty = ui->userTableWidget
                       ->findItems(localHostName,Qt::MatchExactly).isEmpty();
    qDebug() <<"返回的消息";
    if(isEmpty){
        QTableWidgetItem *user = new QTableWidgetItem(userName);
        QTableWidgetItem *ip = new QTableWidgetItem(ipAddress);
        QTableWidgetItem *host = new QTableWidgetItem(localHostName);

        ui->userTableWidget->insertRow(0);
        ui->userTableWidget->setItem(0,0,user);
        ui->userTableWidget->setItem(0,1,host);
        ui->userTableWidget->setItem(0,2,ip);

        ui->messageBrower->setTextColor(Qt::gray);
        ui->messageBrower->setCurrentFont(QFont("Times New Roman",10));
        ui->messageBrower->append(tr("%1在线人数").arg(userName));

        ui->userNumLabel->setText(tr("在线人数: %1").arg(ui->userTableWidget->rowCount()));

        sendMessage(newParticipant);
    }


}

void chat::LeftParticipant(QString userName, QString localHostName, QString time)
{
    int rowNum = ui->userTableWidget->findItems(localHostName,Qt::MatchExactly).first()->row();

    ui->userTableWidget->removeRow(rowNum);
    ui->messageBrower->setTextColor(Qt::gray);
    ui->messageBrower->setCurrentFont(QFont("Times New Roman",10));
    ui->messageBrower->append(tr("%1于%2离开!").arg(userName).arg(time));
    ui->userNumLabel->setText(tr("在线人数:%1")
                                  .arg(ui->userTableWidget->rowCount()));
}

void chat::sendMessage(messageType type, QString serverAddress)
{
    qDebug() << "进入了sendMessage";
    QByteArray datas;
    QDataStream out(&datas,QIODevice::WriteOnly);
    QString localHostName,ipaddress;
    QString message;
    localHostName = QHostInfo::localHostName();
    qDebug()<<"在sendMessage中使用了QHostInfo::localHostName(),获取了localHostName,为: " << localHostName;
    ipaddress = getIP();
    out<<type<<getUserName()<<localHostName;
    switch (type){
    case Message:
    {
        if(ui->messageTextEdit->toPlainText()==""){
            QMessageBox::warning(0,tr("警告"),
                                 tr("所发送内容不能为空"),QMessageBox::Ok);
            return;
        }
        message=getMessage();
        out<<ipaddress<<message;

        ui->messageBrower->verticalScrollBar()
            ->setValue(ui->messageBrower->verticalScrollBar()->maximum());
       break;
    }
    case newParticipant:
    {

        out<<ipaddress;
        qDebug() << "进入了SendMessage中的newparticipant语句 ,且知道其ip为:"<<ipaddress;

        break;
    }
    case leftParticipant:

        break;
    case Refuse:
        out<<serverAddress;
        break;
    case FileName:
        int row = ui->userTableWidget->currentRow();        //这里必须先在用户列表中选择一个用户来接收文件，然后弹出发送端界面。
        QString clientAddress = ui->userTableWidget->item(row,2)->text();
        out<< ipaddress<< clientAddress<<fileName;
        break;
    }
    udpSocket->writeDatagram(datas,datas.length(),QHostAddress::Broadcast,port);
}

void chat::hasPendingFile(QString userName, QString serverAddress, QString clientAddress, QString fileName)
{
    QString  ipAddress = getIP();
    if(clientAddress  == ipAddress)
    {
        int btn = QMessageBox::information(this,tr("接收文件"),
                                           tr("来自 %1 (%2)的文件:%3","是否接受")
                                               .arg(userName)
                                               .arg(serverAddress).arg(fileName),
                                           QMessageBox::Yes,QMessageBox::No);
        if(btn == QMessageBox::Yes)
        {
            QString name = QFileDialog::getSaveFileName(0,tr("保存文件"),fileName);
            if(!name.isEmpty())
            {
                TcpClient *client = new TcpClient(this);
                client->setFileName(name);
                client->setHostAddress(QHostAddress(serverAddress));
                client->show();
                qDebug() << "客户端已创建与服务端的链接" ;

            }
        }
        else if(btn == QMessageBox::No){
            sendMessage(Refuse,serverAddress);
            qDebug() << "severAddress:"<<serverAddress;
        }
    }
}

bool chat::saveFile(const QString &file)
{
    QFile files(file);
    if(!files.open(QFile::WriteOnly|QFile::Text)){
        QMessageBox::warning(this,tr("保存文件"),
                             tr("无法保存文件%1:\n%2").arg(fileName).arg(files.errorString()));
        return false;
    }
    QTextStream out(&files);
    out<<ui->messageBrower->toPlainText();
    return true;
}

void chat::closeEvent(QCloseEvent *e)
{
    sendMessage(leftParticipant);
    QWidget::closeEvent(e);
}

QString chat::getIP()
{
    QList<QHostAddress>list = QNetworkInterface::allAddresses();
    foreach(QHostAddress address,list){
        if(address.protocol() == QHostAddress::IPv4Protocol){
            qDebug()<<"调用了getIP : "<< address.toString();
            return address.toString();
        }
    }
    return 0;
}

QString chat::getUserName()
{
    QStringList envVariables;
    envVariables<<"USERNAME.*"<<"USER.*"<<"USERDOMAIN.*"
                 <<"HOSTNAME.*"<<"DOMAINNAME.*";
    QStringList environment = QProcess::systemEnvironment();
    foreach(QString string,envVariables){
        int  index = environment.indexOf(QRegularExpression(string));
        if(index!=-1){
            QStringList stringList = environment.at(index).split('=');
            if(stringList.size()==2){
                qDebug()<<"调用了getUserName,且获得了username,为: " <<stringList.at(1);
                return stringList.at(1);
                break;
            }

        }

    }
    return "unknow";
}

QString chat::getMessage()
{
    QString msg=ui->messageTextEdit->toHtml();
    ui->messageTextEdit->clear();
    ui->messageTextEdit->setFocus();
    return msg;
}



void chat::processPendingDatagrams()
{
    while(udpSocket->hasPendingDatagrams()){
        qDebug()<<"我们进入了chat::processPendingDatagrams(),且udpsocket接收到了数据了"  ;
    QByteArray datagram;
    port=45454;
    QString localHostName,ipaddress,userName,textData,time;
    datagram.resize(udpSocket->pendingDatagramSize());
    udpSocket->readDatagram(datagram.data(),datagram.length());

    QDataStream in(&datagram,QIODevice::ReadOnly);
    time= QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    int message;
    in>>message;
    qDebug()<<"processPendingDatagrams中接收到的message为: "<<message;
    switch (message) {
    case Message:
        in>>userName>>localHostName>>ipaddress>>textData;
        ui->messageBrower->setTextColor(Qt::blue);
        ui->messageBrower->setCurrentFont(QFont());
        ui->messageBrower->append("["+userName+"]"+time);
        ui->messageBrower->append(textData);
        break;
    case newParticipant:
        in>>userName>>localHostName>>ipaddress;
        qDebug()<<"我们进入了chat::processPendingDatagrams中的newparticipant情况,且其传入的数据为"<<userName
                 <<localHostName<<ipaddress;
        NewParticipant(userName,localHostName,ipaddress);  //如果message类型是New
        break;
    case leftParticipant:
        LeftParticipant(userName,localHostName,ipaddress);
        break;
    case Refuse:
    {
        in >>userName >> localHostName;
        QString serverAddress;
        in >>serverAddress;
        if(getIP() == serverAddress)
        {
            server->refused();;
        }
        break;


    }

    case FileName:
    {
        in>>userName>>localHostName>>ipaddress;
        QString clientAddress,fileName;
        in>>clientAddress>>fileName;
        hasPendingFile(userName,ipaddress,clientAddress,fileName);
        break;
    }
    }
    }
}

void chat::on_sendPushButton_clicked()
{
    sendMessage(Message);
}

void chat::getFileName(QString name)
{
    //这里获取了文件名，然后发送FileName类型的UDP广播。
    fileName = name;
    sendMessage(FileName);
}


void chat::on_sendToolBtn_clicked()
{
    if(ui->userTableWidget->selectedItems().isEmpty()){
        QMessageBox::warning(0,tr("选择用户"),
                             tr("请先从用户列表选择要传输的用户!"),QMessageBox::Ok);
        return;

    }
    server->show();
    server->initServer();

}


void chat::on_boldToolBtn_clicked()
{
    if(Qt::Checked){
        ui->messageTextEdit->setFontWeight(QFont::Bold);
    }else
        ui->messageTextEdit->setFontWeight(QFont::Normal);
    ui->messageTextEdit->setFocus();
}


void chat::on_italicToolBtn_clicked()
{
    if(Qt::Checked){
        ui->messageTextEdit->setFontItalic(true);
    }else
        ui->messageTextEdit->setFontItalic(false);
    ui->messageTextEdit->setFocus();
}





void chat::on_colorToolBtn_clicked()
{
    color = QColorDialog::getColor(color,this);
    if(color.isValid()){
        ui->messageTextEdit->setTextColor(color);
        ui->messageTextEdit->setFocus();
    }
}


void chat::on_fontComboBox_currentFontChanged(const QFont &f)
{
    qDebug()<<"has enter on_fontComboBox_currentFontChanged";
    ui->messageTextEdit->setCurrentFont(f);
    ui->messageTextEdit->setFocus();
}


void chat::on_sizeComboBox_currentIndexChanged(int index)
{
    qDebug()<<"has enter on_sizeComboBox_currentIndexChanged";
    ui->messageTextEdit->setFontPointSize(index);
    ui->messageTextEdit->setFocus();
}


void chat::on_underlineToolBtn_clicked()
{
    if(Qt::Checked){
        ui->messageTextEdit->setFontUnderline(true);
    }else
         ui->messageTextEdit->setFontUnderline(false);
    ui->messageTextEdit->setFocus();
}





void chat::on_saveToolBtn_clicked()
{
    if(ui->messageBrower->document()->isEmpty()){
        QMessageBox::warning(0,tr("警告"),
                             tr("聊天记录为空,无法保存"),QMessageBox::Ok);
    }else{
        QString fileName = QFileDialog::getSaveFileName(this,
                                                        tr("保存聊天记录"),tr("聊天记录"),tr("文本(*.txt);;ALL FILE(*.*)"));
        if(!fileName.isEmpty())
            saveFile(fileName);
    }
}


void chat::on_clearToolBtn_clicked()
{
    ui->messageBrower->clear();
}


void chat::on_exitPushButton_clicked()
{
    close();
}

