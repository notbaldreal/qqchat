#ifndef CHAT_H
#define CHAT_H

#include <QWidget>
#include<QtNetwork/QUdpSocket>
QT_BEGIN_NAMESPACE
namespace Ui {
class chat;
}
class TcpServer;

enum messageType{
    Message,
    newParticipant,
    leftParticipant,
    Refuse,
    FileName
};
QT_END_NAMESPACE

class chat : public QWidget
{
    Q_OBJECT

public:
    chat(QWidget *parent = nullptr);
    ~chat();
protected:
    void NewParticipant(QString userName,QString localHostName,QString ipAddress);  //新加入的用户操作
    void LeftParticipant(QString userName,QString localHostName,QString Lefttime);  //离开的用户操作
    void sendMessage(messageType type,QString serverAddress="");        //广播消息的用户操作

    void hasPendingFile(QString userName,QString serverAddress,
                        QString clientAddress,QString fileName);
    bool saveFile(const QString &file);

    void closeEvent(QCloseEvent *);

    QString getIP();
    QString getUserName();
    QString getMessage();
private slots:
    void processPendingDatagrams();
    void on_sendPushButton_clicked();

    void getFileName(QString);

    void on_sendToolBtn_clicked();

    void on_boldToolBtn_clicked();

    void on_italicToolBtn_clicked();


    void on_colorToolBtn_clicked();

    void on_fontComboBox_currentFontChanged(const QFont &f);

    void on_sizeComboBox_currentIndexChanged(int index);

    void on_underlineToolBtn_clicked();

    void on_saveToolBtn_clicked();

    void on_clearToolBtn_clicked();

    void on_exitPushButton_clicked();

private:
    Ui::chat *ui;
    QUdpSocket *udpSocket;
    qint16 port;
    QString fileName;
    TcpServer *server;
    QColor color;
};
#endif // CHAT_H
