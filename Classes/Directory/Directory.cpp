#include "./Directory.h"

#include <iostream>

using namespace std;

Directory::Directory(int M, int B)
{
    this->depth = depth;
    this->bucketSize = bucketsize;
    for (int i = 0; i < 1 << depth; i++)
    {
        buckets.push_back(new Bucket(depth, bucketsize));
    }
}

Directory::~Directory()
{
}