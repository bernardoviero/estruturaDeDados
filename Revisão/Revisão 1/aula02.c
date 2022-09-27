#include <stdio.h>
#include <stdlib.h>

    //Contruir um programa que receba nome,altura,peso de um possivel atleta.
        // se altura < 1,80 e peso > 70; retornar atletismo.
        // se altura > 1,80 e peso < 70; retornar volei ou basquete
        // se nao; retorna futebol
        
typedef struct{
    char nome[100];
    float altura;
    float peso;
}Atleta;
char * escolhe(Atleta a);

int main(){
    Atleta umAtleta;
    printf("nome: ");
    scanf("%c",umAtleta.nome);
    printf("altura: ");
    scanf("%f",&umAtleta.altura);
    printf("peso: ");
    scanf("%f",&umAtleta.peso);
    char * reposta = escolhe(umAtleta);

    return 1;
}

char * escolhe(Atleta a){
    if(a.altura < 1.80 && a.peso < 70){
        printf("Atletismo");
    }else if(a.altura > 1.80 && a.peso < 70){
        printf("volei ou basquete");
    }else{
        printf("futebol");
    }
}