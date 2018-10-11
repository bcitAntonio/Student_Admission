#include <sstream>
#include <fstream>
#include <iostream>
#include <memory>
#include <queue>
#include <utility>
#include "gpa_txt.hpp"

gpa_txt:: gpa_txt(string file_name) : file_name(file_name) {};				//constructor

gpa_txt:: gpa_txt(const gpa_txt& other) : file_name(other.file_name) {};	//copy constructor

gpa_txt:: gpa_txt(gpa_txt&& other) : file_name(other.file_name) 
{
	other.file_name = "";													//move constructor
}

//copy assignment operator=
//PRE: none
//POST: set this file_name to parameter file_name
//RETURN class reference (gpa_txt)
gpa_txt& gpa_txt::operator=(const gpa_txt& other) 
{ 
	file_name = other.file_name;											
	return *this;
}

//move assignmetn operator=
//PRE: none
//POST: set this file_name to parameter file_name, then set parameter_file name to empty afterward
//RETURN class reference (gpa_txt)
gpa_txt& gpa_txt::operator=(gpa_txt&& other)								
{
	file_name = other.file_name;
	other.file_name = "";
	return *this;
}

//read student.txt file and push each line as a student into the student priority queue
//PRE: student priority queue and student class exists
//POST: open file student.txt and using stringstream collecting value from each line. 
//		with value collect, we constructor a student unique pointer then push into student priority queue
//RETURN: none
void gpa_txt::read_std_txt()
{
	string line;
	ifstream myfile(file_name);

	if (myfile.is_open())
	{
		int std_id, priority{ 0 };
		double gpa{ 0.0 };
		string o1, o2, o3, o4, o5;
		while (getline(myfile, line))
		{
			stringstream str(line); 
			if (str >> std_id >> gpa >> o1 >> o2 >> o3 >> o4 >> o5 >> priority)
			{
				std_queue.push(unique_ptr<student>(new student(std_id, gpa, o1, o2, o3, o4, o5, priority)));
			}
		}
		myfile.close();
	} 
	else
		cout << "Sorry! can not open text file \" stduent.txt\"" << endl;
}

//write to gpa.txt
//PRE: none
//POST: open gpa.txt and write student's id and first option with alogrithum applied.
//		also prints out total of unhappiness
//RETURN: none
void gpa_txt::write_gpa_txt()
{
	read_std_txt();
	ofstream gpa_txt;
	string const file_name{ "gpa.txt" };
	gpa_txt.open(file_name);

	while (!std_queue.empty()) {
		gpa_txt << write_gpa_txt_helper(std_queue.top()->get_option(1));
	}
	gpa_txt.close();
	cout << "\"NOTE: To see unhappy value display inside gpa.txt for each student,\n" << 
		"please uncomment LINE 82 in gpa_txt.cpp \"" << endl;
	cout << "Total of unhappy for gpa_txt is: " << sum_unhappy << endl << endl;
}

//helper function for gpa.txt
//PRE: none.
//POST: checkers checks if student with high gpa's first option is full, 
//		then they can pick their next option (if not full) first.
//RETURN: string with student id and one option

string gpa_txt::write_gpa_txt_helper(string option)
{
	static int i{ 1 };
	const int max{ 25 };
	int option_in_int{ -1 };
	string output;
	option_in_int = string_to_int(option);
	
	if (option_seat[option_in_int] < max)
	{
		output = (to_string(std_queue.top()->get_std_id()) + " "
			+ std_queue.top()->get_option(i) + " " + "\n");
			//to_string(i-1) + "\n");
		sum_unhappy += (i - 1);
		option_seat[option_in_int]++;
		std_queue.pop();
		i = 1;
		return output;
	}
	else
	{
		++i;
		string recusive{ std_queue.top()->get_option(i) };
		return write_gpa_txt_helper(recusive);
	}
}

//converts student option from string to int 
//PRE: none
//POST: starting from option A = 0 moving down.
//		with returned int, it helps with student_seating vector 
//RETURN: integer
int gpa_txt::string_to_int(string s)
{
	int first{ 0 }, second{ 1 }, third{ 2 }, forth{ 3 }, fifth{ 4 };
	if (s == "A")
		return first;
	if (s == "B")
		return second;
	if (s == "C")
		return third;
	if (s == "D")
		return forth;
	if (s == "E")
		return fifth;
	else
		return -1;
}
