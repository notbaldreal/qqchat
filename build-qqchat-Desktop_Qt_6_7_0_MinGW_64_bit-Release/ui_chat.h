/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chat
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QTextBrowser *messageBrower;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QFontComboBox *fontComboBox;
    QComboBox *sizeComboBox;
    QToolButton *boldToolBtn;
    QToolButton *italicToolBtn;
    QToolButton *underlineToolBtn;
    QToolButton *colorToolBtn;
    QToolButton *saveToolBtn;
    QToolButton *sendToolBtn;
    QToolButton *clearToolBtn;
    QTextEdit *messageTextEdit;
    QTableWidget *userTableWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *sendPushButton;
    QSpacerItem *horizontalSpacer;
    QLabel *userNumLabel;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *exitPushButton;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *chat)
    {
        if (chat->objectName().isEmpty())
            chat->setObjectName("chat");
        chat->resize(655, 400);
        verticalLayout_2 = new QVBoxLayout(chat);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(chat);
        widget_3->setObjectName("widget_3");
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName("widget_2");
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        messageBrower = new QTextBrowser(widget_2);
        messageBrower->setObjectName("messageBrower");

        verticalLayout->addWidget(messageBrower);

        frame = new QFrame(widget_2);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        fontComboBox = new QFontComboBox(frame);
        fontComboBox->setObjectName("fontComboBox");

        horizontalLayout_2->addWidget(fontComboBox);

        sizeComboBox = new QComboBox(frame);
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->addItem(QString());
        sizeComboBox->setObjectName("sizeComboBox");
        sizeComboBox->setMinimumSize(QSize(40, 0));

        horizontalLayout_2->addWidget(sizeComboBox);

        boldToolBtn = new QToolButton(frame);
        boldToolBtn->setObjectName("boldToolBtn");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/C:/Users/asus/Pictures/rc/chat/bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        boldToolBtn->setIcon(icon);
        boldToolBtn->setCheckable(true);

        horizontalLayout_2->addWidget(boldToolBtn);

        italicToolBtn = new QToolButton(frame);
        italicToolBtn->setObjectName("italicToolBtn");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/C:/Users/asus/Pictures/rc/chat/leek.png"), QSize(), QIcon::Normal, QIcon::Off);
        italicToolBtn->setIcon(icon1);
        italicToolBtn->setCheckable(true);

        horizontalLayout_2->addWidget(italicToolBtn);

        underlineToolBtn = new QToolButton(frame);
        underlineToolBtn->setObjectName("underlineToolBtn");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/C:/Users/asus/Pictures/rc/chat/xiahuaxian.png"), QSize(), QIcon::Normal, QIcon::Off);
        underlineToolBtn->setIcon(icon2);
        underlineToolBtn->setCheckable(true);

        horizontalLayout_2->addWidget(underlineToolBtn);

        colorToolBtn = new QToolButton(frame);
        colorToolBtn->setObjectName("colorToolBtn");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/C:/Users/asus/Pictures/rc/chat/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        colorToolBtn->setIcon(icon3);

        horizontalLayout_2->addWidget(colorToolBtn);

        saveToolBtn = new QToolButton(frame);
        saveToolBtn->setObjectName("saveToolBtn");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/C:/Users/asus/Pictures/rc/chat/send.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveToolBtn->setIcon(icon4);

        horizontalLayout_2->addWidget(saveToolBtn);

        sendToolBtn = new QToolButton(frame);
        sendToolBtn->setObjectName("sendToolBtn");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/C:/Users/asus/Pictures/rc/chat/file.png"), QSize(), QIcon::Normal, QIcon::Off);
        sendToolBtn->setIcon(icon5);

        horizontalLayout_2->addWidget(sendToolBtn);

        clearToolBtn = new QToolButton(frame);
        clearToolBtn->setObjectName("clearToolBtn");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/C:/Users/asus/Pictures/rc/chat/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearToolBtn->setIcon(icon6);

        horizontalLayout_2->addWidget(clearToolBtn);


        verticalLayout->addWidget(frame);

        messageTextEdit = new QTextEdit(widget_2);
        messageTextEdit->setObjectName("messageTextEdit");
        messageTextEdit->setMaximumSize(QSize(16777215, 120));

        verticalLayout->addWidget(messageTextEdit);


        horizontalLayout_3->addWidget(widget_2);

        userTableWidget = new QTableWidget(widget_3);
        if (userTableWidget->columnCount() < 3)
            userTableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        userTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        userTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        userTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        userTableWidget->setObjectName("userTableWidget");

        horizontalLayout_3->addWidget(userTableWidget);


        verticalLayout_2->addWidget(widget_3);

        widget = new QWidget(chat);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 10, 0, 10);
        horizontalSpacer_2 = new QSpacerItem(77, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        sendPushButton = new QPushButton(widget);
        sendPushButton->setObjectName("sendPushButton");

        horizontalLayout->addWidget(sendPushButton);

        horizontalSpacer = new QSpacerItem(77, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        userNumLabel = new QLabel(widget);
        userNumLabel->setObjectName("userNumLabel");

        horizontalLayout->addWidget(userNumLabel);

        horizontalSpacer_3 = new QSpacerItem(77, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        exitPushButton = new QPushButton(widget);
        exitPushButton->setObjectName("exitPushButton");

        horizontalLayout->addWidget(exitPushButton);

        horizontalSpacer_4 = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout_2->addWidget(widget);


        retranslateUi(chat);

        QMetaObject::connectSlotsByName(chat);
    } // setupUi

    void retranslateUi(QWidget *chat)
    {
        chat->setWindowTitle(QCoreApplication::translate("chat", "chat", nullptr));
        sizeComboBox->setItemText(0, QCoreApplication::translate("chat", "10", nullptr));
        sizeComboBox->setItemText(1, QCoreApplication::translate("chat", "11", nullptr));
        sizeComboBox->setItemText(2, QCoreApplication::translate("chat", "12", nullptr));
        sizeComboBox->setItemText(3, QCoreApplication::translate("chat", "13", nullptr));
        sizeComboBox->setItemText(4, QCoreApplication::translate("chat", "14", nullptr));
        sizeComboBox->setItemText(5, QCoreApplication::translate("chat", "15", nullptr));
        sizeComboBox->setItemText(6, QCoreApplication::translate("chat", "16", nullptr));
        sizeComboBox->setItemText(7, QCoreApplication::translate("chat", "17", nullptr));
        sizeComboBox->setItemText(8, QCoreApplication::translate("chat", "18", nullptr));
        sizeComboBox->setItemText(9, QCoreApplication::translate("chat", "19", nullptr));
        sizeComboBox->setItemText(10, QCoreApplication::translate("chat", "20", nullptr));
        sizeComboBox->setItemText(11, QCoreApplication::translate("chat", "21", nullptr));

#if QT_CONFIG(tooltip)
        boldToolBtn->setToolTip(QCoreApplication::translate("chat", "\345\255\227\344\275\223", nullptr));
#endif // QT_CONFIG(tooltip)
        boldToolBtn->setText(QCoreApplication::translate("chat", "...", nullptr));
#if QT_CONFIG(tooltip)
        italicToolBtn->setToolTip(QCoreApplication::translate("chat", "\346\226\234\344\275\223", nullptr));
#endif // QT_CONFIG(tooltip)
        italicToolBtn->setText(QCoreApplication::translate("chat", "...", nullptr));
#if QT_CONFIG(tooltip)
        underlineToolBtn->setToolTip(QCoreApplication::translate("chat", "\344\270\213\345\210\222\347\272\277", nullptr));
#endif // QT_CONFIG(tooltip)
        underlineToolBtn->setText(QCoreApplication::translate("chat", "...", nullptr));
#if QT_CONFIG(tooltip)
        colorToolBtn->setToolTip(QCoreApplication::translate("chat", "\351\242\234\350\211\262", nullptr));
#endif // QT_CONFIG(tooltip)
        colorToolBtn->setText(QCoreApplication::translate("chat", "...", nullptr));
#if QT_CONFIG(tooltip)
        saveToolBtn->setToolTip(QCoreApplication::translate("chat", "\345\217\221\351\200\201\344\277\241\346\201\257", nullptr));
#endif // QT_CONFIG(tooltip)
        saveToolBtn->setText(QCoreApplication::translate("chat", "...", nullptr));
#if QT_CONFIG(tooltip)
        sendToolBtn->setToolTip(QCoreApplication::translate("chat", "\344\277\235\345\255\230", nullptr));
#endif // QT_CONFIG(tooltip)
        sendToolBtn->setText(QCoreApplication::translate("chat", "...", nullptr));
#if QT_CONFIG(tooltip)
        clearToolBtn->setToolTip(QCoreApplication::translate("chat", "\346\270\205\347\220\206", nullptr));
#endif // QT_CONFIG(tooltip)
        clearToolBtn->setText(QCoreApplication::translate("chat", "...", nullptr));
        QTableWidgetItem *___qtablewidgetitem = userTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("chat", "\347\224\250\346\210\267\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = userTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("chat", "\344\270\273\346\234\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = userTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("chat", "\345\234\260\345\235\200", nullptr));
        sendPushButton->setText(QCoreApplication::translate("chat", "\345\217\221\351\200\201", nullptr));
        userNumLabel->setText(QCoreApplication::translate("chat", "\345\234\250\347\272\277\344\272\272\346\225\260:                           ", nullptr));
        exitPushButton->setText(QCoreApplication::translate("chat", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chat: public Ui_chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
