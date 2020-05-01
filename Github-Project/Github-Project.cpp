// ConsoleApplication6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int n, studentsCount, k;
struct Student
{
	string firstName;
	string secondName;
	string lastName;
	char EGN[11];
	int BEL;
	int MAT;
	int ENG;
	int CHEMISTRY;
	int BIOLOGY;
	int PHYSICS;
	float a;
};

void read_student(Student& students)
{
	cout << "First name:  ";
	cin >> students.firstName;
	cout << "Second name:  ";
	cin >> students.secondName;
	cout << "Last name:  ";
	cin >> students.lastName;
	cout << "EGN: ";
	cin >> students.EGN;
	cout << "BEL: ";
	cin >> students.BEL;
	cout << "MAT: ";
	cin >> students.MAT;
	cout << "ENG: ";
	cin >> students.ENG;
	cout << "CHEMISTRY: ";
	cin >> students.CHEMISTRY;
	cout << "BIOLOGY: ";
	cin >> students.BIOLOGY;
	cout << "PHYSICS: ";
	cin >> students.PHYSICS;
}


void insertDate(Student* students)  //, int &studentsCount)
{
	int i;

	for (i = 0; i < n; i++)
		read_student(students[i]);

	//studentsCount++;
}

void print_student(Student& student)
{
	cout << setw(10) << student.firstName << " ";
	cout << setw(15) << student.secondName << " ";
	cout << setw(15) << student.lastName << " ";
	cout << setw(14) << student.EGN << " ";
	cout << setw(5) << student.BEL << " ";
	cout << setw(6) << student.MAT << " ";
	cout << setw(6) << student.ENG << " ";
	cout << setw(10) << student.CHEMISTRY << " ";
	cout << setw(10) << student.BIOLOGY << " ";
	cout << setw(8) << student.PHYSICS << endl;
	//cout<<students[i].a;
}

void output(Student* students)
{
	int i;
	cout << setw(12) << "first name";
	cout << setw(15) << "secondName";
	cout << setw(15) << "lastName";
	cout << setw(12) << "EGN";
	cout << setw(10) << "BEL";
	cout << setw(7) << "MAT";
	cout << setw(7) << "ENG";
	cout << setw(12) << "CHEMISTRY";
	cout << setw(12) << "BIOLOGY";
	cout << setw(10) << "PHYSICS" << endl;
	for (i = 0; i < n; i++)
		print_student(students[i]);
}

int main()
{
	Student students[100];


	cout << "Number of students: ";
	cin >> n;
	insertDate(students);
	output(students);

	for (int i = 0; i < n; i++)
	{
		float s;
		s = 1.0 * (students[i].BEL + students[i].MAT + students[i].ENG + students[i].CHEMISTRY + students[i].BIOLOGY + students[i].PHYSICS) / 6;
		students[i].a = s;
	}



	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
