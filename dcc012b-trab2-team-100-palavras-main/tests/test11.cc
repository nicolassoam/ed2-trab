#include <iostream>
#include <string.h>
#include "trie.h"
#include <vector>
#include <cstring>
#include "manager.h"

using namespace std;

// faz indice remissivo da receita de bolo

int hash1(string palavra, int tam){
    long key = 0;
    const char* pK = palavra.c_str();
    for (int i = 0; i < strlen(pK); i++)
        key += pK[i];
    key = abs(key);
    return (int)key%tam;
};


int main(){
    manager i;
    string input = INPUT_DIR + string("receita_de_bolo.txt");
    vector<string> nome_arquivo;
    nome_arquivo.push_back(input);
    i.mainGutemberg(TIMSORT, nome_arquivo, 0, hash1);
    
    //i.imprimeTrie();
    
    if(i.return_n_words() == 74) 
        return 0;
    return -1;
}