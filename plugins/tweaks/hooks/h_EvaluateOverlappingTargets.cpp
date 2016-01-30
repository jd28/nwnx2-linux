#include "NWNXTweaks.h"

extern CNWNXTweaks tweaks;

int32_t (*CNWSArea__EvaluateOverlappingTargets)(
        CNWSArea *, CPathfindInformation *, Vector, uint32_t, float, float, float,
        int, int, uint32_t *) = reinterpret_cast<decltype(CNWSArea__EvaluateOverlappingTargets)>(0x080DA5C8);

// If the result of this function is 0 there are non-bumpable creatures on the
// object's path, 1 if not (or cutscene ghost, etc).
int32_t CNWSArea__EvaluateOverlappingTargets_Hook(CNWSArea *area, CPathfindInformation *pi,
                                                  Vector a3, uint32_t object, float a5,
                                                  float a6, float a7, int a8, int a9,
                                                  uint32_t *a10)
{
    CNWSCreature* cre1 = g_pAppManager->ServerExoApp->GetCreatureByGameObjectID(pi->Owner);
    CNWSCreature* cre2 = g_pAppManager->ServerExoApp->GetCreatureByGameObjectID(object);

    int32_t result = 0;
    if(cre1 && cre2 && cre1->IsPC && cre2->IsPC) {
        result = 1;
    }
    else {
        result = CNWSArea__EvaluateOverlappingTargets(area, pi, a3, object, a5, a6, a7, a8, a9, a10);
    }
    return result;
}

void HookEvaluateOverlappingTargets() {
    NX_HOOK(CNWSArea__EvaluateOverlappingTargets,
            0x080DA5C8,
            CNWSArea__EvaluateOverlappingTargets_Hook,
            5);
}
