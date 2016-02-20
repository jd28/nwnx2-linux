#pragma once

#include "NWNXApi.h"
#include "containers/Erf.h"
#include "containers/Key.h"

#include <string>
#include <unordered_map>
#include <algorithm>

static char resref_to_fname_buffer[21];
inline const char* resref_to_fname(const CResRef& resref, uint16_t type) {
    memset(resref_to_fname_buffer, 0, 21);
    const char* resExt = NwnGetResTypeExtension((NwnResType)type);
    strncat(resref_to_fname_buffer, resref.m_resRef, 16);
    strcat(resref_to_fname_buffer, ".");
    if(!resExt) {
        return "";
        //Log(0, "Invalid Res Type: %d\n", type);
    }
    strcat(resref_to_fname_buffer, resExt);
    return resref_to_fname_buffer;
}

struct ResourceEntry {
    Container *container = nullptr;
    CKeyTableEntry *key = nullptr;
    ContainerElement element;
    bool dynamic = false;
    time_t last_demand = 0;
    char *cache = nullptr;

    ResourceEntry() = default;
    ResourceEntry(Container *cont, CKeyTableEntry *k,
                  ContainerElement ele, bool dynamic = false)
        : container(cont)
        , key(k)
        , element(ele)
        , dynamic{dynamic}
    {}

    // Validity is determined solely by whether container is not null.
    bool valid() const { return !!container; }
};

class ResourceLocator {
    using LookupTable = std::unordered_map<std::string, ResourceEntry>;

    static ResourceEntry INVALID_ENTRY;
    static std::string resref_cache;

    LookupTable resources;
    std::vector<Container*> dynamics;
    std::vector<Container*> statics;

public:
    // Add a dynamic container.  These are containers that can load resources from
    // any location.
    void AddDynamic(Container* cont);

    // Add a static container.  These are containers whose contents never change.
    // E,g. Erf, Zip, Key/Bif, etc.
    void AddStatic(Container* cont);

    // Only checks the lookup table, it does not query for updated resource.
    ResourceEntry& Get(const std::string &resref);

    bool HasContainer(const char *name) const;

    // Query for a ResourceEntry.  This will check all dynamic containers for the
    // most recently modified version of a resource.
    ResourceEntry& Query(const CResRef &resref, uint16_t type, CExoKeyTable **v1);

};

class ResourceManager {
    static std::string resref_cache;
    std::vector<NwnResType> cache;
    ResourceLocator locator;
    size_t memory_used = 0;
    size_t memory_usage_limit = 0;

public:
    // Add a static container.  These are containers whose contents never change.
    // E,g. Erf, Zip, Key/Bif, etc.
    void AddStatic(Container *cont) { locator.AddStatic(cont); }

    // Add a dynamic container.  These are containers that can load resources from
    // any location.
    void AddDynamic(Container* cont) { locator.AddDynamic(cont); }

    // Allocates a chunk of memory.  The actual size allocated is dependent on
    // the flags passed in.  This is due to the vagaries of some NWN resource
    // types.
    char *Allocate(size_t size, bool flag1, bool flag2);

    // Deallocate a chunk of memory.
    void Deallocate(char *data, bool flag1, bool flag2);

    // Find and returns the data for a resource.
    char *Demand(CRes *cRes);

    // Bridge between our resource manager and nwserver CExoResMan.  Basically a thin wrapper
    // around ResourceLocater::Query
    int GetKeyEntry(const CResRef& resref, uint16_t type, CExoKeyTable **table, CKeyTableEntry **v2);

    // Get the amount of memory that is currently allocated.
    size_t GetMemoryUsed() { return memory_used; }

    // Determines if we alread have a container of a particular name.  Note that
    // for Key/Bif, Mod, Hak, and Override the name will be the aliased name.
    // i.e. 'HAK:myhak'
    bool HasContainer(const char* name) const { return locator.HasContainer(name); };

    // Checks if a particular resource is one that is cached.
    bool IsCached(NwnResType rtpye);

    // Sets the types that will be cached and (currently) never freed.
    void SetCachedTypes(std::vector<NwnResType> cache_rtypes);

    // Sets the limit for memory useage; Not currently implemented.
    void SetMemoryUsageLimit(size_t size) { memory_usage_limit = size; }
};


