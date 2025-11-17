#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>

/******************************************************************************
 *
 * @file       registerdialog.h
 * @brief      注册窗口
 *
 * @author     yjcat
 * @date       2025/11/17
 * @history
 *****************************************************************************/
namespace Ui {
class RegisterDialog;
}

class RegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterDialog(QWidget *parent = nullptr);
    ~RegisterDialog();

private slots:
    void on_getcode_btn_clicked();

private:
    void showTip(QString str,bool b_ok);

private:
    Ui::RegisterDialog *ui;
};

#endif // REGISTERDIALOG_H
