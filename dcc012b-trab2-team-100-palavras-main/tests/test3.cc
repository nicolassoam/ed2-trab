#include <string>
#include <iostream>

using namespace std;

#include "hash.h"
#include "manager.h"

// testa a remoção de um registro em uma hashtable

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
    hashmp.insere("casa", hash1);
    hashmp.insere("palavra", hash1);
    hashmp.insere("sexta", hash1);
    hashmp.insere("roma", hash1);
    hashmp.insere("amor", hash1);

    hashmp.remove("amor", hash1);
    hashmp.remove("casa", hash1);

    if(hashmp.busca("amor", hash1) == nullptr && hashmp.busca("casa", hash1) == nullptr && hashmp.busca("roma", hash1) != nullptr)
        return 0;
    return -1;
}