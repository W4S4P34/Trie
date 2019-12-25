#include "Trie.h"

/**************************************/
/************* FILE HANDLE ************/
/**************************************/
void inputDictionary(TrieNode*& Root, string Path)
{
	ifstream fin;
	fin.open(Path);

	if (!fin)	// Check if cannot open file to read
	{
		cout << "Can't open file" << endl;
		return;
	}

	while (!fin.eof()) 
	{
		string Str;
		getline(fin, Str, '\n');
		insertNode(Root, Str);
	}

	fin.close();
}

string inputFile(string Path) 
{
	ifstream fin;
	fin.open(Path);

	string Input;
	string OneWord;

	if (!fin)	// Check if cannot open file to read
	{
		cout << "Can't open file to search" << endl;
		return "";
	}

	while (!fin.eof()) 
	{
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

	fout << WordList.size() << endl;	// Print number of words found

	for (int i = 0; i < WordList.size(); i++)	// Print words
	{
		if (i != WordList.size() - 1)
		{
			fout << WordList[i] << endl;
		}
		else
		{
			fout << WordList[i];
		}
	}

	fout.close();
}

/**************************************/
/************* BUILD TRIE *************/
/**************************************/

TrieNode* createNewNode()
{
	return new TrieNode;
}

void insertNode(TrieNode*& Root, string Word)
{
	TrieNode* Current = Root;
	int Height = 1;

	for (int i = 0; i < Word.length(); i++)	// Consider each word
	{
		TrieNode* Node = Current->ChildrenNode[Word[i]];	// Check whether key (word) is in map or not

		if (!Node)	// If key is not in map, create new one
		{
			Node = createNewNode();
			Current->ChildrenNode[Word[i]] = Node;
		}

		Current = Node;
		Current->Height = Height++;
	}

	Current->isWord = true;
}

/**************************************/
/************* SEARCH TRIE ************/
/**************************************/

void searchWords(TrieNode* Root, string& Input, string& CurrentString, vector<string>& WordList, int InputLength)
{
	TrieNode* Current = Root; 

	if (Current->isWord == true && Current->Height >= 3) 
	{
		WordList.push_back(CurrentString);	// Add to wordlist if the word meet the requirement
	}

	if (Current->Height == InputLength)	return;

	for (auto it = Current->ChildrenNode.begin(); it != Current->ChildrenNode.end(); ++it)
	{
		if (Input.find(it->first) == string::npos) continue;	// If current word is not the one we find then skip

		string CurrentWord(1, Input[Input.find(it->first)]);
		CurrentString += CurrentWord;	
		Input.erase(Input.find(it->first), 1);

		searchWords(Current->ChildrenNode[it->first], Input, CurrentString, WordList, InputLength); // Recursion

		CurrentString.pop_back();
		Input += CurrentWord;
	}
}

vector <string> search(TrieNode* Root, string Input) 
{
	vector <string> WordList;	// List of words which are found
	string CurrentString;	// Init string to handle in recursion

	int InputLength = Input.length();	// Number of words from input

	searchWords(Root, Input, CurrentString, WordList, InputLength);

	return WordList;
}

/**************************************/
/************* DELETE TRIE ************/
/**************************************/

void deleteTrie(TrieNode*& Root)	// Post-order traversal
{
	TrieNode* Current = Root;

	for (auto it = Current->ChildrenNode.begin(); it != Current->ChildrenNode.end(); ++it) 
	{
		deleteTrie(Current->ChildrenNode[it->first]);
		delete Current->ChildrenNode[it->first];
	}

	Current->ChildrenNode.clear();
}