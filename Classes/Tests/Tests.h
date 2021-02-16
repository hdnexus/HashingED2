#ifndef TESTS_H_INCLUDED
#define TESTS_H_INCLUDED
#include <iostream>

using namespace std;

class Tests
{
private:
public:
    //Construtor dos testes
    Tests();
    //Destrutor dos testes
    ~Tests();
    //função que irá realizar os testes
    void testsActivity(int B, int M, int N);
    //função que irá gerar um binario randomico
    string randomKeys(int B);
};

#endif