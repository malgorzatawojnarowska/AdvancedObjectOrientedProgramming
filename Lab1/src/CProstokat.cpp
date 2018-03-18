#include "CProstokat.h"

CProstokat CProstokat::operator +(CProstokat& cpOther){
	CProstokat p_result(min(mini.getX(), cpOther.mini.getX()), min(mini.getY(), cpOther.mini.getY()), max(maxi.getX(), cpOther.maxi.getX()), max(maxi.getY(), cpOther.maxi.getY()));

	return p_result;
}


