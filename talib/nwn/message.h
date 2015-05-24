#ifndef TALIB_MESSAGE_H
#define TALIB_MESSAGE_H

CNWCCMessageData *CNWCCMessageData_copy(CNWCCMessageData *msg);
CNWCCMessageData *CNWCCMessageData_create();
void CNWCCMessageData_destroy(CNWCCMessageData *msg);

#endif // TALIB_MESSAGE_H
