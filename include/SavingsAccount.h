#pragma once
#include "Account.h"

class SavingsAccount : public Account {
    private:
        double interestRate;
    public:
        SavingsAccount(const std::string& newOwnerName, const std::string& newPassword, double newInterestRate);

        double getInterestRate() const;

        void applyInterest();

};