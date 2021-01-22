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
void cinemascreen(void);

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
char customerName[100];
string startButton;
string ticketTable[11][6] = {

    {"      ", "         1      ", "         2      ", "         3      ", "         4      ", "         5      "},
    {"A", "   ", "   ", "   ", "   ", "   "},
    {" ", "A1 ", "A2 ", "A3 ", "A4 ", "A5 "},
    {"B", "   ", "   ", "   ", "   ", "   "},
    {" ", "B1 ", "B2 ", "B3 ", "B4 ", "B5 "},
    {"C", "   ", "   ", "   ", "   ", "   "},
    {" ", "C1 ", "C2 ", "C3 ", "C4 ", "C5 "},
    {"D", "   ", "   ", "   ", "   ", "   "},
    {" ", "D1 ", "D2 ", "D3 ", "D4 ", "D5 "},
    {"E", "   ", "   ", "   ", "   ", "   "},
    {" ", "E1 ", "E2 ", "E3 ", "E4 ", "E5 "}};

//pang lagay space
char space()
{
    cout << "                        ";
    return 0;
}
void cinemascreen()
{
    cout << "\n\n";
    cout << space() << "                   ****************************************************" << endl;
    cout << space() << "                   *                   Lee's Cinema                   *" << endl;
    cout << space() << "                   ****************************************************" << endl;
}
//program logo
void page(void)
{
    cinemascreen();
    cout << space() << "                   Type start: ";
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
            cout << space() << "*                                *" << endl;
            cout << space() << "*     1.Reserve a seat           *" << endl;
            cout << space() << "*                                *" << endl;
            cout << space() << "*     2.Search seats             *" << endl;
            cout << space() << "*                                *" << endl;
            cout << space() << "*     3.Delete a reservation     *" << endl;
            cout << space() << "*                                *" << endl;
            cout << space() << "*     4.View receipt             *" << endl;
            cout << space() << "*                                *" << endl;
            cout << space() << "*     5.Exit Program             *" << endl;
            cout << space() << "*                                *" << endl;
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
    //to print out table
    for (int x = 0; x <= 10; x++)
    {
        space();
        for (int y = 0; y <= 5; y++)
        {
            cout << ticketTable[x][y];
            if (x == 0)
                continue;
            cout << "      |      ";
        }

        cout << "\n";
    }
}
//1. Reserve
void reserve(void)
{
    system("cls");
    remove("my_receipt.txt");
    char rowNo;
    int colNo;
    int inputNumSeats;

    //Inputs number of seats to reserve
    cout << space() << "Enter number of seats to reserve: ";
    cin >> inputNumSeats;

    //Prints out available seats available to reserve.
    cout << space() << "Here are the available seats you can reserve: \n";
    cinemascreen();
    tickets();

    cout << "\n\n"
         << space() << "Enter your reservation details: \n\n";
    for (int s = 1; s <= inputNumSeats; s++)
    {
        cout << space() << "\tRow Letter: ";
        cin >> rowNo;
        rowNo = toupper(rowNo);
        cout << space() << "\tColumn Number: ";
        cin >> colNo;
        cout << space() << "\tCustomer Name: ";
        cin >> customerName;
        cout << "\n\n";
        int transRowNo;
        switch (rowNo)
        {
        case 'A':
            transRowNo = 1;
            break;
        case 'B':
            transRowNo = 3;
            break;
        case 'C':
            transRowNo = 5;
            break;
        case 'D':
            transRowNo = 7;
            break;
        case 'E':
            transRowNo = 9;
            break;
        }

        if (ticketTable[transRowNo + 1][colNo] != "X  ")
        {
            ticketTable[transRowNo][colNo] = customerName;
            ticketTable[transRowNo + 1][colNo] = "X  ";
        }
        else if (ticketTable[transRowNo + 1][colNo] == "X  ")
        {
            char answer;
            cout << space() << "Sorry. This seat is already reserved. Reserve again? (Y/N): ";
            cin >> answer;
            answer = toupper(answer);

            if (answer == 'Y')
                reserve();
            else
                messagemenu();
            return;
        }

        fstream my_receipt;
        my_receipt.open("my_receipt.txt", ios::out | ios::app);
        my_receipt << "\tCustomer Name: " << customerName << "\n";
        my_receipt << "\tReserved Seat Location: " << rowNo << colNo << "\n";
        my_receipt.close();
    }

    //printout table
    system("cls");
    space();
    cinemascreen();
    tickets();

    cout << "\n\n";
    cout << space() << space() << "'X' = reserved" << endl;
    cout << space() << space() << "'A1...' = available \n\n"
         << endl;

    char answer;
    cout << space() << "Would you like to go back to the main menu (Y/N)?: ";
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
    if (ticketTable[transRowNo][searchCol] != "   ")
    { //printout table
        space();
        cinemascreen();
        tickets();

        cout << "\n"
             << space() << "This seat is reserved. Would you like to search for more (Y/N)? : ";
        cin >> answer;
        answer = toupper(answer);
        if (answer == 'Y')
        {
            search();
        }
    }
    else
    {
        //printout table
        space();
        cinemascreen();
        tickets();

        cout << "\n\n";
        cout << space() << "This seat is available. Would you like to reserve a seat (Y/N)? : ";
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

    cout << space() << "Enter row letter that you want to delete: ";
    cin >> delRow;
    delRow = toupper(delRow);
    cout << space() << "Enter column number that you want to delete: ";
    cin >> delCol;

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
    string col = to_string(delCol);
    string delInput = delRow + col;
    if (ticketTable[transRowNo + 1][delCol] == "X  ")
    {
        ticketTable[transRowNo][delCol] = "   ";
        ticketTable[transRowNo + 1][delCol] = delInput + " ";

        remove("my_receipt.txt");

        cout << "\n\n"
             << space() << "Deleted reservation succesfully. Would you like to go back to the main menu (Y/N)? : ";
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
    }
    else
    {
        char answer;
        cout << "No seats reserved. Would you like to reserve first? (Y/N)? : ";
        cin >> answer;
        answer = toupper(answer);
        if (answer == 'Y')
        {
            reserve();
        }
    }
}
//4. View
void view(void)
{
    system("cls");
    //printout table
    space();
    cinemascreen();
    tickets();

    char answer;
    string lineFromReceipt;
    fstream my_receipt;
    my_receipt.open("my_receipt.txt", ios::in | ios::app);
    my_receipt >> lineFromReceipt;
    my_receipt.seekg(0);
    cout << "\n"
         << space() << "Thank you for watching in Lee's Cinema.\n"
         << space() << endl
         << endl
         << space() << "Here is your receipt. \n\n";
    while (my_receipt.good())
    {
        getline(my_receipt, lineFromReceipt);
        cout << endl
             << space() << lineFromReceipt << endl;
    }
    my_receipt.close();

    cout << "\n"
         << space() << "Would you like to go back to the main menu (Y/N)? : ";
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

// CLEAN UP CODE YUNG LAST STEP
// dapat yung spacing ng table hindi masira kapag nag input ng mahabang name
// dapat yung search ay makapag recommend ng available seats *TAPOS NA*
// kailangan based sa input sa kung gano karami yung magpapareserve para pwedeng individual or group *TAPOS NA*
// dapat sa isang text file nalang my_receipt.txt tapos nag a-append kapag nag pa reserve by group.*TAPOS NA*
// pag nag delete dapat ma delete rin yung txt file*TAPOS NA*
// pagandahin pa yung table at yung code *TAPOS NA*
// ayusin yung pag input ng user para hindi mukhang tae kapag mag ttype sila *TAPOS NA*
// INDENTION PARA MALINIS space() *TAPOS NA*

//TAPOS TAPOS NA?

/* 1. Menu: */

/* Search - seat if available to reserve,

Reserve - input your name and the selected seat number, Reserve seat individual and by group (enter names based on the number of seats).

Cancel/Delete Reservation Record – remove the name and the seat should be available again.

View Record - names, seat number

Exit.

2. Input Data: Name and seat number *

3. Calculated data change status if reserve or not *

4. Calculated behavior is checking for continuous seats e.g. 2 seats, 3 seats, 4 seats, etc.

5. Data for system should be saved on a flat file e.g. text file or txt files. *

6. System can accept multiple reservation. *

7. Design your own Menu.*/