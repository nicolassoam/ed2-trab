#include "trie.h"
#include <iostream>
#include <string.h>

using namespace std;

Trie::Trie(){
    root = new TrieNode[1000];
    isNull = true;
}

Trie::~Trie(){
   for(int i = 0; i< 480;i++){
        delete root->children[i];  
   }
   delete [] root;
};

void Trie::insert(string palavra, int linha){
    TrieNode* atual = root;
    for (int i = 0; i < palavra.length(); i++)
    {
        int indice = abs(palavra[i] - 'a');
        
        if(atual->children[indice] == nullptr){
            atual->children[indice] = new TrieNode();
        }

        atual->hasChildren = true;
        atual = atual->children[indice];

        atual->data = palavra[i];    
    }

    atual->isLeaf = true;
  
    atual->linhas.push_back(linha);

    isNull = false;
}

TrieNode* Trie::searchToNode(string palavra){
    TrieNode* atual = root;
    string aux= "";
    for (int i = 0; i < palavra.length(); i++)
    {
        int indice = abs(palavra[i] - 'a');
        if(atual->children[indice] == nullptr){
            return nullptr;
        }

        atual = atual->children[indice];
        aux+=atual->data;
    }

    if(atual->isLeaf)
        return atual;

    return nullptr;
}

string Trie::searchToString(string palavra){
    TrieNode* atual = root;
    string aux= "";
    for (int i = 0; i < palavra.length(); i++)
    {
        int indice = abs(palavra[i] - 'a');
        if(atual->children[indice] == nullptr){
            return "";
        }

        atual = atual->children[indice];
        aux+=atual->data;
    }

    if(atual->isLeaf)
        return aux;

    return "";
}

void Trie::print(){
    if (isNull){
        cout << "Trie vazia" << endl;
        return;
    }

    TrieNode* atual = root;

    cout << atual->data <<endl;

    atual->traverseChildren();
}