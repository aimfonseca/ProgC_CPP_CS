#ifndef INTERNAL_H
#define INTERNAL_H

#include "Employee.h"

class Internal : public Employee {
private:
    double baseSalary;
    double annualBonus;
    std::string projectAssignment;

public:
    Internal(int tax, std::string n, double base, double bonus, std::string project)
        : Employee(tax, n), baseSalary(base), annualBonus(bonus), projectAssignment(project) {}

    double calculateSalary() const override {
        return baseSalary + (annualBonus / 12.0); // Monthly salary including bonus portion
    }

    std::string getProject() const { return projectAssignment; }
};

#endif
