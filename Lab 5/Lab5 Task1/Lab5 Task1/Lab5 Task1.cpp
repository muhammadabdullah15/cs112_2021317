#include <iostream>
using namespace std;

class Heater
{
private:
    int temperature;

public:
    Heater() 
    {
        temperature = 15;
    }
    
    void warmer() 
    {
        temperature += 5;
    }
    
    void cooler()
    {
        temperature -= 5;
    }

    int gettemp() 
    {
        return temperature;
    }
};

void menu(Heater heater)
{
    int choice = 1;
    cout << endl << endl << endl;
    cout << "************HEATER************" << endl
        << "1) Return Current Temperature" << endl
        << "2) Warmer" << endl
        << "3) Cooler" << endl
        << "4) Exit " << endl << endl
        << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Current temperature is: " << heater.gettemp();
        menu(heater);
        break;
    case 2:
        heater.warmer();
        cout << "Temperature increased by 5!" << endl << "New temperature is: " << heater.gettemp();
        menu(heater);
        break;
    case 3:
        heater.cooler();
        cout << "Temperature decreased by 5!" << endl << "New temperature is: " << heater.gettemp();
        menu(heater);
        break;
    case 4:
        return;
    default:
        cout << "Invalid choice entered!\n Please try again!";
        menu(heater);
    }
}

int main()
{
    Heater heater;
    cout << "Heater object created with current Temperature: " << heater.gettemp();
    menu(heater);
    
    return 0;
}