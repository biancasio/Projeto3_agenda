#ifndef CONTATOS_H
#define CONTATOS_H

#define TOTAL 100

typedef struct {
    char nome[50];
    char telefone[15];
} Contato;

typedef enum {OK, MAX_contato, SEM_CONTATOS, NAO_ENCONTRADO, ABRIR, FECHAR, ESCREVER, LER} ERROS;

typedef ERROS (*funcao)(Contato[], int*);

ERROS criar(Contato contatos[], int *pos);
ERROS deletar(Contato contatos[], int *pos);
ERROS listar(Contato contatos[], int *pos);
ERROS salvar(Contato contatos[], int *pos);
ERROS carregar(Contato contatos[], int *pos);

void clearBuffer();

#endif
