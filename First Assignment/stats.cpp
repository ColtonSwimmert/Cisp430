//////////////////////////////////////////////////////////////////////////////////////////
//Author: Colton Remmert
//School:Cosumnes River College
//Assignment: Cisp430A1
//Class:CISP430
//Description: Assignment #1 of Professor Huang's Cisp430 Class.
/////////////////////////////////////////////////////////////////////////////////////////
//implementation file:

#include "stats.h"
#include<iostream>

using namespace CISP430_A1;

statistician::statistician() 
{
	//initialized data to zero
	total = 0;
	count = 0;
	tiniest = 0;
	largest = 0;

}; 
//gets the next number and adds it to the list, if zero this will count it. Also determines largest and smallest numbers
void statistician::next(double r)
{
	if (count == 0) {
		total += r; //adds the number to the total
		count++; // for each time this function is called there should be number, so increment each time called
		tiniest = r;
		largest = r;
	}
	else
	{
		total += r;
		count++;

		if (r < tiniest) {
			tiniest = r;
		}
		if (r > largest) {
			largest = r;
		}
	}
}
//resets the data
void CISP430_A1::statistician::reset()
{
	//sets all data members to zero or resets them for another test
	count = 0;
	total = 0;
	tiniest = 0;
	largest = 0;

}
//returns the mean
double statistician::mean() const
{
	if (length() > 0) {
		return sum() / count;
	}
	else {
		return 0;
	}
}
//returns the smallest number
double statistician::minimum() const
{
	if (length() > 0) {
		return tiniest;
	}
	else {
		return 0;
	}
}
//returns the largest number
double statistician::maximum() const
{
	if (length() > 0) {
		return largest;
	}
	else
	{
		return 0;
	}
}
//addition friend function. adds private members and checks for inconsistances in largest/smallest data
statistician CISP430_A1::operator+(const statistician & s1, const statistician & s2)
{
	statistician test;

	test.total = s1.sum() + s2.sum();
	test.count = s1.length() + s2.length();
	//could implement < operator here
	if (s1.minimum() < s2.minimum()) {
		test.tiniest = s1.minimum();
	}
	else {
		test.tiniest = s2.minimum();
	}

	if (s1.maximum() > s2.maximum()) {
		test.largest = s1.maximum();
	}
	else {
		test.largest = s2.maximum();
	}

	return test;
}


//multiplication friend function. Multiplies data and checks if a negative number has been applied to the multiplication
statistician CISP430_A1::operator*(double scale,const  statistician & s)
{
	statistician test = s;
	test.total *= scale;
	test.tiniest *= scale;
	test.largest *= scale;

	if (test.tiniest > test.largest) {
		double temp = test.tiniest;
		test.tiniest = test.largest;
		test.largest = temp;
	}

	
	return test;
	
}


//tests if data is equal or not equal.
bool CISP430_A1::operator==(const statistician & s1, const statistician & s2)
{

	if (s1.length() == s2.length() && s1.sum() == s2.sum()) {
		return true;
	}
	else
	{
		if (s1.sum() != s2.sum() || s1.length() != s2.length()) {
			return false;
		}
	}
	
}
