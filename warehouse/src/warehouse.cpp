#include "include/warehouse.hpp"
#include <vector>

Warehouse::Warehouse() :
    Employees(std::vector<Employee> {}),
    Shelves(std::vector<Shelf> {})
{

}
void Warehouse::addEmployee(Employee employee)
{
    return;
}
void Warehouse::addShelf(Shelf shelf)
{
    return;
}
bool Warehouse::rearrangeShelf(Shelf& shelf)
{
    return true;//to do als laatste
}
bool Warehouse::pickitems(std::string itemName, int itemCount)
{
    return true;// to do
}

