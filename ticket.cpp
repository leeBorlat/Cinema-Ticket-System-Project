#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <ctime>
using namespace std;

//PANG INITIALIZE NG MGA FUNCTIONS
void seats(void), page(void), reserve(void), search(void), erase(void), view(void), quit(void), tickets(void), cinemascreen(void), (*options[])(void) = {reserve, search, erase, view, quit};
int messagemenu(void);
char space();

//UNIVERSAL VARIABLES
char rowNo, searchRow, delRow, answer;
int colNo, quitters, delCol, delAns, searchCol, maxLength = 0, lenOfName = 0;
string customerName, startButton;
string ticketTable[11][6] = {
    {" ", " 1", " 2", " 3", " 4", " 5"},
    {"A", "  ", "  ", "  ", "  ", "  "},
    {" ", "A1", "A2", "A3", "A4", "A5"},
    {"B", "  ", "  ", "  ", "  ", "  "},
    {" ", "B1", "B2", "B3", "B4", "B5"},
    {"C", "  ", "  ", "  ", "  ", "  "},
    {" ", "C1", "C2", "C3", "C4", "C5"},
    {"D", "  ", "  ", "  ", "  ", "  "},
    {" ", "D1", "D2", "D3", "D4", "D5"},
    {"E", "  ", "  ", "  ", "  ", "  "},
    {" ", "E1", "E2", "E3", "E4", "E5"}};

//pang lagay space
char space()
{
    cout << "                        ";
    return 0;
}
void cinemascreen()
{
    cout << "\n\n";
    cout << space() << "                      ****************************************************" << endl;
    cout << space() << "                      *                   Lee's Cinema                   *" << endl;
    cout << space() << "                      ****************************************************" << endl;
}
//program logo
void page(void)
{
    cinemascreen();
    cout << "\n\n" << space() << "                   Type start: ";
    cin >> startButton;
    if (startButton != "start") quit();
}

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
            cout << space() << "**************************\n\n" << endl;
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
            cout << space() << "**********************************\n" << endl;
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
    int newMaxLength;
    for (int x = 0; x <= 10; x++)
    {
        space();
        for (int y = 0; y <= 5; y++)
        {
            if (ticketTable[x][y].length() == 6)  cout << setw(11);
            else if (ticketTable[x][y].length() == 5)  cout << setw(7);
            else if (ticketTable[x][y].length() == 4)  cout << setw(10);
            else if (ticketTable[x][y].length() == 3)  cout << setw(9);
            else if (ticketTable[x][y].length() == 2)  cout << setw(8);
            else if (ticketTable[x][y].length() == 1)  cout << setw(8);

            cout << ticketTable[x][y];

            if (ticketTable[x][y].length() == 6) cout << setw(5);
            else if (ticketTable[x][y].length() == 5)  cout << setw(6);
            else if (ticketTable[x][y].length() == 4)  cout << setw(6);
            else if (ticketTable[x][y].length() == 3)  cout << setw(7);
            else if (ticketTable[x][y].length() == 2)   cout << setw(8);
            else if (ticketTable[x][y].length() == 1)   cout << setw(8);

            cout << "|";
        }
        cout << "\n";
    }
}
// pang call ng customer name

int customerNames()
{
    char answer;
    cout << space() << "\tCustomer Name (upto 6 letters): ";
    cin >> customerName;
    if (customerName.length() > 6)
    {
        cout << "\n" << space() << "Please enter only up to 6 letters. Reserve again? (Y/N) : ";
        cin >> answer;
        answer = toupper(answer);

        if (answer == 'Y') reserve();
        else  messagemenu();
    }

    lenOfName = customerName.length();
    if (maxLength < lenOfName)  maxLength = lenOfName;
    return maxLength;
}
//1. Reserve
void reserve(void)
{
    system("cls");
    remove("my_receipt.txt");
    char rowNo;
    int colNo, inputNumSeats;

    //Inputs number of seats to reserve
    cout << space() << "Enter number of seats to reserve: ";
    cin >> inputNumSeats;

    //Prints out available seats available to reserve.
    cout << space() << "Here are the available seats you can reserve: \n";
    cinemascreen();
    cout << "\n\n";
    tickets();

    cout << "\n\n" << space() << "Enter your reservation details: \n\n";
    for (int s = 1; s <= inputNumSeats; s++)
    {
        cout << space() << "\tRow Letter: ";
        cin >> rowNo;
        rowNo = toupper(rowNo);
        cout << space() << "\tColumn Number: ";
        cin >> colNo;
        customerNames();
        cout << "\n\n";
        int transRowNo;
        switch (rowNo){
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

        if (ticketTable[transRowNo + 1][colNo] != " X "){
            ticketTable[transRowNo][colNo] = customerName;
            ticketTable[transRowNo + 1][colNo] = " X ";
        }
        else if (ticketTable[transRowNo + 1][colNo] == " X "){
            char answer;
            cout << space() << "Sorry. This seat is already reserved. Reserve again? (Y/N): ";
            cin >> answer;
            answer = toupper(answer);

            if (answer == 'Y')  reserve();
            else  messagemenu();
            return;
        }
        //to get the time they reserved:
        time_t tt;
        struct tm *ti;
        time(&tt);
        ti = localtime(&tt);

        fstream my_receipt;
        my_receipt.open("my_receipt.txt", ios::out | ios::app);
        my_receipt << "\tCustomer Name: " << customerName << "\n";
        my_receipt << "\tReserved Seat Location: " << rowNo << colNo << "\n";
        my_receipt << "\tTime you reserved: " << asctime(ti);
        my_receipt.close();
    }

    //printout table
    system("cls"); space(); cinemascreen();  cout << "\n\n"; tickets();

    cout << "\n\n" << space() << space() << "'X' = reserved" << endl;
    cout << space() << space() << "'A1...' = available \n\n" << endl;

    char answer;
    cout << space() << "Would you like to go back to the main menu (Y/N)?: ";
    cin >> answer;
    answer = toupper(answer);

    if (answer == 'Y') messagemenu();
    else reserve();

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
    switch (searchRow) {
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
    if (ticketTable[transRowNo][searchCol] != "  ")
    { //printout table
        space();cinemascreen();cout << "\n\n";tickets();

        cout << "\n" << space() << "This seat is reserved. Would you like to search for more (Y/N)? : ";
        cin >> answer;
        answer = toupper(answer);
        if (answer == 'Y') search();
    }
    else
    {
        //printout table
        space();cinemascreen();cout << "\n\n";tickets();cout << "\n\n";

        cout << space() << "This seat is available. Would you like to reserve a seat (Y/N)? : ";
        cin >> answer;
        answer = toupper(answer);
        if (answer == 'Y') reserve();
    }
}
//3. Erase
void erase(void)
{
    char answer;
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
    if (ticketTable[transRowNo + 1][delCol] == " X ")
    {
        ticketTable[transRowNo][delCol] = "   ";
        ticketTable[transRowNo + 1][delCol] = delInput + " ";

        remove("my_receipt.txt");

        cout << "\n\n"  << space() << "Deleted reservation succesfully. Would you like to go back to the main menu (Y/N)? : ";
        char answer;
        cin >> answer;
        answer = toupper(answer);
        if (answer == 'Y')  messagemenu();
        else  erase();
    }
    else
    {
        cout << "No seats reserved. Would you like to reserve first? (Y/N)? : ";
        cin >> answer;
        answer = toupper(answer);
        if (answer == 'Y') reserve();
    }
}
//4. View
void view(void)
{
    //printout table
    system("cls"); space(); cinemascreen(); tickets();

    char answer;
    string lineFromReceipt;
    fstream my_receipt;
    my_receipt.open("my_receipt.txt", ios::in | ios::app);
    my_receipt >> lineFromReceipt;
    my_receipt.seekg(0);
    cout << "\n" << space() << "Thank you for watching in Lee's Cinema.\n"  << space() << endl << endl << space() << "Here is your receipt. \n\n";
    while (my_receipt.good())
    {
        getline(my_receipt, lineFromReceipt);
        cout << endl << space() << lineFromReceipt << endl;
    }
    my_receipt.close();

    cout << "\n" << space() << "Would you like to go back to the main menu (Y/N)? : ";
    cin >> answer;
    answer = toupper(answer);
    if (answer == 'Y')  messagemenu();
    else   view();
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