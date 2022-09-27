#include <stdio.h>
#include <stdlib.h>

int main () {

    FILE * procurador;

    char nomeArquivo[200], linha[200];

    printf("Nome do arquivo: ");
    scanf ("%s",nomeArquivo);

    procurador = fopen (nomeArquivo,"r");
        if (!procurador){
            exit (0);
        }
    do
    {
        fgets(linha,200,procurador);
        printf("%s",linha);
            
    } while (!feof(procurador));
    fclose(procurador);
        
    return 1;
}