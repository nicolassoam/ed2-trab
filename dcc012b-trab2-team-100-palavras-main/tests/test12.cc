#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <string.h>

#include "manager.h"

int main(){
    manager i;
    vector<string> nomes_arquivos;
   
    i.read_index_file(nomes_arquivos);

    for (int j = 0; j < nomes_arquivos.size(); j++)
    {
        manager *a = new manager();
        a->huffmanCompression(nomes_arquivos[j], j);
        
        delete a;
    }
    
    return 0;
}