#include "include/shelf.hpp"
#include "include/pallet.hpp"


Shelf::Shelf():
    pallets(std::array <Pallet, 4>{Pallet(), Pallet(), Pallet(), Pallet()})
{

}

//Swapping pallets
bool Shelf::swapPallet(int slot, int slot2)
{
    Pallet x = pallets[slot];
    pallets[slot] = pallets[slot2];
    pallets[slot2] = x;
    return true;
}

//Empty Shelfy
bool Shelf::isEmpty()
{
    for(Pallet& p : this->pallets){
        if(p.getItemCount() > 0){
            return false;
        }
    }
    return true;
    

}

//Shelf is full
bool Shelf::isFull()
{
    for(Pallet& p : pallets){
        if(p.getRemainingSpace() == 0)
        return true;
    }
    return false;
}

