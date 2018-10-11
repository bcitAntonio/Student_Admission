#pragma once
#include <string>

using namespace std;

class student
{
private:
	int std_id;
	double* gpa;
	string option1, option2, option3, option4, option5;
	int priority;

public:
	student(const int std_id = 0, const double gpa = 0.0,
		const string option1 = "", const string option2 = "",	//over loading + default constructor 
		const string option3 = "", const string option4 = "",
		const string option5 = "", const int priority = 0); 
	student(const student& other);								//copy constructor
	student(student&& other);									//move constructor
	student& operator=(student& other);							//copy assignment operator
	student& operator=(student&& other);						//move assignment operator
	~student();													//destructor
	int get_std_id() const { return std_id; }					//getter for student id (integer)
	int get_priority() const { return priority; }				//getter for priority (integer)
	string get_option(int option_num) const;					//getter for option with parameter which favourite to return(string)
	double get_gpa() const { return *gpa; }						//getter for gpa (double)
};


