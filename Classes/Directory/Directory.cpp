#include "./Directory.h"

#include <cmath>
#include <iostream>

using namespace std;

Directory::Directory(int M, int B)
{
    this->bucketSize = M;
    this->bits = B;
    this->globalDepth = 1;
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
long long int Directory::intHash(string key)
{
    long long int num = stoull(key); //stoi estava dando erro
    long long int dec_value = 0;

    long long int base = 1;

    long long int temp = num;
    while (temp)
    {
        long long int last_digit = temp % 10;
        temp = temp / 10;

        dec_value += last_digit * base;

        base = base * 2;
    }
    return dec_value;
}

bool Directory::Search(string key)
{
    long long int index = intHash(key.substr(0, this->globalDepth));

    if (this->Buckets[index] != NULL && this->Buckets[index]->Search(key) != -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Directory::duplicateDirectory()
{
    vector<Bucket *> auxBucket = this->Buckets;
    int i = 0, j = 0;
    int lastPosition = pow(2, this->globalDepth);
    this->globalDepth++;

    for (i = lastPosition; i < pow(2, this->globalDepth); i++)
    {
        this->Buckets.push_back(nullptr);
    }

    int newLastPosition = pow(2, this->globalDepth);
    for (i = 0; i < newLastPosition; i++)
    {
        Buckets[i] = auxBucket[j / 2];
        j++;
    }
}

void Directory::bucketDivider(string key)
{
    long long int index = intHash(key.substr(0, this->globalDepth));
    Bucket *addBucket = new Bucket(this->bucketSize);
    this->bucketsCounter++;

    addBucket->Insert(key, this->globalDepth);
    this->keysCounter++;

    vector<string> newKeys;
    newKeys.reserve(this->bucketSize);

    for (int i = 0; i < this->Buckets[index]->getUsedSize(); i++)
    {
        string compareKey = this->Buckets[index]->getPseudoKey(i);
        if (compareKey.substr(0, this->globalDepth) == key.substr(0, this->globalDepth))
        {
            addBucket->Insert(this->Buckets[index]->getPseudoKey(i), this->globalDepth);
            newKeys.push_back(this->Buckets[index]->getPseudoKey(i));
        }
    }

    for (int i = 0; i < newKeys.size(); i++)
    {
        string getKey = newKeys[i];
        this->Buckets[index]->Remove(getKey, this->globalDepth);
    }

    this->Buckets[index] = addBucket;
}

void Directory::Insert(string key)
{
    long long int index = intHash(key.substr(0, this->globalDepth));

    if (this->Buckets[index]->Insert(key, this->globalDepth))
    {
        keysCounter++;
    }
    //Caso o balde esteja cheio
    else
    {
        //Se dLocal < dGlobal
        if (this->Buckets[index]->getLocalDepth() < this->globalDepth)
        {
            //cria novo balde
            bucketDivider(key);
        }
        else if (this->Buckets[index]->getLocalDepth() == this->globalDepth && this->globalDepth < this->bits)
        {

            //duplica diretório
            duplicateDirectory();
            //cria novo balde
            bucketDivider(key);
        }
    }
}

//referência http://www.cplusplus.com/forum/general/129163/
float Directory::memoryOcupation()
{
    float memory = 0;
    memory = sizeof(Bucket) * this->bucketsCounter;
    return memory;
}

void Directory::getResults()
{
    //pelo slide do jairo
    float loadFactor = (float)this->keysCounter / (this->bucketsCounter * this->bucketSize);

    cout << "Tamanho dos baldes: " << bucketSize << endl;

    cout << "Numero de chaves: " << keysCounter << endl;

    cout << "Numero de baldes: " << bucketsCounter << endl;

    cout << "Fator de carga: " << loadFactor << endl;

    cout << "Tamanho do diretorio: " << pow(2, this->globalDepth) << endl;

    cout << "Uso de memoria: " << memoryOcupation() << " Bytes" << endl;
}