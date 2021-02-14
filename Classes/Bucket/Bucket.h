#ifndef BUCKET_H_INCLUDED
#define BUCKET_H_INCLUDED
#include <iostream>
#include <vector>
using namespace std;

class Bucket
{
private:
    int localDepth;
    int usedSize;
    int mSize;
    vector<string> pseudoKeys;

public:
    Bucket(int M);
    ~Bucket();

    int getUsedSize();
    void setUsedSize();
    int getLocalDepth();
    void incrementLocalDepth();
    int getSize();
    bool Full();
    void Remove(int n);
    void clearBucket();
    bool Insert(string pseudoKey);
    string getPseudoKey(int n);
};

#endif
