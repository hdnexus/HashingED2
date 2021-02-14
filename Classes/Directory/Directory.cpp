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

Bucket Directory::getBucket(int n)
{
    return *this->Buckets[n];
}

//referência https://www.geeksforgeeks.org/program-binary-decimal-conversion/
int Directory::intHash(int bits, string key)
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
    for (int i = 0; i < 1 << this->globalDepth; i++)
    {
        Buckets.push_back(Buckets[i]);
    }
    this->globalDepth++;
}

void Directory::bucketDivider(string key)
{
    // obtem indice decimal do balde no diretorio
    int index = intHash(this->globalDepth, key);

    Bucket *newBucket = new Bucket(bucketSize);

    // ajusta a profundidade local
    Buckets[index]->incrementLocalDepth();
    newBucket->incrementLocalDepth();
    ;

    // aponta para novo balde
    Buckets[index] = newBucket;
    bucketsCounter++;

    // redistribui as pseudochaves
    for (int i = 0; i < bucketSize; i++)
    {
        string valBalde = Buckets[index]->getPseudoKey(i);
        if (key.compare(valBalde.substr(0, globalDepth)) == 0)
        {
            newBucket->Insert(valBalde);
            Buckets[index]->setPseudoKey("");
        }
    }
}

void Directory::Insert(string key)
{
    int index = intHash(this->globalDepth, key);

    if (!Buckets[index]->Full())
    {
        Buckets[index]->setPseudoKey(key);
        keysCounter++;
    }
    else
    {
        if (Buckets[index]->getLocalDepth() < this->globalDepth)
        {
            bucketDivider(key);
            Insert(key);
        }
        else if (Buckets[index]->getLocalDepth() == this->globalDepth)
        {
            if (this->globalDepth < this->bits)
            {
                duplicateDirectory();
                Insert(key);
            }
            else
            {
                //Diretório não é mais duplicável
            }
        }
    }
}

bool Directory::Search(string key)
{
    int index = intHash(globalDepth, key);

    for (int i = 0; i < Buckets.size(); i++)
    {
        if (Buckets[index]->getPseudoKey(i).compare(key) == 0)
        {
            return true;
        }
    }

    return false;
}