
#include "emailmanager.h"
#include "smtp_client/SmtpMime"
#include "secdata.h"
#include "utils.h"

void EmailManager::sendReply(Email &email) {
    SmtpClient smtp(smtp_server, smtp_port, SmtpClient::SslConnection);

    smtp.setUser(smtp_user);
    smtp.setPassword(smtp_pass);

    MimeMessage message;

    message.setSender(new EmailAddress(smtp_sender, smtp_sender_name));
    message.addRecipient(new EmailAddress(email.author, email.authorName));
    message.addBcc(new EmailAddress(smtp_sender, smtp_sender_name));
    message.setSubject("RE: " + email.subject);

    message.addPart(new MimeText(EMAIL_TEXT));
    message.addPart(new MimeAttachment(new QFile(getDbPath(ATTACHMENT_FILE))));

    // Now we can send the mail
    smtp.connectToHost();
    smtp.login();
    smtp.sendMail(message);
    smtp.quit();
}
