/*
Programa que leia um arquivo com nºinteiros(um abaixo do outros);
E os popules em uma pilha encadeada dinâmicamente!
Ao final, exibi quantos elementos há na pilha
Seu (topo)-ultimo valor;
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int dado;
    struct no *prox;
} Celula;

Celula *inserir(int valor, Celula *topo){
    // alocar memomira
    Celula *novo = (Celula *)malloc(sizeof(Celula));

    //depositar valor
    novo->dado = valor;
    //engatar o novo no ultimo
    novo->prox = topo;
    //retornar o novo top
    return novo;
}
int contarNos(Celula *topo) {
    int qtd = 0;
    Celula *p;
    for (p = topo; p ; p = p->prox){
        qtd++;
    }
    return qtd;
}
void exibir(Celula *topo) {
    if (!topo) {
        printf("Pilha vazia\n");
        return;
    }
    Celula *p;
    for (p = topo; p ; p = p->prox){
        printf("%d\t", p->dado);
    } 
}

int main(){

    FILE *procuradorArquivo;
    char nomeArquivo[200];
    int valor;
    Celula *pilha = NULL;

    system("cls");
    printf("digite o nome do arquivo para abrir: ");
    scanf("%s",nomeArquivo);
    
    procuradorArquivo=fopen(nomeArquivo,"r");

    if(!procuradorArquivo){
        printf("arquivo não localizado!");
    }else{
        printf("arquivo localizado!\n");
        do{
            fscanf(procuradorArquivo,"%d",&valor);
            pilha = inserir(valor,pilha);
            //printf("passei %d\n", valor);

        }while(!feof(procuradorArquivo));
        fclose(procuradorArquivo);
        printf("o arq tem %d elementos:\n",contarNos(pilha));

        exibir(pilha);
        //printf("fim");
    }

    return 1;
}