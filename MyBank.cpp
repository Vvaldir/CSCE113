#include "Bank.h"

using namespace std;

void greet();

void bank_stats();

int main()
{
	ATM::Bank Bank = ATM::Bank::Bank();
    greet(Bank);
  
  return 0;
}

void greet(ATM::Bank& Bank)
{
    int menu;
    
    system("clear");
    
    cout<<"Welcome to Pirate Bay Bank, We strive to meet your every need"<<endl<<endl;
    cout<<"What would ye like to do?"<<endl<<endl;
    cout<<"\t1) Ope account"<<endl<<endl;
    cout<<"\t2) Log in"<<endl<<endl;
    cout<<"\t3) View Bank Stats"<<endl<<endl;
    
    cin>>menu;
    
    switch (menu)
    {
        case 1: 
            //OpenAcct();
            break;
            
        case 2:
            //LogIn();
            break;
            
        case 3:
            bank_stats();
            break;
            
        default:
        {
            cout<<"Please enter the number of the choice you want followed by the enterkey"<<endl;
            cin.clear();
            greet();
        }
    }
    
}

void bank_stats(ATM::Bank Bank)
{
    int menu;
    
    system("clear");
    
    cout<<"What would ye like to do?\n\n";
    cout<<"\t1) See Average Balance\n\n";
    cout<<"\t2) See number of Accounts\n\n";
    cout<<"\t3) See Total Balance\n\n";
    cout<<"\t4) Go back\n\n";
    
    cin>>menu;
    
    switch (menu)
    {
        case 1: 
            Bank.AveBal();
            break;
            
        case 2:
            Bank.PrntCCt();
            break;
            
        case 3:
            Bank.PrntTB();
            break;
            
        case 4:
            greet(Bank);
            break;
            
        default:
        {
            cout<<"Please enter the number of the choice you want followed by the enterkey"<<endl;
            cin.clear();
            bank_stats(Bank);
        }
    }
}
