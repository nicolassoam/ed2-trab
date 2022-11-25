#include "huffman.h"
#include<sstream>

//função recursiva que imprime o alfabeto huffman
void imprimir(struct MinHeapNode* root, string str, map<char, string> &huffmanDicionary)
{
    if (!root)
        return;
 
    if (root->data != '$')
    {
        huffmanDicionary.insert(pair<char, string>(root->data, str));
    }
 
    imprimir(root->left, str + "0", huffmanDicionary);
    imprimir(root->right, str + "1", huffmanDicionary);
}

void HuffmanCodes(vector<element> elem, int size,map<char, string> &huffmanDicionary)
{
    struct MinHeapNode *left, *right, *top;
 
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap; 
    for (int i = 0; i < size; ++i)
        minHeap.push(new MinHeapNode(elem.at(i).value, elem.at(i).frequency));
 
    while (minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();
 
        right = minHeap.top();
        minHeap.pop();
 
        top = new MinHeapNode('$', left->freq + right->freq);
 
        top->left = left;
        top->right = right;
 
        minHeap.push(top);
    }
    
    imprimir(minHeap.top(), "", huffmanDicionary);
}
