#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

typedef struct no{
    int dado;
    struct no *prox;
}Celula, Celula;

Celula *inserirListaSemRepeticao(int valor, Celula *lista)
{
    Celula *novo, *p, *pR;

    // alocar memomoria
    novo = (Celula *)malloc(sizeof(Celula));

    // depositar valores
    novo->dado = valor;
    novo->prox = NULL;

    // testar primeira vez:
    if (!lista){
        return novo;
    }

    for (pR = NULL, p = lista; p; pR = p, p = p->prox){
        if (valor < p->dado){ // encontrei a posicao
            break;
        }
        if(valor == p->dado){
            return lista;
        }
    }

    // engatar
    // testar se no inicio
    if (p == lista){
        novo->prox = lista;
        return novo;
    }
    else if (!p){ // fim
        pR->prox = novo;
        return lista;
    }
    else{ // meio
        pR->prox = novo;
        novo->prox = p;
    }


    return lista;
}


// IMPEDIR QUE O MESMO NÚMERO SEJA ALOCADO DUAS VEZES;
Celula *inserirLista1(int valor, Celula *lista1)
{
    Celula *novo, *p, *pR;

    // alocar memomoria
    novo = (Celula *)malloc(sizeof(Celula));

    // depositar valores
    novo->dado = valor;
    novo->prox = NULL;

    // testar primeira vez:
    if (!lista1){
        return novo;
    }

    for (pR = NULL, p = lista1; p; pR = p, p = p->prox){
        if (valor < p->dado)
        { // encontrei a posicao
            break;
        }
    }

    // engatar
    // testar se no inicio

    if (p == lista1){
        novo->prox = lista1;
        return novo;
    }
    else if (!p){ // fim
        pR->prox = novo;
        return lista1;
    }
    else{ // meio
        pR->prox = novo;
        novo->prox = p;
    }


    return lista1;
}
Celula *inserirLista2(int valor, Celula *lista2)
{
    Celula *novo, *p, *pR;

    // alocar memomoria
    novo = (Celula *)malloc(sizeof(Celula));

    // depositar valores
    novo->dado = valor;
    novo->prox = NULL;

    // testar primeira vez:
    if (!lista2){
        return novo;
    }

    for (pR = NULL, p = lista2; p; pR = p, p = p->prox){
        if (valor < p->dado)
        { // encontrei a posicao
            break;
        }
    }

    // engatar
    // testar se no inicio

    if (p == lista2){
        novo->prox = lista2;
        return novo;
    }
    else if (!p){ // fim
        pR->prox = novo;
        return lista2;
    }
    else{ // meio
        pR->prox = novo;
        novo->prox = p;
    }


    return lista2;
}
Celula *popularDoArquivo(Celula *lista){
    // ifstream -> input
    // ofstream -> output
    ifstream procurador;
    char nomeArquivo[200];

    cout << "informe o caminho do arquivo com numeros: ";
    cin >> nomeArquivo;

    procurador.open(nomeArquivo);

    if (!procurador)
    {
        cout << "arquivo n localizado\n";
        return lista;
    }

    string linha;
    int valor;

    while (getline(procurador, linha))
    {
        stringstream pegaInteiro(linha);
        pegaInteiro >> valor;
        lista = inserirListaSemRepeticao(valor, lista);
    }

    procurador.close();
    return lista;

}

Celula *popularDoArquivoLista1(Celula *lista1){
    // ifstream -> input
    // ofstream -> output
    ifstream procurador;
    char nomeArquivo[200];

    cout << "informe o caminho do arquivo com numeros: ";
    cin >> nomeArquivo;

    procurador.open(nomeArquivo);

    if (!procurador)
    {
        cout << "arquivo n localizado\n";
        return NULL;
    }

    string linha;
    int valor;

    while (getline(procurador, linha))
    {
        stringstream pegaInteiro(linha);
        pegaInteiro >> valor;
        lista1 = inserirLista1(valor, lista1);
    }

    procurador.close();
    return lista1;

}

Celula *popularDoArquivoLista2(Celula *lista2){
    // ifstream -> input
    // ofstream -> output
    ifstream procurador;
    char nomeArquivo[200];

    cout << "informe o caminho do arquivo com numeros: ";
    cin >> nomeArquivo;

    procurador.open(nomeArquivo);

    if (!procurador)
    {
        cout << "arquivo n localizado\n";
        return NULL;
    }

    string linha;
    int valor;

    while (getline(procurador, linha))
    {
        stringstream pegaInteiro(linha);
        pegaInteiro >> valor;
        lista2 = inserirLista2(valor, lista2);
    }

    procurador.close();
    return lista2;

}

void exibirLista(Celula *lista1)
{
    if (!lista1)
    {
        cout << "lista vazia\n";
        return;
    }
    cout << "Lista: \n";
    Celula *p;
    for (p = lista1; p; p = p->prox)
    {
        cout << p->dado << endl;
    }
}

Celula *excluirOcorrencia(int valor, Celula *lista) {
    Celula *p, *pR;
    int qnt = 0;
    bool exclusao;

    if (!lista) {
        cout << "Lista vazia. Operação cancelada!" << endl;
        return lista;
    }
    do{
        exclusao = false;
        for (pR = NULL, p = lista; p; pR = p, p = p->prox) {
            if (valor == p->dado) {
                //primeiro
                if (p == lista) {
                    lista = lista->prox;
                } else if (!p->prox) { //ultimo
                    pR->prox = NULL;
                } else { //entre celulas
                    pR->prox = p->prox;
                }
                free(p);
                exclusao = true;
                break;
            }
        }
        if(exclusao == true){
            qnt++;
        }
    }while(exclusao == true);

    cout<<"O numero:"<<valor<<" foi excluido "<<qnt<<" vezes."<<endl;

    return lista;
}
/*Celula *compararListas(Celula *lista1, Celula *lista2){
    Celula *p1,*pR1,*p2,*pR2;
    for(pR = NULL, );
}*/

Celula *unirListas(Celula* lista1, Celula* lista2) {
    Celula *p, *pR;
    Celula *temporaria = lista1;
    if (lista1 == NULL){
        return lista2;
    }

    if (lista2 == NULL){
        return lista1;
    }

    for(pR = NULL, p = lista1; p->prox; pR = p, p = p->prox);
    p->prox = lista2;

    return temporaria;

}