#include "Trie.h"

int main()
{
	TrieNode* Root = new TrieNode;
	inputDictionary(Root, "Dick.txt");
	string Input = inputFile("Input.txt");
	vector<string> lmao = search(Root, Input);
	outputFile(Root, "Output.txt", lmao);
	deleteTrie(Root);
	return 0;
}