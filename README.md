# EmailAutoHandler
QT console application for FiltaQuilla addon in Thunderbird.

In Thunderbird you can create a filter and add action "Run program" (feature which is added by FiltaQuilla addon). This console application was written for using in this action. 

Logic of handling is the following:
* This application stores information about author (sender) and if the sender is new then special response will be sent.

Smtp parameters and credentials are stored in `secdata.h`
```cplusplus
#define smtp_server ""
#define smtp_port 465
#define smtp_user ""
#define smtp_pass ""
#define smtp_sender ""
#define smtp_sender_name ""
#define EMAIL_TEXT ""
#define ATTACHMENT_FILE ""
```
