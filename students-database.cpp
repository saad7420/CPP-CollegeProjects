// The Student Database Project, 3rd Semester BSIT, C++ Programming, Muhammad Afnan Hassan (afnanirshad)
#include <bits/stdc++.h>
using namespace std;
struct birth
{
    int date, year;
    string month;
};
struct Student
{
    int id, semester;
    float gpa;
    char gender;
    string name, department, skill;
    birth dob;
};
void display();
void update();
void changeUpdate();
void deleteUpdate();
void addnew();
void search();
void searchName();
void searchDepartment();
void searchSemester();
void print(Student s)
{
    cout << "\t" << setw(25) << left << s.name << " | " << setw(5) << left << s.id << " | " << setw(6) << left << s.gender << " | " << setw(17) << left << s.dob.month << " | " << setw(25) << left << s.department << " | " << setw(8) << left << s.semester << " | " << setw(5) << left << s.gpa << " | " << s.skill << endl;
}
int main()
{
    int choice;
    cout << "\n\t [ Student's Database ]\n\n";
    cout << "\t1. Display all students\n";
    cout << "\t2. Update an information\n"; // updating & deleting the record
    cout << "\t3. Add new students record\n";
    cout << "\t4. Search record in database\n"; // search by name, department, degree
    cout << "\t5. Exit the program\n";
    cout << "\t## Enter your choice here : ";
    cin >> choice;
    if (choice == 1)
        display();
    else if (choice == 2)
        update();
    else if (choice == 3)
        addnew();
    else if (choice == 4)
        search();
    else if (choice == 5)
    {
        cout << "\t## Program exited successfully!\n";
        exit(0);
    }
    else
    {
        cout << "\n\t## ERROR : invalid choice\n";
        main();
    }
    return 0;
}
void display()
{
    Student s;
    char choice;
    ifstream readf("d:\\Student Database.txt");
    if (readf.fail())
    {
        system("cls");
        cout << "\n\t## ERROR : no record found!\n";
        readf.close();
        main();
    }
    cout << "\n\t## Success : record is available!\n\t";
    system("pause");
    system("cls");
    cout << "\n\t\t\t\t\t\t\t\t[ Student's Database ]\n\n\n\t";
    cout << setw(25) << left << "NAMES"
         << " | " << setw(5) << left << "IDs"
         << " | " << setw(6) << left << "GENDER"
         << " | " << setw(17) << left << "D.O.B"
         << " | " << setw(25) << left << "DEPARTMENT"
         << " | " << setw(8) << left << "SEMESTER"
         << " | " << setw(5) << left << "CGPA"
         << " | "
         << "SKILLS" << endl;
    cout << "\t--------------------------|-------|--------|-------------------|---------------------------|----------|-------|-------\n";
    // cout << "\t__________________________|_______|________|___________________|___________________________|__________|_______|_______\n";
    getline(readf, s.name);
    readf >> s.id;
    readf >> s.gender;
    readf.ignore();
    getline(readf, s.dob.month); // to eliminate the possible dob-variable deficiency error
    getline(readf, s.department);
    readf >> s.semester;
    readf >> s.gpa;
    readf.ignore();
    getline(readf, s.skill);
    while (!readf.eof())
    {
        print(s); // printing the readed records one after the other student
        getline(readf, s.name);
        readf >> s.id;
        readf >> s.gender;
        readf.ignore();
        getline(readf, s.dob.month);
        getline(readf, s.department);
        readf >> s.semester;
        readf >> s.gpa;
        readf.ignore();
        getline(readf, s.skill);
    }
    readf.close();
    cout << "\n\n\t1. Return to main menu\n";
    cout << "\t2. Exit the Program\n";
    cout << "\t## Enter a choice : ";
    cin >> choice;
    if (choice == '1')
    {
        system("cls");
        main();
    }
    else if (choice == '2')
    {
        cout << "\t## Success : Program exited!\n\n";
        exit(0);
    }
    else
    {
        cout << "\t## ERROR : invalid choice...\n\t";
        system("pause");
        system("cls");
        main();
    }
}
void update()
{
    system("cls");
    char choice;
    cout << "\t1. Do you remember the Name & Department of student ?\n\t2. Do you want to first search for the desired records ?\n\t3. Exit this window to the main menu";
    cout << "\n\t## Enter a choice : ";
    cin >> choice;
    if (choice == '2')
    {
        cout << "\t## Success!    \n\t";
        system("pause");
        search();
    }
    else if (choice == '3')
    {
        cout << "\t## Success!    \n\t";
        system("pause");
        main();
    }
    else
    {
        cout << "\n\t1. Change a record";
        cout << "\n\t2. Delete a record";
        cout << "\n\t3. Exit to main menu";
        cout << "\n\t## Enter choice : ";
        cin >> choice;
        if (choice == '1')
            changeUpdate();
        else if (choice == '2')
            deleteUpdate();
        else
            main();
    }
}
void addnew()
{
    Student s;
    char choice;
    cout << "\tAre you sure for this task? (y/n) : ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
        goto ifyes_loop;
    }
    else
    {
        cout << "\t## Success : returned back to Home\n\t";
        system("pause");
        system("cls");
        main();
    }
ifyes_loop: // depends on choice & to overcome the possible execution logic error
    system("cls");
    ofstream writef("D:\\Student Database.txt", ios::app);
    cout << "\n\t [ Student's Database ]";
    cout << "\n\t [ Adding new Records ]\n\n";
    cout << "\tEnter student's full NAME : ";
    cin.ignore();
    getline(cin, s.name);
    cout << "\tEnter student Roll number : ";
    cin >> s.id;
    cout << "\tEnter the Gender(M/F/O/N) : ";
    cin >> s.gender;
    cout << "\t(Date of Birth)\n";
    cout << "\t\tEnter date only   : ";
    cin >> s.dob.date;
    cout << "\t\tEnter month only  : ";
    cin.ignore();
    cin >> s.dob.month;
    cout << "\t\tEnter Birth year  : ";
    cin >> s.dob.year;
    cout << "\tEnter the Department name : ";
    cin.ignore();
    getline(cin, s.department);
    cout << "\tEnter the Semester number : ";
    cin >> s.semester;
    cout << "\tEnter the student's CGPA  : ";
    cin >> s.gpa;
    cout << "\t(look at the Skills below) \n";
    cout << "\t{ Society Member / Sportsman\n\t/ Internet Geek / None }\n";
    cout << "\tType extracurricular skill: ";
    cin.ignore();
    getline(cin, s.skill);
    // writing the data onto a txt file in D:
    writef << s.name << endl;
    writef << s.id << endl;
    writef << s.gender << endl;
    writef << setw(2) << left << s.dob.date << "," << setw(9) << left << s.dob.month << "," << s.dob.year << endl;
    writef << s.department << endl;
    writef << s.semester << endl;
    writef << s.gpa << endl;
    writef << s.skill << endl;
    writef.close();
    cout << "\n\t## Success : The record added!\n\t1. Add next record \n\t2. Goto main menu \n\t3. Exit the program \n\t## Enter choice here : ";
    cin >> choice;
    if (choice == '1')
        addnew();
    else if (choice == '2')
    {
        system("cls");
        main();
    }
    else if (choice == '3')
        exit(0);
    else
    {
        cout << "\tERROR : invalid choice...\n\t";
        system("pause");
        system("cls");
        addnew();
    }
}
void search()
{
    char choice;
    system("cls");
    cout << "\n\t [ Student's Database ]\n\n";
    cout << "\t1. Search student by name \n";
    cout << "\t2. Search students by semester\n";
    cout << "\t3. Search students by department\n";
    cout << "\t4. Exit to the main menu\n";
    cout << "\t## Enter a choice here : ";
    cin >> choice;
    if (choice == '1')
        searchName();
    else if (choice == '2')
        searchSemester();
    else if (choice == '3')
        searchDepartment();
    else
    {
        cout << "\n\t## OK. returned to the main menu\n\t";
        system("pause");
        system("cls");
        main();
    }
}
void searchName()
{
    system("cls");
    Student s;
    string iname, fileName;
    char choice;
    bool found = 0;
    cout << "\n\t\t\t [ Student's Database ]\n\n";
    cout << "\n\t\t\tEnter the NAME of student : ";
    cin.ignore();
    getline(cin, iname);
    transform(iname.begin(), iname.end(), iname.begin(), ::tolower); // converts upper cases to all lower cases
    ifstream readf("D:\\Student Database.txt");
    if (readf.fail())
    {
        cout << "\t\t\t## ERROR : file not accessibe\n";
        readf.close();
        system("pause");
        system("cls");
        main();
    }
    getline(readf, s.name);
    readf >> s.id;
    readf >> s.gender;
    readf.ignore();
    getline(readf, s.dob.month); // to eliminate the possible dob-variable deficiency error
    getline(readf, s.department);
    readf >> s.semester;
    readf >> s.gpa;
    readf.ignore();
    getline(readf, s.skill);
    while (!readf.eof())
    {
        fileName = s.name;
        transform(fileName.begin(), fileName.end(), fileName.begin(), ::tolower);
        if (fileName.find(iname) < 51)
        {
            found = 1;
            cout << endl
                 << setw(30) << right << "* Name"
                 << " : " << s.name << endl;
            cout << setw(30) << right << "I.D."
                 << " : " << s.id << endl;
            cout << setw(30) << right << "Gend"
                 << " : " << s.gender << endl;
            cout << setw(30) << right << "DofB"
                 << " : " << s.dob.month << endl;
            cout << setw(30) << right << "Dprt"
                 << " : " << s.department << endl;
            cout << setw(30) << right << "smtr"
                 << " : " << s.semester << endl;
            cout << setw(30) << right << "CGPA"
                 << " : " << s.gpa << endl;
            cout << setw(30) << right << "Skil"
                 << " : " << s.skill << endl;
        }
        getline(readf, s.name);
        readf >> s.id;
        readf >> s.gender;
        readf.ignore();
        getline(readf, s.dob.month);
        getline(readf, s.department);
        readf >> s.semester;
        readf >> s.gpa;
        readf.ignore();
        getline(readf, s.skill);
    }
    readf.close();
    if (!found)
    {
        cout << "\n\t\t\t## ERROR : record not found!\n";
    }
    cout << "\n\n\t\t\t1. Search again\n";
    cout << "\t\t\t2. Search in other modes\n";
    cout << "\t\t\t3. Return to main menu\n";
    cout << "\t\t\t4. Exit the program\n";
    cout << "\t\t\t## Enter choice : ";
    cin >> choice;
    if (choice == '1')
    {
        system("cls");
        searchName();
    }
    else if (choice == '2')
    {
        system("cls");
        search();
    }
    else if (choice == '4')
    {
        cout << "\t\t\t## Success : program closed!\n\n";
        exit(0);
    }
    else
    {
        system("cls");
        main();
    }
}
void searchDepartment()
{
    system("cls");
    Student s;
    string iDepartment, fDepartment;
    char choice;
    bool found = 0;
    cout << "\n\t\t\t\t\t\t\tEnter the NAME of Department : ";
    cin.ignore();
    getline(cin, iDepartment);
    transform(iDepartment.begin(), iDepartment.end(), iDepartment.begin(), ::tolower); // converts upper cases to all lower cases
    ifstream readf("D:\\Student Database.txt");
    if (readf.fail())
    {
        cout << "\t\t\t\t\t\t\t\t\t## ERROR : file not accessibe\n";
        readf.close();
        system("pause");
        system("cls");
        main();
    }
    cout << "\n\t\t\t\t\t\t\t\t[ Student's Database ]\n\n\n\t";
    cout << setw(25) << left << "NAMES"
         << " | " << setw(5) << left << "IDs"
         << " | " << setw(6) << left << "GENDER"
         << " | " << setw(17) << left << "D.O.B"
         << " | " << setw(25) << left << "DEPARTMENT"
         << " | " << setw(8) << left << "SEMESTER"
         << " | " << setw(5) << left << "CGPA"
         << " | "
         << "SKILLS" << endl;
    cout << "\t--------------------------|-------|--------|-------------------|---------------------------|----------|-------|-------\n";
    getline(readf, s.name);
    readf >> s.id;
    readf >> s.gender;
    readf.ignore();
    getline(readf, s.dob.month); // to eliminate the possible dob-variable deficiency error
    getline(readf, s.department);
    readf >> s.semester;
    readf >> s.gpa;
    readf.ignore();
    getline(readf, s.skill);
    while (!readf.eof())
    {
        fDepartment = s.department;
        transform(fDepartment.begin(), fDepartment.end(), fDepartment.begin(), ::tolower);
        if (fDepartment.find(iDepartment) < 51)
        {
            found = 1;
            print(s);
        }
        getline(readf, s.name);
        readf >> s.id;
        readf >> s.gender;
        readf.ignore();
        getline(readf, s.dob.month);
        getline(readf, s.department);
        readf >> s.semester;
        readf >> s.gpa;
        readf.ignore();
        getline(readf, s.skill);
    }
    readf.close();
    if (!found)
    {
        cout << "\n\t\t\t\t\t\t\t\t## ERROR : record not found!\n";
    }
    cout << "\n\t\t\t\t\t\t\t\t1. Search again\n";
    cout << "\t\t\t\t\t\t\t\t2. Search in other modes\n";
    cout << "\t\t\t\t\t\t\t\t3. Return to main menu\n";
    cout << "\t\t\t\t\t\t\t\t4. Exit the program\n";
    cout << "\t\t\t\t\t\t\t\t## Enter choice : ";
    cin >> choice;
    if (choice == '1')
    {
        system("cls");
        searchDepartment();
    }
    else if (choice == '2')
    {
        system("cls");
        search();
    }
    else if (choice == '4')
    {
        cout << "\t\t\t\t\t\t\t## Success : program closed!\n\n";
        exit(0);
    }
    else
    {
        system("cls");
        main();
    }
}
void searchSemester()
{
    system("cls");
    Student s;
    int iSemester;
    char choice;
    bool found = 0;
    cout << "\n\t\t\t\t\t\t\tEnter student's semester number : ";
    cin >> iSemester;
    ifstream readf("D:\\Student Database.txt");
    if (readf.fail())
    {
        cout << "\t\t\t\t\t\t\t## ERROR : file not accessibe\n";
        readf.close();
        system("pause");
        system("cls");
        main();
    }
    cout << "\n\t\t\t\t\t\t\t\t[ Student's Database ]\n\n\n\t";
    cout << setw(25) << left << "NAMES"
         << " | " << setw(5) << left << "IDs"
         << " | " << setw(6) << left << "GENDER"
         << " | " << setw(17) << left << "D.O.B"
         << " | " << setw(25) << left << "DEPARTMENT"
         << " | " << setw(8) << left << "SEMESTER"
         << " | " << setw(5) << left << "CGPA"
         << " | "
         << "SKILLS" << endl;
    cout << "\t--------------------------|-------|--------|-------------------|---------------------------|----------|-------|-------\n";
    getline(readf, s.name);
    readf >> s.id;
    readf >> s.gender;
    readf.ignore();
    getline(readf, s.dob.month); // to eliminate the possible dob-variable deficiency error
    getline(readf, s.department);
    readf >> s.semester;
    readf >> s.gpa;
    readf.ignore();
    getline(readf, s.skill);
    while (!readf.eof())
    {
        if (iSemester == s.semester)
        {
            found = 1;
            print(s);
        }
        getline(readf, s.name);
        readf >> s.id;
        readf >> s.gender;
        readf.ignore();
        getline(readf, s.dob.month);
        getline(readf, s.department);
        readf >> s.semester;
        readf >> s.gpa;
        readf.ignore();
        getline(readf, s.skill);
    }
    readf.close();
    if (!found)
    {
        cout << "\n\t\t\t\t\t\t\t\t## ERROR : record not found!\n";
    }
    cout << "\n\t\t\t\t\t\t\t\t1. Search again\n";
    cout << "\t\t\t\t\t\t\t\t2. Search in other modes\n";
    cout << "\t\t\t\t\t\t\t\t3. Return to main menu\n";
    cout << "\t\t\t\t\t\t\t\t4. Exit the program\n";
    cout << "\t\t\t\t\t\t\t\t## Enter choice : ";
    cin >> choice;
    if (choice == '1')
    {
        system("cls");
        searchSemester();
    }
    else if (choice == '2')
    {
        system("cls");
        search();
    }
    else if (choice == '4')
    {
        cout << "\t\t\t\t\t\t\t## Success : program closed!\n\n";
        exit(0);
    }
    else
    {
        system("cls");
        main();
    }
}
void changeUpdate()
{
    system("cls");
    Student s, news;
    char choice;
    bool found = 0;
    string iname, fname, idepartment, fdepartment;
    cout << "\n\tEnter the name of student : ";
    cin.ignore();
    getline(cin, iname);
    transform(iname.begin(), iname.end(), iname.begin(), ::towlower);
    cout << "\tEnter the name of department : ";
    getline(cin, idepartment);
    transform(idepartment.begin(), idepartment.end(), idepartment.begin(), ::tolower);
    ifstream readf("D:\\Student Database.txt");
    if (readf.fail())
    {
        cout << "\n\t## Error : file not accessible!\n";
        readf.close();
        system("pause");
        system("cls");
        main();
    }
    ofstream writef("D:\\Student newbase.txt");
    if (writef.fail())
    {
        cout << "\n\t## Error : file not accessible!\n";
        writef.close();
        remove("D:\\Student newbase.txt");
        readf.close();
        system("pause");
        system("cls");
        main();
    }
    // system("cls");
    cout << "\n\t\t\t\t\t\t\t\t[ Student's Database ]\n\n\n\t";
    cout << setw(25) << left << "NAMES"
         << " | " << setw(5) << left << "IDs"
         << " | " << setw(6) << left << "GENDER"
         << " | " << setw(17) << left << "D.O.B"
         << " | " << setw(25) << left << "DEPARTMENT"
         << " | " << setw(8) << left << "SEMESTER"
         << " | " << setw(5) << left << "CGPA"
         << " | "
         << "SKILLS" << endl;
    cout << "\t--------------------------|-------|--------|-------------------|---------------------------|----------|-------|-------\n";
    getline(readf, s.name);
    readf >> s.id;
    readf >> s.gender;
    readf.ignore();
    getline(readf, s.dob.month);
    getline(readf, s.department);
    readf >> s.semester;
    readf >> s.gpa;
    readf.ignore();
    getline(readf, s.skill);
    while (!readf.eof())
    {
        fname = s.name;
        transform(fname.begin(), fname.end(), fname.begin(), ::tolower);
        fdepartment = s.department;
        transform(fdepartment.begin(), fdepartment.end(), fdepartment.begin(), ::tolower);
        if (fname.find(iname) < 50 && fdepartment.find(idepartment) < 50)
        {
            found = 1;
            print(s);
            cout << "\n\n\t## Are you sure to update this record ? (y/n) : ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y')
            {
                // the code to accept the user inputs
                system("cls");
                cout << "\n\t [ Student's Database ]";
                cout << "\n\t [ Adding new Records ]\n\n";
                cout << "\tEnter student's full NAME : ";
                cin.ignore();
                getline(cin, news.name);
                cout << "\tEnter student Roll number : ";
                cin >> news.id;
                cout << "\tEnter the Gender(M/F/O/N) : ";
                cin >> news.gender;
                cout << "\t(Date of Birth)\n";
                cout << "\t\tEnter date only   : ";
                cin >> news.dob.date;
                cout << "\t\tEnter month only  : ";
                cin.ignore();
                cin >> news.dob.month;
                cout << "\t\tEnter Birth year  : ";
                cin >> news.dob.year;
                cout << "\tEnter the Department name : ";
                cin.ignore();
                getline(cin, news.department);
                cout << "\tEnter the Semester number : ";
                cin >> news.semester;
                cout << "\tEnter the student's CGPA  : ";
                cin >> news.gpa;
                cout << "\t(look at the Skills below) \n";
                cout << "\t{ Society Member / Sportsman\n\t/ Internet Geek / None }\n";
                cout << "\tType extracurricular skill: ";
                cin.ignore();
                getline(cin, news.skill);
                // writing the data onto a txt file in D:
                writef << news.name << endl;
                writef << news.id << endl;
                writef << news.gender << endl;
                writef << setw(2) << left << news.dob.date << "," << setw(9) << left << news.dob.month << "," << news.dob.year << endl;
                writef << news.department << endl;
                writef << news.semester << endl;
                writef << news.gpa << endl;
                writef << news.skill << endl;
            }
            else
            {
                cout << "\n\t1. Search for another record";
                cout << "\n\t2. Exit & Goto main menu";
                cout << "\n\t## Enter choice : ";
                cin >> choice;
                if (choice == '1')
                {
                    readf.close();
                    writef.close();
                    remove("D:\\Student newbase.txt");
                    system("cls");
                    changeUpdate();
                }
                else if (choice == '2')
                {
                    readf.close();
                    writef.close();
                    remove("D:\\Student newbase.txt");
                    system("cls");
                    main();
                }
                else
                {
                    readf.close();
                    writef.close();
                    remove("D:\\Student newbase.txt");
                    cout << "\n\t## Error : invalid choice!\n";
                    system("pause");
                    main();
                }
            }
        }
        else
        {
            // the code to write in new file otherwise if it doesn't matche the user's inputs
            writef << s.name << endl;
            writef << s.id << endl;
            writef << s.gender << endl;
            writef << s.dob.month << endl;
            writef << s.department << endl;
            writef << s.semester << endl;
            writef << s.gpa << endl;
            writef << s.skill << endl;
        }
        getline(readf, s.name);
        readf >> s.id;
        readf >> s.gender;
        readf.ignore();
        getline(readf, s.dob.month);
        getline(readf, s.department);
        readf >> s.semester;
        readf >> s.gpa;
        readf.ignore();
        getline(readf, s.skill);
    }
    readf.close();
    writef.close();
    remove("D:\\Student Database.txt");
    rename("D:\\Student newbase.txt", "D:\\Student Database.txt");
    if (!found)
    {
        cout << "\n\t## Error : record not found in the database!\n";
        system("pause");
        update();
    }
    cout << "\n\t## Success : record updated!";
    cout << "\n\t1. Return no main menu";
    cout << "\n\t2. Update other records";
    cout << "\n\t3. Exit & close the program";
    cout << "\n\t## Enter a choice : ";
    cin >> choice;
    if (choice == '1')
    {
        system("cls");
        main();
    }
    else if (choice == '3')
    {
        cout << "\n\t## Program exited successfully!\n";
        exit(0);
    }
    else
        update();
}
void deleteUpdate()
{
    system("cls");
    Student s;
    char choice;
    bool found = 0;
    string iname, fname, idepartment, fdepartment;
    cout << "\n\tEnter the name of student : ";
    cin.ignore();
    getline(cin, iname);
    transform(iname.begin(), iname.end(), iname.begin(), ::towlower);
    cout << "\tEnter the name of department : ";
    getline(cin, idepartment);
    transform(idepartment.begin(), idepartment.end(), idepartment.begin(), ::tolower);
    ifstream readf("D:\\Student Database.txt");
    if (readf.fail())
    {
        cout << "\n\t## Error : file not accessible!\n";
        readf.close();
        system("pause");
        system("cls");
        main();
    }
    ofstream writef("D:\\Student newbase.txt");
    if (writef.fail())
    {
        cout << "\n\t## Error : file not accessible!\n";
        writef.close();
        remove("D:\\Student newbase.txt");
        readf.close();
        system("pause");
        system("cls");
        main();
    }
    cout << "\n\t\t\t\t\t\t\t\t[ Student's Database ]\n\n\n\t";
    cout << setw(25) << left << "NAMES"
         << " | " << setw(5) << left << "IDs"
         << " | " << setw(6) << left << "GENDER"
         << " | " << setw(17) << left << "D.O.B"
         << " | " << setw(25) << left << "DEPARTMENT"
         << " | " << setw(8) << left << "SEMESTER"
         << " | " << setw(5) << left << "CGPA"
         << " | "
         << "SKILLS" << endl;
    cout << "\t--------------------------|-------|--------|-------------------|---------------------------|----------|-------|-------\n";
    getline(readf, s.name);
    readf >> s.id;
    readf >> s.gender;
    readf.ignore();
    getline(readf, s.dob.month);
    getline(readf, s.department);
    readf >> s.semester;
    readf >> s.gpa;
    readf.ignore();
    getline(readf, s.skill);
    while (!readf.eof())
    {
        fname = s.name;
        transform(fname.begin(), fname.end(), fname.begin(), ::tolower);
        fdepartment = s.department;
        transform(fdepartment.begin(), fdepartment.end(), fdepartment.begin(), ::tolower);
        if (fname.find(iname) < 50 && fdepartment.find(idepartment) < 50)
        {
            found = 1;
            print(s);
            cout << "\n\n\t## Are you sure to delete this record ? (y/n) : ";
            cin >> choice;
            if (choice == 'y' || choice == 'Y')
            {
                goto skippedRecord;
            }
            else
            {
                cout << "\n\t1. Search for another record";
                cout << "\n\t2. Exit & Goto main menu";
                cout << "\n\t## Enter choice : ";
                cin >> choice;
                if (choice == '1')
                {
                    readf.close();
                    writef.close();
                    remove("D:\\Student newbase.txt");
                    system("cls");
                    deleteUpdate();
                }
                else if (choice == '2')
                {
                    readf.close();
                    writef.close();
                    remove("D:\\Student newbase.txt");
                    system("cls");
                    main();
                }
                else
                {
                    readf.close();
                    writef.close();
                    remove("D:\\Student newbase.txt");
                    cout << "\n\t## Error : invalid choice!\n";
                    system("pause");
                    main();
                }
            }
        }
        else
        {
            // the code to write in new file otherwise if it doesn't matche the user's inputs
            writef << s.name << endl;
            writef << s.id << endl;
            writef << s.gender << endl;
            writef << s.dob.month << endl;
            writef << s.department << endl;
            writef << s.semester << endl;
            writef << s.gpa << endl;
            writef << s.skill << endl;
        }
    skippedRecord:
        getline(readf, s.name);
        readf >> s.id;
        readf >> s.gender;
        readf.ignore();
        getline(readf, s.dob.month);
        getline(readf, s.department);
        readf >> s.semester;
        readf >> s.gpa;
        readf.ignore();
        getline(readf, s.skill);
    }
    readf.close();
    writef.close();
    remove("D:\\Student Database.txt");
    rename("D:\\Student newbase.txt", "D:\\Student Database.txt");
    if (!found)
    {
        cout << "\n\t## Error : record not found in the database!\n";
        system("pause");
        update();
    }
    cout << "\n\t## Success : record updated!";
    cout << "\n\t1. Return no main menu";
    cout << "\n\t2. Update other records";
    cout << "\n\t3. Exit & close the program";
    cout << "\n\t## Enter a choice : ";
    cin >> choice;
    if (choice == '1')
        main();
    else if (choice == '3')
    {
        cout << "\n\t## Program exited successfully!\n";
        exit(0);
    }
    else
        update();
}

// The Student Database Project, 3rd Semester BSIT, C++ Programming, Muhammad Afnan Hassan (afnanirshad)