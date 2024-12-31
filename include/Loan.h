#include <Account.h>
#include <iostream>
#include <stdexcept>

class Loan {
    private:
        double loanAmount;
        double interestRate;
        int termMonths;
        double monthlyInstallment;
        std::string startDate;
        std::string nextPaymentDate;
    public:
        Loan(double amount, double netIncome, double monthlyLiabilities, int months);
        void calculateInstallment();
        void processPayment();
        bool isPaidOff();
        double checkCreditScore();
        
};