#pragma once

#include "NWNXApi.h"
#include "containers/Erf.h"
#include "containers/Key.h"

#include <string>
#include <unordered_map>
#include <algorithm>
#include <boost/functional/hash.hpp>
#include <boost/container/flat_map.hpp>

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

using LookupTable = std::unordered_map<std::string, ResourceEntry>;

struct ResourceLocator {
    static ResourceEntry INVALID_ENTRY;
    LookupTable resources;
    std::vector<Container*> dynamics;
    std::vector<Container*> statics;

    void AddStatic(Container* cont);
    void AddDynamic(Container* cont);
    size_t Demand(CRes *cRes, char **data);
    ResourceEntry& Get(const CResRef &resref, uint16_t type, CExoKeyTable **v1);
    // Only checks the lookup table, it does not query for updated resource locations.
    ResourceEntry& GetCached(const std::string &resref);
};

struct ResourceManager {
    std::vector<NwnResType> cache;
    ResourceLocator locator;
    bool locked = false;
    size_t memory_used = 0;

    bool IsLocked() { return locked; }
    bool Lock(bool val) { return locked = val; }

    void AddStatic(Container *cont) { locator.AddStatic(cont); }
    void AddDynamic(Container* cont) { locator.AddDynamic(cont); }
    char *Allocate(size_t size, bool flag1, bool flag2);
    void Deallocate(char *data, bool flag1, bool flag2);
    bool HasContainer(const char* name);
    void SetCachedTypes(std::vector<NwnResType> cache_rtypes);
    bool IsCached(NwnResType rtpye);
    int GetKeyEntry(const CResRef& resref, uint16_t type, CExoKeyTable **table, CKeyTableEntry **v2)
    {
        ResourceEntry& e = locator.Get(resref, type, table);
        *v2 = e.key;
        return e.valid() ? 1 : 0;
    }

    char *Demand(CRes *cRes);

};
