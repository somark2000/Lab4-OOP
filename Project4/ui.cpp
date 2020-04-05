#include <iostream>
#include "ui.h"
#include "controller.h"
#include "domain.h"
#include "repo.h"

using namespace std;

void ui::Menu()
{
	cout << "Possible commands: " << endl;
	cout << "\t 1 - Add Medicine." << endl;
	cout << "\t 2 - Delete Medicine" << endl;
	cout << "\t 3 - Update." << endl;
	cout << "\t 4 - Display all" << endl;
	cout << "\t 5 - Display by quantity" << endl;
	cout << "\t 6 - Display by price" << endl;
	cout << "\t 7 - Undo" << endl;
	cout << "\t 8 - Redo" << endl;
	cout << "\t 0 - Exit." << endl;
}


void ui::run()
{
	while (true)
	{
		ui::Menu();
		repo* repo;
		int commandRepo{ 0 };
		cout << "Input the command: ";
		cin >> commandRepo;
		cin.ignore();
		if (commandRepo == 0)
			break;
		switch (commandRepo)
		{
		/*
		case 1:
		case 2:
		case 3:
		case 4:
		*/
		case 5:
			repo->preis_sort();
			break;
		case 6:
			cout << "Enter quantity:";
			int quantity;
			cin >> quantity;
			repo->menge_sort(quantity);
			break;
		case 7:
			repo->undo();
			cout << "Undo successful." << endl;
			break;
		case 8:
			repo->redo();
			break;
		}
	}
}