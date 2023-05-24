#include <iostream>
#include "src/include/pallet.hpp"
#include "src/include/shelf.hpp"
#include "src/include/warehouse.hpp"





int main(void){
    Pallet p = Pallet();
    
    std::cout << p.getItemName() << std::endl;

    Shelf s = Shelf();

    std::cout << s.isEmpty() << std::endl;
}
