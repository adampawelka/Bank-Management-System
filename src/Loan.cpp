#include <include/Loan.h>
#include <cmath>

Loan::Loan(double amount, double netIncome, double monthlyLiabilities, int months)
    : loanAmount(amount), termMonths(months) {
        if (amount <= 0 || months <= 0) {
            throw std::invalid_argument("Invalid loan parameters.\n");
        }
    }

double Loan::getLoanAmount() const { return loanAmount; };
double Loan::getInterestRate() const { return interestRate; };
int Loan::getTermMonths() const { return termMonths; };
double Loan::getMonthlyInstallment() const { return monthlyInstallment; };
std::string Loan::getStartDate() const { return startDate; };

double Loan::calculateRate(double netIncome, double monthlyLiabilities, int termMonths) {
    double baseRate = 5.0;
    if (netIncome < 3000) {
        baseRate += 2.0;
    } else if (netIncome <= 6000) {
        baseRate += 1.0;
    }
    if (monthlyLiabilities > 0.5 * netIncome) {
        baseRate += 1.5;
    } else if (monthlyLiabilities > 0.3 * netIncome) {
        baseRate += 0.5;
    }
    if (termMonths > 60) {
        baseRate += 1.0;
    } else if (termMonths > 180) {
        baseRate += 2.0;
    }
    return baseRate;
}

void Loan::setInterestRate(double netIncome, double monthlyLiabilities) {
    interestRate = calculateRate(netIncome, monthlyLiabilities, termMonths);
}

double Loan::checkCreditScore(double netIncome, double monthlyLiabilities, double monthlyOther, double interestRate, int termMonths) {
    double availableForLoan = netIncome - monthlyLiabilities - monthlyOther;

    double monthlyRate = interestRate / 12.0;

    double maxLoan = availableForLoan * ((pow(1 + monthlyRate, termMonths) - 1) / (monthlyRate * pow(1 + monthlyRate, termMonths)));

    return maxLoan;
}

void Loan::calculateInstallment() {
    double q = 1 + (interestRate / 12.0);
    monthlyInstallment = loanAmount * (std::pow(q, getTermMonths()) * (q - 1)) / (std::pow(q, getTermMonths()) - 1);
}   
