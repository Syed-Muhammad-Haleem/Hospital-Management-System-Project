#pragma once

#include "Person.h"
#include <string>
using namespace std;

class Admin:public Person
{
	private:
	string Password;
	
	public:
	Admin(string id,string Name,string AdminPassword);
	void AdminLogin();
	void CreateReceptionalist();
	void CreateDocter();
	void CreateAccountant();
	void DeletePatient();
	void DeleteDocter();
	void DeleteReceptionalist();
	void DeleteAccountant();
	void DeleteHistory();
	
};

