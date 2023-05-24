#include "include/shelf.hpp"
#include "include/pallet.hpp"


Shelf::Shelf():
    pallets(std::array <Pallet, 4>{Pallet(), Pallet(), Pallet(), Pallet()})
{

}

bool Shelf::swapPallet(int slot, int slot2)
{
    int x = slot;
    slot = slot2;
    slot2 = x;
    return slot, slot2;
}

bool Shelf::isEmpty()
{
    for(Pallet& p : this->pallets){
        if(p.getItemCount() > 0){
            return false;
        }
    }
    return true;
    

}
bool Shelf::isFull()
{
    for(Pallet& p : pallets){
        if(p.getRemainingSpace() == 0)
        return true;
    }
}

