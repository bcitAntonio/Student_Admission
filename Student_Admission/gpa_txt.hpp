#pragma once
#include <string>
#include <vector>
#include <queue>
#include "student.hpp"
#include "functor.hpp"

using namespace std;
class gpa_txt 
{
private:
	functor f;										//declaring functor for student queue so it sorts by gpa
													//next line declare a student pointer queue and sorts student by gpa
	priority_queue<unique_ptr<student>, vector<unique_ptr<student>>, decltype(f)> std_queue;	
	vector<int>option_seat{ 0,0,0,0,0 };			// each option has maximum of 25 seats, this vector keeps track of max_seating
	int sum_unhappy{ 0 };						// total of sum_happyniess for all students
	string file_name;								// insistance variable for gpa_txt class to open file "student.txt"

public:
	gpa_txt(string file_name = "student.txt");		//one parameter + default constructor 
	gpa_txt(const gpa_txt& other);					//copy constructor 
	gpa_txt(gpa_txt&& other);						//move constructor
	gpa_txt& operator=(const gpa_txt& other);		//copy assignment operator
	gpa_txt& operator=(gpa_txt&& other);			//move assignment operator
	~gpa_txt() {};									//destructor
	void read_std_txt();							//open up "student.txt" and add each student into priority queue
	void write_gpa_txt();						//write to gpa_txt according to gpa and maximum of 25 seats for each option
	string write_gpa_txt_helper(string option); //helper function that keep shifting to student's 
													//next option if current one is full
	int string_to_int(string s);					//convert option string to int starting with 0 for option "A"
};
