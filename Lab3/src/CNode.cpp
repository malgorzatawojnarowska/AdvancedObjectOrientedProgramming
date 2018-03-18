#include "CNode.h"

CNode::CNode(){}

CNode::~CNode() {
	v_children.clear();
	v_children.erase(v_children.begin(), v_children.end());
}

CNode::CNode(CNode& cnOther){
	v_children.erase(v_children.begin(), v_children.end());
	s_data = cnOther.s_data;
	for(int i = 0;i < cnOther.v_children.size(); i++)
		v_children.push_back(new CNode(*(cnOther.v_children[i])));
}

CNode::CNode(string data){
	s_data = data;
}

CNode::CNode(string data, vector<CNode*> v_nodes){
	s_data = data;
	v_children = v_nodes;
}

string CNode::sGetData(){
	return s_data;
}

int CNode::iGetSize(){
	return v_children.size();
}

CNode* CNode::nGetChild(int i){
	return v_children[i];
}

void CNode::vAddChild(CNode *n_node){
	v_children.push_back(n_node);
}

vector<string> CNode::vAddChild(vector<string> &v_input){
	if(bIsTrigonometric(v_input[0])){
		s_data = v_input[0];
		v_children.push_back(new CNode());
		v_input.erase(v_input.begin());
		return v_children[0]->vAddChild(v_input);
	}
	else if(bIsOperator(v_input[0])){
		s_data = v_input[0];
		v_children.push_back(new CNode());
		v_input.erase(v_input.begin());
		if(v_input.size() == 0)
			v_input.push_back(DEFAULTVALUE);
		v_children[0]->vAddChild(v_input);
		v_children.push_back(new CNode());
		//v_input.erase(v_input.begin());
		return v_children[1]->vAddChild(v_input);
		//return v_input;
	}
	else if(v_input.size() == 0){
		v_input.push_back(DEFAULTVALUE);
		return vAddChild(v_input);
	}
	else{
		s_data = v_input[0];
		v_input.erase(v_input.begin());
		return v_input;
	}
}
/*
CNode& CNode::operator =(CNode& node){
	s_data = node.s_data;
	v_children = node.v_children;
	return *this;
}*/

bool CNode::bIsOperator(string s_command){
	if(s_command == "+" || s_command == "-" || s_command == "*" || s_command == "/" || s_command == "sin" || s_command == "cos")
		return true;
	return false;
}

bool CNode::bIsTrigonometric(string s_command){
	if(s_command == "sin" || s_command == "cos")
		return true;
	return false;
}

bool CNode::bIsNumber(string s_command){
	for (int i = 0; i < s_command.size(); i++)
		if (!isdigit(s_command[i]))
			return false;
	return true;
}

CNode& CNode::findNode()
{
	if (v_children.size() == 0)
		return *this;
	else if (!bIsOperator(v_children[0]->s_data))
		return *this;
	else
		return v_children[0]->findNode();
}
