#include "listase.h"

typedef struct evento{
    char data[11];
    char hora[6];
    char descricao[141];
    char prioridade[11];
} t_evento;

typedef struct agenda{
    t_lse *eventos;
    int tamanho;
}t_agenda;

typedef void (t_imprimir_agenda(void*));
typedef int (t_comparar_agenda(void*, void*));

t_evento* criar_evento(char data[], char hora[], char descricao[], char prioridade[]);
t_evento* ler_evento();
t_evento* ler_data();

t_agenda* criar_agenda(t_imprimir_agenda imprimir, t_comparar_agenda compara);

void agendar_evento(t_agenda* agenda, t_evento* carga);
int busca_data(t_agenda* agenda, char data[], char hora[]);
int quantifica_agenda(t_agenda* agenda);
int comparar_evento(void* evento1, void* evento2);
int comparar_data(void* evento1, void* evento2);
void proximo_evento(t_agenda* agenda);
void* altera_evento(t_agenda* agenda, t_evento* chave, t_evento *novo);
void* cancela_evento(t_agenda* agenda, t_evento* chave);
void conclui_evento(t_agenda* agenda);
// void imprime_evento(void* chave);



