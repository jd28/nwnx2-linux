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

    /* / */ CExoArrayList<unsigned long> SpellsKnown[10];
    /* / */ CExoArrayList<unsigned long> SpellsRemoved[10];
    /* / */ CExoArrayList<unsigned short> FeatList;
    /* / */ unsigned char *Skills;
    /* 0x100 */ unsigned short Skillpoints;
    /* 0x102/ */ unsigned char Ability;
    /* 0x103/ */ unsigned char HP;
    /* 0x104 */ unsigned char Class;
    /* 0x105 */ unsigned char rsvd1[3];
    /* 0x108 */ unsigned char EpicLevel;
    /* 0x109 */ unsigned char rsvd2[3];
};

static_assert_size(CNWLevelStats, 0x10C);

#endif
