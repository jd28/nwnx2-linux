#ifndef TALIB_VERSUS_INFO_H
#define TALIB_VERSUS_INFO_H

#include "NWNXLib.h"

/**
   Abstracts all versus information.
*/
struct VersusInfo {
    explicit VersusInfo(CNWSCreature *obj) {
        if ( !obj ) {
            versus = NULL;
            race = RACIAL_TYPE_INVALID;
            goodevil = 0;
            lawchaos = 0;
            target = OBJECT_INVALID;
        }
        else {
            versus = obj;
            race = obj->cre_stats->cs_race;
            goodevil = 0; //cre->cre_stats->GetSimpleAlignmentGoodEvil();
            lawchaos = 0; //cre->cre_stats->GetSimpleAlignmentLawChaos();
            target = obj->obj.obj_id;
        }

        // Unimplimented.
        deity_id = 0;
        subrace_id = 0;
    }
    
    int32_t       race;
    int32_t       goodevil;
    int32_t       lawchaos;
    int32_t       deity_id;
    int32_t       subrace_id;
    uint32_t      target;
    CNWSCreature *versus;
};

#endif // _TALIB_VERSUS_INFO_H_
