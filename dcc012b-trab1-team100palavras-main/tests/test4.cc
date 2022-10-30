#include <string>
#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

#include "hash.h"
#include "manager.h"

// verifica o número de colisões feitas quando anagramas são inseridos

int hash1(string palavra, int tam){
    int key = 0;
    const char* pK = palavra.c_str();
    for (int i = 0; i < strlen(pK); i++)
        key += pK[i];
    key = abs(key);

    return (int)key%tam;
};

int main(int argc, char *argv[])
{
    Hash hashmp = Hash(123);       // tabela hash
    hashmp.insere("pedra", hash1);
    hashmp.insere("padre", hash1);
    hashmp.insere("perda", hash1);
    hashmp.insere("alergia", hash1);
    hashmp.insere("galeria", hash1);
    hashmp.insere("alegria", hash1);
    hashmp.insere("regalia", hash1);
    hashmp.insere("palavra", hash1);
    hashmp.insere("aleatória", hash1);

    hashmp.imprimeInfo();

    if(hashmp.getColisoes() == 9)
        return 0;
    return -1;
}