#include <iostream>
#include "Stack.h"
using namespace std;

template <class T>
void move(Stack<T> &s1, Stack<T> &s2) {
	while(!s2.isFull() && !s1.isEmpty())
		s2.push(s1.pop());
}

int main() {
	Stack<int> s(3);
	s.push(1);
	s.push(2);
	cout << s << endl;
	s.pop();
	cout << s << endl;

	Stack<int> s1(3);
	s1.push(3);
	s1.push(2);
	cout << s1 << endl;

	move(s1,s);
	cout << s << endl;

	Stack<Student> s2(3);
	s2.push(Student("Kowalski", 1996));
	s2.push(Student("Nowak", 996));
	s2.push(Student("Blable", 1000));
	cout << s2 << endl;
	s2.pop();
	cout << s2 << endl;

	Stack<Stack<int> > s4(3);
	s4.push(s);
	Stack<int> s5 = s4.pop();
	cout << s5;


	return 0;
}
