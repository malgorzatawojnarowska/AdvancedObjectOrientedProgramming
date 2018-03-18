#include "Interface.h"

Interface::Interface() {
	tree = NULL;
	vInput();
}

Interface::~Interface() {}


void Interface::vInput()
{
	vPrintHelp();
    do {
        cin.clear();
        cout << "\n> ";
        getline(cin, s_input);

        //vector of input - command and parameters
        istringstream buf(s_input);
        istream_iterator<string> beg(buf), end;
        vector<string> v_commands(beg, end);
/*
        int j = 0;
        	string buffer = "";

        	for (int i = s_input.find_first_not_of(" "); i < s_input.size(); i++) {
        		if (s_input[i] == ' ') {
        			v_commands.push_back(buffer);
        			j++;
        			buffer = "";
        		}
        		else buffer += s_input[i];
        	}
*/
        if (v_commands.size() == 0) {}

        else if (v_commands[0] == ENTER) {
        		if(tree != NULL)
        			delete tree;
        		vEnterTree(v_commands);

        }

        else if (v_commands[0] == VARIABLES) {
            vPrintVariables();
        }

        else if (v_commands[0] == COMPUTE) {
        	if (iCompute(v_commands) == -1)
        		cout << "Zla liczba danych\n";
        	else
        		cout << "Wynik: " << iCompute(v_commands) << endl;
        }

        else if (v_commands[0] == JOIN) {
        		vJoinTree(v_commands);
        }

        else if (v_commands[0] == PRINT) {
            vPrintTree();
        }

        else if (v_commands[0] == HELP) {
            vPrintHelp();
        }

        else if (v_commands[0] == NUMBER){
        		vCount();
        }

    } while (s_input != EXIT);
    delete tree;
}

bool bOperator(string s_command){
	if(s_command == "+" || s_command == "-" || s_command == "*" || s_command == "/" || s_command == "sin" || s_command == "cos")
		return true;
	return false;
}

bool bNumber(string s_command){
	for (int i = 0; i < s_command.size(); i++)
		if (!isdigit(s_command[i]))
			return false;
	return true;
}

int iNumber(string s_command){
	return stoi(s_command);
}

void Interface::vCount(){
	cout << "Ilosc f jednoargumentowych: " << tree->iCount() << endl;
}

void Interface::vPrintTree(){
	string s_tree;
	tree->vPrintTree(tree->nGetRoot(), s_tree);
	cout << s_tree;
}

void Interface::vPrintHelp(){
	cout << PRINTHELP << endl;
}

int Interface::iCompute(vector<string> v_commands){
	v_commands.erase(v_commands.begin());
	return tree->iCompute(v_commands);
}

void Interface::vPrintVariables(){
	vector<string> variables;
	tree->vPrintVars(tree->nGetRoot(), variables);
	for(int i = 0;i < variables.size(); i++)
		cout << variables[i] << " ";
}


void Interface::vEnterTree(vector<string> v_commands){
	v_commands.erase(v_commands.begin());
	vector<string> v_newCommands = v_commands;
	int i_commandsSize = v_commands.size();

	tree = new CTree(v_commands);

	tree->vMakePrefix();
	if(tree->vGetPrefix().size() > i_commandsSize){
		cout <<"Bledna formula, przetwarzam: ";
		for(int i=0;i<tree->vGetPrefix().size();i++)
			cout << tree->vGetPrefix()[i] << " ";
	}
	else if(tree->vGetPrefix().size() != i_commandsSize){
		cout <<"Bledna formula, przetwarzam: ";
		for(int i=0;i<tree->vGetPrefix().size();i++)
			cout << (tree->vGetPrefix())[i] << " ";
	}
}

void Interface::vJoinTree(vector<string> v_commands){
	v_commands.erase(v_commands.begin());
	vector<string> v_newCommands = v_commands;
	int i_commandsSize = v_commands.size();

	CTree* newTree = new CTree(v_commands);

	newTree->vMakePrefix();
	if(newTree->vGetPrefix().size() > i_commandsSize){
		cout <<"Bledna formula, przetwarzam: ";
		for(int i=0;i<newTree->vGetPrefix().size();i++)
			cout << newTree->vGetPrefix()[i] << " ";
	}
	else if(newTree->vGetPrefix().size() != i_commandsSize){
		cout <<"Bledna formula, przetwarzam: ";
		for(int i=0;i<newTree->vGetPrefix().size();i++)
			cout << (newTree->vGetPrefix())[i] << " ";
	}

	*tree = *tree + *newTree;
	delete newTree;
}
