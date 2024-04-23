#include <stdio.h>
#include "contatos.h"

int main() {
    funcao fs[] = {criar, deletar, listar, salvar, carregar};
    Contato contatos[TOTAL];
    int pos;
    ERROS erro = fs[4](contatos, &pos);
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

    int opcao;
    do {
        printf("\nMenu principal\n");
        printf("1 - Criar novo contato\n");
        printf("2 - Deletar contato\n");
        printf("3 - Listar contatos\n");
        printf("4 - Salvar contatos\n");
        printf("5 - Carregar contatos\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        opcao--;
        if (opcao < -1 || opcao > 4) {
            printf("Opcao invalida\n");
        } else if (opcao == 0) {
            erro = fs[opcao](contatos, &pos);
            if (erro == MAX_contato) {
                printf("Máximo de contatos alcançados\n");
            }
        } else if (opcao == 1) {
            erro = fs[opcao](contatos, &pos);
            if (erro == SEM_CONTATOS) {
                printf("Sem contatos para deletar\n");
            } else if (erro == NAO_ENCONTRADO) {
                printf("Contato não existe\n");
            }
        } else if (opcao == 2) {
            erro = fs[opcao](contatos, &pos);
            if (erro == NAO_ENCONTRADO) {
                printf("Sem contatos para listar\n");
            }
        } else if (opcao == 3 || opcao == 4) {
            fs[opcao](contatos, &pos);
        } else {
            printf("Sair...\n");
        }
    } while (opcao != -1);

    erro = fs[3](contatos, &pos);
    if (erro == ABRIR) {
        printf("Erro para abrir o arquivo ao salvar\n");
    } else if (erro == FECHAR) {
        printf("Erro para fechar o arquivo ao salvar\n");
    } else if (erro == ESCREVER) {
        printf("Erro ao escrever no arquivo ao salvar\n");
    }

    return 0;
}
