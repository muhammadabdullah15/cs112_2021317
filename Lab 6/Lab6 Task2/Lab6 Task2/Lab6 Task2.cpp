#include <iostream>
#include <string>
using namespace std;

void menu();
class Officer;


class Officer
{
private:
    int id;
    static int total_officers;
    string name;
    string rank;

public:
    Officer() 
    {
        total_officers++;

        cout << "Enter officer ID:\t";
        cin >> id;
        
        cout << "Enter officer name:\t";
        cin.ignore();
        getline(cin, name);
        
        cout << "Enter officer rank:\t";
        cin.ignore();
        getline(cin, rank);
    }

    ~Officer() 
    {
        total_officers--;
    }

    bool palindrome()
    {
        int reverse = 0;
        int tempnum = id;
        while (tempnum != 0)
        {
            reverse = (reverse * 10) + (tempnum % 10);
            tempnum /= 10;
        }

        if (reverse == id)
            return 1;
        else
            return 0;
    }

    static int get_total()
    {
        return total_officers;
    }
};

int Officer::total_officers = 0;

void menu() 
{
    cout << endl << endl
        << "1) Enter officer ID" << endl
        << "2) Get total number of officers" << endl
        << "3) Exit" << endl << endl
        << "Enter desired option:\t";
    
    int choice;
    cin >> choice;
    
    switch (choice)
    {
    case 1: 
    {
        Officer* off = new Officer;
        if (off->palindrome())
            cout << "The officer is allowed to enter the area!";
        else
            cout << "The officer is not allowed to enter the area!";
    }
        menu();
        break;
    case 2:
        cout << "Current number of officers: " << Officer::get_total();
        menu();
        break;
    case 3:
        return;
        break;
    default:
        cout << "Invalid choice entered please try again!";
        menu();
        break;
    }
}


int main()
{
    menu();
    return 0;
}