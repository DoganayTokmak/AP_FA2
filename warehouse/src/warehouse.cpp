#include "include/warehouse.hpp"
#include <vector>


Warehouse::Warehouse() :
    employees(std::vector<Employee> {}),
    shelves(std::vector<Shelf> {})
{

}
void Warehouse::addEmployee(Employee employee)
{
    return employees.push_back(employee);
}
void Warehouse::addShelf(Shelf shelf)
{
    return shelves.push_back(shelf);
}


bool Warehouse::rearrangeShelf(Shelf& shelf)
{
    //forkliftcertificate moet hebben
    //Sorteer op volgorde van itemCount
    // Gebruik functie swappallets om 2 pallets te switchen
    for (Employee& e : employees)
    {
        if (e.getForkliftCertificate() == true && !e.getBusy())
        {
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




bool Warehouse::pickitems(std::string ItemName, int ItemCount)
{ //wat nou als er niet genoeg item in de pallets zitten

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

    int pickedCount = 0;
    if (totalCount >= ItemCount)
    {
        for(Shelf& s : shelves)
        {

            for(Pallet& p : s.pallets)
            {
            
                if (ItemName == p.getItemName() && p.getItemCount() > 0)
                {
                    for(int i = 0; i < p.getItemCount(); i++ )
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

