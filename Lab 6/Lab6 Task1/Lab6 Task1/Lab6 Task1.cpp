#include <iostream>
#include <string>
using namespace std;

class Person;
class Coordinator;

class Person 
{
private:
    string comp_name, uni_name;

public:
    Person() 
    {
        string temp;
        cout << "Enter Competition and University name: ";
        getline(cin, temp);
        setter(temp);
    }

    void setter(string temp) 
    {
        int i;
        for (i = 0; temp[i] != ' '; i++)
            comp_name += temp[i];
        for (++i; temp[i] != '\0'; i++) 
            uni_name += temp[i];
    }


    friend class Coordinator;
};

class Coordinator
{
private:
        Person p1, p2;

public:
    
    void check()
    {
        if (p1.uni_name == p2.uni_name)
            cout << "Person 1 & Person 2 are roommates, and the room number is: " << roomnumber() << endl;
        else
            cout << "Person 1 & Person 2 are not roommates!" << endl << endl;
    }

    int roomnumber()
    {
        int len1 = 0, len2 = 0;
        for (len1; p1.comp_name[len1] != '\0'; len1++);
        for (len2; p2.comp_name[len2] != '\0'; len2++);
        if (len1 > len2)
            return len1;
        else
            return len2;
    }

    
};


int main()
{
    Coordinator c1;
    c1.check();
    Coordinator c2;
    c2.check();
}