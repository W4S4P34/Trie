#include "Trie.h"

int main()
{
	/* Inittialize Trie */
	TrieNode* Root = new TrieNode;
	inputDictionary(Root, "Dic.txt");

	/* Initialize input string */
	string Input = inputFile("Input.txt");

	/* Search and generate words*/
	vector<string> WordList = search(Root, Input);

	/* Output to file */
	outputFile(Root, "Output.txt", WordList);

	/* Delete Trie */
	deleteTrie(Root);

	return 0;
}