#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "include/catch.hpp"
#include "../src/include/warehouse.hpp"

// Find all tests in test*.cpp in test/

/// \brief 
/// Creates a mock Warehouse.
/// \return Warehouse with shelf of books.
/// \details
/// Creates a Warehouse with 3 unsorted shelves with a total of 100 Books, 60 Boxes, and 60 Toy Bears.
/// \n Adds forklift certified employee Bob.
/// \n This function can be used in testcases to avoid the repeated construction of Warehouse objects.
Warehouse createMockWarehouse(){
    Warehouse warehouse = Warehouse();
    Shelf shelf1 = Shelf();
    shelf1.pallets = {
        Pallet("Books", 100, 40), 
        Pallet("Boxes", 100, 10), 
        Pallet("Books", 100, 20), 
        Pallet("Books", 100, 20)
    };

    Shelf shelf2 = Shelf();
    shelf2.pallets = {
        Pallet("Books", 100, 15), 
        Pallet("Boxes", 100, 20), 
        Pallet("Books", 100, 5), 
        Pallet("Boxes", 100, 30)
    };

    Shelf shelf3 = Shelf();
    shelf3.pallets = {
        Pallet("Toy Bears", 100, 20), 
        Pallet("Toy Bears", 100, 10), 
        Pallet(), 
        Pallet("Toy Bears", 100, 30)
    };
    
    warehouse.addShelf(shelf1);
    warehouse.addShelf(shelf2);
    warehouse.addShelf(shelf3);

    warehouse.addEmployee(Employee("Bob", true));

    return warehouse;
}


TEST_CASE("Trying to pickitems and checking if the pallet itemcount changes","Warehouse::Pickitems")
{
    Warehouse w = createMockWarehouse();
    
    bool successful = w.pickitems("Toy Bears", 20);

    //Test to see if stock changes.
    REQUIRE(w.shelves[2].pallets[0].getItemCount() == 0);
    REQUIRE(w.shelves[2].pallets[1].getItemCount() == 10);
    REQUIRE(w.shelves[2].pallets[2].getItemCount() == 0);
    REQUIRE(w.shelves[2].pallets[3].getItemCount() == 30);
    REQUIRE(successful);
}

TEST_CASE("Trying to pick too much items","Warehouse::Pickitems")
{
    Warehouse w = createMockWarehouse();
    
    bool successful = w.pickitems("Toy Bears", 500);
    REQUIRE(!successful);
    
}


TEST_CASE("Trying to pickitems negative items","Warehouse::Pickitems")
{
    Warehouse w = createMockWarehouse();
    
    bool successful = w.pickitems("Toy Bears", -1);
    REQUIRE(!successful);
}


TEST_CASE("Trying to pickitems","Warehouse::Pickitems")
{
    Warehouse w = createMockWarehouse();
    
    bool successful = w.pickitems("Toy Bears", 30);
    REQUIRE(successful);
}


TEST_CASE("Trying to pickitems but name is incorrect","Warehouse::Pickitems")
{
    Warehouse w = createMockWarehouse();
    
    bool successful = w.pickitems("Toy beren", 20);
    REQUIRE(!successful);
}





