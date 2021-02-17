#ifndef TESTS_H_INCLUDED
#define TESTS_H_INCLUDED
#include <iostream>

using namespace std;

class Tests
{
private:
public:
    Tests();                                 //OK
    ~Tests();                                //OK
    void testsActivity(int B, int M, int N); //OK
    string randomKeys(int B);                //OK
    void printStatistics();                  //OK
};

#endif