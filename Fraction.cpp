#include "Fraction.h"

Fraction::Fraction (long Top, long Bottom):Numerator(Top), Denominator(Bottom)
{

}

Fraction Fraction::operator --()
{
	Numerator -= Denominator;
	return Fraction(Numerator, Denominator);
}
Fraction Fraction::operator ++()
{
	Numerator += Denominator;
	return Fraction(Numerator, Denominator);
}
Fraction Fraction::operator --(int marker)
{
	long temp_Numerator = Numerator;
	long temp_Denominator = Denominator;
	Numerator -= Denominator;
	return Fraction(temp_Numerator, temp_Denominator);
}
Fraction Fraction::operator ++(int marker)
{
	long temp_Numerator = Numerator;
	long temp_Denominator = Denominator;
	Numerator += Denominator;
	return Fraction(temp_Numerator, temp_Denominator);
}

long Fraction::getTop() const
{
	return Numerator;
}

long Fraction::getBottom() const
{
	return Denominator;
}

void Fraction::normalize()
{
	// working as planned
	long simply = gcd(Numerator, Denominator);
	Numerator = Numerator / simply;
	Denominator = Denominator / simply;
}
double Fraction::toDouble() const
{
	// working as planned
	//double nu = Numerator;
	//double de = Denominator;
	//double decimal = nu / de;
	//return decimal;
	return static_cast<double>(this->Numerator)/this->Denominator;
}
long Fraction::gcd(long a, long b)
{
	// working as planned
	while (b != 0) 
	{
		long remainder = a % b;
		a = b;
		b = remainder;
	}
	return a;
}
string Fraction::toString() const
{
	// working as planned
	ostringstream os;

	os<<fixed<<showpoint<<setprecision(2);
	os<<"Fraction:"<<Numerator << "/" << Denominator <<endl << "Decimal: " << toDouble() << endl << "--------------------------------------" << endl;
	return os.str();
}

/*void Fraction::print(ostream & printStream) const
{
	Fraction F;
	printStream << "Fraction: " << F << endl;
	printStream << "Decimal: " << toDouble() << endl;
	
}*/
const Fraction operator+ (const Fraction & num1, const Fraction & num2)
{
	return Fraction(num1.Numerator*num2.Denominator + num2.Numerator*num1.Denominator, num1.Denominator*num2.Denominator);
}
const Fraction operator- (const Fraction & num1, const Fraction & num2)
{
	return Fraction(num1.Numerator*num2.Denominator - num2.Numerator*num1.Denominator, num1.Denominator*num2.Denominator);
}
const Fraction operator* (const Fraction & num1, const Fraction & num2)
{
	return Fraction(num1.Numerator*num2.Numerator, num1.Denominator*num2.Denominator);
}
const Fraction operator/ (const Fraction & num1, const Fraction & num2)
{
	if (num2.Numerator != 0)
	{
		return Fraction(num1.Numerator*num2.Denominator, num1.Denominator*num2.Numerator);
	}
	else
	{
		return 0;
	}
}
bool operator== (const Fraction & num1, const Fraction & num2)
{
	/*if ((num1.Numerator == num2.Numerator) && (num1.Denominator == num2.Denominator))
	{
		return true;
	}
	else
	{
		return false;
	}*/
	return ((num1.Numerator == num2.Numerator) && (num1.Denominator == num2.Denominator));
}
bool operator!= (const Fraction & num1, const Fraction & num2)
{
	/*if ((num1.Numerator != num2.Numerator) || (num1.Denominator != num2.Denominator))
	{
		return true;
	}
	else
	{
		return false;
	}*/

	return !((num1.Numerator == num2.Numerator) && (num1.Denominator == num2.Denominator));
}
ostream & operator<< (ostream & output, const Fraction & num)
{
	if (num.Denominator == 0)
	{
		output << "Undefined"; 
	}

	int negative;
	negative = num.Numerator * num.Denominator; 

	if (negative < 0)
	{
		if (num.Denominator == 1)
		{
			output << "-" << abs(num.Numerator);
		}
		else
		{
			output << "-" << abs(num.Numerator) << "/" << abs(num.Denominator);
		}
	}
	else
	{
		if (num.Denominator == 1)
		{
			output << num.Numerator;
		}
		else
		{
			output << num.Numerator << "/" << num.Denominator;
		}
	}

	return output;
}
istream & operator>> (istream & input, Fraction & num)
{
	// working as planned
	if (&input == &std::cin)
	{
		cout<<"Enter the numerator.\n";
		cin>>num.Numerator;
		cout<<"Enter the denominator.\n";
		cin>>num.Denominator;
	}
	else
	{
		input>>num.Numerator;
		input>>num.Denominator;
	}
	num.normalize();
	return input;
}

void Fraction::getInstance(istream & input, Fraction & Temp)
{
	// working as planned
	input>>Temp;
}
Fraction Fraction::operator += ( const Fraction & Num )   // extra credit
{
	*this = *this + Num;
	return *this;
}
Fraction Fraction::operator -= ( const Fraction & Num )   // extra credit
{
	*this = *this - Num;
	return *this;
}
Fraction Fraction::operator *= ( const Fraction & Num )   // extra credit
{
	*this = *this * Num;
	return *this;
}
Fraction Fraction::operator /= ( const Fraction & Num )   // extra credit
{
	*this = *this / Num;
	return *this;
}
