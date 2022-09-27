#include <stdio.h>
#include <stdlib.h>


int main(){

    FILE *procurador, *procuradorSaida;
    char nomeArquivo[200];
    int x,y;
    int conta1q = 0,conta2q = 0,conta3q = 0,conta4q = 0,contaOrigem = 0,qtdParticulas = 0;

    printf("nome arquivo da entrada das particulas: ");
    gets(nomeArquivo);

    procurador = fopen(nomeArquivo,"r");

    if(!procurador){
        printf("Arquivo com particular nao localizado\n");
        exit(0);
    }

    do{
        fscanf(procurador,"%d,%d",&x,&y);
        qtdParticulas++;
        if(x>0 && y>0){
            conta1q++;
        } else if(x<0 && y>0){
            conta2q++;
        } else if(x<0 && y<0){
            conta3q++;
        } else if(x>0 && y<0){
            conta4q++;
        } else{
            contaOrigem++;
        }
    }while(!feof(procurador));

    procuradorSaida = fopen("relatorio.txt","w");
    printf("arquivo gerado com sucesso!!!\n");
    fprintf(procuradorSaida,"Foram analisadas %d particulas\n",qtdParticulas);
    fprintf(procuradorSaida,"1º Quadradante: %d\n", conta1q);
    fprintf(procuradorSaida,"2º Quadradante: %d\n", conta2q);
    fprintf(procuradorSaida,"3º Quadradante: %d\n", conta3q);
    fprintf(procuradorSaida,"4º Quadradante: %d\n", conta4q);
    fprintf(procuradorSaida,"Origem: %d\n", contaOrigem);

    fclose(procuradorSaida);
    fclose(procurador);
    return 1;
}