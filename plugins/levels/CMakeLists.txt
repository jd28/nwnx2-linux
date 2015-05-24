set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(
    .
    ../../talib)

add_module(levels NWNXLevels plugin-levels
    funcs/f_GetMaxLevelLimit
    funcs/f_LevelUp
    funcs/f_LevelDown
    funcs/f_ModifyXPDirect
    funcs/f_SetMaxLevelLimit
    funcs/f_SetXPDirect
    funcs/f_GetMeetsFeatRequirements

    hooks/h_GetSpellGain
    hooks/h_GetSpellsKnownPerLevel
    hooks/h_SummonAnimalCompanion
    hooks/h_SummonFamiliar

    ../../talib/nwn/all
)
