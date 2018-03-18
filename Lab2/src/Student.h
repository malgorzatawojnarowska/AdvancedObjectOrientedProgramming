#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include <iostream>

using namespace std;


class Student {
public:
	Student();
	Student(string n, int y);
	virtual ~Student();
	friend ostream& operator<< (ostream& out, Student const& s){
		out << s.name << " " << s.year << " ";
	return out;
	}

private:
	string name;
	int year;
};

#endif /* STUDENT_H_ */
