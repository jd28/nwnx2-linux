#ifndef TALIB_ALL_H
#define TALIB_ALL_H

#include "NWNXLib.h"
#include "talib/custom/armor_class.h"
#include "talib/custom/const.h"
#include "talib/custom/damage.h"
#include "talib/custom/damage_roll.h"
#include "talib/custom/dice.h"
#include "talib/custom/combat.h"
#include "talib/custom/versus_info.h"
#include "talib/custom/saves.h"

extern "C" {

// The following function must be called to initialize function pointers.
void talib_init();

#include "stack.h"
#include "player.h"
#include "creature.h"
#include "object.h"
#include "item.h"
#include "2da.h"
#include "area.h"
#include "effect.h"
#include "message.h"
#include "rules.h"
#include "module.h"
#include "waypoint.h"
#include "cexolocstring.h"
#include "tlk.h"
#include "damage.h"
#include "combat.h"
}

#endif // TALIB_ALL_H
