#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Account;
class AccountOwner;

class Account{
    string id;
    long long balance;
    vector<AccountOwner*> accountOwners;
    public:
    // getter and setter
    string getId() {
        return this->id;
    }
    long long getBalance() {
        return this->balance;
    }
    void setId(string id) {
        this->id = id;
    }
    void setBalance(long long balance) {
        this->balance = balance;
    }
    // constructor
    Account(string id, long long balance) {
        this->setId(id);
        this->setBalance(balance);
    }
    // connect account vs account owner
    void connectAccountOwner(AccountOwner *accountOwner1);
    // display
    void display();

    ~Account() {
        delete this;
    }
};

class AccountOwner{
    string name;
    vector<Account*> accounts;
    public:
    // getter and setter
    string getName() {
        return this->name;
    }
    void setName(string name) {
        this->name = name;
        
    }
    // constructor
    AccountOwner(string name) {
        this->setName(name);
    }
    // connect account owner vs account
    void connectAccount(Account *account1);
    // display
    void display();
    ~AccountOwner() {
        accounts.clear();
    }
};

void Account::connectAccountOwner(AccountOwner *accountOwner1) {
    this->accountOwners.push_back(accountOwner1);
}

void AccountOwner::connectAccount(Account *account1) {
    this->accounts.push_back(account1);
    account1->connectAccountOwner(this);
}

void Account::display() {
    cout << "_______________________________\n";
    cout << "Account ID: " << this->getId() << endl;
    cout << "Balance: " << this->getBalance() << endl;
    cout << "Account Owners: ";
    for (int i = 0; i < this->accountOwners.size(); i++) {
        cout << this->accountOwners[i]->getName() << " ";
    }
    cout << endl;
}

void AccountOwner::display() {
    cout << "_______________________________\n";
    cout << "Account Owner: " << this->getName() << endl;
    cout << "Accounts: ";
    for (int i = 0; i < this->accounts.size(); i++) {
        cout << this->accounts[i]->getId() << " ";
    }
    cout << endl;
}


int main() {
    Account acc1 = Account("1", 1000);
    Account acc2 = Account("2", 2000);
    Account acc3 = Account("3", 3000);

    AccountOwner owner1 = AccountOwner("Owner1");
    AccountOwner owner2 = AccountOwner("Owner2");

    owner1.connectAccount(&acc1);
    owner1.connectAccount(&acc2);
    owner1.connectAccount(&acc3);
    owner2.connectAccount(&acc3);

    acc1.display();
    acc2.display();
    acc3.display();

    owner1.display();
    owner2.display();   
}