#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
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
void (*options[])(void)={reserve,search,erase,view,quit};
char space();


//UNIVERSAL VARIABLES
char rowNo;
int colNo;
int quitters;
int ch;
string startButton;
char answer;
char reserveMore;
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
    if(startButton!="start"){
        quit();
    }
}
//quit function

//MENU
int messagemenu(void)
{while(true){
do
    {
    system("cls");
    cout << space() << "**************************"<< endl;
    cout << space() << "*         Options:       *"<< endl;
    cout << space() << "**************************\n\n"<< endl;
    cout << space() << "**********************************"<< endl;
    cout << space() << "*     1.Reserve a seat           *"<< endl;
    cout << space() << "*                                *"<< endl;
    cout << space() << "*     2.View seats               *"<< endl;
    cout << space() << "*                                *"<< endl;
    cout << space() << "*     3.Delete a reservation     *"<< endl;
    cout << space() << "*                                *"<< endl;
    cout << space() << "*     4.View record              *"<< endl;
    cout << space() << "*                                *"<< endl;
    cout << space() << "*     5.Exit Program             *"<< endl;
    cout << space() << "**********************************\n"<< endl;
    cout << space() << "Select a number: ";
    quitters=getche();
    
    cout << space() << endl;
    

    }while(!strchr("12345",quitters));
        return quitters-49;

    
quitters=0;
}
  
}



//0.Table
void tickets(void)
{
 cout << space() << "Seats available: \n" << endl;
    
    for (int x = 0; x <= 5; x++)
    {
        cout << space();

        for (int y = 0; y <= 5; y++)
        {
            cout << ticketTable[x][y] << "  ";
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
        ticketTable[transRowNo][colNo] == '+';
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
    else if(ticketTable[transRowNo][colNo] = 'X')
    {
        cout << space() << "Sorry. This seat is already reserved"<< endl;
        
    }

    for (int x = 0; x <= 5; x++)
    {
        cout << space();

        for (int y = 0; y <= 5; y++)
        {
            cout << ticketTable[x][y] << "  ";
        }

        cout << "\n\n";   
    }
        cout << space() << "'X' = reserved" << endl;
        cout << space() << "'.' = available" << endl;
    cout << "Would you like to go back to the main menu (Y/N)?";
    cin >> answer;
    answer = toupper(answer);

    if(answer=='Y') messagemenu();
    else reserve();
    return; 
}   
//2. Search
void search(void)
{
  cout << "Would you like to go back to the main menu (Y/N)?";
    cin >> answer;
    answer = toupper(answer);
    if(answer=='Y') messagemenu();
    else reserve();
}
//3. Erase
void erase(void)
{
    cout << "in erase";
    cout << "Would you like to go back to the main menu (Y/N)?";
    cin >> answer;
    answer = toupper(answer);
    
    if(answer=='Y') messagemenu();
    else reserve();
}

//4. View
void view(void)
{
    system("cls");
    for (int x = 0; x <= 5; x++)
    {
        cout << space();

        for (int y = 0; y <= 5; y++)
        {
            cout << ticketTable[x][y] << "  ";
        }

        cout << "\n\n";
    }
    cout << "Would you like to go back to the main menu (Y/N)?";
    cin >> answer;
    answer = toupper(answer); 
    if(answer=='Y') messagemenu();
    else view();
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
    do{
     i=messagemenu();
    (*options[i])();    
 
    }while(true);
   
    

    


    return 0;
}



//things to do 
// i loop yung program *checked*
// dapat ma loop program kahit sa options *checked*
// make reponsive menu pag inenter yung number dun kaagad pupunta *checked*
// dapat ma save na yung values sa database tapos mukhang ticket na malupet
// dapat ma check kung reserved or hindi pa
// dapat maka group reserve
//TAPOS TAPOS NA?