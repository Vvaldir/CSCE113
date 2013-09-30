#include "Header.h"

using namespace ATM;

//------------------------------------------------------------------------------//

Customer::Customer(string FN, string LN, int Pin, float Bal, int Acct, vector<string> Trns)
	: Pin(0), Balance(0), Account(0)
{}	

//------------------------------------------------------------------------------//

Customer::Customer()						// Default Constructor
	: Pin(0), Balance(0), Account(0)
{}

//------------------------------------------------------------------------------//

void TrnsLog(int Account, vector<string> Trns){	
	for (int i(0); i<(Trns.size()); ++i)
	{
		std::cout << Trns[i];
		if (i%5 == 0 && i != 0) { cout << "\n";}
		if (i%5 != 0) {cout << "\t";}
	}
};
