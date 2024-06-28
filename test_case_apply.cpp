#include <iostream>
#include <string>

using namespace std;

// Define classes for bank management system

class Account {
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    // Constructor
    Account(string accNum, string accHolder, double initBalance) {
        accountNumber = accNum;
        accountHolderName = accHolder;
        balance = initBalance;
    }

    // Member functions
    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    double getBalance() {
        return balance;
    }

    string getAccountNumber() {
        return accountNumber;
    }

    string getAccountHolderName() {
        return accountHolderName;
    }
};

class Bank {
private:
    Account** accounts;
    int numAccounts;

public:
    // Constructor
    Bank() {
        accounts = nullptr;
        numAccounts = 0;
    }

    // Destructor
    ~Bank() {
        if (accounts != nullptr) {
            for (int i = 0; i < numAccounts; ++i) {
                delete accounts[i];
            }
            delete[] accounts;
        }
    }

    // Member functions
    void addAccount(string accNum, string accHolder, double initBalance) {
        Account** temp = new Account*[numAccounts + 1];
        for (int i = 0; i < numAccounts; ++i) {
            temp[i] = accounts[i];
        }
        temp[numAccounts] = new Account(accNum, accHolder, initBalance); // Initialize the new Account object
        delete[] accounts;
        accounts = temp;
        numAccounts++;
    }

    void deposit(string accNum, double amount) {
        for (int i = 0; i < numAccounts; ++i) {
            if (accounts[i]->getAccountNumber() == accNum) {
                accounts[i]->deposit(amount);
                cout << "Deposit successful!" << endl;
                return;
            }
        }
        cout << "Account not found!" << endl;
    }

    void withdraw(string accNum, double amount) {
        for (int i = 0; i < numAccounts; ++i) {
            if (accounts[i]->getAccountNumber() == accNum) {
                accounts[i]->withdraw(amount);
                cout << "Withdrawal successful!" << endl;
                return;
            }
        }
        cout << "Account not found!" << endl;
    }

    double getBalance(string accNum) {
        for (int i = 0; i < numAccounts; ++i) {
            if (accounts[i]->getAccountNumber() == accNum) {
                return accounts[i]->getBalance();
            }
        }
        cout << "Account not found!" << endl;
        return -1; // Indicate error
    }

    void displayAllAccounts() {
        cout << "All Accounts:" << endl;
        for (int i = 0; i < numAccounts; ++i) {
            cout << "Account Number: " << accounts[i]->getAccountNumber() << ", Holder: " << accounts[i]->getAccountHolderName() << ", Balance: " << accounts[i]->getBalance() << endl;
        }
    }
};

// Main function
int main() {
    Bank bank;

    // Example usage
    bank.addAccount("123456", "John Doe", 1000.0);
    bank.addAccount("654321", "Jane Smith", 2000.0);

    cout << "Initial Balances:" << endl;
    cout << "Account 1: " << bank.getBalance("123456") << endl;
    cout << "Account 2: " << bank.getBalance("654321") << endl;

    bank.deposit("123456", 500.0);
    bank.withdraw("654321", 1000.0);

    cout << "Final Balances:" << endl;
    cout << "Account 1: " << bank.getBalance("123456") << endl;
    cout << "Account 2: " << bank.getBalance("654321") << endl;

    return 0;
}
