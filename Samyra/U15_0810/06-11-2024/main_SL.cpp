#include <iostream>
#include "Employee.h"
#include "Freelancer.h"
#include "Internal.h"

int main() {
    // Create a freelancer
    Freelancer freelancer1(123456789, "João Silva", 160, 25.0, true);
    
    // Create an internal employee
    Internal internal1(987654321, "Maria Santos", 2500.0, 6000.0, "Project Alpha");

    // Display information
    std::cout << "Freelancer: " << freelancer1.getName() << std::endl;
    std::cout << "Tax Number: " << freelancer1.getTaxNumber() << std::endl;
    std::cout << "Monthly Salary: " << freelancer1.calculateSalary() << "€" << std::endl;
    std::cout << "Shift Worker: " << (freelancer1.isShiftWorker() ? "Yes" : "No") << std::endl;

    std::cout << "\nInternal Employee: " << internal1.getName() << std::endl;
    std::cout << "Tax Number: " << internal1.getTaxNumber() << std::endl;
    std::cout << "Monthly Salary (including bonus): " << internal1.calculateSalary() << "€" << std::endl;
    std::cout << "Assigned Project: " << internal1.getProject() << std::endl;

    return 0;
}
