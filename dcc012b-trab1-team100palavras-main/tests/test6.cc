#include <string>
#include <iostream>
#include <math.h>
#include <cstring>

using namespace std;

#include "manager.h"

// compara os métodos de ordenação utilizando a hash1 (resultado das comparações no REPORT.md)

int hash1(string palavra, int tam){
    long key = 0;
    const char* pK = palavra.c_str();
    for (int i = 0; i < strlen(pK); i++)
        key += pK[i];
    key = abs(key);
    return (int)key%tam;
};

int main(int argc, char *argv[])
{
    manager i;
    string input = INPUT_DIR + string("triste_fim_polycarpo_quaresma.txt");
    vector<string> nome_arquivo;
    nome_arquivo.push_back(input);

    i.mainGutemberg(TIMSORT, nome_arquivo, 0, hash1);
    return 0;
}