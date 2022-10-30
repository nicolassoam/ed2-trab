#ifndef MANAGER
#define MANAGER

#include "config.h"
#include <string.h>
#include <vector>
#include <dirent.h>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <algorithm>
#include <map>
#include "hash.h"
#include "trie.h"

#include"huffman.h"

using namespace std;

typedef enum
{
    INSERTIONSORT,
    MERGESORT,
    QUICKSORT,
    TIMSORT
} sorting_method;

class manager
{
public:
    manager();
    ~manager();                                                                 // destrutor

    int return_n_words() {return n_words;}                                      // retorna o número de palavras no arquivo
    Hash* return_hash() {return &hashmp;}                                       // retorna a hash 
    vector<element> getElementList() { return elements;}                                                              

    void mainGutemberg(sorting_method method, vector<string> nomes_arquivos,    // função que chama a openFile e efetua a indexação na tabela hash
                       int indice, int (*hash)(string key, int tam)); 
    void read_index_file(vector<string> &nomes_arquivos);                       // leitura do arquivo com os nomes dos arquivos
    void huffmanCodeCall(map<char, string> &huffmanDicionary);
    void huffmanCompression(string origin_file, int j);
    void count_caracteres(string sentence);
    void imprimeTrie();

private:
    Hash hashmp = Hash(2073);       // tabela hash
    Trie trie = Trie();             // arvore de busca digital (trie)
    vector<hashVec> words;          // vetor de palavras
    vector<string> ignore_array;    // vetor de palavras ignoradas
    vector<hashVec> words50;
    int n_words = 0; 
    map<int, char> char_frequency;      //hashmap de caracteres do alfabeto
    vector<element> elements;
    double inC = 0;                     // contagem de caracteres no arquivo de entrada
    double outC = 0;                    // contagem de caracteres no arquivo de saída
    double taxa_compressao;             

    bool search_ignored_words(string x);                                        // colocando palavras a serem ignoradas num vetor
    void read_ignore_file();                                                    // leitura do arquivo com as palavras a serem ignoradas
    void searchFiles(string file_name);                                         // Anotando nomes dos arquivos da pasta input
    string tratamento(string word);                                             // Função de tratamento de palavras
    bool compare(string &a, string &b);                                         // função de comparação
    void openFile(string nome_arquivo, int (*hash)(string key, int tam));       // função que abre o arquivo e lê as palavras
    void remissivo50(int indice);                                               // função que escreve o indice remissivo das 50 palavras mais repetidas
    void write50(int indice);                                                   // função que escreve as 50 palavras mais repetidas
    void calcula_taxa();                                                        // função que calcula a taxa de compressão
    
    // função que chama a ordenação das palavras que mais repetem
    template <typename T>                                                      
    void sort_words_by_repeat(vector<T> &arrayPalavras, sorting_method method);

    // função que chama a ordenação das palavras em ordem alfabética
    template <typename T>                                                       
    void sort_words_by_alphabet(vector<T> &arrayPalavras, sorting_method method);
};


#endif