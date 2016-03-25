#pragma once
#ifndef FRACTIONLIST_H
#define FRACTIONLIST_H
#include "Fraction.h"

class FractionList
{
private:
	const static int MAX = 30;
	Fraction List[MAX];
	unsigned  int number_of_elements;
public:
	FractionList();
	void makeEmpty();
	bool isFull() const;
	bool isEmpty() const;
	static unsigned int getMAX();
	int getNumber_of_elements() const;
	const string toString() const;
	void getFractionList(FractionList & FL) const;
	bool addFraction(const Fraction & Std);
	void print(ostream &  PS) const;
	void getSumMeanFraction(Fraction & sum, Fraction & num2) const;
	void printStatistics(ostream & out = cout);
	static void getInstance(FractionList & FL, ifstream & Scn);
	void printHeader(ostream & out = cout);  // does this really work  cout? --------------------

};
#endif