#include "config.h"
#include <iostream>
#include <math.h>
#include <cstring>

#include "manager.h"

// Testa as rotinas da hashtable para cada um dos arquivos de input utilizando o método escolhido

////////////////// - FUNÇÕES HASH - //////////////////

int hash1(string palavra, int tam){
    long key = 0;
    const char* pK = palavra.c_str();
    for (int i = 0; i < strlen(pK); i++)
        key += pK[i];
    key = abs(key);
    return (int)key%tam;
};

int hash2(string palavra, int tam){
    int key = 0;
    const char* pK = palavra.c_str();
    for (int i = 0; i < strlen(pK); i++)
        key += pK[i];
    key = abs(key);

    int A = (sqrt(5)-1)/2;
    return (int)(tam*((key*A)%1));
};


int hash3(string palavra, int tam){
    int key = 0;
    const char* pK = palavra.c_str();
    for (int i = 0; i < strlen(pK); i++)
        key += pK[i];
    key = abs(key);
    return (key*(key+3))%tam;
};

int hash4(string palavra, int tam){
    int key = 0;
    const char* pK = palavra.c_str();
    for (int i = 0; i < strlen(pK); i++)
        key += pK[i];
    key = abs(key);
    key = key*key;

    if(tam > 1000){
        key = key >> 2;
        key = key%1000;
    } else if(tam < 1000){
        key = key >> 1;
        key = key%100;
    }

    return key;
};

int main()
{
    manager i;    

    vector<string> nomes_arquivos;
    vector<string> aux;
    i.read_index_file(nomes_arquivos);

    // 50 palavras mais usadas em cada livro
    for(int i = 0; i < nomes_arquivos.size(); i++){
        manager *a = new manager();
        aux.push_back(nomes_arquivos[i]);
        a->mainGutemberg(QUICKSORT, aux, i, hash1);
        aux.clear();
        delete a; 
    }

    // 50 palavras mais usadas no total
    i.mainGutemberg(QUICKSORT, nomes_arquivos, 1000, hash1);

    return 0;
}