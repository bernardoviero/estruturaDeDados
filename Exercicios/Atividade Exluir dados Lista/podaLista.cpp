#include "codigo.h"
#include <ctime>

Celula *popular(Celula *lista, int n){
    srand(time(NULL));

    for(int i=0;i<n;i++){
        lista = inserirLista(rand()%50,lista);
    }
    return lista;
}

int main(){

    int qntNumeroLista = 30;
    Celula *lista = NULL;

    lista = popular(lista, qntNumeroLista);
    cout<<"lista inicial:"<<endl;
    exibirLista(lista);

    cout<<"O arquivo tem "<< contarNos(lista) << " elementos"<< endl;

    
    lista = excluirPrimeiroUltimo(lista);
    cout<<"lista pós poda:"<<endl;
    exibirLista(lista);
 
    return 1;
}