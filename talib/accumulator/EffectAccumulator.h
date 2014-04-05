#ifndef TALIB_EFFECT_ACCUMULATOR_H
#define TALIB_EFFECT_ACCUMULATOR_H

#include <array>
#include <vector>
#include <unordered_map>

#include "talib/nwn/all.h"
#include "talib/custom/versus_info.h"
#include "talib/util/math.h"

const int MAX_MODS_PER_TYPE = 10;

template <typename T, typename U, int N = MAX_MODS_PER_TYPE>
struct EffectAccumulator {
    EffectAccumulator(CNWSCreature *cre, VersusInfo vs, int32_t type,
                      bool item_stack, bool spell_stack, uint32_t index)
        : vs_(vs),
          type_(type),
          item_stack_(item_stack),
          spell_stack_(spell_stack),
          index_(index) {

        idx = 0;
        obj_ = cre;
        accumulated_ = false;
        resulted_ = false;
    }

    virtual void accumulate() {
        int len = obj_->obj.obj_effects_len;

        for (int i = index_; i < len; ++i){
            CGameEffect *eff = obj_->obj.obj_effects[i];
            if ( eff->eff_type > type_ ) { break; }
            if ( !in_range(eff->eff_type) ) { continue; }
            if ( !is_valid(eff) ) { continue; }

            T amount         = get_amount(eff);
            bool add_effect  = false;
            uint32_t creator = eff->eff_creator;
            int32_t subtype  = get_subtype(eff);
            int true_type    = eff->eff_type;
            int spellid      = eff->eff_spellid;

            if ( !item_stack_ && nwn_GetItemByID(creator) != NULL && i < len - 1 ) {
                //nx_log(NX_LOG_NOTICE, 0, "Start item: i: %d, id: %x", i, creator);
                CGameEffect *next_eff;
                for ( ; i < len-1; ++i ) {
                    next_eff = obj_->obj.obj_effects[i+1];
                    if ( next_eff->eff_creator != creator ||
                         true_type != next_eff->eff_type  ||
                         subtype != get_subtype(next_eff) ) {
                        break;
                    }
                    if ( !is_valid(next_eff) ) { continue; }
                    amount = get_max(amount, get_amount(next_eff));
                }
                //nx_log(NX_LOG_NOTICE, 0, "End item: i: %d, id: %x", i, creator);
            }
            else if ( !spell_stack_ && spellid != -1 && i < len - 1) {
                //nx_log(NX_LOG_NOTICE, 0, "Start spell: i: %d, id: %d", i, spellid);

                CGameEffect *next_eff;
                for ( ; i < len-1; ++i ) {
                    next_eff = obj_->obj.obj_effects[i+1];
                    if ( next_eff->eff_spellid != spellid ||
                         true_type != next_eff->eff_type  ||
                         subtype != get_subtype(next_eff) ) {
                        break;
                    }
                    if ( !is_valid(next_eff) ) { continue; }
                    amount = get_max(amount, get_amount(next_eff));
                }
                //nx_log(NX_LOG_NOTICE, 0, "End spell: i: %d, id: %d", i, spellid);
            }

            add(amount);
        }
    }

    virtual bool in_range(int32_t type) {
        return type == type_;
    }

    void add(T amount) {
        if ( idx < amounts.size() ) {
            amounts[idx++] = amount;
        }
    }

    virtual T get_amount(CGameEffect *eff)        = 0;
    virtual T get_max(T a, T b)                   = 0;
    virtual U get_result()                        = 0;
    virtual int32_t get_subtype(CGameEffect *eff) = 0;
    virtual bool is_valid(CGameEffect *eff)       = 0;

    std::array<T, N> amounts;
    uint32_t idx;

    CNWSCreature *obj_;
    VersusInfo vs_;

    int32_t type_;
    bool item_stack_;
    bool spell_stack_;

    bool accumulated_;
    bool resulted_;
    U result_;
    int32_t index_;
};

#endif // TALIB_EFFECT_ACCUMULATOR_H
