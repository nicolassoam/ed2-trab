#ifndef HUFFMAN_H
#define HUFFMAN_H

#include<iostream>
#include<vector>
#include <queue>
#include<map>
#include<sstream>

using namespace std;

//struct of each element of alphabeth
struct element{
    char value;
    int frequency; 
};

struct MinHeapNode {
    char data;                                   //caractere do alfabeto
    unsigned freq;                               //frequência de cada caracter
    MinHeapNode *left, *right;                   //nós filhos (Esquerda e direita)
    MinHeapNode(char data, unsigned freq)        //constructor
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

//operador de comparação
struct compare {
    bool operator()(MinHeapNode* l, MinHeapNode* r)
    {
        return (l->freq > r->freq);
    }
};

//função recursiva que imprime o alfabeto huffman
void imprimir(struct MinHeapNode* root, string str,  map<char, string> &huffmanDicionary);

void HuffmanCodes(vector<element> elem, int size, map<char, string> &huffmanDicionary);

void huffmanCompression(string origin_file);
#endif