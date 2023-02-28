#include "hmap.h"
#include <iostream>

template <typename KeyType, typename ValueType>
HMap<KeyType, ValueType>::HMap(size_t tableSize, std::function<size_t(const KeyType&)> _h)
    :size(tableSize), h(_h)
{
    table = new HMap<KeyType, ValueType>::TableEntry * [tableSize];
    for (int i = 0; i < size; ++i)
    {
        table[i] = nullptr;
    }
}
template <typename KeyType, typename ValueType>
HMap<KeyType, ValueType>::HMap(const HMap<KeyType, ValueType>& other)
{
   //to do
}
template <typename KeyType, typename ValueType>
HMap<KeyType, ValueType> HMap<KeyType, ValueType>::operator=(const HMap<KeyType, ValueType>& other)
{
   //to do
}
template <typename KeyType, typename ValueType>
ValueType& HMap<KeyType, ValueType>::operator[](const KeyType& key)
{
    HMap<KeyType, ValueType>::TableEntry* current = lookup(key);

    if (current != nullptr)
    {
        return current->value;
    }

    size_t index = h(key) % size;

    ValueType dummy{};
    table[index] = new HMap<KeyType, ValueType>::TableEntry{ key,dummy,table[index] };

    return table[index]->value;
}
template <typename KeyType, typename ValueType>
ValueType HMap<KeyType, ValueType>::operator[](const KeyType& key) const
{

    typename HMap<KeyType, ValueType>::TableEntry* current = lookup(key);

    if (current == nullptr)
        throw "Key not found!";

    return current->value;


}
template <typename KeyType,typename ValueType>
void HMap<typename KeyType, typename ValueType>::printKeyValue()const
{
    for (int i = 0; i < size; i++)
    {
        std::cout << table[i]->key << " " << table[i]->value << std::endl;
    }
}
template <typename KeyType, typename ValueType>
typename HMap<KeyType, ValueType>::TableEntry* HMap<KeyType, ValueType>::lookup(const KeyType& key)
{
    size_t index = h(key) % size;

    typename HMap<KeyType, ValueType>::TableEntry* current = table[index];

    while (current != nullptr && current->key != key)
    {
        current = current->next;
    }

    return current;
}
template <typename KeyType, typename ValueType>
void HMap<KeyType, ValueType>::destroy()
{
    for (int i = 0; i < size; i++)
    {
        HMap<KeyType, ValueType>::TableEntry* current = table[i];
        while (table[i] != nullptr)
        {
            current = table[i]->next;
            delete table[i];
            table[i] = current;
        }
    }
}
template <typename KeyType, typename ValueType>
HMap<KeyType, ValueType>::~HMap()
{
    destroy();
}