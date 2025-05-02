#include <iostream>
#include <vector>
#include "class.h"
#include <limits>
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
    cin >> password;
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
    cout << "Enter password: ";
    cin >> password;

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

void rentCarMenu()
{
    int choice;
    while (true)
    {
        cout << "\n--- Available Cars ---\n";
        for (int i = 0; i < 3; i++)
        {
            cout << i + 1 << ". " << cars[i].Brand << " (" << cars[i].carType << ") - "
                 << cars[i].Color << " - $" << cars[i].pricePerDay << "/day\n";
        }
        cout << "4. Go Back\n";
        cout << "Enter car number to rent or 4 to go back: ";
        cin >> choice;

        if (choice >= 1 && choice <= 3)
        {
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
            cout << "Days   : " << days << "\n";
            cout << "Rate   : $" << cars[choice - 1].pricePerDay << " per day\n";
            cout << "------------------------------\n";
            cout << "Total  : $" << total << "\n";
            cout << "======================================\n";
            string temp;
            cout << "Press any key to go back to car list...";
            cin >> temp;
        }
        else if (choice == 4)
        {
            return;
        }
        else
        {
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
        for (int i = 0; i < 3; i++)
        {
            cout << i + 1 << ". " << bikes[i].Brand << " (" << bikes[i].Type << ") - "
                 << bikes[i].Color << " - $" << bikes[i].pricePerDay << "/day\n";
        }
        cout << "4. Go Back\n";
        cout << "Enter bike number to rent or 4 to go back: ";
        cin >> choice;

        if (choice >= 1 && choice <= 3)
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
        else if (choice == 4)
        {
            return;
        }
        else
        {
            cout << "Invalid choice. Try again.\n";
        }
    }
}
