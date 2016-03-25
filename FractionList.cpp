#include "FractionList.h"
#include <cmath>

FractionList::FractionList()
{
	for (unsigned int index = 0; index < MAX; index++)
	{
		List[index] = Fraction();
	}
	number_of_elements = 0;
}
const string FractionList::toString() const 
{
	if (number_of_elements == 0)
	{
		return "The list is empty.\n";
	}
	else
	{
		string Text = "";

		for (unsigned int index = 0; index < number_of_elements; index++)
		{
			Text += List[index].toString(); 
		}

		return Text;
	}
}
void FractionList::print(ostream &  PS) const
{
	for (unsigned int index = 0; index < number_of_elements; index++) 
	{
		PS<<List[index].toString();
	}
}
void FractionList::getSumMeanFraction(Fraction & sum, Fraction & num2) const
{
	if (number_of_elements == 0)
	{
		cout << "List is Empty. No mean can be found." << endl;
		return;
	}
	
	if (number_of_elements > 1)
	{
		sum = List[0];
		
		for (unsigned int index = 1; index < number_of_elements; index++)
		{
			num2 = List[index];

			sum = num2 + sum; 
		}
	}
	//sum.normalize();                   // normalize not working ----------------------------
	long simple = number_of_elements;
	num2 = sum / simple; 
	//num2.normalize();                // normalize not working ----------------------------

}
void FractionList::printStatistics(ostream & out )
{
	Fraction F1;
	Fraction F2;
	this->getSumMeanFraction(F1, F2);
	F1.normalize();
	F2.normalize();
	out << fixed << showpoint << setprecision(2);
	out << "Sum of Fractions: " << F1 << endl;
	out << "Decimal:          " << F1.toDouble() << endl;
	out << "Mean of Fractions:" << F2 << endl;
	out << "Decimal:          " << F2.toDouble() << endl;
	out<<"**************************************************************************"<<endl;
}
//works
int FractionList::getNumber_of_elements() const
{
	return number_of_elements;
} 
unsigned  int FractionList::getMAX()
{
return MAX;
} 
void FractionList::getInstance(FractionList & FL, ifstream & Scn)
{
	unsigned int index = 0;
	while (index < MAX && (!Scn.eof()))
	{
		Fraction::getInstance(Scn, FL.List[index++]);
		FL.number_of_elements++;
	}
}
bool FractionList::isEmpty() const
{
	return number_of_elements == 0;

}
void FractionList::printHeader(ostream & out)  // change this to fraction and decimal
{
	out << "**********************************************************\n"
		<< "Name: Timothy Park\n"
		<< "Date: 10/1/14\n"
		<< "Email: timothy_park@elcamino.edu\n"
		<< "Assignment #: 2\n"
		<< "Section #: 122\n"
		<< "**********************************************************\n";
	out << endl << "******************************************************************************" << endl;
	out << "Fractions and decimals are listed below" << endl
		<< "******************************************************************************" << endl;
}
/*bool FractionList::addFraction(const Fraction & Std)
{
	bool flag = false;

	if (number_of_elements == MAX)
	{
		flag = false;
		cout << "List is full. New fraction is not added." << endl;
	}
	else
	{
		List[number_of_elements++] = Std;
		flag = true;
	}
	return flag;
}
void FractionList::getFractionList(FractionList & FL) const
{
	if (number_of_elements == 0)
	{
		cout << ("List is empty") << endl;
	}


	for (unsigned int index = 0; index < number_of_elements; index++)
	{

		FL.addFraction(List[index]);
	}
} */