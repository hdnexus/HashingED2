#ifndef TESTS_H_INCLUDED
#define TESTS_H_INCLUDED
#include <iostream>

using namespace std;

class Tests
{
    private:
     
    public:
     Tests();
     void doTests(int nBits, int M);
     void firstTest();
     void secondTest();
     void printStatistics();
};

#endif