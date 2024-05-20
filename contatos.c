#include <stdio.h> // Importa a biblioteca stdio.h para que possamos utilizar as funções de entrada e saída padrão de dados
#include <string.h> // Importa a biblioteca string.h para que possamos utilizar as funções de manipulação de strings
#include "contatos.h" // Importa o arquivo tarefas.h para que possamos utilizar as funções declaradas nele

ERRO adicionar(Agenda contatos[], int *pos){ // Função de adicionar contato, recebe um array de contatos e um ponteiro para a posição atual dos contatos
  if(*pos >= LIMITE_AGENDA) // Verificando erro de limite de contatos atingido
    return MAX_CONTATOS; // Retornando código de ultrapassou do limite de contatos

  long long int telefone;
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
  scanf("%lld", &telefone); // Lendo o telefone digitado pelo usuário
  clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado
  // Verificar se o telefone já existe
    for (int i = 0; i < *pos; i++) {
        if (contatos[i].telefone == telefone) {
            return TELEFONE_DUPLICADO;
        }
    }

  contatos[*pos].telefone = telefone; 
  (*pos)++; // Incrementando a posição para o próximo contato

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
    printf("Telefone: %lld\n", contatos[i].telefone); // Imprimindo o telefone do contato
  }  // Fechando for para listar contatos

  return OK; // Retornando código de sucesso na execução
} // Fechando função de listar contatos

ERRO deletar(Agenda contatos[], int *pos) { // Função de deletar contatos, recebe um array de contatos e um ponteiro para a posição atual dos contatos
  if (*pos == 0) // Verificando erro de nenhum contato foi criado para ser possível deletar
    return SEM_CONTATOS; // retorna erro

  int pos_delet;
  printf("Entre com a posição do contato a ser deletado: "); // digite a posição a ser deletada
  scanf("%d", &pos_delet);

  pos_delet--;

  if (pos_delet >= *pos) // se não existir contato 
    return CONTATO_NAO_ENCONTRADO; // retorna mensagem de erro

  for (int i = pos_delet; i < *pos - 1; i++) {  // Percorrendo o array de contatos para deletar os contatos 
    contatos[i] = contatos[i + 1]; 
  }

  (*pos)--; // Decrementa o contador de contatos após a exclusão


  return OK;
}

ERRO alterar(Agenda contatos[], int *pos) { // Função de alterar contatos, recebe um array de contatos e um ponteiro para a posição atual dos contatos
    if (*pos == 0) // Verificando erro de nenhum contato foi criado para ser possível alterar
      return SEM_CONTATOS; // retorna erro

    int pos_alterar; // Declarando variável do tipo inteiro para armazenar a posição do contato a ser alterado
    printf("Entre com a posição do contato a ser alterado: "); // Pedindo a posição a ser alterada
    scanf("%d", &pos_alterar); // Lendo a posição a ser alterada

    pos_alterar--; // Decrementando a posição para acessar o índice do array de contatos

    if (pos_alterar >= *pos) // Verificando se existe contato 
      return CONTATO_NAO_ENCONTRADO; // Retornando mensagem de erro

    clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado
    printf("\nDigite o nome do contato: "); // Pedindo para o usuário nos informar o nome do contato
    fgets(contatos[pos_alterar].nome, 20, stdin); // Lendo o nome digitado pelo usuário
    clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

    printf("Digite o sobrenome do contato: "); // Pedindo para o usuário nos informar o sobrenome do contato
    fgets(contatos[pos_alterar].sobrenome, 100, stdin); // Lendo o sobrenome digitado pelo usuário
    clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

    printf("Digite o email do contato: "); // Pedindo para o usuário nos informar o email do contato
    fgets(contatos[pos_alterar].email, 100, stdin); // Lendo o email digitado pelo usuário
    clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

    long long int novo_telefone; // Declarando variável do tipo inteiro longo para armazenar o telefone do contato

    printf("Digite o telefone do contato: "); // Pedindo para o usuário nos informar o telefone do contato
    scanf("%lld", &novo_telefone); // Lendo o telefone digitado pelo usuário
    clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclad
  
    for(int i = 0; i < *pos; i++){ // Percorrendo o array de contatos
          if (novo_telefone != contatos[i].telefone) 
          {
              contatos[pos_alterar].telefone = novo_telefone; // Alterando o telefone do contato
          }
          else {
              return TELEFONE_DUPLICADO; // Retornando mensagem de erro
          }
        }

    printf("Contato alterado com sucesso!\n"); // Imprimindo mensagem de sucesso
  
    return OK; // Retornando código de sucesso

}


ERRO salvar(Agenda contatos[], int *pos) {
    FILE *f = fopen("contatos.bin", "wb"); // abre o arquivo binário
    if (f == NULL) // caso ele estiver vazio
        return ABRIR; // retorna abrir

    int qtd = fwrite(contatos, sizeof(Agenda), *pos, f); // escreve o contato adicionado
    if (qtd != *pos)
        return ESCREVER;

    if (fclose(f) != 0) // se o arquivo não estiver vazio, ele fecha
        return FECHAR;

    return OK;
}

ERRO carregar(Agenda contatos[], int *pos) { 
    FILE *f = fopen("contatos.bin", "rb"); // abre o arquivo se ele não estiver vazio
    if (f == NULL)
        return ABRIR;

    int qtd = fread(contatos, sizeof(Agenda), LIMITE_AGENDA, f); // lê o arquivo binário
    if (qtd < 0)
        return LER;

    *pos = qtd;

    if (fclose(f) != 0) // fecha o arquivo
        return FECHAR;

    return OK;
}

void clearBuffer(){ // Função de Limpar Buffer, para evitar o erro gerado ao tentar obter a entrada de informações do usuário
    int c;  // Declarando variável do tipo inteiro para armazenar o caractere lido do buffer
    while ((c = getchar()) != '\n' && c != EOF); // Loop para limpar o buffer do teclado, comparando o valor lido com o valor \n (New Line), e também comparando com o valor EOF (End Of File), para garantir que ele não continue tentando ler quando chegar ao final do arquivo
} // Fechando função de limpar buffer