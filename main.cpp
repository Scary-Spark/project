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
class newUser
{
public:
    string userName;
    string fullName;
    string mobileNumber;
    string email;
    string region;
    string password;
    newUser *nextUser;

    newUser(string fullName,
            string userName,
            string region,
            string mobileNumber,
            string email,
            string password)
    {
        this->fullName = fullName;
        this->userName = userName;
        this->region = region;
        this->mobileNumber = mobileNumber;
        this->email = email;
        this->password = password;
        this->nextUser = NULL;
    }
};
newUser *head = NULL;
void commonStart();
void opeaningInterFace();
void adminLogin();
void createUser();
bool checkUserName(string userName);
bool checkUserMobileNumber(string mobileNumber);
bool checkUserEmail(string email);
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
    else if (choice == "2")
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
    }
    else if (choice == "3")
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
        createUser();
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
void createUser()
{
    string fullName, userName, region, mobileNumber, email, password;

    commonStart();
    cout << "Enter your full name: ";
    cin.ignore();
    getline(cin, fullName);
    system("cls");

    commonStart();
    while (true)
    {
        cout << "Enter user name(must be unique): ";
        cin >> userName;
        cin.ignore();
        if (checkUserName(userName))
        {
            cout << "user name already exists! press enter to try new one...\n";
            cin.ignore();
            cin.get();
        }
        else
        {
            break;
        }
    }
    system("cls");

    commonStart();
    while (true)
    {
        cout << "Enter mobile number (must be unique): ";
        cin >> mobileNumber;
        cin.ignore();
        if (checkUserMobileNumber(mobileNumber))
        {
            cout << "Mobile number already exists! press enter to try new one...\n";
            cin.ignore();
            cin.get();
        }
        else
        {
            break;
        }
    }
    system("cls");

    commonStart();
    while (true)
    {
        cout << "Enter your email (must be unique): ";
        cin >> email;
        cin.ignore();
        if (checkUserEmail(email))
        {
            cout << "Email already exists! press enter to try new one...\n";
            cin.ignore();
            cin.get();
        }
        else
            break;
    }
    system("cls");
}

bool checkUserName(string userName)
{
    if (head != NULL)
    {
        newUser *temp = head;
        while (temp != NULL)
        {
            if (temp->userName == userName)
                return true;
            temp = temp->nextUser;
        }
        return false;
    }
}

bool checkUserMobileNumber(string mobileNumber)
{
    if (head != NULL)
    {
        newUser *temp = head;
        while (temp != NULL)
        {
            if (temp->mobileNumber == mobileNumber)
                return true;
            temp = temp->nextUser;
        }
        return false;
    }
}
bool checkUserEmail(string email)
{
    if (head != NULL)
    {
        newUser *temp = head;
        while (temp != NULL)
        {
            if (temp->email == email)
                return true;
            temp = temp->nextUser;
        }
        return false;
    }
}