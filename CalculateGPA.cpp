#include <iostream>
#include <iomanip>
using namespace std;
class GPA
{
private:                                                                        // data members
    int subjects, subject_marks, total_marks, credit_hr, total_credit_hr, i, g; // i : iterator, g : grade in int instead of letter (for ease)
    float gp, quality_points, gpa, cgpa;                                        // Quality Points = Grade Points * credit Hours

private: // private member functions
    float gradePoints()
    {
        if (subject_marks < 50) // validating for grade checking and gpa value
            gp = 0.00;
        else if (subject_marks < 55)
            gp = 1.00;
        else if (subject_marks < 60)
            gp = 1.33;
        else if (subject_marks < 65)
            gp = 1.67;
        else if (subject_marks < 70)
            gp = 2.00;
        else if (subject_marks < 74)
            gp = 2.33;
        else if (subject_marks < 78)
            gp = 2.67;
        else if (subject_marks < 82)
            gp = 3.00;
        else if (subject_marks < 86)
            gp = 3.33;
        else if (subject_marks < 90)
            gp = 3.67;
        else
            gp = 4.00; // for subject_marks > 89 & subject_marks < 101
        return gp;
    }
    void displayGPA()
    {
        cout << "\n\tTotal Marks : " << total_marks;
        cout << "\n\tPercentage  : " << setprecision(2) << ((float)total_marks / (float)(subjects * 100)) * 100 << " %";
        cout << "\n\t  G P A    :: " << setprecision(2) << gpa << endl;
    }
    void input()
    {
    reEnterData:
        cout << "\tEnter obtained marks : ";
        cin >> subject_marks;
        if (subject_marks < 0 || subject_marks > 100)
        {
            cout << "~  error : invalid marks\n";
            goto reEnterData;
        }
        cout << "\tEnter credit hours : ";
        cin >> credit_hr;
        if (credit_hr < 0 || credit_hr > 3)
        {
            cout << "~  error : invalid credit hours\n";
            goto reEnterData;
        }
    }

public:
    GPA()
    {
        total_marks = 0;
        total_credit_hr = 0;
        quality_points = 0.0;
        cgpa = 0.0;
    }
    void calculateGPA()
    {
        system("cls");
        cout << "\n-- Grade Point Average --\n\n";
        cout << "\n~  Enter number of subjects : ";
        cin >> subjects;
        for (i = 1; i <= subjects; i++)
        {
            cout << "\nSUBJECT :: " << i << endl;
            input();
            quality_points += (gradePoints() * credit_hr);
            total_credit_hr += credit_hr;
            total_marks += subject_marks;
        }
        gpa = quality_points / total_credit_hr;
        displayGPA();
        cout << "\n~  ";
        system("pause");
    }
    void calculateCGPA()
    {
        system("cls");
        cout << "\n-- Cumulative Grade Point Average --\n\n";
        int semester;
        cout << "\n~  Enter current semester no. : ";
        cin >> semester;
        if (semester < 1 || semester > 8)
        {
            cout << "\n~  error : invalid input \n";
            cout << "~  ";
            system("pause");
            calculateCGPA();
        }
        for (i = 1; i < semester; i++)
        {
        reEnterSemester:
            cout << "\tEnter GPA of semester ( " << i << " ) : ";
            cin >> gpa;
            if (gpa < 0 || gpa > 4.0)
            {
                cout << "\n~  error : invalid input \n";
                goto reEnterSemester;
            }
            cgpa += gpa;
        }
        cgpa /= (semester - 1);
        // displaying obtained cGPA
        cout << "\n\tcGPA :: " << setprecision(2) << cgpa;
        cout << "\n\tper. :: " << setprecision(2) << (cgpa / 4.0 * 100) << " %\n";
        cout << "\n~  ";
        system("pause");
    }
};
int main()
{
    system("cls");
    cout << "\n-- Grade Point Average & Cumulative --\n\n";
    char ch;
    cout << "\n1. Find  GPA  of   ONE  Semester";
    cout << "\n2. Find cGPA of current Semester";
    cout << "\n0. Exit this program";
    cout << "\n~  Enter choice : ";
    cin >> ch;
    if (ch == '0')
    {
        cout << "\n\n ~  Program exited\n\n";
        exit(0);
    }
    else if (ch == '1')
    {
        GPA _gpa;
        _gpa.calculateGPA();
        main();
    }
    else if (ch == '2')
    {
        GPA _cgpa;
        _cgpa.calculateCGPA();
        main();
    }
    else
    {
        cout << "\n~  Error : invalid input\n";
        cout << "~  ";
        system("pause");
        main();
    }
    return 0;
}
