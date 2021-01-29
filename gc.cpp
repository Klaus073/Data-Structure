#include<iostream>
#include<string>

using namespace std;

//Abstract class
class Account {
protected:
	string name;	//Name of account holder
	int account_no;		//Account number
	long balance;	//Account balance
public:
	string getName() {
		return this->name;
	}
	int getAccno() {
		return this->account_no;
	}
	int getBalance() {
		return this->balance;
	}
	void setName(string name) {
		this->name = name;
	}
	void setAccountNo(int account_no) {
		this->account_no = account_no;
	}
	void makeDeposit(long amount) {
		this->balance += amount;
	}
	//Pure virtual functions
	virtual void withdrawMoney(long amount) = 0;
	virtual void createStatement() = 0;
};

//Abstract class
class CheckingAccount :public Account {
public:
	virtual void writeCheck(long amount) = 0;
};

class ServiceCheckingAccount :public CheckingAccount {
private:
	long monthlyServiceCharges;
	int numberOfChecks;
public:
	ServiceCheckingAccount(string name, int account_no, long amount, int monthlyServiceCharges, int numberOfChecks) {
		setName(name);
		setAccountNo(account_no);
		makeDeposit(amount);

		this->monthlyServiceCharges = monthlyServiceCharges;
		this->numberOfChecks = numberOfChecks;
	}
	void monthlyCharge() {
		withdrawMoney(monthlyServiceCharges); //Deduct monthly charges from account each month.
	}
	void writeCheck(long amount) {
		if (numberOfChecks > 0) {
			if (getBalance() >= amount) {
				withdrawMoney(amount);
			}
			else {
				cout << "Check bounced due to insufficient balance.\n";
			}
			numberOfChecks--;
		}
		else {
			cout << "Check limit reached.\n";
		}
	}
	void withdrawMoney(long amount) {
		this->balance -= amount;
	}
	void createStatement() {
		cout << "                                 Account Statement" << endl;
		cout << "\tAccount holder's name: \t" << getName() << endl;
		cout << "\tAccount type:          \t" << "Service Checking Account" << endl;
		cout << "\tMonthly Service Charges\t" << this->monthlyServiceCharges << endl;
		cout << "\tNumber Of Checks:      \t" << this->numberOfChecks << endl;
		cout << "\tAccount Balance:       \t" << getBalance() << endl;
	}
};

class NoServiceCheckingAccount :public CheckingAccount {
protected:
	double interestRate;
	long min_balance;
public:
	NoServiceCheckingAccount(string name, int account_no, long amount, double interestRate, long min_balance) {
		setName(name);
		setAccountNo(account_no);
		makeDeposit(amount);

		this->interestRate = interestRate;
		this->min_balance = min_balance;
	}
	void setInterestRate(double interestRate) {
		this->interestRate = interestRate;
	}
	void setMinBalance(long min_balance) {
		this->min_balance = min_balance;
	}
	void writeCheck(long amount) {
		if (getBalance() - amount >= min_balance) {
			withdrawMoney(amount);
		}
		else {
			cout << "Check bounced due to insufficient balance.\n";
		}
	}
	void withdrawMoney(long amount) {
		this->balance -= amount;
	}
	void createStatement() {
		cout << "                                 Account Statement" << endl;
		cout << "\tAccount holder's name: \t" << getName() << endl;
		cout << "\tAccount Type:          \t" << "No-Service Checking Account" << endl;
		cout << "\tInterest Rate:         \t" << this->interestRate << endl;
		cout << "\tMinimum Balance Require\t" << this->min_balance << endl;
		cout << "\tAccount Balance:       \t" << getBalance() << endl;
	}
};

class HighInterestChecking :public NoServiceCheckingAccount {
public:
	HighInterestChecking(string name, int account_no, long amount, double interestRate, long min_balance)
		:NoServiceCheckingAccount(name, account_no, amount, interestRate * 1.10, min_balance) {
		//Body is blank cuz parent class constructor is taking care of initializing account.
	}
	void setInterestRate(double interestRate) {
		this->interestRate = interestRate;
	}
	void setMinBalance(long min_balance) {
		this->min_balance = min_balance;
	}
	void writeCheck(long amount) {
		if (getBalance() - amount >= min_balance) {
			withdrawMoney(amount);
		}
		else {
			cout << "Check bounced due to insufficient balance.\n";
		}
	}
	void withdrawMoney(long amount) {
		this->balance -= amount;
	}
	void createStatement() {
		cout << "                                 Account Statement" << endl;
		cout << "\tAccount holder's name: \t" << getName() << endl;
		cout << "\tAccount Type:          \t" << "High Interest No-Service Checking Account" << endl;
		cout << "\tInterest Rate:         \t" << this->interestRate << endl;
		cout << "\tMinimum Balance Require\t" << this->min_balance << endl;
		cout << "\tAccount Balance:       \t" << getBalance() << endl;
	}
};

class SavingsAccount :public Account {
protected:
	double interestRate;
public:
	SavingsAccount(string name, int account_no, long amount, double interestRate) {
		setName(name);
		setAccountNo(account_no);
		makeDeposit(amount);
		this->interestRate = interestRate;
	}
	void setInterestRate(double interestRate) {
		this->interestRate = interestRate;
	}
	double getInterestRate() {
		return this->interestRate;
	}
	void withdrawMoney(long amount) {
		if (balance >= amount) {
			balance -= amount;
		}
		else {
			cout << "Insufficient amount.\n";
		}
	}
	void createStatement() {
		cout << "                                 Account Statement" << endl;
		cout << "\tAccount holder's name: \t" << getName() << endl;
		cout << "\tAccount type:          \t" << "Savings Account" << endl;
		cout << "\tInterest Rate:         \t" << this->interestRate << endl;
		cout << "\tAccount Balance:       \t" << getBalance() << endl;
	}
};

class HighInterestSaving :public SavingsAccount {
private:
	long min_balance;
public:
	HighInterestSaving(string name, int account_no, long amount, double interestRate, long min_balance)
		:SavingsAccount(name, account_no, amount, interestRate) {

		this->min_balance = min_balance;
	}
	void setMinBalance(long min_balance) {
		this->min_balance = min_balance;
	}
	long getMinBalance() {
		return this->min_balance;
	}
	void withdrawMoney(long amount) {
		if (getBalance() - amount >= min_balance) {
			withdrawMoney(amount);
		}
		else {
			cout << "Insufficient balance.\n";
		}
	}
	void createStatement() {
		cout << "                                 Account Statement" << endl;
		cout << "\tAccount holder's name: \t" << getName() << endl;
		cout << "\tAccount type:          \t" << "High Interest Savings Account" << endl;
		cout << "\tInterest Rate:         \t" << this->interestRate << endl;
		cout << "\tMinimum Balance Require\t" << this->min_balance << endl;
		cout << "\tAccount Balance:       \t" << getBalance() << endl;
	}
};

class CertificateOfDeposit :public Account {
private:
	int numberOfMaturityMonths;
	int currentMonth;
	double interestRate;
public:
	CertificateOfDeposit(string name, int account_no, long amount, int numberOfMaturityMonths, double interestRate) {
		this->setName(name);
		this->setAccountNo(account_no);
		this->makeDeposit(amount);

		this->numberOfMaturityMonths = numberOfMaturityMonths;
		this->interestRate = interestRate;
		this->currentMonth = 1;
	}
	int getCurrentMonth() {
		return this->currentMonth;
	}
	double getInterestRate() {
		return this->interestRate;
	}
	int getNumberOfMaturityMonths() {
		return this->numberOfMaturityMonths;
	}
	void setInterestRate(double interestRate) {
		this->interestRate = interestRate;
	}
	void setCurrentMonth(int currentMonth) {
		this->currentMonth = currentMonth;
	}
	void withdrawMoney(long amount) {
		if (currentMonth < numberOfMaturityMonths) {
			if (amount * interestRate < getBalance())
				balance -= amount * interestRate;
			else
				cout << "Insufficient bank balance.\n";
		}
		else {
			balance -= amount;
		}
	}
	void createStatement() {
		cout << "                                 Account Statement" << endl;
		cout << "\tAccount holder's name: \t" << getName() << endl;
		cout << "\tAccount type:          \t" << "Certificate Of Deposit" << endl;
		cout << "\tTotal Maturity Months: \t" << this->numberOfMaturityMonths << endl;
		cout << "\tCurrent Maturity Month:\t" << this->currentMonth << endl;
		cout << "\tAccount Balance:       \t" << getBalance() << endl;
	}
};


//Main function to test each class
int main() {
	int index;

	Account* bankAccounts[6];


	int choice = 0;
	cout << "Press 1 for Service Checking Account: " << endl;
	cout << "Press 2 for No Service Checking Account: " << endl;
	cout << "Press 3 for High Interest Checking: " << endl;
	cout << "Press 4 for Saving Account: " << endl;
	cout << "Press 5 for High Interest Saving: " << endl;
	cout << "Press 6 for Certificate of Deposit: " << endl;
	cout << "enter choice btw 1-6 " << endl;
	cin >> choice;
	for (int i = 0; i < 6; i++)
	{
		if (choice == 1)
		{
			bankAccounts[0] = new ServiceCheckingAccount("Muhammad Usman", 01, 6000, 100, 25);
			bankAccounts[0]->createStatement();
			return 0;
		}
		if (choice == 2)
		{
			bankAccounts[1] = new NoServiceCheckingAccount("Muneeb Younus", 01, 5000, 1.25, 500);
			bankAccounts[1]->createStatement();
			return 0;
		}
		if (choice == 3)
		{
			bankAccounts[2] = new HighInterestChecking("Hammad Malik", 01, 4000, 1.25, 500);
			bankAccounts[2]->makeDeposit(500);
			bankAccounts[2]->createStatement();
			return 0;
		}
		if (choice == 4)
		{
			bankAccounts[3] = new SavingsAccount("Abdul Rehman", 01, 7000, 1.75);
			bankAccounts[3]->withdrawMoney(1000);
			bankAccounts[3]->createStatement();
			return 0;
		}
		if (choice == 5)
		{
			bankAccounts[4] = new HighInterestSaving("Bushra Ishaq", 01, 8000, 1.75, 1000);
			bankAccounts[4]->createStatement();
			return 0;
		}
		if (choice == 6)
		{
			bankAccounts[5] = new CertificateOfDeposit("Neelam", 01, 5000, 6, 1.25);
			bankAccounts[5]->createStatement();
			return 0;
		}
		else
		{
			cout << "wrong input" << endl;
		}


	}



	return 0;
}