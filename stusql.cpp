#include "stusql.h"
#include <QMessageBox>
#include <QCoreApplication>
#include <QSqlQuery>
#include <QtDebug>

stuSql * stuSql::ptrstuSql = nullptr;
stuSql::stuSql(QObject *parent)
    : QObject{parent}
{
    //init();

    //数据库连接测试
    /*StuInfo s;
    s.name = "小张";
    for(int i = 0;i<10;i++)
    {
    addStu(s);
    }
    */

    //getStuCnt();

    //getPageStu(2,3);
    //delStu(128);
    //StuInfo s;
    //s.id = 124;
    //s.name = "xll";
    //UpadteStuInfo(s);


    //在数据库中增加用户名
    UserInfo info;
    info.username = "xll";
    info.password = "123456";
    info.aut = "admin";
    AddUser(info);


    //AddUser(info);
    //auto l = getAllUsr();
    //qDebug()<<isExit("xll");
    //info.password = "666213";
    //updateUser(info);

    //delUser("xll");
}
void stuSql::init(){
    if(QSqlDatabase::drivers().isEmpty()){
        qDebug()<<"No Database drivers found";
    }
    m_db = QSqlDatabase::addDatabase("QSQLITE");

#if 0
    auto str =  QCoreApplication::applicationDirPath()+"data.db";
    qDebug()<<str;
#endif

    m_db.setDatabaseName("D://data.db");
    if(!m_db.open()){
        qDebug()<<"db not open";
    }
}
//查询学生数量
quint32 stuSql::getStuCnt()
{
    QSqlQuery sql(m_db);
    sql.exec("select count(id) from student;");
    quint32 uiCnt = 0;
    while(sql.next())
    {
       uiCnt = sql.value(0).toUInt();
    }
    return uiCnt;
}

//查询第几页学生信息
QList<StuInfo> stuSql::getPageStu(quint32 page,quint32 uiCnt)
{
    QList<StuInfo> l;
    QSqlQuery sql(m_db);
    QString strsql = QString("select * from student order by id limit %1 offset %2;").
                     arg(uiCnt).arg(page*uiCnt);
    sql.exec(strsql);
    StuInfo info;
    while(sql.next())
    {
        info.id = sql.value(0).toUInt();
        info.name = sql.value(1).toString();
        info.age = sql.value(2).toUInt();
        info.grade = sql.value(3).toUInt();
        info.uiclass = sql.value(4).toUInt();
        info.studentid = sql.value(5).toUInt();
        info.phone = sql.value(6).toString();
        info.wechat = sql.value(7).toString();
        l.push_back(info);
    }
    return l;
}

//添加学生信息
bool stuSql::addStu(StuInfo info)
{
    QSqlQuery sql(m_db);
    QString strSql = QString("insert into student values(null,'%1',%2,%3,%4,%5,'%6','%7');").
        arg(info.name).
        arg(info.age).
        arg(info.grade).
        arg(info.uiclass).
        arg(info.studentid).
        arg(info.phone).
        arg(info.wechat);
    return sql.exec(strSql);
}

//删除学生信息
bool stuSql::delStu(int id)
{
    QSqlQuery sql(m_db);
    return sql.exec(QString("delete from student where id = %1").arg(id));
}

//清空学生信息表
bool stuSql::clearStuTable()
{
    QSqlQuery sql(m_db);
    sql.exec("delete from student;");
    //设置主键从1开始
    return sql.exec("delete from sqlite_sequence where name = 'student';");
}

//更新学生的信息
bool stuSql::UpdateStuInfo(StuInfo info)
{
    QSqlQuery sql(m_db);
    QString strSql = QString("update student set name = '%1',age=%2,grade=%3,class=%4,studentid=%5,phone='%6',wechat='%7' where id=%8").
        arg(info.name).
        arg(info.age).
        arg(info.grade).
        arg(info.uiclass).
        arg(info.studentid).
        arg(info.phone).
        arg(info.wechat).arg(info.id);
    return sql.exec(strSql);
}



QList<UserInfo> stuSql::getAllUser()
{
    QList<UserInfo> l;
    QSqlQuery sql(m_db);
    sql.exec("select * from username");

    UserInfo info;
    while(sql.next())
    {
        info.username = sql.value(0).toString();
        info.password = sql.value(1).toString();
        info.aut = sql.value(2).toString();
        l.push_back(info);
    }
    return l;
}

//查询用户信息是否存在
bool stuSql::isExit(QString strUser)
{
    QSqlQuery sql(m_db);
    sql.exec(QString("select * from username where username = '%1'").arg(strUser));
    return sql.next();
}



//更新用户信息
bool stuSql::updateUser(UserInfo info)
{
    QSqlQuery sql(m_db);
    QString strSql = QString("update username set password='%1',auth='%2' where username='%3'").
                     arg(info.password).
                     arg(info.aut).arg(info.username);
    return sql.exec(strSql);
}

//添加新的用户信息
bool stuSql::AddUser(UserInfo info)
{
    QSqlQuery sql(m_db);
    QString strSql = QString("insert into username values('%1','%2','%3')").
                     arg(info.username).
                     arg(info.password).
                     arg(info.aut);
    return sql.exec(strSql);
}

//删除用户的信息
bool stuSql::delUser(QString strUserName)
{
    QSqlQuery sql(m_db);
    return sql.exec(QString("delete from username where username = '%1'").arg(strUserName));
}

