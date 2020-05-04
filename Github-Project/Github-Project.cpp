// ConsoleApplication6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
const int NUM = 6;
int n;
struct Student
{
	string firstName;
	string secondName;
	string lastName;
	char EGN[11];
	double marks[NUM];
	float a;
}students[100];
int displayMenu();
void beginProgram();
void read_student(Student& students);
void insertDate(Student* students);
void print_student(Student& student);
void output(Student* students);
double average(double* a);
void sortStudents(int n, Student a[]);
void print_student_success(Student& student);
void output_success(Student* students);
void output_success_best(Student* students);

int main()
{
	cout << setprecision(2) << setiosflags(ios::fixed);
	cout << "Number of students: ";
	cin >> n;
	beginProgram();
	cout << endl << endl;
	return 0;
}

int displayMenu()
{
	int ch;
	cout << "\n\n MENU: \n ";
	cout << "\n 1.Entering data for students: \n";
	cout << "\n 2.Output data for the whole class: \n";
	cout << "\n 3.List of students by success with all the data: \n";
	cout << "\n 4.List of students by success: \n";
	cout << "\n 5.List of students by excellent success: \n";
	cout << "\n 100 for END  \n";
	cout << "\n Select  ";
	cin >> ch;
	return(ch);
}

void beginProgram()
{
	int j;
	do {
		j = displayMenu();
		switch (j)
		{
		case 1:insertDate(students); 
			break;
		case 2:output(students); 
			break;
		case 3:sortStudents(n, students); 
			output(students); 
			break;
		case 4:output_success(students); 
			break;
		case 5:output_success_best(students); 
			break;
		case 100: cout << "\n END"; 
			break;
		}
	} while (j != 100);
}

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
	for (int i = 0; i <= NUM - 1; i++)
	{
		cout << i + 1 << " -th mark: ";
		cin >> students.marks[i];
	}
}

void insertDate(Student* students)  //, int &studentsCount)
{
	int i;

	for (i = 0; i < n; i++)
		read_student(students[i]);
}

void print_student(Student& student)
{
	cout << setw(10) << student.firstName << " ";
	cout << setw(15) << student.secondName << " ";
	cout << setw(15) << student.lastName << " ";
	cout << setw(14) << student.EGN << " ";
	for (int i = 0; i <= NUM - 1; i++)
	{
		cout << setw(6) << student.marks[i];
	}
}

void print_student_success(Student& student)
{
	cout << setw(10) << student.firstName << " ";
	cout << setw(15) << student.secondName << " ";
	cout << setw(15) << student.lastName << " ";

}

void output(Student* students)
{
	int i;
	cout << setw(12) << "first name";
	cout << setw(15) << "secondName";
	cout << setw(15) << "lastName";
	cout << setw(12) << "EGN";
	cout << setw(10) << "BEL";
	cout << setw(5) << "MAT";
	cout << setw(7) << "ENG";
	cout << setw(6) << "CHM";
	cout << setw(6) << "BIO";
	cout << setw(5) << "PHY";
	cout << setw(17) << "Average success" << endl;
	for (i = 0; i < n; i++)
	{
		print_student(students[i]);
		cout << setw(7) << average(students[i].marks);
		cout << endl;
	}
	cout << endl;
}

void output_success(Student* students)
{
	int i;
	cout << setw(12) << "first name";
	cout << setw(15) << "secondName";
	cout << setw(15) << "lastName";
	cout << setw(17) << "Average success" << endl;
	for (i = 0; i < n; i++)
	{
		print_student_success(students[i]);
		cout << setw(7) << average(students[i].marks);
		cout << endl;
	}
	cout << endl;
}

void output_success_best(Student* students)
{
	int i;
	cout << setw(12) << "first name";
	cout << setw(15) << "secondName";
	cout << setw(15) << "lastName";
	cout << setw(17) << "Average success" << endl;
	for (i = 0; i < n; i++)
	{
		if (average(students[i].marks) >= 5.50)
		{
			print_student_success(students[i]);
			cout << setw(7) << average(students[i].marks);
			cout << endl;
		}
	}
	cout << endl;
}

double average(double* a)
{
	double s = 0;
	for (int j = 0; j < NUM; j++)
		s += a[j];
	return s / NUM;
}

void sortStudents(int n, Student a[])
{

	for (int i = 0; i <= n - 2; i++)
	{
		int k = i;
		double max = average(a[i].marks);
		for (int j = i + 1; j <= n - 1; j++)
			if (average(a[j].marks) > max)
			{
				max = average(a[j].marks);
				k = j;
			}
		Student x = a[i]; a[i] = a[k]; a[k] = x;
	}
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
