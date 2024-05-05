#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Account;
class Bank;

// make class Account
class Account {
    string id;
    string name;
    Bank* bank = NULL;
    public:
    // getter va setter
    string getId() {
        return this->id;
    }
    string getName() {
        return this->name;
    }
    void setId(string id) {
        this->id = id;
    }
    void setName(string name) {
        this->name = name;
    }
    // constructor
    Account(string id, string name) {
        this->setId(id);
        this->setName(name);
    }
    // ket noi account vs bank
    void connectBank(Bank *bank1);
    // disconnect account vs bank
    void disconnectBank();
    // display
    void display();
};
// make class Bank
class Bank {
    string name;
    string address;
    vector<Account*> accounts;
    public:
    // getter va setter
    string getName() {
        return this->name;
    }
    string getAddress() {
        return this->address;
    }
    void setName(string name) {
        this->name = name;
    }
    void setAddress(string address) {
        this->address = address;
    }
    // constructor
    Bank(string name, string address) {
        this->setName(name);
        this->setAddress(address);
    }
    // ket noi bank vs account
    void connectAccount(Account *acc);
    // disconnect bank vs account
    void disconnectAccount(Account *acc);
    // display
    void display();
};

// write disconnectAccount function
void Bank::disconnectAccount(Account *acc) {
    for (int i = 0; i < this->accounts.size(); i++) {
        if (this->accounts[i] == acc) {
            this->accounts.erase(this->accounts.begin() + i);
            break;
        }
    }
}

void Account::display() {
    cout << "Account id: " << this->id << endl;
    cout << "Account name: " << this->name << endl;
    cout << "Bank name: " << this->bank->getName() << endl;
}

void Account::connectBank(Bank *bank1) {
    this->bank = bank1;
}

void Bank::connectAccount(Account *acc) {
    this->accounts.push_back(acc);
    acc->connectBank(this);
}

// write disconnect bank vs account function
void Account::disconnectBank() {
    this->bank->disconnectAccount(this);
    this->bank = NULL;
}

void Bank::display() {
    cout << "Bank name: " << this->name << endl;
    cout << "Bank address: " << this->address << endl;
    cout << "List of accounts: " << endl;
    for (auto acc : this->accounts) {
        acc->display();
    }
}

int main() {
    Bank bank1 = Bank("Vietcombank", "Hanoi");
    
    Account a = Account("123", "Nguyen Van A");
    Account b = Account("124", "Nguyen Van B");

    bank1.connectAccount(&a);
    bank1.connectAccount(&b);
    bank1.display();
    return 0;
}