#include "include/warehouse.hpp"
#include <vector>
#include <iostream>


Warehouse::Warehouse() :
    employees(std::vector<Employee> {}),
    shelves(std::vector<Shelf> {})
{

}

//Add Employee
void Warehouse::addEmployee(Employee employee)
{
    return employees.push_back(employee);
}

//Add Shelf
void Warehouse::addShelf(Shelf shelf)
{
    return shelves.push_back(shelf);
}

//Sort the pallets 
bool Warehouse::rearrangeShelf(Shelf& shelf)
{
    for (Employee& e : employees)
    {
        //Check on forkliftcertificate and Employee not busy
        if (e.getForkliftCertificate() == true && !e.getBusy())
        {
            //Sort on ItemCount
            for(int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 3 - i; ++j)
                {
                    if (shelf.pallets [j].getItemCount() > shelf.pallets[j + 1].getItemCount())
                    {
                        shelf.swapPallet(j, j + 1);
                    }
                }
            }
            return true;//to do als laatste

        }
    }   
    return false;
}



//Pick item function from a Pallet
bool Warehouse::pickitems(std::string ItemName, int ItemCount)
{ 
    //So it is not possible to give negative item
    if (ItemCount < 0)
    {
        return false;
    }

    //A forloop to count how much there is on a pallet
    int totalCount = 0;
    for(Shelf& s : shelves)
    {

        for(Pallet& p : s.pallets)
        {
            
            if (ItemName == p.getItemName() && p.getItemCount() > 0)
            {
                totalCount += p.getItemCount();
            }
            
    
        }

    }

    //Count how much there is taken from a Pallet
    int pickedCount = 0;

    if (totalCount >= ItemCount)
    {
        for(Shelf& s : shelves)
        {

            for(Pallet& p : s.pallets)
            {
            
                if (ItemName == p.getItemName() && p.getItemCount() > 0)
                {
                    int count = p.getItemCount();
                    for(int i = 0; i < count; i++ )
                    {
                        p.takeOne();
                        pickedCount += 1;
                        if (pickedCount == ItemCount)
                        {
                            return true;
                        }

                    }
                }
            
    
            }   

        }    
    }
    return false;   
}

