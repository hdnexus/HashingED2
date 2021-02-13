#ifndef BUCKET_H_INCLUDED
#define BUCKET_H_INCLUDED
#include <iostream>

using namespace std;

class Bucket
{
private:
    int position;
    int depth;
    int size;
    string *vector;

public:
    Bucket(int M, int depth);
    ~Bucket();

    string getBucket();
    void setBucket();
    int getDepth(int n);
    void setDepth(int n);
    bool Full();
    void Insert(string pseudoKey);
    void Remove();
};

#endif
