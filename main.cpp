#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <unistd.h>
#include <conio.h>
using namespace std;
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
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
        SetConsoleTextAttribute(color, 91);
        cout << "Loading..";
        for (int i = 0; i < 4; i++)
        {
            cout << ".";
            sleep(1);
        }
        SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        system("cls");
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
    char ch;
    while (true)
    {
        ch = _getch();
        if (ch == 13)
            break;
        else if (ch == 8)
        {
            if (password.length() > 0)
            {
                password.pop_back();
                cout << "\b \b";
            }
        }
        else
        {
            password.push_back(ch);
            cout << ch;
            Sleep(190);
            cout << "\b*";
        }
    }

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