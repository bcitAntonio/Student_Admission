#include "student.hpp"

//overloading constructor initializing all instance variables
student::student(const int std_id, const double gpa, const string option1, const string option2, 
	const string option3, const string option4, const string option5, const int priority)
	: std_id(std_id), option1(option1), option2(option2), option3(option3), option4(option4), option5(option5),
	  priority(priority)
	{
		this->gpa = new double(gpa);
	}

//copy constructor
//copies all instance variables value from old to new 
student::student(const student& other) : std_id(other.std_id), option1(other.option1), option2(other.option2), 
	option3(other.option3), option4(other.option4), option5(other.option5),
	priority(other.priority)
	{
		gpa = new double;
		*gpa = *(other.gpa);
	}

//move constructor
//copies all instance variables value from old to new THEN delete all value in the old one afterward
student::student(student&& other) : std_id(other.std_id), option1(other.option1), option2(other.option2),
	option3(other.option3), option4(other.option4), option5(other.option5),
	priority(other.priority)
	{
		gpa = other.gpa;
		other.std_id = other.priority = 0;
		other.option1 = other.option2 = other.option3 = other.option4 = other.option5 = "";
		other.gpa = nullptr;
	}

//copy assignment operator
//PRE: none
//POST:assignment current instance variables values to other instance variable values
//RETURN student reference

student& student::operator=(student& other)
{
	std_id = other.std_id;
	*gpa = *(other.gpa);
	option1 = other.option1;
	option2 = other.option2;
	option3 = other.option3;
	option4 = other.option4; 
	option5 = other.option5;
	priority = other.priority;
	return *this;
}

//move assignment operator
//PRE: none
//POST:assignment current instance variables values to other instance variable values, THEN delete all 
//		instance variable values in other.
//RETURN student reference

student& student::operator=(student&& other)
{
	std_id = other.std_id;
	*gpa = *(other.gpa);
	option1 = other.option1;
	option2 = other.option2;
	option3 = other.option3;
	option4 = other.option4;
	option5 = other.option5;
	priority = other.priority;
	other.std_id = other.priority = 0;
	other.option1 = other.option2 = other.option3 = other.option4 = other.option5 = "";
	other.gpa = nullptr;

	return *this;
}

//destructor (no exception throw)
//deleting student gpa (pointer created without new)
//PRE: none
//POST: delete gpa is gpa is not nullptr
//RETURN: no return type
student::~student()
{
	if (gpa)
		delete gpa;
}

//To reduce code duplication, a swtich stament to determine which option to get 
//pre: none
//POST: getts student option according to index passed in as parameter
//RETURN: string
string student::get_option(int option_num) const
{
	switch (option_num)
	{
	case 1: 
		return option1;
	case 2: 
		return option2;
	case 3:
		return option3;
	case 4: 
		return option4;
	case 5:
		return option5;
	default: 
		return "";
	}
}

