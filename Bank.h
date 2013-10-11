#ifndef BANK_GUARD
#define BANK_GUARD

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "Customer.h"

using namespace std;

//------------------------------------------------------------------------------//
namespace ATM{

struct Bank {
	Bank();				// Default Constructor

	// Account Management
	void OpenAcct();
	void CloseAcct();
  
  	void LogIn(int AcctNum, int PinNum);

	// Raw Data
	int CustomerCt() const {return Accts.size();}			// Counts the total number of Customers
	float TotalBal(vector<Customer> AcctVec);													

	// Printers
	void AveBal() {cout << ( TotalBal(Accts)/CustomerCt() ) << endl;}	// Prints the average balance in the bank
	void PrntCCt() {cout << CustomerCt() << endl;}				// Prints the number of Customers
	void PrntTB() {cout << TotalBal(Accts) << endl;}			// Prints the total balance in the bank
	
	// Friends
	friend class Customer;

private:
	vector<Customer> Accts;		// The bank is built off of a vector of Accounts
};

//------------------------------------------------------------------------------//
}

#endif
