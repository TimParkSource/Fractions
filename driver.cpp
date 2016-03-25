#include <iomanip>
#include <ctime>
#include <cstdlib>
#include "Fraction.h"
#include "FractionList.h"
#include "MenuUtility.h"
using namespace std;

int maintest();
int main()//menu driven
{
	maintest();
	//Assignment Code ------------------------------------------------------------
	FractionList FL;

	MenuUtility::accountManagement(FL);

	system("pause");
	return 0;
	
} 


int maintest()
{
	cout << "The first name a does not have enough characters.\nWe will set first name to a default value of \"First name not set.\"" << endl; // fix this thing check last page of assignment fix for first, last and salary
	//test material ------change to main to test
	Fraction Num1(1, 2);
	Fraction Num2(2, 4); 
	Fraction Num3(5, 25);
	Fraction Num5(1, 2);
	Fraction Num4;

	Num3+=Num1;
	Num3.normalize ();
	cout << Num3 << endl;
	Num3-=Num1;
	Num3.normalize();
	cout << Num3 << endl;
	Num3*=Num1;
	Num3.normalize();
	cout << Num3 << endl;
	Num3/=Num1;
	Num3.normalize();
	cout << Num3 << endl;

	Num4 = Num1 + Num2;
	cout << Num4 << endl;
	Num4 = Num2 - Num3;
	cout << Num4 << endl;
	Num4 = Num2 * Num2;
	cout << Num4 << endl;
	Num4 = Num1 / Num3;
	cout << Num4 << endl;

	cout << "Before: " << "Pre++ " << Num1 << endl;
	++Num1;
	cout << "After: " << "Pre++ " << Num1 << endl;
	cout << "Before: " << "post++ " << Num1 << endl;
	Num1++;
	cout << "After: " << "post++ " << Num1 << endl;
	cout << "Before: " << "Pre--" << Num1 << endl;
	--Num1;
	cout << "After: " << "Pre-- " << Num1 << endl;
	cout << "Before: " << "post-- " << Num1 << endl;
	Num1--;
	cout << "After: " << "post-- " << Num1 << endl;

	if (Num1 == Num5)
	{
		cout << "Num1 == Num5 == operator is working fine" << endl;
	}
	else
	{
		cout << "Num1 == Num5 == operator is broken" << endl;
	}
	if (Num1 == Num3)
	{
		cout << "Num1 == Num3 == operator is broken" << endl;
	}
	else
	{
		cout << "Num1 == Num3 == operator is working fine" << endl;
	}

	if (Num1 != Num5)
	{
		cout << "Num1 != Num5 != operator is broken" << endl;
	}
	else
	{
		cout << "Num1 != Num5 != operator is working fine" << endl;
	}

	if (Num1 != Num3)
	{
		cout << "Num1 != Num3 != operator is working fine" << endl;
	}
	else
	{
		cout << "Num1 != Num3 != operator is broken" << endl;
	}

	system("pause");
	return 0;
}