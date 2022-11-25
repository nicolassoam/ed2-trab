#include "config.h"

#include <string>
#include <iostream>
#include <math.h>
#include <cstring>

using namespace std;

#include "manager.h"
#include "huffman.h"

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
    string input = INPUT_DIR + string("receita_de_bolo.txt");
   
    i.huffmanCompression(input,1);
    return 0;
}