#include <iostream>
#include "student_txt.hpp"
#include "gpa_txt.hpp"

using namespace std;
int main()
{
	student_txt std_txt = student_txt();
	std_txt.gen_student_txt();

	gpa_txt gpa_text = gpa_txt();
	gpa_text.write_gpa_txt();

	system("pause");
	return 0;
}