#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valor;
    //outros atrituos
    struct nodo *prox; //ponteiro para a próxima célula ou próximo elemento
} Celula;

void exibir(Celula *lista) {
    Celula *p;

    if (!lista) { //lista == NULL
        printf("Lista vazia.\n");
        return; //só sai do método
    } 

    //for(aponta p para o início da lista; enquanto p não chegar no final; p avança para o próximo)
    for (p = lista; p ; p = p->prox) { //percurso clássico: usado para exibir, contar, localizar, ...
        printf("%d\t", p->valor);
    }

    printf("\n");
    
}

Celula *inserir(int valor, Celula *lista) {
    //alocar memória
    Celula *novo = (Celula *)malloc(sizeof(Celula));
    
    //depositar valores que vem dos parametros
    novo->valor = valor;
    novo->prox = NULL; //como não sabemos onde o novo será inserido (inicio, meio, fim)

    if (!lista) { //caso a lista esteja vazia, na primeira inserção, a lista começa pelo novo
        return novo;
    }

    //percorrer com controle de duplicidade
    Celula *p, *pR; //pR sempre estará uma posição atrás do p
    for (pR = NULL, p = lista; p ; pR = p, p = p->prox) { 
        if (valor == p->valor) {
            printf("Ja cadastrado!\n");
            free(novo);
            return lista;
        }
       if (valor < p->valor) {
           break;
       }
    }
    //2 situações que saimos do for
    //1o porque chegamos no final (p é null). Isso significa que o valor a ser inserido será o último
    if (!p) {
        pR->prox = novo;
        return lista;
    }
    //2o porque saimos com o break. Isso significa que o valor vai ser inserido na primeira posição
    if (p == lista) {
        novo->prox = lista;
        return novo; //novo se torna o primeiro elemento da lista
    }
    //se não for o último e nem o primeiro, só pode estar no meio
    pR->prox = novo;
    novo->prox = p;
    return lista;
}

int contarElementos(Celula *lista) {
    if (!lista) return 0;

    Celula *p;
    
    int contador = 0;
    //for(aponta p para o início da lista; enquanto p não chegar no final; p avança para o próximo)
    for (p = lista; p  ; p = p->prox) {
        contador++;
    }

    // for (contador = 0, p = lista; p  ; p = p->prox, contatdor++);

    return contador;
}

char *regiaoValor(int valor, Celula *lista) {
    if (!lista) return "Lista vazia"; 

    Celula *p;
    
    for (p = lista; p  ; p = p->prox) { //percurso clássico: exibir, contar, localizar, excluir, ....
        if (valor == p->valor) {
            //verificar se é o primeiro
            if (p == lista) {
                return "é o primeiro";
            }
            //verificar se é o último
            if (p->prox == NULL) {
                return "é o último";
            }
            //se não é o primeiro e nem o último, só pode estar em alguma posição do meio
            return "está em alguma posição do meio";
        }
    }
    return "não encontrado";
}

int valorMeio(Celula *lista) {
    if (!lista) return -27; //valor do ESC

    int qtd = contarElementos(lista);

    if (qtd == 1 || qtd == 2) {
        return lista->valor;
    }

    qtd = (int)qtd / 2;

    Celula *p;
    int i;
    for (i = 0, p = lista; i < qtd; i++, p = p->prox); //leva o p até o meio

    return p->valor;
}

int main() {
    Celula *lista = NULL;
    system("clear");

    
    int valor;
    do {
        printf("Digite um numero inteiro (-1 para sair): ");
        scanf("%d", &valor);
        if (valor == -1)
            break;

        lista = inserir(valor, lista); //vamos inserir no final da lista //percorrendo e parando no último

    } while (1);

    exibir(lista); //percorrer passando por todos elementos

    int quantidadeElementos = contarElementos(lista); //percorrer passando por todos elementos
    printf("A lista possui %d elementos\n", quantidadeElementos);

    printf("Valor no meio da lista é: %d\n", valorMeio(lista));

    return 1;
}



/**
 * numeros a serem inseridos: 30 7 12 5 90 1 3
 * 
 * pilha -> 3 1 90 5 12 7 30
 * 
 * lista -> 30 7 12 5 90 1 3
 * 
 * listaOrdenada -> 1 3 5 7 12 30 90
 */ 
