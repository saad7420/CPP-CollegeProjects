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
    else if (d == 'u') // u: underline design
        cout << "\n____________________________________________________________________________________________________\n";
    else if (d == 'd') // d: dashes design
        cout << "\n----------------------------------------------------------------------------------------------------\n";
    else if (d == '0')
        cout << setw(20) << left << "MOVIE NAMES"
             << " | " << setw(12) << left << "DURATION(hr)"
             << " | " << setw(10) << left << "SHOW DATE"
             << " | " << setw(12) << left << "BOOKED SEATS"
             << " | " << left << "GENRE";
    else if (d == '1')
        cout << "\n\n---------------------|--------------|------------|--------------|--------\n";
    else if (d == '2')
        cout << "\n_____________________|______________|____________|______________|________\n";
    else
        cout << "\n error : design not found!\n";
}

class Cinema // One & Only main class coded here
{
private:
    // data members (private only, shared)
    string movieName, movieGenre, movieDate;
    int movieLength, peopleBooked = 0, totalSeats = 100, moviesCount;
    // parent functions (private only)
    void managerPortal() ////////////// cinemaManagement()'s menu
    {
        cout << setfill(' ') << setw(68) << ' '; // to clear the output stream
        char choice;
        system("cls");
        Design('e');
        cout << '|' << setw(51) << "TRIPLE\t\t 'AAA'\t\t\tCINEMA'S" << setw(20) << '|' << endl;
        cout << '|' << setw(99) << '|' << endl;
        cout << '|' << setw(64) << "MOVIE'S TICKET BOOKING SYSTEM" << setw(35) << '|' << endl;
        cout << '|' << setw(99) << '|' << endl;
        cout << '|' << setw(61) << "[ MANAGER     PORTAL ]" << setw(38) << '|' << endl;
        cout << '|' << setw(99) << '|';
        Design('e');
        cout << '|' << setw(99) << '|' << endl;
        cout << '|' << setw(99) << '|' << endl;
        cout << '|' << setw(99) << '|';
        cout << "\n|" << setw(65) << "1. Finance       Information" << setw(34) << '|';
        cout << "\n|" << setw(65) << "2. Movies & Seats Management" << setw(34) << '|';
        cout << "\n|" << setw(65) << "3. Account          settings" << setw(34) << '|';
        cout << "\n|" << setw(65) << "4. Back    to    main   menu" << setw(34) << '|';
        cout << "\n|" << setw(65) << "0. Exit    this      Program" << setw(34) << '|' << endl;
        cout << '|' << setw(99) << '|' << endl;
        cout << '|' << setw(99) << '|' << endl;
    gotoManagerMenu:
        cout << '|' << setfill('=') << setw(68) << '=';
        cout << "  Enter your choice here : ";
        cin >> choice;
        if (choice == '0')
        {
            cout << '|' << setfill('=') << setw(68) << '=';
            cout << "  Program Exited Successfully !\n\n\n\n";
            exit(0);
        }
        else if (choice == '1')
        {
            financeManagement();
            managerPortal();
        }
        else if (choice == '2')
        {
            MovieSeatsManagement();
            managerPortal();
        }
        else if (choice == '3')
        {
            accountManagement();
            managerPortal(); // self-call
        }
        else if (choice == '4')
        { // no need to code, automatically goes to main menu
        }
        else
        {
            cout << '|' << setfill('=') << setw(68) << '=';
            cout << "  ( error : invalid choice )  x\n";
            goto gotoManagerMenu;
        }
    }
    void financeManagement() ////// under construction
    {
        cout << setfill(' ') << setw(68) << ' '; // to clear the setfill() stream
        system("cls");
        char choice;
        cout << "\n\t\t\t\t       |  FINANCE  MANAGEMENT  |\n";
        cout << setw(40) << '|' << "_______________________|\n\n";
        cout << setw(40) << '1' << ". Display Finance Record\n";
        cout << setw(40) << '2' << ". Transactions of  Today\n";
        cout << setw(40) << '3' << ". Profit/Loss Estimation\n";
        cout << setw(40) << '4' << ". Back to Manager Portal\n";
        cout << setw(40) << '0' << ". Exit    this   Program\n";
    gotoFinanceManager:
        cout << setw(40) << '~' << "  Enter your choice here : ";
        cin >> choice;
        if (choice == '0')
        {
            cout << setw(40) << '~';
            cout << "  Program Exited Successfully !\n\n\n\n";
            exit(0);
        }
        else if (choice == '1')
        {
        }
        else if (choice == '2')
        {
        }
        else if (choice == '3')
        {
        }
        else if (choice == '4')
        { // no need to code, automatically goes to main menu
        }
        else
        {
            cout << setw(68) << '~';
            cout << "  (error : invalid choice)  x\n";
            goto gotoFinanceManager;
        }
    }
    void MovieSeatsManagement()
    {
        cout << " | " << setfill(' ') << setw(40) << ' '; // to clear the setfill() stream
        system("cls");
        char choice;
        cout << "\n\t\t\t\t        |     MOVIES  & SEATS    |\n";
        cout << setw(40) << ' ' << "|________________________|\n\n";
        cout << setw(40) << ' ' << "1. Display all Movies List\n"; // most booked + user demands
        cout << setw(40) << ' ' << "2. Display  Booked  Movies\n"; // current day schedule's fully occupied
        cout << setw(40) << ' ' << "3. Show   all    vacancies\n"; // rectilinear, deluxe, super deluxe
        cout << setw(40) << ' ' << "4. Update   Movies    List\n"; // add, delete, next, closed
        cout << setw(40) << ' ' << "5. Back to  Manager Portal\n";
        cout << setw(40) << ' ' << "0. Exit    this    Program\n";
    gotoMovieSeatsManagement:
        cout << setw(40) << ' ' << "~  Enter your choice here : ";
        cin >> choice;
        if (choice == '0')
        {
            cout << setw(40) << '~';
            cout << "  Program Exited Successfully !\n\n\n\n";
            exit(0);
        }
        else if (choice == '1')
        {
            displayAllMoviesList(); // displaying all movies list
            MovieSeatsManagement();
        }
        else if (choice == '2')
        {
            displayBookedMoviesList(); // displaying only Booked Movies
            MovieSeatsManagement();
        }
        else if (choice == '3')
        {
            showAllVacancies();
            MovieSeatsManagement();
        }
        else if (choice == '4')
        {
            updateMoviesList();
            MovieSeatsManagement();
        }
        else if (choice == '5')
        { // no need to code, automatically goes to main menu
        }
        else
        {
            cout << setw(68) << '~';
            cout << "  (error : invalid choice)  x\n";
            goto gotoMovieSeatsManagement;
        }
    }
    void accountManagement()
    {
        cout << " | " << setfill(' ') << setw(68) << ' '; // to clear the setfill() stream
        system("cls");
        char choice;
        cout << "\n\t\t\t\t       |   ACCOUNT  SETTINGS   |\n";
        cout << setw(40) << '|' << "_______________________|\n\n";
        cout << setw(40) << '1' << ". Add    new     account\n";
        cout << setw(40) << '2' << ". Show   all    accounts\n";
        cout << setw(40) << '3' << ". Back to Manager Portal\n";
        cout << setw(40) << '0' << ". Exit    this   Program\n";
    gotoAccountManager:
        cout << setw(40) << '~' << "  Enter your choice here : ";
        cin >> choice;
        if (choice == '0')
        {
            cout << setw(40) << '~';
            cout << "  Program Exited Successfully !\n\n\n\n";
            exit(0);
        }
        else if (choice == '1')
        {
            addNewAccount();
            accountManagement();
        }
        else if (choice == '2')
        {
            showAccounts();
            accountManagement();
        }
        else if (choice == '3')
        { // no need to code, automatically goes to main menu
        }
        else
        {
            cout << setw(68) << '~';
            cout << "  (error : invalid choice)  x\n";
            goto gotoAccountManager;
        }
    }

    // MovieSeatsManagement() childs
    void updateMoviesList() // add, update, delete, sort movies
    {
        system("cls");
        cout << setfill(' ') << setw(40) << ' '; // to clear the setfill() stream
        char choice;
        cout << "\n\t\t\t\t        |    UPDATE   MOVIES    |\n";
        cout << setw(40) << ' ' << "|_______________________|\n\n";
        cout << setw(40) << ' ' << "1. Add   a   new    movie\n";
        cout << setw(40) << ' ' << "2. Delete movie from list\n";
        cout << setw(40) << ' ' << "3. Reschedule   a   movie\n"; // one Movie per Day
        cout << setw(40) << ' ' << "4. Sort movies  (by name)\n";
        cout << setw(40) << ' ' << "5. Back to Manager Portal\n";
        cout << setw(40) << ' ' << "0. Exit   this    Program\n";
    gotoMovieSeatsManagement:
        cout << setw(40) << ' ' << "~  Enter your choice here : ";
        cin >> choice;
        if (choice == '0')
        {
            cout << setw(40) << '~';
            cout << "  Program Exited Successfully !\n\n\n\n";
            exit(0);
        }
        else if (choice == '1') // add movie
        {
            cout << "\n\n\n"; // getting data from manager
            cout << setw(40) << '~' << "  Enter Movie   Name :";
            cin.ignore();
            getline(cin, movieName);
            cout << setw(40) << '~' << "  Enter Movie  Genre :";
            getline(cin, movieGenre);
            cout << setw(40) << '~' << "  Date : (dd-mm-yyyy)\n";
            cout << setw(40) << '~' << "  Enter  Show   Date :";
            getline(cin, movieDate);
            cout << setw(40) << '~' << "  (Length in (hr) only)\n";
            cout << setw(40) << '~' << "  Enter Movie Length :";
            cin >> movieLength;
            ofstream write("D:\\moviesList.txt", ios::app); // writing into the file moviesList.txt
            write << movieName << endl
                  << movieGenre << endl
                  << movieDate << endl
                  << movieLength << endl
                  << peopleBooked << endl;
            write.close();
            updateMoviesList();
        }
        else if (choice == '2') // delete movie
        {
            ifstream read("D:\\moviesList.txt");
            if (!read) // if file not opened, if there is not data
            {
                cout << setw(40) << '~' << "  No Movies added yet.. \n";
                read.close();
                goto gotoMovieSeatsManagement;
            }
            else
            {
                string i_movieName, i_movieGenre; // getting data from manager
                bool movieFound = 0;
                cout << "\n\n\n";
                cout << setw(40) << '~' << "  Enter Movie   Name :";
                cin.ignore();
                getline(cin, i_movieName);
                transform(i_movieName.begin(), i_movieName.end(), i_movieName.begin(), ::tolower);
                cout << setw(40) << '~' << "  Enter Movie  Genre :";
                getline(cin, i_movieGenre);
                transform(i_movieGenre.begin(), i_movieGenre.end(), i_movieGenre.begin(), ::tolower);
                ofstream write("D:\\moviesListTempo.txt"); // to write data in a temp file in case of deletion
                getline(read, movieName);                  // reading data from file
                getline(read, movieGenre);
                getline(read, movieDate);
                read >> movieLength;
                read >> peopleBooked;
                while (!read.eof())
                {
                    transform(movieName.begin(), movieName.end(), movieName.begin(), ::tolower);
                    transform(movieGenre.begin(), movieGenre.end(), movieGenre.begin(), ::tolower);
                    if (movieName.find(i_movieName) < 41 && movieGenre.find(i_movieGenre) < 41)
                    {
                        movieFound = 1;
                        displayMoviesList();
                        cout << setw(40) << '~' << "  Delete? (y/n) : ";
                        cin >> choice;
                        if (choice == 'y' || choice == 'Y')
                        {
                            // do nothing, so this will be skipped
                            goto gotoMovieSkipped;
                        }
                    }
                    write << movieName << endl
                          << movieGenre << endl
                          << movieDate << endl
                          << movieLength << endl
                          << peopleBooked << endl;
                gotoMovieSkipped:
                    read.ignore();
                    getline(read, movieName); // reading data from file
                    getline(read, movieGenre);
                    getline(read, movieDate);
                    read >> movieLength;
                    read >> peopleBooked;
                }
                if (!movieFound)
                {
                    cout << setw(40) << '~' << "  Movie not found\n";
                    read.close();
                    write.close();
                    remove("D:\\moviesListTempo.txt");
                }
                else
                {
                    cout << setw(40) << '~' << "  Movie Deleted\n";
                    read.close();
                    write.close();
                    remove("D:\\moviesList.txt");
                    rename("D:\\moviesListTempo.txt", "D:\\moviesList.txt");
                }
                cout << setw(40) << '~' << "  ";
                system("pause");
            }
            updateMoviesList();
        }
        else if (choice == '3') // reschedule movie
        {
            ifstream read("D:\\moviesList.txt");
            if (!read) // if file not opened, if there is not data
            {
                cout << setfill(' ') << setw(40) << '~' << "  No Movies added yet.. \n";
                read.close();
                goto gotoMovieSeatsManagement;
            }
            else
            {
                string i_movieName, i_movieGenre; // getting data from manager
                bool movieFound = 0;
                cout << "\n\n\n";
                cout << setw(40) << '~' << "  Enter Movie   Name :";
                cin.ignore();
                getline(cin, i_movieName);
                transform(i_movieName.begin(), i_movieName.end(), i_movieName.begin(), ::tolower);
                cout << setw(40) << '~' << "  Enter Movie  Genre :";
                getline(cin, i_movieGenre);
                transform(i_movieGenre.begin(), i_movieGenre.end(), i_movieGenre.begin(), ::tolower);
                ofstream write("D:\\moviesListTempo.txt"); // to write data in a temp file in case of deletion
                getline(read, movieName);                  // reading data from file
                getline(read, movieGenre);
                getline(read, movieDate);
                read >> movieLength;
                read >> peopleBooked;
                while (!read.eof())
                {
                    transform(movieName.begin(), movieName.end(), movieName.begin(), ::tolower);
                    transform(movieGenre.begin(), movieGenre.end(), movieGenre.begin(), ::tolower);
                    if (movieName.find(i_movieName) < 41 && movieGenre.find(i_movieGenre) < 41)
                    {
                        movieFound = 1;
                        displayMoviesList();
                        cout << setw(40) << '~' << "  Reschedule? (y/n) : ";
                        cin >> choice;
                        if (choice == 'y' || choice == 'Y')
                        {
                            cout << setw(40) << '~' << "  Enter new Date : ";
                            cin.ignore();
                            getline(cin, movieDate); // the new/updated movie date for schedule
                        }
                    }
                    write << movieName << endl
                          << movieGenre << endl
                          << movieDate << endl
                          << movieLength << endl
                          << peopleBooked << endl;
                    read.ignore();
                    getline(read, movieName); // reading data from file
                    getline(read, movieGenre);
                    getline(read, movieDate);
                    read >> movieLength;
                    read >> peopleBooked;
                }
                if (!movieFound)
                {
                    cout << setw(40) << '~' << "  Movie not found\n";
                    read.close();
                    write.close();
                    remove("D:\\moviesListTempo.txt");
                }
                else
                {
                    cout << setw(40) << '~' << "  Movie Updated\n";
                    read.close();
                    write.close();
                    remove("D:\\moviesList.txt");
                    rename("D:\\moviesListTempo.txt", "D:\\moviesList.txt");
                }
                cout << setw(40) << '~' << "  ";
                system("pause");
            }
            updateMoviesList();
        }
        else if (choice == '4') // sorting by name
        {
            ifstream read("D:\\moviesList.txt"); // 1st attempt to count movies
            if (!read)
            {
                cout << setw(40) << '~' << "  No movies added yet... \n";
                read.close();
                goto gotoMovieSeatsManagement;
            }
            string ar_movieNames[moviesCount], tempName; // moviesCount used in constructor
            int i = 0, x, y;
            getline(read, movieName); // now storing all available movie names in an array for sorting
            getline(read, movieGenre);
            getline(read, movieDate);
            read >> movieLength;
            read >> peopleBooked;
            while (!read.eof()) // storing movie names in array
            {
                ar_movieNames[i] = movieName;
                i++;
                read.ignore();
                getline(read, movieName);
                getline(read, movieGenre);
                getline(read, movieDate);
                read >> movieLength;
                read >> peopleBooked;
            }
            read.close();
            for (i = 0; i < moviesCount - 1; i++) // sorting movie names in array
            {
                for (x = i + 1; x < moviesCount; x++)
                {
                    if (ar_movieNames[i] > ar_movieNames[x])
                    {
                        tempName = ar_movieNames[i];
                        ar_movieNames[i] = ar_movieNames[x];
                        ar_movieNames[x] = tempName;
                    }
                }
            }
            ofstream write("D:\\moviesListSorted.txt", ios::app);
            for (x = 0; x < moviesCount; x++) // saving sorted data into the file
            {
                read.open("D:\\moviesList.txt");
                getline(read, movieName);
                getline(read, movieGenre);
                getline(read, movieDate);
                read >> movieLength;
                read >> peopleBooked;
                while (!read.eof())
                {
                    if (movieName == ar_movieNames[x])
                    {
                        write << movieName << endl
                              << movieGenre << endl
                              << movieDate << endl
                              << movieLength << endl
                              << peopleBooked << endl;
                    }
                    read.ignore();
                    getline(read, movieName);
                    getline(read, movieGenre);
                    getline(read, movieDate);
                    read >> movieLength;
                    read >> peopleBooked;
                }
                read.close();
            }
            read.close();
            write.close();
            remove("D:\\moviesList.txt");
            rename("D:\\moviesListSorted.txt", "D:\\moviesList.txt");
            cout << endl;
            cout << setw(40) << ' ' << "~  Sorted Alphabetically!\n";
            cout << setw(40) << ' ' << "~  ";
            system("pause");
            updateMoviesList();
        }
        else if (choice == '5')
        { // no need to code, automatically goes to main menu
        }
        else
        {
            cout << setw(68) << '~';
            cout << "  (error : invalid choice)  x\n";
            goto gotoMovieSeatsManagement;
        }
    }
    void displayMoviesList() // by-request of functions
    {
        cout << " | " << setfill(' ') << setw(40) << ' '; // to clear the setfill() stream
        system("cls");
        cout << endl
             << setw(25) << '|' << "     DISPLAY  MOVIES   |\n"
             << setw(25) << '|' << "_______________________|\n";
        Design('1');
        Design('0');
        Design('2');
        cout << setw(20) << left << movieName
             << " | " << setw(12) << left << movieLength
             << " | " << setw(10) << left << movieDate
             << " | " << setw(12) << left << peopleBooked
             << " | " << left << movieGenre << endl
             << endl;
    }
    void displayAllMoviesList() // by-user demand
    {
        system("cls");
        cout << endl
             << setw(25) << '|' << "     MOVIES    LIST    |\n"
             << setw(25) << '|' << "_______________________|\n"; // printing the upper layout design
        Design('1');
        Design('0');
        Design('2');
        ifstream read("D:\\moviesList.txt"); // opens read file
        if (!read)
        {
            cout << "\n\t\t\t\terror: File not accessible";
            read.close();
            cout << "\n\t\t\t\t";
            system("pause");
        }
        else // if file is accessible
        {
            getline(read, movieName);
            getline(read, movieGenre);
            getline(read, movieDate);
            read >> movieLength;
            read >> peopleBooked;
            while (!read.eof())
            {
                cout << setw(20) << left << movieName
                     << " | " << setw(12) << left << movieLength
                     << " | " << setw(10) << left << movieDate
                     << " | " << setw(12) << left << peopleBooked
                     << " | " << left << movieGenre << endl; // prints the read data on screen
                read.ignore();
                getline(read, movieName);
                getline(read, movieGenre);
                getline(read, movieDate);
                read >> movieLength;
                read >> peopleBooked;
            }
        }
        read.close();
        cout << "\n\n\n\t\t\t\t";
        system("pause");
    }
    void displayBookedMoviesList() // only booked movies
    {
        system("cls");
        cout << endl
             << setw(25) << '|' << "   BOOKED     MOVIES   |\n"
             << setw(25) << '|' << "_______________________|\n"; // printing the upper layout design
        Design('1');
        Design('0');
        Design('2');
        ifstream read("D:\\moviesList.txt"); // opens read file
        if (!read)
        {
            cout << "\n\t\t\t\terror: File not accessible";
            read.close();
            cout << "\n\t\t\t\t";
            system("pause");
        }
        else // if file is accessible
        {
            getline(read, movieName);
            getline(read, movieGenre);
            getline(read, movieDate);
            read >> movieLength;
            read >> peopleBooked;
            while (!read.eof())
            {
                if (peopleBooked > 0)
                {
                    cout << setw(20) << left << movieName
                         << " | " << setw(12) << left << movieLength
                         << " | " << setw(10) << left << movieDate
                         << " | " << setw(12) << left << peopleBooked
                         << " | " << left << movieGenre << endl; // prints the read data on screen
                }
                read.ignore();
                getline(read, movieName);
                getline(read, movieGenre);
                getline(read, movieDate);
                read >> movieLength;
                read >> peopleBooked;
            }
        }
        read.close();
        cout << "\n\n\n\t\t\t\t";
        system("pause");
    }
    void showAllVacancies() // to show all available seats details
    {
        system("cls");
        ifstream read("D:\\moviesList.txt"); // opens read file
        if (!read)
        {
            cout << "\n\t\t\t\terror: File not accessible";
            read.close();
            cout << "\n\t\t\t\t";
            system("pause");
        }
        else // if file is accessible
        {
            cout << endl
                 << setw(15) << ' ' << "|   SEATS   AVAILABLE   |\n"
                 << setw(15) << ' ' << "|_______________________|\n"; // printing the upper layout design
            cout << "\n\n---------------------|------------|--------------\n";
            cout << setw(20) << left << "MOVIE NAMES"
                 << " | " << setw(10) << left << "SHOW DATE"
                 << " | " << setw(12) << left << "VACANT SEATS";
            cout << "\n_____________________|____________|______________\n";
            getline(read, movieName);
            getline(read, movieGenre);
            getline(read, movieDate);
            read >> movieLength;
            read >> peopleBooked;
            while (!read.eof())
            {
                cout << setw(20) << left << movieName
                     << " | " << setw(10) << left << movieDate
                     << " | " << setw(12) << left << totalSeats - peopleBooked << endl; // prints the read data on screen
                read.ignore();
                getline(read, movieName);
                getline(read, movieGenre);
                getline(read, movieDate);
                read >> movieLength;
                read >> peopleBooked;
            }
        }
        read.close();
        cout << "\n\n\n\t\t";
        system("pause");
    }

    // accountManagement() childs
    void addNewAccount()
    {
        string name, password;
        int identityNo;
        char choice;
    gotoAddNewAccount:
        cout << "\n\t\t\t\t\t[ NEW ACCOUNT ] \n\n\n";
        cout << '|' << setfill('=') << setw(68) << '=';
        cout << "  Enter      Name   :: ";
        cin.ignore();
        getline(cin, name);
        cout << '|' << setfill('=') << setw(68) << '=';
        cout << "  Create Password   :: ";
        getline(cin, password);
        cout << '|' << setfill('=') << setw(68) << '=';
        cout << "  Enter id number   :: ";
        cin >> identityNo;
        cout << "\n\n|" << setw(68) << '~';
        cout << "  (Enter '0' to exit )\n";
        cout << '|' << setw(68) << '~';
        cout << "  CONFIRMED? (y/n/0) : ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') // new account created
        {
            ofstream create("D:\\managerInfo.txt", ios::app); // file is created only if user wants
            if (!create)
                create.close();
            else
            {
                create << name << endl;
                create << password << endl;
                create << identityNo << endl;
                create.close();
                cout << "\n\n|" << setw(68) << '~';
                cout << "  Signed up successfully!";
                cout << "\n|" << setw(70) << "~  ";
                system("pause");
            }
        }
        else if (choice == 'n' || choice == 'N')
        {
            system("cls");
            goto gotoAddNewAccount;
        }
        else
            remove("D:\\managerInfo.txt");
    }
    void showAccounts()
    {
        system("cls");
        string userName, userPassword;
        int identityNo;
        ifstream read("D:\\managerInfo.txt");
        if (!read)
            read.close();
        else
        {
            cout << setw(25) << left << "      usernames" << setw(15) << left << "identities\n";
            cout << "____________________________________\n\n";
            getline(read, userName);
            getline(read, userPassword);
            read >> identityNo;
            while (!read.eof())
            {
                cout << "    " << setw(25) << left << userName.substr(0, 25) << setw(15) << identityNo << endl;
                read.ignore();
                getline(read, userName);
                getline(read, userPassword);
                read >> identityNo;
            }
            read.close();
            cout << endl
                 << setw(13) << ' ';
            system("pause");
        }
    }

public:
    Cinema() // constructor to check previous record, movies counting
    {
        ifstream read("D:\\moviesList.txt");
        if (!read)
        {
            read.close();
        }
        else
        {
            moviesCount = 0;
            getline(read, movieName);
            getline(read, movieGenre);
            getline(read, movieDate);
            read >> movieLength;
            read >> peopleBooked;
            while (!read.eof())
            {
                ++moviesCount;
                read.ignore();
                getline(read, movieName);
                getline(read, movieGenre);
                getline(read, movieDate);
                read >> movieLength;
                read >> peopleBooked;
            }
            read.close();
        }
    }
    void buyTicket()
    {
    }
    void visitorsPortal()
    {
    }
    void cinemaManagement()
    {
        cout << " | " << setfill(' ') << setw(68) << ' '; // to clear the setfill() stream
        system("cls");
        string name, password;
        int identityNo;
        char choice;
        ifstream read("D:\\managerInfo.txt");
        if (!read.is_open()) // Sign up: since no previous account.
        {
        gotoManagerSignup:
            cout << "\n\t\t\t\t\t[ SIGN UP ] \n\n\n";
            cout << '|' << setfill('=') << setw(68) << '=';
            cout << "  Enter      Name   :: ";
            cin.ignore();
            getline(cin, name);
            cout << '|' << setfill('=') << setw(68) << '=';
            cout << "  Create Password   :: ";
            getline(cin, password);
            cout << '|' << setfill('=') << setw(68) << '=';
            cout << "  Enter id number   :: ";
            cin >> identityNo;
            cout << "\n\n|" << setfill(' ') << setw(68) << '~';
            cout << "  (Enter '0' to exit )\n";
            cout << '|' << setfill(' ') << setw(68) << '~';
            cout << "  CONFIRMED? (y/n/0) : ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y') // new account created
            {
                ofstream create("D:\\managerInfo.txt"); // file is created only if user wants
                if (!create.is_open())
                {
                    cout << '\n';
                    cout << '|' << setfill('=') << setw(68) << '=';
                    cout << "  (error : File not accessible) x\n";
                    read.close();
                    create.close();
                    exit(0);
                }
                create << name << endl;
                create << password << endl;
                create << identityNo << endl;
                read.close();
                create.close();
                cout << "\n\n|" << setfill(' ') << setw(68) << '~';
                cout << "  Signed up successfully!";
                cout << "\n|" << setfill(' ') << setw(70) << "~  ";
                system("pause");
                managerPortal(); // allows manager portal access
            }
            else if (choice == 'n' || choice == 'N')
            {
                system("cls");
                goto gotoManagerSignup;
            }
            else
            {
                read.close();
                remove("D:\\managerInfo.txt");
            } // towards main menu in main()
        }
        else // Sign in: since previous record found
        {
            int count = 0;
            cout << "\n\n|" << setfill(' ') << setw(68) << '~';
            cout << "  Enter '0' to exit to  main menu\n";
            cout << '|' << setfill(' ') << setw(68) << '~';
            cout << "  Want to Log in? ( y / n / 0 ) : ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y')
            {
            gotoManagerLogin:
                system("cls");
                string i_name, i_password; // user-inputted name, password & identity number
                int i_identityNo;
                cout << "\n\t\t\t\t\t [ LOG IN ]\n\n\n";        // getting user inputs for authentication
                cout << '|' << setfill('=') << setw(68) << '='; // input's design
                cout << "  Enter      Name    :: ";
                cin.ignore();
                getline(cin, i_name);
                transform(i_name.begin(), i_name.end(), i_name.begin(), ::tolower);
                cout << '|' << setfill('=') << setw(68) << '=';
                cout << "  Enter  Password    :: ";
                getline(cin, i_password);
                cout << '|' << setfill('=') << setw(68) << '=';
                cout << "  Enter id number    :: ";
                cin >> i_identityNo;
                count++;             // to count the password input tries
                getline(read, name); // reading present data from file: managerInfo.txt
                getline(read, password);
                read >> identityNo;
                while (!read.eof())
                {
                    transform(name.begin(), name.end(), name.begin(), ::tolower);
                    if (password == i_password && (identityNo == i_identityNo || name.find(i_name) < 41)) // password is must
                    {
                        read.close();
                        cout << "\n\n|" << setfill(' ') << setw(68) << '~' << "  Access Granted !";
                        cout << "\n|" << setfill(' ') << setw(70) << "~  ";
                        system("pause");
                        managerPortal(); // allows manager portal access
                    }
                    else
                    {
                        if (count > 3)
                        {
                            read.close();
                            cout << "|" << setfill(' ') << setw(68) << '~' << "  error : password input limit reached!\n";
                            cout << "|" << setfill(' ') << setw(70) << "~  ";
                            system("pause");
                            exit(0);
                        }
                        read.ignore();
                        getline(read, name); // reading present data from file: managerInfo.txt
                        getline(read, password);
                        read >> identityNo;
                    }
                }
                cout << "\n\n|" << setfill(' ') << setw(68) << '~' << "  Access Denied !";
                cout << "\n|" << setfill(' ') << setw(68) << '~' << "  error : wrong input!\n";
                goto gotoManagerLogin;
            }
            else if (choice == '0')
            {
                read.close(); // way to main menu : main()
            }
            else
            {
                system("cls");
                goto gotoManagerLogin;
            }
        }
    }
};

int main()
{
    cout << " | " << setfill(' ') << setw(68) << ' '; // to clear the setfill() stream
    system("cls");                                    // each main menu will open in a fresh screen
    Cinema theatre;
    char choice;
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
    cout << "\n|\t" << setw(51) << "3. Cinema Management" << setw(41) << '|';
    cout << "\n|\t" << setw(51) << "0. Exit this Program" << setw(41) << '|' << endl;
    cout << '|' << setw(99) << '|' << endl;
    cout << '|' << setw(99) << '|' << endl;
gotoMainMenu:
    cout << '|' << setfill('=') << setw(68) << '=';
    cout << "  Enter your choice here : ";
    cin >> choice;
    if (choice == '0')
    {
        cout << '|' << setfill('=') << setw(68) << '=';
        cout << "  Program Exited Successfully !\n\n\n\n";
        exit(0);
    }
    else if (choice == '1')
    {
    }
    else if (choice == '2')
    {
    }
    else if (choice == '3') // cinema manager portal
    {
        theatre.cinemaManagement();
        main();
    }
    else
    {
        cout << '|' << setfill('=') << setw(68) << '=';
        cout << "  ( error : invalid choice )  x\n";
        goto gotoMainMenu;
    }
    return 0;
}
