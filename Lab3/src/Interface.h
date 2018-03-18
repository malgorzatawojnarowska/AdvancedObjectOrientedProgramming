#ifndef INTERFACE_H_
#define INTERFACE_H_

#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <cmath>

#include "CTree.h"
#include "CNode.h"

#define ENTER "enter"
#define VARIABLES "vars"
#define COMPUTE "comp"
#define JOIN "join"
#define PRINT "print"
#define HELP "help"
#define EXIT "exit"
#define NUMBER "count"
#define PRINTHELP "enter <formula> - enter new tree\nvars - variables from tree\nprint - prefix tree\ncomp <var0> <var1>...<varN> - compute variables\njoin <formula> - join new tree\ncount - count one argument functions\n"

using namespace std;

class Interface {
public:
	Interface();
	virtual ~Interface();
	void vInput();

private:
	string s_input;
	CTree *tree;

	void vPrintTree();
	void vPrintHelp();
	void vCount();
	void vJoinTree(vector<string> v_commands);
	int iCompute(vector<string> v_commands);
	void vPrintVariables();
	void vEnterTree(vector<string> v_commands);

};

#endif /* INTERFACE_H_ */
