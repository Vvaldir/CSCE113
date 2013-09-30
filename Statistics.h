#include <iostream>
#include <vector>
#include <sstream>

using namespace std;


namespace ATM { 

//------------------------------------------------------------------------------//

struct Statistics{
	
	Statistics();
	
	void PrntAveBal() {cout << ( Bank::TotalBal(Accts)/Bank::CustomerCt() ) << endl;}	// Prints the average balance in the bank
	void PrntCCt() {cout << Bank::CustomerCt() << endl;}					// Prints the number of Customers
	void PrntTB() {cout << Bank::TotalBal(Bank::Accts) << endl; }				// Prints the total balance in the bank
	
};

//------------------------------------------------------------------------------//
}
