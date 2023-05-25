#include <iostream>
#include "src/include/pallet.hpp"
#include "src/include/shelf.hpp"
#include "src/include/warehouse.hpp"
#include "src/include/employee.hpp"


int main(void){
    Warehouse warehouse;
    
    // Maak een Pallet aan en voeg deze toe aan de Shelf
    Pallet pallet("brood", 100, 100);
    Pallet pallet1("brood", 100, 100);
    Pallet pallet2("brood", 100, 100);
    Pallet pallet3("brood", 100, 100);

    std::cout << pallet.getItemName() << ", " << (pallet.getRemainingSpace()+pallet.getItemCount()) << ", " << pallet.getItemCount() << std::endl;
    
    // Voeg een Shelf toe aan het magazijn
    Shelf shelf;
    shelf.pallets = {pallet, pallet1, pallet2, pallet3};
    warehouse.addShelf(shelf);



    std::cout << "Is full: " <<std::boolalpha << warehouse.shelves[0].isFull() << std::endl;
    std::cout << "Is empty: " <<std::boolalpha << warehouse.shelves[0].isEmpty() << std::endl;



    // Controleer het resultaat en druk het af
    if (warehouse.pickitems("brood", 400)) {
        std::cout << "400 stuks brood gepakt!" << std::endl;
    } else {
        std::cout << "Niet genoeg brood beschikbaar." << std::endl;
    }

    std::cout << "Is full: " <<std::boolalpha << warehouse.shelves[0].isFull() << std::endl;
    std::cout << "Is empty: " <<std::boolalpha << warehouse.shelves[0].isEmpty() << std::endl;



    std::cout << "-----------------------------------------------------------" << std::endl;
    std::cout << "-----------------------------------------------------------" << std::endl;


    // Employee e = Employee("Robin", true);
    // std::cout << e.getName() << std::endl;

    // Shelf s = Shelf();
    // std::cout << s.isEmpty() << std::endl;
}



