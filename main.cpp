#include <iostream>
#include "./Classes/Tests/Tests.h"
#include "./Classes/Tests/Tests.cpp"

using namespace std;

void menuAtividade(int M, int B)
{
    cout << "" << endl;
    cout << "Atividade de Hashing ED2" << endl;
    cout << "Gabriel Martins" << endl;
    cout << "" << endl;
    cout << "Digite o tamanho M a ser usado para os baldes: ";
    cin >> M;
    cout << "Digite o numero de bits B a ser usado para as pseudo-chaves: ";
    cin >> B;
    cout << "Numeros digitados com sucesso!" << endl;
    cout << "Iniciando testes..." << endl;

    Tests test;
    test.doTests(B, M);
    cout << "opa";
}

int main()
{
    int M;
    int B;

    menuAtividade(M, B);

    return 0;
}