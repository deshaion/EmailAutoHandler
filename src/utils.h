#ifndef UTILS_H
#define UTILS_H

#include <QString>
#include <QStandardPaths>
#include <QProcessEnvironment>
#include <QFileInfo>
#include <QCoreApplication>

static QString getDbPath(QString filename) {
    QString appImagePath = QProcessEnvironment::systemEnvironment().value("APPIMAGE", NULL);
    if (appImagePath == NULL) {
        return QCoreApplication::applicationDirPath() + "/" + filename;
    } else {
        int lastSlashPos = appImagePath.lastIndexOf("/") + 1;
        return appImagePath.left(lastSlashPos) + filename;
    }
}

#endif // UTILS_H
