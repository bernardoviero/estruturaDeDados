/*
Fichas normais e de prioridade

-==Menu-==
1. Retirar ficha NORMAL => inserir ficha(n°)
2. Retirar ficha PRIORITÁRIA => inserir ficha(n°!=)
3. Atender => excluir a ficha
4. Mostrar filas => exibir a fila
5. Sair 

==> OPÇÕES:
FICHAS NORMAIS: 100 A 500(LETRA n NA FRENTE)
FICHAS PRIORITARIAS: 1000 a 1500(LETRA p NA FRENTE)

3 contadores:
contaFichaNormal = 100;
contaFichaPrioritaria = 1000;
contaAtendimentos = 0; => a cada 3 normais atende um prioritario

-> TODA VEZ QUE RETIRAR A FICHA; INFORMAR O NÚMERO. => inseriu a ficha; printou
*/
#include "codigo.h"
int main() {
   
    Fila atendimentoNormal;
    Fila atendimentoPreferencial;

    int contadorFichaNormal = 100;
    int contadorFichaPreferencial = 1000;
    int contaAtendimentos = 0;
    int ficha;

    inicializar(&atendimentoNormal);
    inicializar(&atendimentoPreferencial);

    int opcao;
    do{
        cout << "Menu de atendimento" << endl;
        cout << "1 - Retirar Ficha NORMAL" << endl;
        cout << "2 - Retirar Ficha PREFERENCIAL" << endl;
        cout << "3 - Atender" << endl;
        cout << "4 - Mostrar filas" << endl;
        cout << "5 - Sair" << endl;
        cout << "Opção: ";
        cin >> opcao;

        switch(opcao){
            case 1:
                cout<<"Ficha:"<<contadorFichaNormal<<endl;
                inserir(contadorFichaNormal,&atendimentoNormal);
                contadorFichaNormal++;
                // não deixar a fila passar de 500:
                if(contadorFichaNormal == 500){
                    contadorFichaNormal = 100;
                }
                break;
            case 2:
                cout<<"Ficha:"<<contadorFichaPreferencial<<endl;
                inserir(contadorFichaPreferencial,&atendimentoPreferencial);
                contadorFichaPreferencial++;
                // não deixar a fila passar de 1000:
                if(contadorFichaPreferencial == 1500){
                    contadorFichaPreferencial == 1000;
                }
                break;
            case 3:
                if (contaAtendimentos % 3 == 0) {
                    ficha = excluir(&atendimentoPreferencial);
                    if (ficha == -27) { // esse numero é retornado da funcao excluir qnd a lista esta vazia
                        ficha = excluir(&atendimentoNormal); // pulamos pra chamar o outro tipo de atendimento
                    }
                } else {
                    ficha = excluir(&atendimentoNormal);
                    if (ficha == -27) {
                        ficha = excluir(&atendimentoPreferencial);
                    }
                }
                if (ficha != -27) {
                    cout << "Atendimento a ficha: " << ficha << endl;
                } else {
                    cout << "Não há fichas!!" << endl;
                }
                contaAtendimentos++;               
                break;
            case 4:
                cout<<"Fila atendimento normal:"<<endl;
                exibir(atendimentoNormal);
                cout<<"Fila de atendimento Preferencial:"<<endl;
                exibir(atendimentoPreferencial);
                break;
            case 5:
                cout<<"Encerrando o sistema!"<<endl;
                break;
            default: cout << "Opção invalida" << endl;
        }
    } while (opcao != 5);
    
    return 1;
    
}
