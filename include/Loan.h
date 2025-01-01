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
        double checkCreditScore(double netIncome, double monthlyLiabilities, double monthlyOther, double interestRate, int termMonths);
        void setInterestRate(double netIncome, double monthlyLiabilities);
        double calculateRate(double netIncome, double monthlyLiabilities, int termMonths);


        //getters
        double getLoanAmount() const;
        double getInterestRate() const;
        int getTermMonths() const;
        double getMonthlyInstallment() const;
        std::string getStartDate() const;

};