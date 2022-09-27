#include "codigo.h"
#include <ctime>
using namespace std;

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

    int numeroApagar;
    cout <<"Qual numero deseja apagar ?";
    cin >> numeroApagar;

    lista=excluirOcorrencia(numeroApagar,lista);
    cout<<"lista pós exclusão:"<<endl;
    exibirLista(lista);


    return 1;
}