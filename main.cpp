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
    double totalPurchasedAmount;
    string password;
    newUser *nextUser;
    newUser *previousUser;

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
        this->totalPurchasedAmount = 0.0;
        this->nextUser = NULL;
        this->previousUser = NULL;
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
int regionSelector();
void adminPage();
void adminUserList();
void adminDisplayUser();
int adminUserButton(newUser *&temp, int count);
void adminEditUser(newUser *&temp);
void displayUser1(newUser *&temp, int count);
void displayUser2(newUser *&temp, int count);
void displayUser3(newUser *temp, int count);
void displayUser4(newUser *temp, int count);
void adminDisplayUser2(newUser *temp);
void deleteAUser();

int main()
{
    opeaningInterFace();
}
void commonStart()
{
    cout << "===================================================\n";
    cout << "||                MiHoYo Daily Goods             ||\n";
    cout << "||            Buy Online Save Your Time          ||\n";
    cout << "===================================================\n";
}
void opeaningInterFace()
{
    string choice;
    cout << "===================================================\n";
    cout << "||                MiHoYo Daily Goods             ||\n";
    cout << "||            Buy Online Save Your Time          ||\n";
    cout << "===================================================\n";
    cout << "||              1. Admin login                   ||\n";
    cout << "||              2. User login                    ||\n";
    cout << "||              3. Create a user account         ||\n";
    cout << "===================================================\n";
    cout << "       Enter your choice: ";
    cin >> choice;
    if (choice == "1")
    {
        SetConsoleTextAttribute(color, 91);
        cout << "Loading..";
        for (int i = 0; i < 3; i++)
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
    else
    {
        system("cls");
        opeaningInterFace();
    }
}
void adminLogin()
{
    string userName;
    string password;
    cout << "===================================================\n";
    cout << "||                MiHoYo Daily Goods             ||\n";
    cout << "||            Buy Online Save Your Time          ||\n";
    cout << "===================================================\n";
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
    cout << endl;

    admin adminAccount;
    if (adminAccount.checkForAdmin(userName, password))
    {
        SetConsoleTextAttribute(color, 91);
        cout << "Loading...";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        system("cls");
        adminPage();
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
            SetConsoleTextAttribute(color, 91);
            cout << "Loading...";
            for (int i = 0; i < 5; i++)
            {
                cout << ".";
                Sleep(200);
            }
            SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            system("cls");
            opeaningInterFace();
        }
        else
        {
            SetConsoleTextAttribute(color, 91);
            cout << "Loading...";
            for (int i = 0; i < 5; i++)
            {
                cout << ".";
                Sleep(200);
            }
            SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            system("cls");
            SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            adminLogin();
        }
    }
}
void createUser()
{
    SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    string fullName, userName, region, mobileNumber, email, password;

    commonStart();
    cout << "Enter your full name: ";
    cin.ignore();
    getline(cin, fullName);
    SetConsoleTextAttribute(color, 91);
    cout << "Saving info...";
    for (int i = 0; i < 5; i++)
    {
        cout << ".";
        Sleep(200);
    }
    SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    system("cls");

    while (true)
    {
        commonStart();
        userName = "";
        cout << "Enter user name(must be unique): ";
        while (true)
        {
            char ch;
            ch = _getch();
            if (ch == 13)
                break;
            else if (ch == 8)
            {
                if (userName.length() > 0)
                {
                    userName.pop_back();
                    cout << "\b \b";
                }
            }
            else if ((97 <= ch && ch <= 122) || (ch == 95) || (48 <= ch && ch <= 57))
            {
                userName.push_back(ch);
                cout << ch;
            }
        }
        if (checkUserName(userName))
        {
            cout << endl;
            cout << "user name already exists! press enter to try new one.....";
            cin.get();
            system("cls");
        }
        else
        {
            cout << endl;
            SetConsoleTextAttribute(color, 91);
            cout << "Saving info...";
            for (int i = 0; i < 5; i++)
            {
                cout << ".";
                Sleep(200);
            }
            SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
        }
    }
    system("cls");

    while (true)
    {
        commonStart();
        mobileNumber = "";
        cout << "Enter mobile number (must be unique): +880 ";
        while (true)
        {
            char ch;
            ch = _getch();
            if (mobileNumber.length() == 10 && ch == 13)
            {
                break;
            }
            else if (ch == 8)
            {
                if (mobileNumber.length() > 0)
                {
                    mobileNumber.pop_back();
                    cout << "\b \b";
                }
            }
            else if (48 <= ch && ch <= 57)
            {
                if (mobileNumber.length() < 10)
                {
                    mobileNumber.push_back(ch);
                    cout << ch;
                }
            }
        }

        if (checkUserMobileNumber(mobileNumber))
        {
            cout << endl;
            cout << "Mobile number already exists! Press enter to try new one.....";
            cin.get();
            system("cls");
        }
        else
        {
            cout << endl;
            SetConsoleTextAttribute(color, 91);
            cout << "Saving info...";
            for (int i = 0; i < 5; i++)
            {
                cout << ".";
                Sleep(200);
            }
            SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
        }
    }
    system("cls");

    while (true)
    {
        commonStart();
        cout << "Enter your email (must be unique): ";
        email = "";
        while (true)
        {
            char ch;
            ch = _getch();
            if (ch == 13)
                break;
            else if (ch == 8)
            {
                if (email.length() > 0)
                {
                    email.pop_back();
                    cout << "\b \b";
                }
            }
            else if (ch != ' ')
            {
                email.push_back(ch);
                cout << ch;
            }
        }
        cout << endl;
        if (email.length() >= 10 &&
            (email.substr(email.length() - 10) == "@gmail.com" ||
             email.substr(email.length() - 10) == "@yahoo.com" ||
             email.substr(email.length() - 12) == "@hotmail.com" ||
             email.substr(email.length() - 11) == "@diu.edu.bd"))
        {
            if (checkUserEmail(email))
            {
                cout << "Email already exists! press enter to try new one.....";
                cin.get();
                system("cls");
            }
            else
            {
                SetConsoleTextAttribute(color, 91);
                cout << "Saving info...";
                for (int i = 0; i < 5; i++)
                {
                    cout << ".";
                    Sleep(200);
                }
                SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                break;
            }
        }
        else
        {
            cout << "Invalid email address!! Press enter to try new one......";
            cin.get();
            system("cls");
        }
    }
    system("cls");

    int regionSelect = regionSelector();
    switch (regionSelect)
    {
    case 0:
        region = "Fontaine";
        break;
    case 1:
        region = "Mondstadt";
        break;
    case 2:
        region = "Liyue";
        break;
    case 3:
        region = "Sumeru";
        break;
    case 4:
        region = "Snezhnaya";
        break;
    case 5:
        region = "Inazuma";
        break;
    case 6:
        region = "Natlan";
        break;
    default:
        region = "Invalid";
    }
    SetConsoleTextAttribute(color, 91);
    cout << "Saving info...";
    for (int i = 0; i < 5; i++)
    {
        cout << ".";
        Sleep(200);
    }
    SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    system("cls");

    commonStart();
    cout << "Enter your password: ";
    while (true)
    {
        char ch;
        ch = _getch();
        if (ch == 13) // enter
            break;
        else if (ch == 8) // backspace
        {
            if (password.length() > 0)
            {
                password.pop_back();
                cout << "\b \b";
            }
        }
        else if (ch != ' ')
        {
            password.push_back(ch);
            cout << ch;
            Sleep(190);
            cout << "\b*";
        }
    }
    cout << endl;
    SetConsoleTextAttribute(color, 91);
    cout << "Saving info...";
    for (int i = 0; i < 5; i++)
    {
        cout << ".";
        Sleep(200);
    }
    SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

    system("cls");

    commonStart();
    cout << "Your information: \n";
    cout << "Full Name       : " << fullName << endl;
    cout << "User Name       : " << userName << endl;
    cout << "Cell phone      : +880 " << mobileNumber << endl;
    cout << "Email           : " << email << endl;
    cout << "Region          : " << region << endl;
    cout << "Password        : " << password << endl;
    cout << endl;
    cout << "Type 'cancel' to cancel the form and create a new form OR press enter to confirm......";

    string input;
    getline(cin, input);

    if (input == "exit")
    {
        system("cls");
        opeaningInterFace();
    }
    else if (input == "cancel")
    {
        system("cls");
        createUser();
    }
    else
    {
        SetConsoleTextAttribute(color, 91);
        cout << "Creating user...";
        for (int i = 0; i < 7; i++)
        {
            cout << ".";
            Sleep(200);
        }
        cout << endl;
        SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

        if (head == NULL)
        {
            head = new newUser(fullName, userName, region, mobileNumber, email, password);
            cout << fullName << ", your account has been successfully created\n";
            cout << "Press enter to back to login page....";

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
                opeaningInterFace();
            }
        }
        else
        {
            newUser *newNode = new newUser(fullName, userName, region, mobileNumber, email, password);
            newUser *temp;
            temp = head;
            while (temp->nextUser != NULL)
            {
                temp = temp->nextUser;
            }
            temp->nextUser = newNode;
            newNode->previousUser = temp;
            cout << fullName << ", your account has been successfully created\n";
            SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            cout << "Press enter to back to login page....";

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
                opeaningInterFace();
            }
        }
    }
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

int regionSelector()
{
    SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    int choosen = 0;
    string regions[] = {"Fontaine", "Mondstadt", "Liyue", "Sumeru", "Snezhnaya", "Inazuma", "Natlan"};
    int total = 7;

    while (true)
    {
        system("cls");
        commonStart();
        cout << "Select your region (use w/s for change and enter to confirm): \n\n";
        for (int i = 0; i < total; i++)
        {
            if (i == choosen)
            {
                SetConsoleTextAttribute(color, 10);
                cout << "  > " << regions[i] << " <\n";
                SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
            else
                cout << " " << regions[i] << endl;
        }

        char ch;
        ch = _getch();

        if (ch == 27) // escape key
        {
            break;
        }
        else if (ch == 13)
        {
            return choosen;
        }
        else if (ch == 'w' || ch == 'W')
        {
            if (choosen > 0)
                choosen--;
        }
        else if (ch == 's' || ch == 'S')
        {
            if (choosen < total - 1)
                choosen++;
        }
    }

    return -1;
}
void adminPage()
{
    string choice;
    cout << "===================================================\n";
    cout << "||                MiHoYo Daily Goods             ||\n";
    cout << "||            Buy Online Save Your Time          ||\n";
    cout << "===================================================\n";
    cout << "||               1. User list                    ||\n";
    cout << "||               2. Shop catageory               ||\n";
    cout << "||               3. View orders                  ||\n";
    cout << "||               4. Back to login page           ||\n";
    cout << "===================================================\n";
    cout << "            Enter your choice: ";
    cin >> choice;
    if (choice == "1")
    {
        SetConsoleTextAttribute(color, 91);
        cout << "Loading...";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        system("cls");
        adminUserList();
        cin.ignore();
    }
    else if (choice == "2")
    {
    }
    else if (choice == "3")
    {
    }
    else if (choice == "4")
    {
    }
    else
    {
        system("cls");
        adminPage();
    }
}
void deleteAUser()
{
    if (head == NULL)
    {
        cout << "No user exists!\n";
        cout << "Press enter to continue.....";
        string input;
        cin.get();
        cout << "Loading.....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
        }
        cout << endl;
        system("cls");
        adminUserList();
    }
    string userName;
    newUser *temp = head;
    cout << "===================================================\n";
    cout << "||                MiHoYo Daily Goods             ||\n";
    cout << "||            Buy Online Save Your Time          ||\n";
    cout << "===================================================\n";
    cout << "  Enter username: ";

    while (true)
    {
        char ch;
        ch = _getch();
        if (ch == 13 && userName.length() > 0)
            break;
        else if (ch == 8)
        {
            if (userName.length() > 0)
            {
                userName.pop_back();
                cout << "\b \b";
            }
        }
        else if ((97 <= ch && ch <= 122) || (ch == 95) || (48 <= ch && ch <= 57))
        {
            userName.push_back(ch);
            cout << ch;
        }
    }
    cout << "Searchin username....";
    for (int i = 0; i < 5; i++)
    {
        cout << ".";
        Sleep(200);
    }
    string confirmation;
    bool founded = false;
    while (temp != NULL)
    {
        if (temp->userName == userName)
        {
            system("cls");
            if (temp->nextUser == NULL && temp->previousUser == NULL)
            {
                cout << "===================================================\n";
                cout << "||                    User Details               ||\n";
                cout << "===================================================\n";
                cout << " Full Name       : " << temp->fullName << endl;
                cout << " User Name       : " << temp->userName << endl;
                cout << " Cell phone      : +880 " << temp->mobileNumber << endl;
                cout << " Email           : " << temp->email << endl;
                cout << " Region          : " << temp->region << endl;
                cout << " Password        : " << temp->password << endl;
                cout << " Total purchesed : " << temp->totalPurchasedAmount << " $" << endl;
                cout << "===================================================\n\n";
                cout << " are you sure want to delete this accout? (y/N) ";
                getline(cin, confirmation);
                if (confirmation == "y" || confirmation == "Y")
                {
                    cout << "Deleting account....";
                    for (int i = 0; i < 5; i++)
                    {
                        cout << ".";
                        Sleep(200);
                    }
                    cout << endl;
                    if (head->nextUser == NULL)
                    {
                        delete head;
                        head = NULL;
                    }
                    cout << "User has been successfully deleted\n";
                    cout << "Press enter to continue....";
                    cin.get();
                    cout << "Loading.....";
                    for (int i = 0; i < 5; i++)
                    {
                        cout << ".";
                        Sleep(200);
                    }
                    founded = true;
                    system("cls");
                    adminUserList();
                }
                else
                {
                    cout << "Loading.....";
                    for (int i = 0; i < 5; i++)
                    {
                        cout << ".";
                        Sleep(200);
                    }
                    system("cls");
                    adminUserList();
                }
                break;
            }
            else if (temp->previousUser == NULL)
            {
                cout << "===================================================\n";
                cout << "||                    User Details               ||\n";
                cout << "===================================================\n";
                cout << " Full Name       : " << temp->fullName << endl;
                cout << " User Name       : " << temp->userName << endl;
                cout << " Cell phone      : +880 " << temp->mobileNumber << endl;
                cout << " Email           : " << temp->email << endl;
                cout << " Region          : " << temp->region << endl;
                cout << " Password        : " << temp->password << endl;
                cout << " Total purchesed : " << temp->totalPurchasedAmount << " $" << endl;
                cout << "===================================================\n\n";
                cout << " are you sure want to delete this accout? (y/N) ";
                getline(cin, confirmation);
                if (confirmation == "y" || confirmation == "Y")
                {
                    cout << "Deleting account....";
                    for (int i = 0; i < 5; i++)
                    {
                        cout << ".";
                        Sleep(200);
                    }
                    cout << endl;
                    head = head->nextUser;
                    head->previousUser = NULL;
                    delete temp;
                    cout << "User has been successfully deleted\n";
                    cout << "Press enter to continue.....";
                    string input;
                    cin.get();
                    cout << "Loading.....";
                    for (int i = 0; i < 5; i++)
                    {
                        cout << ".";
                        Sleep(200);
                    }
                    founded = true;
                    system("cls");
                    adminUserList();
                }
                else
                {
                    cout << "Loading.....";
                    for (int i = 0; i < 5; i++)
                    {
                        cout << ".";
                        Sleep(200);
                    }
                    system("cls");
                    adminUserList();
                }
                break;
            }
            else if (temp->nextUser == NULL)
            {
                cout << "===================================================\n";
                cout << "||                    User Details               ||\n";
                cout << "===================================================\n";
                cout << " Full Name       : " << temp->fullName << endl;
                cout << " User Name       : " << temp->userName << endl;
                cout << " Cell phone      : +880 " << temp->mobileNumber << endl;
                cout << " Email           : " << temp->email << endl;
                cout << " Region          : " << temp->region << endl;
                cout << " Password        : " << temp->password << endl;
                cout << " Total purchesed : " << temp->totalPurchasedAmount << " $" << endl;
                cout << "===================================================\n\n";
                cout << " are you sure want to delete this accout? (y/N) ";
                getline(cin, confirmation);
                if (confirmation == "y" || confirmation == "Y")
                {
                    cout << "Deleting account....";
                    for (int i = 0; i < 5; i++)
                    {
                        cout << ".";
                        Sleep(200);
                    }
                    cout << endl;
                    newUser *previous;
                    previous = temp->previousUser;
                    previous->nextUser = NULL;
                    temp->previousUser = NULL;
                    delete temp;

                    cout << "User has been successfully deleted\n";
                    cout << "Press enter to continue.....";
                    string input;
                    cin.get();
                    cout << "Loading.....";
                    for (int i = 0; i < 5; i++)
                    {
                        cout << ".";
                        Sleep(200);
                    }
                    founded = true;
                    system("cls");
                    adminUserList();
                }
                else
                {
                    cout << "Loading.....";
                    for (int i = 0; i < 5; i++)
                    {
                        cout << ".";
                        Sleep(200);
                    }
                    system("cls");
                    adminUserList();
                }
                break;
            }
            else
            {
                cout << "===================================================\n";
                cout << "||                    User Details               ||\n";
                cout << "===================================================\n";
                cout << " Full Name       : " << temp->fullName << endl;
                cout << " User Name       : " << temp->userName << endl;
                cout << " Cell phone      : +880 " << temp->mobileNumber << endl;
                cout << " Email           : " << temp->email << endl;
                cout << " Region          : " << temp->region << endl;
                cout << " Password        : " << temp->password << endl;
                cout << " Total purchesed : " << temp->totalPurchasedAmount << " $" << endl;
                cout << "===================================================\n\n";
                cout << " are you sure want to delete this accout? (y/N) ";
                getline(cin, confirmation);
                if (confirmation == "y" || confirmation == "Y")
                {
                    cout << "Deleting account....";
                    for (int i = 0; i < 5; i++)
                    {
                        cout << ".";
                        Sleep(200);
                    }

                    newUser *previous = temp->previousUser;
                    newUser *next = temp->nextUser;

                    previous->nextUser = next;
                    temp->previousUser = NULL;

                    next->previousUser = previous;
                    temp->nextUser = NULL;

                    cout << "User has been successfully deleted\n";
                    cout << "Press enter to continue.....";
                    string input;
                    cin.get();
                    cout << "Loading.....";
                    for (int i = 0; i < 5; i++)
                    {
                        cout << ".";
                        Sleep(200);
                    }
                    founded = true;
                    system("cls");
                    adminUserList();
                }
                else
                {
                    cout << "Loading.....";
                    for (int i = 0; i < 5; i++)
                    {
                        cout << ".";
                        Sleep(200);
                    }
                    system("cls");
                    adminUserList();
                }

                break;
            }
        }
        temp = temp->nextUser;
    }
    if (founded == false)
    {
        cout << endl;
        cout << "username not found\n";
        cout << "Press enter to continue....";
        cin.get();
        cout << "Loading.....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        system("cls");
        deleteAUser();
    }
}
void adminUserList()
{
    SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    system("cls");
    string choice;
    cout << "===================================================\n";
    cout << "||                MiHoYo Daily Goods             ||\n";
    cout << "||            Buy Online Save Your Time          ||\n";
    cout << "===================================================\n";
    cout << "||              1. Display users                 ||\n";
    cout << "||              2. Display by region             ||\n";
    cout << "||              3. Delete user                   ||\n";
    cout << "||              4. Edit user                     ||\n";
    cout << "||              5. Back to login page            ||\n";
    cout << "===================================================\n";
    cout << "              Enter your choice: ";
    cin >> choice;
    cin.ignore();
    if (choice == "1")
    {
        cout << "Loading...";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        system("cls");
        adminDisplayUser();
    }
    // TODO     Have to configure   asdfffffffffffffffffffffffffffffffffffffffffffffffffffffffff
    else if (choice == "2")
    {
    }

    else if (choice == "3")
    {
        cout << "Loading...";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        system("cls");
        deleteAUser();
    }
    else if (choice == "4")
    {
        cout << "Loading....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        system("cls");
        if (head == NULL)
        {
            cout << "No user exists!\n";
            cout << "Press enter to continue.....";
            string input;
            cin.get();
            cout << "Loading.....";
            for (int i = 0; i < 5; i++)
            {
                cout << ".";
            }
            cout << endl;
            system("cls");
            adminUserList();
        }

        string userName;
        newUser *temp = head;
        cout << "===================================================\n";
        cout << "||                MiHoYo Daily Goods             ||\n";
        cout << "||            Buy Online Save Your Time          ||\n";
        cout << "===================================================\n";
        cout << "  Enter username: ";
        while (true)
        {
            char ch;
            ch = _getch();
            if (ch == 13 && userName.length() > 0)
                break;
            else if (ch == 8)
            {
                if (userName.length() > 0)
                {
                    userName.pop_back();
                    cout << "\b \b";
                }
            }
            else if ((97 <= ch && ch <= 122) || (ch == 95) || (48 <= ch && ch <= 57))
            {
                userName.push_back(ch);
                cout << ch;
            }
        }
        cout << "Searchin username....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        bool founded = false;
        while (temp != NULL)
        {
            if (temp->userName == userName)
            {
                string confirmation;
                system("cls");
                cout << "===================================================\n";
                cout << "||                    User Details               ||\n";
                cout << "===================================================\n";
                cout << " Full Name       : " << temp->fullName << endl;
                cout << " User Name       : " << temp->userName << endl;
                cout << " Cell phone      : +880 " << temp->mobileNumber << endl;
                cout << " Email           : " << temp->email << endl;
                cout << " Region          : " << temp->region << endl;
                cout << " Password        : " << temp->password << endl;
                cout << " Total purchesed : " << temp->totalPurchasedAmount << " $" << endl;
                cout << "===================================================\n\n";
                cout << " are you sure want to edit this accout? (y/N) ";
                getline(cin, confirmation);
                if (confirmation == "y" || confirmation == "Y")
                {
                    cout << endl;
                    cout << "Loading....";
                    for (int i = 0; i < 5; i++)
                    {
                        cout << ".";
                    }
                    founded = true;
                    system("cls");
                    adminEditUser(temp);
                }
            }
            temp = temp->nextUser;
        }
        if (founded == false)
        {
            cout << "username doesn't exists!";
            cout << endl;
            cout << "Loading....";
            for (int i = 0; i < 5; i++)
            {
                cout << ".";
            }
            system("cls");
            adminUserList();
        }
    }
    else if (choice == "5")
    {
        cout << endl;
        cout << "Loading.....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        cout << endl;
        system("cls");
        opeaningInterFace();
    }
    else
    {
        system("cls");
        adminUserList();
    }
}
void adminDisplayUser2(newUser *temp)
{
    int count = 1;

    if (temp->previousUser == NULL && temp->nextUser == NULL)
    {
        displayUser1(temp, count);
    }
    else if (temp->previousUser == NULL)
    {
        count++;
        displayUser2(temp, count);
    }
    else if (temp->nextUser == NULL)
    {
        displayUser3(temp, count);
    }
    else
    {
        displayUser4(temp, count);
    }
}
void adminDisplayUser()
{
    SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    newUser *temp;
    temp = head;
    if (head == NULL)
    {
        cout << "No users found\n";
    }
    else
    {
        adminDisplayUser2(temp);
    }

    string input;
    cout << "Type 'exit' to go back to login page. Press enter to back to user list page.....";
    getline(cin, input);
    if (input == "exit")
    {
        SetConsoleTextAttribute(color, 91);
        cout << "Loading...";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        system("cls");
        opeaningInterFace();
    }
    else
    {
        SetConsoleTextAttribute(color, 91);
        cout << "Loading...";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        system("cls");
        adminUserList();
    }
}
int adminUserButton(newUser *&temp, int count)
{
    if (temp->previousUser == NULL && temp->nextUser == NULL)
    {
        int choosen = 0;
        string buttons[] = {"delete", "edit", "exit"};
        int total = 3;
        while (true)
        {
            system("cls");
            cout << "===================================================\n";
            cout << "||                MiHoYo Daily Goods             ||\n";
            cout << "||            Buy Online Save Your Time          ||\n";
            cout << "===================================================\n";
            cout << " Full Name       : " << temp->fullName << endl;
            cout << " User Name       : " << temp->userName << endl;
            cout << " Cell phone      : +880 " << temp->mobileNumber << endl;
            cout << " Email           : " << temp->email << endl;
            cout << " Region          : " << temp->region << endl;
            cout << " Password        : " << temp->password << endl;
            cout << " Total purchesed : " << temp->totalPurchasedAmount << " $" << endl;
            cout << "====================================================\n\n";
            cout << "               ";
            for (int i = 0; i < total; i++)
            {
                if (i == choosen)
                {
                    SetConsoleTextAttribute(color, 10);
                    cout << "  > " << buttons[i] << " <     ";
                    SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
                else
                    cout << " " << buttons[i] << "     ";
            }
            cout << "               ";
            char ch;
            ch = _getch();
            if (ch == 27)
            {
                break;
            }
            else if (ch == 13)
            {
                return choosen;
            }
            else if (ch == 'a' || ch == 'A')
            {
                if (choosen > 0)
                    choosen--;
            }
            else if (ch == 'd' || ch == 'D')
            {
                if (choosen < total - 1)
                    choosen++;
            }
        }
        return -1;
    }
    else if (temp->previousUser == NULL)
    {
        int choosen = 0;
        string buttons[] = {"delete", "edit", "next", "exit"};
        int total = 4;
        while (true)
        {
            system("cls");
            cout << "===================================================\n";
            cout << "||                MiHoYo Daily Goods             ||\n";
            cout << "||            Buy Online Save Your Time          ||\n";
            cout << "===================================================\n";
            cout << " Full Name       : " << temp->fullName << endl;
            cout << " User Name       : " << temp->userName << endl;
            cout << " Cell phone      : +880 " << temp->mobileNumber << endl;
            cout << " Email           : " << temp->email << endl;
            cout << " Region          : " << temp->region << endl;
            cout << " Password        : " << temp->password << endl;
            cout << " Total purchesed : " << temp->totalPurchasedAmount << " $" << endl;
            cout << "====================================================\n\n";
            cout << "               ";
            for (int i = 0; i < total; i++)
            {
                if (i == choosen)
                {
                    SetConsoleTextAttribute(color, 10);
                    cout << "  > " << buttons[i] << " <     ";
                    SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
                else
                    cout << " " << buttons[i] << "     ";
            }
            char ch;
            ch = _getch();
            if (ch == 27)
            {
                break;
            }
            else if (ch == 13)
            {
                return choosen;
            }
            else if (ch == 'a' || ch == 'A')
            {
                if (choosen > 0)
                    choosen--;
            }
            else if (ch == 'd' || ch == 'D')
            {
                if (choosen < total - 1)
                    choosen++;
            }
        }
        return -1;
    }
    else if (temp->nextUser == NULL)
    {
        int choosen = 0;
        string buttons[] = {"previous", "delete", "edit", "exit"};
        int total = 4;
        while (true)
        {
            system("cls");
            cout << "===================================================\n";
            cout << "||                MiHoYo Daily Goods             ||\n";
            cout << "||            Buy Online Save Your Time          ||\n";
            cout << "===================================================\n";
            cout << " Full Name       : " << temp->fullName << endl;
            cout << " User Name       : " << temp->userName << endl;
            cout << " Cell phone      : +880 " << temp->mobileNumber << endl;
            cout << " Email           : " << temp->email << endl;
            cout << " Region          : " << temp->region << endl;
            cout << " Password        : " << temp->password << endl;
            cout << " Total purchesed : " << temp->totalPurchasedAmount << " $" << endl;
            cout << "====================================================\n\n";
            cout << " ";
            for (int i = 0; i < total; i++)
            {
                if (i == choosen)
                {
                    SetConsoleTextAttribute(color, 10);
                    cout << "  > " << buttons[i] << " <     ";
                    SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
                else
                    cout << " " << buttons[i] << "     ";
            }
            cout << "               ";
            char ch;
            ch = _getch();
            if (ch == 27)
            {
                break;
            }
            else if (ch == 13)
            {
                return choosen;
            }
            else if (ch == 'a' || ch == 'A')
            {
                if (choosen > 0)
                    choosen--;
            }
            else if (ch == 'd' || ch == 'D')
            {
                if (choosen < total - 1)
                    choosen++;
            }
        }
        return -1;
    }
    else
    {
        int choosen = 0;
        string buttons[] = {"previous", "delete", "edit", "next", "exit"};
        int total = 5;
        while (true)
        {
            system("cls");
            cout << "===================================================\n";
            cout << "||                MiHoYo Daily Goods             ||\n";
            cout << "||            Buy Online Save Your Time          ||\n";
            cout << "===================================================\n";
            cout << " Full Name       : " << temp->fullName << endl;
            cout << " User Name       : " << temp->userName << endl;
            cout << " Cell phone      : +880 " << temp->mobileNumber << endl;
            cout << " Email           : " << temp->email << endl;
            cout << " Region          : " << temp->region << endl;
            cout << " Password        : " << temp->password << endl;
            cout << " Total purchesed : " << temp->totalPurchasedAmount << " $" << endl;
            cout << "====================================================\n\n";
            for (int i = 0; i < total; i++)
            {
                if (i == choosen)
                {
                    SetConsoleTextAttribute(color, 10);
                    cout << "  > " << buttons[i] << " <     ";
                    SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                }
                else
                    cout << " " << buttons[i] << "     ";
            }
            char ch;
            ch = _getch();
            if (ch == 27)
            {
                break;
            }
            else if (ch == 13)
            {
                return choosen;
            }
            else if (ch == 'a' || ch == 'A')
            {
                if (choosen > 0)
                    choosen--;
            }
            else if (ch == 'd' || ch == 'D')
            {
                if (choosen < total - 1)
                    choosen++;
            }
        }
        return -1;
    }
}
void adminEditUser(newUser *&temp)
{
    string fullName = temp->fullName,
           userName = temp->userName,
           cellPhone = temp->mobileNumber,
           email = temp->email,
           region = temp->region,
           password = temp->password;
    cout << "===================================================\n";
    cout << "||                MiHoYo Daily Goods             ||\n";
    cout << "||            Buy Online Save Your Time          ||\n";
    cout << "===================================================\n";
    cout << "  Full Name: " << fullName;
    while (true)
    {
        char ch;
        ch = _getch();
        if (ch == 13)
            break;
        else if (ch == 8)
        {
            if (fullName.length() > 0)
            {
                fullName.pop_back();
                cout << "\b \b";
            }
        }
        else
        {
            fullName.push_back(ch);
            cout << ch;
        }
    }
    cout << endl;
    SetConsoleTextAttribute(color, 91);
    cout << "Saving info...";
    for (int i = 0; i < 5; i++)
    {
        cout << ".";
        Sleep(200);
    }
    SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << endl;
    system("cls");

    while (true)
    {
        cout << "===================================================\n";
        cout << "||                MiHoYo Daily Goods             ||\n";
        cout << "||            Buy Online Save Your Time          ||\n";
        cout << "===================================================\n";
        userName = temp->userName;
        cout << " User Name: " << userName;
        while (true)
        {
            char ch;
            ch = _getch();
            if (ch == 13)
                break;
            else if (ch == 8)
            {
                if (userName.length() > 0)
                {
                    userName.pop_back();
                    cout << "\b \b";
                }
            }
            else if ((97 <= ch && ch <= 122) || (ch == 95) || (48 <= ch && ch <= 57))
            {
                userName.push_back(ch);
                cout << ch;
            }
        }
        if (checkUserName(userName) && userName != temp->userName)
        {
            cout << endl;
            cout << "user name already exists! press enter to try new one.....";
            cin.get();
            system("cls");
        }
        else
        {
            cout << endl;
            SetConsoleTextAttribute(color, 91);
            cout << "Saving info...";
            for (int i = 0; i < 5; i++)
            {
                cout << ".";
                Sleep(200);
            }
            SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
        }
    }
    system("cls");

    while (true)
    {
        cout << "===================================================\n";
        cout << "||                MiHoYo Daily Goods             ||\n";
        cout << "||            Buy Online Save Your Time          ||\n";
        cout << "===================================================\n";
        cellPhone = temp->mobileNumber;
        cout << "  Cell phone: +880 " << cellPhone;
        while (true)
        {
            char ch;
            ch = _getch();
            if (cellPhone.length() == 10 && ch == 13)
            {
                break;
            }
            else if (ch == 8)
            {
                if (cellPhone.length() > 0)
                {
                    cellPhone.pop_back();
                    cout << "\b \b";
                }
            }
            else if (48 <= ch && ch <= 57)
            {
                if (cellPhone.length() < 10)
                {
                    cellPhone.push_back(ch);
                    cout << ch;
                }
            }
        }

        if (checkUserMobileNumber(cellPhone) && cellPhone != temp->mobileNumber)
        {
            cout << endl;
            cout << "Mobile number already exists! Press enter to try new one.....";
            cin.get();
            system("cls");
        }
        else
        {
            cout << endl;
            SetConsoleTextAttribute(color, 91);
            cout << "Saving info...";
            for (int i = 0; i < 5; i++)
            {
                cout << ".";
                Sleep(200);
            }
            SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
        }
    }
    system("cls");

    while (true)
    {
        email = temp->email;
        cout << "===================================================\n";
        cout << "||                MiHoYo Daily Goods             ||\n";
        cout << "||            Buy Online Save Your Time          ||\n";
        cout << "===================================================\n";
        cout << "  Email: " << email;
        while (true)
        {
            char ch;
            ch = _getch();
            if (ch == 13)
                break;
            else if (ch == 8)
            {
                if (email.length() > 0)
                {
                    email.pop_back();
                    cout << "\b \b";
                }
            }
            else if (ch != ' ')
            {
                email.push_back(ch);
                cout << ch;
            }
        }
        cout << endl;
        if (email.length() >= 10 &&
            (email.substr(email.length() - 10) == "@gmail.com" ||
             email.substr(email.length() - 10) == "@yahoo.com" ||
             email.substr(email.length() - 12) == "@hotmail.com" ||
             email.substr(email.length() - 11) == "@diu.edu.bd"))
        {
            if (checkUserEmail(email) && email != temp->email)
            {
                cout << "Email already exists! press enter to try new one.....";
                cin.get();
                system("cls");
            }
            else
            {
                SetConsoleTextAttribute(color, 91);
                cout << "Saving info...";
                for (int i = 0; i < 5; i++)
                {
                    cout << ".";
                    Sleep(200);
                }
                SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                break;
            }
        }
        else
        {
            cout << "Invalid email address!! Press enter to try new one......";
            cin.get();
            system("cls");
        }
    }
    system("cls");

    int regionSelect = regionSelector();
    switch (regionSelect)
    {
    case 0:
        region = "Fontaine";
        break;
    case 1:
        region = "Mondstadt";
        break;
    case 2:
        region = "Liyue";
        break;
    case 3:
        region = "Sumeru";
        break;
    case 4:
        region = "Snezhnaya";
        break;
    case 5:
        region = "Inazuma";
        break;
    case 6:
        region = "Natlan";
        break;
    default:
        region = "Invalid";
    }
    SetConsoleTextAttribute(color, 91);
    cout << "Saving info...";
    for (int i = 0; i < 5; i++)
    {
        cout << ".";
        Sleep(200);
    }
    SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    system("cls");

    cout << "  Password: " << password;
    while (true)
    {
        char ch;
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
        else if (ch != ' ')
        {
            password.push_back(ch);
            cout << ch;
        }
    }
    cout << endl;
    system("cls");
    cout << "====================================================\n";
    cout << "||                  Updated User                  ||" << endl;
    cout << "====================================================\n";
    cout << " Full Name       : " << fullName << endl;
    cout << " User Name       : " << userName << endl;
    cout << " Cell phone      : +880 " << cellPhone << endl;
    cout << " Email           : " << email << endl;
    cout << " Region          : " << region << endl;
    cout << " Password        : " << password << endl;
    cout << "====================================================\n\n";
    cout << "Type 'cancel' to cancel the changes. Or press enter to confirm.....";
    string input;
    getline(cin, input);
    if (input == "cancel")
    {
        cout << "Cancelling....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        cout << endl;
        return;
    }
    else
    {
        cout << "Updating user....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        cout << endl;
        temp->fullName = fullName;
        temp->userName = userName;
        temp->mobileNumber = cellPhone;
        temp->email = email;
        temp->region = region;
        temp->password = password;
        cout << "User has been updated.." << endl;
        cout << "Press enter to continue....";
        cin.get();
        cout << "Loading....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        system("cls");
        return;
    }
}
void displayUser1(newUser *&temp, int count) // w3hen just 1 user (pre==NULL && next==NULL)
{

    int buttonSelected = adminUserButton(temp, count);
    switch (buttonSelected)
    {
    case 1:
        cout << endl;
        cout << "Loading.....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
        }
        system("cls");
        adminEditUser(temp);
        displayUser1(temp, count);
        break;
    case 2:
        cout << endl;
        cout << "Loading....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        cout << ".";
        adminUserList();
        break;
    case 0:
        string confirmation;
        cout << endl;
        cout << "are you sure want to delete this accout? (y/N) ";
        getline(cin, confirmation);
        if (confirmation == "y" || confirmation == "Y")
        {
            cout << "Deleting account....";
            for (int i = 0; i < 5; i++)
            {
                cout << ".";
                Sleep(200);
            }
            cout << endl;
            if (head->nextUser == NULL)
            {
                delete head;
                head = NULL;
            }
            cout << "User has been successfully deleted\n";
        }
        break;
    }
}

void displayUser2(newUser *&temp, int count) // previousUser==NULL
{
    int buttonSelected = adminUserButton(temp, count);
    string confirmation;
    switch (buttonSelected)
    {
    case 0:
        cout << endl;
        cout << "are you sure want to delete this accout? (y/N) ";
        getline(cin, confirmation);
        if (confirmation == "y" || confirmation == "Y")
        {
            cout << "Deleting account....";
            for (int i = 0; i < 5; i++)
            {
                cout << ".";
                Sleep(200);
            }
            cout << endl;
            head = head->nextUser;
            head->previousUser = NULL;
            delete temp;
            cout << "User has been successfully deleted\n";

            cout << "Press enter to continue.....";
            string input;
            cin.get();
            temp = head;
        }
        break;
    case 1:
        cout << endl;
        cout << "Loading.....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
        }
        system("cls");
        adminEditUser(temp);
        break;
    case 2:
        cout << endl;
        cout << "Loading.....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
        }
        temp = temp->nextUser;
        system("cls");
        adminDisplayUser2(temp);
        break;
    case 3:
        cout << endl;
        cout << "Loading....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        cout << ".";
        adminUserList();
        break;
    }
}
void displayUser3(newUser *temp, int count) // nextUser==NULL
{
    int buttonSelected = adminUserButton(temp, count);
    string confirmation;
    switch (buttonSelected)
    {
    case 0:
        temp = temp->previousUser;
        system("cls");
        adminDisplayUser2(temp);
        break;
    case 1:
        cout << endl;
        cout << "are you sure want to delete this accout? (y/N) ";
        getline(cin, confirmation);
        if (confirmation == "y" || confirmation == "Y")
        {
            cout << "Deleting account....";
            for (int i = 0; i < 5; i++)
            {
                cout << ".";
                Sleep(200);
            }
            cout << endl;
            newUser *previous;
            previous = temp->previousUser;
            previous->nextUser = NULL;
            temp->previousUser = NULL;
            delete temp;

            cout << "User has been successfully deleted\n";
            cout << "Press enter to continue.....";
            string input;
            cin.get();
        }
        break;

    case 2:
        cout << endl;
        cout << "Loading.....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
        }
        system("cls");
        adminEditUser(temp);
        break;

    case 3:
        cout << endl;
        cout << "Loading....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        cout << ".";
        adminUserList();
        break;
    }
}
void displayUser4(newUser *temp, int count)
{
    int buttonSelected = adminUserButton(temp, count);
    string confirmation;
    switch (buttonSelected)
    {
    case 0:
        temp = temp->previousUser;
        system("cls");
        adminDisplayUser2(temp);
        break;
        break;
    case 1:
        cout << endl;
        cout << "are you sure want to delete this accout? (y/N) ";
        getline(cin, confirmation);
        if (confirmation == "y" || confirmation == "Y")
        {
            cout << "Deleting account....";
            for (int i = 0; i < 5; i++)
            {
                cout << ".";
                Sleep(200);
            }

            newUser *previous = temp->previousUser;
            newUser *next = temp->nextUser;

            previous->nextUser = next;
            temp->previousUser = NULL;

            next->previousUser = previous;
            temp->nextUser = NULL;

            cout << "User has been successfully deleted\n";
            cout << "Press enter to continue.....";
            string input;
            cin.get();
        }
        break;
    case 2:
        cout << endl;
        cout << "Loading.....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
        }
        system("cls");
        adminEditUser(temp);
        break;
    case 3:
        cout << endl;
        cout << "Loading.....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
        }
        temp = temp->nextUser;
        system("cls");
        adminDisplayUser2(temp);

        break;
    case 4:
        cout << endl;
        cout << "Loading....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        cout << ".";
        adminUserList();
        break;
    }
}