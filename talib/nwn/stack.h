#ifndef TALIB_STACK_H
#define TALIB_STACK_H

void      nwn_ExecuteCommand(int command, int num_args);

uint32_t  nwn_GetCommandObjectId();
uint32_t  nwn_SetCommandObjectId(uint32_t obj);

bool      nwn_StackPopBoolean();
int32_t   nwn_StackPopInteger();
float     nwn_StackPopFloat();
char     *nwn_StackPopString();
Vector   *nwn_StackPopVector();
uint32_t  nwn_StackPopObject();
void      nwn_StackPushBoolean(bool value);
void     *nwn_StackPopEngineStructure(uint32_t type);
void      nwn_StackPushFloat(float value);
void      nwn_StackPushInteger(int32_t value);
void      nwn_StackPushString(const char *value);
void      nwn_StackPushVector(Vector *value);
void      nwn_StackPushObject(uint32_t value);
void      nwn_StackPushEngineStructure(uint32_t type, void * value);

#endif // TALIB_STACK_H
