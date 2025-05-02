#include <iostream>
#include <vector>
using namespace std;

struct User
{
    string username;
    string password;
};

class Vehicle
{
public:
    float pricePerDay;
    string Color;
    string Brand;
};

class Car : public Vehicle
{
public:
    string carType;
    int maxSpeed;
    Car(float price, string color, string brand, string type, int speed)
    {
        pricePerDay = price;
        Color = color;
        Brand = brand;
        carType = type;
        maxSpeed = speed;
    }
};

class Bike : public Vehicle
{
public:
    string Type;
    Bike(float price, string color, string brand, string type)
    {
        pricePerDay = price;
        Color = color;
        Brand = brand;
        Type = type;
    }
};

vector<User> users;
User *loggedInUser = nullptr;

Bike bikes[] = {
    Bike(2, "black", "track", "Aluminium"),
    Bike(3, "green", "viva", "Carbon Fiber"),
    Bike(4.5, "red", "overlord", "Super Deluxe")};

Car cars[] = {
    Car(10, "white", "Ford Mondeo", "sedan", 150),
    Car(17, "blue", "BMW X3", "SUV", 200),
    Car(30, "black", "Benz C-class", "Luxury", 260)};
