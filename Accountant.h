#pragma once

#include "Person.h"
using namespace std;

class Accountant:public Person
{
	private:
	string Password;
	
	public:
	string getAccountantPassword();

	Accountant(string name,string ID,string Password);

	static void StoreAccountant(Accountant &ob);

	void CreateBill(string PtID, string PtName,string DrName,string Disease,string Prescription,float Fees);

	void CreateHistory(string PtID,string PtName,string DrName,string Disease,string date,float Bill);

	void ManageBill_And_History();
};
