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

//construtor da classe
Tests::Tests()
{
}

//destrutor da classe
Tests::~Tests()
{
}

//função para gerar a string de binário com bits aleatórios
//referência https://stackoverflow.com/questions/25357892/create-random-binary-string-how-to-remove-null-character-0-from-to-string
string Tests::randomKeys(int B)
{
    uniform_int_distribution<> int1(0, 1);
    string s;
    s.reserve(B);
    for (size_t i = 0; i < B; i++)
        s.push_back(int1(gen) ? '1' : '0');
    return s;
}

//função que irá fazer os testes
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
        pseudoKey = "";
        pseudoKey = "0";
        pseudoKey += randomKeys(B - 1);

        directB->Insert(pseudoKey);
    }
    finalTime = clock();
    cout << "Resultado para N pseudo-chaves iniciadas com um mesmo padrão de bits" << endl;

    directB->getResults();
    cout << "Tempo gasto: " << (finalTime - startTime) / ((float)CLOCKS_PER_SEC) << endl;
    cout << "" << endl;
}