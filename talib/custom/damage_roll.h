#ifndef TALIB_CUSTOM_DAMAGE_ROLL_H
#define TALIB_CUSTOM_DAMAGE_ROLL_H

#include "damage.h"
#include "combat.h"

#include <string>
#include <sstream>
/*
struct DamageResult {
    DamageResult(CombatWeapon * weapon,
                 std::vector<DamageAmount>* eff_misc,
                 std::vector<DamageAmount>* eff_atk)
        : wpn(weapon),
          emisc(eff_misc),
          eatk(eff_atk) {
        std::fill_n(damages, 13, 0);
        std::fill_n(immunity_adjust, 13, 0);
        std::fill_n(resist_adjust, 13, 0);
        std::fill_n(mod_adjust, 13, 0);
        soak_adjust = 0;
    }

    int32_t    damages[13];
    int32_t    immunity_adjust[13];
    int32_t    resist_adjust[13];
    int32_t    mod_adjust[13];
    int32_t    soak_adjust;

    void roll(uint32_t mult = 1) {
        if ( mult <= 0 || mult > 20 ) { mult = 1; }

        if ( wpn ) {
            for ( auto it = wpn->damage.begin(); it != wpn->damage.end(); ++it ) {
                if ( it->type < 0 || it->type > 12 ) { continue; }

                if ( it->penalty ) {
                    damages[it->type] -= it->roll.roll(mult);
                }
                else {
                    damages[it->type] += it->roll.roll(mult);
                }
            }
        }

        if ( emisc ) {
            for ( auto it = emisc->begin(); it != emisc->end(); ++it ) {
                if ( it->type < 0 || it->type > 12 ) { continue; }

                if ( it->penalty ) {
                    damages[it->type] -= it->roll.roll(mult);
                }
                else {
                    damages[it->type] += it->roll.roll(mult);
                }
            }
        }

        if ( eatk ) {
            for ( auto it = eatk->begin(); it != eatk->end(); ++it ) {
                if ( it->type < 0 || it->type > 12 ) { continue; }

                if ( it->penalty ) {
                    damages[it->type] -= it->roll.roll(mult);
                }
                else {
                    damages[it->type] += it->roll.roll(mult);
                }
            }
        }

        if ( wpn && mult > 1 ) {
            for ( auto it = wpn->crit_dmg.begin(); it != wpn->crit_dmg.end(); ++it ) {
                if ( it->type < 0 || it->type > 12 ) { continue; }

                if ( it->penalty ) {
                    damages[it->type] -= it->roll.roll();
                }
                else {
                    damages[it->type] += it->roll.roll();
                }
            }
        }

        if ( wpn ) {
            add(DamageAmount(DAMAGE_INDEX_BASE_WEAPON,
                             wpn->base_dmg_roll,
                             false),
                mult);

            add(DamageAmount(DAMAGE_INDEX_BASE_WEAPON,
                             DiceRoll(0, 0, wpn->dmg_ability),
                             false),
                mult);
        }
    }

    void add(const DamageAmount& dmg, uint32_t mult = 1) {
        if ( dmg.type < 0 || dmg.type > 12 ) { return; }

        for ( uint32_t m = 0; m < mult; ++m ) {
            if ( dmg.penalty ) {
                damages[dmg.type] -= dmg.roll.roll();
            }
            else {
                damages[dmg.type] += dmg.roll.roll();
            }
        }
    }

    void compactPhysicals() {
        damages[DAMAGE_INDEX_BASE_WEAPON] += damages[DAMAGE_INDEX_BLUDGEONING];
        damages[DAMAGE_INDEX_BLUDGEONING] = 0;
        damages[DAMAGE_INDEX_BASE_WEAPON] += damages[DAMAGE_INDEX_PIERCING];
        damages[DAMAGE_INDEX_PIERCING] = 0;
        damages[DAMAGE_INDEX_BASE_WEAPON] += damages[DAMAGE_INDEX_SLASHING];
        damages[DAMAGE_INDEX_SLASHING] = 0;
    }

    void finalize() {
        for ( size_t i = 0; i < 13; ++i ) {
            damages[i] = std::max(0, damages[i] - immunity_adjust[i]);
        }
        for ( size_t i = 0; i < 13; ++i ) {
            damages[i] = std::max(0, damages[i] - resist_adjust[i]);
        }
        // for ( size_t i = 0; i < 13; ++i ) {
        //     damages[i] = std::max(0, damages[i] - mod_adjust[i])
        // }

        damages[12] = std::max(0, damages[12] - soak_adjust);
    }

    int32_t get_total() {
        int32_t total = 0;
        for ( int i = 0; i < 13; ++i ) {
            total += damages[i];
        }
        return total;
    }

    std::string toString() {
        std::stringstream out;

        out << "Damages:\n";
        for ( size_t i = 0; i < 13; ++i ) {
            if ( damages[i] > 0 ) {
                out << "    "
                    << DamageIndexToString(i)
                    << ": "
                    << damages[i]
                    << '\n';
            }
        }
        out << "Immunity Adjustments:\n";
        for ( size_t i = 0; i < 13; ++i ) {
            if ( resist_adjust[i] > 0 ) {
                out << "    "
                    << DamageIndexToString(i)
                    << ": "
                    << immunity_adjust[i]
                    << '\n';
            }
        }
        out << "Resistance Adjustments:\n";
        for ( size_t i = 0; i < 13; ++i ) {
            if ( resist_adjust[i] > 0 ) {
                out << "    "
                    << DamageIndexToString(i)
                    << ": "
                    << resist_adjust[i]
                    << '\n';
            }
        }
        out << "Mod Adjustments:\n";
        for ( size_t i = 0; i < 13; ++i ) {
            if ( mod_adjust[i] > 0 ) {
                out << "    "
                    << DamageIndexToString(i)
                    << ": "
                    << mod_adjust[i]
                    << '\n';
            }
        }
        if ( soak_adjust > 0 ) {
            out << "Soak adjustment: " << soak_adjust << '\n';
        }

        return out.str();
    }
};
*/
#endif // TALIB_CUSTOM_DAMAGE_ROLL_H
