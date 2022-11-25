#ifndef TRIE_H_
#define TRIE_H_
#include <string.h>
#include <vector>
#include "trienode.h"
#include <iostream>

using namespace std;

class Trie{

    public:
        Trie();
        ~Trie();
        void insert(string palavra, int linha);
        TrieNode* searchToNode(string palavra);
        string searchToString(string palavra);
        void print();

    private:
        TrieNode* root;
        
        bool isNull;
};


#endif