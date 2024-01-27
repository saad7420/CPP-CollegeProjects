//
//
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

void Design(char d) // all designs in output coded here
{
    if (d == 'e') // e: equal signed design
        cout << "\n====================================================================================================\n";
    else if (d == 'u')
        cout << "\n____________________________________________________________________________________________________\n";
    else if (d == 'd')
        cout << "\n----------------------------------------------------------------------------------------------------\n";
    else
        cout << "\n error : design not found!\n";
}

class Cinema // One & Only main class coded here
{
private:
public:
    Cinema() // constructor will check if previously any data available
    {
    }
};

int main()
{
    Cinema theatre;
    system("cls"); // each main menu will open in a fresh screen
    Design('e');
    cout << '|' << setw(51) << "TRIPLE\t\t 'AAA'\t\t\tCINEMA'S" << setw(20) << '|' << endl;
    cout << '|' << setw(99) << '|' << endl;
    cout << '|' << setw(64) << "MOVIE'S TICKET BOOKING SYSTEM" << setw(35) << '|';
    Design('e');
    cout << '|' << setw(99) << '|' << endl;
    cout << '|' << setw(99) << '|' << endl;
    cout << '|' << setw(99) << '|';
    cout << "\n|\t" << setw(48) << "1. Buy AAA Ticket" << setw(44) << '|';
    cout << "\n|\t" << setw(50) << "2. Visitor's Portal" << setw(42) << '|';
    cout << "\n|\t" << setw(51) << "3. Cinema Management" << setw(41) << '|' << endl;
    cout << '|' << setw(99) << '|' << endl;
    cout << '|' << setw(99) << '|' << endl;
    cin.get();
    return 0;
}
