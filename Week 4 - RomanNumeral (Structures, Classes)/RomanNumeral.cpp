/*
 * RomanNumeral.cpp
 *
 *  Created on: Sep 23, 2017
 *      Author: anshul
 */

/*
 * Declaring Includes
 */
 
#include "RomanNumeral.h"
#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

/*
 * Defining Functions
 */

/*
 * Default Constructor Function
 */
RomanNumeral::RomanNumeral(): roman(""), decimal(0)
{

}

/*
 * Constructor Function for initializing the object with decimal value
 */
RomanNumeral::RomanNumeral(int dec)
{
	decimal = dec;

	to_roman();
}

/*
 * Constructor Function for initializing the object with roman value
 */
RomanNumeral::RomanNumeral(string rom)
{
	roman = rom;
	to_decimal();
}

/*
 * Function for access the decimal value of an object
 */
int RomanNumeral::get_decimal() const
{
	return decimal;
}

/*
 * Function for access the roman value of an object
 */
string RomanNumeral::get_roman() const
{
	return roman;
}

/*
 * Function to overload an operator '+'
 */
int operator +(const RomanNumeral& rn1, const RomanNumeral& rn2)
{
	return rn1.decimal+rn2.decimal;
}

/*
 * Function to overload an operator '-'
 */
int operator -(const RomanNumeral& rn1, const RomanNumeral& rn2)
{
	return rn1.decimal-rn2.decimal;
}

/*
 * Function to overload an operator '*'
 */
int operator *(const RomanNumeral& rn1, const RomanNumeral& rn2)
{
	return rn1.decimal*rn2.decimal;
}

/*
 * Function to overload an operator '/'
 */
int operator /(const RomanNumeral& rn1, const RomanNumeral& rn2)
{
	return rn1.decimal/rn2.decimal;
}

/*
 * Function to overload an operator '=='
 */
bool operator ==(const RomanNumeral& rn1, const RomanNumeral& rn2)
{
	if (rn1.decimal == rn2.decimal)
	{
		return true;
	}
	else
		return false;
}

/*
 * Function to overload an operator '!='
 */
bool operator !=(const RomanNumeral& rn1, const RomanNumeral& rn2)
{
	if (rn1.decimal != rn2.decimal)
	{
		return true;
	}
	else
		return false;
}

/*
 * Function to overload an operator '<<'
 */
ostream& operator <<(ostream& outs, const RomanNumeral& rn1)
{
	outs << "[" << rn1.decimal << ":" << rn1.roman << "]";
	return outs;
}

/*
 * Function to overload an operator '>>'
 */
istream& operator >>(istream& ins, RomanNumeral& rn1)
{
	string temp;

	ins >> temp;

	rn1.roman = temp;
	rn1.to_decimal();

	return ins;
}

/*
 * Function to find the roman value for a given decimal value
 */
void RomanNumeral::to_roman()
{
	string rom;
	int temp = decimal;
	int temp2 = decimal;
	int n;

	if(temp >= 1000)
	{
		temp2 = temp/1000;
		for(n = 0; n < temp2; n++)
		{
			rom = rom + "M";
		}
		temp = temp%1000;
	}

	if(temp >= 900)
	{
		rom = rom + "CM";
		temp = temp % 900;
	}
	else if(temp >= 500 && temp < 900)
	{
		temp2 = temp/500;
		for(n = 0; n < temp2; n++)
		{
			rom = rom + "D";
		}
		temp = temp % 500;
	}

	if(temp >= 400)
	{
		rom = rom + "CD";
		temp = temp % 400;
	}
	else if(temp >= 100 && temp < 400)
	{
		temp2 = temp/100;
		for(n = 0; n < temp2; n++)
		{
			rom = rom + "C";
		}
		temp = temp % 100;
	}

	if(temp >= 90)
	{
		rom = rom + "XC";
		temp = temp % 90;
	}
	else if(temp >= 50 && temp < 90)
	{
		temp2 = temp/50;
		for(n = 0; n < temp2; n++)
		{
			rom = rom + "L";
		}
		temp = temp % 50;
	}

	if(temp >= 40)
	{
		rom = rom + "XL";
		temp = temp % 40;
	}
	else if(temp >= 10 && temp < 40)
	{
		temp2 = temp/10;
		for(n = 0; n < temp2; n++)
		{
			rom = rom + "X";
		}
		temp = temp % 10;
	}

	if(temp >= 9)
	{
		rom = rom + "IX";
		temp = temp % 9;
	}
	else if(temp >= 5 && temp < 9)
	{
		temp2 = temp/5;
		for(n = 0; n < temp2; n++)
		{
			rom = rom + "V";
		}
		temp = temp % 5;
	}

	if(temp >= 4)
	{
		rom = rom + "IV";
		temp = temp % 4;
	}
	else if(temp >= 1 && temp < 4)
	{
	   temp2 = temp;
		for(n = 0; n < temp2; n++)
		{
			rom = rom + "I";
		}
	}
	roman = rom;
}


/*
 * Function to find the decimal value for a given roman value
 */
void RomanNumeral::to_decimal()
{
	int num = 0, i = 0;
	int prev;
	int length = roman.length();

	while(length >= 0)
	{
		switch(roman[i])
		{
			case 'M':
				num = num + 1000;
				if (prev < 1000)
				{
					num = num - 2*prev;
				}
				prev = 1000;
				break;
			case 'D':
				num = num + 500;
				if (prev < 500)
				{
					num = num - 2*prev;
				}
				prev = 500;
				break;
			case 'C':
				num = num + 100;
				if (prev < 100)
				{
					num = num - 2*prev;
				}
				prev = 100;
				break;
			case 'L':
				num = num + 50;
				if (prev < 50)
				{
					num = num - 2*prev;
				}
				prev = 50;
				break;
			case 'X':
				num = num + 10;
				if (prev < 10)
				{
					num = num - 2*prev;
				}
				prev = 10;
				break;
			case 'V':
				num = num + 5;
				if (prev < 10)
				{
					num = num - 2*prev;
				}
				prev = 5;
				break;
			case 'I':
				num = num + 1;
				if (prev < 1)
				{
					num = num - 2*prev;
				}
				prev = 1;
				break;
			default:
				break;
				// Do nothing
		}
		length--;
		i++;
	}
	decimal = num;
}