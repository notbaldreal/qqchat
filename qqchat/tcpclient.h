#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QDialog>
#include<QTcpServer>
#include<QFile>
#include<QTcpSocket>
#include<QTime>
#include<QFileDialog>
#include<QString>
#include<QCloseEvent>
#include<QHostAddress>
#include<QElapsedTimer>
namespace Ui {
class TcpClient;
}

class TcpClient : public QDialog
{
    Q_OBJECT

public:
    explicit TcpClient(QWidget *parent = nullptr);
    ~TcpClient();

    void setFileName(QString fileName);
    void setHostAddress(QHostAddress address);

    void closeEvent(QCloseEvent *);

    QFile *localFile;
private slots:

    void readMessage();

    void displayError(QAbstractSocket::SocketError);

    void newConnect();

    void on_tcpClientCancleBtn_clicked();

    void on_tcpClientCloseBtn_clicked();

private:
    Ui::TcpClient *ui;
    //客户端的
    QTcpSocket *tcpClient;
    qint16 tcpPort;

    QHostAddress hostAddress;
    /*
    以下是文件传输在应用层的文件内容完整性验证所需要的数据
    */
    qint64 TotalBytes ;
    qint64 bytesReceived;
    qint64 fileNameSize ;
    qint64 blockSize;
    QString fileName;

    QElapsedTimer time;
    QByteArray inBlock;
};

#endif // TCPCLIENT_H
