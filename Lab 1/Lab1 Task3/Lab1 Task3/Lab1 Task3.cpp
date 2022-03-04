#include <iostream>

using namespace std;

struct DOB {
    int day;
    int year;
    string month;
};

struct user {
    string name;
    string city;
    int age;
    DOB dateofbirth;
};

int main()
{
    user users[3];
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter the record of User " << i + 1 << endl
            << "Enter name:\t";
        cin >> users[i].name;
        cout << "Enter Age:\t";
        cin >> users[i].age;
        cout << "Enter city:\t";
        cin >> users[i].city;
        cout << endl << "Enter Date of Birth Details:" << endl
            << "Enter day:\t";
        cin >> users[i].dateofbirth.day;
        cout << "Enter month:\t";
        cin >> users[i].dateofbirth.month;
        cout << "Enter year:\t";
        cin >> users[i].dateofbirth.year;

        cout << endl << endl << endl;
    }

    int tempday;
    int tempyear;
    string tempmonth;
    cout << endl << "Enter Date of Birth to check:" << endl << endl
        << "Enter day:\t";
    cin >> tempday;
    cout << "Enter month:\t";
    cin >> tempmonth;
    cout << "Enter year:\t";
    cin >> tempyear;
    
    cout << endl << endl;
    
    bool found = true;
    
    for (int s = 0; s < 3; s++)
    {
        if (users[s].dateofbirth.day == tempday)
        {
            if (users[s].dateofbirth.month == tempmonth)
            {
                if (users[s].dateofbirth.year == tempyear)
                {
                    cout << "It is " << users[s].name << "'s birthday. Happy birthday, " << users[s].name;
                    break;
                }
                else
                    found = false;
            }
            else
                found = false;
        }
        else
            found = false;
    }
    cout << endl << (found ? "" : "No DOB found at entered date");
}