#include <vector>
#pragma once
#include "employee.hpp"
#include "shelf.hpp"
#include <string>



class Warehouse{
    public:
    std::vector<Employee> Employees;
    std::vector<Shelf> Shelves;
//-------------------------------------------
    Warehouse();
    void addEmployee(Employee employee);
    void addShelf(Shelf shelf);
    bool rearrangeShelf(Shelf& shelf);
    bool pickitems(std::string itemName, int itemCount);

};