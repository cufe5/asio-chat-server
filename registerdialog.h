#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>
#include "global.h"

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
    void slot_reg_mod_finish(ReqId id,QString res,ErrorCodes err,Modules mod);

private:
    void initHttpHandlers();
    void showTip(QString str,bool b_ok);
    Ui::RegisterDialog *ui;
    QMap<ReqId,std::function<void(const QJsonObject&)>> _handlers;
};

#endif // REGISTERDIALOG_H
