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
    else
        cout << "\n error : design not found!\n";
}

class Cinema // One & Only main class coded here
{
private:
    // data members (private only, shared)
    string movieName, movieGenre, movieDate;
    int movieLength;
    // parent functions (private only)
    void managerPortal() //////////////////    completed
    {
        cout << '|' << setfill(' ') << setw(68) << ' '; // to clear the output stream
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
        cout << "\n|" << setw(65) << "3. Clients Record Management" << setw(34) << '|';
        cout << "\n|" << setw(65) << "4. Account          settings" << setw(34) << '|';
        cout << "\n|" << setw(65) << "5. Back    to    main   menu" << setw(34) << '|';
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
            ClientsRecordManagement();
            managerPortal();
        }
        else if (choice == '4')
        {
            accountManagement();
            managerPortal(); // self-call
        }
        else if (choice == '5')
        { // no need to code, automatically goes to main menu
        }
        else
        {
            cout << '|' << setfill('=') << setw(68) << '=';
            cout << "  ( error : invalid choice )  x\n";
            goto gotoManagerMenu;
        }
    }
    void financeManagement()
    {
        system("cls");
        char choice;
        cout << "\n\t\t\t\t       |  FINANCE  MANAGEMENT  |\n";
        cout << setfill(' ') << setw(40) << '|' << "_______________________|\n\n";
        cout << setfill(' ') << setw(40) << '1' << ". Display Finance Record\n";
        cout << setfill(' ') << setw(40) << '2' << ". Transactions of  Today\n";
        cout << setfill(' ') << setw(40) << '3' << ". Profit/Loss Estimation\n";
        cout << setfill(' ') << setw(40) << '4' << ". Back to Manager Portal\n";
        cout << setfill(' ') << setw(40) << '0' << ". Exit    this   Program\n";
    gotoFinanceManager:
        cout << setfill(' ') << setw(40) << '~' << "  Enter your choice here : ";
        cin >> choice;
        if (choice == '0')
        {
            cout << setfill(' ') << setw(40) << '~';
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
            cout << setfill(' ') << setw(68) << '~';
            cout << "  (error : invalid choice)  x\n";
            goto gotoFinanceManager;
        }
    }
    void MovieSeatsManagement()
    {
        system("cls");
        char choice;
        cout << "\n\t\t\t\t       |    MOVIES  & SEATS    |\n";
        cout << setfill(' ') << setw(40) << '|' << "_______________________|\n\n";
        cout << setfill(' ') << setw(40) << '1' << ". Display all Movies List\n"; // most booked + user demands
        cout << setfill(' ') << setw(40) << '2' << ". Display  Booked  Movies\n"; // current day schedule's fully occupied
        cout << setfill(' ') << setw(40) << '3' << ". Show   all    vacancies\n"; // rectilinear, deluxe, super deluxe
        cout << setfill(' ') << setw(40) << '4' << ". Update   Movies    List\n"; // add, delete, next, closed
        cout << setfill(' ') << setw(40) << '5' << ". Update the     Schedule\n"; // movies, timing, arrangements, date
        cout << setfill(' ') << setw(40) << '6' << ". Back to  Manager Portal\n";
        cout << setfill(' ') << setw(40) << '0' << ". Exit    this    Program\n";
    gotoMovieSeatsManagement:
        cout << setfill(' ') << setw(40) << '~' << "  Enter your choice here : ";
        cin >> choice;
        if (choice == '0')
        {
            cout << setfill(' ') << setw(40) << '~';
            cout << "  Program Exited Successfully !\n\n\n\n";
            exit(0);
        }
        else if (choice == '1')
        {
            MovieSeatsManagement();
        }
        else if (choice == '2')
        {
            MovieSeatsManagement();
        }
        else if (choice == '3')
        {
            MovieSeatsManagement();
        }
        else if (choice == '4')
        {
            updateMoviesList();
            MovieSeatsManagement();
        }
        else if (choice == '5')
        {
            MovieSeatsManagement();
        }
        else if (choice == '6')
        { // no need to code, automatically goes to main menu
        }
        else
        {
            cout << setfill(' ') << setw(68) << '~';
            cout << "  (error : invalid choice)  x\n";
            goto gotoMovieSeatsManagement;
        }
    }
    void ClientsRecordManagement()
    {
        system("cls");
        char choice;
        cout << "\n\t\t\t\t       |   RECORD MANAGEMENT   |\n";
        cout << setfill(' ') << setw(40) << '|' << "_______________________|\n\n\n";
        cout << setfill(' ') << setw(40) << '1' << ". Display Clients Record\n";
        cout << setfill(' ') << setw(40) << '2' << ". Daily Schedules Record\n";
        cout << setfill(' ') << setw(40) << '3' << ". Display Finance record\n";
        cout << setfill(' ') << setw(40) << '4' << ". Back to Manager Portal\n";
        cout << setfill(' ') << setw(40) << '0' << ". Exit    this   Program\n";
    gotoClientsRecordManagement:
        cout << setfill(' ') << setw(40) << '~' << "  Enter your choice here : ";
        cin >> choice;
        if (choice == '0')
        {
            cout << setfill(' ') << setw(40) << '~';
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
            cout << setfill(' ') << setw(68) << '~';
            cout << "  (error : invalid choice)  x\n";
            goto gotoClientsRecordManagement;
        }
    }
    void accountManagement()
    {
        system("cls");
        char choice;
        cout << "\n\t\t\t\t       |   ACCOUNT  SETTINGS   |\n";
        cout << setfill(' ') << setw(40) << '|' << "_______________________|\n\n";
        cout << setfill(' ') << setw(40) << '1' << ". Add    new     account\n";
        cout << setfill(' ') << setw(40) << '2' << ". Update current account\n";
        cout << setfill(' ') << setw(40) << '3' << ". Delete current account\n";
        cout << setfill(' ') << setw(40) << '4' << ". Show   all    accounts\n";
        cout << setfill(' ') << setw(40) << '5' << ". Back to Manager Portal\n";
        cout << setfill(' ') << setw(40) << '0' << ". Exit    this   Program\n";
    gotoAccountManager:
        cout << setfill(' ') << setw(40) << '~' << "  Enter your choice here : ";
        cin >> choice;
        if (choice == '0')
        {
            cout << setfill(' ') << setw(40) << '~';
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
            cout << setfill(' ') << setw(68) << '~';
            cout << "  (error : invalid choice)  x\n";
            goto gotoAccountManager;
        }
    }

    // child functions
    void updateMoviesList() ////////////////// completed
    {
        system("cls");
        char choice;
        cout << "\n\t\t\t\t       |    UPDATE   MOVIES    |\n";
        cout << setfill(' ') << setw(40) << '|' << "_______________________|\n\n";
        cout << setfill(' ') << setw(40) << '1' << ". Add   a   new    movie\n";
        cout << setfill(' ') << setw(40) << '2' << ". Delete movie from list\n";
        cout << setfill(' ') << setw(40) << '3' << ". Reschedule   a   movie\n";
        cout << setfill(' ') << setw(40) << '4' << ". Sort movies  (by name)\n";
        cout << setfill(' ') << setw(40) << '5' << ". Back to  Manager Portal\n";
        cout << setfill(' ') << setw(40) << '0' << ". Exit    this    Program\n";
    gotoMovieSeatsManagement:
        cout << setfill(' ') << setw(40) << '~' << "  Enter your choice here : ";
        cin >> choice;
        if (choice == '0')
        {
            cout << setfill(' ') << setw(40) << '~';
            cout << "  Program Exited Successfully !\n\n\n\n";
            exit(0);
        }
        else if (choice == '1') // add movie
        {
            cout << "\n\n\n"; // getting data from manager
            cout << setfill(' ') << setw(40) << '~' << "  Enter Movie   Name :";
            cin.ignore();
            getline(cin, movieName);
            cout << setfill(' ') << setw(40) << '~' << "  Enter Movie  Genre :";
            getline(cin, movieGenre);
            cout << setfill(' ') << setw(40) << '~' << "  Date : (dd-mm-yyyy)\n";
            cout << setfill(' ') << setw(40) << '~' << "  Enter  Show   Date :";
            getline(cin, movieDate);
            cout << setfill(' ') << setw(40) << '~' << "  (Length in (hr) only)\n";
            cout << setfill(' ') << setw(40) << '~' << "  Enter Movie Length :";
            cin >> movieLength;
            ofstream write("D:\\moviesList.txt", ios::app); // writing into the file moviesList.txt
            write << movieName << endl
                  << movieGenre << endl
                  << movieDate << endl
                  << movieLength << endl;
            write.close();
            updateMoviesList();
        }
        else if (choice == '2') // delete movie
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
                cout << setfill(' ') << setw(40) << '~' << "  Enter Movie   Name :";
                cin.ignore();
                getline(cin, i_movieName);
                transform(i_movieName.begin(), i_movieName.end(), i_movieName.begin(), ::tolower);
                cout << setfill(' ') << setw(40) << '~' << "  Enter Movie  Genre :";
                getline(cin, i_movieGenre);
                transform(i_movieGenre.begin(), i_movieGenre.end(), i_movieGenre.begin(), ::tolower);
                ofstream write("D:\\moviesListTempo.txt"); // to write data in a temp file in case of deletion
                getline(read, movieName);                  // reading data from file
                getline(read, movieGenre);
                getline(read, movieDate);
                read >> movieLength;
                while (!read.eof())
                {
                    transform(movieName.begin(), movieName.end(), movieName.begin(), ::tolower);
                    transform(movieGenre.begin(), movieGenre.end(), movieGenre.begin(), ::tolower);
                    if (movieName.find(i_movieName) < 41 && movieGenre.find(i_movieGenre) < 41)
                    {
                        movieFound = 1;
                        cout << setfill(' ') << setw(40) << '~' << "  Delete? (y/n) : ";
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
                          << movieLength << endl;
                gotoMovieSkipped:
                    read.ignore();
                    getline(read, movieName); // reading data from file
                    getline(read, movieGenre);
                    getline(read, movieDate);
                    read >> movieLength;
                }
                if (!movieFound)
                {
                    cout << setfill(' ') << setw(40) << '~' << "  Movie not found\n";
                    read.close();
                    write.close();
                    remove("D:\\moviesListTempo.txt");
                }
                else
                {
                    cout << setfill(' ') << setw(40) << '~' << "  Movie Deleted\n";
                    read.close();
                    write.close();
                    remove("D:\\moviesList.txt");
                    rename("D:\\moviesListTempo.txt", "D:\\moviesList.txt");
                }
                cout << setfill(' ') << setw(40) << '~' << "  ";
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
                cout << setfill(' ') << setw(40) << '~' << "  Enter Movie   Name :";
                cin.ignore();
                getline(cin, i_movieName);
                transform(i_movieName.begin(), i_movieName.end(), i_movieName.begin(), ::tolower);
                cout << setfill(' ') << setw(40) << '~' << "  Enter Movie  Genre :";
                getline(cin, i_movieGenre);
                transform(i_movieGenre.begin(), i_movieGenre.end(), i_movieGenre.begin(), ::tolower);
                ofstream write("D:\\moviesListTempo.txt"); // to write data in a temp file in case of deletion
                getline(read, movieName);                  // reading data from file
                getline(read, movieGenre);
                getline(read, movieDate);
                read >> movieLength;
                while (!read.eof())
                {
                    transform(movieName.begin(), movieName.end(), movieName.begin(), ::tolower);
                    transform(movieGenre.begin(), movieGenre.end(), movieGenre.begin(), ::tolower);
                    if (movieName.find(i_movieName) < 41 && movieGenre.find(i_movieGenre) < 41)
                    {
                        movieFound = 1;
                        cout << setfill(' ') << setw(40) << '~' << "  Reschedule? (y/n) : ";
                        cin >> choice;
                        if (choice == 'y' || choice == 'Y')
                        {
                            cout << setfill(' ') << setw(40) << '~' << "  Enter new Date : ";
                            cin.ignore();
                            getline(cin, movieDate); // the new/updated movie date for schedule
                        }
                    }
                    write << movieName << endl
                          << movieGenre << endl
                          << movieDate << endl
                          << movieLength << endl;
                    read.ignore();
                    getline(read, movieName); // reading data from file
                    getline(read, movieGenre);
                    getline(read, movieDate);
                    read >> movieLength;
                }
                if (!movieFound)
                {
                    cout << setfill(' ') << setw(40) << '~' << "  Movie not found\n";
                    read.close();
                    write.close();
                    remove("D:\\moviesListTempo.txt");
                }
                else
                {
                    cout << setfill(' ') << setw(40) << '~' << "  Movie Deleted\n";
                    read.close();
                    write.close();
                    remove("D:\\moviesList.txt");
                    rename("D:\\moviesListTempo.txt", "D:\\moviesList.txt");
                }
                cout << setfill(' ') << setw(40) << '~' << "  ";
                system("pause");
            }
            updateMoviesList();
        }
        else if (choice == '4') // sorting by name
        {
            int count = 0;                       // to count the movies number
            ifstream read("D:\\moviesList.txt"); // 1st attempt to count movies
            if (!read)
            {
                cout << setfill(' ') << setw(40) << '~' << "  No movies added yet... \n";
                read.close();
                goto gotoMovieSeatsManagement;
            }
            else
            {
                count = 0;
                getline(read, movieName);
                getline(read, movieGenre);
                getline(read, movieDate);
                read >> movieLength;
                while (!read.eof())
                {
                    ++count;
                    read.ignore();
                    getline(read, movieName);
                    getline(read, movieGenre);
                    getline(read, movieDate);
                    read >> movieLength;
                }
                read.close();
            }
            string ar_movieNames[count], tempName;
            int i = 0, x, y;
            read.open("D:\\moviesList.txt");
            getline(read, movieName); // now storing all available movie names in an array for sorting
            getline(read, movieGenre);
            getline(read, movieDate);
            read >> movieLength;
            while (!read.eof())
            {
                ar_movieNames[i] = movieName;
                i++;
                read.ignore();
                getline(read, movieName);
                getline(read, movieGenre);
                getline(read, movieDate);
                read >> movieLength;
            }
            read.close();
            for (i = 0; i < count - 1; i++) // sorting movie names in array
            {
                for (x = i + 1; x < count; x++)
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
            for (x = 0; x < count; x++) // saving sorted data into the file
            {
                read.open("D:\\moviesList.txt");
                read.ignore();
                getline(read, movieName);
                getline(read, movieGenre);
                getline(read, movieDate);
                read >> movieLength;
                while (!read.eof())
                {
                    if (movieName == ar_movieNames[x])
                    {
                        write << movieName << endl
                              << movieGenre << endl
                              << movieDate << endl
                              << movieLength << endl;
                    }
                    read.ignore();
                    getline(read, movieName);
                    getline(read, movieGenre);
                    getline(read, movieDate);
                    read >> movieLength;
                }
                read.close();
            }
            read.close();
            write.close();
            remove("D:\\moviesList.txt");
            rename("D:\\moviesListSorted.txt", "D:\\moviesList.txt");
            cout << endl;
            cout << setfill(' ') << setw(40) << '~' << "  Sorted Alphabetically!\n";
            cout << setfill(' ') << setw(40) << '~' << "  ";
            system("pause");
            updateMoviesList();
        }
        else if (choice == '5')
        { // no need to code, automatically goes to main menu
        }
        else
        {
            cout << setfill(' ') << setw(68) << '~';
            cout << "  (error : invalid choice)  x\n";
            goto gotoMovieSeatsManagement;
        }
    }

public:
    Cinema() // constructor will check if previously any data available
    {
    }
    void buyTicket()
    {
    }
    void visitorsPortal()
    {
    }
    void cinemaManagement()
    {
        managerPortal();
        // system("cls");
        // string name, password;
        // int identityNo;
        // char choice;
        // ifstream read("D:\\managerInfo.txt");
        // if (!read.is_open()) // Sign up: since no previous account.
        // {
        // gotoManagerSignup:
        //     cout << "\n\t\t\t\t\t[ SIGN UP ] \n\n\n";
        //     cout << '|' << setfill('=') << setw(68) << '=';
        //     cout << "  Enter      Name   :: ";
        //     cin.ignore();
        //     getline(cin, name);
        //     cout << '|' << setfill('=') << setw(68) << '=';
        //     cout << "  Create Password   :: ";
        //     getline(cin, password);
        //     cout << '|' << setfill('=') << setw(68) << '=';
        //     cout << "  Enter id number   :: ";
        //     cin >> identityNo;
        //     cout << "\n\n|" << setfill(' ') << setw(68) << '~';
        //     cout << "  (Enter '0' to exit )\n";
        //     cout << '|' << setfill(' ') << setw(68) << '~';
        //     cout << "  CONFIRMED? (y/n/0) : ";
        //     cin >> choice;
        //     if (choice == 'y' || choice == 'Y') // new account created
        //     {
        //         ofstream create("D:\\managerInfo.txt"); // file is created only if user wants
        //         if (!create.is_open())
        //         {
        //             cout << '\n';
        //             cout << '|' << setfill('=') << setw(68) << '=';
        //             cout << "  (error : File not accessible) x\n";
        //             read.close();
        //             create.close();
        //             exit(0);
        //         }
        //         create << name << endl;
        //         create << password << endl;
        //         create << identityNo << endl;
        //         read.close();
        //         create.close();
        //         cout << "\n\n|" << setfill(' ') << setw(68) << '~';
        //         cout << "  Signed up successfully!";
        //         cout << "\n|" << setfill(' ') << setw(70) << "~  ";
        //         system("pause");
        //         managerPortal(); // allows manager portal access
        //     }
        //     else if (choice == 'n' || choice == 'N')
        //     {
        //         system("cls");
        //         goto gotoManagerSignup;
        //     }
        //     else
        //     {
        //         read.close();
        //         remove("D:\\managerInfo.txt");
        //     } // towards main menu in main()
        // }
        // else // Sign in: since previous record found
        // {
        //     int count = 0;
        //     getline(read, name); // reading present data from file: managerInfo.txt
        //     getline(read, password);
        //     read >> identityNo;
        // gotoManagerLogin:
        //     cout << "\n\n|" << setfill(' ') << setw(68) << '~';
        //     cout << "  Enter '0' to exit to  main menu\n";
        //     cout << '|' << setfill(' ') << setw(68) << '~';
        //     cout << "  Want to Log in? ( y / n / 0 ) : ";
        //     cin >> choice;
        //     if (choice == 'y' || choice == 'Y')
        //     {
        //         system("cls");
        //         string i_name, i_password; // user-inputted name, password & identity number
        //         int i_identityNo;
        //         cout << "\n\t\t\t\t\t [ LOG IN ]\n\n\n";        // getting user inputs for authentication
        //         cout << '|' << setfill('=') << setw(68) << '='; // input's design
        //         cout << "  Enter      Name    :: ";
        //         cin.ignore();
        //         getline(cin, i_name);
        //         cout << '|' << setfill('=') << setw(68) << '=';
        //         cout << "  Enter  Password    :: ";
        //         getline(cin, i_password);
        //         cout << '|' << setfill('=') << setw(68) << '=';
        //         cout << "  Enter id number    :: ";
        //         cin >> i_identityNo;
        //         count++;                                                                              // to count the password input tries
        //         if (password == i_password && (identityNo == i_identityNo || name.find(i_name) < 41)) // password is must
        //         {
        //             read.close();
        //             cout << "\n\n|" << setfill(' ') << setw(68) << '~' << "  Access Granted !";
        //             cout << "\n|" << setfill(' ') << setw(70) << "~  ";
        //             system("pause");
        //             managerPortal(); // allows manager portal access
        //         }
        //         else
        //         {
        //             if (count > 3)
        //             {
        //                 read.close();
        //                 cout << "\n\n|" << setfill(' ') << setw(68) << '~' << "  Access Denied !";
        //                 cout << "\n|" << setfill(' ') << setw(68) << '~' << "  error : wrong information!\n";
        //                 cout << "\n|" << setfill(' ') << setw(68) << '~' << "  error : password input limit reached!\n";
        //                 cout << "\n|" << setfill(' ') << setw(70) << "~  ";
        //                 system("pause");
        //             }
        //             else
        //             {
        //                 cout << "\n\n|" << setfill(' ') << setw(68) << '~' << "  Access Denied !";
        //                 cout << "\n|" << setfill(' ') << setw(68) << '~' << "  error : wrong information!\n";
        //                 system("pause");
        //                 system("cls");
        //                 goto gotoManagerLogin;
        //             }
        //         }
        //     }
        //     else if (choice == '0')
        //     {
        //         read.close(); // way to main menu : main()
        //     }
        //     else
        //     {
        //         system("cls");
        //         goto gotoManagerLogin;
        //     }
        // }
    }
};

int main()
{
    cout << '|' << setfill(' ') << setw(68) << ' '; // to clear the output stream
    system("cls");                                  // each main menu will open in a fresh screen
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
