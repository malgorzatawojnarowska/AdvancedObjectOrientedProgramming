#include "CPunkt.h"

CPunkt::CPunkt(int x, int y) {
	this->x = new int(x);
	this->y = new int(y);
}

CPunkt::CPunkt(CPunkt &cpOther){
	x = new int(*cpOther.x);
	y = new int(*cpOther.y);
}

CPunkt::~CPunkt() {
	delete x;
	delete y;
}

void CPunkt::setX(int newX){
	*x = newX;
}

void CPunkt::setY(int newY){
	*y = newY;
}

int CPunkt::getX(){
	return *x;
}

int CPunkt::getY(){
	return *y;
}

CPunkt& CPunkt::operator =(const CPunkt& cpOther){
	*x = *(cpOther.x);
	*y = *(cpOther.y);
	return *this;

}



