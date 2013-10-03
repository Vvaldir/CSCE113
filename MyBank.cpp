#include <iostream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

void greet()
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
            //open();
            break;
            
        case 2:
            //login();
            break;
            
        case 3:
            //bank_stats();
            break;
            
        default:
        {
            cout<<"Please enter the number of the choice you want followed by the enterkey"<<endl;
            cin;
            cin.clear();
            greet();
        }
    }
}

int main()
{
    greet();

	
	return 0;
}
