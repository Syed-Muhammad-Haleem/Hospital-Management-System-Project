#include"Reception.h"
#include "Patient.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include <limits>
#include <string>
#include <stdlib.h>
using namespace std;

    void Reception::AddPatient()
   	{
   		Patient TemPatient;
   		cin>>TemPatient;
   		fstream Myfile("Patients.csv",ios::app);
   		if(!Myfile.is_open())
   		{
   		   cout<<"\a\t\t\t\t\tERROR:File Not Opening!..\n";	
		}
		else
		{
			 Myfile<<TemPatient.getID()<<","<<TemPatient.getName()<<","<<TemPatient.age<<","<<TemPatient.Gender<<","<<TemPatient.Disease<<endl;	
   		     Myfile.close();
   		     cout<<"\a\t\t\t\t\t\t"<<TemPatient.getName()<<" is Added to Patient Record SUCCESSFULY!..\n";
		}
	
	}
   	string Reception::getReceptPassword()
   	{
   	   return Password;	
	}
	
    void Reception::StoreReception(Reception &ob)
	{
	    fstream Myfile("Reception.csv",ios::app);
	    Myfile<<ob.ID<<","<<ob.name<<","<<ob.Password<<endl;
	    cout<<"\a\t\t\t\t\t"<<ob.name<<" is Added to Reception Record Successfuly!."<<endl;
	}
	
   	Reception::Reception(string ReceptID,string ReceptName,string ReceptPassword)
   	{
   	  ID=ReceptID;
   	  name=ReceptName;
   	  Password=ReceptPassword;	
	}
	
	void Reception::CreateAppointment()
	{
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout<<"\a\t\t\t\t\tCREATING APPOINTMENT.."<<endl;
		string PatientID,DocterID,PatientName,Disease,DocterName,Fees,PresCription="NULL",Status="NULL";
		bool IsPatientFound=false;
		bool IsDocterFound=false;
		cout<<"\a\t\t\t\t\tEnter Patient-ID: ";
		getline(cin,PatientID);
		cout<<"\a\t\t\t\t\tEnter Docter-ID: ";
		getline(cin,DocterID);
		
		
		//Searching the Patients
		fstream Patient("Patients.csv",ios::in);
		fstream Docter("Docters.csv",ios::in);
		string line;
		
		if(!Patient.is_open())
		{
			cout<<"\a\t\t\t\t\tPatients Files Error..."<<endl;
		}
		else
		{
			  getline(Patient,line);
		      while(getline(Patient,line))
		      {
		     	stringstream S(line);
			    string ID,Name,Age,Gender,PDisease;
			    getline(S,ID,',');
			    getline(S,Name,',');
			    getline(S,Age,',');
			    getline(S,Gender,',');
			    getline(S,PDisease,',');
			
			    if(ID==PatientID)
			    {
				   PatientName=Name;
				   Disease=PDisease;
				   IsPatientFound=true;
			    }
			
			   if(IsPatientFound)
			   {
				  break;
			   }	
		  }
		}
		
		if(!Docter.is_open())
		{
			cout<<"\a\t\t\t\t\tDocter Files Error..."<<endl;
		}
		
		else
		{
		      getline(Docter,line);
		      while(getline(Docter,line))
		      {
			      stringstream S(line);
			      string ID,Name,Password,DFees,timing,Specialist;
			      getline(S,ID,',');
			      getline(S,Name,',');
			      getline(S,Password,',');
			      getline(S,DFees,',');
			      getline(S,timing,',');
			      getline(S,Specialist,',');
			
			      if(ID==DocterID)
			      {
				     DocterName=Name;
				     Fees=DFees;
				     IsDocterFound=true;
			      }
			
			      if(IsDocterFound)
			      {
				  break;
			      }	
		      }	
		}
		
		
	    if(IsPatientFound==true and IsDocterFound==true)
	    {
	    	fstream MyFile("Appointments.csv",ios::app);
	    	MyFile<<PatientID<<","<<PatientName<<","<<Disease<<","<<DocterID<<","<<DocterName<<","<<Fees<<","<<PresCription<<","<<Status<<endl;
	    	cout<<"\a\t\t\t\t\t"<<PatientName<<" is Appointed to "<<DocterName<<endl;
		    MyFile.close();
		}
		else
		{
			cout<<"\a\t\t\t\t\tAppointment Fails....TRY AGAIN....Enter Correct Information.."<<endl;
		}
	
	}

    void Reception::CancellAppointment()
	{
		cout<<"\a\t\t\t\t\tCANCELLING THE APPOINTMENT....."<<endl;
		string PatientID,DocterID;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout<<"\a\t\t\t\t\tEnter Patient-ID: ";
		getline(cin,PatientID);
		cout<<"\a\t\t\t\t\tEnter Docter-ID: ";
		getline(cin,DocterID);
		
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
		    getline(Appt,line);
		    Temp<<"PtID"<<","<<"PtName"<<","<<"Disease"<<","<<"DrID"<<","<<"DrName"<<","<<"Fees"<<","<<"Status"<<","<<"Prescription"<<endl;
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
		        
		        if(!(PID == PatientID && DrID == DocterID))
		        {
		        	Temp<<PID<<","<<PName<<","<<PDisease<<","<<DrID<<","<<DrName<<","<<Fees<<","<<Status<<","<<Prescription<<endl;
				}
				else
				{
					Found=true;
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
                   cout << "\a\t\t\t\t\tAppointment Cancelled Successfully!\n";
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
