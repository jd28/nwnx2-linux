if (gperf)

add_gperf_target(tweaks TweaksStrCmds TweaksStr TWEAKS STR)
add_gperf_target(tweaks TweaksObjCmds TweaksObj TWEAKS OBJ)

include_directories(
    .
    ../../api
)

add_module(tweaks
    NWNXTweaks
    plugin-tweaks
    TweaksStrCmds
    TweaksObjCmds

    funcs/f_GetTweakOption
    funcs/f_IntToObject
    funcs/f_SetTweakOption
    hooks/h_FixSendFeedbackMessage
    hooks/h_EvaluateOverlappingTargets
    tables/t_TweakOptions
)

endif (gperf)
