find_path(LUAJIT_INCLUDE_DIR luajit.h
            NAMES luajit.h
            PATH_SUFFIXES luajit-2.0)

find_library(LUAJIT_LIBRARIES luajit NAMES luajit-5.1.a)

# Add the user's chosen flags to the build for this directory.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x -Wno-return-type")

include_directories(
    .
    ../../talib
    ${LUA_INCLUDE_DIR})

set(SOLSTICE_FUNCS_SRC
  funcs.h
  handle_request
  funcs/f_RemoveObjectFromCache
)

add_module(solstice NWNXSolstice plugin-solstice
    lua_funcs
    hook_functions
    solstice_funcs
    ${SOLSTICE_FUNCS_SRC}
    handles/hndl_ChatMessage
    handles/hndl_CombatMessage
    handles/hndl_ConversationEvent
    handles/hndl_EffectEvent
    handles/hndl_EquipEvent
    handles/hndl_Event
    handles/hndl_ItemPropEvent
    handles/hndl_PluginsLoaded
    hooks/h_ExecuteCommandDestroyObject
    hooks/h_RunScript
    hooks/h_GetFeatRemainingUses
    hooks/h_GetFeatTotalUses
    hooks/h_GetRunScriptReturnValue
    hooks/h_LoadModuleStart
    hooks/h_RunScriptSituation
    hooks/h_SetCombatMode
    hooks/h_ToggleMode
    local/l_GetLastChatMessage
    local/l_GetLastCombatMsg
    local/l_GetLastEffectEvent
    local/l_GetLastEquipEvent
    local/l_GetLastItemPropEvent
    local/l_GetLastNWNXEvent
    local/l_NWNXLog
    local/l_RunLuaScript

    profiler/profiler

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
