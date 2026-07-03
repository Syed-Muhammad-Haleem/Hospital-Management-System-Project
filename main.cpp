#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include <limits>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include "Person.h"
#include "Patient.h"
#include "Docter.h"
#include "Reception.h"
#include "Accountant.h"
#include"Hospital.h"
#include "Admin.h"
#include "Menu_Global.h"
using namespace std;

// Global Objects of Hospital and Admin
Hospital  HospitalMainObject;
Admin AdminObject("101","Haleem","1234");  // WE will Used it Perform Admin Operation

int main()
{
	
  do
  {
  	system("cls");
  	showMainMenu();
  	int Choice;
  	cout<<"\n\a\t\t\t\t\t\tEnter Choice: ";
  	cin>>Choice;
  	switch(Choice)
  	{
  		case 1:
  	    {
  	      while(true)   // this loop is used to maintain login session
		  {
		  	  Reception *Rec=HospitalMainObject.manageReception();
		  	  bool LoopController=false;
		  	  if(Rec==nullptr)
		  	  {
				break;
			  }
		  	  while(true)
  	          {
  		         system("cls");
  		         showReceptMenu();
  		         int SubChoice;
  		         cout<<"\n\a\t\t\t\t\t\tEnter Choice: ";
  	             cin>>SubChoice;
  	             switch(SubChoice)
  	             {
  	      	        case 1:
  	      	        Rec->AddPatient();
  	      	        break;
  	      	
  	      	        case 2:
  	      	        ShowPatients();
  	      	        break;
  	      	  
  	      	        case 3:
  	      	        ShowDocters();
  	      	        break;
  	      	        
  	      	        case 4:
  	      	        Rec->CreateAppointment();
  	      	        break;
  	      	        
  	      	        case 5:
  	      	        ShowAppointments();
  	      	        break;
  	      	        
  	      	        case 6:
  	      	        Rec->CancellAppointment();
  	      	        break;
  	      	        
  	      	        case 7:
  	      	        cout<<"\a Backing to Main_Menu: "<<endl;
  	      	        LoopController=true;
		        }
		        if(LoopController==true)
		        {
		     	   break;
			    }
			    PauseScreen();
	          }
	          
	        if(LoopController==true)
	        {
	          break;
			}
		  }	
		  PauseScreen();    
  	    }
  		break;
  		
  		case 2:
  		{
  		 
  		 while(true)
  		 {
		      Docter *Dr=HospitalMainObject.manageDocter();
		  	  bool LoopController=false;
		  	  if(Dr==nullptr)
		  	  {
				break;
			  }
			  
  		      while(true)
  	          {
  	            system("cls");
  		        showDocterMenu();
  		        int SubChoice;
  		        cout<<"\n\a\t\t\t\t\t\tEnter Choice: ";
  	            cin>>SubChoice;
  	            switch(SubChoice)
  	            {
  	      	      case 1:
  	      	      Dr->Disply_Docter_Appointments(Dr);
  	      	      break;
  	      	
  	      	      case 2:
  	      	      Dr->CheckPatient(Dr);
  	      	      break;
  	      	  
  	      	      case 3:
  	      	      cout<<"\a Backing to Main_Menu: "<<endl;
  	      	      LoopController=true;
		        }
		        if(LoopController==true)
		        {
		     	   break;
			    }
			    PauseScreen();
	          }
	        if(LoopController==true)
	        {
	          break;
			}
	      }
	      PauseScreen();
	     }
  		break;
  		
  		case 3:
  		{
  		 while(true)
		 {	
		 
		      Accountant *Acc=HospitalMainObject.manageAccountant();
		  	  bool LoopController=false;
		  	  if(Acc==nullptr)
		  	  {
				break;
			  }
  		   while(true)
  	       {
  	        system("cls");
  		    showAccountantMenu();
  		    int SubChoice;
  		    cout<<"\n\a\t\t\t\t\t\tEnter Choice: ";
  	        cin>>SubChoice;
  	        switch(SubChoice)
  	        {
  	      	  case 1:
  	      	  ShowAppointments();
  	      	  break;
  	      	
  	      	  case 2:
  	      	  Acc->ManageBill_And_History();
  	      	  break;
  	      	  
  	      	  case 3:
  	      	  cout<<"\a Backing to Main_Menu: "<<endl;
  	      	  LoopController=true;
		     }
		     if(LoopController==true)
		     {
		     	break;
			 }
			  PauseScreen();
	       }
	       if(LoopController==true)
	        {
	          break;
			}
	      }
	      PauseScreen();
	     }
  		break;
  		
  		case 4:
  		{
  		  	   AdminObject.AdminLogin();
  		  	   while(true)
  	           {
  	             system("cls");
  		         showAdminMenu();
  		         int SubChoice;
  		         bool LoopController=false;
  		         cout<<"\n\a\t\t\t\t\t\tEnter Choice: ";
  	             cin>>SubChoice;
  	             switch(SubChoice)
  	             {
  	      	       case 1:
  	      	       {
  	      	  	      AdminObject.CreateReceptionalist();
			       }
  	      	       break;
  	      	
  	      	       case 2:
  	      	       {
  	      	       	 AdminObject.CreateDocter();
				   }
  	      	       break;
  	      	  
  	      	       case 3:
  	      	       {
  	      	       	 AdminObject.CreateAccountant();
				    }
  	      	       break;
  	      	  
  	      	       case 4:
  	      	       ShowPatients();
  	      	       break;
  	      	  
  	      	       case 5:
  	      	       AdminObject.DeletePatient();
  	      	       break;
  	      	  
  	      	       case 6:
  	      	       ShowDocters();
  	      	       break;
  	      	  
  	      	       case 7:
  	      	       AdminObject.DeleteDocter();
  	      	       break;
  	      	  
  	      	       case 8:
  	      	       ShowReception();
  	      	       break;
  	      	  
  	      	       case 9:
  	      	       AdminObject.DeleteReceptionalist();
  	      	       break;
  	      	  
  	      	       case 10:
  	      	       ShowAccountant();
  	      	       break;
  	      	       	
  	      	       case 11:
  	      	       AdminObject.DeleteAccountant();
  	      	       break;
  	      	       
  	      	       case 12:
  	      	       ShowHistory();
  	      	       break;
  	      	       
  	      	       case 13:
  	      	       AdminObject.DeleteHistory();
  	      	       break;
  	      	       
  	      	       case 14:
  	      	       cout<<"\a Backing to Main_Menu: "<<endl;
  	      	       LoopController=true;
		        }
		        
		     if(LoopController==true)
		     {
		     	break;
			 }
			  PauseScreen();
	       }
	       PauseScreen();
	    }
  		break;
  		
  		default:
  		cout<<"\a Thanks For USING the System... Exiting.."<<endl;
  		return 0;
  		
	}
  }while(true);
  	
}
