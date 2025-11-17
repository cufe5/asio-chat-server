#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    login_dlg = new LoginDialog(this);
    setCentralWidget(login_dlg);

    reg_dlg = new RegisterDialog(this);

    //创建注册连接
    connect(login_dlg,&LoginDialog::switchRegister,this,&MainWindow::slotSwitchReg);

    login_dlg->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    reg_dlg->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    reg_dlg->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotSwitchReg()
{
    setCentralWidget(reg_dlg);
    login_dlg->hide();
    reg_dlg->show();

}
