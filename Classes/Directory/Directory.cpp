#include "./Directory.h"

#include <cmath>
#include <iostream>

using namespace std;

Directory::Directory(int M, int B)
{
    this->bucketSize = M;
    this->bits = B;
    this->globalDepth = 2;
    this->keysCounter = 0;
    Bucket *initialBucket = new Bucket(bucketSize);

    for (int i = 0; i < pow(2, this->globalDepth); i++)
    {
        this->Buckets.push_back(initialBucket);
    }
    this->bucketsCounter = 1;
}

Directory::~Directory()
{
    for (int i = 0; i < Buckets.size(); i++)
    {
        delete Buckets[i];
    }
}

//referência https://www.geeksforgeeks.org/program-binary-decimal-conversion/
int Directory::intHash(string key)
{
    int num = stoi(key);
    int dec_value = 0;

    int base = 1;

    int temp = num;
    while (temp)
    {
        int last_digit = temp % 10;
        temp = temp / 10;

        dec_value += last_digit * base;

        base = base * 2;
    }
    return dec_value;
}

string Directory::binaryHash(int n)
{
    string hashBinary;
    for (int i = this->bits; i >= 0; i--)
    {
        int j = n / 2;
        if (j % 2)
        {
            hashBinary.push_back('1');
        }
        else
        {
            hashBinary.push_back('0');
        }
    }
    return hashBinary;
}

void Directory::duplicateDirectory()
{
}

void Directory::bucketDivider(string key)
{
}

void Directory::Insert(string key)
{
    //Identifica os d bits mais à esquerda da pseudochave
    int index = intHash(key.substr(0, this->globalDepth));

    //Acessa o balde apontado por essa posição no diretório
    //Caso o balde não esteja cheio, irá inserir a chave
    if (this->Buckets[index]->Insert(key))
    {
        keysCounter++;
    }
    //Caso o balde esteja cheio
    else
    {
        //Se dLocal < dGlobal
        if (this->Buckets[index]->getLocalDepth() < this->globalDepth)
        {
            //Cria novo balde
            //Ajusta ponteiros e dLocal
            //Redistribui as chaves
            bucketDivider(key);
            Insert(key);
        }
        //Se dLocal = dGlobal
        else if (this->Buckets[index]->getLocalDepth() == this->globalDepth)
        {
            //Duplica diretório
            //Cria novo balde
            //Ajusta ponteiros e dLocal
            //Redistribui as chaves
            duplicateDirectory();
            Insert(key);
        }
    }
}

bool Directory::Search(string key)
{
    //Identifica os d bits mais à esquerda da pseudochave
    int index = intHash(key.substr(0, this->globalDepth));

    //Acessa o balde apontado por essa posição no diretório
    if (this->Buckets[index] != NULL)
    {
        //Busca a chave no balde
        if (this->Buckets[index]->Search(key) != -1)
        {
            return true;
        }
    }

    return false;
}

void Directory::getResults()
{
    float loadFactor = (float)this->keysCounter / (this->bucketsCounter * this->bucketSize);
    cout << "Número de baldes: " << bucketsCounter << endl;
    cout << "Número de chaves: " << keysCounter << endl;
    cout << "Fator de carga: " << loadFactor << endl;
    cout << "Gasto de Memória: " << endl;
}