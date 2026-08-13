# Employee Management System

A simple **C++ Employee Management System** that allows users to manage employee records, calculate payroll, search employees, and store data in a text file.

## Features

* Add new employees
* Delete employees by ID
* Update employee information
* Search employees by ID
* Calculate employee payroll
* Display all employees in a formatted table
* Sort employees by ID using **Bubble Sort**
* Search sorted employee records using **Binary Search**
* Save employee data to a file
* Load employee data automatically when the program starts

## Technologies Used

* C++
* STL `vector`
* File Handling (`fstream`)
* `iomanip`
* Bubble Sort
* Binary Search

## Employee Information

Each employee contains the following information:

* Employee ID
* Name
* Department
* Salary
* Overtime Hours
* Bonus

## Payroll Calculation

Employee payroll is calculated using:

```text
Overtime Pay = Overtime Hours × 20
Total Payroll = Salary + Overtime Pay + Bonus
```

The overtime rate is defined as:

```cpp
#define OVERTIME_RATE 20.0
```

## Menu

When the program starts, the following menu is displayed:

```text
===== Employee Management System =====
1. Add Employee
2. Delete Employee
3. Update Employee
4. Search Employee
5. Calculate Payroll
6. Display Employees
7. Sort Employees by ID
0. Exit
======================================
```

## Data Storage

Employee information is stored in:

```text
database.txt
```

Example data:

```text
1001 "Jalal Gahramanov" "CTIS" 1200 10 90
1002 "Khayyam Gahramanli" "Stomatologiya" 9000 10 80
```

The format is:

```text
ID "Name" "Department" Salary OvertimeHours Bonus
```

Quotation marks are used so employee names and department names can contain spaces.

## Searching

The program uses **Binary Search** to search for employees by ID.

Before performing the binary search, a copy of the employee vector is sorted using **Bubble Sort**.

```text
Employees
    ↓
Bubble Sort by ID
    ↓
Binary Search
    ↓
Employee Found / Not Found
```

## File Structure

```text
EmployeeManagementSystem/
│
├── main.cpp
├── database.txt
└── README.md
```

## How to Run

### Visual Studio

1. Open the project in **Visual Studio**.
2. Make sure `database.txt` is located in the correct project working directory.
3. Build the project.
4. Run using:

```text
Ctrl + F5
```

### Using a C++ Compiler

Compile:

```bash
g++ main.cpp -o EmployeeManagementSystem
```

Run on Windows:

```bash
EmployeeManagementSystem.exe
```

Run on Linux/macOS:

```bash
./EmployeeManagementSystem
```

A compiler supporting **C++14 or newer** is recommended because the program uses `std::quoted`.

## Example Employee Table

```text
ID        Name                     Department               Salary      Overtime Hours    Bonus
----------------------------------------------------------------------------------------------------
1001      Jalal Gahramanov         CTIS                     1200        10                90
1002      Khayyam Gahramanli       Stomatologiya            9000        10                80
```

## Author

**Jalal Gahramanov**
