#pragma once

#include "Reception.h"
#include "Docter.h"
#include "Accountant.h"
#include <vector>
using namespace std;

class Hospital
{
	private:
	vector<Reception>Receptions;
	vector<Docter>Docters;
	vector<Accountant>Accountants;
	
	public:
	bool LoadReception_To_Vecter();
	Reception* ReceptionLogin();
	Reception* manageReception();
	bool LoadDocter_To_Vecter();
	Docter* DocterLogin();
	Docter* manageDocter();
	bool LoadAccountants_To_Vecter();
	Accountant* AccountantLogin();
	Accountant* manageAccountant();
	void addReception(Reception &obj);
	void addDocter(Docter &obj);
	void addAccountant(Accountant &obj);
	

};
