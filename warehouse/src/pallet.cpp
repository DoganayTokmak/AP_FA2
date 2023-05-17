#include "include/pallet.hpp"

Pallet::Pallet(std::string itemName, int itemCapacity, int itemCount) :
    itemName(itemName),
    itemCapacity(itemCapacity),
    itemCount(itemCount)
{

}
Pallet::Pallet() : Pallet("", 0, 0)
{
    
}

std::string Pallet::getitemName()
{
    return itemName;
}

int Pallet::getitemCount()
{
    return itemCount;
}
int Pallet::getRemainingSpace()
{
    return itemCapacity - itemCount;
}
bool Pallet::reallocateEmptyPallet(std::string itemName, int itemCapacity)
{   
    if (itemCount == 0){
        this-> itemName = itemName;
        this-> itemCapacity = itemCapacity;
        return true;
    }
    return false;
}
bool Pallet::takeOne()
{
    return itemCount - 1;
}
bool Pallet::putOne()
{
    return itemCount + 1;
}
