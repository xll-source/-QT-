#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QKeyEvent>
#include <QFile>
#include <QCoreApplication>
#include <QRandomGenerator>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,m_ptrStuSql(nullptr)
{
    ui->setupUi(this);

    m_dlgLogin.show();
    auto f = [&](){
        this->show();
    };
    connect(&m_dlgLogin,&Page_Login::sendLoginSuccess,this,f);

    ui->treeWidget->clear();
    ui->treeWidget->setColumnCount(1);
    QStringList l;
    l<<"学生信息管理系统";

    QTreeWidgetItem *pf = new QTreeWidgetItem(ui->treeWidget,l);
    ui->treeWidget->addTopLevelItem(pf);
    l.clear();
    l<<"学生信息管理";

    QTreeWidgetItem *p1 = new QTreeWidgetItem(pf,l);
    l.clear();
    l<<"管理员管理";
    //QTreeWidgetItem *p2 = new QTreeWidgetItem(pf,l);

    //父子关系
    pf->addChild(p1);
    //pf->addChild(p2);

    ui->treeWidget->expandAll();
    ui->stackedWidget->setCurrentIndex(0);

    m_ptrStuSql = stuSql::getinstance();
    m_ptrStuSql->init();


    m_LNames<<"小项";
    m_LNames<<"小程";
    m_LNames<<"小柴";
    m_LNames<<"张三";
    m_LNames<<"李四";
    m_LNames<<"王五";
    m_LNames<<"赵六";

    updateTable();

}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_F6)
    {
        QFile f;
        auto str = QCoreApplication::applicationDirPath();
        f.setFileName(str+"//"+"stuqss.css");
        f.open(QIODevice::ReadOnly);
        QString strQss = f.readAll();
        this->setStyleSheet(strQss);
        m_dlgLogin.setStyleSheet(strQss);
    }
}*/

//主页面的退出的实现
void MainWindow::on_btn_exit_clicked()
{
    exit(0);
}

void MainWindow::on_btn_simulation_clicked()
{
    QStringList l;

    QRandomGenerator g;
    g.seed(0);

    //制作1000条学生数据
    for(int i =0;i<m_LNames.size();i++){

        auto grade = g.bounded(1,4);
        auto uiclass = g.bounded(1,8);

        StuInfo info;
        info.name = m_LNames[i];
        if(i%3)
        {
            info.age = 16;
        }
        if(i%7)
        {
            info.age = 17;
        }
        if(i%2)
        {
            info.age = 18;
        }

        info.grade = grade;
        info.uiclass = uiclass;
        info.studentid = i;
        info.phone = "13212344345";
        info.wechat = "21434324423";
        m_ptrStuSql->addStu(info);
    }
    updateTable();
}


void MainWindow::on_btn_add_clicked()
{
    m_dlgAddStu.setType(true);
    m_dlgAddStu.exec();
    //在进行相关操作后对数据库进行刷新
    updateTable();
}


void MainWindow::on_btn_clear_clicked()
{
    m_ptrStuSql->clearStuTable();
    //在进行相关操作后对数据库进行刷新
    updateTable();
}

//数据库刷新的功能
void MainWindow::updateTable()
{
    ui->tableWidget->clear();
    //设置一共为9列
    ui->tableWidget->setColumnCount(9);
    QStringList l;
    l<<"序号"<<"id"<<"姓名"<<"年龄"<<"年级"<<"班级"<<"学号"<<"电话"<<"微信";
    ui->tableWidget->setHorizontalHeaderLabels(l);
    //只选中行
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    //ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    auto cnt = m_ptrStuSql->getStuCnt();

    //数据的统计
    ui->lb_cnt->setText(QString("数量:%1").arg(cnt));
    QList<StuInfo> lStudents = m_ptrStuSql->getPageStu(0,cnt);

    ui->tableWidget->setRowCount(cnt);
    for(int i = 0;i<lStudents.size();i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(i)));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(lStudents[i].id)));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(lStudents[i].name));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(lStudents[i].age)));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(lStudents[i].grade)));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(QString::number(lStudents[i].uiclass)));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(QString::number(lStudents[i].studentid)));
        ui->tableWidget->setItem(i,7,new QTableWidgetItem(lStudents[i].phone));
        ui->tableWidget->setItem(i,8,new QTableWidgetItem(lStudents[i].wechat));
    }

}

//信息删除
void MainWindow::on_btn_del_clicked()
{
    int i= ui->tableWidget->currentRow();
    if(i>=0)
    {
        int id = ui->tableWidget->item(i,1)->text().toUInt();
        m_ptrStuSql->delStu(id);
        updateTable();
        QMessageBox::information(nullptr,"信息","删除成功");
    }
}



//修改按钮的槽函数
void MainWindow::on_btn_update_clicked()
{
    StuInfo info;
    int i= ui->tableWidget->currentRow();
    if(i>=0)
    {
        info.id = ui->tableWidget->item(i,1)->text().toUInt();
        info.name = ui->tableWidget->item(i,2)->text();
        info.age= ui->tableWidget->item(i,3)->text().toUInt();
        info.grade= ui->tableWidget->item(i,4)->text().toUInt();
        info.uiclass = ui->tableWidget->item(i,5)->text().toUInt();
        info.studentid = ui->tableWidget->item(i,6)->text().toUInt();
        info.phone = ui->tableWidget->item(i,7)->text();
        info.wechat = ui->tableWidget->item(i,8)->text();
        m_dlgAddStu.setType(false,info);
        m_dlgAddStu.exec();
    }
    //在进行相关操作后对数据库进行刷新
    updateTable();
}


void MainWindow::on_btn_search_clicked()
{
    //获取筛选人的名字
    QString strFilter = ui->le_search->text();

    if(strFilter.isEmpty())
    {
        QMessageBox::information(nullptr,"警告","名字筛选为空");
        updateTable();
        return;
    }

    ui->tableWidget->clear();
    //设置一共为8列
    ui->tableWidget->setColumnCount(9);
    QStringList l;
    l<<"序号"<<"id"<<"姓名"<<"年龄"<<"年级"<<"班级"<<"学号"<<"电话"<<"微信";
    ui->tableWidget->setHorizontalHeaderLabels(l);
    //只选中行
    //ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    //ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    //ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    auto cnt = m_ptrStuSql->getStuCnt();

    //数据的统计
    ui->lb_cnt->setText(QString("数量:%1").arg(cnt));
    QList<StuInfo> lStudents = m_ptrStuSql->getPageStu(0,cnt);

    //ui->tableWidget->setRowCount(cnt);

    int index = 0;
    for(int i = 0;i<lStudents.size();i++)
    {
        //如果包含名字
        if(!lStudents[i].name.contains(strFilter))
        {
            continue;
        }

        ui->tableWidget->setItem(index,0,new QTableWidgetItem(QString::number(index+1)));
        ui->tableWidget->setItem(index,1,new QTableWidgetItem(QString::number(lStudents[i].id)));
        ui->tableWidget->setItem(index,2,new QTableWidgetItem(lStudents[i].name));
        ui->tableWidget->setItem(index,3,new QTableWidgetItem(QString::number(lStudents[i].age)));
        ui->tableWidget->setItem(index,4,new QTableWidgetItem(QString::number(lStudents[i].grade)));
        ui->tableWidget->setItem(index,5,new QTableWidgetItem(QString::number(lStudents[i].uiclass)));
        ui->tableWidget->setItem(index,6,new QTableWidgetItem(QString::number(lStudents[i].studentid)));
        ui->tableWidget->setItem(index,7,new QTableWidgetItem(lStudents[i].phone));
        ui->tableWidget->setItem(index,8,new QTableWidgetItem(lStudents[i].wechat));
        index++;
    }
    ui->tableWidget->setRowCount(index);
}

