### nwnx_resources

This plugin is derived from the ResMan plugin by Dumbo and Virusman.
It **does not** include the hardcoded resman directory but does two things:

1. Expose NWNX events for resource existance and resource demands.
2. Caches all NCS scripts.  The cache is invalidated when a new file is found
in one of the observers.

Notes:
Existance event handlers should **never** return 1 and override.  All observers
must be queried to find the latest file.  So all existance event handlers should
follow a pattern like so:

 ```c++
 int HandleResourceExistsEvent(WPARAM p, LPARAM a) {
    ResManResExistsStruct *exists = reinterpret_cast<ResManResExistsStruct*>(p);
    if(PHYSFS_exists(exists->resRefWithExt)) {
        PHYSFS_sint64 t = PHYSFS_getLastModTime(exists->resRefWithExt);
        if (t != -1) {
            exists->mtime = std::max(exists->mtime, (time_t)t);
            exists->exists = true;
        }
    }
    return 0;
}
```

And all resource demand handlers should never override and return data unless the last modified time of one of their files
is greater than or equal to `ResManDemandResStruct::minimum_mtime` :

```c++
    ResManDemandResStruct *event = reinterpret_cast<ResManDemandResStruct*>(p);

    // If the file doesn't exist or the minimim required last modified time
    // is greater than what we have, we cannot service this file.
    if (!PHYSFS_exists(event->resref)
        || PHYSFS_getLastModTime(event->resref) == -1
        || event->minimum_mtime > (time_t)PHYSFS_getLastModTime(event->resref)) {
        physfs.Log(4, "Unable to service file: %s, Exists?: %d, Required mtime: %d, Our mtime: %d\n", event->resref, PHYSFS_exists(event->resref),
                   event->minimum_mtime, PHYSFS_getLastModTime(event->resref));
        return 0;
    }
```