#include "./Bucket.h"
#include <sstream>
#include <cassert>
#include <iostream>

using namespace std;

//construtor do balde
Bucket::Bucket(int M)
{
  this->mSize = M;
  this->localDepth = 0;
  this->usedSize = 0;
}

//destrutor do balde
Bucket::~Bucket()
{
}

//função para obter a profundidade local
int Bucket::getLocalDepth()
{
  return this->localDepth;
}

//função para obter um bit especifico de uma string
char Bucket::getSpecificBit(int i, int j)
{
  return this->pseudoKeys[i].at(j);
}

//função para obter o tamanho máximo do balde
int Bucket::getSize()
{
  return mSize;
}
//função para incrementar a profundidade local
void Bucket::incrementLocalDepth()
{
  this->localDepth = this->localDepth + 1;
}

//função para remover uma pseudochave e recalcular a profundidade local
void Bucket::Remove(string key, int globalDepth)
{
  if (this->Search(key) != -1)
  {
    this->pseudoKeys.erase(this->pseudoKeys.begin() + this->Search(key));
    this->decreaseUsedSize();
    int index = 0;

    for (int i = 0; i < pseudoKeys.size(); i++)
    {
      string anotherKey = getPseudoKey(i);
      this->pseudoKeys.erase(this->pseudoKeys.begin() + index);
      this->decreaseUsedSize();
      newLocalDepth(anotherKey, globalDepth);
      this->pseudoKeys.push_back(anotherKey);
      this->incrementUsedSize();
      index++;
    }
  }
}

//função para verificar a profundidade
void Bucket::newLocalDepth(string key, int globalDepth)
{

  int numberOfBits;
  this->localDepth = 0;

  for (int i = 0; i < globalDepth; i++)
  {
    numberOfBits = 0;
    for (int j = 0; j < this->getUsedSize(); j++)
    {
      string specificBit = key.substr(0, globalDepth);
      if (specificBit.at(i) == getSpecificBit(j, i))
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

//função para inserir pseudokey no balde
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

//função para checar se o balde está cheio
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

//função para obter o tamanho usado
int Bucket::getUsedSize()
{
  return this->usedSize;
}

//função para incrementar o tamanho usado
void Bucket::incrementUsedSize()
{
  this->usedSize = this->usedSize + 1;
}

//função para decrementar o tamanho usado
void Bucket::decreaseUsedSize()
{
  this->usedSize = this->usedSize - 1;
}

//função para obter uma determinada pseudochave
string Bucket::getPseudoKey(int n)
{
  return this->pseudoKeys[n];
}

//função para inserir uma pseudochave de valor n
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
