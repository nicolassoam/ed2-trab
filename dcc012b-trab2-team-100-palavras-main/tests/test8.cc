#include<iostream>
#include<vector>
#include <string.h>

#include "huffman.h"

using namespace std; 

// teste unitário do huffmanCode

int main()
{
 
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = { 5, 9, 12, 13, 16, 45};

    //int size = sizeof(arr) / sizeof(arr[0]);

    vector<element> elements;
    element aux;

    for(int i=0; i<6; i++)
    {
        aux.value = arr[i];
        aux.frequency = freq[i];
        elements.push_back(aux);
    }
    
    map<char, string> huffmanDicionary;
    HuffmanCodes(elements, 6, huffmanDicionary);
    
    string expected_output[] = {"a=>1100", "b=>1101", "c=>100", "d=>101", "e=>111", "f=>0"};
    string output[6];

    int i = 0;
    for(map<char,string>::iterator it = huffmanDicionary.begin(); it != huffmanDicionary.end(); ++it)
    {
        output[i] = it->first + (string)"=>" + it->second;
        i++;
    }

    for (int i=0; i<6; i++)
    {
        if(output[i] != expected_output[i])
        {
            cout << "Erro no teste unitário do huffmanCode" << endl;
            return -1;
        }   
        
        cout << output[i] << endl;
    }
    
    return 0;
}