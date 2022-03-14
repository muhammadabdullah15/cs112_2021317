#include <iostream>
#include <string>
using namespace std;

class StringType
{
private:
    string string1, string2;
    
public:
    void setValues(string str1, string str2) 
    {
        string1 = str1;
        string2 = str2;
    }

    void printValues() 
    {
        cout << "String 1:\t" << string1 << "\nString 2:\t" << string2;
    }

    int maxLength() 
    {
        int i;
        for (i = 0; string1[i] != '\0'; i++);

        int j;
        for (j = 0; string2[j] != '\0'; j++);
        
        if (i >= j)
            return i;
        else
            return j;
    }

    int compare() 
    {
        for (int i = 0; i < 100; i++)
            if (string1[i] != string2[i])
                return 0;

        return 1;
    }

    void copy()
    {
        int i;
        for (i = 0; string1[i] != '\0'; i++)
            string2[i] = string1[i];
        for (; string2[i] != '\0'; i++)
            string2[i] = '\0';
    }

    string concatenate()
    {
        return (string1 + string2);
    }

    int searchWord(string word) 
    {
        int wordlength;
        for (wordlength = 0; word[wordlength] != '\0'; wordlength++);

        for (int i = 0; string1[i] != '\0'; i++)
        {
            if (string1[i] == word[0]) 
            {
                if (wordlength == 1)
                    return 1;

                for (int j = 1; j < wordlength; j++) 
                {
                    if (word[j] != string1[i + j])
                        break;
                    if (j == (wordlength - 1))
                        return 1;
                }
            }
        }

        return 0;
    }

    int searchChar(char ch) 
    {
        for (int i = 0; string1[i] != '\0'; i++) 
        {
            if (string1[i] == ch)
                return 1;
        }
        
        return 0;
    }
};

void menu(StringType strtype)
{
    int choice = 1;
    cout << endl << endl << endl;
    cout << "************STRING************" << endl
        << "1) Set Values" << endl
        << "2) Print Values" << endl
        << "3) Max Length" << endl
        << "4) Compare" << endl
        << "5) Copy" << endl
        << "6) Concatenate" << endl
        << "7) Search Word" << endl
        << "8) Search Char" << endl
        << "9) Exit" << endl << endl
        << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        string temp1, temp2;
        cout << "Enter str1:";
        cin.ignore();
        getline(cin, temp1);
        cout << "Enter str2:";
        getline(cin, temp2);
        strtype.setValues(temp1, temp2);
        cout << "Values set successfully";
        menu(strtype);
    }
        break;
    case 2:
        cout << "String values:\n";
        strtype.printValues();
        menu(strtype);
        break;
    case 3:
        cout << "Max length is: " << strtype.maxLength();
        menu(strtype);
        break;
    case 4:
        cout << "Compare function returns: " << (strtype.compare() == 1 ? "TRUE" : "FALSE");
        menu(strtype);
        break;
    case 5:
        strtype.copy();
        cout << "string2 copied to string1!";
        menu(strtype);
        break;
    case 6:
        cout << "Concatenating string1 & string2 returns string: " << strtype.concatenate();
        menu(strtype);
        break;
    case 7:
    {
        cout << "Enter word to search: ";
        string word;
        cin >> word;
        cout << "\"" << word << "\" " << (strtype.searchWord(word) == 1 ? "" : "not ") << "found in string1!";
        menu(strtype);
    }
    break;
    case 8: 
    {
        cout << "Enter character to search: ";
        char ch;
        cin >> ch;
        cout << "'" << ch << "' " << (strtype.searchChar(ch) == 1 ? "" : "not ") << "found in string1!";
        menu(strtype);
    }
        break;
    case 9:
        return;
    default:
        cout << "Invalid choice entered!\n Please try again!";
        menu(strtype);
    }
}

int main()
{
    
    StringType strtype;
    menu(strtype);

    return 0;
}