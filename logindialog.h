#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

/******************************************************************************
 *
 * @file       logindialog.h
 * @brief      登录窗口
 *
 * @author     yjcat
 * @date       2025/11/17
 * @history
 *****************************************************************************/
namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private:
    Ui::LoginDialog *ui;

signals:
    void switchRegister();
};

#endif // LOGINDIALOG_H
