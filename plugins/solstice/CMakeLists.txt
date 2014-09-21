find_path(LUAJIT_INCLUDE_DIR luajit.h
            NAMES luajit.h
            PATH_SUFFIXES luajit-2.0)

find_library(LUAJIT_LIBRARIES luajit NAMES luajit-5.1.a)

# Add the user's chosen flags to the build for this directory.
set(CMAKE_CXX_FLAGS "-mtune=i386 -m32 -Wall -Wno-unused -Wno-write-strings -std=c++11 -O3")

include_directories(
    .
    ../../talib
    ${LUA_INCLUDE_DIR}
    ${Boost_INCLUDE_DIR})

set(SOLSTICE_FUNCS_SRC
  funcs.h
  handle_request
  funcs/f_RemoveObjectFromCache
)

set(SOLSTICE_LUAFUNCS_SRC
  lua_funcs.h
  lua_funcs.cpp
)

add_module(solstice NWNXSolstice plugin-solstice
    hook_functions
    solstice_funcs
    ${SOLSTICE_LUAFUNCS_SRC}
    ${SOLSTICE_FUNCS_SRC}
    handles/hndl_ChatMessage
    handles/hndl_CombatMessage
    handles/hndl_ConversationEvent
    handles/hndl_EffectEvent
    handles/hndl_EquipEvent
    handles/hndl_Event
    handles/hndl_ItemPropEvent
    handles/hndl_PluginsLoaded
    hooks/h_AddAttackOfOpportunity
    hooks/h_DoDamageImmunity
    hooks/h_DoDamageReduction
    hooks/h_DoDamageResistance
    hooks/h_Effects
    hooks/h_RunScript
    hooks/h_GetArmorClass
    hooks/h_GetCriticalHitRoll
    hooks/h_GetCriticalHitMultiplier
    hooks/h_GetFeatRemainingUses
    hooks/h_GetFeatTotalUses
    hooks/h_GetMaxHitpoints
    hooks/h_GetRunScriptReturnValue
    hooks/h_GetWeaponFinesse
    hooks/h_InitializeNumberOfAttacks
    hooks/h_LoadModuleStart
    hooks/h_Polymorph
    hooks/h_ResolveMeleeAttack
    hooks/h_ResolveRangedAttack
    hooks/h_RunScriptSituation
    hooks/h_SetCombatMode
    hooks/h_ToggleMode
    hooks/h_Unpolymorph
    hooks/h_UpdateCombatInformation
    local/l_GetCreature
    local/l_DeleteCreature
    local/l_GetCombatInfo
    local/l_GetLastChatMessage
    local/l_GetLastCombatMsg
    local/l_GetLastEffectEvent
    local/l_GetLastEquipEvent
    local/l_GetLastItemPropEvent
    local/l_GetLastNWNXEvent
    local/l_NWNXLog
    local/l_RunLuaScript
    local/l_GetPoly2da
    local/l_GetPolyEffect
    local/l_SetDamageInfo

    combat/Attack

    object/Creature

    ../../talib/nwn/all
    ../../talib/effects/itemprop
    ../../talib/effects/creation
)
message(${CMAKE_MODULE_LINKER_FLAGS})
set(CMAKE_MODULE_LINKER_FLAGS ${CMAKE_MODULE_LINKER_FLAGS} -Wl,-E
CACHE STRING "Flags used by the linker during the creation.")

target_link_libraries(solstice
  rt
  libluajit-5.1.a)
