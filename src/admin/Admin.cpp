#include "Admin.h"
#include "Patient.h"
#include "Docter.h"
#include "Reception.h"
#include "Accountant.h"
#include "Hospital.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include <limits>
#include <string>
#include <stdlib.h>
using namespace std;

    extern Hospital HospitalMainObject;  // these are present in main.cpp
    extern Admin AdminObject;

	Admin::Admin(string id,string Name,string AdminPassword)
	{
		ID=id;
		name=Name;
		Password=AdminPassword;
	}
	
	void Admin::AdminLogin()
	{
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		while(true)
		{
		     cout<<"\a\t\t\t\t\t\tENTER LOGIN DETAILS FOR ADMIN: "<<endl;
		     string AdID,AdName,AdPass;
		     cout<<"\a\t\t\t\t\t\tEnter Admin Name: ";
		     getline(cin,AdName);
		     //cout<<AdName;
		     cout<<"\a\t\t\t\t\t\tEnter Admin Password: ";
		     getline(cin,AdPass);
			 cout<<"\a\t\t\t\t\t\tEnter Admin ID: ";
		     getline(cin,AdID);
			 if(AdID==ID and AdName==name and AdPass==Password)
			 {
			 	cout<<"\n\a\t\t\t\t\tADMIN LOGIN SUCCESSFULL!.."<<endl<<endl;
			 	break;
			 }
			 else
			 {
			 	cout<<"\n\a\t\t\t\t\t INVALID CREDENTIAL....TRY AGAIN"<<endl<<endl;
			 }
			 
		}
	}
	
	void Admin::CreateReceptionalist()
	{
	  string Receptname,ReceptID,ReceptPassword;
	  cout<<"\a\t\t\t\t\t\t Creating the Receptionalist...."<<endl;
	  cout<<"\t\t\t\t\t\tEnter Name: ";
	  cin.ignore();
	  getline(cin,Receptname);
	  cout<<"\t\t\t\t\t\tEnter ID: ";
	  getline(cin,ReceptID);
	  cout<<"\t\t\t\t\t\tEnter Password: ";
	  getline(cin,ReceptPassword);
	  
	  
	  Reception TemporaryObj(ReceptID,Receptname,ReceptPassword);
	  HospitalMainObject.addReception(TemporaryObj);
	  Reception::StoreReception(TemporaryObj);	
	}
	
	
	void Admin::CreateDocter()
	{
	  string Doctname,DoctID,DoctPassword,DoctSpecilization,DoctTiming;
	  double DoctFees;
	  cout<<"\a\t\t\t\t\t\t Creating the Doctor...."<<endl;
	  cout<<"\t\t\t\t\t\tEnter Name: ";
	  cin.ignore();
	  getline(cin,Doctname);
	  cout<<"\t\t\t\t\t\tEnter ID: ";
	  getline(cin,DoctID);
	  cout<<"\t\t\t\t\t\tEnter Password: ";
	  getline(cin,DoctPassword);
	  cout<<"\t\t\t\t\t\tEnter Specilization : ";
	  getline(cin,DoctSpecilization);
	  cout<<"\t\t\t\t\t\tEnter Docter-Timing : ";
	  getline(cin,DoctTiming);
	  cout<<"\t\t\t\t\t\tEnter Fees: ";
	  cin>>DoctFees;
	  
	  
	  Docter TemporaryObj(Doctname,DoctID,DoctPassword,DoctSpecilization,DoctFees,DoctTiming);
	  HospitalMainObject.addDocter(TemporaryObj);
	  Docter::StoreDocter(TemporaryObj);	
	}
	
	
	void Admin::CreateAccountant()
	{
	  string Accname,AccID,AccPassword;
	  cout<<"\a\t\t\t\t\t\t Creating the Accountant...."<<endl;
	  cout<<"\t\t\t\t\t\tEnter Name: ";
	  cin.ignore();
	  getline(cin,Accname);
	  cout<<"\t\t\t\t\t\tEnter ID: ";
	  getline(cin,AccID);
	  cout<<"\t\t\t\t\t\tEnter Password: ";
	  getline(cin,AccPassword);
	  Accountant TemporaryObj(Accname,AccID,AccPassword);
	  HospitalMainObject.addAccountant(TemporaryObj);
	  Accountant::StoreAccountant(TemporaryObj);	
	}
	
	void Admin::DeletePatient()
	{
		cout<<"\a\t\t\t\t\tDELETING THE PATIENT....."<<endl;
		string PatientID;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout<<"\a\t\t\t\t\tEnter Patient-ID: ";
		getline(cin,PatientID);
		
		fstream Patientfile("Patients.csv",ios::in);
		fstream Temp("Temp.csv",ios::out);
		string line;
		bool Found=false;
		if(!(Patientfile.is_open() and Temp.is_open()))
		{
			cout<<"\a\t\t\t\tERROR: Files Not Opening...TRY AGAIN...."<<endl;
		}
		else
		{ 
		    getline(Patientfile,line);
		    Temp<<"PtID"<<","<<"PtName"<<","<<"Age"<<","<<"Gender"<<","<<"Disease"<<endl;
		    while(getline(Patientfile,line))
		    {
			    stringstream S(line);
		        string PtID,PtName,PtDisease,Ptage,Ptgender;
		        getline(S,PtID,',');
		        getline(S,PtName,',');
		        getline(S,Ptage,',');
		        getline(S,Ptgender,',');
		        getline(S,PtDisease,','); 
		        
		        if(PtID!=PatientID)
		        {
		           Temp<<PtID<<","<<PtName<<","<<Ptage<<","<<Ptgender<<","<<PtDisease<<endl;	
				}
				else
				{
					Found=true;
				}
		    }
		    
		    if(Found)
            {
                Patientfile.close();
                Temp.close();

                int StoreRemoveStatus = remove("Patients.csv");
                int StoreRenameStatus = rename("Temp.csv", "Patients.csv");

                if (StoreRemoveStatus != 0 || StoreRenameStatus != 0)
                {
                      cout<<"\a\t\t\t\t\tERROR While Deleting the Patients..."<<endl;
                }
               else
               {
                   cout << "\a\t\t\t\t\tPatient Deleted Successfully!\n";
               }
           }
           else
           {
             Patientfile.close();
             Temp.close();
             remove("Temp.csv");   // we removed the Temp File 
             cout<<"\a\t\t\t\t\tPatient NOT Found!"<<endl;
           }
		}	
	}	
	
	
	void Admin::DeleteDocter()
	{
		cout<<"\a\t\t\t\t\tDELETING THE DOCTER....."<<endl;
		string DocterID;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout<<"\a\t\t\t\t\tEnter Docter-ID: ";
		getline(cin,DocterID);
		
		fstream Docterfile("Docters.csv",ios::in);
		fstream Temp("Temp.csv",ios::out);
		string line;
		bool Found=false;
		if(!(Docterfile.is_open() and Temp.is_open()))
		{
			cout<<"\a\t\t\t\tERROR: Files Not Opening...TRY AGAIN...."<<endl;
		}
		else
		{ 
		    getline(Docterfile,line);
		    Temp<<"DrID"<<","<<"DrName"<<","<<"Password"<<","<<"Fees"<<","<<"Timing"<<","<<"Disease"<<endl;
		    while(getline(Docterfile,line))
		    {
			    stringstream S(line);
		        string DrID,DrName,Password,Fees,Timing,Disease;
		        getline(S,DrID,',');
		        getline(S,DrName,',');
		        getline(S,Password,',');
		        getline(S,Fees,',');
		        getline(S,Timing,',');
		        getline(S,Disease,','); 
		        
		        if(DrID!=DocterID)
		        {
		           Temp<<DrID<<","<<DrName<<","<<Password<<","<<Fees<<","<<Timing<<","<<Disease<<endl;	
				}
				else
				{
					Found=true;
				}
		    }
		    
		    if(Found)
            {
                Docterfile.close();
                Temp.close();

                int StoreRemoveStatus = remove("Docters.csv");
                int StoreRenameStatus = rename("Temp.csv", "Docters.csv");

                if (StoreRemoveStatus != 0 || StoreRenameStatus != 0)
                {
                      cout<<"\a\t\t\t\t\tERROR While Deleting the Docter..."<<endl;
                }
               else
               {
                   cout << "\a\t\t\t\t\tDocter Deleted Successfully!\n";
               }
           }
           else
           {
             Docterfile.close();
             Temp.close();
             remove("Temp.csv");   // we removed the Temp File 
             cout<<"\a\t\t\t\t\tDocter NOT Found!"<<endl;
           }
		}	
	}	
	
	
	void Admin::DeleteReceptionalist()
	{
		cout<<"\a\t\t\t\t\tDELETING THE RECEPTIONALIST....."<<endl;
		string Recept_ID;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout<<"\a\t\t\t\t\tEnter Receptionalist-ID: ";
		getline(cin,Recept_ID);
		
		fstream file("Reception.csv",ios::in);
		fstream Temp("Temp.csv",ios::out);
		string line;
		bool Found=false;
		if(!(file.is_open() and Temp.is_open()))
		{
			cout<<"\a\t\t\t\tERROR: Files Not Opening...TRY AGAIN...."<<endl;
		}
		else
		{ 
		    getline(file,line);
		    Temp<<"ReceptID"<<","<<"ReceptName"<<","<<"Password"<<endl;
		    while(getline(file,line))
		    {
			    stringstream S(line);
		        string ReceptID,ReceptName,Password;
		        getline(S,ReceptID,',');
		        getline(S,ReceptName,',');
		        getline(S,Password,',');
		        if(ReceptID!=Recept_ID)
		        {
		           Temp<<ReceptID<<","<<ReceptName<<","<<Password<<endl;	
				}
				else
				{
					Found=true;
				}
		    }
		    
		    if(Found)
            {
                file.close();
                Temp.close();

                int StoreRemoveStatus = remove("Reception.csv");
                int StoreRenameStatus = rename("Temp.csv", "Reception.csv");

                if (StoreRemoveStatus != 0 || StoreRenameStatus != 0)
                {
                      cout<<"\a\t\t\t\t\tERROR While Deleting the Docter..."<<endl;
                }
               else
               {
                   cout << "\a\t\t\t\t\tReceptionalist Deleted Successfully!\n";
               }
           }
           else
           {
             file.close();
             Temp.close();
             remove("Temp.csv");   // we removed the Temp File 
             cout<<"\a\t\t\t\t\tReceptionalist NOT Found!"<<endl;
           }
		}	
	}
	
	
	void Admin::DeleteAccountant()
	{
		cout<<"\a\t\t\t\t\tDELETING THE ACCOUNTANT....."<<endl;
		string Accountant_ID;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout<<"\a\t\t\t\t\tEnter Accountant-ID: ";
		getline(cin,Accountant_ID);
		
		fstream file("Accountants.csv",ios::in);
		fstream Temp("Temp.csv",ios::out);
		string line;
		bool Found=false;
		if(!(file.is_open() and Temp.is_open()))
		{
			cout<<"\a\t\t\t\tERROR: Files Not Opening...TRY AGAIN...."<<endl;
		}
		else
		{ 
		    getline(file,line);
		    Temp<<"ID"<<","<<"Name"<<","<<"Password"<<endl;
		    while(getline(file,line))
		    {
			    stringstream S(line);
		        string AccID,AccName,Password;
		        getline(S,AccID,',');
		        getline(S,AccName,',');
		        getline(S,Password,',');
		        if(AccID!=Accountant_ID)
		        {
		           Temp<<AccID<<","<<AccName<<","<<Password<<endl;	
				}
				else
				{
					Found=true;
				}
		    }
		    
		    if(Found)
            {
                file.close();
                Temp.close();

                int StoreRemoveStatus = remove("Accountants.csv");
                int StoreRenameStatus = rename("Temp.csv", "Accountants.csv");

                if (StoreRemoveStatus != 0 || StoreRenameStatus != 0)
                {
                      cout<<"\a\t\t\t\t\tERROR While Deleting the Docter..."<<endl;
                }
               else
               {
                   cout << "\a\t\t\t\t\tAccountant Deleted Successfully!\n";
               }
           }
           else
           {
             file.close();
             Temp.close();
             remove("Temp.csv");   // we removed the Temp File 
             cout<<"\a\t\t\t\t\tAccountant NOT Found!"<<endl;
           }
		}	
	}	
	
	
	void Admin::DeleteHistory()
	{
		string Option;
		cout<<"\a\t\t\t\tDo You Want To Clear All History!.....(yes,no): ";
		cin>>Option;
		if(Option=="yes" or Option=="YES" or Option=="Yes")
		{
			int StoreRemoveStatus = remove("History.csv");
			if(StoreRemoveStatus!=0)
			{
				cout<<"\a\t\t\t\t\tDeletion Failed!.."<<endl;
			}
			else
			{
				cout<<"\a\t\t\t\t\tHISTORY DELETED SUCCESSFULLY!.."<<endl;
			}
		}
		else
		{
			cout<<"\a\t\t\t\t\tIt's OK BUDDY!"<<endl;
	    }
	}	


