/***************************************************************************
    NWNXEffects
    Copyright (C) 2011-2012 jmd ( jmd2028 at gmail dot com )

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
***************************************************************************/

#ifndef NWNX_EFFECTS_H
#define NWNX_EFFECTS_H

#include "NWNXLib.h"
#include "talib/nwn/all.h"
#include "nwnx_modules_ext.h"
#include "hooks.h"

#include <string>

extern int (*CExoArrayList__CGameEffect_Add)(CExoArrayList_ptr *list, CGameEffect *eff);

#include "NWNXBase.h"

class CNWNXEffects:public CNWNXBase {
public:
    CNWNXEffects ();
    virtual ~ CNWNXEffects ();

    bool OnCreate (gline *nwnxConfig, const char *LogDir = NULL);
    char *OnRequest (char *gameObject, char *Request, char *Parameters);
    unsigned long OnRequestObject (char *gameObject, char *Request);

    void EffectEvent(CNWSObject *obj, CGameEffect *eff, bool removal);
    void CustomEffectEvent(CNWSObject *obj, CGameEffect *eff, bool removal);

    // script variables.
    EventEffect effect_event;
    EventEffect custom_effect_event;


private:
    HANDLE hOnEffectEvent;
    HANDLE hOnCustomEffectEvent;
};

#endif /* NWNX_EFFECTS_H */
