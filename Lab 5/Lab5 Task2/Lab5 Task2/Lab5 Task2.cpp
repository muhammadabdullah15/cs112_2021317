#include <iostream>
using namespace std;

class Parity
{
private:
    int arrsize;
    int* par;

public:
    Parity(int size = 1)
    {
        arrsize = size;
        par = new int[size];
        for (int i = 0; i < size; i++) 
            par[i] = i;
    }

    void put(int num)
    {
        arrsize++;
        int* newarr = new int[arrsize];
        for (int i = 0; i < arrsize - 1; i++)
            newarr[i] = par[i];
        newarr[arrsize - 1] = num;
        par = newarr;
    }

    void print()
    {
        for (int i = 0; i < arrsize; i++)
            cout << par[i] << endl;
    }

    void Delete()
    {
        if (arrsize <= 1) 
        {
            cout << "Error! Last element cannot be deleted";
            return;
        }

        arrsize--;
        int* newarr = new int[arrsize];
        for (int i = 0; i < arrsize; i++)
            newarr[i] = par[i];
        par = newarr;
        
    }

    int test() 
    {
        if (arrsize % 2 == 0)
            return 1;
        else
            return 0;
    }
};

void menu(Parity parity)
{
    int choice = 1;
    cout << endl << endl << endl;
    cout << "************PARITY************" << endl
        << "1) Print" << endl
        << "2) Put" << endl
        << "3) Delete" << endl
        << "4) Test" << endl
        << "5) Exit" << endl << endl
        << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Current elements:\n";
        parity.print();
        menu(parity);
        break;
    case 2: 
    {
        cout << "Enter new value to put: ";
        int num;
        cin >> num;
        parity.put(num);
        cout << num << " inserted into array";
        menu(parity);
    }
        break;
    case 3:
    {
        parity.Delete();
        cout << "Last element deleted from array";
        menu(parity);
    }
        break;
    case 4:
        cout << "Parity test returns: " << (parity.test() == 1 ? "TRUE" : "FALSE");
        menu(parity);
        break;
    case 5:
        return;
    default:
        cout << "Invalid choice entered!\n Please try again!";
        menu(parity);
    }
}

int main()
{
    int initialsize = 4;
    Parity parity(initialsize);
    cout << "Array initialized with " << initialsize << " element";
    menu(parity);

    return 0;
}