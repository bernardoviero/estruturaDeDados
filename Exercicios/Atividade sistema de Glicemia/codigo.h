#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

typedef struct no{
    int valorGlicemia;
    string data;
    string hora;
    struct no *prox;
}Celula;

Celula *inserirPilha(int valor, Celula *topo){
    // alocar memomira
    Celula *novo = (Celula *)malloc(sizeof(Celula));
    //depositar valor
    novo->valorGlicemia = valor;
    //engatar o novo no ultimo
    novo->prox = topo;
    //retornar o novo top
    return novo;
}
Celula *inserirLista(int valor, Celula *lista)
{
    Celula *novo, *p, *pR;
    // alocar memomoria
    novo = (Celula *)malloc(sizeof(Celula));
    // depositar valores
    novo->valorGlicemia = valor;
    novo->prox = NULL; // não sei onde ele vai ser inserido ! inicia-se nulo;
    // localizar a posicao de inserção
    // testar primeira vez:
    if (!lista)
        return novo;

    for (pR = NULL, p = lista; p; pR = p, p = p->prox)
    {
        if (valor < p->valorGlicemia)
        { // encontrei a posicao
            break;
        }
    }
    // engatar
    // testar se no inicio
    if (p == lista)
    {
        novo->prox = lista;
        return novo;
    }
    else if (!p)
    { // testar se no fim
        pR->prox = novo;
        return lista;
    }
    else
    { // no meio
        pR->prox = novo;
        novo->prox = p;
    }
    return lista;
    // retornar ao inicio da lista
}
void exibirPilha(Celula *topo) {
    if (!topo) {
        printf("Pilha vazia\n");
        return;
    }
    cout<< "Pilha: \n";
    Celula *p;
    for (p = topo; p ; p = p->prox){
        printf("%d\n", p->valorGlicemia);
    } 
}

void exibirLista(Celula *lista)
{
    if (!lista)
    {
        cout << "lista vazia\n";
        return;
    }
    cout << "Lista: \n";
    Celula *p;
    for (p = lista; p; p = p->prox)
    {
        cout << p->valorGlicemia << endl;
    }
}
Celula *popularDoArquivo(Celula **topo, Celula **lista){
    // ifstream -> inputar
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
    
    int valor;

    string linha;
    string valorGlicemia;

    int posicaoEspaco =0;
    while (getline(procurador, linha))
    {
        posicaoEspaco = linha.find(" ");
        //extrair glicemia
        valorGlicemia = linha.substr(0,posicaoEspaco);
        *topo = inserirPilha(stoi(valorGlicemia),*topo);
        *lista = inserirLista(stoi(valorGlicemia),*lista);
    }

    procurador.close();
    return *topo,*lista;
}

int contarNos(Celula *lista) {
    int qtd = 0;
    Celula *p;
    for (p = lista; p ; p = p->prox){
        qtd++;
    }
    return qtd;
}

int calcularMedia(Celula *lista){
    int soma = 0;

    Celula *p;
    for(p = lista; p; p = p->prox){
        soma+=p->valorGlicemia;
    }

    return soma / contarNos(lista);
}

int calcularMediana(Celula *lista){
    int quantidadeElementos = contarNos(lista);
    bool ehPar;

    if(quantidadeElementos % 2 == 0){
        ehPar = true;
    }else{
        ehPar = false;
    }
    int i;
    int metade;
    Celula *p;
    if (!ehPar){
        metade = (int)quantidadeElementos/2;
    }else{
        metade = (int)quantidadeElementos/2 - 1;
    }
    for(i = 0, p = lista; i <metade; i++, p =p->prox);

    if(!ehPar) return p->valorGlicemia;

    return (p->valorGlicemia + p->prox->valorGlicemia)/2;
}

int retornaUltimo(Celula *lista){
    Celula *p;
    Celula *ultimo;
    for (p = lista; p->prox; p = p->prox){
        ultimo = p->prox;
    }
    return ultimo->valorGlicemia;
}