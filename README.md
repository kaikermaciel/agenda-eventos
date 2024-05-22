# Projeto de Agenda

Este projeto é um sistema de gerenciamento de eventos de agenda. Ele permite criar, modificar e excluir eventos, bem como listar e concluir eventos agendados.

## Descrição

O projeto implementa uma agenda utilizando uma lista simplesmente encadeada (LSE). Os eventos são armazenados com informações de data, hora, descrição e prioridade. As principais funcionalidades incluem:

- Criação de eventos
- Agendamento de eventos
- Alteração e cancelamento de eventos
- Listagem do próximo evento
- Conclusão de eventos

## Estrutura do Repositório

O repositório contém os seguintes arquivos principais:

- `agendaKaike_Maciel.c`: Implementa as funções principais de gerenciamento de agenda.
- `agendaKaike_Maciel.h`: Define as estruturas e funções relacionadas aos eventos e à agenda.
- `listase.h`: Define a estrutura e funções da lista simplesmente encadeada.
- `listase.c`: Implementa as funções principais da lista simplesmente encadeada.
- `agenda.c`: Implementa a função main de todo projeto onde tem chamada de funções implementadas anteriormente.

## Requisitos

Para compilar e executar este projeto, você precisará de um compilador C, como `gcc`. Certifique-se de ter as bibliotecas padrão do C instaladas em seu sistema.

## Compilação e Execução

1. Clone este repositório para o seu ambiente local:

   ```bash
   git clone https://github.com/kaikermaciel/agenda-eventos
   cd agenda-eventos
  

2. Compile o código utilizando gcc:

  ```bash
  gcc -o agenda agenda.c agendaKaike_Maciel.c listase.c
  ```

3. Execute o programa:

  ```bash
  ./agenda
  ```
## Uso

As principais funções e como utilizá-las:

- `t_evento* criar_evento(char data[], char hora[], char dsr[], char prior[])`: Cria um novo evento com a data, hora, descrição e prioridade fornecidas.
- `t_evento* criar_data(char data[], char hora[])`: Cria um evento com data e hora fornecidas.
- `t_agenda* criar_agenda(t_imprimir_agenda imprimir, t_comparar_agenda compara)`: Cria uma nova agenda.
- `void agendar_evento(t_agenda* agenda, t_evento* evento)`: Agenda um novo evento na agenda fornecida.
- `int quantifica_agenda(t_agenda* agenda)`: Retorna a quantidade de eventos na agenda.
- `void proximo_evento(t_agenda* agenda)`: Imprime o próximo evento da agenda.
- `void* altera_evento(t_agenda* agenda, t_evento *chave, t_evento *novo)`: Altera um evento existente na agenda.
- `void* cancela_evento(t_agenda* agenda, t_evento* chave)`: Cancela um evento existente na agenda.
- `void conclui_evento(t_agenda* agenda)`: Conclui o próximo evento da agenda.
- `t_evento* ler_evento()`: Lê um evento da entrada padrão.
- `t_evento* ler_data()`: Lê uma data da entrada padrão.
- `int comparar_evento(void* evento1, void* evento2)`: Compara dois eventos com base na data, hora e prioridade.
- `int comparar_data(void* data1, void* data2)`: Compara duas datas com base na data e hora.

## Contribuição

Se você deseja contribuir com este projeto, siga os seguintes passos:

1. Fork este repositório.
2. Crie uma branch para a sua feature (`git checkout -b feature/nova-feature`).
3. Commit suas mudanças (`git commit -m 'Adiciona nova feature'`).
4. Push para a branch (`git push origin feature/nova-feature`).
5. Abra um Pull Request.
