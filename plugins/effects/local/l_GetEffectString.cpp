#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "NWNXEffects.h"
#include "talib/nwn/effect.h"
#include "talib/effects/creation.h"

std::string Local_GetEffectString(CNWSObject *obj) {
    std::ostringstream out;
    out << "Effects (" << obj->obj_effects_len << ") on Object: 0x";
    out << std::hex << obj->obj_id << std::dec << '\n';

    CGameEffect *e;
    for ( int i = 0; i < obj->obj_effects_len; ++i ) {
        e = obj->obj_effects[i];
        out << "#" << i << ":\n";
        out << "  ID: " << e->eff_id;
        out << "  Type: " << e->eff_type;
        out << "  Creator: 0x" << std::hex << e->eff_creator << std::dec;
        out << "  Spell ID: " << e->eff_spellid;
        out << "  Duration Type: " << nwn_GetDurationType(e);
        out << "  Subtype: " << nwn_GetSubType(e);
        out << "  Duration: " << e->eff_duration << '\n';
	    
        out << "  Expires Day: " 
            << e->eff_expire_day << " Time: "
            << e->eff_expire_time << '\n';

        out << "  Ints: ";
        for ( int j = 0; j < e->eff_num_integers; ++j ) {
            out << e->eff_integers[j] << "; ";
        }
        out << '\n';

        out << "  Floats: " << std::setprecision (2);
        for ( int j = 0; j < 4; ++j ) {
            out << e->eff_floats[j] << "; ";
        }
        out << '\n';

        out << "  Strings: ";
        //for ( int j = 0; j < 6; ++j ) {
        //    out << e->eff_strings[j].text << "; ";
        //}
        out << '\n';
	
        out << "  Objects: " << std::hex;
        for ( int j = 0; j < 4; ++j ) {
            out << e->eff_objects[j] << "; ";
        }
        out << std::dec << '\n';
    }

    return out.str();
}
