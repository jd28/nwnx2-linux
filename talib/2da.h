#ifndef TALIB_2DA_H
#define TALIB_2DA_H

C2DA *nwn_GetCached2da(const char *file);
int nwn_Get2daColumnCount(C2DA *tda);
int nwn_Get2daRowCount(C2DA *tda);
const char * nwn_Get2daString(C2DA *tda, const char* col, uint32_t row);
const char * nwn_Get2daStringIdx(C2DA *tda, int col, uint32_t row);
int32_t nwn_Get2daInt(C2DA *tda, const char* col, uint32_t row);
int32_t nwn_Get2daIntIdx(C2DA *tda, int col, uint32_t row);
float nwn_Get2daFloat(C2DA *tda, const char* col, uint32_t row);
float nwn_Get2daFloatIdx(C2DA *tda, int col, uint32_t row);

#endif // TALIB_2DA_H
