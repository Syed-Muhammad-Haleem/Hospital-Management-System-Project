#pragma once

#include "Person.h"
#include <iostream>
using namespace std;

class Patient : public Person
{
public:
    string Gender;
    string Disease;
    int age;

    friend istream& operator>>(istream& c, Patient& p);
};
