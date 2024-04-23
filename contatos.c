#include <stdio.h>
#include <string.h>
#include "contatos.h"

ERROS criar(Contato contatos[], int *pos) {
    if (*pos >= TOTAL) {
        return MAX_contato; // Retorna erro se o limite de contatos foi alcançado.
    }

    printf("Digite o nome do contato: ");
    clearBuffer(); // Limpa o buffer do teclado antes de usar fgets.
    fgets(contatos[*pos].nome, sizeof(contatos[*pos].nome), stdin);
    contatos[*pos].nome[strcspn(contatos[*pos].nome, "\n")] = 0; // Remove a quebra de linha.

    printf("Digite o telefone do contato: ");
    fgets(contatos[*pos].telefone, sizeof(contatos[*pos].telefone), stdin);
    contatos[*pos].telefone[strcspn(contatos[*pos].telefone, "\n")] = 0; // Remove a quebra de linha.

    (*pos)++; // Incrementa a posição para o próximo contato.

    printf("Contato criado com sucesso.\n");

    return OK; // Retorna OK se o contato foi criado com sucesso.
}

ERROS deletar(Contato contatos[], int *pos) {
    // Implemente a lógica para deletar um contato
    return OK;
}

ERROS listar(Contato contatos[], int *pos) {
    // Implemente a lógica para listar os contatos
    return OK;
}

ERROS salvar(Contato contatos[], int *pos) {
    FILE *f = fopen("contatos.bin", "wb"); // abre o arquivo binário
    if (f == NULL) // caso ele estiver vazio
        return ABRIR; // retorna abrir

    int qtd = fwrite(contatos, sizeof(Contato), *pos, f); // escreve o contato adicionado
    if (qtd != *pos)
        return ESCREVER;

    if (fclose(f) != 0) // se o arquivo não estiver vazio, ele fecha
        return FECHAR;

    return OK;
}

ERROS carregar(Contato contatos[], int *pos) { 
    FILE *f = fopen("contatos.bin", "rb"); // abre o arquivo se ele não estiver vazio
    if (f == NULL)
        return ABRIR;

    int qtd = fread(contatos, sizeof(Contato), TOTAL, f); // lê o arquivo binário
    if (qtd < 0)
        return LER;

    *pos = qtd;

    if (fclose(f) != 0) // fecha o arquivo
        return FECHAR;

    return OK;
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
