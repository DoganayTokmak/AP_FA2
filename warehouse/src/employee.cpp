#include "include/employee.hpp"


Employee::Employee(std::string name, bool forkliftCertificate):
    name(name),
    busy(false),
    forkliftCertificate(forkliftCertificate)
    
{

}
//Name of employee
std::string Employee::getName()
{
    return this-> name;
}

//Employee busy or not
bool Employee::getBusy()
{
    return busy;
}

//Set employee busy
void Employee::setBusy(bool busy)
{
    this-> busy = busy;
}

//Certificate of employee
bool Employee::getForkliftCertificate()
{
    return forkliftCertificate;
}

//Certificate of employee
void Employee::setForkliftCertificate(bool forkliftCertificate)
{
    this-> forkliftCertificate = forkliftCertificate;
}