#ifndef EMAIL_H
#define EMAIL_H

#include <QString>
#include <QStringList>

struct Email {
    QString author;
    QString authorName;
    QString subject;

    Email(QString author, QString authorName, QString subject) :
        author(author), authorName(authorName), subject(subject) {}

    static Email parseArguments(QStringList args) {
        QString subject = args.at(1);
        QString author = args.at(3);
        QString authorName = "";

        int posOfAddressBeginning = author.indexOf('<');
        if (posOfAddressBeginning != -1) {
            authorName = author.left(posOfAddressBeginning - 1);
            author = author.mid(posOfAddressBeginning + 1, author.lastIndexOf('>') - posOfAddressBeginning - 1);
        }

        return Email(author, authorName, subject);
    }
};

#endif // EMAIL_H
