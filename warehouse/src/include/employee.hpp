#pragma once
#include <string>

class Employee{
    private:
    std::string const name;
    bool busy;
    bool forkliftCertificate;

    public:
    Employee(std::string name, bool forkliftCertificate);
    std::string getName();
    bool getBusy();
    void setBusy(bool busy);
    bool getForkliftCertificate();

    // forkliftCertificate Heb ik wel met hoofdletter gedaan voor consistentie
    void setForkliftCertificate(bool forkliftCertificate);
};