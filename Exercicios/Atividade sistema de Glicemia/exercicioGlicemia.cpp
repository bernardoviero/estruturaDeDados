/*
Fazer um programa em C, que leia um arquivo com dados glicemicos(valor,data e hora);
os dados lidos devem ser inseridos em uma pilha;(dados originais) e em uma lista (dados ordenados). ok
1- exiba os dados na pilha ok
2- exiba os dados na lista  ok
3- fazer um metodos que exiba ContarElementos da lista; ok
4- fazer um metodo calcularMedia dos elementos da lista ok
5- retornar a mediana da lista; valor que está no meio. se for para são dois números; ok
6- retornar o menor valor da lista ok
7- retornar o maior valor da lista ok
8- fazer um metodo que retorne os dois valores que mais repetem na lista(moda);
*/
#include "codigo.h"

int main(){
    Celula *pilha = NULL;
    Celula *lista = NULL;

    popularDoArquivo(&pilha,&lista);
    exibirPilha(pilha);
    exibirLista(lista);
    cout<<"O arquivo tem "<< contarNos(lista) << " elementos"<< endl;
    cout <<"\nO arquivo tem media: "<<calcularMedia(lista)<<endl;
    cout <<"\nA mediana da lista é:"<< calcularMediana(lista)<<endl;
    cout<<"\nO primeiro valor da lista é: "<<lista->valorGlicemia<< endl;
    cout<<"\nO último valor é: "<<retornaUltimo(lista)<<endl;
    

    return 1;
}

