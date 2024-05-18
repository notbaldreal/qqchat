#ifndef TCPSERVER_H
#define TCPSERVER_H
#include<QFile>
#include <QDialog>
#include<QTcpServer>
#include<QElapsedTimer>
namespace Ui {
class TcpServer;
}

class QTcpServer;
class QTcpSocket;
class TcpServer : public QDialog
{
    Q_OBJECT

public:
    explicit TcpServer(QWidget *parent = nullptr);
    ~TcpServer();
    void initServer();  //初始服务器的函数
    void refused();

protected:
    void closeEvent(QCloseEvent *);
signals:
   void sendFileName(QString );
private:
    Ui::TcpServer *ui;
    QTcpServer *tcpServer ;
    QTcpSocket *clientConnection;
    QFile *localFile;  //本地文件
    qint32 tcpPort;

    qint64 payloadSize;
    qint64 TotalBytes;  //存放的总大小信息
    qint64 bytesWritten; //
    qint64 bytestoWrite;

    QString theFileName;  // 存放文件名
    QString fileName;

    QElapsedTimer time;
    QByteArray outBlock;  //数据缓冲区

private slots:
        void sendMessage();  //发送信息的槽函数
        void updateClientProgress(qint64 numBytes);
        void on_serverOpenBtn_clicked();
        void on_serverSendBtn_clicked();
        void on_serverCloseBtn_clicked();
};

#endif // TCPSERVER_H
