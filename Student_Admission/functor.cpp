#include "functor.hpp"

//functor that helps to sort student by gpa
//PRE: there's student class
//POST: if first priority is greater or equal to second then compare their gpa (student wiht 1st priority first)
//RETURN: bool (T if first gpa is < then second gpa, F otherwise)

bool functor::operator()(const unique_ptr<student>& a, const unique_ptr<student>& b)
{
	if (a->get_priority() >= b->get_priority())
	{
		return a->get_gpa() < b->get_gpa();
	}
	return 0;
}