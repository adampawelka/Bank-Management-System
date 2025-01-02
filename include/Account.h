
#pragma once
#include <string>

class Account {
    protected:
        std::string accountNumber;
        double balance;
        std::string ownerName;
        std::string password;
        
        void passwordValidation(const std::string& password) const;

    public: 
        Account(const std::string& newOwnerName, const std::string& newPassword);

        std::string getAccountNumber() const;
        double getBalance() const;
        std::string getOwnerName() const;

        void deposit(double amount);
        void withdraw(double amount);
        bool login(std::string password);
        void transfer(double amount, std::string destinationAccountNumber);

};