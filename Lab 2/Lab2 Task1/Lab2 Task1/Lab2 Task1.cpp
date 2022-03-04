#include <iostream>

using namespace std;

#define read(type,var) type var; cin >> var;
#define powerof2(a) ((a) & (a-1))

int main()
{
    cout << "Enter number to check: ";
    read(int, num);

    if (!powerof2(num))
        cout << "\nYes, " << num << " is a power of 2\n";
    else
        cout << "\nNo, " << num << " is not a power of 2\n";

    return 0;
}