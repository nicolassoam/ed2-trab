#include <string.h>
#include <vector>
#include <dirent.h>
#include <iostream>
#include <sstream>
#include <algorithm>

#include "sort.h"
#include "hash.h"
#include "trie.h"
#include "config.h"
#include "manager.h"

using namespace std;
namespace fs = std::filesystem;

#pragma region 
manager::manager(){        };
manager::~manager(){        };

bool compare_alf_ordem(string& a, string& b)
{
    return a < b;
}
bool compare_alf_ordem_hashVec(hashVec& a, hashVec& b)
{
    return a.palavra < b.palavra;
}

bool compare_freq_palavra(hashVec& a, hashVec& b){
    return a.c > b.c;
}

void manager::read_ignore_file(){
    fstream ignore_file(OUTPUT_DIR + (string)"ignore.csv", ios::out | ios::in);
    string *aux = new string;

    if(!ignore_file.is_open()){
        cout<<"Erro ao abrir o ignore.csv"<<endl;
    }

    while(!ignore_file.eof()){
        getline(ignore_file, *aux, ';');
        ignore_array.push_back(*aux);
    } 

    quick_sort<string>(&ignore_array[0], ignore_array.size(), compare_alf_ordem);
    delete aux;
    ignore_file.close();      
};

void manager::read_index_file(vector<string> &nomes_arquivos){
     string *name = new string;
    
    string index_file_name = OUTPUT_DIR;
    index_file_name += "/nome_arquivos.txt";
    searchFiles(index_file_name); //chamando função de leitura de diretório

    ifstream index_file;
    index_file.open(index_file_name, ios::in);

    while(getline(index_file, *name))
        nomes_arquivos.push_back(*name);
    delete name;
};

bool manager::search_ignored_words(string x){
    return binary_search(ignore_array.begin(), ignore_array.end(), x);
};

template <typename T>
void manager::sort_words_by_repeat(vector<T> &arrayPalavras, sorting_method method){
    switch(method){
        case INSERTIONSORT:
            insertion_sort(&arrayPalavras[0], 0, arrayPalavras.size()-1, compare_freq_palavra);
            break;
        case MERGESORT:
            merge_sort(&arrayPalavras[0], arrayPalavras.size()-1, compare_freq_palavra);
            break;
        case QUICKSORT:
            quick_sort(&arrayPalavras[0], arrayPalavras.size()-1, compare_freq_palavra);
            break;
        case TIMSORT:
            timSort(&arrayPalavras[0], arrayPalavras.size()-1, compare_freq_palavra);    
            break;
        default:
            cout<<"ERRO NA ORDENAÇÃO: TIPO INVÁLIDO"<<endl;
            return;
            break;
    }
};

template <typename T>
void manager::sort_words_by_alphabet(vector<T> &arrayPalavras, sorting_method method){
    switch(method){
        case INSERTIONSORT:
            insertion_sort(&arrayPalavras[0], 0, arrayPalavras.size()-1, compare_alf_ordem_hashVec);
            break;
        case MERGESORT:
            merge_sort(&arrayPalavras[0], arrayPalavras.size()-1, compare_alf_ordem_hashVec);
            break;
        case QUICKSORT:
            quick_sort(&arrayPalavras[0], arrayPalavras.size()-1, compare_alf_ordem_hashVec);
            break;
        case TIMSORT:
            timSort(&arrayPalavras[0], arrayPalavras.size()-1, compare_alf_ordem_hashVec);    
            break;
        default:
            cout<<"ERRO NA ORDENAÇÃO: TIPO INVÁLIDO"<<endl;
            return;
            break;
    }
};

void manager::searchFiles(string file_name){
    ofstream listaArquivos;
    listaArquivos.open(file_name, ios::trunc | ios::out);
    
    string path = INPUT_DIR;
    for (const auto & entry : fs::directory_iterator(path)){
        listaArquivos << entry.path().string() << endl;
    }
    
    listaArquivos.close();
};

string manager::tratamento(string word){
    int char_especiais[] = {'!', '.', ',', '?', '(', ')', '{', '}',' ', '>', '<', ';',':' -62, -85, '"', '"'};
    for(int i = 0; i<17; i++)
        word.erase(remove(word.begin(), word.end(), char_especiais[i]), word.end());

    for(int i=0; i<word.size(); i++)
    {
        word[i] = tolower(word[i]);
    }

    return word;
};

void manager::openFile(string nome_arquivo, int (*hash)(string key, int tam)) {
    ifstream file(nome_arquivo, ios::in);
    string sentence, word, line;
    int n_lines = 0;

    if(!file.is_open()){
        cout<<"ERRO AO ABRIR O ARQUIVO: "<< nome_arquivo << endl; 
        return;
    }

    //Leitura do texto e passando para a Hash
    while(!file.eof()){
        getline(file , sentence);
        stringstream sentence_stream(sentence);
        stringstream line_stream(sentence);

        while(getline(line_stream, line, '\n')){
            n_lines++;
        }

        while(getline(sentence_stream, word, ' ')){
            word = tratamento(word.c_str());
            
            if(!search_ignored_words(word) && word.size()>1){
                hashmp.insere(word, hash);
                trie.insert(word, n_lines);
                n_words++;
            }
        }
        
    }
    
    file.close();
}

void manager::imprimeTrie() {
    trie.print();
}

void manager::write50(int indice) {  

    // FUNÇÃO UTILIZADA NA VERSÃO ANTERIOR DO TRABALHO, MANTIDA AQUI APENAS PARA QUE 
    // OS TESTES IMPLEMENTADOS ANTERIORMENTE CONTINUEM FUNCIONANDO.

    // A ESCRITA DAS 50 PALAVRAS MAIS FREQUENTES OCORRE AGORA EM remissivo50(int indice),
    // JUNTO COM A ESCRITA DO ÍNDICE REMISSIVO

    // ofstream output_file(OUTPUT_DIR + (string)"output" + to_string(indice) + (string)".txt", ios::trunc);
    // for(int i = 0; i<50; i++)
    //     output_file<<i+1<<"º - "<<words[i].palavra<<" (" << words[i].c << ")"<<endl;

    // output_file.close();
}

void manager::remissivo50(int indice) {  
    ofstream output_file(OUTPUT_DIR + (string)"remissivo" + to_string(indice+1) + (string)".txt", ios::trunc);
    for(int i = 0; i < 50; i++) {
        vector<int> aux = trie.searchToNode(words50[i].palavra)->getLines();

        output_file<< i+1 <<"º - "<<words50[i].palavra<<" (" << words50[i].c << "x)"<<endl;
        
        output_file << "Linhas: ";
        for (int j = 0; j < aux.size(); j++) {
            output_file << aux.at(j);

            if (j != aux.size()-1)
                output_file << ", ";
        }
        output_file << endl << endl;
    }

    output_file.close();
}

void manager::mainGutemberg(sorting_method method, vector<string>nomes_arquivos, int indice, int (*hash)(string key, int tam)){
    //anexando palavras a serem ignoradas
    read_ignore_file(); 

    //abrindo arquivos a serem lidos
    for(auto file_name : nomes_arquivos){
        cout << "\n" << file_name << endl;
        openFile(file_name, hash);
    }

    hashmp.copyToVector(words);
    sort_words_by_repeat(words, method);

    for(int i =0; i<50; i++){
        words50.push_back(words[i]);
    }
    sort_words_by_alphabet(words50, method);

    write50(indice);
    remissivo50(indice);
};

    
void manager::huffmanCodeCall(map<char, string> &huffmanDicionary)
{
    HuffmanCodes(elements, elements.size(), huffmanDicionary);
    
    for(map<char,string>::iterator it = huffmanDicionary.begin(); it != huffmanDicionary.end(); ++it)
    {
        cout<<it->first << "=>" << it->second << endl;
    }
}

void manager::huffmanCompression(string origin_file, int j)
{
    inC = 0;
    outC = 0;

    ifstream input_file(origin_file, ios::in);

    int file_size = fs::file_size(origin_file);

    char* output_file_name = new char[origin_file.size()-4];

    for(int i=0; i<origin_file.size()-4; i++)
        output_file_name[i] = origin_file[i];

    ofstream output_file(OUTPUT_DIR+ to_string(j) + (string)"_compressed.txt", ios::trunc);
    string sentence; 

    if(!input_file.is_open()){
        cout<<"ERRO AO ABRIR O ARQUIVO: "<< origin_file << endl; 
        return;
    }

    if(!output_file.is_open()){
        cout<<"ERRO AO ABRIR O ARQUIVO: "<< OUTPUT_DIR + to_string(j) + (string)"_compressed.txt" << endl; 
        return;
    }

    while(!input_file.eof())
    {
        getline(input_file , sentence);
        count_caracteres(sentence);
    }

    map<char, string> huffmanDicionary;
    map<char, string>::iterator it; 
    HuffmanCodes(elements, elements.size() , huffmanDicionary);
    string charactere; 
    input_file.seekg(ios::beg);

    while(!input_file.eof())
    {
        getline(input_file, sentence);
        for(int i = 0 ; i < sentence.length(); i++)
        {
            it = huffmanDicionary.find(sentence[i]);
            charactere = it->second;
            for(int j = 0; j < charactere.length(); j++)
            {
                outC++;
                output_file.put(charactere[j]);
            }
        }
    }

    calcula_taxa();
    input_file.close();
    output_file.close();

}

void manager::calcula_taxa() 
{
    outC = outC/8;
    taxa_compressao = (inC - outC)/inC;
    taxa_compressao = (taxa_compressao*100);
    cout << "Taxa de compressão = " << taxa_compressao << "%" << endl;
}

void manager::count_caracteres(string word)
{
    inC += word.size();
    for(int i=0; i<word.size(); i++)
    {
        if(char_frequency.find((char)word[i]) == char_frequency.end())
        {
            element *aux = new element; 
            aux->frequency = 1; 
            aux->value = word[i];
            elements.push_back(*aux);
            
            char_frequency.insert(pair<int,char>((int)word[i],word[i]));
            delete aux; 
        }
        else
        {
            for(int i=0;i<elements.size();i++)
            {
                if(elements.at(i).value == word[i])
                {
                    elements.at(i).frequency++;
                    break; 
                }
            }
        }
    }
}
