#include <iostream>
#include <string.h>

using namespace std;
void seats(void);
void page(void);
char space();

char space()
{
    cout << "                        ";
    return 0;
}
void page(void)
{
    cout << space() << "**************************" << endl;
    cout << space() << "*                        *" << endl;
    cout << space() << "*                        *" << endl;
    cout << space() << "*      Lee's Cinema      *" << endl;
    cout << space() << "*         Tickets        *" << endl;
    cout << space() << "*                        *" << endl;
    cout << space() << "*                        *" << endl;
    cout << space() << "*                        *" << endl;
    cout << space() << "**************************" << endl;
}

int main()
//start of code

{
    page();

    cout << endl;
    cout << endl;
    cout << endl;

    cout << space() << "Seats available: \n"<< endl;
char table[6][6] = {{' ', '1', '2', '3', '4', '5'},
                                {'A', 'X', '.', '.', '.', '.'},
                                {'B', '.', '.', '.', '.', '.'},
                                {'C', '.', '.', '.', '.', '.'},
                                {'D', '.', '.', '.', '.', '.'},
                                {'E', '.', '.', '.', '.', '.'}};
    for (int x = 0; x <= 5; x++)
    {
        cout << space();

        for (int y = 0; y <= 5; y++)
        {
            cout << table[x][y] << "  ";

        }

        cout << "\n\n";
    }
    char rowNo;
    int colNo;

    cout << space() << "Where would you like to reserve your seat? \n"<< endl;
    cout << space() << "Row Letter: ";
    cin >> rowNo;
    cout << space() << "Column Number: ";
    cin >> colNo;

    int transRowNo;
    switch(rowNo)
    {
        case 'A':
        transRowNo=1; 
        break; 
        case 'B':
        transRowNo=2;
        break;
        case 'C':
        transRowNo=3;
        break;
        case 'D':
        transRowNo=4;
        break;
        case 'E':
        transRowNo=5;
        break;

    } 
    cout << table[transRowNo][colNo];

if(table[transRowNo][colNo]=='.')
{
    table[transRowNo][colNo]='+';
}

    for (int x = 0; x <= 5; x++)
    {
        cout << space();

        for (int y = 0; y <= 5; y++)
        {
            cout << table[x][y] << "  ";

        }

        cout << "\n\n";
    }
    return 0;
}
