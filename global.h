#ifndef GLOBAL_H
#define GLOBAL_H
#include <QWidget>
#include <functional>
#include <QRegularExpression>
#include <QStyle>
#include <memory.h>
#include <iostream>
#include <mutex>
#include <QByteArray>
#include <QNetworkReply>
/**
 * @brief repolish 用来刷新qss
 */
extern std::function<void(QWidget*)> repolish;

enum ReqId{
    ID_GET_VARIFY_CODE = 1001,  //获取验证码
    ID_REG_USER =1002,   //注册用户
};

enum Modules{
    REGISTERMOD = 0,
};

enum ErrorCodes{
    SUCCES = 0,
    ERR_JSON = 1,  //json解析错误
    ERR_NETWORK =2, //网络错误
};

#endif // GLOBAL_H
