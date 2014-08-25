add_module(resources ../../api/nwnsyms.S ../../api/all
   HookDemandRes NwnDefines NWNXResources plugin-resources)

set_target_properties(resources PROPERTIES
        COMPILE_FLAGS "-std=c++0x -Wno-deprecated -Wno-return-type")
