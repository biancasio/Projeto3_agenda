#include <stdio.h> // Importa a biblioteca stdio.h para que possamos utilizar as funções de entrada e saída padrão de dados
#include "contatos.h" // Importa o arquivo tarefas.h para que possamos utilizar as funções declaradas nele

int main() { // Função principal
    funcao2 funcoes2[] = {adicionar_trabalho, deletar_trabalho, listar_trabalho, alterar_trabalho, salvar_trabalho, carregar_trabalho}; // Definindo um array de funções que serão utilizadas no programa
    funcao funcoes[] = {adicionar, deletar,listar, alterar,salvar,carregar}; // Definindo um array de funções que serão utilizadas no programa
    Agenda contatos[LIMITE_AGENDA_PESSOAL]; // Declarando um array de contatos (com limite de 255), onde cada contato possui uma estrutura com as informações de nome, sobrenome, email e telefone
    Agenda2 contatos2[LIMITE_AGENDA_TRABALHO]; // Declarando um array de contatos (com limite de 255), onde cada contato possui uma estrutura com as informações de nome, sobrenome, email e telefone
    int pos; // Declarando variável do tipo inteiro para armazenar a posição dos contatos no array
    int pos2; // Declarando variável do tipo inteiro para armazenar a posição dos contatos no array

    ERRO erro = funcoes[5](contatos, &pos); // funções que mostram os erros
    if (erro == ABRIR) {
        printf("Erro ao carregar o arquivo para abrir.\n"); // mensagem de erro
        pos = 0;
    } else if (erro == FECHAR) {
        printf("Erro ao carregar o arquivo para fechar.\n"); // mensagem de erro
        pos = 0;
    } else if (erro == LER) {
        printf("Erro ao carregar o arquivo para ler.\n"); // mensagem de erro
        pos = 0;
    }

    ERRO erro2 = funcoes2[5](contatos2, &pos2); // funções que mostram os erros
    if (erro2 == ABRIR) {
        printf("Erro ao carregar o arquivo para abrir.\n"); // mensagem de erro
        pos2 = 0;
    } else if (erro2 == FECHAR) {
        printf("Erro ao carregar o arquivo para fechar.\n"); // mensagem de erro
        pos2 = 0;
    } else if (erro2 == LER) {
        printf("Erro ao carregar o arquivo para ler.\n"); // mensagem de erro
        pos2 = 0;
    }
    int opcao; // Declarando variável do tipo inteiro para a escolha da opção do menu
    do { // Início do loop do menu de opções até que o usuário escolha a opção de sair
        printf("\nMenu principal\n"); // Imprimindo o menu de opções
        printf("1) Adicionar contatos\n"); // Imprimindo a primeira opção
        printf("2) Adicionar contatos trabalho\n");
        printf("3) Deletar contato \n");
        printf("4) Deletar contato trabalho \n"); // Imprimindo a segunda opção
        printf("5) Listar contatos\n"); 
        printf("6) Listar contatos trabalho\n");// Imprimindo a terceira opção
        printf("7) Alterar contato\n"); 
        printf("8) Alterar contato trabalho\n"); // Imprimindo a quarta opção
        printf("9) Salvar contatos\n"); 
        printf("10) Salvar contatos trabalho\n");// Imprimindo a quinta opção
        printf("11) Carregar contatos\n");
        printf("12) Carregar contatos trabalho\n"); // Imprimindo a sexta opção
        printf("0) Sair\n"); // Imprimindo a última opção
        printf("Escolha uma opção: "); // Pedindo ao usuário para escolher uma opção
        scanf("%d", &opcao); // Lendo a opção escolhida pelo usuário

        opcao--; // Decrementando a opção para acessar o índice do array de funções
        if (opcao < -1 || opcao > 11) { // Verificando se a opção escolhida é válida
            printf("Opção inválida\n"); // Informando para o usuário que a opção escolhida é inválida
        } else if (opcao == 0) { 
            erro = funcoes[opcao](contatos, &pos); 
            if (erro == MAX_CONTATOS) {
                printf("Máximo de contatos alcançados\n"); // se a posição for igual a máxima de contatos mostra erro
            } else if (erro == TELEFONE_DUPLICADO) {
                printf("Telefone já existente. Tente novamente com um número diferente.\n");
            } else if (erro == EMAIL_INVALIDO) {
                printf("Email inválido. Tente novamente com um email válido.\n");
            }
        } else if (opcao == 1) { 
            opcao--;
            erro2 = funcoes2[opcao](contatos2, &pos2); 
            if (erro2 == MAX_CONTATOS) {
                printf("Máximo de contatos alcançados\n"); // se a posição for igual a máxima de contatos mostra erro
            } else if (erro2 == TELEFONE_DUPLICADO) {
                printf("Telefone já existente. Tente novamente com um número diferente.\n");
            } else if (erro2 == EMAIL_INVALIDO) {
                printf("Email inválido. Tente novamente com um email válido.\n");
            }
        } else if (opcao == 2) {
            opcao--;
            erro = funcoes[opcao](contatos, &pos);
            if (erro == SEM_CONTATOS) { // se não possuir contatos para deletar mostrar 
                printf("Sem contatos para deletar\n"); // mensagem de erro
            } else if (erro == CONTATO_NAO_ENCONTRADO) { // se o contato não for encontrado
                printf("Contato não existe\n"); // mensagem de erro
            }
        } else if (opcao == 3) {
            opcao = opcao - 2;
            erro2 = funcoes2[opcao](contatos2, &pos2);
            if (erro2 == SEM_CONTATOS) { // se não possuir contatos para deletar mostrar 
                printf("Sem contatos para deletar\n"); // mensagem de erro
            } else if (erro2 == CONTATO_NAO_ENCONTRADO) { // se o contato não for encontrado
                printf("Contato não existe\n"); // mensagem de erro
            }
        } else if (opcao == 4) {
            opcao = opcao - 2;
            erro = funcoes[opcao](contatos, &pos);
            if (erro == SEM_CONTATOS) { // se não possuir contatos para listar mostrar 
                printf("Sem contatos para listar\n"); // mensagem de erro
            } else if (erro == CONTATO_NAO_ENCONTRADO) { // se o contato não for encontrado
                printf("Contato não existe\n"); // mensagem de erro
            }
        } else if (opcao == 5) {
            opcao = opcao - 3;
            erro2 = funcoes2[opcao](contatos2, &pos2);
            if (erro2 == SEM_CONTATOS) { // se não possuir contatos para listar mostrar 
                printf("Sem contatos para listar\n"); // mensagem de erro
            } else if (erro2 == CONTATO_NAO_ENCONTRADO) { // se o contato não for encontrado
                printf("Contato não existe\n"); // mensagem de erro
            }
        } else if (opcao == 6) {
            opcao = opcao - 3;
            erro = funcoes[opcao](contatos, &pos);
            if (erro == SEM_CONTATOS) { // se não possuir contatos para alterar mostrar 
                printf("Sem contatos para alterar\n"); // mensagem de erro
            } else if (erro == CONTATO_NAO_ENCONTRADO) { // se o contato não for encontrado
                printf("Contato não existe\n"); // mensagem de erro
            } else if (erro == TELEFONE_DUPLICADO) {
                printf("Telefone já existente. Tente novamente com um número diferente.\n");
            } else if (erro == EMAIL_INVALIDO) {
                printf("Email inválido. Tente novamente com um email válido.\n");
            }
        } else if (opcao == 7) {
            opcao = opcao - 4;
            erro2 = funcoes2[opcao](contatos2, &pos2);
            if (erro2 == SEM_CONTATOS) { // se não possuir contatos para alterar mostrar 
                printf("Sem contatos para alterar\n"); // mensagem de erro
            } else if (erro2 == CONTATO_NAO_ENCONTRADO) { // se o contato não for encontrado
                printf("Contato não existe\n"); // mensagem de erro
            } else if (erro2 == TELEFONE_DUPLICADO) {
                printf("Telefone já existente. Tente novamente com um número diferente.\n");
            } else if (erro2 == EMAIL_INVALIDO) {
                printf("Email inválido. Tente novamente com um email válido.\n");
            }
        } else if (opcao == 8) {
            opcao = opcao - 4;
            funcoes[opcao](contatos, &pos);
        }  else if (opcao == 10) {
            opcao = opcao - 5;
            funcoes[opcao](contatos, &pos);
        } else if (opcao == 9) {
            opcao = opcao - 5;
            funcoes2[opcao](contatos2, &pos2);
        } else if (opcao == 11) {
            opcao = opcao - 6;
            funcoes2[opcao](contatos2, &pos2);
        } else {
            printf("Sair...\n"); // Informando ao usuário que o programa foi encerrado
        }
    } while (opcao != -1); // Condição para que o loop continue até que o usuário escolha a opção de sair, quando isso acontecer o loop se encerra

    erro = funcoes[4](contatos, &pos);
    if (erro == ABRIR) { // erros possiveis do arquivo binário
        printf("Erro para abrir o arquivo ao salvar\n"); // mensagem de erro do arquivo
    } else if (erro == FECHAR) {
        printf("Erro para fechar o arquivo ao salvar\n"); // mensagem de erro do arquivo
    } else if (erro == ESCREVER) {
        printf("Erro ao escrever no arquivo ao salvar\n"); // mensagem de erro do arquivo
    }

    erro2 = funcoes2[4](contatos2, &pos2);
    if (erro2 == ABRIR) { // erros possiveis do arquivo binário
        printf("Erro para abrir o arquivo ao salvar\n"); // mensagem de erro do arquivo
    } else if (erro2 == FECHAR) {
        printf("Erro para fechar o arquivo ao salvar\n"); // mensagem de erro do arquivo
    } else if (erro2 == ESCREVER) {
        printf("Erro ao escrever no arquivo ao salvar\n"); // mensagem de erro do arquivo
    }

    return 0;
}
