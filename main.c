#include <stdio.h> // Importa a biblioteca stdio.h para que possamos utilizar as funções de entrada e saída padrão de dados
#include "contatos.h" // Importa o arquivo tarefas.h para que possamos utilizar as funções declaradas nele

int main(){ // Função principal
  funcao funcoes[] = {adicionar, listar, deletar, listar, salvar, carregar}; // Definindo um array de funções que serão utilizadas no programa

  Agenda contatos[LIMITE_AGENDA]; // Declarando um array de contatos (com limite de 255), onde cada contato possui uma estrutura com as informações de nome, sobrenome, email e telefone
  int pos; // Declarando variável do tipo inteiro para armazenar a posição dos contatos no array
  
  ERRO erro = funcoes[4](contatos, &pos);
    if (erro == ABRIR) {
        printf("Erro ao carregar o arquivo para abrir.\n");
        pos = 0;
    } else if (erro == FECHAR) {
        printf("Erro ao carregar o arquivo para fechar.\n");
        pos = 0;
    } else if (erro == LER) {
        printf("Erro ao carregar o arquivo para ler.\n");
        pos = 0;
    }

    int opcao; // Declarando variável do tipo inteiro para a escolha da opção do menu
    do{ // Início do loop do menu de opções até que o usuário escolha a opção de sair
        printf("\nMenu principal\n"); // Imprimindo o menu de opções
        printf("1) Adicionar contatos\n"); // Imprimindo a primeira opção
        printf("2) Deletar contato\n"); // Imprimindo a segunda opção
        printf("3) Listar contatos\n"); // Imprimindo a terceira opção
        printf("4) Salvar contatos\n"); // Imprimindo a quarta opção
        printf("5) Carregar contatos\n"); // Imprimindo a quinta opção
        printf("0) Sair\n"); // Imprimindo a última opção
        printf("Escolha uma opção: "); // Pedindo ao usuário para escolher uma opção
        scanf("%d", &opcao); // Lendo a opção escolhida pelo usuário
        
        opcao--; // Decrementando a opção para acessar o índice do array de funções
        if (opcao < -1 || opcao > 4) { // Verificando se a opção escolhida é válida
            printf("Opção inválida\n"); // Informando para o usuário que a opção escolhida é inválida
        } else if (opcao == 0) {
            erro = funcoes[opcao](contatos, &pos);
            if (erro == MAX_CONTATOS) {
                printf("Máximo de contatos alcançados\n");
            }
        } else if (opcao == 1) {
            erro = funcoes[opcao](contatos, &pos);
            if (erro == SEM_CONTATOS) {
                printf("Sem contatos para deletar\n");
            } else if (erro == CONTATO_NAO_ENCONTRADO) {
                printf("Contato não existe\n");
            }
        } else if (opcao == 2) {
            erro = funcoes[opcao](contatos, &pos);
            if (erro == CONTATO_NAO_ENCONTRADO) {
                printf("Sem contatos para listar\n");
            }
        } else if (opcao == 3 || opcao == 4) {
            funcoes[opcao](contatos, &pos);
        } else {
            printf("Sair...\n"); // Informando ao usuário que o programa foi encerrado
        }
    } while (opcao != -1); // Condição para que o loop continue até que o usuário escolha a opção de sair, quando isso acontecer o loop se encerra

    erro = funcoes[3](contatos, &pos);
    if (erro == ABRIR) {
        printf("Erro para abrir o arquivo ao salvar\n");
    } else if (erro == FECHAR) {
        printf("Erro para fechar o arquivo ao salvar\n");
    } else if (erro == ESCREVER) {
        printf("Erro ao escrever no arquivo ao salvar\n");
    }

    return 0;
}