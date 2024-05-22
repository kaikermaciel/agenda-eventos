#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "agendaKaike_Maciel.h"
#include "listase.h"

void imprime_evento(void *e){
    t_evento *ee = e;
    printf("%s %s %s %s\n", ee->data, ee->hora, ee->descricao, ee->prioridade);
}

int main(){
    t_agenda* agenda;
    agenda = criar_agenda(imprime_evento, comparar_evento);
    int controlador = 0;
    while(controlador != -1){
        scanf("%i", &controlador);

        switch(controlador){
            case 1:
                t_evento* novoE = ler_evento();
                agendar_evento(agenda, novoE);
                break;
            
            case 2:
                printf("%i\n",quantifica_agenda(agenda));
                break;
            
            case 3:
                proximo_evento(agenda);
                break;

            case 4:
                t_evento* busca = ler_data();
                t_evento* novoev = ler_evento();
                altera_evento(agenda, novoev, busca);
                break;
            
            case 5:
                t_evento* chave = ler_evento();
                cancela_evento(agenda, chave);
                break;
            
            case 6:
                conclui_evento(agenda);
                break;
        }
    }
}




