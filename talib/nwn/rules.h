#ifndef TALIB_RULES_H
#define TALIB_RULES_H

bool        nwn_GetIsClassBonusFeat(int32_t cls, uint16_t feat);
bool        nwn_GetIsClassGeneralFeat(int32_t cls, uint16_t feat);
uint8_t     nwn_GetIsClassGrantedFeat(int32_t cls, uint16_t feat);
int32_t     nwn_GetIsClassSkill (int32_t idx, uint16_t skill);
CNWFeat    *nwn_GetFeat(uint32_t);
CNWSkill   *nwn_GetSkill(uint32_t skill);
const char *nwn_GetSkillName(uint32_t skill);
const char *nwn_GetAbilityName(uint32_t abil);
const char *nwn_GetArmorClassName(uint32_t val);
const char *nwn_GetMiscImmunityName(uint32_t val);
CNWRace    *nwn_GetRace(uint32_t race);

#endif // TALIB_RULES_H
