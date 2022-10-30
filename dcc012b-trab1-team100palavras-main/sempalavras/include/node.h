#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <iostream>

using namespace std;

//estrutura dos elementos da hash (palavra,contador)
struct hashVec{
    string palavra; //palavra
    int c;          //contador 
};

class Node
{
    public:
        Node(){
            info.c = 0;
            info.palavra = "";
            prox = nullptr;
        };

        ~Node(){};
        
        hashVec getInfo(){ return info;  };
        Node* getProx(){ return prox; };

        void setProx(Node *p){ prox = p; };
        
        void setInfo(string palavra, int cont){ 
            info.palavra = palavra;    
            info.c += cont;
        };
        
    private:
        hashVec info;
        Node *prox;
};

#endif // NODE_H_INCLUDED
