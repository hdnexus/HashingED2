#include "./Directory.h"

#include <cmath>
#include <iostream>

using namespace std;

Directory::Directory(int M, int B)
{
    this->bucketSize = M;
    this->bits = B;
    this->globalDepth = 2;

    Bucket *initialBucket = new Bucket(bucketSize);

    for (int i = 0; i < pow(2, this->globalDepth); i++)
    {
        this->Buckets.push_back(initialBucket);
    }
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

int Directory::binaryHash(long long int number, string key)
{
}

string Directory::intHash(string binary, int n)
{
}

void Directory::Insert(int i)
{
}

void Directory::duplicateDirectory()
{

    for (int i = 0; i < pow(2, globalDepth); i++)
    {
        Buckets.push_back(nullptr);
    }

    globalDepth++;

    for (int i = pow(2, globalDepth) - 1; i >= 0; i--)
    {
        Buckets[i] = Buckets[i / 2];
    }
}

void Directory::bucketDivider() {}

bool Directory::Search(string key)
{
    int directoryIndex = binaryHash(globalDepth, key);

    for (int i = 0; i < Buckets.size(); i++)
        if (Buckets[directoryIndex]->getPseudoKey(i).compare(key) == 0)
            return true;

    return false;
}