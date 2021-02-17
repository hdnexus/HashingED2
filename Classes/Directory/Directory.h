#ifndef DIRECTORY_H_INCLUDED
#define DIRECTORY_H_INCLUDED
#include <iostream>
#include "../Bucket/Bucket.h"
#include <vector>

using namespace std;

class Directory
{
private:
    int globalDepth;
    int bits;
    int bucketSize;
    int bucketsCounter;
    int keysCounter;
    vector<Bucket *> Buckets;

public:
    Directory(int M, int B);           //OK
    ~Directory();                      //OK
    Bucket getBucket(int n);           //OK
    void bucketDivider(string key);    //OK
    void duplicateDirectory();         //OK
    void Insert(string key);           //OK
    long long int intHash(string key); //OK
    bool Search(string i);             //OK
    void Remove();                     //OK
    void getResults();                 //OK
    float memoryOcupation();           //OK
};

#endif