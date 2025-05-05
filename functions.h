#include <iostream>
#include <vector>
#include "class.h"
#include <limits>
#include <conio.h>
#include <string>
using namespace std;

void loggedInMenu();
void rentCarMenu();
void rentBikeMenu();

bool usernameExists(string username)
{
    for (auto &user : users)
        if (user.username == username)
            return true;
    return false;
}

void signUp()
{
    cout << "****************\n";
    cout << "Sign Up\n";
    cout << "****************\n";

    string username, password;

    cout << "Enter username: ";
    cin >> username;
    if (usernameExists(username))
    {
        cout << "Username already exists! Try another one.\n";
        return;
    }
    cout << "Enter password: ";
    password.clear();

    int ch;

    while ((ch = _getch()) != '\r')
    {

        if (ch == '\b')
        {

            if (!password.empty())
            {

                password.pop_back();

                cout << "\b \b";
            }
        }
        else
        {

            password.push_back(static_cast<char>(ch));

            cout << '*';
        }
    }

    cout << endl;
    users.push_back({username, password});
    cout << "Signed up successfully!\n";
}

void login()
{
    if (loggedInUser != nullptr)
    {
        cout << "You are already logged in as " << loggedInUser->username << ".\n";
        return;
    }

    cout << "****************\n";
    cout << "Login\n";
    cout << "****************\n";

    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter password: ";
    password.clear();

    int ch;

    while ((ch = _getch()) != '\r')
    {

        if (ch == '\b')
        {

            if (!password.empty())
            {

                password.pop_back();

                cout << "\b \b";
            }
        }
        else
        {

            password.push_back(static_cast<char>(ch));

            cout << '*';
        }
    }

    cout << endl;

    for (auto &user : users)
    {
        if (user.username == username && user.password == password)
        {
            loggedInUser = &user;
            cout << "Logged in successfully! Welcome, " << username << ".\n";
            loggedInMenu();
            return;
        }
    }
    cout << "Login failed!\n";
}

void logout()
{
    if (loggedInUser == nullptr)
    {
        cout << "No user is currently logged in.\n";
    }
    else
    {
        cout << "User " << loggedInUser->username << " has been logged out.\n";
        loggedInUser = nullptr;
    }
}

void menu()
{
    cout << "\n--- MENU ---\n";
    cout << "1. Sign Up\n";
    cout << "2. Log In\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
}

void appFirstPage()
{
    cout << "Welcome to the vehicle rent application!\n\n";
    int choice;
    bool running = true;

    while (running)
    {
        menu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            signUp();
            break;
        case 2:
            login();
            break;
        case 3:
            cout << "Exiting...\n";
            running = false;
            break;
        default:
            cout << "Invalid choice! Try again.\n";
            break;
        }
    }
}

void loggedInMenu()
{
    int choice;
    bool loggedIn = true;

    while (loggedIn)
    {
        cout << "\n--- Logged In Menu ---\n";
        cout << "1. Show Cars\n";
        cout << "2. Show Bikes\n";
        cout << "3. Log Out\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            rentCarMenu();
            break;
        case 2:
            rentBikeMenu();
            break;
        case 3:
            logout();
            loggedIn = false;
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}

void rentCarMenu() {
    int choice;
    while (true) {
        cout << "\n--- Available Cars ---\n";
        for (int i = 0; i < cars.size(); i++) {
            cout << i + 1 << ". " << cars[i].Brand << " (" << cars[i].carType << ") - "
                 << cars[i].Color << " - $" << cars[i].pricePerDay << "/day\n";
        }
        int goBackOption = cars.size() + 1;
        int addNewOption = cars.size() + 2;
        cout << goBackOption << ". Go Back\n";
        cout << addNewOption << ". Add New Car\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= cars.size()) {
            int days;
            cout << "For how many days do you want to rent the " << cars[choice - 1].Brand << "? ";
            cin >> days;

            while (cin.fail() || days <= 0)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a positive number: ";
                cin >> days;
            }
            float total = days * cars[choice - 1].pricePerDay;

            cout << "\n=========== RENTAL RECEIPT ===========\n";
            cout << "Vehicle: " << cars[choice - 1].Brand << " (" << cars[choice - 1].carType << ")\n";
            cout << "Color  : " << cars[choice - 1].Color << "\n";
            cout << "Speed  : " << cars[choice - 1].maxSpeed << "\n";
            cout << "Days   : " << days << "\n";
            cout << "Rate   : $" << cars[choice - 1].pricePerDay << " per day\n";
            cout << "------------------------------\n";
            cout << "Total  : $" << total << "\n";
            cout << "======================================\n";
            string temp;
            cout << "Press any key to go back to car list...";
            cin >> temp;
        } else if (choice == goBackOption) {
            return;
        } else if (choice == addNewOption) {
            float price;
            string color, brand, type;
            int speed;

            cout << "Enter price per day: ";
            while (!(cin >> price)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Enter a number: ";
            }

            cin.ignore();
            cout << "Enter color: ";
            getline(cin, color);
            cout << "Enter brand: ";
            getline(cin, brand);
            cout << "Enter car type: ";
            getline(cin, type);

            cout << "Enter max speed: ";
            while (!(cin >> speed)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Enter an integer: ";
            }

            cars.push_back(Car(price, color, brand, type, speed));
            cout << "New car added successfully!\n";
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }
}
void rentBikeMenu()
{
    int choice;
    while (true)
    {
        cout << "\n--- Available Bikes ---\n";
        for (int i = 0; i < bikes.size(); i++) {
            cout << i + 1 << ". " << bikes[i].Brand << " (" << bikes[i].Type << ") - "
                 << bikes[i].Color << " - $" << bikes[i].pricePerDay << "/day\n";
        }
        int goBackOption = bikes.size() + 1;
        int addNewOption = bikes.size() + 2;
        cout << goBackOption << ". Go Back\n";
        cout << addNewOption << ". Add New Bike\n";
        cout << "Enter your choice: ";
        cin >> choice;


        if (choice >= 1 && choice <= bikes.size())
        {
            int days;
            cout << "For how many days do you want to rent the " << bikes[choice - 1].Brand << "? ";
            cin >> days;

            while (cin.fail() || days <= 0)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a positive number: ";
                cin >> days;
            }
            float total = days * bikes[choice - 1].pricePerDay;

            cout << "\n=========== RENTAL RECEIPT ===========\n";
            cout << "Vehicle: " << bikes[choice - 1].Brand << " (" << bikes[choice - 1].Type << ")\n";
            cout << "Color  : " << bikes[choice - 1].Color << "\n";
            cout << "Days   : " << days << "\n";
            cout << "Rate   : $" << bikes[choice - 1].pricePerDay << " per day\n";
            cout << "------------------------------\n";
            cout << "Total  : $" << total << "\n";
            cout << "======================================\n";
            string temp;
            cout << "Press any key to go back to bike list...";
            cin >> temp;
        }
        else if (choice == goBackOption) {
            return;
        } else if (choice == addNewOption) {
            float price;
            string color, brand, type;

            cout << "Enter price per day: ";
            while (!(cin >> price)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Enter a number: ";
            }

            cin.ignore();
            cout << "Enter color: ";
            getline(cin, color);
            cout << "Enter brand: ";
            getline(cin, brand);
            cout << "Enter bike type: ";
            getline(cin, type);


            bikes.push_back(Bike(price, color, brand, type));
            cout << "New bike added successfully!\n";
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }
}
