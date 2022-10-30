#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include<vector>

#include "node.h"

class LinkedList
{
    private:
        Node *primeiro;
    public:

        LinkedList();                        //construtor da lista encadeada
        ~LinkedList();                       //destrutor da lista encadeada

        void insereNode(string palavra);     //insere um par (palavra,contador) na lista       
        void removeNode(hashVec palavra);    //remove um par (palavra,contador) da lista
        void imprimir();                     //imprime todos os pares (palavra,contador) da lista

        bool verificaPalavra(hashVec newData, int *n_colisoes);     //verifica se a palavra já foi inserida na lista
                                                                    //e incrementa contador e/ou n_colisoes
        void getAllInfo(vector<hashVec>& vet);

        hashVec* buscaPalavra(string palavra);      //procura a palavra na lista e retorna um ponteiro para o par (palavra,contador) ou,
                                                    // caso a palavra não esteja na lista, retorna um nullptr
};


#endif // LIST_H_INCLUDED
