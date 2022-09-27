#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    FILE *procurador;

    char nomeArquivo[200];
    int qntNumeros;

    printf("Nome do arquivo de saida c/ números?");
    scanf("%s",nomeArquivo);

    //verificar se o arquivo existe; se sim(exit), se não(abre no modo escrita)

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
    for(; qntNumeros > 0; qntNumeros++){
        valor = rand()%1000;
        fprintf(procurador,"%d\n",valor);
        fflush(procurador);
    }

    fclose(procurador);

    return 1;
}