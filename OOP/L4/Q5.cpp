#include <iostream>
#include <iomanip>
using namespace std;

class Employee
{
    int empID;
    string empName;
    string empDepartment;
    double empSalary;

public:
    Employee()
    {
        empID = 0;
        empName = "";
        empDepartment = "";
        empSalary = 0.0;
    }

    Employee(int id, string name, string department, double salary)
    {
        empID = id;
        empName = name;
        empDepartment = department;
        empSalary = salary;
    }

    void addBonus(double bonusAmount)
    {
        empSalary += bonusAmount;
        cout << "\nBonus has been successfully added.\n";
    }

    bool checkIfManager()
    {
        return empDepartment == "Management";
    }

    void showDetails()
    {
        cout << "\nEmployee ID: " << empID << endl;
        cout << "Name: " << empName << endl;
        cout << "Department: " << empDepartment << endl;
        cout << "Salary: $" << fixed << setprecision(2) << empSalary << endl;
    }
};

int main()
{
    Employee emp1;

    emp1 = Employee(635, "Fadil Faisal", "Management", 1000000.00);
    emp1.addBonus(4000);
    emp1.showDetails();
    cout << "Manager: " << (emp1.checkIfManager() ? "Yes" : "No") << endl;

    return 0;
}
