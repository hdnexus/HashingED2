#ifndef BUCKET_H_INCLUDED
#define BUCKET_H_INCLUDED
#include <iostream>
#include <vector>
using namespace std;

class Bucket
{
private:
    //profundidade local
    int localDepth;
    //tamanho que está sendo usado
    int usedSize;
    //tamanho máximo do balde
    int mSize;
    //vetor de pseudochaves
    vector<string> pseudoKeys;

public:
    Bucket(int M);                                     //OK
    ~Bucket();                                         //OK
    int getUsedSize();                                 //OK
    void incrementUsedSize();                          //OK
    int getLocalDepth();                               //OK
    void incrementLocalDepth();                        //OK
    void decreaseUsedSize();                           //OK
    int getSize();                                     //OK
    bool Full();                                       //OK
    bool Insert(string pseudoKey, int globalDepth);    //OK
    void newLocalDepth(string value, int globalDepth); //OK
    string getPseudoKey(int n);                        //OK
    void setPseudoKey(string key);                     //OK
    int Search(string key);                            //OK
    void Remove(string key, int globalDepth);          //OK
    char getSpecificBit(int i, int j);                 //OK
};

#endif
