#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>
#include <algorithm>
using namespace std;
int globalID, lastID; // keep track of student's count
void row_design(int d)
{
    switch (d)
    {
    case 0:
        cout << setw(3) << left << " Sr"
             << " | " << setw(19) << left << "STUDENT NAMES"
             << " | " << setw(19) << left << "PARENTS NAMES"
             << " | " << setw(9) << left << "D.O.B"
             << " | " << setw(22) << left << "DEPARTMENT NAMES"
             << " |" << setw(5) << left << "SMSTR"
             << "| " << setw(3) << left << "ROL"
             << " | " << setw(3) << left << "GEN"
             << " | " << setw(3) << left << "AGE"
             << " | " << setw(4) << left << "CGPA"
             << " | " << setw(7) << left << "CITY"
             << " | " << setw(12) << left << "SKILLS" << '\n';
        break;
    case 1:
        cout << "\n\n----|---------------------|---------------------|-----------|------------------------|-----|-----|-----|-----|------|---------|-------------\n";
        break;
    case 2:
        cout << "____|_____________________|_____________________|___________|________________________|_____|_____|_____|_____|______|_________|_____________\n";
        break;
    default:
        break;
    }
}

class StudentDatabase // MAIN class
{
private:
    int semester, age, new_age, srno, rolNo; // new_age : while updating
    float gpa;
    char gender;
    string sname, fname, department, skills, dob, new_dob, city; // new_dob : while updating

public:
    StudentDatabase() // constructor : to check and read if data is available previously
    {
        ifstream readf("D:\\Students_Database.txt");
        if (readf.fail())
        {
            cout << " ~   Error : Student Database.txt file not found !!!\n";
            globalID = 0;
            readf.close();
        }
        // write code to read the srNo = globalID
        else
        {
            globalID = 0;  // initialized the global id to keep track of counts
            readf >> srno; // 1st attemp to reading the file
            readf.ignore();
            getline(readf, sname);
            getline(readf, fname);
            readf >> gender;
            readf.ignore();
            getline(readf, dob);
            readf >> age;
            readf.ignore();
            getline(readf, city);
            getline(readf, department);
            readf >> semester;
            readf >> rolNo;
            readf >> gpa;
            readf.ignore();
            getline(readf, skills);
            while (!readf.eof())
            {
                ++globalID;
                readf >> srno;
                readf.ignore();
                getline(readf, sname);
                getline(readf, fname);
                readf >> gender;
                readf.ignore();
                getline(readf, dob);
                readf >> age;
                readf.ignore();
                getline(readf, city);
                getline(readf, department);
                readf >> semester;
                readf >> rolNo;
                readf >> gpa;
                readf.ignore();
                getline(readf, skills);
            }
            lastID = srno;
            cout << " ~   success : Student Database has data of [ " << globalID << " ] students \n";
            readf.close();
        }
    }
    void DisplayFileRecords() // 1 : Display infile records
    {
        if (globalID == 0)
        {
            cout << "\t ~   Error : No Records available yet !!!\n";
            cout << "\t\t";
            system("pause");
            // main();
        }
        else
        {
            ifstream readf("D:\\Students_Database.txt");
            if (readf.fail())
            {
                cout << "\t ~   Error : Students_Database.txt file not found !!!\n";
                readf.close();
                system("pause");
                //                main();
            }
            else
            {
                system("cls");
                row_design(1); // printing the output designs
                row_design(0);
                row_design(2);
                readf >> srno; // 1st attemp to reading the file
                readf.ignore();
                getline(readf, sname);
                getline(readf, fname);
                readf >> gender;
                readf.ignore();
                getline(readf, dob);
                readf >> age;
                readf.ignore();
                getline(readf, city);
                getline(readf, department);
                readf >> semester;
                readf >> rolNo;
                readf >> gpa;
                readf.ignore();
                getline(readf, skills);
                while (!readf.eof())
                {
                    DisplayRecords();
                    readf >> srno;
                    readf.ignore();
                    getline(readf, sname);
                    getline(readf, fname);
                    readf >> gender;
                    readf.ignore();
                    getline(readf, dob);
                    readf >> age;
                    readf.ignore();
                    getline(readf, city);
                    getline(readf, department);
                    readf >> semester;
                    readf >> rolNo;
                    readf >> gpa;
                    readf.ignore();
                    getline(readf, skills);
                }
            }
            readf.close();
            cout << "\n\n\t\t~  ";
            system("pause");
        }
    }
    void AddRecords()
    {
        system("cls");
        cout << "\n          ---------- Students Database ---------\n\n";
        cout << " ~\t Enter Records for serial number ( " << ++globalID << " )\n";
        srno = globalID;
        cin.ignore();
        cout << " *\t Enter Student's Education Department   :: ";
        getline(cin, department);
        cout << " *\t Enter Student's Semester Number        :: ";
        cin >> semester;
        cout << " *\t Enter Student's ID/Roll Number         :: ";
        cin >> rolNo;
        cin.ignore();
        cout << " *\t Enter Student's Name                   :: ";
        getline(cin, sname);
        cout << " *\t Enter Student's Father Name            :: ";
        getline(cin, fname);
        cout << " *\t Enter Date of Birth (DDMMYYYY)         :: ";
        getline(cin, dob);
        cout << " *\t Enter Student's gender M/F/O/N         :: ";
        cin >> gender;
        cout << " *\t Enter current maintained CGPA          :: ";
        cin >> gpa;
        cin.ignore();
        cout << " *\t Enter Student's residence city name    :: ";
        getline(cin, city);
        cout << " *\t Enter Student's Extracurricular Skills :: ";
        getline(cin, skills);

        date_format(dob, 'a'); //  'a' : adding new record
        row_design(1);
        row_design(0);
        row_design(2);
        DisplayRecords(); // displaying the newly given records for confirmation
        char choice;
        cout << "\n ~\t Are you sure to save this record? (y/n) : ";
        cin >> choice;
        if (choice == 'n' || choice == 'N')
        {
            --globalID;
            AddRecords(); // clearing the present records & again adding for the same pace
        }
        else if (choice == 'y' || choice == 'Y')
        {
            WriteRecords(); // writing & saving the confirmed records for permanent future use in Student Database.txt file
            system("cls");
            cout << "\n          ---------- Students Database ---------\n\n";
            cout << "\t\t 1 : Add more Students\n";
            cout << "\t\t 2 : Jump back to main menu\n";
            cout << "\t\t 0 : Exit this program & endup\n";
            cout << "\t\t ~   Enter your choice here :: ";
            cin >> choice;
            if (choice == '1')
                AddRecords();
            else if (choice == '0')
            {
                cout << "\t\t ~   Program exited successfully !!! \n\n";
                exit(0);
            }
            // else
            // main(); // jumping to the MAIN function
        }
    }
    void sortDATA()
    {
        system("cls");
        char choice;
        cout << "\n          ---------- Sorting the Database ---------\n";
        cout << "\n\t 1 : Sort by Student's NAMES (alphabetically)";
        cout << "\n\t 2 : Sort by Department Names(alphabetically)";
        cout << "\n\t 3 : Sort by Semester Number(ascending order)";
        cout << "\n\t 4 : Sort by Student Roll no(ascending order)";
        cout << "\n\t 5 : Sort by Student's CGPA (ascending order)";
        cout << "\n\t 6 : Back to main menu of progam"; // no need to write the code, since it'll automatically directed to the main()
        cout << "\n\t 7 : Back to Serial vise sorting\n";
        cout << "\n\t 0 : Exit the SDB Program\n";
        cout << "\n\t ~   Enter your choice here :: ";
        cin >> choice;
        if (choice == '0')
        {
            cout << "\t ~   Program exited successfully !!! \n\n";
            exit(0);
        }
        else if (choice == '1')
        {
            data_sorting_and_filing('N'); // sort data according to 'N': Names
        }
        else if (choice == '2')
        {
            data_sorting_and_filing('D'); // 'D': Department vise
        }
        else if (choice == '3')
        {
            data_sorting_and_filing('S'); // 'S": Semester vise
        }
        else if (choice == '4')
        {
            data_sorting_and_filing('R'); // 'R': Roll number vise
        }
        else if (choice == '5')
        {
            data_sorting_and_filing('C'); // 'C': CGPA or marks
        }
        else if (choice == '6')
        {
            goto SortingLOOP; // towards main menu
        }
        else if (choice == '7')
        {
            data_sorting_and_filing('0'); // sort back to the serial number vise
        }
        else
        {
            cout << "\t ~   Error : invalid input by user";
            system("pause");
            sortDATA();
        }
    SortingLOOP:
        cout << "\t ~   Error : invalid input by user";
        /*
     . Always checking & sorting the serial number in ascending order after updating/deleting the records
        */
    }
    void searchRecords()
    {
        if (globalID == 0)
        {
            cout << "\t ~   Error : No Records available yet !!!\n";
            cout << "\t\t";
            system("pause");
        }
        else
        {
            system("cls");
            char choice;
            cout << "\n          ---------- Sorting the Database ---------\n";
            cout << "\n\t\t 1 : Search by Gender";
            cout << "\n\t\t 2 : Search by Roll Numbers";
            cout << "\n\t\t 3 : Search by Student Names ";
            cout << "\n\t\t 4 : Search by Serial Numbers";
            cout << "\n\t\t 5 : Search by Semester Number";
            cout << "\n\t\t 6 : Search by Locality (city)";
            cout << "\n\t\t 7 : Search by Department Names";
            cout << "\n\t\t 8 : Back to main menu of progam\n"; // no need to write the code, since it'll automatically directed to the main()
            cout << "\n\t\t 0 : Exit the SDB Program";
            cout << "\n\t\t ~   Enter your choice here :: ";
            cin >> choice;
            if (choice == '0')
            {
                cout << "\t\t ~   Program exited successfully !!! \n\n";
                exit(0);
            }
            else if (choice == '1')
            {
                data_searching('G'); // gender
                searchRecords();
            }
            else if (choice == '2')
            {
                data_searching('R'); // roll number
                searchRecords();
            }
            else if (choice == '3')
            {
                data_searching('N'); // name
                searchRecords();
            }
            else if (choice == '4')
            {
                data_searching('s'); // serial number
                searchRecords();
            }
            else if (choice == '5')
            {
                data_searching('S'); // semester number
                searchRecords();
            }
            else if (choice == '6')
            {
                data_searching('C'); // city
                searchRecords();
            }
            else if (choice == '7')
            {
                data_searching('D'); // department
                searchRecords();
            }
            else if (choice == '8')
            {
                goto SearchingLoop; // towards main menu
                searchRecords();
            }
            else
            {
                cout << "\t\t ~   Error : invalid input by user\n\t\t ~   ";
                system("pause");
                searchRecords();
            }
        SearchingLoop:
            cout << "\t ~   Welcome Back to main menu\n";
        }
    }
    void updateDeleteRecords()
    {
        system("cls");
        if (globalID == 0)
        {
            cout << "\t ~   Error : No Records available yet !!!\n";
            cout << "\t\t";
            system("pause");
        }
        else
        {
            char choice;
            cout << "\n\t\t-------- Updating the Database ---------\n\n";
            cout << "\n\t\t\t 1 : Update Records";
            cout << "\n\t\t\t 2 : Delete Records";
            cout << "\n\t\t\t 3 : Back to main menu";
            cout << "\n\t\t\t 0 : Exit SDB Program\n";
            cout << "\n\t\t\t ~   Enter choice here :: ";
            cin >> choice;
            if (choice == '0')
            {
                cout << "\t\t\t ~   Program exited successfully !!! \n\n";
                exit(0);
            }
            else if (choice == '1')
            {
                updateRecords();
                updateDeleteRecords();
            }
            else if (choice == '2')
            {
                deleteRecords();
                updateDeleteRecords();
            }
            else if (choice != '3')
            {
                cout << "\t\t ~   Error : invalid input by user\n\t\t ~   ";
                system("pause");
                updateDeleteRecords();
            }
            else
            {
            }
        }
    }
    ~StudentDatabase()
    {
        cout << "\n\t\t~   CodeBY: Muhammad Afnan Hassan #ITBatch1st\n\n";
    }

private:
    void updateRecords()
    {
        system("cls");
        char choice;
        cout << "\n\t\t~   Do you know 'Name', 'Roll number' & 'Semester' ? (y/n) : ";
        cin >> choice;
        if (choice == 'n' || choice == 'N')
        { // do nothing, just go back
        }
        else
        {
            int given_rolnumber, given_semester, given_serial;
            string given_name, filed_name;
            bool found = 0, updated = 0;
            cout << "\n\t\t~   Enter Student's Name : ";
            cin.ignore();
            getline(cin, given_name);
            transform(given_name.begin(), given_name.end(), given_name.begin(), ::tolower);
            cout << "\t\t~   Enter  Roll   Number : ";
            cin >> given_rolnumber;
            cout << "\t\t~   Enter   Semester  No : ";
            cin >> given_semester;
            // reading file data
            ifstream read("D:\\Students_Database.txt"); // old file
            ofstream write("D:\\temp.txt", ios::app);   // new file
            if (read.fail() || write.fail())
            {
                cout << " ~   Error : (.txt) file not accessible !!!\n";
                read.close();
                write.close();
                system("pause");
                updateDeleteRecords();
            }
            // 1st attemp to reading the file
            read >> srno;
            read.ignore();
            getline(read, sname);
            getline(read, fname);
            read >> gender;
            read.ignore();
            getline(read, dob);
            read >> age;
            read.ignore();
            getline(read, city);
            getline(read, department);
            read >> semester;
            read >> rolNo;
            read >> gpa;
            read.ignore();
            getline(read, skills);
            while (!read.eof())
            {
                filed_name = sname;
                transform(filed_name.begin(), filed_name.end(), filed_name.begin(), ::tolower);
                if (given_rolnumber == rolNo && given_semester == semester || filed_name.find(given_name) < 51)
                {
                    found = 1;
                    cout << endl;
                    row_design(1); // printing the output designs
                    row_design(0);
                    row_design(2);
                    DisplayRecords();
                    cout << endl;
                    cout << "\n\t\t~   Do you want to update this? (y/n) : ";
                    cin >> choice;
                    if (choice == 'y' || choice == 'Y')
                    {
                        int new_rolNo, new_semester, new_serial;
                        float new_gpa;
                        char new_gender;
                        string new_sname, new_fname, new_city, new_skills, new_department;
                        new_serial = srno;
                        cin.ignore();
                        cout << "\n *\t Enter Student's Education Department   :: ";
                        getline(cin, new_department);
                        cout << " *\t Enter Student's Semester Number        :: ";
                        cin >> new_semester;
                        cout << " *\t Enter Student's ID/Roll Number         :: ";
                        cin >> new_rolNo;
                        cin.ignore();
                        cout << " *\t Enter Student's Name                   :: ";
                        getline(cin, new_sname);
                        cout << " *\t Enter Student's Father Name            :: ";
                        getline(cin, new_fname);
                        cout << " *\t Enter Date of Birth (DDMMYYYY)         :: ";
                        getline(cin, new_dob); // this is not local variable
                        cout << " *\t Enter Student's gender M/F/O/N         :: ";
                        cin >> new_gender;
                        cout << " *\t Enter current maintained CGPA          :: ";
                        cin >> new_gpa;
                        cin.ignore();
                        cout << " *\t Enter Student's residence city name    :: ";
                        getline(cin, new_city);
                        cout << " *\t Enter Student's Extracurricular Skills :: ";
                        getline(cin, new_skills);
                        date_format(new_dob, 'u'); // procedure = 'u': update
                        row_design(1);
                        row_design(0);
                        row_design(2);
                        cout << ' ' << setw(3) << new_serial
                             << '|' << setw(21) << left << new_sname.substr(0, 21)
                             << '|' << setw(21) << left << new_fname.substr(0, 21)
                             << '|' << setw(11) << left << new_dob.substr(0, 11)
                             << '|' << setw(24) << left << new_department.substr(0, 24)
                             << "|  " << setw(3) << left << new_semester
                             << "| " << setw(4) << left << new_rolNo
                             << "| " << setw(4) << left << new_gender
                             << "| " << setw(4) << left << new_age
                             << "| " << setw(5) << left << new_gpa
                             << '|' << setw(9) << left << new_city.substr(0, 9)
                             << '|' << setw(13) << left << new_skills.substr(0, 13) << '\n';
                        cout << "\n\t\t~   Are you sure to update this? (y/n) : ";
                        cin >> choice;
                        if (choice == 'y' || choice == 'Y')
                        {
                            updated = 1;
                            write << new_serial << '\n'; // writing in new file
                            write << new_sname << '\n';
                            write << new_fname << '\n';
                            write << new_gender << '\n';
                            write << new_dob << '\n';
                            write << new_age << '\n'; // this is not local variable
                            write << new_city << '\n';
                            write << new_department << '\n';
                            write << new_semester << '\n';
                            write << new_rolNo << '\n';
                            write << new_gpa << '\n';
                            write << new_skills << '\n';
                            goto skippedWriting;
                        }
                        else
                        {
                            read.close();
                            write.close();
                            remove("d:\\temp.txt");
                            cout << "\n\t\t~   success : Record bot changed! \n";
                            cout << "\n\t\t~   1. Looking for another record";
                            cout << "\n\t\t~   2. Back to main menu";
                            cout << "\n\t\t~   0. Exit Program \n";
                            cout << "\n\t\t~   Enter choice : ";
                            cin >> choice;
                            if (choice == '0')
                            {
                                cout << "\t\t~   Program exited successfully! \n";
                                exit(0);
                            }
                            else if (choice == '1')
                            {
                                updateRecords();
                            }
                            else if (choice == '2')
                            {
                                goto mainMenuLast;
                            }
                            else
                                goto mainMenuLast;
                        }
                    }
                }
                write << srno << '\n'; // writing in new file
                write << sname << '\n';
                write << fname << '\n';
                write << gender << '\n';
                write << dob << '\n';
                write << age << '\n';
                write << city << '\n';
                write << department << '\n';
                write << semester << '\n';
                write << rolNo << '\n';
                write << gpa << '\n';
                write << skills << '\n';
            skippedWriting:
                read >> srno; // reading next records from old file
                read.ignore();
                getline(read, sname);
                getline(read, fname);
                read >> gender;
                read.ignore();
                getline(read, dob);
                read >> age;
                read.ignore();
                getline(read, city);
                getline(read, department);
                read >> semester;
                read >> rolNo;
                read >> gpa;
                read.ignore();
                getline(read, skills);
            }
            if (!found) // if record not found
            {
                read.close();
                write.close();
                remove("d:\\temp.txt");
                cout << "\n\t\t~   Error : Record not found! \n";
                cout << "\n\t\t~   Check again (input carefully) \n\t\t~   ";
                system("pause");
                updateRecords();
            }
            if (updated)
                cout << "\n\t\t~   success : Record Updated!";
            else
                cout << "\n\t\t~   success : record not changed!";
            read.close();
            write.close();
            remove("d:\\Students_Database.txt");
            rename("d:\\temp.txt", "d:\\Students_Database.txt");
        mainMenuLast:
            cout << "\n\t\t~   ";
            system("pause");
        }
    }
    void deleteRecords()
    {
        system("cls");
        char choice;
        cout << "\n\t\t~   Do you know 'Name', 'Roll number' & 'Semester' ? (y/n) : ";
        cin >> choice;
        if (choice == 'n' || choice == 'N')
        { // do nothing, just go back
        }
        else
        {
            int given_rolnumber, given_semester, given_serial;
            string given_name, filed_name;
            bool found = 0, deleted = 0;
            cout << "\n\t\t~   Enter Student's Name : ";
            cin.ignore();
            getline(cin, given_name);
            transform(given_name.begin(), given_name.end(), given_name.begin(), ::tolower);
            cout << "\t\t~   Enter  Roll   Number : ";
            cin >> given_rolnumber;
            cout << "\t\t~   Enter   Semester  No : ";
            cin >> given_semester;
            // reading file data
            ifstream read("D:\\Students_Database.txt");  // old file
            ofstream write("D:\\tempDel.txt", ios::app); // new file
            if (read.fail() || write.fail())
            {
                cout << " ~   Error : (.txt) file not accessible !!!\n";
                read.close();
                write.close();
                system("pause");
                updateDeleteRecords();
            }
            // 1st attemp to reading the file
            read >> srno;
            read.ignore();
            getline(read, sname);
            getline(read, fname);
            read >> gender;
            read.ignore();
            getline(read, dob);
            read >> age;
            read.ignore();
            getline(read, city);
            getline(read, department);
            read >> semester;
            read >> rolNo;
            read >> gpa;
            read.ignore();
            getline(read, skills);
            while (!read.eof())
            {
                filed_name = sname;
                transform(filed_name.begin(), filed_name.end(), filed_name.begin(), ::tolower);
                if (given_rolnumber == rolNo && given_semester == semester || filed_name.find(given_name) < 51)
                {
                    found = 1;
                    cout << endl;
                    row_design(1); // printing the output designs
                    row_design(0);
                    row_design(2);
                    DisplayRecords();
                    cout << endl;
                    cout << "\n\t\t~   Do you want to Delete this? (y/n) : ";
                    cin >> choice;
                    if (choice == 'y' || choice == 'Y')
                    {
                        deleted = 1;
                        goto skipDeleting;
                    }
                }
                write << srno << '\n'; // writing in new file
                write << sname << '\n';
                write << fname << '\n';
                write << gender << '\n';
                write << dob << '\n';
                write << age << '\n';
                write << city << '\n';
                write << department << '\n';
                write << semester << '\n';
                write << rolNo << '\n';
                write << gpa << '\n';
                write << skills << '\n';
            skipDeleting:
                read >> srno; // reading next records from old file
                read.ignore();
                getline(read, sname);
                getline(read, fname);
                read >> gender;
                read.ignore();
                getline(read, dob);
                read >> age;
                read.ignore();
                getline(read, city);
                getline(read, department);
                read >> semester;
                read >> rolNo;
                read >> gpa;
                read.ignore();
                getline(read, skills);
            }
            if (!found) // if record not found
            {
                read.close();
                write.close();
                remove("d:\\tempDel.txt");
                cout << "\n\t\t~   Error : Record not found! \n";
                cout << "\n\t\t~   Check again (input carefully) \n\t\t~   ";
                system("pause");
                updateRecords();
            }
            if (deleted)
                cout << "\n\t\t~   success : Record Deleted!";
            else
                cout << "\n\t\t~   success : record not changed!";
            read.close();
            write.close();
            remove("d:\\Students_Database.txt");
            rename("d:\\tempDel.txt", "d:\\Students_Database.txt");
            cout << "\n\t\t~   ";
            system("pause");
        }
    }
    void DisplayRecords() // Display runtime records
    {
        cout << ' ' << setw(3) << srno
             << '|' << setw(21) << left << sname.substr(0, 21)
             << '|' << setw(21) << left << fname.substr(0, 21)
             << '|' << setw(11) << left << dob.substr(0, 11)
             << '|' << setw(24) << left << department.substr(0, 24)
             << "|  " << setw(3) << left << semester
             << "| " << setw(4) << left << rolNo
             << "| " << setw(4) << left << gender
             << "| " << setw(4) << left << age
             << "| " << setw(5) << left << gpa
             << '|' << setw(9) << left << city.substr(0, 9)
             << '|' << setw(13) << left << skills.substr(0, 13) << '\n';
    }
    void data_searching(char search_type)
    {
        int given_rolnumber, given_serial, given_semester;
        char given_gender, filed_gender;
        string given_name, given_city, given_department, filed_name, filed_city, filed_department;
        bool found = 0;
        if (search_type == 'R')
        {
            cout << "\n\t\t ~   Enter Student's Roll Number :: ";
            cin >> given_rolnumber;
        }
        else if (search_type == 's')
        {
            cout << "\n\t\t ~   Enter Recorded Serial Number :: ";
            cin >> given_serial;
        }
        else if (search_type == 'S')
        {
            cout << "\n\t\t ~   Enter Semester Number :: ";
            cin >> given_semester;
        }
        else if (search_type == 'G')
        {
            cout << "\n\t\t ~   Enter Gender (M/F/O/N) :: ";
            cin >> given_gender;
            if (given_gender == 'M' || given_gender == 'F' || given_gender == 'O' || given_gender == 'N')
                given_gender += 32; // conversion to lowercase letter
        }
        else if (search_type == 'N')
        {
            cin.ignore();
            cout << "\n\t\t ~   Enter Student's Name :: ";
            getline(cin, given_name);
            transform(given_name.begin(), given_name.end(), given_name.begin(), ::tolower);
        }
        else if (search_type == 'C')
        {
            cin.ignore();
            cout << "\n\t\t ~   Enter City Name :: ";
            getline(cin, given_city);
            transform(given_city.begin(), given_city.end(), given_city.begin(), ::tolower);
        }
        else if (search_type == 'D')
        {
            cin.ignore();
            cout << "\n\t\t ~   Enter Department Name :: ";
            getline(cin, given_department);
            transform(given_department.begin(), given_department.end(), given_department.begin(), ::tolower);
        }
        system("cls");
        row_design(1); // printing the output designs
        row_design(0);
        row_design(2);
        ifstream read("d:\\Students_Database.txt");
        if (read.fail())
        {
            cout << "\n\t\t ~   File not found !!!\n";
            read.close();
        }
        read >> srno; // 1st attemp to reading the file
        read.ignore();
        getline(read, sname);
        getline(read, fname);
        read >> gender;
        read.ignore();
        getline(read, dob);
        read >> age;
        read.ignore();
        getline(read, city);
        getline(read, department);
        read >> semester;
        read >> rolNo;
        read >> gpa;
        read.ignore();
        getline(read, skills);
        while (!read.eof())
        {
            filed_name = sname; // assigning filed values to new variables to avoid direct manipulations
            filed_city = city;
            filed_department = department;
            filed_gender = gender;
            transform(filed_name.begin(), filed_name.end(), filed_name.begin(), ::tolower); // conversions to lower case letter for better comparison
            transform(filed_city.begin(), filed_city.end(), filed_city.begin(), ::tolower);
            transform(filed_department.begin(), filed_department.end(), filed_department.begin(), ::tolower);
            if (filed_gender == 'M' || filed_gender == 'F' || filed_gender == 'O' || filed_gender == 'N')
                filed_gender += 32; // conversion to lowercase letter
            // displaying the compared results
            if (search_type == 'R')
            {
                if (given_rolnumber == rolNo)
                {
                    found = 1;
                    DisplayRecords();
                }
            }
            else if (search_type == 's')
            {
                if (given_serial == srno)
                {
                    found = 1;
                    DisplayRecords();
                }
            }
            else if (search_type == 'S')
            {
                if (given_semester == semester)
                {
                    found = 1;
                    DisplayRecords();
                }
            }
            else if (search_type == 'G')
            {
                if (given_gender == filed_gender)
                {
                    found = 1;
                    DisplayRecords();
                }
            }
            else if (search_type == 'N')
            {
                if (filed_name.find(given_name) < 51)
                {
                    found = 1;
                    DisplayRecords();
                }
            }
            else if (search_type == 'C')
            {
                if (filed_city.find(given_city) < 51)
                {
                    found = 1;
                    DisplayRecords();
                }
            }
            else if (search_type == 'D')
            {
                if (filed_department.find(given_department) < 51)
                {
                    found = 1;
                    DisplayRecords();
                }
            }
            read >> srno;
            read.ignore();
            getline(read, sname);
            getline(read, fname);
            read >> gender;
            read.ignore();
            getline(read, dob);
            read >> age;
            read.ignore();
            getline(read, city);
            getline(read, department);
            read >> semester;
            read >> rolNo;
            read >> gpa;
            read.ignore();
            getline(read, skills);
        }
        if (!found)
            cout << "\n\n\n\n\t\t ~   Error : No Records Matched (Record NOT Found) !!!";
        cout << "\n\n\t\t ~   ";
        system("pause");
    }
    void WriteRecords()
    {
        ofstream write("D:\\Students_Database.txt", ios::app);
        if (write.fail())
        {
            cout << " ~   Error : Students_Database.txt file not processable !!!\n";
            write.close();
            // main();
        }
        else
        {
            write << globalID << '\n'; // globalID = srno
            write << sname << '\n';
            write << fname << '\n';
            write << gender << '\n';
            write << dob << '\n';
            write << age << '\n';
            write << city << '\n';
            write << department << '\n';
            write << semester << '\n';
            write << rolNo << '\n';
            write << gpa << '\n';
            write << skills << '\n';

            write.close();
            cout << " ~\t  Record saved successfully !!! \n ~\t  ";
            system("pause");
        }
    }
    void date_format(string temp_dob, char procedure)
    {
        int dy, mn, yr; // to catch the user date of birth dd-mm-yyyy
        int date;
        date = stoi(temp_dob);      // string to integer conversion
        if (temp_dob.length() == 8) // calculations start here
        {
            dy = date / 1000000;
            date %= 1000000;
            mn = date / 10000;
            yr = date % 10000;
        }
        else if (temp_dob.length() == 6)
        {
            dy = date / 100000;
            date %= 100000;
            mn = date / 10000;
            yr = date % 10000;
        }
        if (temp_dob.length() == 7)
        {
            yr = date % 10000;
            date /= 10000;
            if (date % 100 > 12)
            {
                dy = date / 10;
                mn = date % 10;
            }
            else
            {
                dy = date / 100;
                mn = date % 100;
            }
        }
        // formatting the date with dashes and zeros
        ostringstream formattedDate;
        formattedDate << setfill('0') << setw(2) << dy << "-"
                      << setw(2) << mn << "-" << yr;
        temp_dob = formattedDate.str();
        // calculating the age at the time of record added
        char charDATE[12]; // to use strftime(),we always need char array
        string presentDATE;
        int temp_age;
        time_t t = time(0); // fetches the local time of machine
        strftime(charDATE, 12, "%d/%m/%Y", localtime(&t));
        presentDATE = charDATE;                           // char to string conversion
        int yearPresent = stoi(presentDATE.substr(6, 4)); // years assignment
        temp_age = yearPresent - yr;
        if (procedure == 'a') // add a new record
        {
            dob = temp_dob;
            age = temp_age;
        }
        else // update an existing record
        {
            new_dob = temp_dob;
            new_age = temp_age;
        }
    }
    void data_sorting_and_filing(char sort_type)
    {
        int arr_ROLLnumber[globalID], arr_Semester[globalID], arr_SerialNumber[globalID];
        int i = 0, x, y, tempN;
        string arr_SNAME[globalID], arr_Department[globalID];
        string tempS;
        float arr_CGPA[globalID];

        if (globalID == 0)
        {
            cout << "\t ~   Error : No Records available yet !!!\n";
            cout << "\t\t";
            system("pause");
        }
        else
        {
            ifstream read("d:\\Students_Database.txt");
            if (read.fail())
            {
                cout << "\nFile not found !!!\n";
                read.close();
            }
            read >> srno; // 1st attemp to reading the file
            read.ignore();
            getline(read, sname);
            getline(read, fname);
            read >> gender;
            read.ignore();
            getline(read, dob);
            read >> age;
            read.ignore();
            getline(read, city);
            getline(read, department);
            read >> semester;
            read >> rolNo;
            read >> gpa;
            read.ignore();
            getline(read, skills);
            while (!read.eof())
            {
                arr_SerialNumber[i] = srno;
                arr_ROLLnumber[i] = rolNo;
                arr_SNAME[i] = sname;
                arr_CGPA[i] = gpa;
                arr_Department[i] = department;
                arr_Semester[i] = semester;
                i++;
                read >> srno;
                read.ignore();
                getline(read, sname);
                getline(read, fname);
                read >> gender;
                read.ignore();
                getline(read, dob);
                read >> age;
                read.ignore();
                getline(read, city);
                getline(read, department);
                read >> semester;
                read >> rolNo;
                read >> gpa;
                read.ignore();
                getline(read, skills);
            }
            read.close();
            if (sort_type == 'R') // sorting data in the arrays according to Roll numbers
            {
                for (x = 0; x < globalID; x++) // bubble sorting
                {
                    for (y = 0; y < globalID - 1; y++)
                    {
                        if (arr_ROLLnumber[y] > arr_ROLLnumber[y + 1])
                        {
                            tempN = arr_ROLLnumber[y];
                            tempS = arr_SNAME[y];
                            arr_ROLLnumber[y] = arr_ROLLnumber[y + 1];
                            arr_SNAME[y] = arr_SNAME[y + 1];
                            arr_ROLLnumber[y + 1] = tempN;
                            arr_SNAME[y + 1] = tempS;
                        }
                    }
                }
            }
            else if (sort_type == '0') // sorting data in the arrays according to Roll numbers
            {
                int tempSRNO;
                for (x = 0; x < globalID; x++) // bubble sorting
                {
                    for (y = 0; y < globalID - 1; y++)
                    {
                        if (arr_SerialNumber[y] > arr_SerialNumber[y + 1])
                        {
                            tempSRNO = arr_SerialNumber[y];
                            tempN = arr_ROLLnumber[y];
                            tempS = arr_SNAME[y];
                            arr_SerialNumber[y] = arr_SerialNumber[y + 1];
                            arr_ROLLnumber[y] = arr_ROLLnumber[y + 1];
                            arr_SNAME[y] = arr_SNAME[y + 1];
                            arr_SerialNumber[y + 1] = tempSRNO;
                            arr_ROLLnumber[y + 1] = tempN;
                            arr_SNAME[y + 1] = tempS;
                        }
                    }
                }
            }
            else if (sort_type == 'N') // sorting data according to student's names
            {
                for (i = 0; i < globalID - 1; i++) // selection sorting
                {
                    for (x = i + 1; x < globalID; x++)
                    {
                        if (arr_SNAME[i] > arr_SNAME[x])
                        {
                            tempS = arr_SNAME[i];
                            tempN = arr_ROLLnumber[i];
                            arr_SNAME[i] = arr_SNAME[x];
                            arr_ROLLnumber[i] = arr_ROLLnumber[x];
                            arr_SNAME[x] = tempS;
                            arr_ROLLnumber[x] = tempN;
                        }
                    }
                }
            }
            else if (sort_type == 'D') // sorting data according to department names
            {
                string tempD;
                for (i = 0; i < globalID - 1; i++) // selection sorting
                {
                    for (x = i + 1; x < globalID; x++)
                    {
                        if (arr_Department[i] > arr_Department[x])
                        {
                            tempD = arr_Department[i];
                            tempS = arr_SNAME[i];
                            tempN = arr_ROLLnumber[i];
                            arr_Department[i] = arr_Department[x];
                            arr_SNAME[i] = arr_SNAME[x];
                            arr_ROLLnumber[i] = arr_ROLLnumber[x];
                            arr_Department[x] = tempD;
                            arr_SNAME[x] = tempS;
                            arr_ROLLnumber[x] = tempN;
                        }
                    }
                }
            }
            else if (sort_type == 'S') // sorting data according to Semester number
            {
                int tempSM;
                for (x = 0; x < globalID; x++)
                {
                    for (y = 0; y < globalID - 1; y++)
                    {
                        if (arr_Semester[y] < arr_Semester[y + 1])
                        {
                            tempSM = arr_Semester[y];
                            tempN = arr_ROLLnumber[y];
                            tempS = arr_SNAME[y];
                            arr_Semester[y] = arr_Semester[y + 1];
                            arr_ROLLnumber[y] = arr_ROLLnumber[y + 1];
                            arr_SNAME[y] = arr_SNAME[y + 1];
                            arr_Semester[y + 1] = tempSM;
                            arr_ROLLnumber[y + 1] = tempN;
                            arr_SNAME[y + 1] = tempS;
                        }
                    }
                }
            }
            else if (sort_type == 'C') // sorting data according to obtained CGPA
            {
                float tempC;
                for (x = 0; x < globalID; x++) // bubble sorting
                {
                    for (y = 0; y < globalID - 1; y++)
                    {
                        if (arr_CGPA[y] < arr_CGPA[y + 1])
                        {
                            tempC = arr_CGPA[y];
                            tempN = arr_ROLLnumber[y];
                            tempS = arr_SNAME[y];
                            arr_CGPA[y] = arr_CGPA[y + 1];
                            arr_ROLLnumber[y] = arr_ROLLnumber[y + 1];
                            arr_SNAME[y] = arr_SNAME[y + 1];
                            arr_CGPA[y + 1] = tempC;
                            arr_ROLLnumber[y + 1] = tempN;
                            arr_SNAME[y + 1] = tempS;
                        }
                    }
                }
            }
            ofstream write("d:\\temp.txt", ios::app); // writing the sorted data into the file
            if (write.fail())
            {
                cout << "\nError: File not created !!\n";
                write.close();
                read.close();
            }
            // sorting data into the files
            for (x = 0; x < globalID; x++)
            {
                read.open("d:\\Students_Database.txt");
                read >> srno;
                read.ignore();
                getline(read, sname);
                getline(read, fname);
                read >> gender;
                read.ignore();
                getline(read, dob);
                read >> age;
                read.ignore();
                getline(read, city);
                getline(read, department);
                read >> semester;
                read >> rolNo;
                read >> gpa;
                read.ignore();
                getline(read, skills);
                while (!read.eof())
                {
                    if (rolNo == arr_ROLLnumber[x] && sname == arr_SNAME[x])
                    {
                        write << srno << '\n';
                        write << sname << '\n';
                        write << fname << '\n';
                        write << gender << '\n';
                        write << dob << '\n';
                        write << age << '\n';
                        write << city << '\n';
                        write << department << '\n';
                        write << semester << '\n';
                        write << rolNo << '\n';
                        write << gpa << '\n';
                        write << skills << '\n';
                    }
                    read >> srno;
                    read.ignore();
                    getline(read, sname);
                    getline(read, fname);
                    read >> gender;
                    read.ignore();
                    getline(read, dob);
                    read >> age;
                    read.ignore();
                    getline(read, city);
                    getline(read, department);
                    read >> semester;
                    read >> rolNo;
                    read >> gpa;
                    read.ignore();
                    getline(read, skills);
                }
                read.close();
            }
            read.close();
            write.close();
            remove("d:\\Students_Database.txt");
            rename("d:\\temp.txt", "d:\\Students_Database.txt");
            cout << " ~\t  Record Sorted successfully !!! \n ~\t  ";
            system("pause");
        }
    }
};

int main() // MAIN function
{
    system("cls");
    StudentDatabase sdb;
    char choice;
    cout << "\n         ---------- Students Database ---------\n";
    cout << "\n\t\t1 : Add new records";
    cout << "\n\t\t2 : Search in record";
    cout << "\n\t\t3 : Sort the database";
    cout << "\n\t\t4 : Display all records";
    cout << "\n\t\t5 : Update/Delete records";
    cout << "\n\t\t0 : Exit the SDB Program\n";
reselectMain:
    cout << "\n\t\t~   Enter your choice here :: ";
    cin >> choice;
    if (choice == '0') // validating the given choice from menu
    {
        cout << "\t\t~   Program exited successfully !!! \n\n";
        sdb.~StudentDatabase();
        exit(0);
    }
    else if (choice == '1')
    {
        sdb.AddRecords();
        main();
    }
    else if (choice == '2')
    {
        sdb.searchRecords();
        main();
    }
    else if (choice == '3')
    {
        sdb.sortDATA();
        main();
    }
    else if (choice == '4')
    {
        sdb.DisplayFileRecords();
        main();
    }
    else if (choice == '5')
    {
        sdb.updateDeleteRecords();
        main();
    }
    else
    {
        cout << "\t\t~   Error : invalid input by user";
        goto reselectMain;
    }
    return 0;
}
