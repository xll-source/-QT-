/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QTreeWidget *treeWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout_4;
    QPushButton *btn_update;
    QPushButton *btn_search;
    QCheckBox *checkBox;
    QPushButton *btn_add;
    QPushButton *btn_clear;
    QLineEdit *le_search;
    QPushButton *btn_simulation;
    QTableWidget *tableWidget;
    QPushButton *btn_del;
    QLabel *lb_cnt;
    QWidget *page_2;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QPushButton *btn_exit;
    QLabel *label_2;
    QLabel *lb_user;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1125, 700);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon.jpg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(170, 170, 255);\n"
""));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName("gridLayout_3");
        treeWidget = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName("treeWidget");
        treeWidget->setMaximumSize(QSize(150, 16777215));
        treeWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);\n"
"color: rgb(0, 0, 0);\n"
"font: 10pt \"Microsoft YaHei UI\";"));
        treeWidget->header()->setVisible(false);

        gridLayout_3->addWidget(treeWidget, 1, 0, 1, 1);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 255, 255);"));
        page = new QWidget();
        page->setObjectName("page");
        gridLayout_4 = new QGridLayout(page);
        gridLayout_4->setObjectName("gridLayout_4");
        btn_update = new QPushButton(page);
        btn_update->setObjectName("btn_update");
        btn_update->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 255);"));

        gridLayout_4->addWidget(btn_update, 0, 6, 1, 1);

        btn_search = new QPushButton(page);
        btn_search->setObjectName("btn_search");
        btn_search->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);"));

        gridLayout_4->addWidget(btn_search, 0, 4, 1, 1);

        checkBox = new QCheckBox(page);
        checkBox->setObjectName("checkBox");

        gridLayout_4->addWidget(checkBox, 0, 0, 1, 1);

        btn_add = new QPushButton(page);
        btn_add->setObjectName("btn_add");
        btn_add->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 0);"));

        gridLayout_4->addWidget(btn_add, 0, 5, 1, 1);

        btn_clear = new QPushButton(page);
        btn_clear->setObjectName("btn_clear");

        gridLayout_4->addWidget(btn_clear, 1, 1, 1, 1);

        le_search = new QLineEdit(page);
        le_search->setObjectName("le_search");

        gridLayout_4->addWidget(le_search, 0, 3, 1, 1);

        btn_simulation = new QPushButton(page);
        btn_simulation->setObjectName("btn_simulation");

        gridLayout_4->addWidget(btn_simulation, 1, 0, 1, 1);

        tableWidget = new QTableWidget(page);
        if (tableWidget->rowCount() < 1)
            tableWidget->setRowCount(1);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setStyleSheet(QString::fromUtf8("color:black;"));
        tableWidget->horizontalHeader()->setVisible(true);
        tableWidget->horizontalHeader()->setHighlightSections(true);
        tableWidget->verticalHeader()->setVisible(false);

        gridLayout_4->addWidget(tableWidget, 2, 0, 1, 8);

        btn_del = new QPushButton(page);
        btn_del->setObjectName("btn_del");
        btn_del->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 0, 0);"));

        gridLayout_4->addWidget(btn_del, 0, 7, 1, 1);

        lb_cnt = new QLabel(page);
        lb_cnt->setObjectName("lb_cnt");
        lb_cnt->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        gridLayout_4->addWidget(lb_cnt, 1, 2, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);

        gridLayout_3->addWidget(stackedWidget, 1, 3, 1, 1);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 170, 255);"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalSpacer = new QSpacerItem(253, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 0, 1, 1);

        label = new QLabel(widget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(18);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("\n"
"background-color: #4d34db,rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(label, 0, 1, 1, 1);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName("gridLayout");
        btn_exit = new QPushButton(widget_2);
        btn_exit->setObjectName("btn_exit");
        btn_exit->setMaximumSize(QSize(60, 16777215));
        btn_exit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 0);"));

        gridLayout->addWidget(btn_exit, 0, 2, 1, 1);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(35, 40));
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(:/user.jpg);"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        lb_user = new QLabel(widget_2);
        lb_user->setObjectName("lb_user");

        gridLayout->addWidget(lb_user, 0, 1, 1, 1);


        gridLayout_2->addWidget(widget_2, 0, 2, 1, 1);

        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(1, 1);
        gridLayout_2->setColumnStretch(2, 1);

        gridLayout_3->addWidget(widget, 0, 0, 1, 4);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1125, 18));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\255\246\347\224\237\344\277\241\346\201\257\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
#if QT_CONFIG(tooltip)
        MainWindow->setToolTip(QCoreApplication::translate("MainWindow", "\350\277\231\346\230\257\345\255\246\347\224\237\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_update->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271", nullptr));
        btn_search->setText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "\345\205\250\351\200\211", nullptr));
        btn_add->setText(QCoreApplication::translate("MainWindow", "\345\242\236\345\212\240", nullptr));
        btn_clear->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\345\255\246\347\224\237\350\241\250", nullptr));
        btn_simulation->setText(QCoreApplication::translate("MainWindow", "\346\250\241\346\213\237\346\225\260\346\215\256", nullptr));
        btn_del->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        lb_cnt->setText(QCoreApplication::translate("MainWindow", "\345\255\246\347\224\237\346\225\260\351\207\217", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\345\255\246\347\224\237\344\277\241\346\201\257\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        btn_exit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        label_2->setText(QString());
        lb_user->setText(QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215 \357\274\232admin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
