#include "Patient.h"
#include <limits>
#include<iostream>

using namespace std;

istream& operator>>(istream &c, Patient &p)
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"\a\t\t\t\t\t\tENTER THE PATIENT DETAIL...\n";
    cout<<"\t\t\t\t\t\tPatient-ID: ";
    getline(c,p.ID);
    cout<<"\t\t\t\t\t\tName: ";
    getline(c,p.name);
    cout<<"\t\t\t\t\t\tGender: ";
    getline(c,p.Gender);
    cout<<"\t\t\t\t\t\tDisease: ";
    getline(c,p.Disease);
    cout<<"\t\t\t\t\t\tAge: ";
    cin>>p.age;
    return c;
}
