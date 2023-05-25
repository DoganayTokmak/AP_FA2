#include "include/pallet.hpp"

Pallet::Pallet(std::string ItemName, int ItemCapacity, int ItemCount) :
    ItemName(ItemName),
    ItemCapacity(ItemCapacity),
    ItemCount(ItemCount)
{

}
//Pallet default
Pallet::Pallet() : Pallet("", 0, 0)
{
    
}

//Pallet ItemName
std::string Pallet::getItemName()
{
    return ItemName;
}

//Amount of Items
int Pallet::getItemCount()
{
    return ItemCount;
}

//Remainingspace on a pallet
int Pallet::getRemainingSpace()
{
    return ItemCapacity - ItemCount;
}

//Pallet reallocate
bool Pallet::reallocateEmptyPallet(std::string ItemName, int ItemCapacity)
{   
    if (ItemCount == 0){
        this-> ItemName = ItemName;
        this-> ItemCapacity = ItemCapacity;
        return true;
    }
    return false;
}

//Take one product
bool Pallet::takeOne()
{   
    if (!isEmpty())
    {
        ItemCount --;
        return true;
    } 
    return false;
}

//Put one product
bool Pallet::putOne()
{
    if (!isFull())
    {
        ItemCount ++;
        return true;
    }
    return false;
}



//Pallet is empty
bool Pallet::isEmpty() 
{
    if( ItemCount == 0){
        return true;
    }
    return false;

}

//Pallet is full
bool Pallet::isFull() 
{
    if( getRemainingSpace() == 0){
       return true;
    }
    return false;

};
