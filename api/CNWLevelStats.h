#ifndef _CNWLEVELSTATS_H_
#define _CNWLEVELSTATS_H_
#include "nwndef.h"
#include "CExoArrayList.h"

class CNWLevelStats
{
public:
    void AddFeat(unsigned short);
    int ClearFeats();
    char GetSkillRankChange(unsigned short);
    void SetSkillRankChange(unsigned short, char);
    ~CNWLevelStats();
    CNWLevelStats();

    CExoArrayList<unsigned long> SpellsKnown[10];
    CExoArrayList<unsigned long> SpellsRemoved[10];
    CExoArrayList<unsigned short> FeatList;
    uint8_t *Skills;
    /* 0100 */ uint16_t Skillpoints;
    uint8_t Ability;
    uint8_t HP;
    /* 0104 */ uint8_t Class;
    /* 0105 */ uint8_t rsvd1[3];
    /* 0108 */ uint8_t EpicLevel;
    /* 0109 */ uint8_t rsvd2[3];
};

static_assert(sizeof(CNWLevelStats) == 0x10C, "CNWLevelStats has an incorrect size");
#endif
