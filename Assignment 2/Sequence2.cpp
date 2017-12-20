///////////////////////////////////////////////////////////
//Author: Colton Remmert
//Assignment: Cisp430A2
//Class: Cisp430
////////////////////////////////////////////////////////////
//implementation file:

#include "sequence2.h"
#include <cassert>

using namespace CISP430_A2;

//default constructor
sequence::sequence(size_type entry)
{
	//initialize data
	data = new value_type[entry];
	used = 0;
	capacity = entry;
	current_index = 0;
}

//Copy constructor
sequence::sequence(const sequence& entry)
{
	//copies data sets from other class
	capacity = entry.capacity;
	used = entry.used;
	current_index = entry.current_index;

	//sets size 
	data = new value_type[capacity];

	//copies data
	for (int i = 0; i < used; i++)
	{ 
		data[i] = entry.data[i];
	}
}


//sets the index to the start 
void sequence::start()
{ 
	current_index = 0;
}

//increment by 1
void sequence::advance()
{
	current_index++;
}

//inserts a number
void sequence::insert(const value_type& entry)
{
	//will resize if used is greater than the capacity
	if (used >= capacity) 
		resize(size_t(capacity * 1.1)); 

	if (is_item() == true) 
	{ 
	   //will shift data to the right
		for (int i = used; i > current_index; i--)
		{
			data[i] = data[i - 1];
		}
	}
	else
	{
		current_index = 0;
		//sets data to the right
		for (int i = used; i > 0; i--)
		{
			data[i] = data[i - 1];
		}
	}
	//inserts here
	data[current_index] = entry;
	used++; 
}
//appends data to the end of the list
void sequence::attach(const value_type& entry)
{
	//will resize if necessary
	if (used >= capacity) 
		resize(size_t(capacity * 1.1));

	if (is_item() == true) 
	{
		current_index++; //sets to end of list
						 
		for (int i = used; i > current_index; i--)
		{
			data[i] = data[i - 1];
		}
	}
	else
	{
	
		current_index = used;
	}
	//insertion
	data[current_index] = entry; 
	used++; 
}
//will remove the current iem
void sequence::remove_current()
{
	//checks if there is an item in the current spot
	assert(is_item() == true); 
							   
	for (int i = current_index; i < used - 1; i++)
	{
		data[i] = data[i + 1];
	}
	used--; 
}

//will resize if the capacity is greater than used
void sequence::resize(size_type capacityTemp)
{ 
	if (capacityTemp > used)
	{
		
		value_type *temp = new value_type[capacityTemp];

		
		for (int i = 0; i < used; i++)
		{
			temp[i] = data[i];
		}

		delete[] data; 
		data = temp;	
		capacity = capacityTemp; 
	}
	
} 

//will copy data
void sequence::operator =(const sequence &copySeq)
{
	resize(copySeq.capacity);

	used = copySeq.used; 
	current_index = copySeq.current_index;

	
	for (int i = 0; i < used; i++)
	{
		data[i] = copySeq.data[i];
	}
}


sequence::size_type sequence::size() const
{ 
	return used;
}


//checks if the item is valid or not
bool sequence::is_item() const
{ 
	if (current_index < used)
	{
		return true;
	}
	else {
		return false;
	}
}

//gets the current item
sequence::value_type sequence::current() const
{
	assert(is_item() == true);
	return data[current_index];
}
//destructor
sequence::~sequence()
{ 
	delete[] data;
}