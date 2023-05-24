#pragma once
#include <vector>
#include "employee.hpp"
#include "shelf.hpp"
#include <string>



class Warehouse{
    public:
    std::vector<Employee> employees;
    std::vector<Shelf> shelves;
//-------------------------------------------
    Warehouse();
    void addEmployee(Employee employee);
    void addShelf(Shelf shelf);
    bool rearrangeShelf(Shelf& shelf);
    bool pickitems(std::string ItemName, int ItemCount);

};