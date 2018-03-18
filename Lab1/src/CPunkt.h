#ifndef CPUNKT_H_
#define CPUNKT_H_

#include <iostream>
#include <string>

using namespace std;

class CPunkt {
public:
	CPunkt(int x, int y);
	CPunkt(CPunkt &cpOther);
	virtual ~CPunkt();
	void setX(int newX);
	void setY(int newY);
	int getX();
	int getY();
	CPunkt& operator =(const CPunkt& cpOther);
	friend ostream& operator<< (ostream& out, CPunkt const& point){
		out << "(" << *point.x << ", " << *point.y << ")";
		return out;
	}

private:
	int* x;
	int* y;
};

#endif /* CPUNKT_H_ */
