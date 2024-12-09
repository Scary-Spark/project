#include <bits/stdc++.h>
#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <unistd.h>
#include <conio.h>
#include <sstream>
#include <limits>
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

class item
{
public:
    string name;
    double inStock;
    double price;
    double minPurchaseAmount;
    item *nextItem;
    item *previousItem;
    item(string name, double inStock, double price, double minPuchaseAmount)

    {
        this->name = name;
        this->inStock = inStock;
        this->price = price;
        this->minPurchaseAmount = minPuchaseAmount;
        this->nextItem = NULL;
        this->previousItem = NULL;
    }
};
class catagory
{
public:
    string name;
    item *itemHead;
    item *itemTail;
    catagory *previousCat;
    catagory *nextCat;
    catagory(string name)
    {
        this->name = name;
        this->itemHead = NULL;
        this->itemTail = NULL;
        this->nextCat = NULL;
        this->previousCat = NULL;
    }
    void addItem(string itemName, double stock, double price, double minAmount)
    {
        item *newItem = new item(itemName, stock, price, minAmount);
        item *tempItem = itemHead;

        if (itemHead == NULL)
        {
            itemHead = newItem;
        }
        else
        {
            while (tempItem->nextItem != NULL)
            {
                tempItem = tempItem->nextItem;
            }
            tempItem->nextItem = newItem;
            newItem->previousItem = tempItem;
        }
    }
};
catagory *catHead = NULL;

void catagoryCreation();
void addItemToCatagory();
void viewItem();

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
void userLoginInterFace();
bool userLoginCheck(string userName, string password);
void userInterFace(string userName);
void userDetails(newUser *temp);
void shopCatagory();
int shopCatagoryButton();
void displayCatagory();
void removeCatagory();
void userItemView(newUser *temp);
int userItemButtons(item *itemTemp);
void userItemView1(newUser *tempUser, item *itemTemp);
void userItemView2(newUser *tempUser, item *itemTemp);
void userItemView3(newUser *tempUser, item *itemTemp);
void userItemView4(newUser *tempUser, item *itemTemp);
void userItemView5(newUser *tempUser, catagory *temp, item *itemTemp);

void addDefaultCatagory(string catagoryName, string itemName, double inStock, double price, double minAmount);

int main()
{
    addDefaultCatagory("Fresh Market", "Hilsha", 10, 1.2, .5);
    addDefaultCatagory("Fresh Market", "Raw Meat", 15, .99, .5);
    addDefaultCatagory("Fresh Market", "Raw Chicken", 20, .2, .5);
    addDefaultCatagory("Fresh Market", "Raw Beef", 20, .7, .5);

    opeaningInterFace();
}
void addDefaultCatagory(string catagoryName, string itemName, double inStock, double price, double minAmount)
{
    catagory *temp = catHead;
    bool found = false;
    while (temp != NULL)
    {
        if (temp->name == catagoryName)
        {
            found = true;
            break;
        }
        temp = temp->nextCat;
    }
    if (!found)
    {
        catagory *newCat = new catagory(catagoryName);
        if (catHead == NULL)
        {
            catHead = newCat;
        }
        else
        {
            temp = catHead;
            while (temp->nextCat != NULL)
            {
                temp = temp->nextCat;
            }
            temp->nextCat = newCat;
            newCat->previousCat = temp;
        }
        temp = newCat;
    }

    temp->addItem(itemName, inStock, price, minAmount);
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
        cout << "Loading...";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
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
            Sleep(200);
        }
        SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        system("cls");
        userLoginInterFace();
    }
    else if (choice == "3")
    {
        SetConsoleTextAttribute(color, 91);
        cout << "Loading..";
        for (int i = 0; i < 4; i++)
        {
            cout << ".";
            Sleep(200);
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
    cout << "Enter username: ";
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
    cout << endl;
    cout << "Enter password: ";
    char ch;
    while (true)
    {
        ch = _getch();
        if (ch == 13 && password.length() > 0)
            break;
        else if (ch == 8)
        {
            if (password.length() > 0)
            {
                password.pop_back();
                cout << "\b \b";
            }
        }
        else if (ch != 13)
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
        system("cls");
        cout << "========================================================\n";
        cout << "||     Login failed! Invalid username or password.    ||\n";
        cout << "========================================================\n";
        cout << endl;
        cout << "Type 'exit' to get back to main login page or press enter to try again....";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
    fullName = "";
    cout << "Enter your full name: ";
    while (true)
    {
        char ch;
        ch = _getch();
        if (ch == 13 && fullName.length() > 0)
        {
            break;
        }
        else if (ch == 8)
        {
            if (fullName.length() > 0)
            {
                fullName.pop_back();
                cout << "\b \b";
            }
        }
        else if (ch != 13)
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
    system("cls");

    while (true)
    {
        commonStart();
        userName = "";
        cout << "Enter username(must be unique): ";
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
        if (ch == 13 && password.length() > 0) // enter
            break;
        else if (ch == 8) // backspace
        {
            if (password.length() > 0)
            {
                password.pop_back();
                cout << "\b \b";
            }
        }
        else if (ch != ' ' && ch != 13)
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
    cout << "Type 'cancel' to cancel the form and create a new form OR 'exit' to back to login page or press enter to confirm......";

    string input;
    getline(cin, input);

    if (input == "exit")
    {
        cout << endl;
        cout << "Loading....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }

        system("cls");
        opeaningInterFace();
    }
    else if (input == "cancel")
    {
        cout << endl;
        cout << "Loading....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        system("cls");
        createUser();
    }
    else
    {
        cin.ignore();
        SetConsoleTextAttribute(color, 91);
        cout << "Creating user...";
        for (int i = 0; i < 7; i++)
        {
            cout << ".";
            Sleep(200);
        }
        SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
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
        system("cls");
    }

    return -1;
}
int shopCatagoryButton()
{
    SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    int choosen = 0;

    int total = 0;
    catagory *temp = catHead;
    while (temp != NULL)
    {
        total++;
        temp = temp->nextCat;
    }
    if (total == 0)
    {
        cout << "No catagory found\n";
        cout << "Press enter to continue....";
        cin.ignore();
        cin.get();
        cout << "Loading...";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        system("cls");
        adminPage();
    }
    temp = catHead;
    string buttons[total];
    int index = 0;
    while (temp != NULL)
    {
        buttons[index] = temp->name;
        temp = temp->nextCat;
        index++;
    }

    while (true)
    {
        system("cls");
        string choice;
        cout << "===================================================\n";
        cout << "||                MiHoYo Daily Goods             ||\n";
        cout << "||            Buy Online Save Your Time          ||\n";
        cout << "===================================================\n";
        cout << "  Select catagory (w/s to change): \n";
        for (int i = 0; i < total; i++)
        {
            if (i == choosen)
            {
                SetConsoleTextAttribute(color, 10);
                cout << "  > " << buttons[i] << " <\n";
                SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
            else
                cout << " " << buttons[i] << endl;
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
void displayCatagory()
{
    if (catHead == NULL)
    {
        cout << "No catagory found\n";
        cout << endl;
        cout << "Press enter to go back.....";

        cin.get();
        cout << endl;
        cout << "Laoding....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        system("cls");
        shopCatagory();
    }
    catagory *temp;
    temp = catHead;
    int i = 1;
    while (temp != NULL)
    {
        cout << i << ". " << temp->name;
        i++;
        temp = temp->nextCat;
        cout << endl;
    }
    cout << endl;
    cout << "Press enter to go back.....";

    cin.get();
    cout << "Laoding....";
    for (int i = 0; i < 5; i++)
    {
        cout << ".";
        Sleep(200);
    }
    system("cls");
    shopCatagory();
}
void removeCatagory()
{
    catagory *temp = catHead;
    int selected = shopCatagoryButton();
    int i = 0;
    for (i = 0; i <= selected; i++)
    {

        if (i == selected)
        {
            break;
        }
        temp = temp->nextCat;
    }
    if (temp->nextCat == NULL && temp->previousCat == NULL)
    {
        cout << "Removing catagory...";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        delete temp;
        catHead = NULL;
        cout << endl;
        cout << "Catagory has been removed\n";
        cout << "Press enter to continue....";
        cin.get();
        cout << "Loading....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        system("cls");
        shopCatagory();
    }
    else if (temp->nextCat == NULL)
    {
        catagory *previous;
        cout << "Removing catagory...";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        cout << endl;
        previous = temp->previousCat;
        previous->nextCat = NULL;
        temp->previousCat = NULL;
        delete temp;
        cout << "Catagory has been removed\n";
        cout << "Press enter to continue....";
        cin.get();
        cout << "Loading....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        system("cls");
        shopCatagory();
    }
    else if (temp->previousCat == NULL)
    {
        cout << "Removing catagory...";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        cout << endl;
        catHead = catHead->nextCat;
        catHead->previousCat = NULL;
        temp->nextCat = NULL;
        delete temp;
        cout << "Catagory has been removed\n";
        cout << "Press enter to continue....";
        cin.get();
        cout << "Loading....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        system("cls");
        shopCatagory();
    }
    else
    {
        cout << "Removing catagory...";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        cout << endl;
        catagory *next, *previous;
        next = temp->nextCat;
        previous = temp->previousCat;

        next->previousCat = previous;
        previous->nextCat = next;
        temp->previousCat = NULL;
        temp->nextCat = NULL;

        delete temp;
        cout << "Catagory has been removed\n";
        cout << "Press enter to continue....";
        cin.get();
        cout << "Loading....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        system("cls");
        shopCatagory();
    }
}
void viewItem()
{
    catagory *temp = catHead;
    int selected = shopCatagoryButton();
    int i = 0;
    for (i = 0; i <= selected; i++)
    {

        if (i == selected)
        {
            break;
        }
        temp = temp->nextCat;
    }
    cout << endl
         << "Loading....";
    for (int i = 0; i < 5; i++)
    {
        cout << ".";
        Sleep(200);
    }
    system("cls");

    if (temp->itemHead == NULL)
    {
        cout << "No items found in this category.\n";
        cout << "Press enter to go back.....";
        cin.get();
        cout << "Loading....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        system("cls");
        shopCatagory();
        return;
    }

    item *itemTemp = temp->itemHead;
    int itemIndex = 1;
    while (itemTemp != NULL)
    {
        cout << itemIndex << ". " << itemTemp->name << "\n";
        cout << "   In Stock: " << itemTemp->inStock << "\n";
        cout << "   Price: $" << itemTemp->price << "\n";
        cout << "   Min Purchase: " << itemTemp->minPurchaseAmount << "\n";
        itemIndex++;
        itemTemp = itemTemp->nextItem;
    }

    cout << "\nPress enter to go back.....";
    cin.get();
    cout << "Loading....";
    for (int i = 0; i < 5; i++)
    {
        cout << ".";
        Sleep(200);
    }
    system("cls");
    shopCatagory();
}
void shopCatagory()
{
    string choice;
    cout << "===================================================\n";
    cout << "||                MiHoYo Daily Goods             ||\n";
    cout << "||            Buy Online Save Your Time          ||\n";
    cout << "===================================================\n";
    cout << "||                 1. View Catagory              ||\n";
    cout << "||                 2. Add Catagory               ||\n";
    cout << "||                 3. Remove Catagory            ||\n";
    cout << "||                 4. Add items                  ||\n";
    cout << "||                 5. View Items                 ||\n";
    cout << "||                 6. Exit                       ||\n";
    cout << "===================================================\n";
    cout << "             Enter your choice: ";
    getline(cin, choice);
    if (choice == "1")
    {
        cout << endl;
        cout << "Loading....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        system("cls");
        displayCatagory();
    }
    else if (choice == "2")
    {
        cout << endl;
        cout << "Loading....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        system("cls");
        catagoryCreation();
    }
    else if (choice == "3")
    {
        cout << endl;
        cout << "Loading....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        system("cls");
        removeCatagory();
    }
    else if (choice == "4")
    {
        cout << endl;
        cout << "Loading....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        system("cls");
        addItemToCatagory();
    }
    else if (choice == "5")
    {
        cout << endl;
        cout << "Loading....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        system("cls");
        viewItem();
    }
    else if (choice == "6")
    {
        cout << endl;
        cout << "Loading....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        system("cls");
        adminPage();
    }
    else
    {
        system("cls");
        shopCatagory();
    }
}
void addItemToCatagory()
{
    catagory *temp = catHead;
    int selected = shopCatagoryButton();
    int i = 0;
    for (i = 0; i <= selected; i++)
    {

        if (i == selected)
        {
            break;
        }
        temp = temp->nextCat;
    }
    cout << endl;
    cout << "Loading....";
    for (int i = 0; i < 5; i++)
    {
        cout << ".";
        Sleep(200);
    }
    system("cls");
    string itemName;
    double stock;
    double price;

    string catagoryName = temp->name;
    temp = catHead;
    cout << "===================================================\n";
    cout << "||                MiHoYo Daily Goods             ||\n";
    cout << "||            Buy Online Save Your Time          ||\n";
    cout << "===================================================\n";
    string input;
    while (true)
    {
        cout << "  Enter item name: ";
        getline(cin, itemName);
        if (itemName.length() > 0)
            break;
    }
    while (true)
    {
        cout << "  Enter amount to add: ";
        getline(cin, input);
        istringstream stream(input);
        if (stream >> stock && stock > 0)
            break;
    }
    string input2;
    while (true)
    {
        cout << "  Enter price (per unit): ";
        getline(cin, input2);
        istringstream stream(input2);
        if (stream >> price && price > 0)
            break;
    }
    string input3;
    double minAmount;
    while (true)
    {
        cout << "  Enter minimum quantity/unit that customer can buy: ";
        getline(cin, input);
        istringstream stream(input);
        if (stream >> minAmount && minAmount > 0)
            break;
    }
    cout << "Press enter....";

    cin.get();

    while (temp != NULL)
    {
        if (temp->name == catagoryName)
        {
            temp->addItem(itemName, stock, price, minAmount);
            break;
        }
        temp = temp->nextCat;
    }
    cout << endl;
    cout << "Loading....";
    for (int i = 0; i < 5; i++)
    {
        cout << ".";
        Sleep(200);
    }
    system("cls");
    shopCatagory();
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
        cout << "Loading...";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        system("cls");
        shopCatagory();
    }
    else if (choice == "3")
    {
    }
    else if (choice == "4")
    {
        cout << "Loading...";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        system("cls");
        opeaningInterFace();
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
    cout << endl;
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
        if (ch == 13 && fullName.length() > 0)
        {
            break;
        }
        else if (ch == 8)
        {
            if (fullName.length() > 0)
            {
                fullName.pop_back();
                cout << "\b \b";
            }
        }
        else if (ch != 13)
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
        cout << " Username: " << userName;
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
        if (ch == 13 && password.length() > 0)
            break;
        else if (ch == 8)
        {
            if (password.length() > 0)
            {
                password.pop_back();
                cout << "\b \b";
            }
        }
        else if (ch != ' ' && ch != 13)
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
        system("cls");
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
void userLoginInterFace()
{
    string userName;
    string password;
    cout << "===================================================\n";
    cout << "||                MiHoYo Daily Goods             ||\n";
    cout << "||            Buy Online Save Your Time          ||\n";
    cout << "===================================================\n";
    cout << "Enter username: ";
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
    cout << endl;
    cout << "Enter password: ";
    char ch;
    while (true)
    {
        ch = _getch();
        if (ch == 13 && password.length() > 0)
            break;
        else if (ch == 8)
        {
            if (password.length() > 0)
            {
                password.pop_back();
                cout << "\b \b";
            }
        }
        else if (ch != 13)
        {
            password.push_back(ch);
            cout << ch;
            Sleep(190);
            cout << "\b*";
        }
    }
    cout << endl
         << endl;

    cout << "Searching for user....";
    for (int i = 0; i < 5; i++)
    {
        cout << ".";
        Sleep(200);
    }
    cout << endl;
    if (userLoginCheck(userName, password))
    {
        cout << endl;
        cout << "User found\n";
        cout << "Trying to login....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        system("cls");
        userInterFace(userName);
    }
    else
    {
        cout << endl;
        cout << "Username or password in incorrect\n";
        cout << "Press enter to continue....";
        cin.ignore();
        cin.get();
        cout << "Loading....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        system("cls");
        opeaningInterFace();
    }
}
bool userLoginCheck(string userName, string password)
{
    newUser *temp = head;
    while (temp != NULL)
    {
        if (temp->userName == userName && temp->password == password)
        {
            return true;
        }
        temp = temp->nextUser;
    }
    return false;
}
int userItemButtons(item *itemTemp)
{

    if (itemTemp->previousItem == NULL && itemTemp->nextItem == NULL)
    {
        int choosen = 0;
        while (true)
        {
            system("cls");
            cout << "===================================================\n";
            cout << "||                MiHoYo Daily Goods             ||\n";
            cout << "||            Buy Online Save Your Time          ||\n";
            cout << "===================================================\n";
            cout << "||          use (a/d) in order to change         ||\n";
            cout << "===================================================\n";
            cout << "   " << itemTemp->name << ": " << endl;
            cout << "       In Stock: " << itemTemp->inStock << endl;
            cout << "       Price (per gm/unit): " << itemTemp->price << endl;
            cout << "       Minminum order (gm/unit): " << itemTemp->minPurchaseAmount << endl;
            string buttons[] = {"order", "exit"};
            int total = 2;
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
    else if (itemTemp->previousItem == NULL)
    {
        int choosen = 0;
        while (true)
        {
            system("cls");
            cout << "===================================================\n";
            cout << "||                MiHoYo Daily Goods             ||\n";
            cout << "||            Buy Online Save Your Time          ||\n";
            cout << "===================================================\n";
            cout << "||          use (a/d) in order to change         ||\n";
            cout << "===================================================\n";
            cout << "   " << itemTemp->name << ": " << endl;
            cout << "       In Stock: " << itemTemp->inStock << endl;
            cout << "       Price (per gm/unit): " << itemTemp->price << endl;
            cout << "       Minminum order (gm/unit): " << itemTemp->minPurchaseAmount << endl;

            string buttons[] = {"order", "next", "exit"};
            int total = 3;
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
    else if (itemTemp->nextItem == NULL)
    {
        int choosen = 0;
        while (true)
        {
            system("cls");
            cout << "===================================================\n";
            cout << "||                MiHoYo Daily Goods             ||\n";
            cout << "||            Buy Online Save Your Time          ||\n";
            cout << "===================================================\n";
            cout << "||          use (a/d) in order to change         ||\n";
            cout << "===================================================\n";
            cout << "   " << itemTemp->name << ": " << endl;
            cout << "       In Stock: " << itemTemp->inStock << endl;
            cout << "       Price (per gm/unit): " << itemTemp->price << endl;
            cout << "       Minminum order (gm/unit): " << itemTemp->minPurchaseAmount << endl;

            string buttons[] = {"previous", "order", "exit"};
            int total = 3;
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
        while (true)
        {
            system("cls");
            cout << "===================================================\n";
            cout << "||                MiHoYo Daily Goods             ||\n";
            cout << "||            Buy Online Save Your Time          ||\n";
            cout << "===================================================\n";
            cout << "||          use (a/d) in order to change         ||\n";
            cout << "===================================================\n";
            cout << "   " << itemTemp->name << ": " << endl;
            cout << "       In Stock: " << itemTemp->inStock << endl;
            cout << "       Price (per gm/unit): $ " << itemTemp->price << endl;
            cout << "       Minminum order (gm/unit): " << itemTemp->minPurchaseAmount << endl;
            cout << "===================================================\n";

            string buttons[] = {"previous", "order", "next", "exit"};
            int total = 4;
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
}
void userItemView1(newUser *tempUser, item *itemTemp, catagory *temp)
{
    int button = userItemButtons(itemTemp);
    cout << endl;
    cout << "Loading....";
    for (int i = 0; i < 5; i++)
    {
        cout << ".";
        Sleep(200);
    }
    cout << endl;
    system("cls");
    if (button == 0)
    {
        // TODO      congigure order ststem qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq
    }
    else if (button == 1)
    {
        userInterFace(tempUser->userName);
    }
}
void userItemView2(newUser *tempUser, item *itemTemp, catagory *temp)
{
    int button = userItemButtons(itemTemp);
    cout << endl;
    cout << "Loading....";
    for (int i = 0; i < 5; i++)
    {
        cout << ".";
        Sleep(200);
    }
    cout << endl;
    system("cls");
    if (button == 0)
    {
        // TODO      congigure order ststem qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq
    }
    else if (button == 1)
    {
        itemTemp = itemTemp->nextItem;
        userItemView5(tempUser, temp, itemTemp);
    }
    else if (button == 2)
    {
        userInterFace(tempUser->userName);
    }
}
void userItemView3(newUser *tempUser, item *itemTemp, catagory *temp)
{
    int button = userItemButtons(itemTemp);
    cout << endl;
    cout << "Loading....";
    for (int i = 0; i < 5; i++)
    {
        cout << ".";
        Sleep(200);
    }
    cout << endl;
    system("cls");
    if (button == 0)
    {
        itemTemp = itemTemp->previousItem;
        userItemView5(tempUser, temp, itemTemp);
    }
    else if (button == 1)
    {
        // TODO      congigure order ststem qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq
    }
    else if (button == 2)
    {
        userInterFace(tempUser->userName);
    }
}
void userItemView4(newUser *tempUser, item *itemTemp, catagory *temp)
{
    int button = userItemButtons(itemTemp);
    cout << endl;
    cout << "Loading....";
    for (int i = 0; i < 5; i++)
    {
        cout << ".";
        Sleep(200);
    }
    cout << endl;
    system("cls");
    if (button == 0)
    {
        itemTemp = itemTemp->previousItem;
        userItemView5(tempUser, temp, itemTemp);
    }
    else if (button == 1)
    {
        // TODO      congigure order ststem qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq
    }
    else if (button == 2)
    {
        itemTemp = itemTemp->nextItem;
        userItemView5(tempUser, temp, itemTemp);
    }
    else if (button == 3)
    {
        userInterFace(tempUser->userName);
    }
}
void userItemView5(newUser *tempUser, catagory *temp, item *itemTemp)
{
    if (temp->itemHead == NULL)
    {
        cout << "No items found in this category.\n";
        cout << "Press enter to go back.....";
        cin.get();
        cout << "Loading....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        system("cls");
        userInterFace(tempUser->userName);
        return;
    }
    if (itemTemp == NULL)
    {
        cout << "No items found in this category.\n";
        cout << "Press enter to go back.....";
        cin.get();
        cout << "Loading....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        system("cls");
        userInterFace(tempUser->userName);
        return;
    }

    if (itemTemp->previousItem == NULL && itemTemp->nextItem == NULL)
    {
        userItemView1(tempUser, itemTemp, temp);
    }

    else if (itemTemp->previousItem == NULL)
    {
        userItemView2(tempUser, itemTemp, temp);
    }

    else if (itemTemp->nextItem == NULL)
    {
        userItemView3(tempUser, itemTemp, temp);
    }
    else
    {
        userItemView4(tempUser, itemTemp, temp);
    }
}
void userItemView(newUser *tempUser)
{
    catagory *temp = catHead;
    if (catHead == NULL)
    {
        cout << "No catagory available.\n";
        cout << "Press enter to go back....";
        cin.get();
        cout << "Loading....\n";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        system("cls");
        userInterFace(tempUser->userName);
    }

    int selected = shopCatagoryButton();

    for (int i = 0; i <= selected; i++)
    {
        if (i == selected)
            break;
        temp = temp->nextCat;
    }
    cout << endl;
    cout << "Loading....";
    for (int i = 0; i < 5; i++)
    {
        cout << ".";
        Sleep(200);
    }
    item *itemTemp = temp->itemHead;
    system("cls");
    userItemView5(tempUser, temp, itemTemp);
}

void userInterFace(string userName)
{
    newUser *temp = head;
    while (temp != NULL)
    {
        if (temp->userName == userName)
        {
            break;
        }
        temp = temp->nextUser;
    }
    cout << "===================================================\n";
    cout << "||                MiHoYo Daily Goods             ||\n";
    cout << "||            Buy Online Save Your Time          ||\n";
    cout << "===================================================\n";
    cout << "||                1. View profile                ||\n";
    cout << "||                2. Edit profile                ||\n";
    cout << "||                3. Enter shop                  ||\n";
    cout << "||                4. View cart                   ||\n";
    cout << "||                5. Back to login page          ||\n";
    cout << "===================================================\n";
    cout << "             Enter your choice: ";
    string input;
    getline(cin, input);
    if (input == "1")
    {
        cout << endl;
        cout << "Loading....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        system("cls");
        userDetails(temp);
    }
    else if (input == "2")
    {
        cout << endl;
        cout << "Loading....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        system("cls");
        adminEditUser(temp);
        userInterFace(userName);
    }
    else if (input == "3")
    {
        cout << endl;
        cout << "Loading....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        system("cls");
        userItemView(temp);
    }
    else if (input == "4")
    {
    }
    else if (input == "5")
    {
        cout << endl;
        cout << "Loading....";
        for (int i = 0; i < 5; i++)
        {
            cout << ".";
            Sleep(200);
        }
        system("cls");
        opeaningInterFace();
    }
    else
    {
        system("cls");
        userInterFace(userName);
    }
}
void userDetails(newUser *temp)
{

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
    cout << " Press enter to go back....";
    cin.get();
    cout << endl;
    cout << "Loading....";
    for (int i = 0; i < 5; i++)
    {
        cout << ".";
        Sleep(200);
    }
    system("cls");
    userInterFace(temp->userName);
}
void catagoryCreation()
{
    string catName;
    cout << "Enter catagory name: ";
    cin >> catName;

    if (catHead == NULL)
    {
        catagory *newNode = new catagory(catName);
        catHead = newNode;
    }
    else
    {
        catagory *newNode = new catagory(catName);
        catagory *temp = catHead;
        while (temp->nextCat != NULL)
        {
            temp = temp->nextCat;
        }
        temp->nextCat = newNode;
        newNode->previousCat = temp;
    }

    cout << endl;
    cout << catName << ", has been created\n";
    cout << "Press enter to continue....";
    cin.ignore();
    cin.get();
    cout << "Loading.....";
    for (int i = 0; i < 5; i++)
    {
        cout << ".";
        Sleep(200);
    }
    system("cls");
    shopCatagory();
}