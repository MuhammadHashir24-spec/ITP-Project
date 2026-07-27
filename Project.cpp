#include <iostream>
#include <fstream>
using namespace std;
struct Finance
{
    int id;
    char name[50];
    double salary;
};
// Function to search employee by ID
void searchEmployee(Finance emp[], int n)
{
    int searchId;
    cout << "\nEnter ID to search: ";
    cin >> searchId;
    for (int i = 0; i < n; i++)
    {
        if (emp[i].id == searchId)
        {
            cout << "\nEmployee Found!\n";
            cout << "ID: " << emp[i].id << endl;
            cout << "Name: " << emp[i].name << endl;
            cout << "Salary: " << emp[i].salary << endl;
            return;
        }
    }
    cout << "\nEmployee not found.\n";
}
int main()
{
    int n;
    Finance emp[100];
    cout << "Enter number of finance employees: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details of employee " << i + 1 << endl;

        cout << "Enter ID: ";
        cin >> emp[i].id;
        cin.ignore();

        cout << "Enter Name: ";
        cin.getline(emp[i].name, 50);

        cout << "Enter Salary: ";
        cin >> emp[i].salary;
    }
    cout << "\nEmployee List:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "ID: " << emp[i].id << endl;
        cout << "Name: " << emp[i].name << endl;
        cout << "Salary: " << emp[i].salary << endl << endl;
    }
    // Call search function
    searchEmployee(emp, n);
    // Save in file
    ofstream file("Finance.txt");
    for (int i = 0; i < n; i++)
    {
        file << "ID: " << emp[i].id << endl;
        file << "Name: " << emp[i].name << endl;
        file << "Salary: " << emp[i].salary << endl << endl;
    }
    file.close();
    cout << "Data saved in Finance.txt";
    return 0;
}
