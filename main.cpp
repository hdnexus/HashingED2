#include <iostream>
#include "./Classes/Tests/Tests.h"
#include "./Classes/Tests/Tests.cpp"
#include <string>
using namespace std;

int main()
{
    int M; // tamanho dos baldes
    int B; // número de bits
    int N; // número de pseudochaves

    Tests test;

    //Menu
    cout << "" << endl;
    cout << "Atividade de Hashing ED2" << endl;
    cout << "Gabriel Martins" << endl;
    cout << "" << endl;
    cout << "Digite o tamanho M a ser usado para os baldes: ";
    cin >> M;
    while (M < 0)
    {
        cout << "Valor invalido. Digite um valor positivo!!!!" << endl;
        cout << "Digite novamente o tamanho M a ser usado para os baldes: ";
        cin >> M;
    }
    cout << "Digite o numero de bits B a ser usado para as pseudo-chaves: ";
    cin >> B;
    while (B < 0)
    {
        cout << "Valor invalido. Digite um valor positivo!!!!" << endl;
        cout << "Digite novamente o numero de bits B a ser usado para as pseudo-chaves: ";
        cin >> B;
    }
    cout << "Insira o valor de N: ";
    cin >> N;
    while (N < 0)
    {
        cout << "Valor invalido. Digite um valor positivo!!!!" << endl;
        cout << "Insira novamente o valor de N: ";
        cin >> N;
    }
    cout << "Numeros digitados com sucesso!" << endl;
    cout << "Iniciando testes..." << endl;
    //Menu

    test.testsActivity(B, M, N);

    return 0;
}