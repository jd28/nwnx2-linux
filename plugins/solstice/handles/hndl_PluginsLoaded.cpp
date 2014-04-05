#include "NWNXSolstice.h"

extern CNWNXSolstice solstice;

#define HOOK(orig, addr, hook, bytes) \
    *(void**)&orig = nx_hook_function((void*)addr, (void*)hook, bytes, NX_HOOK_DIRECT | NX_HOOK_RETCODE)

int Handle_PluginsLoaded(WPARAM p, LPARAM a) {
    if (!solstice.InitializeEventHandlers())
	solstice.Log(0, "ERROR: Unable to initialize NWNX event handlers!");

    HOOK(CNWSCombatRound__InitializeNumberOfAttacks, 0x080E2260, Hook_InitializeNumberOfAttacks, 5);
    HOOK(CNWSCreature__GetMaxHitPoints, 0x0812E25C, Hook_GetMaxHitpoints, 5);

    return 0;
}
