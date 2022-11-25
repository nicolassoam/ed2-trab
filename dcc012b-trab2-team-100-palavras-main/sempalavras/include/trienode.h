#ifndef TRIENODE_H_
#define TRIENODE_H_
#include <string.h>
#include <iostream>

using namespace std;

class TrieNode{
    friend class Trie;
    public:
        TrieNode(){
            isLeaf = false;
            hasChildren = false;
            children = new TrieNode*[480];
            for(int i = 0; i < 480; i++){
                children[i] = nullptr;
            }
        };
        ~TrieNode(){};

        void print(){
            cout << data <<endl;
        }

        void traverseChildren(){
            if (!hasChildren)
                return;

            for (int i = 0; i < 480; i++){
                if(children[i] != nullptr){ 
                      
                    cout << "|_" << children[i]->data << " ";

                    if (children[i]->isLeaf) {
                        cout << "(Linhas: ";

                        for (int j = 0; j < children[i]->linhas.size(); j++) {
                            cout << children[i]->linhas[j];
                            if (j != children[i]->linhas.size() - 1)
                                cout << ", ";
                        }

                        cout << ") ";
                    }

                    children[i]->traverseChildren();               
                }
            }
            cout << endl;
        }

        vector<int> getLines(){
            return this->linhas;
        }

    private:
        char data;
        vector<int>linhas;
        TrieNode**children;
        bool isLeaf;
        bool hasChildren;
};


#endif