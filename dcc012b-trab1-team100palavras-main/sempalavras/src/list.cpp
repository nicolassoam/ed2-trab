#include <iostream>
#include <string.h>

#include "list.h"

using namespace std;

LinkedList::LinkedList(){ primeiro = NULL; }

LinkedList::~LinkedList(){
    Node *p = primeiro;
    while(p != NULL) {
        primeiro = primeiro->getProx();
        delete p;
        p = primeiro;
    }
}

void LinkedList::insereNode(string palavra) {
    Node *p = new Node();
    p->setInfo(palavra, 1);
    p->setProx(primeiro);
    primeiro = p;
}

void LinkedList::removeNode(hashVec palavra) {
    Node *p = primeiro;
    Node *q = primeiro;

    if (palavra.c != 0) {
        while(p != NULL) {

            if ((strcmp((p->getInfo().palavra).c_str(), (palavra.palavra).c_str()) == 0) && p == primeiro){
                primeiro = primeiro->getProx();
                delete p;
                return;
            }

            q = q->getProx();

            if ((q != NULL) && (strcmp((q->getInfo().palavra).c_str(), (palavra.palavra).c_str()) == 0)) {
                p = p->getProx();
                delete p;
                delete q;
                return; 
            }
            
            p = p->getProx();
        }
    }

    delete p;
    delete q;
}

void LinkedList::imprimir(){
    Node *p = primeiro;
    while(p != NULL) {
        cout << p->getInfo().palavra << "(" << p->getInfo().c << ")";
        cout << endl;
        p = p->getProx();
    }
}

void LinkedList::getAllInfo(vector<hashVec>& vet){
    Node *p = primeiro;
    while(p!=NULL){
        vet.push_back(p->getInfo());
        p = p->getProx();
    }
    delete p;
}

bool LinkedList::verificaPalavra(hashVec novoPar, int *n_colisoes){
    Node *p = primeiro;

    while(p != NULL) {
        if (strcmp(p->getInfo().palavra.c_str(), novoPar.palavra.c_str())==0) {
            p->setInfo(novoPar.palavra, 1); 
            return true;
        } else {
            (*n_colisoes)++;
            p = p->getProx();
        }
    }
    return false;
}


hashVec* LinkedList::buscaPalavra(string palavra) {
    Node *p = primeiro;
    hashVec *aux = new hashVec;
    while(p != NULL) {
        if (strcmp((p->getInfo().palavra).c_str(), palavra.c_str()) == 0){
            *aux = p->getInfo();
            return aux;
        }
        
        p = p->getProx();
    }

    delete aux;

    return nullptr;
}