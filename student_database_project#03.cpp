/* 															STUDENT'S DATABASE
#include "bits/stdc++.h" */
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <cstring>
#include <algorithm>
using namespace std;
int ID, totalStudents = 0; // global ID for student's count
struct student
{
	int sr, semester, age;
	char gender;
	float gpa;
	string name, fname, department, degree, rolNo; // REMINDER : I have to add a field of hobies/skills
};
void print(student s)
{
	cout << "\n	- - - - - > Student - SrNo # " << s.sr;
	cout << "\n	---------------------------------";
	cout << "\n	ID/Roll No	: " << s.rolNo;
	cout << "\n	Name		: " << s.name;
	cout << "\n	Father		: " << s.fname;
	cout << "\n	Age		: " << s.age;
	cout << "\n	Gender		: " << s.gender;
	cout << "\n	Department	: " << s.department;
	cout << "\n	Degree/Program	: " << s.degree;
	cout << "\n	Semester NO	: " << s.semester;
	cout << "\n	CGPA		: " << s.gpa;
	cout << "\n\n	---------------------------------";
	totalStudents++;
}
void addStudent();
void seeStudent();
void searchStudent(); // search
void srSearch();
void nmSearch();
void idSearch();
void degreeSearch();
void departSearch();
void genderSearch();
void smrSearch();
void deleteStudent();
void updateStudent();
int main() // main function
{
	student s;

	ifstream file("D:\\student.txt"); // file opened  // checking previous record
	if (file.fail())
	{
		ID = 0;
		ofstream write("D:\\id.txt"); // file opened
		write << ID;
		write.close(); // file closed
	}
	else
	{
		file >> s.sr;
		if (s.sr >= 1) // what if the file is empty, so not to show this message? (bug)
		{
			cout << "\n The Record is available! (Enter 2 to SEE the Record)\n\n";
		}
		else
		{
			ID = 0;
			ofstream write("D:\\id.txt"); // file opened
			write << ID;
			write.close(); // file closed
		}
	}
	file.close(); // file closed

	ifstream read("D:\\id.txt"); // student's counting file	// file opened
	if (read.fail())
		ID = 0;
	else
		read >> ID;
	read.close(); // file closed

	char option; // main menu of the program
	cout << "	- - - - > STUDENT'S DATABASE\n";
	cout << "\n	1 : ADD a Student in Record";
	cout << "\n	2 : SHOW - Student's Record";
	cout << "\n	3 : SEARCH Student's Record";
	cout << "\n	4 : DELETE Student's Record";
	cout << "\n	5 : UPDATE Student's Record";
	cout << "\n	6 : 	Exit the Program \n";
	cout << "\n	Select any Option by its Number : ";
	cin >> option;

	switch (option)
	{
	case '1':
		addStudent();
		break;
	case '2':
		seeStudent();
		break;
	case '3':
		searchStudent();
		break;
	case '4':
		deleteStudent();
		break;
	case '5':
		updateStudent();
		break;
	case '6':
		cout << "\n	(Program Exited successfully!)\n"
			 << endl;
		exit(0);
		break;
	default:
	{
		cout << "\n	ERROR: Please Select a valid Option!\n\n";
		main();
		break;
	}
	}

	//	system("pause");
	return 0;
}
void addStudent()
{
	student s;
	char ch;

	ofstream write("D:\\student.txt", ios::app); //  file opened
	cout << "\n		Enter Student's ID or Roll No. : ";
	cin >> s.rolNo;
	cout << "		Enter Student's Name : ";
	cin.ignore();
	getline(cin, s.name);
	cout << "		Enter Student's Father Name : ";
	getline(cin, s.fname);
	cout << "		Enter Student's Age : ";
	cin >> s.age;
	cout << "		Enter Student's Gender (M/F/O): ";
	cin >> s.gender;
	cout << "		Enter Department name : ";
	cin.ignore();
	getline(cin, s.department);
	cout << "		Enter Program/Degree : ";
	getline(cin, s.degree);
	cout << "		Enter Semester number : ";
	cin >> s.semester;
	cout << "		Enter current CGPA : ";
	cin >> s.gpa;
	ID++;

	write << ID << endl;
	write << s.rolNo << endl;
	write << s.name << endl;
	write << s.fname << endl;
	write << s.age << endl;
	write << s.gender << endl;
	write << s.department << endl;
	write << s.degree << endl;
	write << s.semester << endl;
	write << s.gpa << endl;
	write.close(); // file closed

	write.open("d:\\id.txt"); // file opened
	if (!write.fail())
		write << ID;
	else
		cout << "\n	ERROR: ID didn't store successfully!\n";
	write.close(); // file closed

	cout << "\n	Do you want to add more student's record? (y/n) --- ";
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
		addStudent();
	else
	{
		cout << "		(Data Stored successfully!)\n";
		main();
	}
}
void seeStudent()
{
	student s;
	if (ID == 0)
	{
		cout << "\n	There is NO record yet!\n\n";
		main();
	}
	ifstream read("D:\\student.txt"); // file opened
	cout << "\n	---------------------------------";
	read >> s.sr;
	read >> s.rolNo;
	read.ignore();
	getline(read, s.name);
	getline(read, s.fname);
	read >> s.age;
	read >> s.gender;
	read.ignore();
	getline(read, s.department);
	getline(read, s.degree);
	read >> s.semester;
	read >> s.gpa;
	while (!read.eof())
	{
		print(s);
		read >> s.sr;
		read >> s.rolNo;
		read.ignore();
		getline(read, s.name);
		getline(read, s.fname);
		read >> s.age;
		read >> s.gender;
		read.ignore();
		getline(read, s.department);
		getline(read, s.degree);
		read >> s.semester;
		read >> s.gpa;
	}
	read.close(); // file closed
	cout << "\n Total Students : " << totalStudents << "\n\n";
	char ch;
	cout << "	Do you want to EXIT the Program? (y/n) : ";
	cin >> ch;
	if (ch == 'n' || ch == 'N')
		main();
	else
	{
		cout << "	(Program Exited successfully!)\n";
		exit(0);
	}
}
void searchStudent() // search
{
	if (ID == 0)
	{
		cout << "\n	There is NO record available yet!\n\n";
		main();
	}

	char sOption;
	cout << "\n	select an option to go further";
	cout << "\n	1 : Search by Serial Number";
	cout << "\n	2 : Search by Student's Name";
	cout << "\n	3 : Search by ID / Roll Number";
	cout << "\n	4 : Search by Program / Degree";
	cout << "\n	5 : Search by Department";
	cout << "\n	6 : Search by Gender";
	cout << "\n	7 : Search by Semester Number";
	cout << "\n	8 : Exit the Program / Searching\n";
	cout << "\n	- - - - > Enter Search : ";
	cin >> sOption;

	switch (sOption)
	{
	case '1':
	{
		srSearch();
		break;
	}
	case '2':
	{
		nmSearch();
		break;
	}
	case '3':
	{
		idSearch();
		break;
	}
	case '4':
	{
		degreeSearch();
		break;
	}
	case '5':
	{
		departSearch();
		break;
	}
	case '6':
	{
		genderSearch();
		break;
	}
	case '7':
	{
		smrSearch();
		break;
	}
	case '8':
	{
		char x;
		cout << "\n	1 : Exit Search window";
		cout << "\n	2 : Exit the Program";
		cout << "\n	Enter your choice : ";
		cin >> x;
		if (x == '2')
		{
			cout << "\n	(Program Exited successfully)\n";
			exit(0);
		}
		else
		{
			cout << "\n	(Search window Exited successfully)\n\n";
			main();
		}
	}
	default:
	{
		cout << "\n	ERROR: Invalid Choice\n";
		searchStudent();
		break;
	}
	}
}
void srSearch()
{
	int sr;
	student s;
	bool found = false;
	cout << "\n	Enter Serial Number of student : ";
	cin >> sr;
	ifstream read("d:\\student.txt"); // REMINDER : I should change the Path letter D to d
	if (read.fail())
	{
		cout << "\n	(ERROR: File not found)\n";
		main();
	}
	cout << "\n	---------------------------------";
	read >> s.sr;
	read >> s.rolNo;
	read.ignore();
	getline(read, s.name);
	getline(read, s.fname);
	read >> s.age;
	read >> s.gender;
	read.ignore();
	getline(read, s.department);
	getline(read, s.degree);
	read >> s.semester;
	read >> s.gpa;
	while (!read.eof())
	{
		if (s.sr == sr)
		{
			found = true;
			print(s);
		}
		read >> s.sr;
		read >> s.rolNo;
		read.ignore();
		getline(read, s.name);
		getline(read, s.fname);
		read >> s.age;
		read >> s.gender;
		read.ignore();
		getline(read, s.department);
		getline(read, s.degree);
		read >> s.semester;
		read >> s.gpa;
	}
	if (!found)
		cout << "\n	(Sorry! Desired data not found)\n";
	char ch;
	cout << "\n	Do you want to SEARCH again? (y/n) : ";
	cin >> ch;
	cout << endl;
	if (ch == 'y' || ch == 'Y')
		srSearch();
	else
		main();
	read.close();
}
void nmSearch()
{
	string nm;
	student s;
	bool found = false;
	cout << "\n	Enter the Name of student : "; // REMINDER : convert upper to lower characters
	cin.ignore();
	getline(cin, nm);
	ifstream read("d:\\student.txt"); // REMINDER : I should change the Path letter D to d
	if (read.fail())
	{
		cout << "\n	(ERROR: File not found)\n";
		main();
	}
	cout << "\n	---------------------------------";
	read >> s.sr;
	read >> s.rolNo;
	read.ignore();
	getline(read, s.name);
	getline(read, s.fname);
	read >> s.age;
	read >> s.gender;
	read.ignore();
	getline(read, s.department);
	getline(read, s.degree);
	read >> s.semester;
	read >> s.gpa;
	while (!read.eof())
	{
		if (s.name == nm)
		{
			found = true;
			print(s);
		}
		read >> s.sr;
		read >> s.rolNo;
		read.ignore();
		getline(read, s.name);
		getline(read, s.fname);
		read >> s.age;
		read >> s.gender;
		read.ignore();
		getline(read, s.department);
		getline(read, s.degree);
		read >> s.semester;
		read >> s.gpa;
	}
	if (!found)
		cout << "\n	(Sorry! Desired data not found)\n";
	char ch;
	cout << "\n	Do you want to SEARCH again? (y/n) : ";
	cin >> ch;
	cout << endl;
	if (ch == 'y' || ch == 'Y')
		nmSearch();
	else
		main();
	read.close();
}
void idSearch()
{
	string id;
	student s;
	bool found = false;
	cout << "\n	Enter ID / Roll Number of student : "; // REMINDER : convert upper to lower characters
	cin.ignore();
	getline(cin, id);
	ifstream read("d:\\student.txt"); // REMINDER : I should change the Path letter D to d
	if (read.fail())
	{
		cout << "\n	(ERROR: File not found)\n";
		main();
	}
	cout << "\n	---------------------------------";
	read >> s.sr;
	read >> s.rolNo;
	read.ignore();
	getline(read, s.name);
	getline(read, s.fname);
	read >> s.age;
	read >> s.gender;
	read.ignore();
	getline(read, s.department);
	getline(read, s.degree);
	read >> s.semester;
	read >> s.gpa;
	while (!read.eof())
	{
		if (s.rolNo == id)
		{
			found = true;
			print(s);
		}
		read >> s.sr;
		read >> s.rolNo;
		read.ignore();
		getline(read, s.name);
		getline(read, s.fname);
		read >> s.age;
		read >> s.gender;
		read.ignore();
		getline(read, s.department);
		getline(read, s.degree);
		read >> s.semester;
		read >> s.gpa;
	}
	if (!found)
		cout << "\n	(Sorry! Desired data not found)\n";
	char ch;
	cout << "\n	Do you want to SEARCH again? (y/n) : ";
	cin >> ch;
	cout << endl;
	if (ch == 'y' || ch == 'Y')
		idSearch();
	else
		main();
	read.close();
}
void degreeSearch()
{
	string deg;
	student s;
	bool found = false;
	cout << "\n	Enter the name of Program/Degree : "; // REMINDER : convert upper to lower characters
	cin.ignore();
	getline(cin, deg);
	ifstream read("d:\\student.txt"); // REMINDER : I should change the Path letter D to d
	if (read.fail())
	{
		cout << "\n	(ERROR: File not found)\n";
		main();
	}
	cout << "\n	---------------------------------";
	read >> s.sr;
	read >> s.rolNo;
	read.ignore();
	getline(read, s.name);
	getline(read, s.fname);
	read >> s.age;
	read >> s.gender;
	read.ignore();
	getline(read, s.department);
	getline(read, s.degree);
	read >> s.semester;
	read >> s.gpa;
	while (!read.eof())
	{
		if (s.degree == deg)
		{
			found = true;
			print(s);
		}
		read >> s.sr;
		read >> s.rolNo;
		read.ignore();
		getline(read, s.name);
		getline(read, s.fname);
		read >> s.age;
		read >> s.gender;
		read.ignore();
		getline(read, s.department);
		getline(read, s.degree);
		read >> s.semester;
		read >> s.gpa;
	}
	if (!found)
		cout << "\n	(Sorry! Desired data not found)\n";
	char ch;
	cout << "\n	Do you want to SEARCH again? (y/n) : ";
	cin >> ch;
	cout << endl;
	if (ch == 'y' || ch == 'Y')
		degreeSearch();
	else
		main();
	read.close();
}
void departSearch()
{
	string dpt;
	student s;
	bool found = false;
	cout << "\n	Enter the name of Department : "; // REMINDER : convert upper to lower characters
	cin.ignore();
	getline(cin, dpt);
	ifstream read("d:\\student.txt"); // REMINDER : I should change the Path letter D to d
	if (read.fail())
	{
		cout << "\n	(ERROR: File not found)\n";
		main();
	}
	cout << "\n	---------------------------------";
	read >> s.sr;
	read >> s.rolNo;
	read.ignore();
	getline(read, s.name);
	getline(read, s.fname);
	read >> s.age;
	read >> s.gender;
	read.ignore();
	getline(read, s.department);
	getline(read, s.degree);
	read >> s.semester;
	read >> s.gpa;
	while (!read.eof())
	{
		if (s.department == dpt)
		{
			found = true;
			print(s);
		}
		read >> s.sr;
		read >> s.rolNo;
		read.ignore();
		getline(read, s.name);
		getline(read, s.fname);
		read >> s.age;
		read >> s.gender;
		read.ignore();
		getline(read, s.department);
		getline(read, s.degree);
		read >> s.semester;
		read >> s.gpa;
	}
	if (!found)
		cout << "\n	(Sorry! Desired data not found)\n";
	char ch;
	cout << "\n	Do you want to SEARCH again? (y/n) : ";
	cin >> ch;
	cout << endl;
	if (ch == 'y' || ch == 'Y')
		departSearch();
	else
		main();
	read.close();
}
void genderSearch()
{
	char gen;
	student s;
	bool found = false;
	cout << "\n	Enter Gender (m/f/o) : "; // REMINDER : convert upper to lower characters
	cin >> gen;
	ifstream read("d:\\student.txt"); // REMINDER : I should change the Path letter D to d
	if (read.fail())
	{
		cout << "\n	(ERROR: File not found)\n";
		main();
	}
	cout << "\n	---------------------------------";
	read >> s.sr;
	read >> s.rolNo;
	read.ignore();
	getline(read, s.name);
	getline(read, s.fname);
	read >> s.age;
	read >> s.gender;
	read.ignore();
	getline(read, s.department);
	getline(read, s.degree);
	read >> s.semester;
	read >> s.gpa;
	while (!read.eof())
	{
		if (s.gender == gen)
		{
			found = true;
			print(s);
		}
		read >> s.sr;
		read >> s.rolNo;
		read.ignore();
		getline(read, s.name);
		getline(read, s.fname);
		read >> s.age;
		read >> s.gender;
		read.ignore();
		getline(read, s.department);
		getline(read, s.degree);
		read >> s.semester;
		read >> s.gpa;
	}
	if (!found)
		cout << "\n	(Sorry! Desired data not found)\n";
	char ch;
	cout << "\n	Do you want to SEARCH again? (y/n) : ";
	cin >> ch;
	cout << endl;
	if (ch == 'y' || ch == 'Y')
		genderSearch();
	else
		main();
	read.close();
}
void smrSearch()
{
	int smr;
	student s;
	bool found = false;
	cout << "\n	Enter Semester number : "; // REMINDER : convert upper to lower characters
	cin >> smr;
	ifstream read("d:\\student.txt"); // REMINDER : I should change the Path letter D to d
	if (read.fail())
	{
		cout << "\n	(ERROR: File not found)\n";
		main();
	}
	cout << "\n	---------------------------------";
	read >> s.sr;
	read >> s.rolNo;
	read.ignore();
	getline(read, s.name);
	getline(read, s.fname);
	read >> s.age;
	read >> s.gender;
	read.ignore();
	getline(read, s.department);
	getline(read, s.degree);
	read >> s.semester;
	read >> s.gpa;
	while (!read.eof())
	{
		if (s.semester == smr)
		{
			found = true;
			print(s);
		}
		read >> s.sr;
		read >> s.rolNo;
		read.ignore();
		getline(read, s.name);
		getline(read, s.fname);
		read >> s.age;
		read >> s.gender;
		read.ignore();
		getline(read, s.department);
		getline(read, s.degree);
		read >> s.semester;
		read >> s.gpa;
	}
	if (!found)
		cout << "\n	(Sorry! Desired data not found)\n";
	char ch;
	cout << "\n	Do you want to SEARCH again? (y/n) : ";
	cin >> ch;
	cout << endl;
	if (ch == 'y' || ch == 'Y')
		smrSearch();
	else
		main();
	read.close();
}
void deleteStudent()
{
	string delID;
	student s;
	char ch;
	bool deleted = false;

	cout << "\n	Do you want to delete record? (y/n) : ";
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
	{
		cout << "\n	- - > search & select the desired record to delete it\n";
		cout << "\n	Enter the Student's ID (Roll Number) : ";
		cin >> delID;

		ifstream read("d:\\student.txt");
		ofstream write("d:\\temp.txt"); // REMINDER : should I use app mode or not
		read >> s.sr;
		read >> s.rolNo;
		read.ignore();
		getline(read, s.name);
		getline(read, s.fname);
		read >> s.age;
		read >> s.gender;
		read.ignore();
		getline(read, s.department);
		getline(read, s.degree);
		read >> s.semester;
		read >> s.gpa;
		while (!read.eof())
		{
			if (s.rolNo == delID)
			{
				print(s);
				cout << "\n	Confirm to Delete this Record? (y/n) : ";
				cin >> ch;
				if (ch == 'y' || ch == 'Y')
				{
					deleted = true;
					goto yesDelete;
				}
				else
				{
					read.close();
					write.close();
					remove("d:\\temp.txt");
					cout << "\n	success! Record not deleted\n";
					cout << "\n	1 : Looking for another student?";
					cout << "\n	2 : Exit the Program 'overall'";
					cout << "\n	3 : Exit to the main menu";
					cout << "\n	- - > Enter Choice : ";
					cin >> ch;
					if (ch == '1')
						deleteStudent();
					else if (ch == '2')
					{
						cout << "\n 	(The Program Exited successfully!)\n"
							 << endl;
						exit(0);
					}
					else
						main();
				}
			}
		yesDelete:
			if (s.rolNo != delID)
			{
				write << s.sr << endl;
				write << s.rolNo << endl;
				write << s.name << endl;
				write << s.fname << endl;
				write << s.age << endl;
				write << s.gender << endl;
				write << s.department << endl;
				write << s.degree << endl;
				write << s.semester << endl;
				write << s.gpa << endl;
			}
			read >> s.sr;
			read >> s.rolNo;
			read.ignore();
			getline(read, s.name);
			getline(read, s.fname);
			read >> s.age;
			read >> s.gender;
			read.ignore();
			getline(read, s.department);
			getline(read, s.degree);
			read >> s.semester;
			read >> s.gpa;
		}
		read.close();
		write.close();
		remove("d:\\student.txt");
		rename("d:\\temp.txt", "d:\\student.txt");
		if (deleted)
			cout << "\n	( Desired Record Deleted successfully )\n";
		deleteStudent();
	}
	else
	{
		main();
	}
}
void updateStudent()
{
	char ch;
	cout << "\n	Do you want to update and change the records? (y/n) : ";
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
	{
		cout << "\n	Do you remember the ID or Roll Number of the student? (y/n) : ";
		cin >> ch;
		if (ch == 'y' || ch == 'Y')
		{
			string updtID;
			student s;
			bool updated = false;
			cout << "\n	Enter the ID / Roll Number : ";
			cin >> updtID;
			ifstream read("d:\\student.txt");
			if (read.fail())
			{
				cout << "\n	ERROR: File not accessed\n";
				main();
			}
			ofstream write("d:\\updated.txt");
			if (write.fail())
			{
				cout << "\n	ERROR: File not processed\n";
				main();
			}
			read >> s.sr;
			read >> s.rolNo;
			read.ignore();
			getline(read, s.name);
			getline(read, s.fname);
			read >> s.age;
			read >> s.gender;
			read.ignore();
			getline(read, s.department);
			getline(read, s.degree);
			read >> s.semester;
			read >> s.gpa;
			while (!read.eof())
			{
				if (s.rolNo == updtID) // the 1nd piece of code
				{
					print(s);
					cout << "\n	Confirm to update this? (y/n) : ";
					cin >> ch;
					if (ch == 'y' || ch == 'Y')
					{
						updated = true;
						student ns;
					notSure:
						cout << "\n	----------------------------------\n";
						cout << "\n		Enter the ID/Roll number : ";
						cin >> ns.rolNo;
						cout << "\n		Enter Student's Name : ";
						cin.ignore();
						getline(cin, ns.name);
						cout << "\n		Enter Father's Name : ";
						getline(cin, ns.fname);
						cout << "\n		Enter Age : ";
						cin >> ns.age;
						cout << "\n		Enter Gender : ";
						cin >> ns.gender;
						cout << "\n		Enter Department : ";
						cin.ignore();
						getline(cin, ns.department);
						cout << "\n		Enter Program/Degree : ";
						getline(cin, ns.degree);
						cout << "\n		Enter Semester : ";
						cin >> ns.semester;
						cout << "\n		Enter CGPA : ";
						cin >> ns.gpa;
						cout << "\n		Do you want to change the serial number (listing number) of this student? (y/n) : ";
						cin >> ch;
						if (ch == 'y' || ch == 'Y')
						{
							cout << "\n		 Enter the new Sr. Number you want to assign : ";
							cin >> ns.sr;
						}
						else
						{
							ns.sr = s.sr;
						}
						cout << "\n\n		Are you sure for this new record? (y/n) : ";
						cin >> ch;
						if (ch == 'y' || ch == 'Y')
						{
							write << ns.sr << endl;
							write << ns.rolNo << endl;
							write << ns.name << endl;
							write << ns.fname << endl;
							write << ns.age << endl;
							write << ns.gender << endl;
							write << ns.department << endl;
							write << ns.degree << endl;
							write << ns.semester << endl;
							write << ns.gpa << endl;
						}
						else
						{
							cout << "\n		OK. Put the data again, carefully!\n";
							goto notSure;
						}
						goto yesUpdated; // to avoid creating infinite loop in this block
					}
					else
					{
						read.close();
						write.close();
						remove("d:\\updated.txt");
						cout << "\n	0 : Input another ID/Roll Number";
						cout << "\n	1 : Search for other student";
						cout << "\n	2 : Return to main menu";
						cout << "\n	3 : Exit the Program";
						cout << "\n	Enter Choice : ";
						cin >> ch;
						switch (ch)
						{
						case '0':
							goto searchAgain;
							break;
						case '1':
							goto searchAgain;
							break;
						case '2':
							main();
							break;
						case '3':
							exit(0);
							break;
						default:
							cout << "\n	ERROR: invalid choice\n";
							updateStudent();
							break;
						}
					}
				}
				else // the 2nd piece of code
				{
					write << s.sr << endl;
					write << s.rolNo << endl;
					write << s.name << endl;
					write << s.fname << endl;
					write << s.age << endl;
					write << s.gender << endl;
					write << s.department << endl;
					write << s.degree << endl;
					write << s.semester << endl;
					write << s.gpa << endl;
				}
			yesUpdated:
				read >> s.sr;
				read >> s.rolNo;
				read.ignore();
				getline(read, s.name);
				getline(read, s.fname);
				read >> s.age;
				read >> s.gender;
				read.ignore();
				getline(read, s.department);
				getline(read, s.degree);
				read >> s.semester;
				read >> s.gpa;
			}
			read.close();
			write.close();
			remove("d:\\student.txt");
			rename("d:\\updated.txt", "d:\\student.txt");
			if (updated)
				cout << "\n		( success! record updated for the student # " << updtID << " )\n";
			else
			{
				cout << "\n		Sorry, This ID/Roll Number doesn't exist in the Record!\n";
			}
			updateStudent();
		}
		else if (ch == 'n' || ch == 'N')
		{
		searchAgain:
			cout << "\n		Select a Method to Search for Desired Student : \n";
			searchStudent();
		}
		else
		{
			cout << "\n	ERROR: invalid choice!\n";
			updateStudent();
		}
	}
	else
	{
		cout << "\n	1 : Return to the main menu";
		cout << "\n	2 : Close & Exit the Program";
		cout << "\n	Enter Choice : ";
		cin >> ch;
		if (ch == '1')
			main();
		else if (ch == '2')
		{
			cout << "\n		(Program Exited successfully)\n"
				 << endl;
			exit(0);
		}
		else
		{
			cout << "\n	Invalid Choice!\n";
			updateStudent();
		}
	}
}

// Description :	A final terms Project for semester (3rd) on basic concepts of filing & strings handling
// Student (Coder) :	Muhammad Afnan # IT2130 # 3rd semester
// Teacher (Programmer) :	Professor Muhammad Abid # Government Graduate College (boys), Leiah
//																										(MAi)