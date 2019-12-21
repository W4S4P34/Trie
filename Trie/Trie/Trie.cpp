#include "Trie.h"

bool inputFile(TrieNode*& Root)
{
	return false;
}

void outputFile(TrieNode* Root)
{

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

void searchWords(TrieNode* Root, string Input)
{

}

void deleteTrie(TrieNode*& Root)
{

}