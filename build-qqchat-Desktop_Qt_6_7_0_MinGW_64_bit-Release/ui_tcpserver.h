/********************************************************************************
** Form generated from reading UI file 'tcpserver.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPSERVER_H
#define UI_TCPSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TcpServer
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *serverStatusLabel;
    QProgressBar *progressBar;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *serverOpenBtn;
    QPushButton *serverSendBtn;
    QPushButton *serverCloseBtn;

    void setupUi(QDialog *TcpServer)
    {
        if (TcpServer->objectName().isEmpty())
            TcpServer->setObjectName("TcpServer");
        TcpServer->resize(527, 273);
        verticalLayout = new QVBoxLayout(TcpServer);
        verticalLayout->setObjectName("verticalLayout");
        serverStatusLabel = new QLabel(TcpServer);
        serverStatusLabel->setObjectName("serverStatusLabel");

        verticalLayout->addWidget(serverStatusLabel);

        progressBar = new QProgressBar(TcpServer);
        progressBar->setObjectName("progressBar");
        progressBar->setValue(24);

        verticalLayout->addWidget(progressBar);

        widget = new QWidget(TcpServer);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        serverOpenBtn = new QPushButton(widget);
        serverOpenBtn->setObjectName("serverOpenBtn");

        horizontalLayout->addWidget(serverOpenBtn);

        serverSendBtn = new QPushButton(widget);
        serverSendBtn->setObjectName("serverSendBtn");

        horizontalLayout->addWidget(serverSendBtn);

        serverCloseBtn = new QPushButton(widget);
        serverCloseBtn->setObjectName("serverCloseBtn");

        horizontalLayout->addWidget(serverCloseBtn);


        verticalLayout->addWidget(widget);


        retranslateUi(TcpServer);

        QMetaObject::connectSlotsByName(TcpServer);
    } // setupUi

    void retranslateUi(QDialog *TcpServer)
    {
        TcpServer->setWindowTitle(QCoreApplication::translate("TcpServer", "Dialog", nullptr));
        serverStatusLabel->setText(QCoreApplication::translate("TcpServer", "<html><head/><body><p align=\"center\"><span style=\" font-size:22pt; font-weight:700;\">\350\257\267\351\200\211\346\213\251\350\246\201\345\217\221\351\200\201\347\232\204\346\226\207\344\273\266</span></p></body></html>", nullptr));
        serverOpenBtn->setText(QCoreApplication::translate("TcpServer", "\346\211\223\345\274\200", nullptr));
        serverSendBtn->setText(QCoreApplication::translate("TcpServer", "\345\217\221\351\200\201", nullptr));
        serverCloseBtn->setText(QCoreApplication::translate("TcpServer", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TcpServer: public Ui_TcpServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPSERVER_H
