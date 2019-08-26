#ifndef EMAILSDAO_H
#define EMAILSDAO_H

#include <QString>
#include "email.h"
#include "initdb.h"
#include "simpleQtLogger.h"

struct EmailsDAO {
    static bool addEmail(Email& email);
    static bool authorExist(QString author);
};

#endif // EMAILSDAO_H

bool EmailsDAO::addEmail(Email &email) {
    QSqlDatabase db = QSqlDatabase::database(DB_CONNECTION);

    if (!db.transaction()) {
        L_ERROR(db.lastError().databaseText());
        return false;
    }

    QSqlQuery query(db);

    query.prepare("INSERT INTO Emails (author, subject) VALUES (:author, :subject)");

    query.bindValue(":author"      , email.author);
    query.bindValue(":subject"     , email.subject);

    if (!query.exec()) {
        L_ERROR(db.lastError().databaseText());
        return false;
    }

    if (!db.commit()) {
        L_ERROR(db.lastError().databaseText());
        return false;
    }

    return true;
}

bool EmailsDAO::authorExist(QString author) {
    QSqlDatabase db = QSqlDatabase::database(DB_CONNECTION);
    QSqlQuery query(db);

    query.prepare("SELECT * FROM Emails WHERE author = :author LIMIT 1;");
    query.bindValue(":author", author);

    if (!query.exec()) {
        L_ERROR(db.lastError().databaseText());
        return false;
    }

    return query.next();
}
