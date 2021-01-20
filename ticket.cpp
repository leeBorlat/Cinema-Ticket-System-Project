#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;

//PANG INITIALIZE NG MGA FUNCTIONS
void seats(void);
void page(void);
int messagemenu(void);
void reserve(void);
void search(void);
void erase(void);
void view(void);
void quit(void);
void tickets(void);

void (*options[])(void) = {reserve, search, erase, view, quit};
char space();

//UNIVERSAL VARIABLES
char rowNo;
int colNo;
int quitters;
char delRow;
int delCol;
int delAns;
char searchRow;
int searchCol;
char answer;
string customerName;
string startButton;
char ticketTable[6][6] = {{' ', '1', '2', '3', '4', '5'},
                          {'A', '.', '.', '.', '.', '.'},
                          {'B', '.', '.', '.', '.', '.'},
                          {'C', '.', '.', '.', '.', '.'},
                          {'D', '.', '.', '.', '.', '.'},
                          {'E', '.', '.', '.', '.', '.'}};

//pang lagay space
char space()
{
    cout << "                        ";
    return 0;
}
//program logo
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
    cout << space() << "Type start: ";
    cin >> startButton;
    if (startButton != "start")
    {
        quit();
    }
}
//quit function

//MENU
int messagemenu(void)
{
    while (true)
    {
        do
        {
            system("cls");
            cout << space() << "**************************" << endl;
            cout << space() << "*         Options:       *" << endl;
            cout << space() << "**************************\n\n"
                 << endl;
            cout << space() << "**********************************" << endl;
            cout << space() << "*     1.Reserve a seat           *" << endl;
            cout << space() << "*                                *" << endl;
            cout << space() << "*     2.Search seats             *" << endl;
            cout << space() << "*                                *" << endl;
            cout << space() << "*     3.Delete a reservation     *" << endl;
            cout << space() << "*                                *" << endl;
            cout << space() << "*     4.View receipt             *" << endl;
            cout << space() << "*                                *" << endl;
            cout << space() << "*     5.Exit Program             *" << endl;
            cout << space() << "**********************************\n"
                 << endl;
            cout << space() << "Select a number: ";
            quitters = getche();

            cout << space() << endl;

        } while (!strchr("12345", quitters));
        return quitters - 49;

        quitters = 0;
    }
}

//0.Table
void tickets(void)
{
    cout << space() << "Seats available: \n"
         << endl;
    //to print out table
    for (int x = 0; x <= 5; x++)
    {
        cout << space();

        for (int y = 0; y <= 5; y++)
        {
            cout << ticketTable[x][y] << " | ";
        }

        cout << "\n\n";
    }
    int transRowNo;
    switch (rowNo)
    {
    case 'A':
        transRowNo = 1;
        break;
    case 'B':
        transRowNo = 2;
        break;
    case 'C':
        transRowNo = 3;
        break;
    case 'D':
        transRowNo = 4;
        break;
    case 'E':
        transRowNo = 5;
        break;
    }

    if (ticketTable[transRowNo][colNo] == '.')
    {
        ticketTable[transRowNo][colNo] == 'X';
    }
    cout << ticketTable[transRowNo][colNo];
}

//1. Reserve
void reserve(void)
{
    system("cls");
    char rowNo;
    int colNo;

    cout << space() << "Row Letter: ";
    cin >> rowNo;
    rowNo = toupper(rowNo);
    cout << space() << "Column Number: ";
    cin >> colNo;
    cout << space() << "Customer Name: ";
    cin >> customerName;

    int transRowNo;
    switch (rowNo)
    {
    case 'A':
        transRowNo = 1;
        break;
    case 'B':
        transRowNo = 2;
        break;
    case 'C':
        transRowNo = 3;
        break;
    case 'D':
        transRowNo = 4;
        break;
    case 'E':
        transRowNo = 5;
        break;
    }

    if (ticketTable[transRowNo][colNo] == '.')
    {
        ticketTable[transRowNo][colNo] = 'X';
    }
    else if (ticketTable[transRowNo][colNo] = 'X')
    {
        cout << space() << "Sorry. This seat is already reserved\n"
             << endl;
    }
    //table
    cout << "\n\n\n";
    for (int x = 0; x <= 5; x++)
    {
        cout << space();
        for (int y = 0; y <= 5; y++)
        {
            if (x == 0 && y == 0)
            {
                cout << "    ";
                continue;
            }
            if (x == 0 && y == 1)
            {
                cout << "1   ";
                continue;
            }
            if (x == 0 && y == 2)
            {
                cout << "2   ";
                continue;
            }
            if (x == 0 && y == 3)
            {
                cout << "3   ";
                continue;
            }
            if (x == 0 && y == 4)
            {
                cout << "4   ";
                continue;
            }
            if (x == 0 && y == 5)
            {
                cout << "5   ";
                continue;
            }
            cout << ticketTable[x][y] << " | ";
        }
        cout << "\n\n";
    }
    cout << "\n\n";
    cout << space() << "'X' = reserved" << endl;
    cout << space() << "'.' = available" << endl;

    fstream my_receipt;
    my_receipt.open(customerName + "'s ticket", ios::app);
    my_receipt << "Row Number: " << rowNo << "\n";
    my_receipt << "Column Number: " << colNo << "\n";
    my_receipt << "Customer Name: " << customerName << "\n";
    my_receipt.close();
    char answer;
    cout << space() << "Would you like to go back to the main menu (Y/N)?";
    cin >> answer;
    answer = toupper(answer);

    if (answer == 'Y')
        messagemenu();
    else
        reserve();
    return;
}
//2. Search
void search(void)
{

    cout << space() << "Enter row letter that you want to search:";
    cin >> searchRow;
    searchRow = toupper(searchRow);
    cout << space() << "Enter column number that you want to search: ";
    cin >> searchCol;
    cout << "\n\n";

    int transRowNo;
    switch (searchRow)
    {
    case 'A':
        transRowNo = 1;
        break;
    case 'B':
        transRowNo = 2;
        break;
    case 'C':
        transRowNo = 3;
        break;
    case 'D':
        transRowNo = 4;
        break;
    case 'E':
        transRowNo = 5;
        break;
    }
    if (ticketTable[transRowNo][searchCol] == 'X')
    {
        //printout table
        for (int x = 0; x <= 5; x++)
        {
            cout << space();
            for (int y = 0; y <= 5; y++)
            {
                if (x == 0 && y == 0)
                {
                    cout << "    ";
                    continue;
                }
                if (x == 0 && y == 1)
                {
                    cout << "1   ";
                    continue;
                }
                if (x == 0 && y == 2)
                {
                    cout << "2   ";
                    continue;
                }
                if (x == 0 && y == 3)
                {
                    cout << "3   ";
                    continue;
                }
                if (x == 0 && y == 4)
                {
                    cout << "4   ";
                    continue;
                }
                if (x == 0 && y == 5)
                {
                    cout << "5   ";
                    continue;
                }
                cout << ticketTable[x][y] << " | ";
            }
            cout << "\n\n";
        }
        cout << space() << "This seat is reserved. Would you like to go back to the main menu? (Y/N)";
        cin >> answer;
        answer = toupper(answer);
        if (answer == 'Y')
        {
            messagemenu();
        }
    }
    else
    {
        //printout table
        for (int x = 0; x <= 5; x++)
        {
            cout << space();
            for (int y = 0; y <= 5; y++)
            {
                if (x == 0 && y == 0)
                {
                    cout << "    ";
                    continue;
                }
                if (x == 0 && y == 1)
                {
                    cout << "1   ";
                    continue;
                }
                if (x == 0 && y == 2)
                {
                    cout << "2   ";
                    continue;
                }
                if (x == 0 && y == 3)
                {
                    cout << "3   ";
                    continue;
                }
                if (x == 0 && y == 4)
                {
                    cout << "4   ";
                    continue;
                }
                if (x == 0 && y == 5)
                {
                    cout << "5   ";
                    continue;
                }
                cout << ticketTable[x][y] << " | ";
            }
            cout << "\n\n";
        }
        cout << "\n\n";
        cout << space() << "This seat is available. Would you like to reserve a seat? (Y/N)";
        cin >> answer;
        answer = toupper(answer);
        if (answer == 'Y')
        {
            reserve();
        }
    }
}
//3. Erase
void erase(void)
{
    cout << space() << "Enter row letter that you want to delete:";
    cin >> delRow;
    delRow = toupper(delRow);
    cout << space() << "Enter column number that you want to delete:";
    cin >> delCol;
    fstream my_receipt;
    my_receipt.open(customerName + "'s ticket", ios::out);
    my_receipt << "Row Number: \n";
    my_receipt << "Column Number: \n";
    my_receipt << "Customer Name: \n";
    my_receipt.close();
    cout << space() << "Deleted reservation succesfully. Would you like to go back to the main menu (Y/N)";
    char answer;
    cin >> answer;
    answer = toupper(answer);
    if (answer == 'Y')
    {
        messagemenu();
    }
    else
    {
        erase();
    }

    int transRowNo;
    switch (delRow)
    {
    case 'A':
        transRowNo = 1;
        break;
    case 'B':
        transRowNo = 2;
        break;
    case 'C':
        transRowNo = 3;
        break;
    case 'D':
        transRowNo = 4;
        break;
    case 'E':
        transRowNo = 5;
        break;
    }
    if (ticketTable[transRowNo][delCol] == 'X')
    {
        ticketTable[transRowNo][delCol] = '.';
    }
    else
    {
        char answer;
        cout << "No seats reserved. Would you like to delete another one? (Y/N)";
        cin >> answer;
        answer = toupper(answer);
        if (answer == 'Y')
        {
            erase();
        }
    }
}
//4. View
void view(void)
{
    system("cls");
    //table
    for (int x = 0; x <= 5; x++)
    {
        cout << space();
        for (int y = 0; y <= 5; y++)
        {
            if (x == 0 && y == 0)
            {
                cout << "    ";
                continue;
            }
            if (x == 0 && y == 1)
            {
                cout << "1   ";
                continue;
            }
            if (x == 0 && y == 2)
            {
                cout << "2   ";
                continue;
            }
            if (x == 0 && y == 3)
            {
                cout << "3   ";
                continue;
            }
            if (x == 0 && y == 4)
            {
                cout << "4   ";
                continue;
            }
            if (x == 0 && y == 5)
            {
                cout << "5   ";
                continue;
            }
            cout << ticketTable[x][y] << " | ";
        }
        cout << "\n\n";
    }
    char answer;
    string lineFromReceipt;
    fstream my_receipt;
    my_receipt.open(customerName + "'s ticket", ios::in | ios::app);
    my_receipt >> lineFromReceipt;
    my_receipt.seekg(0);
    cout << space() << "Thank you for watching in Lee's Cinema.\n"
         << space() << endl
         << endl
         << space() << "Here is your receipt. \n";
    while (my_receipt.good())
    {
        getline(my_receipt, lineFromReceipt);
        cout << endl
             << space() << lineFromReceipt << endl;
    }
    my_receipt.close();

    cout << space() << "Would you like to go back to the main menu (Y/N)?";
    cin >> answer;
    answer = toupper(answer);
    if (answer == 'Y')
        messagemenu();
    else
        view();
}
//5. Quit
void quit()
{

    exit(0);
}

//start of code
main(void)

{
    page();

    int i;
    do
    {
        i = messagemenu();
        (*options[i])();

    } while (true);

    return 0;
}

//things to do
//focus sa menu
//dapat
// i loop yung program *checked*
// dapat ma loop program kahit sa options *checked*
// make reponsive menu pag inenter yung number dun kaagad pupunta *checked*
// dapat ma save na yung values sa database tapos mukhang ticket na malupet *checked*
// dapat makagawa bagong text file per reservation na naka base sa name nila *checked*
// dapat ma check kung reserved or hindi pa *IMPORTANTE*
// dapat maka group reserve *importante rin*
//TAPOS TAPOS NA?