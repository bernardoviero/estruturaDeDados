/*
1) Modificar o método inserir (lista):
alterar para que o mesmo valor não seja inserido mais de uma vez;
2) No método excluirOcorrências(lista):
Além de ele excluir as ocorrências ele, também exiba quantos números foram excluidos
3) Faça um método que receba 2 listas:
E exiba o números que apararece em comum nas listas
4) Faça um método que receba 2 listas:
o método deve unir AS DUAS LISTAS e RETORNAR uma nova lista com as duas LISTAS JUNTAS.
*/

#include "codigo.h"

int main(){

    Celula *lista = NULL;
    Celula *lista1 = NULL;
    Celula *lista2 = NULL;

    int opcaoExercicio;
    cout<<"Qual exercicio deseja executar: 1 | 2 | 4 |\n";
    cin >> opcaoExercicio;

    if(opcaoExercicio == 1){
    // exercicio 01
        lista = popularDoArquivo(lista);
        exibirLista(lista);
    }
    else if(opcaoExercicio == 2){
        // exercicio 02
        lista1 = popularDoArquivoLista1(lista1);
        exibirLista(lista1);
        int numeroApagar;
        cout<<"Qual numero deseja apagar ?";
        cin >> numeroApagar;
        lista1=excluirOcorrencia(numeroApagar,lista1);
        cout<<"lista pós exclusão:"<<endl;
        exibirLista(lista1);
    }
    else if(opcaoExercicio == 4){
        // exercicio 04
        lista1 = popularDoArquivoLista1(lista1);
        exibirLista(lista1);
        lista2 = popularDoArquivoLista2(lista2);
        exibirLista(lista2);
        exibirLista(unirListas(lista1,lista2));
    }


    return 1;
}