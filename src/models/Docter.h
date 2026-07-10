#pragma once

#include "Person.h"
#include <string>

class Docter : public Person
{
protected:
    string Specilization,Password,timing;
    float Fees;

public:
    string getDocterPassword();
    Docter(string name,string ID,string Password,string Spz,float Fees,string time);
    static void StoreDocter(Docter &ob);
    void Disply_Docter_Appointments(Docter *ptr);
    void CheckPatient(Docter *ptr);
};
