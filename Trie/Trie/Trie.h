#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
using namespace std;

struct TrieNode
{
	map<char, TrieNode*> ChildrenNode;
	int Height = 0;
	bool isWord = false;
};

/* FILE HANDLE */
void inputDictionary(TrieNode*&, string);
string inputFile(string);
void outputFile(TrieNode*, string, vector<string>);


/* BUILD TRIE */
TrieNode* createNewNode();
void insertNode(TrieNode*&, string);

/* SEARCH TRIE */
void searchWords(TrieNode*, string&, string&, vector<string>&, int);			// Pre-order Traversal
vector <string> search(TrieNode*, string);

/* DELETE TRIE */
void deleteTrie(TrieNode*&);				// Post-order Traversal