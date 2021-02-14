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
    vector<Bucket *> Buckets;

public:
    Directory(int M, int B);
    ~Directory();
    Bucket getBucket(int n);
    void bucketDivider();
    void duplicateDirectory();
    void Insert(int i);
    int binaryHash(long long int number, string key);
    string intHash(string binary, int n);
    bool Search(string i);
    void Remove();
};

#endif