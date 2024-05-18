#include "tcpserver.h"
#include "ui_tcpserver.h"
#include<QHostInfo>
#include<QMessageBox>
#include<QDateTime>
#include<QProcess>
#include<QDataStream>
#include<QScrollBar>
#include<QFont>
#include<QNetworkInterface>
#include<QStringList>
#include<QDebug>
#include<QApplication>
#include<QElapsedTimer>
#include<QtNetwork/QTcpSocket>
#include<qtcpsocket.h>
#include<QFileDialog>
TcpServer::TcpServer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TcpServer)
{
    ui->setupUi(this);
    setFixedSize(350,180);

    tcpPort = 6666;
    tcpServer = new QTcpServer(this);
    connect(tcpServer,&QTcpServer::newConnection,this,&TcpServer::sendMessage);

    initServer();
}

TcpServer::~TcpServer()
{
    delete ui;
}

void TcpServer::initServer()
{
    payloadSize = 64*1024;
    TotalBytes =0;
    bytesWritten=0;
    bytestoWrite=0;
    ui->progressBar->reset();
    ui->serverOpenBtn->setEnabled(true);
    ui->serverSendBtn->setEnabled(false);  //设置一开始是否能被选中
    tcpServer->close();
}

void TcpServer::refused()
{
    tcpServer->close();
    ui->serverStatusLabel->setText(tr("对方拒绝接收!!!"));
}

void TcpServer::closeEvent(QCloseEvent *)
{
    on_serverCloseBtn_clicked();
}

void TcpServer::sendMessage()
{
    //对按钮的初始化,如果触发了sendmessage函数,则ui中的send按钮就不能用了
    ui->serverSendBtn->setEnabled(false);
    //接着我们要对所连接的套接字进行操作,但是我们需要先从server中返回所选中的socket
    clientConnection = tcpServer->nextPendingConnection();  //获取已经建立连接的套接字,next...返回已经接受这个连接的套接字

    //接着我们需要连接所提取的socket到相对应的槽函数,也就是updateclientprogress中
    connect(clientConnection,SIGNAL(bytesWritten(qint64)),
            this,SLOT(updateClientProgress(qint64)));

    //接下来我们对ui界面的进行一些对socket反应的操作
    ui->serverStatusLabel->setText(tr("开始传输文件:\n %1!").arg(theFileName));
    //我们需要创建一个localFile来操作我们所在ui上传递的QFile文件路径,也就是fileName
    localFile= new QFile(fileName);
    //然后对其进行判断,是否打开成功,如果打开不成功,则使用QMessage中的warning来提示打开文件失败
    if(!localFile->open(QFile::ReadOnly)){
        QMessageBox::warning(this,tr("应用程序"),tr("无法读取文件 %1:\n%2").arg(fileName).arg(localFile->errorString()));
        return ;
    }
    /*
    接下来是对我们所要传输的文件的一些在应用层的鉴定,鉴定所传入文件的完整性

    */
    TotalBytes = localFile->size();
    QDataStream sendOut(&outBlock,QIODevice::WriteOnly);

    time.start();  //开始计时
    /*
    以下是对filename的filename进行提取,我们是会有个QString的filename,但是我们要对其进行操作提取该文件路径的有用信息
    */
    QString currentFile = fileName.right(fileName.size()-fileName.lastIndexOf('/')-1);

    sendOut<<qint64(0)<<qint64(0)<<currentFile;
    TotalBytes +=outBlock.size();
    sendOut.device()->seek(0);
    sendOut<<TotalBytes<<qint64(outBlock.size()-sizeof(qint64)*2);
    bytestoWrite=TotalBytes-clientConnection->write(outBlock);
    outBlock.resize(0);
}

void TcpServer::updateClientProgress(qint64 numBytes)
{
    qApp->processEvents();
    bytesWritten +=(int) numBytes;
    if(bytestoWrite > 0)
    {
        //对文件内容的读取操作,将其文件的内容读取到outblock中
        outBlock = localFile->read(qMin(bytestoWrite,payloadSize));
        //这行代码的含义是将实际写入的字节数从剩余未写入的字节数量中减去，更新剩余未写入的字节数
        bytestoWrite -=(int)clientConnection->write(outBlock);
        //当读取完成之后将其清零
        outBlock.resize(0);

    }
    else
    {   //如果读取完了则关闭file
        localFile->close();
    }
    ui->progressBar->setMaximum(TotalBytes);
    ui->progressBar->setValue(bytesWritten);

    float useTime = time.elapsed();
    // qDebug() << "uerTime:" << useTime;
    double speed = bytesWritten / useTime;
    ui->serverStatusLabel->setText(tr("已发送 %1MB( %2MB/s)"
                                      "\n共%3MB 已用时:%4秒\n估计剩余时间:%5秒")
                                       .arg(bytesWritten / (1024*1024))
                                       .arg(speed * 1000 /(1024*1024),0,'f',2)
                                       .arg(TotalBytes /(1024*1024))
                                       .arg(useTime/1000,0,'f',0)
                                       .arg(TotalBytes/speed/1000 - useTime/1000,0,'f',0));
    if(bytesWritten == TotalBytes)
    {
        localFile->close();
        tcpServer->close();
        ui->serverStatusLabel->setText(tr("传送文件: %1成功").arg(theFileName));

    }
}

void TcpServer::on_serverOpenBtn_clicked()
{
    fileName = QFileDialog::getOpenFileName(this);
    if(!fileName.isEmpty()){
        //这行代码的作用是从文件路径中提取文件名部分，并将结果存储到 theFileName 变量中
        theFileName = fileName.right(fileName.size()-fileName.lastIndexOf('/')-1);
        ui->serverStatusLabel->setText(tr("要传送的文件为 %1" ).arg(theFileName));
        ui->serverSendBtn->setEnabled(true);
        ui->serverOpenBtn->setEnabled(false);

    }
}


void TcpServer::on_serverSendBtn_clicked()
{
    if(!tcpServer->listen(QHostAddress::Any,tcpPort)){
        qDebug()<<tcpServer->errorString();
        close();
        return;

    }
    ui->serverStatusLabel->setText(tr("等待对方接收...."));
    emit sendFileName(theFileName);
}


void TcpServer::on_serverCloseBtn_clicked()
{
    if(tcpServer->isListening()){
        if(localFile->isOpen())
            localFile->close();
        clientConnection->abort();

    }
    close();
}

