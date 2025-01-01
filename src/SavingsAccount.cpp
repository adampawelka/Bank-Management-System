#include <include/SavingsAccount.h>
#include <stdexcept>
#include <iostream>

SavingsAccount::SavingsAccount(const std::string& newOwnerName, const std::string& newPassword, double newInterestRate) 
    : Account(newOwnerName, newPassword), interestRate(newInterestRate) {
        if (interestRate < 0) {
            throw std::invalid_argument("Interest rate cannot be negative.\n");
        }
    }
double SavingsAccount::getInterestRate() const { return interestRate; }
void SavingsAccount::applyInterest() {
    double newBalance = getBalance() * (1 + getInterestRate());
}
