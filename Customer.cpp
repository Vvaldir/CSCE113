#include "Customer.h"

using namespace std;

//------------------------------------------------------------------------------//

namespace ATM{

//-------[Constructors]-------------------------------------------------------------//

Customer::Customer(string FN, string LN, int Pin, float Bal, string Acct, vector<string> Trnz) // Full Constructor. Used for Reading/Writing from/to files
	: First_Name(FN), Last_Name(LN), PinNum(Pin), Balance(Bal), Account(Acct)		// Initializes all Data Members other than the Vector. Standard Constructor
{ for (int i(0); i<Trnz.size(); ++i){this->Trns[i] = Trnz[i];} }	// Initializes the Vector. When testing, watch this part carefully, "this" may not work as intended.


Customer::Customer(string FN, string LN, int Pin, float Bal, string Acct)
	: PinNum(Pin), Balance(Bal), Account(Acct)
{}	// Initialize most Data Members


Customer::Customer()						// Default Constructor
	: PinNum(5000), Balance(0), Account("100049999")	// Start Pin numbers at 5000. Account Nums should be acquired from the Account struct.
{}

//------------------------------------------------------------------------------//

void TrnsLog(int Account, vector<string> Trns){	    // Print out the last 10 Transactions
	for (int i(0); i<(Trns.size()); ++i)
	{
		std::cout << Trns[i];                       // 
		if (i%5 == 0 && i != 0) { cout << "\n";}    // Output Formatting: 5 Transactions per Line
		if (i%5 != 0) {cout << "\t";}               // 
	}
};

//------------------------------------------------------------------------------//    
  
void Withdrawal(float amount, Customer C)
{
    if(C.Ret_Balance() - amount > 50 && amount<500)
    {
        C.Ret_Balance = C.Ret_Balance-amount;
        C.PrintBalance();
    }
    else
    {
        cout<<"Ye lack de booty! (Insufficient Funds!)";
    }
}

//------------------------------------------------------------------------------//  

void Deposit(float amount, Customer C)
{
    C.Ret_Balance = C.Ret_Balance+amount;
    C.PrintBalance();
};
  
//------------------------------------------------------------------------------//  

bool AcctNumChk(istream& is, string AcctNum) {		// Called by '>>' Operator
	for (int i(0); i<AcctNum.size(); ++i)
	{
		if (isdigit(AcctNum[i]) != true) // Check for non-numerical characters
		{
			is.clear(ios_base::failbit); 
			cout << "Not all characters in AcctNum are numbers!\n"; 
			return false;	// failure
		}	
	}

	if (AcctNum.size() < 9) {			// Check size of AcctNum
		is.clear(ios_base::failbit);
		cout << "Too few numbers in AcctNum!\n";
		return false;		// failure
	}

	if (AcctNum.size() > 9) {			// Check size of AcctNum
		is.clear(ios_base::failbit); 
		cout << "Too many numbers in AcctNum!\n"; 
		return false;		// failure
	}

	else {return true;}			// Success!
}

//------------------------------------------------------------------------------//  

bool DupAcctChk(string NewAcct) {  // Returns false if there is another acct with the same number as NewAcct
	return true;
}

//------------------------------------------------------------------------------//  

string AcctNumGenerator() {				// Needs DupAcctChk Defined!
	int RA(0);
	string RandAcctNum;
	// bool Isnt_Unique = true;

	//while (Isnt_Unique) {
		RA = ((rand()*32767) % 899999999 + 100000000);	// Acct Number is between 100,000,000 and 999,999,999
		RandAcctNum = std::to_string(RA);
		// if (DupAcctChk(RandAcctNum) == true) {Isnt_Unique = false);
	//}

	return RandAcctNum;
}

//------------------------------------------------------------------------------//  

bool PinChk(istream& is, string PinNbmr) {
	for (int i(0); i<PinNbmr.size(); ++i)
	{
		if (isdigit(PinNbmr[i]) != true) // Check for non-numerical characters
		{
			is.clear(ios_base::failbit); 
			cout <<"Not all characters in the Pin are numbers!\n"; 
			return false;	// failure
		}	
	}

	if (PinNbmr.size() < 4) {			// Check size of PinNbmr
		is.clear(ios_base::failbit);
		cout << "Too few numbers in the Pin!\n";
		return false;		// failure
	}

	if (PinNbmr.size() > 4) {			// Check size of PinNbmr
		is.clear(ios_base::failbit); 
		cout << "Too many numbers in the Pin!\n"; 
		return false;		// failure
	}

	else {return true;}			// Success!
}

//------------------------------------------------------------------------------//  

string PinGenerator(){
	int RP(0);
	string RandPin;

	RP = (rand()%9000)+1000;	// Pin is equal to a value between 1000 and 9999
	RandPin = std::to_string(RP);	// Make the Number into a string

	return RandPin;
}

//-------[Customer::Operators]--------------------------------------------------------------//  

bool Customer::operator>>(istream& is, Customer& C)
{
	string FN,LN, AcctNum, PinNmbr;
	int Pin(0);
	float Blnce(0.0);
	stringstream SS(ios::in|ios::out);
	bool test1 = false;
	bool test2 = false;
	bool test3 = false;	
	
	is >> FN >> LN;
	if (!is) return is;
	while (!test3) {
		is >> Blnce;
		if (Blnce >= 1000) {test3 = true;}		// Check to see if the Balance is enough to make an acct (more than $999.99)
	}

	PinNmbr = PinGenerator();		// Generate a Pin
	AcctNum = AcctNumGenerator();	// Generate a unique Account Number
	
	test1 = AcctNumChk(is, AcctNum);	// Check Validity of AcctNum value.
	test2 = PinChk(is, PinNmbr);		// Check Validity of PinNmbr value. If needed, this function call can be removed, just initialize test2 to "true".
						
	if (test2 == true) { SS.str(PinNmbr); SS >> Pin; }	// If valid pin, Make it into an int.
		if (test1 == true && test2 == true && test3 == true) { C = Customer::Customer(FN, LN, Pin, Blnce, AcctNum); }	// if valid AcctNum, PinNmbr, and Blnce, fill in customer with standard Constructor.
	
	return is;
}  

                          
bool Customer::operator<<(ostream& os, Customer& C)		// Need to do formatting!
{
	return os << "[" << C.Ret_First_Name() << " " << C.Ret_Last_Name() << ", " << C.Ret_Account() << "]\n";
}
  

bool Customer::operator==(const Customer& C1, const Customer& C2)
{
// NOTE: This operator does not check the contents of the Vector in order to simplify and speed up the comparison
	return C1.Ret_First_Name() == C2.Ret_First_Name()
		&& C1.Ret_Last_Name() == C2.Ret_Last_Name()
		&& C1.Ret_Account() == C2.Ret_Account()
		&& C1.Ret_PinNumber() == C2.Ret_PinNumber() 
		&& C1.Ret_Balance() == C2.Ret_Balance();
}

//-------[File I/O]----------------------------------------------------------------//

vector<ATM::Customer> FileRead(string FileName) 		// Works for text files of any length.
{
	string Text;								// Placeholder, used as a buffer for transfer into FCS
	vector<string> FCS;							// Holds Customer data as a string for read-in by '>>'
	stringstream SS (ios::in|ios::out);
	
	ifstream ifst; ifst.open(FileName);				// Initializes the File Stream to a .txt file
	if (!ifst) {cout << "Cannot open input file " << FileName << "!\n";}	// Checks for valid File

	while (getline(ifst,Text)) 
	{
		FCS.push_back(Text);	// Puts each line from the .txt file in the vector
		//cout << " Acquired a line: " << FCS.back();
	}
	
	int P = FCS.size();
	vector<ATM::Customer> Final_Cust_Vec(P);
	for (int i(0); i<P; ++i) {
		SS.str(FCS[i]);
		SS >> Final_Cust_Vec[i];
			// Read info from file (which is in FCS now) into the customer data vector
		//if (SS.good() == 0){cout << " ~";}	// For testing File Read abilities
	}
	
	ifst.close();
	return Final_Cust_Vec;
};


void FileWrite(string FileName, vector<Customer> CustVec) 		// Works for text files of any length.
{
	string Text;								// Placeholder, used as a buffer for transfer into File
	stringstream SS (ios::in|ios::out);
  
  
	ofstream ofst;	
  	ofst.open(FileName);								// Initializes the File Stream to a .txt file
	if (!ofst) {cout << "Cannot open output file " << FileName << "!\n";}	 // Checks for valid file

	for (int i(0); i<CustVec.size(); ++i) {  			// Reads the Contents of CustVec to the file
		ofst << CustVec[i];
		ofst << "\n";
	}
  
  	if (ofst.good() == 0){cout << "Successful Write!\n";}
	ofst.close();
};

//---------[File I/O - Operators]------------------------------------------------------------//

// Work on this!
bool operator>>(istream& is, Customer& C)
{
	//char ch1,ch2,ch3;
	string FN,LN, AcctNum;
	int Pin(0);
	float Balnce(0.0);
	
	is /*>> ch1*/ >> FN >> LN /*>> ch2*/ >> AcctNum /*>> ch3*/;
	if (!is) return is;
	/*if (ch1!='[' || ch2!=',' || ch3!=']') { // format error
        is.clear(ios_base::failbit);        // set the fail bit
        return is;
    }*/
	bool test = AcctNumChk(is, AcctNum);
	if (test == true) { C = Customer::Customer(FN, LN, Pin, Balnce, AcctNum); }	// if valid SSN, fill in customer with Full Constructor.
	
	return is;
}  

/*	.txt File Format

[
customer first_name last_name
account account_number
PIN pin_number
balance amount_number
transactions { 
(date amount)
(date amount)
(date amount)
...
}
]

*/
};
