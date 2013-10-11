#ifndef ACCOUNT_GUARD
#define ACCOUNT_GUARD

#include "Bank.h"

using namespace std;

//------------------------------------------------------------------------------//

namespace ATM{

struct Account {
	Account();			// Default Constructor, gets account number from Customer and sets it to the account
	
	void Transaction();		// Responsible for Withdrawal and Deposit Calls in Customer
	void Transaction_Log();		// Prints out 10 previous Transactions (Calls TrnsLog in Customer)

	// Friends
	friend struct Bank;
	friend class Customer;

private:
	class Customer;			// An account is built off of a Customer
	string AcctNumber;		// Starts at 100050000, and is equal to 100050000 + CustomerCt()
};

//------------------------------------------------------------------------------//

}

#endif
