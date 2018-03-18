#ifndef CTREE_H_
#define CTREE_H_

#include <algorithm>
#include <cmath>
#include <string>
#include <iterator>
#include <sstream>
#include <iostream>

#include "CNode.h"


class CTree {
public:
	CTree();
	virtual ~CTree();
	void vPrintTree(CNode *n_node, vector<string>& v_tree);
	CTree(vector<string> v_input);
	CTree(CNode *n_root);
	CTree(CTree &pcOther);
//	CNode* createTree(vector<string> &v_commands, vector<string> &v_newCommands);
//	CTree (vector<string> &v_commands, vector<string> &v_newCommands);
	CNode* nGetRoot();
	vector<string> vGetPrefix();
	void vMakePrefix();
	void vPrintTree(CNode *n_node, string& s_tree);
	void vPrintVars(CNode* n_node, vector<string> &v_variables);
	void vCount(CNode* n_node, int& number);
	int iCount();
	int iCompute(vector<string> v_commands);
	CTree& operator =(const CTree & t_tree);
	CTree operator +(CTree& t_second);


private:
	CNode *n_root;
	vector<string> prefix;

};

#endif /* CTREE_H_ */
