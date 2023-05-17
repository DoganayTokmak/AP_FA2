#include <iostream>
#include "src/include/pallet.hpp"
#include "src/include/shelf.hpp"
#include "src/include/warehouse.hpp"





int main(void){
    Pallet p = Pallet("Brood", 30, 30);
    
    std::cout << p.getitemName() << std::endl;

    Shelf s = Shelf();

    std::cout << s.isEmpty() << std::endl;
}
