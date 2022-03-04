#include <iostream>

using namespace std;

int main()
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    
    int* array = new int[size];
    
    cout << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "Enter a number: ";
        cin >> *(array + i);
    }

    int* differences = new int[size - 1];

    for (int i = 0; i < (size-1); i++)
        *(differences + i) = *(array + i + 1) - *(array + i);

    cout << endl << "Resultant array: " << endl;

    for (int i = 0; i < (size - 1); i++)
        cout << *(differences + i) << endl;
    
    delete[] array;                 //delete to save memory or to re utilize the array
    delete[] differences;
    return 0;
}
