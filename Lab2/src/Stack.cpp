#include"Stack.h"

template <class T>
Stack<T>::Stack() {
	maxSize = 10;
	table = new T[10];
	currentSize = 0;
}

template <class T>
Stack<T>::Stack(int n) {
	maxSize = n;
	table = new T[n];
	currentSize = 0;
}

template <class T>
Stack<T>::Stack(const Stack &sOther){
	maxSize = sOther.maxSize;
	table = new T[maxSize];
	for(int i=0;i<maxSize;i++)
		table[i] = sOther.table[i];
	currentSize = sOther.currentSize;
}

template <class T>
Stack<T>::~Stack() {
}

template <class T>
void Stack<T>::push(T object){
	if(isFull()) throw FullException();
	else {
		table[currentSize] = object;
		currentSize++;
	}
}

template <class T>
T Stack<T>::pop(){
	if(isEmpty()) throw EmptyException();
	else
		currentSize--;
	return table[currentSize];
}

template <class T>
bool Stack<T>::isFull(){
	return currentSize == maxSize;
}

template <class T>
bool Stack<T>::isEmpty(){
	return currentSize == 0;
}

template <class T>
Stack<T>& Stack<T>::operator =(const Stack<T>& sOther){

	maxSize = sOther.maxSize;
	if(table != NULL) delete table;
	table = new T[maxSize];
	for(int i=0;i<maxSize;i++)
		table[i] = sOther.table[i];
	currentSize = sOther.currentSize;
	return *this;
}

template class Stack <int>;
template class Stack <Student>;
template class Stack <Stack<int> >;

