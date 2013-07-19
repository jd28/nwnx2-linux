#ifndef TALIB_CUSTOM_SAVES_H
#define TALIB_CUSTOM_SAVES_H

#include <algorithm>
#include "talib/custom/attribute.h"

class Saves {
    Attribute reflex;
    Attribute fort;
    Attribute will;
    Attribute versus[20];

public:
    enum types {
        ALL = 0,
        FORTITUDE = 1,
        REFLEX = 2,
        WILL = 3,
        NUM = 4
    };
    
    Saves() 
        : reflex()
        , fort()
        , will() {
        std::fill_n(versus, 20, Attribute());
    }

    int32_t getSave(types type, Attribute::selector select) {
        switch(type){
        default: return 0;
        case FORTITUDE: return fort.get(select);
        case REFLEX: return reflex.get(select);
        case WILL: return will.get(select);
        }        
    }

    void setSave(types type, int32_t val, Attribute::selector select) {
        switch(type){
        default: return;
        case FORTITUDE: return fort.set(val, select);
        case REFLEX: return reflex.set(val, select);
        case WILL: return will.set(val, select);
        }        
    }

    void modifySave(types type, int32_t val, Attribute::selector select) {
        switch(type){
        default:
            fort.modify(val, select);
            reflex.modify(val, select);
            will.modify(val, select);
            break;
        case FORTITUDE: fort.modify(val, select);   break;
        case REFLEX:    reflex.modify(val, select); break;
        case WILL:      will.modify(val, select);   break;
        }        
    }

    int32_t getVersus(uint32_t vs, Attribute::selector select) {
        if ( vs >= 20 ) { return 0; }
        return versus[vs].get(select);
    }

    void modifyVersus(uint32_t vs, int32_t amount, Attribute::selector select) {
        if ( vs >= 20 ) { return; }
        versus[vs].modify(amount, select);
    }
};

#endif // TALIB_CUSTOM_SAVES_H
