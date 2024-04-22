#include <stdio.h> // Importa a biblioteca stdio.h para que possamos utilizar as funções de entrada e saída padrão de dados
#include "contatos.h" // Importa o arquivo tarefas.h para que possamos utilizar as funções declaradas nele

int main(){ // Função principal
  funcao funcoes[] = {adicionar, listar}; // Definindo um array de funções que serão utilizadas no programa

  Agenda contatos[LIMITE_AGENDA]; // Declarando um array de contatos (com limite de 255), onde cada contato possui uma estrutura com as informações de nome, sobrenome, email e telefone
  int pos; // Declarando variável do tipo inteiro para armazenar a posição dos contatos no array

    int opcao; // Declarando variável do tipo inteiro para a escolha da opção do menu
    do{ // Início do loop do menu de opções até que o usuário escolha a opção de sair
        printf("\nMenu principal\n"); // Imprimindo o menu de opções
        printf("1) Adicionar contatos\n"); // Imprimindo a primeira opção
        printf("2) Listar contatos\n"); // Imprimindo a segunda opção
        printf("0) Sair\n"); // Imprimindo a última opção
        printf("Escolha uma opção: "); // Pedindo ao usuário para escolher uma opção
        scanf("%d", &opcao); // Lendo a opção escolhida pelo usuário

        opcao--; // Decrementando a opção para acessar o índice do array de funções
        if(opcao > 5) // Verificando se a opção escolhida é válida
          printf("Opção inválida\n"); // Informando para o usuário que a opção escolhida é inválida
        else if(opcao >= 0) // Verificando se a opção escolhida é válida para acessar o índice do array de funções
          funcoes[opcao](contatos, &pos); // Chamando a função correspondente à opção escolhida com o array de contatos e a posição atual dos contatos
        else // Caso nenhuma das condições anteriores sejam verdadeiras, a opção escolhida é sair, portanto o programa se encerrará
          printf("Sair...\n"); // Informando ao usuário que o programa foi encerrado

    } while(opcao >= 0); // Condição para que o loop continue até que o usuário escolha a opção de sair, quando isso acontecer o loop se encerra
}