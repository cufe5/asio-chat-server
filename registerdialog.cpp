#include "registerdialog.h"
#include "ui_registerdialog.h"
#include "global.h"
#include "httpmgr.h"

RegisterDialog::RegisterDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
    ui->pass_edit->setEchoMode(QLineEdit::Password);
    ui->confirm_edit->setEchoMode(QLineEdit::Password);
    ui->err_tip->setProperty("state","normal");
    repolish(ui->err_tip);
    connect(HttpMgr::GetInstance().get(),&HttpMgr::sig_reg_mod_finish,this,&RegisterDialog::slot_reg_mod_finish);

    initHttpHandlers();

}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

void RegisterDialog::on_getcode_btn_clicked()
{
    auto email = ui->email_edit->text();
    QRegularExpression regex(R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");
    bool match = regex.match(email).hasMatch();
    if(match){
        //发送验证码
    }else{
        showTip(tr("邮箱地址不正确"),false);
    }
}

void RegisterDialog::slot_reg_mod_finish(ReqId id, QString res, ErrorCodes err, Modules mod)
{
    if(err != ErrorCodes::SUCCES){
        showTip(tr("网络请求错误"),false);
        return;
    }
    //解析JSON 字符串， res转为QByteArray
    QJsonDocument jsonDoc = QJsonDocument::fromJson(res.toUtf8());
    if(jsonDoc.isNull()){
        showTip(tr("json解析失败"),false);
        return;
    }
    //json 解析错误
    if(!jsonDoc.isObject()){
        showTip(tr("json解析失败"),false);
        return;
    }

    _handlers[id](jsonDoc.object());
    return;

}

void RegisterDialog::initHttpHandlers()
{
    //注册获取验证码
    _handlers.insert(ReqId::ID_GET_VARIFY_CODE,[this](const QJsonObject& jsonObj){
        int error = jsonObj["error"].toInt();
        if(error != ErrorCodes::SUCCES){
            showTip(tr("参数错误"),false);
            return;
        }
        auto email = jsonObj["email"].toString();
        showTip(tr("验证码已发送邮箱，请注意查收"),true);
        qDebug() << "email is" << email;

    });

}

void RegisterDialog::showTip(QString str,bool b_ok)
{
     ui->err_tip->setText(str);
    if(b_ok){
        ui->err_tip->setProperty("state","normal");
    }else{
        ui->err_tip->setProperty("state","err");
    }


    repolish(ui->err_tip);
}

