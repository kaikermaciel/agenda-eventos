#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listase.h"
#include "agendaKaike_Maciel.h"


t_evento* criar_evento(char data[], char hora[], char dsr[], char prior[]){
    t_evento* novo = malloc(sizeof(t_evento));
    strcpy(novo->data,data);
    strcpy(novo->hora,hora);
    strcpy(novo->descricao, dsr);
    strcpy(novo->prioridade,prior);
    return novo;
}

t_evento* criar_data(char data[], char hora[]){
    t_evento* dataNova = malloc(sizeof(t_evento));
    strcpy(dataNova->data, data);
    strcpy(dataNova->hora, hora);
    return dataNova;
}

t_agenda* criar_agenda(t_imprimir_agenda imprimir, t_comparar_agenda compara){//t_imprimir_agenda imprimir,t_comparar_agenda comparar){
    t_agenda *agenda = malloc(sizeof(t_agenda));
    agenda->eventos = criar_lse(imprimir,compara);
    agenda->tamanho = 0;
    return agenda;
}

void agendar_evento(t_agenda* agenda, t_evento* evento){
    inserir_conteudo_lse(agenda->eventos, (void*) evento);
    agenda->tamanho++;
}

int quantifica_agenda(t_agenda* agenda){
    return agenda->tamanho;
}

void proximo_evento(t_agenda* agenda){
    imprimir_proximo_lse(agenda->eventos);
}

void* altera_evento(t_agenda* agenda, t_evento *chave, t_evento *novo) {
    if (agenda) {
        t_evento *busca = busca_lista(agenda->eventos, (void*) chave);
        if (busca) {
            t_evento* novo_evento = criar_evento(novo->data, novo->hora, chave->descricao, chave->prioridade);
            cancela_evento(agenda, chave);
            agendar_evento(agenda, novo_evento);
            agenda->tamanho--;
            return novo_evento;
        }
    }
    return NULL;
}

void* cancela_evento(t_agenda* agenda, t_evento* chave){
    if(agenda){
        if(chave){
            t_evento* removido = remove_busca_lse(agenda->eventos, (void*) chave);
            if(removido){
                agenda->tamanho--;
            }
        }        
    }
    return NULL;
}




void conclui_evento(t_agenda* agenda){
    if(agenda){
        remover_lse(agenda->eventos);
    }
    agenda->tamanho--;
}


t_evento* ler_evento(){
    char entrada[650];
    char data[11];
    char hora[6];
    char descricao[141];
    char prioridade[11];
    scanf("%[^\n]", entrada);
    sscanf(entrada, "%s %s %s %s", data, hora, descricao, prioridade);
    criar_evento(data, hora, descricao, prioridade);
}

t_evento* ler_data(){
    char entrada[18];
    char data[11];
    char hora[6];
    scanf("%s %s", data, hora);
    //sscanf(entrada, "%s %s", data, hora);
    criar_data(data, hora);
}

int comparar_evento(void* evento1, void* evento2){
    t_evento* antigo = evento1;
    t_evento* novo = evento2;
    int dia1, mes1, ano1, hora1, minuto1, dia2, mes2, ano2, hora2, minuto2, prior1, prior2, dsr1,dsr2;
    sscanf(antigo->data, "%d/%d/%d", &dia1, &mes1, &ano1);
    sscanf(antigo->hora, "%d:%d", &hora1, &minuto1);
    sscanf(novo->data, "%d/%d/%d", &dia2, &mes2, &ano2);
    sscanf(novo->hora, "%d:%d", &hora2, &minuto2);
    
    if(strcmp(antigo->prioridade, "alta") == 0){ prior1 = 3; }
    else if(strcmp(antigo->prioridade, "media") == 0){ prior1 = 2; }
    else{ prior1 = 1; }

    if(strcmp(novo->prioridade, "alta") == 0){ prior2 = 3; }
    else if(strcmp(novo->prioridade, "media") == 0){ prior2 = 2; }
    else{ prior2 = 1; }

    if(ano1 - ano2 != 0){return ano1-ano2;}
    else if(mes2 - mes2 != 0){return mes2-mes2;}
    else if(dia1 - dia2 != 0){return dia1-dia2;}
    else if(hora1 - hora2 != 0){return hora1-hora2;}
    else if(minuto1 - minuto2 != 0){return minuto1-minuto2;}
    else if(prior1 - prior2 != 0){return prior2-prior1;}
    else{return 0;}
}

int comparar_data(void* data1, void* data2){
    t_evento* antigo = data1;
    t_evento* novo = data2;
    int dia1, mes1, ano1, hora1, minuto1, dia2, mes2, ano2, hora2, minuto2;

    sscanf(antigo->data, "%d/%d/%d", &dia1, &mes1, &ano1);
    sscanf(antigo->hora, "%d:%d", &hora1, &minuto1);
    sscanf(novo->data, "%d/%d/%d", &dia2, &mes2, &ano2);
    sscanf(novo->hora, "%d:%d", &hora2, &minuto2);   

    if(ano1 - ano2 != 0){return ano1-ano2;}
    else if(mes2 - mes2 != 0){return mes2-mes2;}
    else if(dia1 - dia2 != 0){return dia1-dia2;}
    else if(hora1 - hora2 != 0){return hora1-hora2;}
    else if(minuto1 - minuto2 != 0){return minuto1-minuto2;}
    else{return 0;}
}



