#include <iostream>
#include <string>
#include "trie.h"

// Testa inserção e busca na trie e imprime conteúdo dos nós

int main(){

    int testes = 0;

    Trie* t = new Trie();

    cout << "Inserindo teste, teste1, teste2, teste3 e aa" << endl;

    t->insert("teste",1);
    t->insert("teste1",1);
    t->insert("teste2",1);
    t->insert("teste3",1);
    t->insert("aa",1);

    testes++;

    if (t->searchToString("teste2") == "teste2") {
        cout << "encontrou teste2" << endl;
        testes++;
    }
    

    if(t->searchToString("bbb") != "") {
        cout << "encontrou bbb" << endl;
    } else {
        cout << "nao encontrou bbb" << endl;  
        testes++;
    }

    if(t->searchToNode("teste3") != nullptr) {
        cout << "encontrou teste3" << endl;
        testes++;
    } else {
        cout << "nao encontrou teste3" << endl;
    }

    t->print(); 

    if (testes == 4)
        return 0;
    else    
        return -1;
}