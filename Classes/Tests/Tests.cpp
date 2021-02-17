#include "./Tests.h"
#include "../Directory/Directory.h"
#include "../Directory/Directory.cpp"
#include "../Bucket/Bucket.h"
#include "../Bucket/Bucket.cpp"
#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

random_device rd;
mt19937 gen(rd());

Tests::Tests()
{
}

Tests::~Tests()
{
}

string Tests::randomKeys(int B)
{
    uniform_int_distribution<> int1(0, 1);
    string s;
    s.resize(B);
    for (size_t i = 0; i < B; i++)
        s.insert(i, to_string(int1(gen)));

    return s;
}

void Tests::testsActivity(int B, int M, int N)
{
    clock_t startTime = 0, finalTime;
    int notInserted = 0;
    Directory *directA = new Directory(M, B);
    Directory *directB = new Directory(M, B);
    string pseudoKey = "";

    cout << "\nEtapa 01" << endl;
    startTime = clock();
    for (int i = 0; i < N; i++)
    {
        pseudoKey = "";
        pseudoKey = randomKeys(B);
        directA->Insert(pseudoKey);
    }
    finalTime = clock();
    cout << "Resultado para N pseudo-chaves aleatórias" << endl;

    directA->getResults();
    cout << "Tempo gasto: " << (finalTime - startTime) / ((float)CLOCKS_PER_SEC) << endl;
    cout << "" << endl;

    cout << "\nEtapa 02" << endl;
    startTime = clock();
    for (int j = 0; j < N; j++)
    {
        if (B == 1)
        {
            pseudoKey = "0";
        }
        else
        {
            pseudoKey = "";
            pseudoKey = "01";
            pseudoKey += randomKeys(B - 2);
        }
        directB->Insert(pseudoKey);
    }
    finalTime = clock();
    cout << "Resultado para N pseudo-chaves iniciadas com um mesmo padrão de bits" << endl;

    directB->getResults();
    cout << "Tempo gasto: " << (finalTime - startTime) / ((float)CLOCKS_PER_SEC) << endl;
    cout << "" << endl;
}