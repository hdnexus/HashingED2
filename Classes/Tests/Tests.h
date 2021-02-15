#ifndef TESTS_H_INCLUDED
#define TESTS_H_INCLUDED
#include <iostream>

using namespace std;

class Tests
{
private:
public:
    Tests();
    ~Tests();
    void testsActivity(int B, int M, int N);
    string randomKeys(int B);
    void printStatistics();
};

#endif