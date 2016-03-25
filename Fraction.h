#pragma once

#ifndef Fraction_H

#define Fraction_H

#include <iostream>
#include <fstream>
#include<string>
#include <sstream>
#include <stdexcept>
#include <iomanip>
using namespace std;

class Fraction
{
private:
	long Numerator;
	long Denominator;

public:
	Fraction (long Top = 0, long Bottom= 1); 
	
	//void printData(ostream& out) const; need print?

	Fraction operator --();//pre-decrement
	Fraction operator ++();//pre-increment
	Fraction operator --(int marker); // post decrement Marker will not be used.
	Fraction operator ++(int marker); // Marker will not be used.
	long getTop() const;
	long getBottom() const;
	void normalize();
	double toDouble() const;
	long gcd(long a, long b);
	string toString() const;
	friend const Fraction operator+ (const Fraction & num1, const Fraction & num2);
	friend const Fraction operator- (const Fraction & num1, const Fraction & num2);
	friend const Fraction operator* (const Fraction & num1, const Fraction & num2);
	friend const Fraction operator/ (const Fraction & num1, const Fraction & num2);
	friend bool operator== (const Fraction & num1, const Fraction & num2);
	friend bool operator!= (const Fraction & num1, const Fraction & num2);
	friend ostream & operator<< (ostream & output, const Fraction & num);
	friend istream & operator>> (istream & input, Fraction & num);
	static void getInstance(istream & input, Fraction & Temp);
	void print(ostream & printStream) const;
	Fraction operator += ( const Fraction & Num );  // extra credit
	Fraction operator -= ( const Fraction & Num );
	Fraction operator *= ( const Fraction & Num );
	Fraction operator /= ( const Fraction & Num );
};
#endif
