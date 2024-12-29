#include "include/Account.h"
#include <random>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <iomanip>

std::string generateAccountNumber() {
    srand(time(0));

    std::ostringstream oss;
    for (int i = 0; i < 26; ++i) {
        if (i > 0 && i % 4 == 0) {
            oss << ' ';
        }
        oss << rand() % 10;
    }
    return oss.str();
}

Account::Account(const std::string& newOwnerName, const std::string& newPassword) 
    : accountNumber(generateAccountNumber()), balance(0), ownerName(newOwnerName), password(newPassword) {}

//getters
std::string Account::getAccountNumber() const { return accountNumber; }
double Account::getBalance() const { return balance; }
std::string Account::getOwnerName() const { return ownerName; }

//operations
void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        std::cout << "Succesfully deposited " << amount << ". New balance: " << getBalance() << std::endl;
    } else {
        throw std::invalid_argument("Deposit amount must be positive.\n");
    }
}
void Account::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        std::cout << "Succesfully withdrawed " << amount << ". New balance: " << getBalance() << std::endl;
    } else if (amount > balance) {
        throw std::invalid_argument("Not enough balance.\n");
    } else {
        throw std::invalid_argument("Withdrawal amount must be positive.\n");
    }
}