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
    int depth;
    int bucketSize;
    int nBuckets;
    vector<Bucket *> Buckets;

public:
    Directory(int M, int B);
    ~Directory();

    void bucketDivider();
    void duplicateDirectory();
    void Insert(int i);
    string binaryConverter();
    bool Search(int i);
    void Remove();
};

#endif