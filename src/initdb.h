#ifndef INITDB_H
#define INITDB_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>

#include "utils.h"
#include "simpleQtLogger.h"

#define DB_CONNECTION "EmailFilterDB"
#define DB_NAME "emailFilter.db"

static bool createConnection() {
    QString dbPath = getDbPath(DB_NAME);
    L_INFO("dbPath: " + dbPath);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", DB_CONNECTION);
    db.setDatabaseName(dbPath);
    if (!db.open()) {
        return false;
    }

    QSqlQuery query(db);
    if (!query.exec("create table if not exists Emails ("
               "id INTEGER primary key AUTOINCREMENT,"
               "author varchar(200),"
               "subject TEXT"
               ")")) {
        L_ERROR(query.lastError().databaseText());
        return false;
    }

    return true;
}

#endif // INITDB_H
