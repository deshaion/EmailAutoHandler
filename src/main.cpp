#include <QCoreApplication>
#include <QDebug>

#include "simpleQtLogger.h"
#include "initdb.h"
#include "utils.h"
#include "emailsdao.h"
#include "emailmanager.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    simpleqtlogger::SimpleQtLogger::createInstance(qApp)->setLogFileName(getDbPath("emailFilter.log"), 10*1000*1000, 20);

    L_INFO("Start filter. Arguments are:");
    for (QString arg : a.arguments()) {
        L_INFO(arg);
    }

    if (a.arguments().size() < 4) {
        L_ERROR("Not enough parameters");
        return 0;
    }

    L_INFO("Parse email");
    Email email = Email::parseArguments(a.arguments());

    L_INFO("Create connection");
    if (!createConnection()) {
        L_ERROR("Can't create connection with Db");
        throw std::runtime_error("Can't create connection with Db");
    }

    try {
        bool needReply = !EmailsDAO::authorExist(email.author);
        L_INFO(QString("Is reply needed? ") + QString::number(needReply));

        EmailsDAO::addEmail(email);

        if (needReply) {
            EmailManager::sendReply(email);
            L_INFO("Reply was sent");
        }
    } catch (std::exception &e) {
        L_ERROR(e.what());
    }

    return 0;
}
