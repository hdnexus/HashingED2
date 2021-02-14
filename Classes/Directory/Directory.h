#ifndef DIRECTORY_H_INCLUDED
#define DIRECTORY_H_INCLUDED
#include <iostream>
#include "../Bucket/Bucket.h"
#include <vector>

using namespace std;

class Directory
{
private:
    int nKeys;
    int globalDepth;
    int bits;
    int bucketSize;
    int nBuckets;
    int bucketsCounter;
    int keysCounter;
    vector<Bucket *> Buckets;

public:
    Directory(int M, int B);
    ~Directory();
    Bucket getBucket(int n);
    void bucketDivider(string key);
    void duplicateDirectory();
    void Insert(string key);
    int intHash(int number, string key);
    string binaryHash(int n);
    bool Search(string i);
    void Remove();
};

#endif