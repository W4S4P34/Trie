#include "Trie.h"
void inputDictionary(TrieNode*& Root, string Path)
{
	ifstream fin;
	fin.open(Path);
	if (!fin) {
		cout << "Can't open file" << endl;
		return;
	}
	while (!fin.eof()) {
		string str;
		getline(fin, str, '\n');
		insertNode(Root, str);
	}
	fin.close();
}
string inputFile(string Path) 
{
	ifstream fin;
	fin.open(Path);
	string Input;
	string OneWord;
	if (!fin) {
		cout << "Can't open file to search";
		return "";
	}
	while (!fin.eof()) {
		getline(fin, OneWord, ' ');
		Input += OneWord;
	}
	fin.close();
	return Input;
}

void outputFile(TrieNode* Root, string Path, vector<string> WordList)
{
	ofstream fout;
	fout.open(Path);
	fout << WordList.size() << endl;
	for (int i = 0; i < WordList.size(); i++) {
		if (i != WordList.size() - 1)
			fout << WordList[i] << endl;
		else fout << WordList[i];
	}
	fout.close();
}

TrieNode* createNewNode()
{
	return new TrieNode;
}

void insertNode(TrieNode*& Root, string Word)
{
	TrieNode* Current = Root;
	int Height = 1;
	for (int i = 0; i < Word.length(); i++) {
		TrieNode* Node = Current->ChildrenNode[Word[i]];
		if (!Node) {
			Node = createNewNode();
			Current->ChildrenNode[Word[i]] = Node;
		}
		Current = Node;
		Current->Height = Height++;
	}
	Current->isWord = true;
}
//Something specific
void searchWords(TrieNode* Root, string& Input, string& CurrentString, vector<string>& WordList, int InputLength)
{
	TrieNode* Current = Root; 

	if (Current->isWord == true && Current->Height >= 3) {
		WordList.push_back(CurrentString);
	}

	if (Current->Height == InputLength) return;

	for (auto it = Current->ChildrenNode.begin(); it != Current->ChildrenNode.end(); ++it) { 
		if (Input.find(it->first) == string::npos)
			continue;

		string CurrentWord(1, Input[Input.find(it->first)]);
		CurrentString += CurrentWord;
		Input.erase(Input.find(it->first), 1);

		searchWords(Current->ChildrenNode[it->first], Input, CurrentString, WordList, InputLength);

		Input += CurrentWord;
		CurrentString.pop_back();
	}
}
vector <string> search(TrieNode* Root, string Input) {
	vector <string> WordList;
	string CurrentWord;

	int InputLength = Input.length();

	searchWords(Root, Input, CurrentWord, WordList, InputLength);

	return WordList;
}
void deleteTrie(TrieNode*& Root)
{
	TrieNode* Current = Root;

	for (auto it = Current->ChildrenNode.begin(); it != Current->ChildrenNode.end(); ++it) {
		deleteTrie(Current->ChildrenNode[it->first]);
		delete Current->ChildrenNode[it->first];
	}
	Current->ChildrenNode.clear();
}