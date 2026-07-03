#include<iostream>
#include<fstream>
#include<sstream>
#include <limits>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include "Menu_Global.h"
using namespace std;

void showMainMenu()
{
	
	cout<<"\a\n\n\t\t\t~~~~~~~~~~~~~~~~~~~~~~~WELLCOME TO DHQ HOSPITAL KOHAT~~~~~~~~~~~~~~~~~~~~~~\n\n";
	cout<<"\t\t\t\t\t\t____LoGiN As A____"<<endl<<endl;
	cout<<"\t\t\t\t\t\t1-Receptionalist: "<<endl;
	cout<<"\t\t\t\t\t\t2-Docter: "<<endl;
	cout<<"\t\t\t\t\t\t3-Accoutant: "<<endl;
	cout<<"\t\t\t\t\t\t4-Admin: "<<endl;
	cout<<"\t\t\t\t\t\t5-Exit: "<<endl;
}
void showReceptMenu()
{ 
    cout<<"\a\n\n\t\t\t.................WELLCOME TO RECEPTION_MENU........... .\n\n";
	cout<<"\a\t\t\t\t\t\t1-Add Patient: "<<endl;
	cout<<"\t\t\t\t\t\t2-See All Patients: "<<endl;
	cout<<"\t\t\t\t\t\t3-See All Docters: "<<endl;
	cout<<"\t\t\t\t\t\t4-Create Appointment: "<<endl;
	cout<<"\t\t\t\t\t\t5-See Appointments: "<<endl;
	cout<<"\t\t\t\t\t\t6-Cancell Appointment: "<<endl;
	cout<<"\t\t\t\t\t\t7-Log_Out: "<<endl;
}
void showDocterMenu()
{
	cout<<"\a\n\n\t\t\t.................WELLCOME TO DOCTERS_MENU........... .\n\n";
	cout<<"\a\t\t\t\t\t\t1-Check Appointments: "<<endl;
	cout<<"\t\t\t\t\t\t2-Check Patient: "<<endl;
	cout<<"\t\t\t\t\t\t3-Log_Out: "<<endl;
}
void showAccountantMenu()
{
	cout<<"\a\n\n\t\t\t.................WELLCOME TO ACCOUNTANT_MENU........... .\n\n";
	cout<<"\a\t\t\t\t\t\t1-Check Appointments-record: "<<endl;
	cout<<"\t\t\t\t\t\t2-Create Bill of patient: "<<endl;
	cout<<"\t\t\t\t\t\t3-Log_Out: "<<endl;
}
void showAdminMenu()
{
	cout<<"\a\n\n\t\t\t\t\t.................WELLCOME ADMIN........... .\n\n";
	cout<<"\a\t\t\t\t\t\t1-Add Receptionalist: "<<endl;
	cout<<"\t\t\t\t\t\t2-Add Doctors: "<<endl;
	cout<<"\t\t\t\t\t\t3-Add Accountants: "<<endl;
	cout<<"\a\t\t\t\t\t\t4-See All Patients: "<<endl;
	cout<<"\t\t\t\t\t\t5-Delete Patient: "<<endl;
	cout<<"\t\t\t\t\t\t6-See All Docters: "<<endl;
	cout<<"\t\t\t\t\t\t7-Delete Docter: "<<endl;
	cout<<"\t\t\t\t\t\t8-See All Receptionalists: "<<endl;
	cout<<"\t\t\t\t\t\t9-Delete Receptionalist: "<<endl;
	cout<<"\t\t\t\t\t\t10-See All Accountants: "<<endl;
	cout<<"\t\t\t\t\t\t11-Delete Accountant: "<<endl;
	cout<<"\t\t\t\t\t\t12-See History: "<<endl;
	cout<<"\t\t\t\t\t\t13-Delete History: "<<endl;
	cout<<"\t\t\t\t\t\t14-Log_Out: "<<endl;
}
void PauseScreen()
{
	cout<<"\a\n\n\n\t\t\t\t\tPLEASE ENTER TO CONTINUE: ";
	cin.ignore();
	cin.get();
}
 
void ShowPatients()
{
	fstream Myfile("Patients.csv",ios::in);
	if(!Myfile.is_open())
	{
	    cout<<"\a\t\t\t\t\tERROR:File is not opening....\n";	
	}
	else
	{
		string line;
		getline(Myfile,line);
		cout<<"\a\n\n\n\t\t\t\t\t==============PATIENTS RECORD=================="<<endl;
		cout<<"\n\t\t\tID\t\tName\t\tAge\t\tGender\t\tDisease"<<endl;
		cout<<"\t\t\t======================================================================"<<endl;
	    while(getline(Myfile,line))
	    {
	    	
		    stringstream S(line);
		    string PatID,PatName,PatAge,PatGender,PatDisease;
		    getline(S,PatID,',');
		    getline(S,PatName,',');
		    getline(S,PatAge,',');
		    getline(S,PatGender,',');
		    getline(S,PatDisease,',');
		    cout<<"\t\t\t"<<PatID<<"\t\t"<<PatName<<"\t\t"<<PatAge<<"\t\t"<<PatGender<<"\t\t"<<PatDisease<<endl;
			cout<<"\t\t\t-----------------------------------------------------------------------"<<endl; 
	    }
	}
}

void ShowDocters()
{
	fstream Myfile("Docters.csv",ios::in);
	if(!Myfile.is_open())
	{
	    cout<<"\a\t\t\t\t\tERROR:File is not opening....\n";	
	}
	else
	{
		string line;
		getline(Myfile,line);
		cout<<"\a\n\n\n\t\t\t\t\t==============DOCTERS RECORD=================="<<endl;
		cout<<"\n\t\tID\t\tName\t\tFees\t\tTiming\t\t\t\tSepcilization"<<endl;
		cout<<"\t\t==================================================================================================="<<endl;
	    while(getline(Myfile,line))
	    {
	    	
		    stringstream S(line);
		    string DrID,DrName,DrPass,DrFees,DrTime,DrSpz;
		    getline(S,DrID,',');
		    getline(S,DrName,',');
		    getline(S,DrPass,','); // Unused Veriable
		    getline(S,DrFees,',');
		    getline(S,DrTime,',');
		    getline(S,DrSpz,',');
		    cout<<"\t\t"<<DrID<<"\t\t"<<DrName<<"\t\t"<<DrFees<<"\t\t"<<DrTime<<"\t\t\t"<<DrSpz<<endl;
			cout<<"\t\t------------------------------------------------------------------------------------------------"<<endl; 
	    }
	}
}

void ShowAppointments()
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
		cout<<"\a\n\n\n\t\t\t\t\t==============APPOINTMENTS RECORD=================="<<endl;
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
		    cout<<PID<<"\t\t"<<PName<<"\t\t"<<PDisease<<"\t\t"<<DrID<<"\t\t"<<DrName<<"\t\t"<<Fees<<"\t "<<Status<<"\t\t"<<Prescription<<endl;
			cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl; 
	    }
	}
}

void ShowReception()
{
	fstream Myfile("Reception.csv",ios::in);
	if(!Myfile.is_open())
	{
	    cout<<"\a\t\t\t\t\tERROR:File is not opening....\n";	
	}
	else
	{
		string line;
		getline(Myfile,line);
		cout<<"\a\n\n\n\t\t\t\t==============RECEPTIONS RECORD=================="<<endl;
		cout<<"\n\t\t\t\t\tRecept-ID\t\tRecept-Name"<<endl;
		cout<<"\t\t\t\t\t===================================="<<endl;
	    while(getline(Myfile,line))
	    {
	    	
		    stringstream S(line);
		    string RID,RName,RPass;
		    getline(S,RID,',');
		    getline(S,RName,',');
		    getline(S,RPass,','); // Unused Veriable
		    cout<<"\t\t\t\t\t"<<RID<<"\t\t\t"<<RName<<endl;
			cout<<"\t\t\t\t\t------------------------------------"<<endl; 
	    }
	}
}

void ShowAccountant()
{
	fstream Myfile("Accountants.csv",ios::in);
	if(!Myfile.is_open())
	{
	    cout<<"\a\t\t\t\t\tERROR:File is not opening....\n";	
	}
	else
	{
		string line;
		getline(Myfile,line);
		cout<<"\a\n\n\n\t\t\t\t==============ACCOUNTANTS RECORD=================="<<endl;
		cout<<"\n\t\t\t\t\tAcctt-ID\t\tAcctt-Name"<<endl;
		cout<<"\t\t\t\t\t===================================="<<endl;
	    while(getline(Myfile,line))
	    {
	    	
		    stringstream S(line);
		    string AID,AName,APass;
		    getline(S,AID,',');
		    getline(S,AName,',');
		    getline(S,APass,','); // Unused Veriable
		    cout<<"\t\t\t\t\t"<<AID<<"\t\t\t"<<AName<<endl;
			cout<<"\t\t\t\t\t------------------------------------"<<endl; 
	    }
	}
}


void ShowHistory()
{
	fstream Myfile("History.csv",ios::in);
	if(!Myfile.is_open())
	{
	    cout<<"\a\t\t\t\t\tERROR:File is not opening....\n";	
	}
	else
	{
		string line;
		getline(Myfile,line);
		cout<<"\a\n\n\n\t\t\t\t================ALL HISTORY=================="<<endl;
		cout<<"\n\t\t\tID\t\tName\t\tDrName\t\tDisease\t\tDate\t\tFees"<<endl;
		cout<<"\t\t\t========================================================================================"<<endl;
	    while(getline(Myfile,line))
	    {
	    	if(line.empty())
	    	  continue;
	    	 
			 
		    stringstream S(line);
		    string PtID,PtName,DrName,Disease,Date,Fees;
		    getline(S,PtID,',');
		    getline(S,PtName,',');
		    getline(S,DrName,',');
		    getline(S,Disease,',');
			getline(S,Date,',');
			getline(S,Fees,','); 
			if (PtID.empty())
            continue;
		    cout<<"\t\t\t"<<PtID<<"\t\t"<<PtName<<"\t\t"<<DrName<<"\t\t"<<Disease<<"\t\t"<<Date<<"\t"<<Fees<<endl;
			cout<<"\t\t\t-----------------------------------------------------------------------------------------"<<endl; 
	    }
	}
}
