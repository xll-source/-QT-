#include "page_login.h"
#include "ui_page_login.h"
#include <QMessageBox>
#include "stusql.h"

Page_Login::Page_Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Page_Login)
{
    ui->setupUi(this);
}

Page_Login::~Page_Login()
{
    delete ui;
}

void Page_Login::on_btn_login_clicked()
{
    // 获取用户名和密码
    QString username = ui->le_username->text();
    QString password = ui->le_password->text();

    // 检查输入是否为空
    if(username.isEmpty() || password.isEmpty())
    {
        QMessageBox::warning(this, "警告", "用户名或密码不能为空！");
        return;
    }

    // 获取数据库实例
    auto ptr = stuSql::getinstance();

    // 获取所有用户信息
    QList<UserInfo> users = ptr->getAllUser();

    // 遍历用户列表进行验证
    bool loginSuccess = false;
    for(const auto& user : users)
    {
        if(user.username == username && user.password == password)
        {
            loginSuccess = true;
            break;
        }
    }

    if(loginSuccess)
    {
        QMessageBox::information(this, "成功", "登录成功！");
        emit sendLoginSuccess();
    }
    else
    {
        QMessageBox::critical(this, "错误", "用户名或密码错误！");
        ui->le_password->clear();
        ui->le_password->setFocus();
    }
}


void Page_Login::on_btn_out_clicked()
{
    //退出
    exit(0);
}

