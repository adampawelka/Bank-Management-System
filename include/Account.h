
#pragma once
#include <string>

class Account {
    private:
        std::string accountNumber;
        double balance;
        std::string ownerName;
        std::string password;
    public: 
        Account(const std::string& newOwnerName, const std::string& newPassword);

        std::string getAccountNumber() const;
        double getBalance() const;
        std::string getOwnerName() const;

        void deposit(double amount);
        void withdraw(double amount);

};