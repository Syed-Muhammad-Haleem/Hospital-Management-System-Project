#pragma once

#include <string>
using namespace std;

class Person
{
protected:
    string ID, name;

public:
    string getID();
    string getName();
};
