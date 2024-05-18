#include "chat.h"

#include <QApplication>
#include<QFile>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    chat w;
    QString qss;
    QFile qssfile(":/QSS/ubuntu.qss");
    if(qssfile.open(QFile::ReadOnly)){
        qss=qssfile.readAll();
        w.setStyleSheet(qss);
        qssfile.close();
    }
    w.setFixedSize(QSize(828,434));
    w.setWindowTitle(chat::tr("局域网聊天窗口"));
    w.setWindowIcon(QIcon(":/C:/Users/asus/Pictures/rc/chat/QQ.png"));
    w.show();
    return a.exec();
}
