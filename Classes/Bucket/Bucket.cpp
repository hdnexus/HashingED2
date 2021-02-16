#include "./Bucket.h"
#include <sstream>
#include <cassert>
#include <iostream>

using namespace std;

Bucket::Bucket(int M)
{
  this->mSize = M;
  this->localDepth = 0;
  this->usedSize = 0;
}

Bucket::~Bucket()
{
}

int Bucket::getLocalDepth()
{
  return this->localDepth;
}

int Bucket::getSize()
{
  return mSize;
}

void Bucket::incrementLocalDepth()
{
  this->localDepth = this->localDepth + 1;
}

bool Bucket::Insert(string pseudoKey)
{
  if (!Full())
  {
    this->pseudoKeys.push_back(pseudoKey);
    this->usedSize++;
    return true;
  }
  else
  {
    return false;
  }
}

bool Bucket::Full()
{
  if (this->usedSize == this->mSize)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int Bucket::getUsedSize()
{
  return this->usedSize;
}

void Bucket::setUsedSize()
{
  this->usedSize = this->usedSize + 1;
}

void Bucket::Remove(int n)
{
  this->pseudoKeys.erase(pseudoKeys.begin() + n);
}

void Bucket::clearBucket()
{
  this->pseudoKeys.clear();
  this->usedSize = 0;
}

string Bucket::getPseudoKey(int n)
{
  return this->pseudoKeys[n];
}

void Bucket::setPseudoKey(string n)
{
  this->pseudoKeys.push_back(n);
}

//Busca a chave no balde
int Bucket::Search(string key)
{
  int index = 0;
  for (string currentValue : this->pseudoKeys)
  {
    if (key == currentValue)
    {
      return index;
    }
    index++;
  }

  return -1;
}
