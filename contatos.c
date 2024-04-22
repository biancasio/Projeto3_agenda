#include <stdio.h> // Importa a biblioteca stdio.h para que possamos utilizar as funções de entrada e saída padrão de dados
#include <string.h> // Importa a biblioteca string.h para que possamos utilizar as funções de manipulação de strings
#include "contatos.h" // Importa o arquivo tarefas.h para que possamos utilizar as funções declaradas nele

ERRO adicionar(Agenda contatos[], int *pos){ // Função de adicionar contato, recebe um array de contatos e um ponteiro para a posição atual dos contatos
  if(*pos >= LIMITE_AGENDA) // Verificando erro de limite de contatos atingido
    return MAX_CONTATOS; // Retornando código de ultrapassou do limite de contatos

  clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado
  printf("\nDigite o nome do contato: "); // Pedindo para o usuário nos informar o nome do contato
  fgets(contatos[*pos].nome, 20, stdin); // Lendo o nome digitado pelo usuário
  clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

  printf("Digite o sobrenome do contato: "); // Pedindo para o usuário nos informar o sobrenome do contato
  fgets(contatos[*pos].sobrenome, 100, stdin); // Lendo o sobrenome digitado pelo usuário
  clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

  printf("Digite o email do contato: "); // Pedindo para o usuário nos informar o email do contato
  fgets(contatos[*pos].email, 100, stdin); // Lendo o email digitado pelo usuário
  clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

  printf("Digite o telefone do contato: "); // Pedindo para o usuário nos informar o telefone do contato
  scanf("%ld", &contatos[*pos].telefone); // Lendo o telefone digitado pelo usuário
  clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

  *pos = *pos + 1; // Incrementando a posição para o próximo contato

  return OK; // Retornando código de sucesso na execução
} // Fechando função de adicionar contato

ERRO listar(Agenda contatos[], int *pos){ // Função de listar contatos, recebe um array de contatos e um ponteiro para a posição atual dos contatos
  if(*pos == 0)  // Verificando erro de nenhum contato foi criado para ser possível listar
    return SEM_CONTATOS; // Retornando código de nenhum contato para listar

  for(int i=0; i<*pos; i++){ // Percorrendo o array de contatos para listar todos os contatos e cada uma de suas informações
    printf("\nPosição: %d\t", i+1); // Imprimindo a posição do contato
    printf("Nome: %s\t", contatos[i].nome); // Imprimindo o nome do contato
    printf("Sobrenome: %s\t", contatos[i].sobrenome); // Imprimindo o sobrenome do contato
    printf("Email: %s\t", contatos[i].email); // Imprimindo o email do contato
    printf("Telefone: %ld\n", contatos[i].telefone); // Imprimindo o telefone do contato
  }  // Fechando for para listar contatos

  return OK; // Retornando código de sucesso na execução
} // Fechando função de listar contatos


void clearBuffer(){ // Função de Limpar Buffer, para evitar o erro gerado ao tentar obter a entrada de informações do usuário
    int c;  // Declarando variável do tipo inteiro para armazenar o caractere lido do buffer
    while ((c = getchar()) != '\n' && c != EOF); // Loop para limpar o buffer do teclado, comparando o valor lido com o valor \n (New Line), e também comparando com o valor EOF (End Of File), para garantir que ele não continue tentando ler quando chegar ao final do arquivo
} // Fechando função de limpar buffer