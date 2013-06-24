C2DA *nwn_GetCached2da(const char *file) {
    CExoString s;
    s.text = strdup(file);
    return CTwoDimArrays__GetCached2DA((*NWN_Rules)->ru_2das, &s, 1);
}

int nwn_Get2daColumnCount(C2DA *tda) {
    return C2DA__GetNumColumns(tda);
}

int nwn_Get2daRowCount(C2DA *tda) {
    return C2DA__GetNumRows(tda);
}

const char * nwn_Get2daStringIdx(C2DA *tda, int col, uint32_t row) {
    static char res_[2048] = {0};

    if ( !tda                     || 
         col >= tda->tda_cols_len ||
         row >= tda->tda_rows_len ) { 
        return ""; 
    }

    CExoString *str = &tda->tda_rows[row][col];

    res_[0] = '\0';
    strncat(res_, str->text, 2047);
    return res_;
}

const char * nwn_Get2daString(C2DA *tda, const char* col, uint32_t row) {
    if ( !tda ) { return ""; }

    int loc = -1;
    size_t i;
    for ( i = 0; i < tda->tda_cols_len; ++i ) {
        if ( strcasecmp(col, tda->tda_cols[i].text) == 0 ) {
            loc = i;
            break;
        }
    }
    if ( loc == -1 ) { return ""; }

    return nwn_Get2daStringIdx(tda, loc, row);
}

int32_t nwn_Get2daInt(C2DA *tda, const char* col, uint32_t row) {

    int32_t result;
    if ( C2DA__GetINTEntry(tda, row, &col, &result) ) {
        return result;
    }

    return 0;
}

int32_t nwn_Get2daIntIdx(C2DA *tda, int col, uint32_t row) {

    int32_t result;
    if ( C2DA__GetINTEntry2(tda, row, col, &result) ) {
        return result;
    }

    return 0;
}

float nwn_Get2daFloat(C2DA *tda, const char* col, uint32_t row) {

    float result;
    if ( C2DA__GetFLOATEntry(tda, row, &col, &result) ) {
        return result;
    }

    return 0.0f;
}

float nwn_Get2daFloatIdx(C2DA *tda, int col, uint32_t row) {

    float result;
    if ( C2DA__GetFLOATEntry2(tda, row, col, &result) ) {
        return result;
    }

    return 0.0f;
}
