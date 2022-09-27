#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

#include "codigo.h"
int main(){
    ifstream procurador;
    int mesmaAltura;
    int valorDigitado;
    int folha;

    char nomeArquivo[200];
    cout << "Nome do arquivo fonte com os numeros: ";
    cin >> nomeArquivo;

    procurador.open(nomeArquivo);
    if (!procurador) {
        cout << "Arquivo nao localizado!\n";
        exit(0);
    }

    //daqui pra baixo
    int valor;
    Arvore *raiz = NULL;
    do {
        procurador >> valor;
        raiz = inserir(valor,raiz);
    } while(!procurador.eof());
    procurador.close();

    exibir(raiz,0);
    cout<<"\n\n"<<endl;

    mesmaAltura = estaoNaMesmaAltura(raiz);
    cout<<"Se estiverem na mesma altura, resposta = 1; se nao, resposta = 0: \n"<<mesmaAltura<<endl;

    cout << "Digite um valor para saber se eh uma folha, ou nao: \n";
    cin >> valorDigitado;
    folha = localizarFolha(valorDigitado,raiz);
    cout<<"(Se resposta 1 = Folha; se nao 0 = nao eh folha): \n"<<folha;

    return 1;
}