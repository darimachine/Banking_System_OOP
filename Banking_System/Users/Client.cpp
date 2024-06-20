#include "Client.h"
using std::cout;
using std::endl;
void Client::help()
{
	std::cout << "Client commands:\n";
	std::cout << "1. check_avl [bank_name] [account_number]: Displays the balance in the account with number [account_number] in the bank with name [bank_name]. If such an account or bank does not exist, an appropriate error message is displayed.\n";
	std::cout << "2. open [bank_name]: Sends a request to the bank to open a new account. The client's name, EGN (personal identification number), and age are automatically included in the request sent to the bank (the user does not enter them manually).\n";
	std::cout << "3. close [bank_name] [account_number]: Sends a request to the bank to close an account. If the data is invalid, an appropriate error message is displayed.\n";
	std::cout << "4. redeem [bank_name] [account_number] [verification_code]: Redeems a check received from a third party through the bank. The money from the check is transferred to the specified account upon validation of the code. If such a check does not exist, an appropriate error message is displayed.\n";
	std::cout << "5. change [new_bank_name] [current_bank_name] [account_number]: Sends a request to the bank to transfer the specified account to another bank.\n";
	std::cout << "6. list [bank_name]: Displays all accounts that the user owns in the bank.\n";
	std::cout << "7. messages: Displays all messages in chronological order.\n";
}
Task* Client::change(const MyString& newBankName, const MyString& currentBankName, unsigned accountID)
{
	
	int index = findbankAccountIndex(currentBankName, accountID);
	if (index == -1)
	{
		throw std::invalid_argument("There is no such BankAccount");
	}
	return new ChangeAccountTaskNoValidated(newBankName, *this, currentBankName, accountID);
}

void Client::list(const MyString& bankName) const
{
	unsigned size = bankAccounts.getSize();
	for (int i = 0; i < size; i++)
	{
		if (bankAccounts[i].getBankName() == bankName) {
			cout << "* " << bankAccounts[i].getID() << endl;
		}
	}
}

void Client::messages() const
{
	unsigned size = msg.getSize();
	for (int i = 0; i < size; i++)
	{
		cout << "[" << i + 1 << "] - " << msg[i]<<endl;
	}
	
}

void Client::addMessage(const MyString& message)
{
	msg.pushBack(message);
}

void Client::addMessage(MyString&& message)
{
	msg.pushBack(std::move(message));
}

int Client::findbankAccountIndex(const MyString& bankName,unsigned accountID) const
{
	unsigned size = bankAccounts.getSize();
	for (int i = 0; i < size; i++)
	{
		if (bankAccounts[i].getID() == accountID && bankAccounts[i].getBankName()==bankName) {
			return i;
		}
	}
	return -1;
}

int Client::findCheckIndex(const MyString& code) const
{
	unsigned size = checks.getSize();
	for (int i = 0; i < size; i++)
	{
		if (checks[i].getCode() == code) {
			return i;
		}
	}
	return -1;
}

Client::Client(const MyString& name, const MyString& egn, unsigned age, const MyString& password)
	:User(name,egn,age,password)
{
}

void Client::addCheck(const Check& check)
{
	checks.pushBack(check);
}

void Client::addCheck(Check&& check)
{
	checks.pushBack(std::move(check));
}

void Client::addBill(const Bill& bill)
{
	bankAccounts.pushBack(bill);
}

void Client::addBill(Bill&& bill)
{
	bankAccounts.pushBack(std::move(bill));
}

void Client::removeBill(const MyString& bankName, unsigned accountID)
{
	unsigned index = findbankAccountIndex(bankName,accountID);
	bankAccounts.popAt(index);
}

const Bill& Client::getBill(int index) const
{
	return bankAccounts[index];
}

Bill& Client::getBill(int index)
{
	return bankAccounts[index];
	
}



void Client::check_avl(const MyString& bankName, unsigned accountNumber) const
{

	int index = findbankAccountIndex(bankName, accountNumber);
	if (index == -1)
	{
		throw std::invalid_argument("There is no such BankAccount");
	}
	cout << bankAccounts[index].getBalance() << "$\n";

}

Task* Client::open(const MyString& bankName)
{
	return new OpenAccountTask(bankName,*this);
}

Task* Client::close(const MyString& bankName, unsigned accountNumber)
{
	int index = findbankAccountIndex(bankName, accountNumber);
	if (index == -1)
	{
		throw std::invalid_argument("There is no such BankAccount");
	}
	return new CloseAccountTask(*this,bankName,accountNumber);
}

void Client::redeem(const MyString& bankName, unsigned accountNumber, const MyString& verificationCode)
{
	int bankIndex = findbankAccountIndex(bankName, accountNumber);
	if (bankIndex == -1)
	{
		throw std::invalid_argument("There is no such BankAccount");
	}
	int checkIndex = findCheckIndex(verificationCode);
	if (checkIndex == -1)
	{
		throw std::invalid_argument("There is no such Check with this code");
	}
	bankAccounts[bankIndex].deposit(checks[checkIndex].getCash());
	checks.popAt(checkIndex);

	
}


