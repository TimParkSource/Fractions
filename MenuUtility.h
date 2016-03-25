#pragma once
#include <iostream>
#include "FractionList.h"
#include "FileManagement.h"
using namespace std;

class MenuUtility
{
public:

	static void accountManagement(FractionList & FL)
	{
		bool done = false;
		int choice = 0;

		ifstream in;
		FileManagement::getValidInputFile(in);
		FractionList::getInstance(FL, in);
		in.close();

		do
		{
			cout << "***Output Menu***" << endl;
			cout << "[1] Write student list to a file:\n"
				 << "[2] Print student list to console:\n"
				 << "[3] Exit" << endl;
			cin >> choice;

			if (choice == 3)
			{
				done = true;
			}
			else if (choice == 1)
			{
				if (FL.isEmpty())
				{
					cout << "List is empty" << endl;
					done = false;
					continue;
				}
				else
				{
					FileManagement::giveOutputFileInstructions();
					ofstream out;
					FileManagement::getValidOutputFile(out);
					FL.printHeader(out);
					out << FL.toString() << endl;
					out << "Number of Fractions in this list: " << FL.getNumber_of_elements() << endl;
					FL.printStatistics(out);
					out.close();
					done = false;
					continue;
				}
			}
			else if (choice == 2)
			{
				if (FL.isEmpty())
				{
					cout << "List is empty" << endl;
					done = false;
					continue;
				}
				else
				{
					FL.printHeader();
					FL.print(cout);
					cout << "Number of Fractions in this list: " << FL.getNumber_of_elements() << endl;
					FL.printStatistics(cout);
					done = false;
					continue;
				}
			}
			else
			{
				cout << "Invalid choice." << endl;
				done = false;
				continue;
			}
		} while (!done);
	}	

};