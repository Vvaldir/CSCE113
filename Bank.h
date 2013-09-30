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
	int CustomerCt() const {return Accts.size();}			// Counts the total number of Customers
	float TotalBal(vector<Customer> AcctVec);													

	// Printers
	/*
	void AveBal() {cout << ( TotalBal(Accts)/CustomerCt() ) << endl;}	// Prints the average balance in the bank
	void PrntCCt() {cout << CustomerCt() << endl;}				// Prints the number of Customers
	void PrntTB() {cout << TotalBal(Accts) << endl; }			// Prints the total balance in the bank
	*/
private:
	vector<Customer> Accts;		// The bank is built off of a vector of Accounts
};

//------------------------------------------------------------------------------//
}
