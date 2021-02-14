#include "./Tests.h"
#include "../Directory/Directory.h"
#include "../Directory/Directory.cpp"
#include "../Bucket/Bucket.h"
#include "../Bucket/Bucket.cpp"
#include <iostream>

using namespace std;
Tests::Tests()
{
}

Tests::~Tests()
{
}

string Tests::randomKeys(int B)
{
    int bits;
    string pseudoKey = "";
    for (int i = 0; i < B; i++)
    {
        bits = rand() % 100;
        bits = bits % 2;
        pseudoKey.append(to_string(bits));
    }
    return pseudoKey;
}

void Tests::doTests(int B, int M, int N)
{
    int notInserted = 0;
    Directory *direct = new Directory(M, B);

    cout << "Diretório criado" << endl;
    cout << "Teste 1" << endl;
    for (int i = 0; i < 20; i++)
    {
        string str = randomKeys(B);
        cout << str << endl;
        notInserted = direct->intHash(B, str);
        cout << notInserted << endl;
    }
    cout << "Teste 2" << endl;
    for (int i = 0; i < 20; i++)
    {
        string str = "0";
        str = str + randomKeys(B - 1);
        cout << str << endl;
    }
}