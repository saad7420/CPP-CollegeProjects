#include <iostream>
#include <string>
#include <string.h>
#include <string.h>
#include <fstream>
using namespace std;
class Employee
{
private:
    int serial, fmembers, age;
    string ename, fname, street, timing;
    float pay, score, height;
public:
    Employee()
    {
        char checking_data[200];
        ofstream read("D:\\Employee Database.txt");
        // read.open("D:\\Employee Database.txt");
        if (read.fail())
            cout << "\n\tError: no previous records found! \n";
        else
        {
            gets(checking_data);
            if (checking_data[200]!='/0')
                cout << "\n\tHint: record available! \n";
            else
                cout << "\n\tNO previous records found! \n";
        }
        read.close();
    }
};
int main()
{
    Employee e1;
    cout << "\n\tHello World!\n\n\n";
    return 0;
}