include_directories(. ../../talib)

# Add the user's chosen flags to the build for this directory.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_module(items NWNXItems plugin-items
    funcs/f_SetItempropHandler   

    handle_request
    hook_funcs
    hooks/h_CalculateBaseCosts
    hooks/h_CanEquipItem
    hooks/h_CanUnequipItem
    hooks/h_CanUseItem
    hooks/h_ComputeWeight
    hooks/h_GetIsHelmetHidden
    hooks/h_GetMinEquipLevel
    hooks/h_OnItemPropertyApplied
    hooks/h_OnItemPropertyRemoved
    hooks/h_UpdateAppearanceForEquips

    handles/hndl_ExamineEvent
    handles/hndl_ItemPropEvent

    local/l_GetIsHelmetHidden
    local/l_GetItemPropString
    local/l_ExamineItemEvent

    ../../talib/nwn/all
    ../../talib/itemprop/itemprops
)

target_link_libraries(items rt)
