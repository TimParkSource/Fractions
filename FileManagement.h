#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>
using namespace std;

class FileManagement
{
private:
	static void TrimSpaces(string& str)
	{
		size_t startpos = str.find_first_not_of(" \t");  
		size_t endpos = str.find_last_not_of(" \t"); 

		if ((string::npos == startpos) || (string::npos == endpos))
		{
			str = "";
		}
		else
			str = str.substr(startpos, endpos - startpos + 1);
	}
public:

	static void getValidOutputFile(ofstream & Out)
	{
		bool done = false;
		string Out_File;
		int val = cin.sync();

		if (val == -1)
		{
			cin.clear();
			cin.ignore(128, '\n');
		}


		while (!done)
		{
			cout << "Please type the name of the file to which results are to be written to: ";
			getline(cin, Out_File);
			TrimSpaces(Out_File);
			cout << "The file name entered is : " << Out_File << endl;
			Out.open(Out_File, ios::app);

			if (Out.fail())
			{
				Out.close();
				cout << "Failed to create the output file.\n";
				cout << "Do you want to try again? 1 to retry, 0 to exit\n";
				int choice;
				cin >> choice;
				if (choice == 0)
				{
					exit(1);
				}
				else if (choice == 1)
				{
					ofstream ou;
					getValidOutputFile(ou);
					break;
				}
			}
			else
			{
				done = true;
			}
		}
	}

	static void getValidInputFile(ifstream & input)
	{
		char ch = char();
		bool done = false;
		string In_File;
		int val = cin.sync();

		if (val == -1)
		{
			cin.clear();
			cin.ignore(128, '\n');
		}

		while (!done)
		{
			input.clear();
			cout << "Please make sure none of your denominators are zeros otherwise your\nfraction wil be undefined.\nPlease input the name of the data file to be read.\n: ";
			getline(cin, In_File);
			TrimSpaces(In_File);
			cout << "The file name entered is : " << In_File << endl;
			input.open(In_File);

			if (input.fail())
			{
				input.clear();
				cout << "The file does not exist, or does not have read permission.\n";
				cout << "Do you want to try again? 1 to retry, 0 to exit\n";
				int choice;
				cin >> choice;
				if (choice == 0)
				{
					exit(1);
				}
				else if (choice == 1)
				{
					ifstream in;
					getValidInputFile(in);
					break;
				}
			}
			else
			{
				ch = input.peek();//peek gets copy of first character.

				if (ch == EOF)
				{
					input.close();
					cout << "The file has no data in it\n";
					cout << "Do you want to try again? 1 to retry, 0 to exit\n";
					int choice;
					cin >> choice;
					if (choice == 0)
					{
						exit(1);
					}
					else if (choice == 1)
					{
						ifstream in;
						getValidInputFile(in);
						break;
					}
				}
				else
					done = true;
			}
		}
	}

	static void giveOutputFileInstructions()
	{
		cout << "*********************************************************************\n";
		cout << "You will be asked to provide output file name which must be valid\n"
			<< "for Windows operating syetem. Following 11 file names are invalid.\n"
			<< "1. Aux, 2. Com1, 3. Com2, 4. Com3, 5. Com4, 6. Con, 7. Lpt1, 8. Lpt2\n"
			<< "9. Lpt3, 10. Prn, 11. Nul.\n"
			<< "A. The output file for above 11 names (case sensitivity ignored) will not\n"
			<< "be created. And program behavior would be unpredictable.\n"
			<< "B. In addition the filenames with first character as dot(.) are also invalid.\n"
			<< "C. If last character in the filename is a dot (.) then dot is ignored.\n"
			<< "    For example the filename xyz. is taken as xyz\n"
			<< "D. In Windows XP etc., maximum full path characters in filename can be 255.\n";
		cout << "*********************************************************************\n";
	}

};