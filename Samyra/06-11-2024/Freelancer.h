#ifndef FREELANCER_H
#define FREELANCER_H

#include "Employee.h"

class Freelancer : public Employee {
private:
    int hoursWorked;
    double hourlyRate;
    bool shiftWork;

public:
    Freelancer(int tax, std::string n, int hours, double rate, bool shift)
        : Employee(tax, n), hoursWorked(hours), hourlyRate(rate), shiftWork(shift) {}

    double calculateSalary() const override {
        return hoursWorked * hourlyRate;
    }

    bool isShiftWorker() const { return shiftWork; }
};

#endif
