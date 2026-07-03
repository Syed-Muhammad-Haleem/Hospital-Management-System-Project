#include "Docter.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include <limits>
#include <string>
#include <conio.h>
#include <stdlib.h>
using namespace std;

	string Docter::getDocterPassword()  
	{
		return Password;
	}
	
	Docter::Docter(string name,string ID,string Password,string Spz,float Fees,string time)
	{
		this->name=name;
		this->ID=ID;
		this->Password=Password;
		this->Fees=Fees;
		Specilization=Spz;
		timing=time;
	}
	
	 void Docter::StoreDocter(Docter &ob)
	 {
	    fstream Myfile("Docters.csv",ios::app);
	    Myfile<<ob.ID<<","<<ob.name<<","<<ob.Password<<","<<ob.Fees<<","<<ob.timing<<","<<ob.Specilization<<endl;
	    cout<<"\a\t\t\t\t\t\t"<<ob.name<<" is Added Successfuly!."<<endl;
	 }
	
	void Docter::Disply_Docter_Appointments(Docter *ptr)
    {
     	fstream Myfile("Appointments.csv",ios::in);
	    if(!Myfile.is_open())
	    {
	       cout<<"\a\t\t\t\t\tERROR:File is not opening....\n";	
		}
	    else
	    {
		    string line;
		    getline(Myfile,line);
		    cout<<"\a\n\n\n\t\t\t\t\t============== APPOINTMENTS RECORD=================="<<endl;
		    cout<<"\nPatient-ID\tPatient-Name\tDisease\t\tDocter-ID\tDocter-Name\tFees\tStatus\tPrescription"<<endl;
		    cout<<"========================================================================================================================"<<endl;
	        while(getline(Myfile,line))
	        {
	    	
		       stringstream S(line);
		       string PID,PName,PDisease,DrID,DrName,Fees,Status,Prescription;
		       getline(S,PID,',');
		       getline(S,PName,',');
		       getline(S,PDisease,','); 
		       getline(S,DrID,',');
		       getline(S,DrName,',');
		       getline(S,Fees,',');
		       getline(S,Status,',');
		       getline(S,Prescription,',');
		       if(ptr->getID()==DrID)
		       {
		       	  cout<<PID<<"\t\t"<<PName<<"\t\t"<<PDisease<<"\t\t"<<DrID<<"\t\t"<<DrName<<"\t\t"<<Fees<<"\t "<<Status<<"\t\t"<<Prescription<<endl;
			      cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl; 
			   }  
	       }
	   }
   }

     
    void Docter::CheckPatient(Docter *ptr)
    {
    	cout<<"\n\n\n\a\t\t\t\t\tHELLO DOCTER!...CHECK YOUR PATIENT...."<<endl;
    	string PatientID,DocterPrescription;
    	cin.ignore(numeric_limits<streamsize>::max(), '\n');
    	cout<<"\a\t\t\t\t\tDear Docter!..Enter your Patient-ID: ";
    	getline(cin,PatientID);
    	cout<<"\a\t\t\t\t\tEnter Your Medicine to Patient: ";
    	getline(cin,DocterPrescription);
    	
		fstream Appt("Appointments.csv",ios::in);
		fstream Temp("Temp.csv",ios::out);
		string line;
		bool Found=false;
		if(!(Appt.is_open() and Temp.is_open()))
		{
			cout<<"\a\t\t\t\tERROR: Files Not Opening...TRY AGAIN...."<<endl;
		}
		else
		{ 
		    while(getline(Appt,line))
		    {
			    stringstream S(line);
		        string PID,PName,PDisease,DrID,DrName,Fees,Status,Prescription;
		        getline(S,PID,',');
		        getline(S,PName,',');
		        getline(S,PDisease,','); 
		        getline(S,DrID,',');
		        getline(S,DrName,',');
		        getline(S,Fees,',');
		        getline(S,Status,',');
		        getline(S,Prescription,',');
		        
		        if(PID==PatientID and DrID==ptr->getID())
		        {
		        	Temp<<PID<<","<<PName<<","<<PDisease<<","<<DrID<<","<<DrName<<","<<Fees<<","<<"DONE"<<","<<DocterPrescription<<endl;
				    Found=true;
				}
				else
				{
					Temp<<PID<<","<<PName<<","<<PDisease<<","<<DrID<<","<<DrName<<","<<Fees<<","<<Status<<","<<Prescription<<endl;
				}
		    }
		    
		    if(Found)
            {
                Appt.close();
                Temp.close();

                int StoreRemoveStatus = remove("Appointments.csv");
                int StoreRenameStatus = rename("Temp.csv", "Appointments.csv");

                if (StoreRemoveStatus != 0 || StoreRenameStatus != 0)
                {
                      cout<<"\a\t\t\t\t\tERROR While Updating the Appointments..."<<endl;
                }
               else
               {
                   cout << "\a\t\t\t\t\tAppointment Updated Successfully!\n";
               }
           }
           else
           {
             Appt.close();
             Temp.close();
             remove("Temp.csv");   // we removed the Temp File 
             cout<<"\a\t\t\t\t\tAppointment NOT Found!"<<endl;
           }
		}	
    	
	}



