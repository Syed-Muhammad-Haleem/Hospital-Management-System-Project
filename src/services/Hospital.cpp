#include"Hospital.h"
#include "Docter.h"
#include "Reception.h"
#include "Accountant.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include <limits>
#include <string>
#include <stdlib.h>



	bool Hospital::LoadReception_To_Vecter()
	{
		ifstream Myfile("Reception.csv");
		if(!Myfile.is_open())
		{
			return false;
		}
	    string line;
	    getline(Myfile, line);
	    while(getline(Myfile,line))
	    {
		    stringstream S(line);
		    string Receptid,ReceptName,ReceptPassword;
		    getline(S,Receptid,',');
		    getline(S,ReceptName,',');
		    getline(S,ReceptPassword,',');
		    Reception temObj(Receptid,ReceptName,ReceptPassword);
		    
		    // adding object to vector
		    Receptions.push_back(temObj);    
	    }
	    return true;
	}
	
	Reception* Hospital::ReceptionLogin()
	{
		
		while(true)
		{
			 cin.ignore(numeric_limits<streamsize>::max(), '\n');
			 cout<<"\a \t\t\t\t\t\t ENTER LOGIN DETAILS FOR RECEPT: "<<endl;
		     string ReceptName,ReceptPassword;
		     cout<<"\a\t\t\t\t\t\t\tEnter Recept Name: ";
		     getline(cin,ReceptName);
		     cout<<"\a\t\t\t\t\t\t\tEnter Recept Password: ";
		     getline(cin,ReceptPassword);
		     for(auto &a:Receptions)
		     {
			    if(a.getName()==ReceptName and a.getReceptPassword()==ReceptPassword)
			     {
				   return &a;
			     }
		     }
		     cout<<"\a\t\t\t\t INVALID CREDENTIAL....TRY AGAIN"<<endl<<endl;
        }
	}
	
	Reception* Hospital::manageReception()
	{
		Reception *pt=nullptr;
		if(Receptions.empty())
		{
			bool Checker=LoadReception_To_Vecter();
			if(Checker==true)
			{
				cout<<"\a\t\t\t\t\t\t File Loaded Successfuly!."<<endl;
				pt=ReceptionLogin();
				return pt;
			}
			else
			{
				cout<<"\a\n\n\t\t\t\t\t NO Receptionalist Found!."<<endl;
				cout<<"\a\n\t\t\t\t\t Ask from Admin For Receptionalist!."<<endl;
				return pt;
			}
		}
	    else
		{
		   pt=ReceptionLogin();
		   return pt;	
		}
	}
	
	bool Hospital::LoadDocter_To_Vecter()
	{
		ifstream Myfile("Docters.csv");
		if(!Myfile.is_open())
		{
			return false;
		}
	    string line;
	    getline(Myfile,line);
	    while(getline(Myfile,line))
	    {
	    	
	    	if (line.empty())
            continue;
            
		    stringstream S(line);
		    string Did,DName,DPassword,DFees,Dspz,DTime;
		    getline(S,Did,',');
		    getline(S,DName,',');
		    getline(S,DPassword,',');
		    getline(S,DFees,',');
		    getline(S,DTime,',');
		    getline(S,Dspz,',');
		    float DoctFees=stof(DFees);
		    Docter temObj(DName,Did,DPassword,Dspz,DoctFees,DTime);  
		    
		    // adding object to vector
		    Docters.push_back(temObj);    
	    }
	    return true;
	}
	
	
	
	Docter* Hospital::DocterLogin()
	{
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		while(true)
		{ 
			 cout<<"\a \t\t\t\t\t\t ENTER LOGIN DETAILS FOR DOCTER: "<<endl;
		     string DName,DPassword;
		     cout<<"\a\t\t\t\t\t\t\tEnter Docter Name: ";
		     getline(cin,DName);
		     cout<<"\a\t\t\t\t\t\t\tEnter Docter Password: ";
		     getline(cin,DPassword);
		     for(auto &a:Docters)
		     {
			    if(a.getName()==DName and a.getDocterPassword()==DPassword)
			     {
				   return &a;
			     }
		     }
		     cout<<"\a\t\t\t\t INVALID CREDENTIAL....TRY AGAIN"<<endl<<endl;
        }
	}
	
	Docter* Hospital::manageDocter()
	{
		Docter *pt=nullptr;
		if(Docters.empty())
		{
			bool Checker=LoadDocter_To_Vecter();
			if(Checker==true)
			{
				cout<<"\a\t\t\t\t\t\t File Loaded Successfuly!."<<endl;
				pt=DocterLogin();
				return pt;
			}
			else
			{
				cout<<"\a\n\n\t\t\t\t\t NO Docter Found!."<<endl;
				cout<<"\a\n\t\t\t\t\t Ask from Admin For Docters!."<<endl;
				return pt;
			}
		}
	    else
		{
		   pt=DocterLogin();
		   return pt;	
		}
	}
	
	
	bool Hospital::LoadAccountants_To_Vecter()
	{
		ifstream Myfile("Accountants.csv");
		if(!Myfile.is_open())
		{
			return false;
		}
	    string line;
	    getline(Myfile,line);
	    
	    while(getline(Myfile,line))
	    {
		    stringstream S(line);
		    string Accid,AccName,AccPassword;
		    getline(S,Accid,',');
		    getline(S,AccName,',');
		    getline(S,AccPassword,',');
		    Accountant temObj(AccName,Accid,AccPassword);  
		    
		    // adding object to vector
		    Accountants.push_back(temObj);    
	    }
	    return true;
	}
	
	
	
	Accountant* Hospital::AccountantLogin()
	{
		
		while(true)
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			 cout<<"\a \t\t\t\t\t\t ENTER LOGIN DETAILS FOR ACCOUNTANT: "<<endl;
		     string AccName,AccPassword;
		     cout<<"\a\t\t\t\t\t\t\tEnter Accountant Name: ";
		     getline(cin,AccName);
		     cout<<"\a\t\t\t\t\t\t\tEnter Accountnt Password: ";
		     getline(cin,AccPassword);
		     for(auto &a:Accountants)
		     {
			    if(a.getName()==AccName and a.getAccountantPassword()==AccPassword)
			     {
				   return &a;
			     }
		     }
		     cout<<"\a\t\t\t\t INVALID CREDENTIAL....TRY AGAIN"<<endl<<endl;
        }
	}
	
	Accountant* Hospital::manageAccountant()
	{
		Accountant *pt=nullptr;
		if(Accountants.empty())
		{
			bool Checker=LoadAccountants_To_Vecter();
			if(Checker==true)
			{
				cout<<"\a\t\t\t\t\t\t File Loaded Successfuly!."<<endl;
				pt=AccountantLogin();
				return pt;
			}
			else
			{
				cout<<"\a\n\n\t\t\t\t\t NO Accountant Found!."<<endl;
				cout<<"\a\n\t\t\t\t\t Ask from Admin For Accountant!."<<endl;
				return pt;
			}
		}
	    else
		{
		   pt=AccountantLogin();
		   return pt;	
		}
	}
	
	
	
	
	void Hospital::addReception(Reception &obj)
	{
		Receptions.push_back(obj);
	}
	
	void Hospital::addDocter(Docter &obj)
	{
		Docters.push_back(obj);
	}
	
	void Hospital::addAccountant(Accountant &obj)
	{
		Accountants.push_back(obj);
	}


