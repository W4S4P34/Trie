#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

struct TrieNode
{
	map<char, TrieNode*> ChildrenNode;
	int Height = 1;
	bool isWord = false;
};

/* FILE HANDLE */
bool inputFile(TrieNode*&);
void outputFile(TrieNode*);

/* BUILD TRIE */
TrieNode* createNewNode();
void insertNode(TrieNode*&, string);

/* SEARCH TRIE */
void searchWords(TrieNode*, string);		// In-order Traversal

/* DELETE TRIE */
void deleteTrie(TrieNode*&);				// Post-order Traversal