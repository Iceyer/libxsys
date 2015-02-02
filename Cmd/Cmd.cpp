#include "Cmd.h"

#include "../Common/Result.h"
#include "../FileSystem/FileSystem.h"

#include <QDebug>
#include <QString>
#include <QTextStream>
#include <QFile>
#include <QProcess>

namespace XSys {


static Result runApp(const QString &execPath, const QString &execParam, const QString &execPipeIn="") {
 //   QString outPipePath = FS::TmpFilePath("pipeOut");

    QProcess app;
    app.setStandardInputFile(execPipeIn);
//    app.setStandardOutputFile(outPipePath);
//    app.setStandardErrorFile(outPipePath);
    app.start(execPath + " " + execParam);
    app.waitForFinished();

    if (QProcess::NormalExit != app.exitStatus()) {
        qWarning()<<"Cmd Exec Failed:"<<app.readAllStandardError();
        return Result(Result::Faiiled, app.readAllStandardError());
    }

//    QFile locale(outPipePath);
//    if (!locale.open(QIODevice::ReadOnly)) {
//        return Result(Result::Faiiled, "Open Ouput Pipe Failed");
//    }
//    QTextStream localets(&locale);

//    QString outUtf8PipePath = FS::TmpFilePath("utf8pipeOut");
//    QFile utf8(outUtf8PipePath);
//    if (!utf8.open(QIODevice::WriteOnly)) {
//        return Result(Result::Faiiled, "Open Ouput Pipe Failed");
//    }
//    QTextStream utf8ts(&utf8);
//    utf8ts.setCodec("utf8");
//    utf8ts<<localets.readAll();
//    locale.close();
//    utf8.close();

//    utf8.open(QIODevice::ReadOnly);
//    QString ret = QString(utf8.readAll());
//    utf8.close();

//    locale.remove();
//    utf8.remove();
    Result rest (Result::Success, app.readAllStandardError(), app.readAllStandardOutput());
    return rest;
}

Result SynExec(const QString &exec, const QString &param, const QString &execPipeIn) {
    Result ret = runApp(exec, param, execPipeIn);
    qDebug()<<exec<<param<<execPipeIn<<ret.isSuccess()<<ret.errmsg();
    return ret;
}

}
