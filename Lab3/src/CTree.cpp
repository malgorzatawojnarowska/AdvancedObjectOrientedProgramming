#include "CTree.h"

CTree::CTree() {
	n_root = NULL;
}

CTree::CTree(CTree &ctOther){
	n_root = new CNode(*(ctOther.n_root));
}

CTree::CTree(vector<string> v_input){
	n_root = new CNode();
	n_root->vAddChild(v_input);
}

CTree::CTree(CNode* n_root){
	this->n_root = n_root;
}

void CTree::vMakePrefix(){
	vPrintTree(n_root, prefix);
}

void CTree::vPrintTree(CNode *n_node, vector<string>& v_tree){
	if (n_node != NULL) {
		v_tree.push_back(n_node->sGetData());
		for(int i = 0;i < n_node->iGetSize(); i++)
			vPrintTree(n_node->nGetChild(i), v_tree);
		}
}

vector<string> CTree::vGetPrefix(){
	return prefix;
}

void CTree::vPrintTree(CNode *n_node, string& s_tree){
	if (n_node != NULL) {
		s_tree += n_node->sGetData() + " ";
		for(int i = 0;i < n_node->iGetSize(); i++)
			vPrintTree(n_node->nGetChild(i), s_tree);
		}
}

CNode* CTree::nGetRoot(){
	return n_root;
}

bool bContains(vector<string> v_vars, string s_variable){
	for (int i = 0; i < v_vars.size(); i++)
		if (v_vars[i] == s_variable)
			return true;
	return false;
}

void CTree::vPrintVars(CNode *n_node, vector<string> &v_variables){
	if (n_node != NULL) {
		if(!n_node->bIsOperator(n_node->sGetData()) && !n_node->bIsNumber(n_node->sGetData()) && !bContains(v_variables, n_node->sGetData()))
			v_variables.push_back(n_node->sGetData());
		for(int i = 0;i < n_node->iGetSize(); i++){
			vPrintVars(n_node->nGetChild(i), v_variables);
		}
	}
}

void CTree::vCount(CNode* n_node, int &number){
	if (n_node != NULL) {
		if(n_node->bIsTrigonometric(n_node->sGetData()))
			number += 1;
		for(int i = 0;i < n_node->iGetSize(); i++)
			vCount(n_node->nGetChild(i), number);
	}
}

int CTree::iCount(){
	int number = 0;
	vCount(n_root, number);
	return number;
}

CTree& CTree::operator =(const CTree & t_tree){

	if (n_root != NULL)
		 delete n_root;
	n_root = new CNode(*t_tree.n_root);
	return *this;

}

CTree CTree::operator +(CTree& t_second){
	CTree t_result = *this;
	CNode* n_left = &t_result.n_root->findNode();

	if (n_left->v_children.size() == 0){
		if(n_left != NULL)
			delete n_left;
		t_result.n_root = new CNode(*t_second.n_root);
		return t_result;
	}
	delete n_left->v_children[0];
	n_left->v_children[0] = new CNode(*t_second.n_root);
	return t_result;
}


/*
CTree::CTree(vector<string> &v_commands, vector<string> &v_newCommands){
	createTree(v_commands, v_newCommands);
}

CNode* CTree::createTree(vector<string> &v_commands, vector<string> &v_newCommands){

	if(v_commands.size() == 0){
		v_newCommands.push_back("1");
		return new CNode("1");
	}
	CNode* node = new CNode(v_commands[0]);
	if(node->bIsOperator(v_commands[0])){
		//v_commands.erase(v_commands.begin());
		if (node->bIsTrigonometric(v_commands[0])){
			v_commands.erase(v_commands.begin());
			node->vAddChild(createTree(v_commands, v_newCommands));
		}
		else{
			v_commands.erase(v_commands.begin());
			node->vAddChild(createTree(v_commands, v_newCommands));
			//v_commands.erase(v_commands.begin());
			node->vAddChild(createTree(v_commands, v_newCommands));
		}
	}
	else
		v_commands.erase(v_commands.begin());
	return node;
}*/

bool bNumber2(string s_command){
	for (int i = 0; i < s_command.size(); i++)
		if (!isdigit(s_command[i]))
			return false;
	return true;
}

int iNumber2(string s_command){
	return stoi(s_command);
}


int CTree::iCompute(vector<string> v_commands){
	vector<string> variables;
	vPrintVars(n_root, variables);
	if (v_commands.size() != variables.size())
		return -1;
	else{
		vector<int> v_compute;
		string s_tree;
		vPrintTree(n_root, s_tree);
		istringstream buf(s_tree);
		istream_iterator<string> beg(buf), end;
		vector<string> v_tree(beg, end);

		while(v_tree.size() != 0){

			int i = v_tree.size()-1;

			if(bNumber2(v_tree[i])){
				v_compute.push_back(iNumber2(v_tree[i]));
			}

			else if (n_root->bIsOperator(v_tree[i])){
				int result = v_compute[v_compute.size()-1];
				v_compute.pop_back();

				if (v_tree[i] == "+"){
					result += v_compute[v_compute.size()-1];
					v_compute.pop_back();
					v_compute.push_back(result);
				}
				if (v_tree[i] == "-"){
					result -= v_compute[v_compute.size()-1];
					v_compute.pop_back();
					v_compute.push_back(result);
				}
				if (v_tree[i] == "*"){
					result *= v_compute[v_compute.size()-1];
					v_compute.pop_back();
					v_compute.push_back(result);
				}
				if (v_tree[i] == "/"){
					result /= v_compute[v_compute.size()-1];
					v_compute.pop_back();
					v_compute.push_back(result);
				}
				if (v_tree[i] == "sin"){
					result = sin(result);
					v_compute.push_back(result);
				}
				if (v_tree[i] == "cos"){
					result = cos(result);
					v_compute.push_back(result);
				}
			}
			else{
				v_compute.push_back(iNumber2(v_commands[v_commands.size()-1]));
				v_commands.pop_back();
			}

			v_tree.pop_back();

		}

		return v_compute[0];

	}

}

CTree::~CTree() {
	delete n_root;
}
