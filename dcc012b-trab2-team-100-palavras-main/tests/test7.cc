#include <string>
#include <iostream>
#include <math.h>
#include <cstring>

using namespace std;

#include "hash.h"

// testa a inserção e a busca de nós na LinkedList

int main(int argc, char *argv[])
{
    LinkedList* lista = new LinkedList();
    hashVec* aux = new hashVec();
    int nos = 0;

    lista->insereNode("amogus");
    lista->insereNode("paysandu");
    lista->insereNode("botafogo");

    aux = lista->buscaPalavra("amogus");
    if (aux != nullptr) nos++;

    aux = lista->buscaPalavra("paysandu");
    if (aux != nullptr) nos++;

    aux = lista->buscaPalavra("botafogo");
    if (aux != nullptr) nos++;

    aux = lista->buscaPalavra("seminole");
    if (aux != nullptr) nos++;

    lista->imprimir();

    if (nos == 3)
        return 0;
    
    return -1;
    
}