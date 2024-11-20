#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
protected:
    int taxNumber;
    std::string name;

public:
    Employee(int tax, std::string n) : taxNumber(tax), name(n) {}
    virtual ~Employee() {}

    int getTaxNumber() const { return taxNumber; }
    std::string getName() const { return name; }
    
    // Pure virtual function to make Employee an abstract class
    virtual double calculateSalary() const = 0;
};

#endif
