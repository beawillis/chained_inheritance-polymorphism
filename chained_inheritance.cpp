#include <iomanip>
#include <iostream>
#include <string>

// The base class contains information and behavior shared by all people.
class Person {
public:
    Person(const std::string& name, int age) : name_(name), age_(age) {}

    const std::string& getName() const {
        return name_;
    }

    int getAge() const {
        return age_;
    }

    void introduce() const {
        std::cout << "Name: " << name_ << '\n'
                  << "Age: " << age_ << '\n';
    }

private:
    std::string name_;
    int age_;
};

// Employee publicly inherits Person and adds employment-specific information.
class Employee : public Person {
public:
    Employee(const std::string& name, int age, const std::string& employeeId,
             double annualSalary)
        : Person(name, age),
          employeeId_(employeeId),
          annualSalary_(annualSalary) {}

    const std::string& getEmployeeId() const {
        return employeeId_;
    }

    double getAnnualSalary() const {
        return annualSalary_;
    }

    void displayEmployeeDetails() const {
        // These inherited members come from Person.
        introduce();
        std::cout << "Employee ID: " << employeeId_ << '\n'
                  << "Annual salary: $" << std::fixed << std::setprecision(2)
                  << annualSalary_ << '\n';
    }

private:
    std::string employeeId_;
    double annualSalary_;
};

// Manager inherits both Person's and Employee's public behavior and data access.
class Manager : public Employee {
public:
    Manager(const std::string& name, int age, const std::string& employeeId,
            double annualSalary, const std::string& department, int teamSize)
        : Employee(name, age, employeeId, annualSalary),
          department_(department),
          teamSize_(teamSize) {}

    void displayManagerDetails() const {
        // This inherited method displays the Person and Employee details too.
        displayEmployeeDetails();
        std::cout << "Department: " << department_ << '\n'
                  << "Team size: " << teamSize_ << '\n';
    }

    void leadTeam() const {
        // getName() is inherited through Employee from Person.
        std::cout << getName() << " is leading the " << department_
                  << " team of " << teamSize_ << " people.\n";
    }

private:
    std::string department_;
    int teamSize_;
};

int main() {
    const Employee employee("Maya Chen", 29, "E104", 72000.00);
    const Manager manager("Jordan Lee", 41, "M201", 105000.00,
                          "Engineering", 8);

    std::cout << "=== Chained Inheritance: Workplace Roles ===\n";
    std::cout << "Employee details:\n";
    employee.displayEmployeeDetails();

    std::cout << "\nManager details:\n";
    manager.displayManagerDetails();
    manager.leadTeam();

    return 0;
}