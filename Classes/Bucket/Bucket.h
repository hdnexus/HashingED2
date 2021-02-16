#ifndef BUCKET_H_INCLUDED
#define BUCKET_H_INCLUDED
#include <iostream>
#include <vector>
using namespace std;

class Bucket
{
private:
    //profundidade local
    int localDepth;
    //tamanho que está sendo usado
    int usedSize;
    //tamanho do balde
    int mSize;
    //vetor de pseudochaves
    vector<string> pseudoKeys;

public:
    //Construtor do balde
    Bucket(int M);
    //Destrutor do balde
    ~Bucket();
    //get e set do tamanho que está sendo usado
    int getUsedSize();
    void setUsedSize();
    //get da profundidade local
    int getLocalDepth();
    //função para incrementar a profundidade local
    void incrementLocalDepth();
    //get para o tamanho do balde
    int getSize();
    //função booleana que irá checar se o balde está cheio ou não
    bool Full();
    //função para remover uma pseudochave 
    void Remove(int n);
    //função que irá limpar o balde
    void clearBucket();
    //função que irá inserir a chalve no balde
    bool Insert(string pseudoKey);
    //get e set para a pseudochave
    string getPseudoKey(int n);
    void setPseudoKey(string key);
    //função que irá procurar a chave dentro do balde
    int Search(string key);
};

#endif
