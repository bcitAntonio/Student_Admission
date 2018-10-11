#pragma once
#include <string>
#include <random>

using namespace std;

class student_txt {

public: 
	student_txt(){}									//default constructor
	string gen_specialization();					//generating random option within (A,B,C,D,E)
	int gen_std_num(int position);					//generating student id with 9 digit starting with 100000001
	void gen_std_info(int const num_of_std,			//helper function to generate student.txt 
	int const std_with_priority_one, const int priority_two); 
	void gen_student_txt();							//generating student.txt with std id, gpa, 5 options, and priority
};

//non-member function (template random generator)
//PRE: none
//POST: typename T generating random value with start and end value specified in the parameter
//RETURN: random value (typename T)
template <typename T = int>
T gen_rand(T start, T end)
{
	--end;
	T rand_num;
	random_device rd;
	mt19937 g{rd()};
	uniform_real_distribution<> distribution(start, end);
	rand_num = distribution(g);
	return rand_num;
}
