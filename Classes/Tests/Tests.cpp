#include "./Tests.h"
#include "../Directory/Directory.h"
#include "../Directory/Directory.cpp"
#include "../Bucket/Bucket.h"
#include "../Bucket/Bucket.cpp"
#include <iostream>
#include <string>
#include <random>

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
    int notInserted = 0;
    Directory *directA = new Directory(M, B);
    Directory *directB = new Directory(M, B);
    string pseudoKey = "";

    cout << "\nResultado para N pseudo-chaves aleatórias" << endl;
    for (int i = 0; i < N; i++)
    {
        pseudoKey = "";
        pseudoKey = randomKeys(B);
        if (directA->Search(pseudoKey))
        {
            i--;
        }
        else
        {
            directA->Insert(pseudoKey);
        }
        cout << "O valor da pseudokey e: " << pseudoKey << endl;
    }

    cout << "\n------------------ RESULTADOS ------------------" << endl;

    directA->getResults();

    cout << "------------------------------------------------" << endl;

    cout << "\nResultado para N pseudo-chaves iniciadas com um mesmo padrão de bits" << endl;
    for (int j = 0; j < N; j++)
    {
        pseudoKey = "";
        pseudoKey = "10";
        pseudoKey += randomKeys(B - 2);
        if (directB->Search(pseudoKey))
        {
            j--;
        }
        else
        {
            directB->Insert(pseudoKey);
        }
    }
    cout << "\n------------------ RESULTADOS ------------------" << endl;

    directB->getResults();

    cout << "------------------------------------------------" << endl;
}