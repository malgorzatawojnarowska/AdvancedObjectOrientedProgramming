#ifndef CNODE_H_
#define CNODE_H_

#include <iostream>
#include <string>
#include <vector>

#define DEFAULTVALUE "1"

using namespace std;

class CNode {

	friend class CTree;

public:
	CNode();
	virtual ~CNode();
	CNode(CNode& cnOther);
	CNode(string data);
	CNode(string data, vector<CNode*> v_nodes);
	string sGetData();
	int iGetSize();
	bool bIsOperator(string s_command);
	bool bIsNumber(string s_command);
	bool bIsTrigonometric(string s_command);
	CNode* nGetChild(int i);
	vector<string> vAddChild(vector<string>& v_input);
	void vAddChild(CNode *n_node);
	CNode& operator =(CNode& node);
	CNode& findNode();

private:
	string s_data;
	vector<CNode*> v_children;



};

#endif /* CNODE_H_ */
