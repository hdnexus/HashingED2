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

char Bucket::getSpecificBit(int i, int j)
{
  return this->pseudoKeys[i].at(j);
}

int Bucket::getSize()
{
  return mSize;
}

void Bucket::incrementLocalDepth()
{
  this->localDepth = this->localDepth + 1;
}

void Bucket::Remove(string key, int globalDepth) //
{
  if (this->Search(key) != -1)
  {
    this->pseudoKeys.erase(this->pseudoKeys.begin() + this->Search(key));
    this->decreaseUsedSize();
    int index = 0;

    for (int i = 0; i < pseudoKeys.size(); i++)
    {
      string key = getPseudoKey(i);
      this->pseudoKeys.erase(this->pseudoKeys.begin() + index);
      this->decreaseUsedSize();
      newLocalDepth(key, globalDepth);
      this->pseudoKeys.push_back(key);
      this->incrementUsedSize();
      index++;
    }
  }
}

void Bucket::newLocalDepth(string key, int globalDepth)
{

  int numberOfBits;
  this->localDepth = 0;

  for (int i = 0; i < globalDepth; i++)
  {
    numberOfBits = 0;
    for (int j = 0; j < this->getUsedSize(); j++)
    {
      if (key.substr(0, globalDepth).at(i) == getSpecificBit(j, i))
      {
        numberOfBits++;
      }
    }

    if (numberOfBits == this->getUsedSize())
    {
      this->localDepth++;
    }
  }
}

bool Bucket::Insert(string pseudoKey, int globalDepth)
{
  if (!Full())
  {
    this->pseudoKeys.push_back(pseudoKey);
    this->newLocalDepth(pseudoKey, globalDepth);
    this->incrementUsedSize();
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
    return true;
  }
  else
  {
    return false;
  }
}

int Bucket::getUsedSize()
{
  return this->usedSize;
}

void Bucket::incrementUsedSize()
{
  this->usedSize = this->usedSize + 1;
}

void Bucket::decreaseUsedSize()
{
  this->usedSize = this->usedSize - 1;
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
  for (int i = 0; i < this->pseudoKeys.size(); i++)
  {
    string keyB = this->getPseudoKey(i);
    if (keyB == key)
    {
      return index;
    }
    else
    {
      index++;
    }
  }
  return -1;
}
