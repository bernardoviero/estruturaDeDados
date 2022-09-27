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
}Celula;

Celula *inserirPilha(int valor, Celula *topo){
    // alocar memomira
    Celula *novo = (Celula *)malloc(sizeof(Celula));
    //depositar valor
    novo->dado = valor;
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
    novo->dado = valor;
    novo->prox = NULL; // não sei onde ele vai ser inserido ! inicia-se nulo;
    // localizar a posicao de inserção
    // testar primeira vez:
    if (!lista)
        return novo;

    for (pR = NULL, p = lista; p; pR = p, p = p->prox)
    {
        if (valor < p->dado)
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
        printf("%d\n", p->dado);
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
        cout << p->dado << endl;
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
    string dado;

    int posicaoEspaco =0;
    while (getline(procurador, linha))
    {
        posicaoEspaco = linha.find(" ");
        //extrair glicemia
        dado = linha.substr(0,posicaoEspaco);
        *topo = inserirPilha(stoi(dado),*topo);
        *lista = inserirLista(stoi(dado),*lista);
    }

    procurador.close();
    return *topo,*lista;
}

int contarNos(Celula *lista){
    int qtd = 0;
    Celula *p;
    for (p = lista; p ; p = p->prox){
        qtd++;
    }
    return qtd;
}

Celula *excluirLista(int valor, Celula *lista) {
  Celula *p, *pR;

  if (!lista) {
    cout << "Lista vazia. Operação cancelada!" << endl;
    return lista;
  }

  for (pR = NULL, p = lista; p; pR = p, p = p->prox) {
    if (valor == p->dado) {
      //eh o primeiro
      if (p == lista) {
        lista = lista->prox;
      } else if (!p->prox) { //eh o ultimo
        pR->prox = NULL;
      } else { //esta entre celulas
        pR->prox = p->prox;
      }
      free(p);
      return lista;
    }
  }
  cout << "Valor não localizado para exclusão!" << endl;
  return lista;
}

Celula *excluirOcorrencia(int valor, Celula *lista) {
    Celula *p, *pR;
    bool exclusao;

    if (!lista) {
        cout << "Lista vazia. Operação cancelada!" << endl;
        return lista;
    }

    do{
        exclusao = false;
        for (pR = NULL, p = lista; p; pR = p, p = p->prox) {
            if (valor == p->dado) {
                //eh o primeiro
                if (p == lista) {
                    lista = lista->prox;
                } else if (!p->prox) { //eh o ultimo
                    pR->prox = NULL;
                } else { //esta entre celulas
                    pR->prox = p->prox;
                }
                free(p);
                exclusao = true;
                break;
            }
        }
    }while(exclusao == true);

    return lista;
}

Celula *excluirPrimeiroUltimo(Celula *lista){
    Celula *primeiro = lista;
    Celula *p,*pR;
    int qtd = contarNos(lista);
    if(qtd > 3){
    // removendo primeiro elemento
        lista = lista->prox;
        free(primeiro);
    // removendo ultimo elemento
        for(pR = NULL, p = lista; p->prox; pR = p, p = p->prox);
        pR->prox = NULL;
        free(p);
    }
    return lista;
}