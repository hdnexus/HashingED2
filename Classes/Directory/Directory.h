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
    vector<Bucket*> Buckets;

    void bucketDivider();


public:
    Directory();
    ~Directory();

    void Duplicate();
    void Insert();
    string binaryConverter();
    bool Search();
    void Remove();
};

#endif