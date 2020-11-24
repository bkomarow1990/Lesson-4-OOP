// 03_Student static.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Student.h"
void testFunc()
{
	Student stud("Olia", Student::Gender::FEMALE);
	/*stud.addMark(10);
	stud.addMark(12);
	stud.addMark(11);
*/

	stud.print();
}

Student stud("Ivan", Student::Gender::MALE);

void demoCopyCtorAssign()
{
	std::cout << "Count of students : " << Student::getCountOfStudents() << std::endl; // 1
	stud.print();

	testFunc();

	Student stud1("Petro", Student::Gender::MALE);
	stud1.addMark(10);
	stud1.addMark(12);
	stud1.addMark(9);
	stud1.print();

	testFunc();

	Student* stud2 = new Student("Ann", Student::Gender::FEMALE);
	stud2->addMark(10);
	stud2->print();

	int result = Student::compareStudentByRate(stud1, *stud2);
	if (result == 0)
	{
		std::cout << "Students have same rate\n";
	}
	// статична функція отримує 2 студента, повертає 0, >0, <0 на основі імені strcmp()
	std::cout << "Count of students : " << Student::getCountOfStudents() << std::endl; // 1

	delete stud2;
	Student clone = stud1;
	std::cout << "End of main\n";

}
void testFunc(Student& student) {
	if (student.getMarksQty()>0)
	{
		student.addMark(12);
	}
}
int main(){
	Student stud("Petro", Student::Gender::MALE);
	stud.addMark(10);
	stud.addMark(12);
	stud.addMark(9);
	testFunc(stud);
	stud.print();
}