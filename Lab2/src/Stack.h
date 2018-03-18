#ifndef STACK_H_
#define STACK_H_

#include <string>
#include <iostream>

#include "Student.h"

using namespace std;


template <class T>
class Stack {
public:
	class FullException{};
	class EmptyException{};
	Stack();
	Stack(int n);
	Stack(const Stack &sOther);
	virtual ~Stack();
	void push(T object);
	T pop();
	bool isEmpty();
	bool isFull();
	Stack& operator =(const Stack& sOther);
	friend ostream& operator<< (ostream& out, Stack const& s){
		for(int i=0;i<s.currentSize;i++)
			out << s.table[i] << " ";
		return out;
	}

private:
	T *table;
	int maxSize;
	int currentSize;
};


#endif /* STACK_H_ */
