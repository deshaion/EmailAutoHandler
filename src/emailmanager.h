#ifndef EMAILMANAGER_H
#define EMAILMANAGER_H

#include "email.h"

struct EmailManager {
    static void sendReply(Email& email);
};

#endif // EMAILMANAGER_H
