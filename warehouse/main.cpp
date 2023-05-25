#include <iostream>
#include "src/include/pallet.hpp"
#include "src/include/shelf.hpp"
#include "src/include/warehouse.hpp"
#include "src/include/employee.hpp"


int main(void){
    Warehouse warehouse;
    
    // Voeg een Shelf toe aan het magazijn
    Shelf shelf;
    warehouse.addShelf(shelf);

    // Maak een Pallet aan en voeg deze toe aan de Shelf
    Pallet pallet("brood", 100, 90);

    // Roep de pickitems-functie aan
    bool pick = warehouse.pickitems("brood", 50);

    // Controleer het resultaat en druk het af
    if (pick)
    {
        std::cout << "50 stuks brood gepakt!" << std::endl;
    }
    else
    {
        std::cout << "Niet genoeg brood beschikbaar." << std::endl;
    }

    return 0;


    Pallet p = Pallet("Brood", 100, 90);
    std::cout << p.getItemName() << " " << p.getItemCount() << std::endl;

    Employee e = Employee("Robin", true);
    std::cout << e.getName() << std::endl;

    Shelf s = Shelf();
    std::cout << s.isEmpty() << std::endl;
}



