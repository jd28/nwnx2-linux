#include "message.h"
#include "NWNXLib.h"

CNWCCMessageData *CNWCCMessageData_copy(CNWCCMessageData *msg) {
    CNWCCMessageData *copy = CNWCCMessageData_create();
    CNWCCMessageData__CopyTo(msg, copy);
    return copy;
}

CNWCCMessageData *CNWCCMessageData_create() {
    CNWCCMessageData *msg = (CNWCCMessageData *)malloc(sizeof (CNWCCMessageData));
    CNWCCMessageData__ctor(msg);
    return msg;
}

void CNWCCMessageData_destroy(CNWCCMessageData *msg) {
    if ( msg->integers.data ) {
        free(msg->integers.data);
    }
    
    if ( msg->floats.data ) {
        free(msg->floats.data);
    }

    if ( msg->objects.data ) {
        free(msg->objects.data);
    }

    if ( msg->strings.data ) {
        int i = 0;
        for ( ; i < msg->strings.len; ++i ) {
            if ( msg->strings.data[i].text) {
                free(msg->strings.data[i].text);
            }
        }
        free(msg->strings.data);
    }

    free(msg);
}
