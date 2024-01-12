#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
int globalID; // keep track of student's count
void row_design(int d)
{
    switch (d)
    {
    case 0:
        cout << setw(3) << left << "Sr"
             << " | " << setw(25) << left << "STUDENTS"
             << " | " << setw(25) << left << "PARENTS"
             << " | " << setw(17) << left << "D.O.B"
             << " | " << setw(25) << left << "DEPARTMENT"
             << " | " << setw(5) << left << "SMSTR"
             << " | " << setw(3) << left << "ROL"
             << " | " << setw(3) << left << "GEN"
             << " | " << setw(3) << left << "AGE"
             << " | " << setw(4) << left << "CGPA"
             << " | " << setw(12) << left << "CITY"
             << " | "
             << "Skills" << '\n';
        break;
    case 1:
        cout << "----|---------------------------|---------------------------|-------------------|---------------------------|-------|-----|-----|-----|------|--------------|-------\n";
        break;
    case 2:
        cout << "____|___________________________|___________________________|___________________|___________________________|_______|_____|_____|_____|______|______________|_______\n";
        break;
    default:
        break;
    }
}

class StudentDatabase // MAIN class
{
private:
    int semester, age = 22, srno, rolNo;
    float gpa;
    char gender;
    string sname, fname, department, skills, dob, city;

public:
    StudentDatabase() // constructor : to check and read if data is availabe previously
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
            globalID = srno;
            readf.close();
        }
    }
    void DisplayRecords() // 1 : Display runtime records
    {
        cout << setw(4) << left << srno
             << '|' << setw(27) << left << sname
             << '|' << setw(27) << left << fname
             << '|' << setw(19) << left << dob
             << '|' << setw(27) << left << department
             << "| " << setw(6) << left << semester
             << "| " << setw(4) << left << rolNo
             << "| " << setw(4) << left << gender
             << "| " << setw(4) << left << age
             << "| " << setw(5) << left << gpa
             << '|' << setw(14) << left << city
             << '|' << skills << '\n';
    }
    void DisplayFileRecords() // 1 : Display infile records
    {
        if (globalID == 0)
        {
            cout << " ~   Error : No Records available yet !!!\n";
            system("pause");
            // main();
        }
        else
        {
            ifstream read("D:\\Students_Database.txt");
            if (read.fail())
            {
                cout << " ~   Error : Students_Database.txt file not found !!!\n";
                read.close();
                system("pause");
                //                main();
            }
            row_design(1);
            row_design(0);
            row_design(2);
            while (!read.eof())
            {
                read >> srno;
                read.ignore();
                getline(read, sname);
                getline(read, fname);
                getline(read, dob);
                getline(read, department);
                read >> semester;
                read >> rolNo;
                read >> gender;
                read >> age;
                read >> gpa;
                read.ignore();
                getline(read, city);
                getline(read, skills);
                DisplayRecords();
            }
            read.close();
        }
    }
    void AddRecords()
    {
        system("cls");
        cout << "\n          ---------- Students Database ---------\n\n";
        cout << " ~\tEnter Records for serial number ( " << ++globalID << " )\n";
        srno = globalID;
        cin.ignore();
        cout << "\t Enter Student's Education Department   :: ";
        getline(cin, department);
        cout << "\t Enter Student's Semester Number        :: ";
        cin >> semester;
        cout << "\t Enter Student's Roll Number/ ID        :: ";
        cin >> rolNo;
        cin.ignore();
        cout << "\t Enter Student's Name                   :: ";
        getline(cin, sname);
        cout << "\t Enter Student's Father Name            :: ";
        getline(cin, fname);
        cout << "\t {date | month name/number | year | day}\n";
        cout << "\t Enter Student's Date of Birth          :: ";
        getline(cin, dob);
        cout << "\t Enter Student's gender M/F/O/N         :: ";
        cin >> gender;
        cout << "\t Enter current maintained CGPA          :: ";
        cin >> gpa;
        cin.ignore();
        cout << "\t Enter Student's residence city name    :: ";
        getline(cin, city);
        cout << "\t Enter Student's Extracurricular Skills :: ";
        getline(cin, skills);

        DisplayRecords(); // displaying the newly given records for confirmation
        char choice;
        cout << "\n\t\t ~ Are you sure to save this record? (y/n) : ";
        cin >> choice;
        if (choice == 'n' || choice == 'N')
        {
            --globalID;
            AddRecords(); // clearing the present records & again adding for the same pace
        }
        else if (choice == 'y' || choice == 'Y')
        {
            WriteRecords(); // writing & saving the confirmed records for permanant future use in Student Database.txt file
            globalID++;     // a new record added successfully
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
            cout << "\t\t ~   Record saved successfully !!! \n\n";
            system("pause");
        }
    }
};

int main() // MAIN function
{
    system("cls");
    StudentDatabase sdb;
    char choice;
    cout << "\n          ---------- Students Database ---------\n";
    cout << "\n\t\t 1 : Display all records";
    cout << "\n\t\t 2 : Update an information";
    cout << "\n\t\t 3 : Add new/fresh records";
    cout << "\n\t\t 4 : Search in the records";
    cout << "\n\t\t 0 : Exit the SDB Program\n";
reselectMain:
    cout << "\n\t\t ~   Enter your choice here :: ";
    cin >> choice;
    if (choice == '0' || choice == 'o' || choice == 'O') // validating the given choice from menu
    {
        cout << "\t\t ~   Program exited successfully !!! \n\n";
        exit(0);
    }
    else if (choice == '1')
    {
        sdb.DisplayFileRecords();
        main();
    }
    else if (choice == '2')
    {
    }
    else if (choice == '3')
    {
        sdb.AddRecords();
        main();
    }
    else if (choice == '4')
    {
    }
    else
    {
        cout << "\t\t ~   Error : invalid input by user";
        goto reselectMain;
    }
    return 0;
}
