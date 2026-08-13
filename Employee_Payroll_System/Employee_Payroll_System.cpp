//by Jalal Gahramanov

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>

#define pb push_back
#define popb pop_back
#define OVERTIME_RATE 20.0

using namespace std;

typedef struct Employee {
    int id;
    string name;
    string department;
    double salary;
    int overtimeHours;
    double bonus;
} emp_t;

int menu();

void addEmployee(vector<emp_t>& employees, const string& filename);
void deleteEmployee(vector<emp_t>& employees, const string& filename);
void updateEmployee(vector<emp_t>& employees, const string& filename);
void searchEmployee(const vector<emp_t>& employees); 
void calculatePayroll(vector<emp_t>& employees);
void displayEmployees(const vector<emp_t>& employees);
void savetofile(const vector<emp_t>& employees, const string& filename);
void loadFromFile(vector<emp_t>& employees, const string& filename);

void bubbleSortById(vector<emp_t>& employees);
int binarySearchById(const vector<emp_t>& employees, int id);

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<emp_t> employees;

    loadFromFile(employees, "database.txt");

    int choice = menu();

    while (choice > 0 && choice <= 7) {

        switch (choice) {

        case 1:
            addEmployee(employees, "database.txt");
            break;

        case 2:
            deleteEmployee(employees, "database.txt");
            break;

        case 3:
            updateEmployee(employees, "database.txt");
            break;

        case 4:
            searchEmployee(employees);
            break;

        case 5:
            calculatePayroll(employees);
            break;

        case 6:
            displayEmployees(employees);
            break;

        case 7:
            bubbleSortById(employees);
            break;
        
        }
        choice = menu();
    }

    return (0);
}

void loadFromFile(vector<emp_t>& employees, const string& filename) {

    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error" << endl;
        return;
    }

    emp_t emp{};

    while (file >> emp.id
        >> quoted(emp.name)
        >> quoted(emp.department)
        >> emp.salary
        >> emp.overtimeHours
        >> emp.bonus) {

        employees.pb(emp);
    }

    file.close();
}

void savetofile(const vector<emp_t>& employees, const string& filename) {

    ofstream file(filename);

    if (!file.is_open()) {
        cout << "Error" << endl;
        return;
    }

    for (const emp_t& emp : employees) {
        file << emp.id << " " << quoted(emp.name) << " " << quoted(emp.department) << " " << emp.salary << " " << emp.overtimeHours << " " << emp.bonus << endl;
    }

    file.close();
}

int menu() {

    int choice;

    cout << "===== Employee Management System =====\n";
    cout << "1. Add Employee\n";
    cout << "2. Delete Employee\n";
    cout << "3. Update Employee\n";
    cout << "4. Search Employee\n";
    cout << "5. Calculate Payroll\n";
    cout << "6. Display Employees\n";
    cout << "7. Sort Employees by ID\n";
    cout << "0. Exit\n";
    cout << "======================================\n\n";

    do {

        cout << "Enter your choice: ";

        cin >> choice;

    } while (!(choice >= 0 && choice <= 7));

	return (choice);
}

void addEmployee(vector<emp_t>& employees, const string& filename) {

    emp_t emp{};

    cout << endl;

    cout << "Enter employee ID: ";
    cin >> emp.id;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter employee name: ";
    getline(cin, emp.name);

    cout << "Enter department: ";
    getline(cin, emp.department);

    cout << "Enter salary: ";
    cin >> emp.salary;

    cout << "Enter overtime hours: ";
    cin >> emp.overtimeHours;

    cout << "Enter bonus: ";
    cin >> emp.bonus;

    employees.pb(emp);

    cout << "Employee added successfully!\n";
    cout << endl;

    savetofile(employees, filename);
}

void deleteEmployee(vector<emp_t>& employees, const string& filename) {

    int id;

	cout << endl;

    cout << "Enter employee ID to delete: ";
    cin >> id;

    for (auto i = employees.begin(); i != employees.end(); i++) {

        if (i->id == id) {

            employees.erase(i);

            cout << "Employee deleted successfully!\n\n";

            savetofile(employees, filename);

            return;
        }
    }

    cout << "Employee not found!\n\n";
}

void updateEmployee(vector<emp_t>& employees, const string& filename) {

    int id;

    cout << endl;

    cout << "Enter employee ID to update: ";
    cin >> id;

    for (emp_t& emp : employees) {

        if (emp.id == id) {

            cout << "\nCurrent Employee Data:\n";
            cout << "ID: " << emp.id << endl;
            cout << "Name: " << emp.name << endl;
            cout << "Department: " << emp.department << endl;
            cout << "Salary: " << emp.salary << endl;
            cout << "Overtime Hours: " << emp.overtimeHours << endl;
            cout << "Bonus: " << emp.bonus << endl;

            cout << "\nEnter New Employee Data:\n";

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter new employee name: ";
            getline(cin, emp.name);

            cout << "Enter new department: ";
            getline(cin, emp.department);

            cout << "Enter new salary: ";
            cin >> emp.salary;

            cout << "Enter new overtime hours: ";
            cin >> emp.overtimeHours;

            cout << "Enter new bonus: ";
            cin >> emp.bonus;

            savetofile(employees, filename);

            cout << "\nEmployee updated successfully!\n";
            cout << endl;

            return;
        }
    }

    cout << "Employee not found!\n";
    cout << endl;
}

void searchEmployee(const vector<emp_t>& employees) {
    int id;
    cout << endl;
    cout << "Enter employee ID to search: ";
    cin >> id;

    vector<emp_t> sortedEmployees = employees;

    bubbleSortById(sortedEmployees);

    int idx = binarySearchById(sortedEmployees, id);

	if (idx != -1) {
		cout << "\nEmployee Data:\n";
		cout << "ID: " << sortedEmployees[idx].id << endl;
		cout << "Name: " << sortedEmployees[idx].name << endl;
		cout << "Department: " << sortedEmployees[idx].department << endl;
		cout << "Salary: " << sortedEmployees[idx].salary << endl;
		cout << "Overtime Hours: " << sortedEmployees[idx].overtimeHours << endl;
		cout << "Bonus: " << sortedEmployees[idx].bonus << endl;
		cout << endl;
		return;
	}

    cout << "Employee not found!\n";
    cout << endl;

}

void calculatePayroll(vector<emp_t>& employees) {

    int id;

    cout << endl;

    cout << "Enter employee ID: ";
    cin >> id;

    for (const emp_t& emp : employees) {

        if (emp.id == id) {

            double overtimePay = emp.overtimeHours * OVERTIME_RATE;
            double totalPayroll = emp.salary + overtimePay + emp.bonus;

            cout << "\n===== Payroll Information =====\n";
            cout << "Employee: " << emp.name << endl;
            cout << "Department: " << emp.department << endl;
            cout << "Base Salary: " << emp.salary << endl;
            cout << "Overtime Hours: " << emp.overtimeHours << endl;
            cout << "Overtime Pay: " << overtimePay << endl;
            cout << "Bonus: " << emp.bonus << endl;
            cout << "Total Payroll: " << totalPayroll << endl;
            cout << "===============================\n\n";

            return;
        }
    }

    cout << "Employee not found!\n\n";
}

void displayEmployees(const vector<emp_t>& employees) {

    cout << endl;

    cout << left
        << setw(10) << "ID"
        << setw(25) << "Name"
        << setw(25) << "Department"
        << setw(12) << "Salary"
        << setw(18) << "Overtime Hours"
        << setw(10) << "Bonus"
        << endl;

    cout << string(100, '-') << endl;

    for (const emp_t& emp : employees) {

        cout << left
            << setw(10) << emp.id
            << setw(25) << emp.name
            << setw(25) << emp.department
            << setw(12) << emp.salary
            << setw(18) << emp.overtimeHours
            << setw(10) << emp.bonus
            << endl;
    }

    cout << endl;
}

void bubbleSortById(vector<emp_t>& employees) {

    int n = employees.size();

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            if (employees[j].id > employees[j + 1].id) {

                emp_t temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }
}

int binarySearchById(const vector<emp_t>& employees, int id) {

    int left = 0;
    int right = employees.size() - 1;

    while (left <= right) {

        int middle = left + (right - left) / 2;

        if (employees[middle].id == id) {
            return (middle);
        }

        else if (employees[middle].id < id) {
            left = middle + 1;
        }

        else {
            right = middle - 1;
        }

    }

    return (-1);
}