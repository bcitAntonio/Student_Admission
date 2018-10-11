#pragma once
#include "student.hpp"

class functor
{
public:
	//default constructor
	functor() {};

	//functor operator to help sort student by gpa
	bool operator()(const unique_ptr<student>& a, const unique_ptr<student>& b);
};