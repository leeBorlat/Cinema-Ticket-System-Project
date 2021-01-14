#include <iostream>

using namespace std;
void page(void);
void seats(void);
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
void seats(void)
{
    for (int x = 0; x <= 5; x++)
    {
        cout << space();

        for (int y = 0; y <= 5; y++)
        {
            
            char table[6][6] = {{' ', '1', '2', '3', '4', '5'},
                                {'A', '.', '.', '.', '.', '.'},
                                {'B', '.', '.', '.', '.', '.'},
                                {'C', '.', '.', '.', '.', '.'},
                                {'D', '.', '.', '.', '.', '.'},
                                {'E', '.', '.', '.', '.', '.'}};

            cout << table[x][y] << "  ";
        }

        cout << "\n\n";
    }
}
int main()

{
    page();

    cout << endl;
    cout << endl;
    cout << endl;

    cout << space() << "Seats available: \n"<< endl;

    seats();
    char rowNo;
    int colNo;

    cout << space() << "Where would you like to reserve your seat? \n" << endl;
    cout << "Row Letter: ";
    cin >> rowNo;
    cout <<"Column Number: ";
    cin >> colNo;

    return 0;
}
