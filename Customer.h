#ifndef CUSTOMER_GUARD	// if "CUSTOMER_GUARD" isn't defined, then...
#define CUSTOMER_GUARD	// Define "CUSTOMER_GUARD" as the following code:

#include "Account.h"

using namespace std;

namespace ATM{

class Customer {            // Also gets data from .txt file
	// Data Members
	vector<string> Trns;
	string First_Name;
	string Last_Name;
	int PinNum;
	float Balance;
	string Account;	// Really is a member of ATM::Account, just copied over here for easy File I/O applications.

public:
	// Constructors
	Customer(string FN, string LN, int Pin, float Bal, string Acct, vector<string> Trns);	// Full Constructor (For Reading from file)
	Customer(string FN, string LN, int Pin, float Bal, string Acct);	// Standard Constructor
	Customer();			// Default Constructor

	// Non-Modifiers
	vector<string> Trns() const {return Trns;}
	string Ret_First_Name() const {return First_Name;}
	string Ret_Last_Name() const {return Last_Name;}
	int Ret_PinNumber() const {return PinNum;}
	float Ret_Balance() const {return Balance;}
	string Ret_Account()const {return Account;}

	// Friends
	friend struct Account;
	
  	// Member Modifiers
	float Bal_Change(float F) {Balance = Balance+F;}

	// Print Functions
	void TrnsLog(string Account, vector<string> Trns);				// Prints Transaction Log. Should read info from file into a vector and then print out said vector.
	void PrintBalance() const {cout << Balance << endl;};

	//Operators	- Only Callable if you do Customer::operatorXX
	static bool operator>>(istream& is, Customer& C);
 	static bool operator<<(ostream& os, Customer& C);
	static bool operator==(const Customer& C1, const Customer& C2);

	// Called by Account Functions
	void Withdrawal(float amount);
	void Deposit(float amount);
};

//-------[Misc Functions]-----------------------------------------------------//	
		// Check Format
bool AcctNumChk(istream& is, string SSN);
bool PinChk(istream& is, int PinNbmr);
		// Create Random Values
string PinGenerator();
string AcctNumGenerator();
		// Check for Duplicates
bool DupAcctChk(string NewAcct);	// Returns false if there is another acct with the same number as NewAcct

//-------[File I/O]-----------------------------------------------------//	    
void FileWrite(string FileName,vector<Customer> CustVec);
vector<ATM::Customer> FileRead(string FileName);

//----------------------------------------------------------------------------//

//-------[Operators]------------------------------------------------------------//
// NOTE: These Functions are defined for file I/O purposes, and should not be used for anything other than file I/O or you may get odd results!		
bool operator>>(istream& is, Customer& C);
bool operator<<(ostream& os, Customer& C);
//bool operator==(const Customer& C1, const Customer& C2);                        
  
/*
struct Statistics{
	
	Statistics();
	
	void PrntAveBal() {cout << ( Bank::TotalBal(Accts)/Bank::CustomerCt() ) << endl;}	// Prints the average balance in the bank
	void PrntCCt() {cout << Bank::CustomerCt() << endl;}					// Prints the number of Customers
	void PrntTB() {cout << Bank::TotalBal(Bank::Accts) << endl; }				// Prints the total balance in the bank
	
};
*/
}

#endif
