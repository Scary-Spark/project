#include <iostream>
#include <windows.h>
#include <cstdlib>
using namespace std;
class admin
{
private:
    string adminUserName = "mihoyo";
    string adminPassword = "genshin2024";

public:
    bool checkForAdmin(string adminUserName, string adminPassword)
    {
        if (this->adminUserName == adminUserName && this->adminPassword == adminPassword)
            return true;
        else
            return false;
    }
};
void commonStart();
void opeaningInterFace();
void adminLogin();
int main()
{
    opeaningInterFace();
}
void commonStart()
{
    cout << "===========================================\n";
    cout << "||            MiHoYo Daily Goods         ||\n";
    cout << "||           Buy Online Save Time        ||\n";
    cout << "===========================================\n";
}
void opeaningInterFace()
{
    string choice;
    commonStart();
    cout << "||           1. Admin login              ||\n";
    cout << "||           2. User login               ||\n";
    cout << "||           3. Create a user account    ||\n";
    cout << "===========================================\n";
    cout << "       Enter your choice: ";
    cin >> choice;
    if (choice == "1")
    {
        adminLogin();
    }
}
void adminLogin()
{
    string userName;
    string password;
    cout << "===========================================\n";
    cout << "||            MiHoYo Daily Goods         ||\n";
    cout << "||           Buy Online Save Time        ||\n";
    cout << "===========================================\n";
    cout << "Enter user Name: ";
    cin >> userName;
    cout << "Enter password: ";
    cin >> password;

    admin adminAccount;
    if (adminAccount.checkForAdmin(userName, password))
    {
        cout << "Check is successful\n";
    }
    else
    {
        cout << "========================================================\n";
        cout << "||     Login failed! Invalid username or password.    ||\n";
        cout << "========================================================\n";
        cout << endl;
        cout << "Type 'exit' to get back to main login page or press enter to try again....";
        cin.ignore();
        string input;
        getline(cin, input);
        if (input == "exit")
        {
            system("cls");
            opeaningInterFace();
        }
        else
        {
            system("cls");
            adminLogin();
        }
    }
}