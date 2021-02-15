#include <iostream>
#include "./Classes/Tests/Tests.h"
#include "./Classes/Tests/Tests.cpp"

using namespace std;

int main()
{
    int M;
    int B;
    int N;
    Tests test;
    cout << "" << endl;
    cout << "Atividade de Hashing ED2" << endl;
    cout << "Gabriel Martins" << endl;
    cout << "" << endl;
    cout << "Digite o tamanho M a ser usado para os baldes: ";
    cin >> M;
    cout << "Digite o numero de bits B a ser usado para as pseudo-chaves: ";
    cin >> B;
    cout << "Insira o valor de N: ";
    cin >> N;

    cout << "Numeros digitados com sucesso!" << endl;
    cout << "Iniciando testes..." << endl;

    test.testsActivity(B, M, N);

    return 0;
}