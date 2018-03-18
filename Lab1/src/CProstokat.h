#ifndef CPROSTOKAT_H_
#define CPROSTOKAT_H_

#include <algorithm>

#include "CPunkt.h"

class CProstokat {
public:
	//CProstokat();
	CProstokat(int x1, int y1, int x2, int y2) : mini(min(x1,x2), min(y1,y2)), maxi(max(x1,x2), max(y1,y2)){}
	CProstokat(CPunkt a, CPunkt b) : mini(min(a.getX(),b.getX()), min(a.getY(),b.getY())), maxi(max(a.getX(),b.getX()), max(a.getY(),b.getY())){}
	CProstokat(CProstokat &cpOther): mini(cpOther.mini), maxi(cpOther.maxi){}
	CProstokat operator +(CProstokat& cpOther);
	friend ostream& operator<< (ostream& out, CProstokat const& p){
		out << p.mini << ", " << p.maxi;
		return out;
	}

private:
	CPunkt mini;
	CPunkt maxi;
};

#endif /* CPROSTOKAT_H_ */
