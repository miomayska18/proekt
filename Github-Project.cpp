// Github-Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct TOY {
	string toyName;
	float price;
	int id;
	int startAge; //start and end age are for the age range for a toy
	int endAge; //example: (0-3) years
	string genderForToy;
};

//functional stuff????

void createToy(TOY* toys, int& toyCount, int& maxId, TOY newToy) {
	newToy.id = maxId++;
	toys[toyCount] = newToy;
	toyCount++;
}

TOY getToy(TOY* toys, int& toyCount, int& toyId) {
	for (int i = 0; i < toyCount; i++)
	{
		if (toys->id == toyId)
		{
			return toys[i];
		}
	}
}

int getToyIndexById(TOY* toys, int& toyCount, int id) {
	for (int i = 0; i < toyCount; i++)
	{
		if (toys[i].id == id) {
			return id;
		}
	}
}

void updateToy(TOY* toys, int toyCount, int id, TOY newToy) {
	int index = getToyIndexById(toys, toyCount, id);
	toys[index] = newToy;
}

void deleteToy(TOY* toys, int& toyCount, int id) {
	int index = getToyIndexById(toys, toyCount, id);

	for (int i = index; i < toyCount - 1; i++)
	{
		toys[i] = toys[i + 1];
	}
	toyCount--;
}

//presentation layer?????

void showToysMenu(TOY* toys, int& toyCount, int& maxId) {
	cout << "\nList of all the toys in the store! " << endl;
	for (int i = 0; i < toyCount; i++)
	{
		cout << toys[i].toyName << ": " << toys[i].id << ", (" << toys[i].startAge << "-" << toys[i].endAge << ") years" << endl;
	}
}

void createToyMenu(TOY* toys, int& toyCount, int& maxId) {
	TOY toy;
	cout << "Enter toy name: ";
	cin >> toy.toyName;

	cout << "Enter toy price: ";
	cin >> toy.price;

	cout << "Enter toy id: ";
	cin >> toy.id;

	cout << "Enter toy age range: " << endl;
	cout << "From: ";
	cin >> toy.startAge;
	cout << " years" << endl;
	cout << "To: ";
	cin >> toy.endAge;
	cout << " years" << endl;

	cout << "Enter target gender: girls/boys/both" << endl;
	cin >> toy.genderForToy;

	createToy(toys, toyCount, maxId, toy);
}

void editToyMenu(TOY* toys, int& toyCount) {
	int toyId;
	cout << "Enter toy id: ";
	cin >> toyId;

	TOY toy = getToy(toys, toyCount, toyId);

	cout << "1. Toy Name" << endl;
	cout << "2. Price" << endl;
	cout << "3. Id" << endl;
	cout << "4. Start of age range" << endl;
	cout << "5. End of age range" << endl;
	cout << "6. Target gender (for girls/boys/both)" << endl;
	cout << "Which field do you want to edit: " << endl;

	int field;
	cin >> field;

	switch (field)
	{
	case 1:
		cout << "1. Toy Name: ";
		cin >> toy.toyName;
		updateToy(toys, toyCount, toyId, toy);
		break;
	case 2:
		cout << "2. Price: ";
		cin >> toy.toyName;
		updateToy(toys, toyCount, toyId, toy);
		break;
	case 3:
		cout << "3. Id: ";
		cin >> toy.toyName;
		updateToy(toys, toyCount, toyId, toy);
		break;
	case 4:
		cout << "4. Start of age range: ";
		cin >> toy.toyName;
		updateToy(toys, toyCount, toyId, toy);
		break;
	case 5:
		cout << "5. End of age range: ";
		cin >> toy.toyName;
		updateToy(toys, toyCount, toyId, toy);
		break;
	case 6:
		cout << "6. Target gender (for girls/boys/both): ";
		cin >> toy.toyName;
		updateToy(toys, toyCount, toyId, toy);
		break;
	default:
		cout << "Invalid field!" << endl;
		break;
	}
}

void deleteToyMenu(TOY* toys, int& toyCount, int& maxId) {
	int toyId;

	cout << "Enter toy Id: ";
	cin >> toyId;

	deleteToy(toys, toyCount, toyId);
}

//void showReportsMenu(/*stuff*/) {
//
//}

bool showMainMenu(TOY* toys, int& toyCount, int& maxId)
{
	int option;
	cout << "\nChoose an option from the menu below:" << endl;
	cout << "1. Show Toys" << endl;
	cout << "2. Add Toys" << endl;
	cout << "3. Edit toy data" << endl;
	cout << "4. Delete Toys" << endl;
	//cout << "5. Reports" << endl;
	cout << "9. Exit." << endl;
	cout << "Enter the option, which you want to use: ";

	cin >> option;

	switch (option)
	{
	case 1:
		showToysMenu(toys, toyCount, maxId);
		break;
	case 2:
		createToyMenu(toys, toyCount, maxId);
		break;
	case 3:
		editToyMenu(toys, toyCount);
		break;
	case 4:
		deleteToyMenu(toys, toyCount, maxId);
		break;
		//case 5:
		//	;
		//	break;
	case 9:
		return false;
	}
	return true;
}

int main()
{
	int toyCount = 0;
	int maxId = 0;

	TOY toys[100];

	bool doShowMenu;

	do {
		doShowMenu = showMainMenu(toys, toyCount, maxId);
	} while (doShowMenu);
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
