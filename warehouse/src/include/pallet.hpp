#pragma once
#include <string>
#include "IContainer.hpp"




class Pallet:public IContainer{
    private:
    std::string ItemName;
    int ItemCapacity;
    int ItemCount;
    
    
    public:
    Pallet(std::string ItemName, int ItemCapacity, int ItemCount);
    Pallet();
    std::string getItemName();
    int getItemCount();
    int getRemainingSpace();
    bool reallocateEmptyPallet(std::string ItemName, int ItemCapacity);
    bool takeOne();
    bool putOne();  

    bool isEmpty() override;
    bool isFull() override;


};
