#include <iostream>
#include "src/include/pallet.hpp"



int main(void){
    Pallet p = Pallet("Brood", 30, 30);

    std::cout << p.getitemName() << std::endl;
}
