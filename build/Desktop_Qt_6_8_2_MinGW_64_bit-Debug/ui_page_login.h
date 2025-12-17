/********************************************************************************
** Form generated from reading UI file 'page_login.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE_LOGIN_H
#define UI_PAGE_LOGIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Page_Login
{
public:
    QLabel *lb_title;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *btn_login;
    QPushButton *btn_out;
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QLabel *lb1;
    QLineEdit *le_username;
    QLabel *lb2;
    QLineEdit *le_password;

    void setupUi(QWidget *Page_Login)
    {
        if (Page_Login->objectName().isEmpty())
            Page_Login->setObjectName("Page_Login");
        Page_Login->resize(400, 250);
        Page_Login->setMinimumSize(QSize(400, 250));
        Page_Login->setMaximumSize(QSize(400, 250));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon.jpg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Page_Login->setWindowIcon(icon);
        lb_title = new QLabel(Page_Login);
        lb_title->setObjectName("lb_title");
        lb_title->setGeometry(QRect(10, 20, 381, 60));
        lb_title->setMinimumSize(QSize(0, 60));
        QFont font;
        font.setPointSize(18);
        lb_title->setFont(font);
        lb_title->setAlignment(Qt::AlignmentFlag::AlignCenter);
        widget = new QWidget(Page_Login);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(80, 170, 251, 35));
        widget->setMinimumSize(QSize(0, 35));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        btn_login = new QPushButton(widget);
        btn_login->setObjectName("btn_login");
        btn_login->setMinimumSize(QSize(0, 30));
        QFont font1;
        font1.setPointSize(10);
        btn_login->setFont(font1);

        gridLayout->addWidget(btn_login, 0, 0, 1, 1);

        btn_out = new QPushButton(widget);
        btn_out->setObjectName("btn_out");
        btn_out->setMinimumSize(QSize(0, 30));
        btn_out->setFont(font1);

        gridLayout->addWidget(btn_out, 0, 1, 1, 1);

        widget_2 = new QWidget(Page_Login);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(79, 80, 251, 91));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        lb1 = new QLabel(widget_2);
        lb1->setObjectName("lb1");
        lb1->setFont(font1);

        gridLayout_2->addWidget(lb1, 0, 0, 1, 1);

        le_username = new QLineEdit(widget_2);
        le_username->setObjectName("le_username");
        le_username->setMinimumSize(QSize(0, 30));
        le_username->setMaxLength(8);

        gridLayout_2->addWidget(le_username, 0, 1, 1, 1);

        lb2 = new QLabel(widget_2);
        lb2->setObjectName("lb2");
        lb2->setFont(font1);

        gridLayout_2->addWidget(lb2, 1, 0, 1, 1);

        le_password = new QLineEdit(widget_2);
        le_password->setObjectName("le_password");
        le_password->setMinimumSize(QSize(0, 30));
        le_password->setMaxLength(8);
        le_password->setEchoMode(QLineEdit::EchoMode::Password);

        gridLayout_2->addWidget(le_password, 1, 1, 1, 1);


        retranslateUi(Page_Login);

        QMetaObject::connectSlotsByName(Page_Login);
    } // setupUi

    void retranslateUi(QWidget *Page_Login)
    {
        Page_Login->setWindowTitle(QCoreApplication::translate("Page_Login", "\347\231\273\345\275\225", nullptr));
#if QT_CONFIG(tooltip)
        Page_Login->setToolTip(QCoreApplication::translate("Page_Login", "\350\277\231\346\230\257\347\231\273\345\275\225\347\252\227\345\217\243", nullptr));
#endif // QT_CONFIG(tooltip)
        lb_title->setText(QCoreApplication::translate("Page_Login", "\345\255\246\347\224\237\344\277\241\346\201\257\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        btn_login->setText(QCoreApplication::translate("Page_Login", "\347\231\273\345\275\225", nullptr));
        btn_out->setText(QCoreApplication::translate("Page_Login", "\351\200\200\345\207\272", nullptr));
        lb1->setText(QCoreApplication::translate("Page_Login", "\347\224\250\346\210\267\345\220\215", nullptr));
        le_username->setPlaceholderText(QCoreApplication::translate("Page_Login", "\350\257\267\350\276\223\345\205\245...", nullptr));
        lb2->setText(QCoreApplication::translate("Page_Login", "\345\257\206\347\240\201", nullptr));
        le_password->setPlaceholderText(QCoreApplication::translate("Page_Login", "\350\257\267\350\276\223\345\205\245...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Page_Login: public Ui_Page_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE_LOGIN_H
