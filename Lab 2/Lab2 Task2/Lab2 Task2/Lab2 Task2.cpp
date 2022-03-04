#include <iostream>

using namespace std;

#define read(type,var) type var; cin >> var;
#define calculate(num1,num2) (num1 * (2 << num2 - 1))

int main()
{
    cout << "Enter first number:\t";
    read(int, num1);
    cout << "Enter second number:\t";
    read(int, num2);

    cout << "\nAnswer is " << calculate(num1,num2) << endl;

    return 0;
}