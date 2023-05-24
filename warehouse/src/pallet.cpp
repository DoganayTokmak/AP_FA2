#include "include/pallet.hpp"

Pallet::Pallet(std::string ItemName, int ItemCapacity, int ItemCount) :
    ItemName(ItemName),
    ItemCapacity(ItemCapacity),
    ItemCount(ItemCount)
{

}
Pallet::Pallet() : Pallet("", 0, 0)
{
    
}

std::string Pallet::getItemName()
{
    return ItemName;
}

int Pallet::getItemCount()
{
    return ItemCount;
}
int Pallet::getRemainingSpace()
{
    return ItemCapacity - ItemCount;
}
bool Pallet::reallocateEmptyPallet(std::string ItemName, int ItemCapacity)
{   
    if (ItemCount == 0){
        this-> ItemName = ItemName;
        this-> ItemCapacity = ItemCapacity;
        return true;
    }
    return false;
}
bool Pallet::takeOne()
{
    return ItemCount - 1;
}
bool Pallet::putOne()
{
    return ItemCount + 1;
}




bool Pallet::isEmpty() 
{
    if( ItemCount == 0){
        return true;
    }
    return false;

}
bool Pallet::isFull() 
{
    if( getRemainingSpace() == 0){
       return true;
    }
    return false;

};
