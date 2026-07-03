#include"Accountant.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include <limits>
#include <string>
#include <conio.h>
#include <stdlib.h>  
using namespace std;
   
   
   string Accountant::getAccountantPassword()
	{
		return Password;
	}
	
	Accountant::Accountant(string name,string ID,string Password)
	{
		this->name=name;
		this->ID=ID;
		this->Password=Password;
		
	}
	
	void Accountant::StoreAccountant(Accountant &ob)
	{
	    fstream Myfile("Accountants.csv",ios::app);
	    Myfile<<ob.ID<<","<<ob.name<<","<<ob.Password<<endl;
	    cout<<"\a\t\t\t\t\t\t"<<ob.name<<" Added as a Accountant Successfully!."<<endl;
	}
	
	void Accountant::CreateBill(string PtID, string PtName,string DrName,string Disease,string Prescription,float Fees)
	{
		cout<<"\n\a\t\t\t\t\tDEAR CUSTOMER....MANAGING YOUR TOTAL BILL...."<<endl<<endl;
		cout<<"\n\n\t\t\t\t\tENTER ALL THE DETAILS..."<<endl;
		cout<<"\n\a\t\t\t\t\tEnter Price Of "<<Prescription<<": ";
		float MedicinePrice;
		cin>>MedicinePrice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
		string Date;
		cout<<"\a\t\t\t\t\tEnter Date of Today: ";
		getline(cin,Date);
		
		float TotalBill=MedicinePrice+Fees;
		
		cout<<"\a\n\n\t\t\t\t\tYOUR DETAILS ARE SAVED!..	Enter To Calculate BILL!: ";
	    cin.get();
		cout<<"\a\n\n\t\t\t\t\t================================================"<<endl;
		cout<<"\t\t\t\t\t\t\tPatient-ID : "<<PtID<<endl;
		cout<<"\t\t\t\t\t\t\tPatientName: "<<PtName<<endl;
		cout<<"\t\t\t\t\t\t\tDocterName : "<<DrName<<endl;
		cout<<"\t\t\t\t\t\t\tDocterFees : "<<Fees<<endl;
		cout<<"\t\t\t\t\t\t\tMedicine-Rs: "<<MedicinePrice<<endl;
		cout<<"\t\t\t\t\t-------------------------------------------------"<<endl;
		cout<<"\t\t\t\t\t\t\tTotal_Bill : "<<TotalBill<<"Rs- "<<endl;
		cout<<"\t\t\t\t\t================================================="<<endl;
	    
	    
        
	    CreateHistory(PtID,PtName,DrName,Disease,Date,TotalBill);
	}
	
	void Accountant::CreateHistory(string PtID,string PtName,string DrName,string Disease,string date,float Bill)
	{
	   	fstream Myfile("History.csv",ios::app);
	   	if(Myfile.is_open())
	   	{
	   		Myfile<<PtID<<","<<PtName<<","<<DrName<<","<<Disease<<","<<date<<","<<Bill<<endl;
		}
		else
		{
			cout<<"\a\t\t\t\t\tERROR: History File Not Opening!.."<<endl;
		}
	}
	
	void Accountant::ManageBill_And_History()
	{
		
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
		    	if (line.empty())
                   continue;
                   
			    stringstream S(line);
		        string PID,PName,PDisease,DrID,DrName,DFees,Status,Prescription;
		        getline(S,PID,',');
		        getline(S,PName,',');
		        getline(S,PDisease,','); 
		        getline(S,DrID,',');
		        getline(S,DrName,',');
		        getline(S,DFees,',');
		        getline(S,Status,',');
		        getline(S,Prescription,',');
		        float Fees=stof(DFees);
		        
		        
		        if(!(PID == PatientID && DrID == DocterID && Status=="DONE"))
		        {
		        	Temp<<PID<<","<<PName<<","<<PDisease<<","<<DrID<<","<<DrName<<","<<DFees<<","<<Status<<","<<Prescription<<endl;
				}
				else
				{
					CreateBill(PID,PName,DrName,PDisease,Prescription,Fees);
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
	

