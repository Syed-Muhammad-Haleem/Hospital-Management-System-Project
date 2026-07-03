#pragma once

#include "Person.h"
#include "Patient.h"
using namespace std;

class Reception : public Person
{
protected:
    string Password;

public:
    void AddPatient();

    string getReceptPassword();

    static void StoreReception(Reception &ob);

    Reception(string ReceptID,string ReceptName,string ReceptPassword);

    void CreateAppointment();

    void CancellAppointment();
};
