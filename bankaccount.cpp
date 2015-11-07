#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool isLogged(int status);
// Create account function
void createAccount(); 
// Calls out the main menu function
int mainMenu();
// User logged in menu function
int loggedMenu();
// Login Menu
void displayBalance();
// Withdraw Function
void withdraw();
// Deposit
void deposit();
// Interest calculator
void interest();
// Variables
double userBalance, newBalance, depositAmount;
bool status;
string username, password;

int main()
{
	int choice, choice2;
	
		// Calls the main menu function
		choice = mainMenu();
		if (choice == 1)
			createAccount();
		else if (choice == 2) {
			status = isLogged(status);
			if (!status) {
				cout << "Invalid username or pincode entered\n";
				return 0;
			}
			else {
				cout << "Welcome back to Bank of Magnus!"<< endl;
				choice2 = loggedMenu();
				switch (choice2) {
				case 1:
					displayBalance();
					break;
				case 2:
					withdraw();
					break;
				case 3:
					deposit();
					break;
				case 4:
					interest();
					break;
				default:
					cout << "Invalid menu option";
				}

			}

		}
	return 0;
}

int mainMenu()
{
	int choice;

		cout << "Please select one of the following options\n"
			<< "---------------------------------------------\n"
			<< "1: Register\n"
			<< "2: Login\n";
		cin >> choice;		cin.ignore(80, '\n');
		return choice;
}

int loggedMenu()
{
	int choice2;

	cout << "Please choice one of the following options\n"
		<< "---------------------------------------------\n"
		<< "1: Check Balance\n"
		<< "2: Widthdrawl\n"
		<< "3: Deposit\n"
		<< "4: Interest calculator\n";
	cin >> choice2;		cin.ignore(80, '\n');
	return choice2;

}

void createAccount()
{
	cout << "Enter a username: ";
	cin >> username;		cin.ignore(80, '\n');
	cout << "Enter a password: ";
	cin >> password;		cin.ignore(80, '\n');
	cout << "Enter amount you want to deposit";
	cin >> userBalance;		cin.ignore(80, '\n');
	while (userBalance <= 20)
		cout << "You have to deposit $20 or more.";

	ofstream outFile;
	outFile.open(username + ".txt");
	outFile << username << endl << password << endl << userBalance;
	outFile.close();

	cout << "Thanks for becoming a customer of Bank of Magnus!\n";
}


bool isLogged(int status)
{
	string username, password, un, pw;

	cout << "Enter Username: ";
	cin >> username;		cin.ignore(80, '\n');
	cout << "Enter Pincode: ";
	cin >> password;		cin.ignore(80, '\n');

	ifstream read(username + ".txt");
	getline(read, un);
	getline(read, pw);

	if (un == username && pw == password) {
		return true;
	}
	else {
		return false;
	}
}

void displayBalance()
{
	ifstream inFile;
	inFile.open ("Magnus.txt");
	if (!inFile)
		cout << "Error Opening File";

	string username;
	int actBalance;

	inFile >> username >> password >> userBalance;
	cout << "Getting Balance from\n";
	cout << "Your Balance is : $" << userBalance << endl;
	userBalance = newBalance;
	inFile.close();

}

void withdraw()
{

	double withdraw;

	ifstream inFile;
	inFile.open("Magnus.txt");
	if (!inFile)
		cout << "Error Opening File";
	string username;
	int actBalance;
	inFile >> username >> password >> userBalance;

	cout << "***WITHDRAW***\n"
		<<"You can take out maxiumum " << userBalance << endl
		<< "How much do you want to withdraw: $";
	cin >> withdraw;		cin.ignore(80, '\n');
	while (withdraw > userBalance) {
		cout << "You can't withdraw that much money"
			<< "Enter new amount: ";
		cin >> withdraw;		cin.ignore(80, '\n');
	}
	userBalance = userBalance - withdraw;
	ofstream outFile;
	outFile.open(username + ".txt");
	outFile << username << endl << password << endl << userBalance;
	cout << "Your current balance is $" << userBalance << " remaning";
	outFile.close();
}

void deposit()
{

	double deposit;

	ifstream inFile;
	inFile.open("Magnus.txt");
	if (!inFile)
		cout << "Error Opening File";
	string username;
	int actBalance;
	inFile >> username >> password >> userBalance;

	cout << "***DEPOSIT***\n"
		<< "You can take out maxiumum " << userBalance << endl
		<< "How much do you want to deposit: $";
	cin >> depositAmount;		cin.ignore(80, '\n');
	while (depositAmount < 20) {
		cout << "You can't depposit less then $20"
			<< "Enter new amount: ";
		cin >> depositAmount;		cin.ignore(80, '\n');
	}
	userBalance = userBalance + depositAmount;
	ofstream outFile;
	outFile.open(username + ".txt");
	outFile << username << endl << password << endl << userBalance;
	cout << "Your current balance is $" << userBalance << " remaning";
	outFile.close();
}

void interest()
{

	double interest, principal, paymentBack;
	double  rate = 5;
	int years;

	cout << "***INTEREST CALCULATOR***\n"
		 << "Our interest rate is 5% " << endl
		 << "For how many years do you want to calculate: \n";
	cin  >> years;		cin.ignore(80, '\n');
	
	cout << "How much money do you want to borrow: $\n";
	cin >> principal;		cin.ignore(80, '\n');
	
	interest = (principal * (rate/100)) * years;
	cout << "The interest is \n" << interest;

	paymentBack = principal + interest;
	cout << "The total amount to be paid back is: $" << paymentBack << endl;

	system("pause");

}

void interestSavings()
{
	double principal, rate, total, userBalance;
	int years;
	double interest = .5;

	ofstream outFile;
	outFile.open(username + ".txt");
	outFile << username << endl << password << endl << userBalance;

	cout << "You currently have $" << userBalance << endl
		<< "How many years do you want to calculate\n";
	cin >> years;

	cout << "Our standard rate at the moment is 5%";
	for (int i = 1; i < years; ++i) {
		userBalance *= interest;
		cout << "The balance after" << years << " is " << i <<
	}
	

}