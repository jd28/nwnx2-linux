#pragma once
#include "api/all.h"
#include "include/NwnDefines.h"
#include <time.h>
#include <string>

struct ContainerElement {
    ContainerElement () : size(0), internal(nullptr), mtime(0) {}
    ContainerElement (size_t size, time_t time, void* data = nullptr)
        : size(size)
        , internal(data)
        , mtime(time)
    {}
    bool valid() const { return size != 0; }

    size_t size;
    void *internal;
    time_t mtime;
};

class Container;

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
    bool valid() const { return !!container; }
};

class Container {
    std::string name;
public:
    virtual ContainerElement get(size_t index, CKeyTableEntry **) = 0;
    virtual ContainerElement get(const std::string& resref, CKeyTableEntry **) = 0;
    // Defaults to nullptr.
    virtual CExoKeyTable* GetKeyTable() { return nullptr; }
    const char* GetName() const { return name.c_str(); }
    void SetName(const char* n) { name = n; }
    virtual size_t Demand(const std::string& resref, ContainerElement element, void *data) = 0;
    virtual size_t size() const = 0;
    virtual ~Container() {}
};
