/********************************************************************************
** Form generated from reading UI file 'tcpclient.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPCLIENT_H
#define UI_TCPCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TcpClient
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *tcpClientStatusLabel;
    QProgressBar *progressBar;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *tcpClientCancleBtn;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *tcpClientCloseBtn;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *TcpClient)
    {
        if (TcpClient->objectName().isEmpty())
            TcpClient->setObjectName("TcpClient");
        TcpClient->resize(435, 255);
        verticalLayout = new QVBoxLayout(TcpClient);
        verticalLayout->setObjectName("verticalLayout");
        tcpClientStatusLabel = new QLabel(TcpClient);
        tcpClientStatusLabel->setObjectName("tcpClientStatusLabel");

        verticalLayout->addWidget(tcpClientStatusLabel);

        progressBar = new QProgressBar(TcpClient);
        progressBar->setObjectName("progressBar");
        progressBar->setValue(24);

        verticalLayout->addWidget(progressBar);

        widget = new QWidget(TcpClient);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(75, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        tcpClientCancleBtn = new QPushButton(widget);
        tcpClientCancleBtn->setObjectName("tcpClientCancleBtn");

        horizontalLayout->addWidget(tcpClientCancleBtn);

        horizontalSpacer_2 = new QSpacerItem(76, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        tcpClientCloseBtn = new QPushButton(widget);
        tcpClientCloseBtn->setObjectName("tcpClientCloseBtn");

        horizontalLayout->addWidget(tcpClientCloseBtn);

        horizontalSpacer_3 = new QSpacerItem(75, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(widget);


        retranslateUi(TcpClient);

        QMetaObject::connectSlotsByName(TcpClient);
    } // setupUi

    void retranslateUi(QDialog *TcpClient)
    {
        TcpClient->setWindowTitle(QCoreApplication::translate("TcpClient", "Dialog", nullptr));
        tcpClientStatusLabel->setText(QCoreApplication::translate("TcpClient", "<html><head/><body><p align=\"center\"><span style=\" font-size:22pt;\">\347\255\211\345\276\205\346\216\245\346\224\266\346\226\207\344\273\266....</span></p></body></html>", nullptr));
        tcpClientCancleBtn->setText(QCoreApplication::translate("TcpClient", "\345\217\226\346\266\210", nullptr));
        tcpClientCloseBtn->setText(QCoreApplication::translate("TcpClient", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TcpClient: public Ui_TcpClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPCLIENT_H
