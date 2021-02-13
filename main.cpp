#include<iostream>
#include "./Classes/Tests/Tests.h"
#include "./Classes/Tests/Tests.cpp"


using namespace std;
void menuAtividade(int M, int nBits)
{
    cout << "----------------------------------------------------" << endl;
    cout << "--------------Atividade de Hashing ED2--------------" << endl;
    cout << "------------------Gabriel Martins-------------------" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "Digite o tamanho dos baldes: ";
    cin >> M;
    cout << "Digite o numero de Bits: ";
    cin >> nBits;
    cout << "----------------------------------------------------" << endl;
    cout << "------------Numeros digitados com sucesso-----------" << endl;
    cout << "----------------------------------------------------" << endl;

    Tests test;
    test.doTests(nBits, M);
}
int main(){
    int M;
    int nBits;

    menuAtividade(M,nBits);
    

}