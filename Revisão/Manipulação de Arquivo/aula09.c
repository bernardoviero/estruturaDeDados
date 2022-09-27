#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    FILE *procurador;
    char nomeArquivo[200];
    int x,y;
    int qntParticulas;

    printf("Digite o nome do arquivo: ");
    gets(nomeArquivo);
    // reescrever sobre o arquivo.
    procurador = fopen(nomeArquivo,"w");

    //qnt particulas
    printf("quantas particulas ?");
    scanf("%d",&qntParticulas);

    srand(time(NULL));
    for(; qntParticulas > 0; qntParticulas--){
        x = 100 - rand()%200; 
        y = 100 - rand()%200;

        fprintf(procurador,"%d,%d\n",x,y);
        fflush(procurador);

    }

    fclose(procurador);

    return 1;
}