
#include "tcpclient.h"
#include "ui_tcpclient.h"
#include<QMessageBox>
TcpClient::TcpClient(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TcpClient)
{
    ui->setupUi(this);
    setFixedSize(350,180);

    //文件校验所需要的数据初始化
    TotalBytes = 0;
    bytesReceived=0;
    fileNameSize =0;
    blockSize=0;
    //tcp通信所需要的socket初始化
    tcpPort=6666;
    tcpClient = new QTcpSocket(this);
    //这里对变量进行了初始化，并创建了QTcpServer对象，然后关联了信号和槽
    connect(tcpClient,&QTcpSocket::readyRead,this,&TcpClient::readMessage);
    connect(tcpClient,SIGNAL(error(QAbstractSocket::SocketError)),
            this,SLOT(displayError(QAbstractSocket::SocketError)));
}

TcpClient::~TcpClient()
{
    delete ui;
}

void TcpClient::setFileName(QString fileName)
{
    /*因为要在主界面Widget类中弹出文件对话框来选择发送过来文件的保存路径，
     * 所以要在客户端类中提供函数来获取该路径，这是由setFileName()函数来完成的，
     * 下面添加该函数的定义
    */
    localFile= new QFile(fileName);
}

void TcpClient::setHostAddress(QHostAddress address)
{
    hostAddress = address;
    newConnect();
}

void TcpClient::readMessage()
{
    QDataStream in(tcpClient);
    float useTime = time.elapsed();
    if(bytesReceived <= sizeof(qint64)*2){
        if((tcpClient->bytesAvailable()>=sizeof(qint64)*2)&&(fileNameSize==0)){
            in >>TotalBytes>>fileNameSize;
            bytesReceived+=sizeof(qint64)*2;
        }
        if((tcpClient->bytesAvailable()>=fileNameSize)&&(fileNameSize!=0)){
            in>>fileName;
            bytesReceived+=fileNameSize;
            if(!localFile->open(QFile::WriteOnly)){
                QMessageBox::warning(this,tr("应用程序"),tr("无法读取文件 %1:\n%2.")
                                                               .arg(fileName)
                                                               .arg(localFile->errorString()));
                return ;

            }


        }else{
            return;
        }


    }
    if(bytesReceived<TotalBytes){
        bytesReceived+=tcpClient->bytesAvailable();
        inBlock=tcpClient->readAll();
        localFile->write(inBlock);
        inBlock.resize(0);
    }
    ui->progressBar->setMaximum(TotalBytes);
    ui->progressBar->setValue(bytesReceived);

    double speed = bytesReceived / useTime;
    ui->tcpClientStatusLabel->setText(tr("已接收 %1MB( %2MB/s)"
                                         "\n共%3MB 已用时:%4秒\n估计剩余时间:%5秒")
                                          .arg(bytesReceived / (1024*1024))
                                          .arg(speed *1000/(1024*1024),0,'f',2)
                                          .arg(TotalBytes / (1024*1024))
                                          .arg(useTime/1000,0,'f',0)
                                          .arg(TotalBytes/speed/1000 - useTime/1000,0,'f',0 ));


    if(bytesReceived == TotalBytes)
    {
        localFile ->close();
        tcpClient->close();
        ui->tcpClientStatusLabel->setText(tr("接收文件: %1完毕").arg(fileName));

    }
}

void TcpClient::displayError(QAbstractSocket::SocketError sockError)
{
    switch (sockError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    default:
        qDebug() << tcpClient->errorString();
    }
}

void TcpClient::newConnect()
{

    blockSize=0;
    tcpClient->abort();  //abort 终止,堕胎
    tcpClient->connectToHost(hostAddress,tcpPort);
    time.start();


}

void TcpClient::on_tcpClientCancleBtn_clicked()
{
    tcpClient->abort();
    if(localFile->isOpen()){
        localFile->close();

    }
    close();
    ui->~TcpClient();
}


void TcpClient::on_tcpClientCloseBtn_clicked()
{
    on_tcpClientCancleBtn_clicked();
}
void TcpClient::closeEvent(QCloseEvent *)
{
    on_tcpClientCloseBtn_clicked();
}

