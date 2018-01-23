/*
 * RomanNumeral.h
 *
 *  Created on: Sep 23, 2017
 *      Author: anshul
 */

#ifndef ROMANNUMERAL_H_
#define ROMANNUMERAL_H_
#include <string.h>
#include <iostream>

using namespace std;

class RomanNumeral
{
public:
   /**
    * Default constructor.
    */
   RomanNumeral();
   
	RomanNumeral(int decimal);
	RomanNumeral(string roman);
	int get_decimal() const;
	string get_roman() const;

   // Operator overloading functions
	friend int operator +(const RomanNumeral& rn1, const RomanNumeral& rn2);
	friend int operator -(const RomanNumeral& rn1, const RomanNumeral& rn2);
	friend int operator *(const RomanNumeral& rn1, const RomanNumeral& rn2);
	friend int operator /(const RomanNumeral& rn1, const RomanNumeral& rn2);
	friend bool operator ==(const RomanNumeral& rn1, const RomanNumeral& rn2);
	friend bool operator !=(const RomanNumeral& rn1, const RomanNumeral& rn2);
	friend ostream& operator <<(ostream& outs, const RomanNumeral& rn1);
	friend istream& operator >>(istream& ins, RomanNumeral& rn1);

	private:
	string roman;
	int decimal;
	void to_roman();
	void to_decimal();
};

#endif /* ROMANNUMERAL_H_ */