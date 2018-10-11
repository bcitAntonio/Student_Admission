#include "student_txt.hpp"
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>

//generating five different options with in option A,B,C,D,E
//PRE: random function is working
//POST: creates a vector of option A,B,C,D,E and apply random to them afterward
//RETURN string
string student_txt::gen_specialization()
{
	int i { 0 };
	string str_spc;
	vector<string> spec{ "A", "B", "C", "D", "E" };

	while (spec.size() > 0)
	{
		i = gen_rand<int>(0,spec.size()+1);
		str_spc = str_spc + spec[i] + " ";
		spec.erase(spec.begin() + i);
	}
	return str_spc;
}

//generating student id starting from 100000000
//PRE: none
//POST: increment by one after each
//RETURN: int
int student_txt::gen_std_num(int position)
{
	int stu_num_begin{ 10000000 };
	return stu_num_begin += position;
}

//helper function for gen_student_txt function
//PRE: none
//POST: generate the string with student id, gpa (random), options(5 and random) + priority
//RETURN none
void student_txt::gen_std_info(int const num_of_std, int const std_with_priority_one, const int int_two)
{
	double gpa{ 0.0 };
	const int gpa_start{ 50 };
	//predecrement in the rand function
	const int gpa_end{ 101 };
	ofstream std_txt;
	string const file_name{ "student.txt" };
	std_txt.open(file_name);

	for(int i{1}; i <= num_of_std; ++i)
	{
		gpa = gen_rand<double>(gpa_start,gpa_end);
		if (i <= std_with_priority_one) {
			std_txt << gen_std_num(i) << " " << setprecision(1) << fixed << gpa
				<< " " << gen_specialization() << " " << 1 << endl;
		} else {
			std_txt << gen_std_num(i) << " " << setprecision(1) << fixed << gpa
				<< " " << gen_specialization() << " " << int_two << endl;;
		}
	}
	std_txt.close();
}

//generating student txt
//PRE: helper function is working (named gen_std_info)
//POST: specify number of students, number of prority ones and call helper function to do the work
//RETURN none
void student_txt::gen_student_txt()
{
	//predecrement in gen_rand function
	const int num_of_std { 125 };
	const int std_with_priority_one { 100 };
	const int int_two{ 2 };
	gen_std_info(num_of_std, std_with_priority_one, int_two);
}

