#pragma once
#include <functional>

template <typename KeyType, typename ValueType>
class HMap
{
private:

    struct TableEntry
    {
        KeyType key;
        ValueType value;
        TableEntry* next;
    };

    TableEntry** table;
    size_t size;
    std::function<size_t(const KeyType&)> h;

    TableEntry* lookup(const KeyType&);
    void destroy();

public:

    HMap(size_t tableSize, std::function<size_t(const KeyType&)>);
    HMap(const HMap<KeyType, ValueType>&);
    HMap<KeyType, ValueType> operator=(const HMap<KeyType, ValueType>&);

    ValueType& operator[](const KeyType&);
    ValueType operator[](const KeyType&) const;

    void printKeyValue()const;

    ~HMap();

};
