#ifndef DIRECTORY_H_INCLUDED
#define DIRECTORY_H_INCLUDED
#include <iostream>
#include "../Bucket/Bucket.h"
#include <vector>

using namespace std;

class Directory
{
private:
    //profundidade global
    int globalDepth;
    //número de bits
    int bits;
    //tamanho do balde
    int bucketSize;
    //quantidade de buckets
    int bucketsCounter;
    //quantidade de chaves
    int keysCounter;
    //vetor de baldes
    vector<Bucket *> Buckets;

public:
    //construtor do diretório
    Directory(int M, int B);
    //destrutor do diretório
    ~Directory();

    //função que irá dividir o diretório
    void bucketDivider(string key);
    //função que irá duplicar o diretório
    void duplicateDirectory();
    //função que irá inserir as chaves no balde
    void Insert(string key);
    //função que irá realizar a tranformação de binário para inteiro
    int intHash(string key);
    //função que irá realizar a tranformação de inteiro para binário
    string binaryHash(int n);
    //função que irá procurar o balde e depois a pseudochave
    bool Search(string i);
    //função que irá gerar os resultados
    void getResults();
};

#endif