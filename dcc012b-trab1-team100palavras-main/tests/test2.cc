#include <string>
#include <iostream>
#include <math.h>
#include <cstring>

using namespace std;

#include "hash.h"

////////////////// - FUNÇÕES HASH - //////////////////

int hash1(string palavra, int tam){
    int key = 0;
    const char* pK = palavra.c_str();
    for (int i = 0; i < strlen(pK); i++)
        key += pK[i];
    key = abs(key);

    return (int)key%tam;
};

long hash2(string palavra, int tam){
    int key = 0;
    const char* pK = palavra.c_str();
    for (int i = 0; i < strlen(pK); i++)
        key += pK[i];
    key = abs(key);

    int A = (sqrt(5)-1)/2;
    return (int)(tam*((key*A)%1));
};

long hash3(string palavra, int tam){
    int key = 0;
    const char* pK = palavra.c_str();
    for (int i = 0; i < strlen(pK); i++)
        key += pK[i];
    key = abs(key);
    return key;
};

long hash4(string palavra, int tam){
    int key = 0;
    const char* pK = palavra.c_str();
    for (int i = 0; i < strlen(pK); i++)
        key += pK[i];
    key = abs(key);

    return (key*(key+3))%tam;
};

long long hash5(string palavra, int tam){
    long long key = 0;
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



// testa a inserção de registros em uma hashtable

int main(int argc, char *argv[])
{
    Hash hashmp = Hash(123);

    hashmp.insere("palavra",hash1);
    hashmp.insere("palavra",hash1);
    hashmp.insere("word",hash1);
    hashmp.insere("amor",hash1);
    hashmp.insere("roma",hash1);

    /**
     * Verifica os casos:
     * - duas palavras iguais (c = 2)
     * - duas palavras diferentes com keys diferentes 
     * - duas palavras diferentes com keys iguais (endereços diferentes)
    **/ 

    if ((hashmp.busca("palavra", hash1)->c == 2) && (hashmp.busca("word", hash1)->c == 1) && (hashmp.busca("amor", hash1) != hashmp.busca("roma", hash1)))
        return 0;
    return -1;
}