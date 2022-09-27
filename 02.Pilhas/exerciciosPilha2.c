/*
Criar um programa em C (modulado) que gere números aleatórios e inteiros.
A quantidade de números é definida pelo usuário. 

Para cada número gerado, analisar:
    Se for par inseri-lo na pilha (conforme trabalho em aula). 
    Se for ímpar, remover o elemento do topo.

    Ao final, exibir a pilha resultante.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// criando a struct:
typedef struct no{
    int dado;
    struct no *prox;
} Celula;

//gerando os numeros no arq
int numerosNoArquivo(){
    FILE *procurador;
    char nomeArquivo[200];
    int qntNumeros;
    int rangeNumeros;

    printf("Nome do arquivo de saida c/ números?");
    scanf("%s",nomeArquivo);
    
    procurador = fopen(nomeArquivo,"r");
    if(procurador){
        printf("Arquivo já existente!");
        fclose(procurador);
        exit(0);
    }

    procurador = fopen(nomeArquivo,"w");
    printf("Quantos numeros quer gerar no arq ?");
    scanf("%d", &qntNumeros);

    int valor;
    srand(time(NULL));
    for (; qntNumeros >0; qntNumeros--){
        valor = 100 - rand() % 200;
        fprintf(procurador,"%d ",valor);
        fflush(procurador);
    }
    fclose(procurador);
}
//FUNCAO EXIBIR
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
//inserindo os numeros da pilha:
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

int main(){

    numerosNoArquivo();
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
        }while(!feof(procuradorArquivo));
        fclose(procuradorArquivo);
        exibir(pilha);
    }

    return 1;
}