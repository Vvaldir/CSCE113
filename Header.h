#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

//------------------------------------------------------------------------------//
namespace ATM{

struct Bank {
	Bank();				// Default Constructor

	// Account Management
	void OpenAcct();
	void CloseAcct();

	// Raw Data
	int CustomerCt() const {return Accts.size();}					// Counts the total number of Customers
	float TotalBal(vector<Customer> AcctVec);													

	// Printers
	/*
	void AveBal() {cout << ( TotalBal(Accts)/CustomerCt() ) << endl;}	// Prints the average balance in the bank
	void PrntCCt() {cout << CustomerCt() << endl;}					// Prints the number of Customers
	void PrntTB() {cout << TotalBal(Accts) << endl; }					// Prints the total balance in the bank
	*/
private:
	vector<Customer> Accts;		// The bank is built off of a vector of Accounts
};

//------------------------------------------------------------------------------//
/*		// Obsolete
struct Account {
	Account();					// Default Constructor

	void Transaction();			// Responsible for Withdrawal and Deposit Calls in Customer
	void Transaction_Log();		// Prints out 10 previous Transactions (Calls TrnsLog in Customer)

private:
	class Customer;				// An account is built off of a Customer
};
*/
//------------------------------------------------------------------------------//

struct Statistics{
	
	Statistics();
	
	void PrntAveBal() {cout << ( Bank::TotalBal(Accts)/Bank::CustomerCt() ) << endl;}	// Prints the average balance in the bank
	void PrntCCt() {cout << Bank::CustomerCt() << endl;}					// Prints the number of Customers
	void PrntTB() {cout << Bank::TotalBal(Bank::Accts) << endl; }					// Prints the total balance in the bank
	
};

//------------------------------------------------------------------------------//

class Customer {
	Customer(string FN, string LN, int Pin, float Bal, int Acct, vector<string> Trns);		// Constructor
	Customer();				// Default Constructor

	// Data Members
	vector<string> Trns;
	string First_Name;
	string Last_Name;
	int Pin;
	float Balance;
	int Account;

public:
	// For use by Account Functions
	float Withdrawal(float Balance, int Account);
	float Deposit(float Balance, int Account);

	// Print Functions
	void TrnsLog(int Account, vector<string> Trns);				// Prints Transaction Log
	void PrintBalance() const {cout << Balance << endl;};
};

//------------------------------------------------------------------------------//

}
