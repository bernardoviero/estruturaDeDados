#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arvore.h"

int main () {
    Arvore *raiz = NULL;

    int quantidadeNumeros;
    // printf("Quantos números quer gerar?");
    // scanf("%d", &quantidadeNumeros);

    srand(time(NULL));
    quantidadeNumeros = rand() % 20 + 5;

    
    for (int i = 0; i < quantidadeNumeros; i++) {
        raiz = inserir(rand() % 50, raiz);
    }
    
    exibir(raiz, 0);
    printf("\nEsta árvore possui %d nós\n", contarNos(raiz));
    printf("A soma dos elementos da árvore é: %d\n", somarNos(raiz));
    printf("Esta árvore possui %d nós pares\n", contarNosPares(raiz));

    int valorPesquisa;
    printf("Digite valor para pesquisa: ");
    scanf("%d", &valorPesquisa);

    int nivel = localizarNivel(valorPesquisa, raiz);
    if (nivel != -1) {
        printf("Valor localizado na árvore no nível %d\n", nivel);
        if (nivel % 2 == 0) {
            printf("Valor está em um nível par\n");
        }
    } else {
        printf("Valor não localizado na árvore\n");
    }

    printf("O valor %d aparece na árvore %d vezes\n", valorPesquisa, contarVezes(valorPesquisa, raiz));
    printf("A quantidade de múltiplos de %d é: %d\n", valorPesquisa, multiplos(valorPesquisa, raiz));
    printf("A quantidade de nós folhas é: %d\n", contarFolhas(raiz));
    printf("E os nós folhas são: "); mostrarFolhas(raiz);
    printf("\n");
    printf("A quantidade de nós NÃO folhas é: %d\n", contarNaoFolhas(raiz));

    return 1;
}