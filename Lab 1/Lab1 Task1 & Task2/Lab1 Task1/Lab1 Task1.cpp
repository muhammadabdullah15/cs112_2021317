#include <iostream>
#include <iomanip>

using namespace std;

struct student {
    string regno;
    string name;
    string degree;
    float sgpa;
};

void sortdescending(student[3], int[3]);

int main()
{
    student students[3];
    for (int i = 0; i < 3; i++) 
    {
        cout << "Enter the record of student " << i + 1<<endl
            << "Enter name:\t\t\t";
        cin >> students[i].name;
        cout << "Enter reg number:\t\t";
        cin >> students[i].regno;
        cout << "Enter degree program:\t\t";
        cin >> students[i].degree;
        cout << "Enter number of courses:\t";
        int courses;
        cin >> courses;
        cout << endl;
        
        float sgpa=0;
        for (int c = 1; c <= courses; c++) 
        {
            cout << "Enter marks of course " << c << ":\t";
            int marks;
            cin >> marks;
            if (marks >= 86)                    //A
                sgpa += (4.0 * 3);
            else if (marks < 86 && marks >= 82) //A-
                sgpa += (3.67 * 3);
            else if (marks < 82 && marks >= 78) //B+
                sgpa += (3.33 * 3);
            else if (marks < 78 && marks >= 74) //B
                sgpa += (3.0 * 3);
            else if (marks < 74 && marks >= 70) //B-
                sgpa += (2.67 * 3);
            else if (marks < 70 && marks >= 66) //C+
                sgpa += (2.33 * 3);
            else if (marks < 66 && marks >= 62) //C
                sgpa += (2.0 * 3);
            else if (marks < 62 && marks >= 58) //C-
                sgpa += (1.67 * 3);
            else if (marks < 58 && marks >= 54) //D+
                sgpa += (1.33 * 3);
            else if (marks < 54 && marks >= 50) //D
                sgpa += (1.0 * 3);
            else                                //F
                sgpa += 0.0;
        }
        sgpa /= (courses * 3);
        students[i].sgpa = sgpa;
        cout << endl << endl;
    }
    
    int Sno[3] = { 1,2,3 };

    cout << endl << endl
        << setw(10) << left << "S.No." << setw(20) << left << "Name" << setw(20) << left << "Reg. No." << setw(20) << "Degree Program" << setw(10) << left << "SGPA" << endl;
    for (int j = 0; j < 3; j++)
        cout << setw(10) << left << Sno[j]
        << setw(20) << left << students[j].name
        << setw(20) << left << students[j].regno
        << setw(20) << left << students[j].degree
        << setw(10) << left << students[j].sgpa << endl;

    cout << endl << endl << "Sorting students on basis of SGPA:";
    sortdescending(students, Sno);

    cout << endl << endl
        << setw(10) << left << "S.No." << setw(20) << left << "Name" << setw(20) << left << "Reg. No." << setw(20) << "Degree Program" << setw(10) << left << "SGPA" << endl;
    for (int j = 0; j < 3; j++)
        cout << setw(10) << left << Sno[j]
        << setw(20) << left << students[j].name
        << setw(20) << left << students[j].regno
        << setw(20) << students[j].degree
        << setw(10) << left << students[j].sgpa << endl;

    cout << endl << endl;

    cout<<"The best student is:"<<endl
        << setw(20) << left << students[0].name
        << setw(20) << left << students[0].regno
        << setw(20) << students[0].degree
        << setw(10) << left << students[0].sgpa << endl;
}

void sortdescending(student students[3], int Sno[3])
{
    for (int j = 3; j > 0; j--)
    {
        for (int i = 0; i < (j - 1); i++)
        {
            if (students[i + 1].sgpa == 0)
                break;
            if (students[i].sgpa < students[i + 1].sgpa)
            {
                swap(Sno[i], Sno[i + 1]);
                swap(students[i].regno, students[i + 1].regno);
                swap(students[i].name, students[i + 1].name);
                swap(students[i].degree, students[i + 1].degree);
                swap(students[i].sgpa, students[i + 1].sgpa);
            }
        }
    }
}
