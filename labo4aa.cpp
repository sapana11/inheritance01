//Sapana Chhetri
//19th October 2023
//A program to write a class that represents a manager in a company

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

// Defining the Employee class by not making any change

class Employee {
public:
    Employee(const string& empName, double empWage, double empHours)
        : name(empName), wage(empWage), hours(empHours) {}

    double calcPay() const
    {
        return wage * hours;
    }

    const string& getName() const
    {
        return name;
    }

protected:
    string name;
    double wage;
    double hours;
};

// Defining the Manager class that inherits from Employee
class Manager : public Employee {
public:
    Manager(const string& empName, double empWage,
             double empHours, double empBonus)
        : Employee(empName, empWage, empHours), bonus(empBonus) {}

    double calcPay() const;

private:
    double bonus;
};

// Implementation of calcPay for the Manager class
double Manager::calcPay() const
{
    return Employee::calcPay() + bonus;
}

int main()
{
    int numManagers;
    cout << "Enter number of managers:  ";
    cin >> numManagers;

    vector<Manager> managers;

    for (int i= 0;i <numManagers; ++i)
      {
        string empName;
        double empWage, empHours, empBonus;

// Input manager details
      cout << "\n" << "Enter manager " << i << " name: ";
      cin.ignore();
      getline(cin, empName);

      cout << "Enter manager " << i <<  " hourly wage: ";
      cin >> empWage;

      cout << "Enter manager " << i <<  " hours worked: ";
      cin >> empHours;

      cout << "Enter manager " << i <<  " bonus: ";
      cin >> empBonus;

// Creating a Manager object and add it to the vector

     managers.emplace_back(empName, empWage, empHours, empBonus);
    }

    double highestEarning = 0.0;
    double totalEarnings = 0.0;
    string highestEarnerName;

// Calculate the highest earning manager and total earnings

    for (const Manager& manager : managers)
      {
        totalEarnings += manager.calcPay();

        if (manager.calcPay() > highestEarning) {
            highestEarning = manager.calcPay();
            highestEarnerName = manager.getName();
        }
    }

    double averageEarnings = totalEarnings / numManagers;

// Display the results in the desired format

  cout << endl <<  "Highest paid manager is " << highestEarnerName
  << " who is paid $" << fixed << setprecision(2) << highestEarning;
  cout << endl << "Average pay is $" << fixed << setprecision(2) << averageEarnings;

    return 0;
}

