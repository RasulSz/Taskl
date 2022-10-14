#include <iostream>
using namespace std;

//class : Debtor(debtor - borclu)
//  fields : objectId, name, surname, workAddress, salary, phoneNumber
//  fields : hasLatePayment(bool), liveAddress, debt, Id(static)
//  methods : showDebtor
// 
// 
//class : Bank
//  fields : name, debtors(array)
//  method : showAllDebtors,
//  method : borcu 1000 den yuxari olanlari gostermek
//  method : gecikmesi olanlari gostermek


class Debtor {
private:
	int objectID;
	char* name = nullptr;
	char* surname = nullptr;
	char* workAddress = nullptr;
	int salary;
	char* phonenumber = nullptr;
	char* liveAddress = nullptr;
	bool hasLatePayment = false;
	int debt;
public:
	static int ID;
	Debtor() {
		SetObjectID(ID++);
		SetName("No Name");
		SetSurname("No Surname");
		SetWorkAddress("No Address");
		SetSalary(0);
		SetPhoneNumber("No Number");
		SetLatePayment(false);
		SetLiveAddress("No Address");
		SetDebt(0);
	}
	Debtor(const Debtor& other) {
		SetObjectID(other.objectID);
		SetName(other.name);
		SetSurname(other.surname);
		SetWorkAddress(other.workAddress);
		SetPhoneNumber(other.phonenumber);
		SetSalary(other.salary);
		SetLiveAddress(other.liveAddress);
		SetDebt(other.debt);
		SetLatePayment(other.hasLatePayment);
	}
	Debtor(const char* name, const char* surname, const char* workAddress, int salary, const char* phonenumber, bool hasLatePayment, const char* liveAddress, int debt) {
		SetName(name);
		SetSurname(surname);
		SetWorkAddress(workAddress);
		SetSalary(salary);
		SetPhoneNumber(phonenumber);
		SetLatePayment(hasLatePayment);
		SetLiveAddress(liveAddress);
		SetDebt(debt);
		this->objectID = ID++;
	}
	void SetObjectID(int objid) {
		this->objectID = objid;
	}
	void SetName(const char* namee) {
		delete[] name;
		name = new char[strlen(namee) + 1];
		strcpy_s(name, strlen(namee) + 1, namee);
	}
	void SetSurname(const char* surnamee) {
		delete[]this->surname;
		this->surname = new char[strlen(surnamee) + 1];
		strcpy_s(this->surname, strlen(surnamee) + 1, surnamee);
	}
	void SetWorkAddress(const char* wrkadd) {
		delete[]this->workAddress;
		this->workAddress = new char[strlen(wrkadd) + 1];
		strcpy_s(this->workAddress, strlen(wrkadd) + 1, wrkadd);
	}
	void SetSalary(int sal) {
		this->salary = sal;
	}
	void SetPhoneNumber(const char* num) {
		delete[]this->phonenumber;
		this->phonenumber = new char[strlen(num) + 1];
		strcpy_s(this->phonenumber, strlen(num) + 1, num);
	}
	void SetLatePayment(const bool hasLatePayment) {
		this->hasLatePayment = hasLatePayment;
	}
	void SetLiveAddress(const char* liadd) {
		delete[]this->liveAddress;
		this->liveAddress = new char[strlen(liadd) + 1];
		strcpy_s(this->liveAddress, strlen(liadd) + 1, liadd);
	}
	void SetDebt(int deb) {
		this->debt = deb;
	}
	int GetObjectID() {
		return this->objectID;
	}
	char* GetName() {
		return this->name;
	}
	char* GetSurname() {
		return this->surname;
	}
	char* GetWorkAddress() {
		return this->workAddress;
	}
	int GetSalary() {
		return this->salary;
	}
	char* GetPhoneNumber() {
		return this->phonenumber;
	}
	char* GetLiveAddress() {
		return this->liveAddress;
	}
	bool GetLatePayment() {
		return this->hasLatePayment;
	}
	int GetDebt() {
		return this->debt;
	}
	void ShowDebtor() {
		cout << endl;
		cout << "Debtor's Information" << endl;
		cout << "ID : " << this->objectID << endl;
		cout << "Name : " << this->name << endl;
		cout << "Surname : " << this->surname << endl;
		cout << "Work Address : " << this->workAddress << endl;
		cout << "Salary : " << this->salary << endl;
		cout << "Phone Number : " << this->phonenumber << endl;
		cout << "Live Address : " << this->liveAddress << endl;
		if (hasLatePayment == 1) {
			cout << "Payment Delayed" << endl;
		}
		else {
			cout << "Payment not Delayed" << endl;
		}
		cout << "Debt : " << this->debt << endl;
	}
	~Debtor() {
		delete[]name;
		delete[]surname;
		delete[]workAddress;
		delete[]liveAddress;
		delete[]phonenumber;
	}
};
int Debtor::ID = 1;
class Bank {
	char* bankName;
	Debtor* debtors;
	int count=5;
public:
	Bank(Debtor* debtors, int count, const char* bankName) {
		this->debtors = debtors;
		this->count;
		SetBankName(bankName);
	}
	void SetBankName(const char* bankName) {
		delete[]this->bankName;
		this->bankName = new char[strlen(bankName) + 1]{};
		strcpy_s(this->bankName, strlen(bankName) + 1, bankName);
	}
	char* GetBankName() {
		return this->bankName;
	}
	void Show() {
		cout << "------>" << this->bankName << "<-------" << endl << endl;
		for (size_t i = 0; i < count; i++)
		{
			if (debtors[i].GetDebt() <= 1000) {
				debtors[i].ShowDebtor();
			}
		}
		for (size_t i = 0; i < count; i++)
		{
			if (debtors[i].GetDebt() > 1000) {
				cout << "Those who owe more than 1000" << endl;
				debtors[i].ShowDebtor();
			}
		}
	}
	~Bank() {
		delete[]debtors;
		delete[]bankName;
	}
};
void main() {

	Debtor* debtors = new Debtor[3]{
		 Debtor("Rasul", "Sabziyev", "I dont Know", 900, "+994555888074", false, "Baku", 100),
		Debtor("Nizami", "Allahverdiyev", "Any Company", 1200, "+994503454545", true, "Baku", 567),
		Debtor("Yura", "Sadigov", "Any Menagement", 1434, "+994555678901", true, "Baku", 200)
	};
	Bank a(debtors, 3, "LeoBank");
	a.Show();

}