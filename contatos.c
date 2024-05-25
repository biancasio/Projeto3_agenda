#include <stdio.h> // Importa a biblioteca stdio.h para que possamos utilizar as funções de entrada e saída padrão de dados
#include <string.h> // Importa a biblioteca string.h para que possamos utilizar as funções de manipulação de strings
#include "contatos.h" // Importa o arquivo contatos.h para que possamos utilizar as funções declaradas nele


void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
// Função para validar o email
int validarEmail(const char *email) {
    const char *at = strchr(email, '@');
    if (at && strchr(at, '.')) {
        return 1; // Email válido
    }
    return 0; // Email inválido
}

ERRO adicionar(Agenda contatos[], int *pos) { // Função de adicionar contato, recebe um array de contatos e um ponteiro para a posição atual dos contatos
    if (*pos >= LIMITE_AGENDA_PESSOAL) // Verificando erro de limite de contatos atingido
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
    contatos[*pos].email[strcspn(contatos[*pos].email, "\n")] = 0; // Remover o newline
    clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

    // Validar o email
    if (!validarEmail(contatos[*pos].email)) {
        return EMAIL_INVALIDO; // Retornar erro se o email for inválido
    }

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
}

ERRO adicionar_trabalho(Agenda2 contatos2[], int *pos2) { // Função de adicionar contato, recebe um array de contatos e um ponteiro para a posição atual dos contatos
    if (*pos2 >= LIMITE_AGENDA_TRABALHO) // Verificando erro de limite de contatos atingido
        return MAX_CONTATOS; // Retornando código de ultrapassou do limite de contatos

    long long int telefone2;
    clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado
    printf("\nDigite o nome do contato: "); // Pedindo para o usuário nos informar o nome do contato
    fgets(contatos2[*pos2].nome2, 20, stdin); // Lendo o nome digitado pelo usuário
    clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

    printf("Digite o sobrenome do contato: "); // Pedindo para o usuário nos informar o sobrenome do contato
    fgets(contatos2[*pos2].sobrenome2, 100, stdin); // Lendo o sobrenome digitado pelo usuário
    clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

    printf("Digite o email do contato: "); // Pedindo para o usuário nos informar o email do contato
    fgets(contatos2[*pos2].email2, 100, stdin); // Lendo o email digitado pelo usuário
    contatos2[*pos2].email2[strcspn(contatos2[*pos2].email2, "\n")] = 0; // Remover o newline
    clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

    // Validar o email
    if (!validarEmail(contatos2[*pos2].email2)) {
        return EMAIL_INVALIDO; // Retornar erro se o email for inválido
    }

    printf("Digite o telefone do contato: "); // Pedindo para o usuário nos informar o telefone do contato
    scanf("%lld", &telefone2); // Lendo o telefone digitado pelo usuário
    clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

    // Verificar se o telefone já existe
    for (int i = 0; i < *pos2; i++) {
        if (contatos2[i].telefone2 == telefone2) {
            return TELEFONE_DUPLICADO;
        }
    }

    contatos2[*pos2].telefone2 = telefone2; 
    (*pos2)++; // Incrementando a posição para o próximo contato

    return OK; // Retornando código de sucesso na execução
}

ERRO listar(Agenda contatos[], int *pos) { // Função de listar contatos, recebe um array de contatos e um ponteiro para a posição atual dos contatos
    if (*pos == 0) // Verificando se não há contatos para serem listados
        return SEM_CONTATOS; // Retornando código de sem contatos

    for (int i = 0; i < *pos; i++) { // Loop para percorrer o array de contatos
        printf("\nContato %d:\n", i + 1); // Imprimindo o número do contato
        printf("Nome: %s", contatos[i].nome); // Imprimindo o nome do contato
        printf("Sobrenome: %s", contatos[i].sobrenome); // Imprimindo o sobrenome do contato
        printf("Email: %s\n", contatos[i].email); // Imprimindo o email do contato
        printf("Telefone: %lld\n", contatos[i].telefone); // Imprimindo o telefone do contato
    }

    return OK; // Retornando código de sucesso na execução
}
ERRO listar_trabalho(Agenda2 contatos2[], int *pos2) { // Função de listar contatos, recebe um array de contatos e um ponteiro para a posição atual dos contatos
    if (*pos2 == 0) // Verificando se não há contatos para serem listados
        return SEM_CONTATOS; // Retornando código de sem contatos

    for (int i = 0; i < *pos2; i++) { // Loop para percorrer o array de contatos
        printf("\nContato %d:\n", i + 1); // Imprimindo o número do contato
        printf("Nome: %s", contatos2[i].nome2); // Imprimindo o nome do contato
        printf("Sobrenome: %s", contatos2[i].sobrenome2); // Imprimindo o sobrenome do contato
        printf("Email: %s\n", contatos2[i].email2); // Imprimindo o email do contato
        printf("Telefone: %lld\n", contatos2[i].telefone2); // Imprimindo o telefone do contato
    }

    return OK; // Retornando código de sucesso na execução
}

ERRO deletar(Agenda contatos[], int *pos) { // Função de deletar contato, recebe um array de contatos e um ponteiro para a posição atual dos contatos
    if (*pos == 0) // Verificando se não há contatos para serem deletados
        return SEM_CONTATOS; // Retornando código de sem contatos

    long long int telefone;
    printf("Digite o telefone do contato que deseja deletar: "); // Pedindo para o usuário nos informar o telefone do contato a ser deletado
    scanf("%lld", &telefone); // Lendo o telefone digitado pelo usuário
    clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

    int indice = -1; // Inicializando variável para armazenar o índice do contato a ser deletado
    for (int i = 0; i < *pos; i++) { // Loop para percorrer o array de contatos
        if (contatos[i].telefone == telefone) { // Verificando se o telefone digitado pelo usuário é igual ao telefone do contato atual
            indice = i; // Armazenando o índice do contato a ser deletado
            break; // Saindo do loop
        }
    }

    if (indice == -1) // Verificando se o telefone digitado pelo usuário não foi encontrado
        return CONTATO_NAO_ENCONTRADO; // Retornando código de contato não encontrado

    for (int i = indice; i < *pos - 1; i++) { // Loop para percorrer o array de contatos a partir do índice do contato a ser deletado
        contatos[i] = contatos[i + 1]; // Sobrescrevendo o contato atual com o próximo contato
    }
    (*pos)--; // Decrementando a posição para o próximo contato

    return OK; // Retornando código de sucesso na execução
}

ERRO deletar_trabalho(Agenda2 contatos2[], int *pos2) { // Função de deletar contato, recebe um array de contatos e um ponteiro para a posição atual dos contatos
    if (*pos2 == 0) // Verificando se não há contatos para serem deletados
        return SEM_CONTATOS; // Retornando código de sem contatos

    long long int telefone2;
    printf("Digite o telefone do contato que deseja deletar: "); // Pedindo para o usuário nos informar o telefone do contato a ser deletado
    scanf("%lld", &telefone2); // Lendo o telefone digitado pelo usuário
    clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

    int indice = -1; // Inicializando variável para armazenar o índice do contato a ser deletado
    for (int i = 0; i < *pos2; i++) { // Loop para percorrer o array de contatos
        if (contatos2[i].telefone2 == telefone2) { // Verificando se o telefone digitado pelo usuário é igual ao telefone do contato atual
            indice = i; // Armazenando o índice do contato a ser deletado
            break; // Saindo do loop
        }
    }

    if (indice == -1) // Verificando se o telefone digitado pelo usuário não foi encontrado
        return CONTATO_NAO_ENCONTRADO; // Retornando código de contato não encontrado

    for (int i = indice; i < *pos2 - 1; i++) { // Loop para percorrer o array de contatos a partir do índice do contato a ser deletado
        contatos2[i] = contatos2[i + 1]; // Sobrescrevendo o contato atual com o próximo contato
    }
    (*pos2)--; // Decrementando a posição para o próximo contato

    return OK; // Retornando código de sucesso na execução
}

ERRO alterar(Agenda contatos[], int *pos) { // Função de alterar contato, recebe um array de contatos e um ponteiro para a posição atual dos contatos
    if (*pos == 0) // Verificando se não há contatos para serem alterados
        return SEM_CONTATOS; // Retornando código de sem contatos

    long long int telefone;
    printf("Digite o telefone do contato que deseja alterar: "); // Pedindo para o usuário nos informar o telefone do contato a ser alterado
    scanf("%lld", &telefone); // Lendo o telefone digitado pelo usuário
    clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

    int indice = -1; // Inicializando variável para armazenar o índice do contato a ser alterado
    for (int i = 0; i < *pos; i++) { // Loop para percorrer o array de contatos
        if (contatos[i].telefone == telefone) { // Verificando se o telefone digitado pelo usuário é igual ao telefone do contato atual
            indice = i; // Armazenando o índice do contato a ser alterado
            break; // Saindo do loop
        }
    }

    if (indice == -1) // Verificando se o telefone digitado pelo usuário não foi encontrado
        return CONTATO_NAO_ENCONTRADO; // Retornando código de contato não encontrado

    clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado
    printf("Digite o novo nome do contato: "); // Pedindo para o usuário nos informar o novo nome do contato
    fgets(contatos[indice].nome, 20, stdin); // Lendo o novo nome digitado pelo usuário
    clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

    printf("Digite o novo sobrenome do contato: "); // Pedindo para o usuário nos informar o novo sobrenome do contato
    fgets(contatos[indice].sobrenome, 100, stdin); // Lendo o novo sobrenome digitado pelo usuário
    clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

    printf("Digite o novo email do contato: "); // Pedindo para o usuário nos informar o novo email do contato
    fgets(contatos[indice].email, 100, stdin); // Lendo o novo email digitado pelo usuário
    contatos[indice].email[strcspn(contatos[indice].email, "\n")] = 0; // Remover o newline
    clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

    // Validar o email
    if (!validarEmail(contatos[indice].email)) {
        return EMAIL_INVALIDO; // Retornar erro se o email for inválido
    }

    printf("Digite o novo telefone do contato: "); // Pedindo para o usuário nos informar o novo telefone do contato
    scanf("%lld", &telefone); // Lendo o novo telefone digitado pelo usuário
    clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

    // Verificar se o telefone já existe
    for (int i = 0; i < *pos; i++) {
        if (i != indice && contatos[i].telefone == telefone) {
            return TELEFONE_DUPLICADO;
        }
    }

    contatos[indice].telefone = telefone;

    return OK; // Retornando código de sucesso na execução
}

ERRO alterar_trabalho(Agenda2 contatos2[], int *pos2) { // Função de alterar contato, recebe um array de contatos e um ponteiro para a posição atual dos contatos
    if (*pos2 == 0) // Verificando se não há contatos para serem alterados
        return SEM_CONTATOS; // Retornando código de sem contatos

    long long int telefone2;
    printf("Digite o telefone do contato que deseja alterar: "); // Pedindo para o usuário nos informar o telefone do contato a ser alterado
    scanf("%lld", &telefone2); // Lendo o telefone digitado pelo usuário
    clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

    int indice = -1; // Inicializando variável para armazenar o índice do contato a ser alterado
    for (int i = 0; i < *pos2; i++) { // Loop para percorrer o array de contatos
        if (contatos2[i].telefone2 == telefone2) { // Verificando se o telefone digitado pelo usuário é igual ao telefone do contato atual
            indice = i; // Armazenando o índice do contato a ser alterado
            break; // Saindo do loop
        }
    }

    if (indice == -1) // Verificando se o telefone digitado pelo usuário não foi encontrado
        return CONTATO_NAO_ENCONTRADO; // Retornando código de contato não encontrado

    clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado
    printf("Digite o novo nome do contato: "); // Pedindo para o usuário nos informar o novo nome do contato
    fgets(contatos2[indice].nome2, 20, stdin); // Lendo o novo nome digitado pelo usuário
    clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

    printf("Digite o novo sobrenome do contato: "); // Pedindo para o usuário nos informar o novo sobrenome do contato
    fgets(contatos2[indice].sobrenome2, 100, stdin); // Lendo o novo sobrenome digitado pelo usuário
    clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

    printf("Digite o novo email do contato: "); // Pedindo para o usuário nos informar o novo email do contato
    fgets(contatos2[indice].email2, 100, stdin); // Lendo o novo email digitado pelo usuário
    contatos2[indice].email2[strcspn(contatos2[indice].email2, "\n")] = 0; // Remover o newline
    clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

    // Validar o email
    if (!validarEmail(contatos2[indice].email2)) {
        return EMAIL_INVALIDO; // Retornar erro se o email for inválido
    }

    printf("Digite o novo telefone do contato: "); // Pedindo para o usuário nos informar o novo telefone do contato
    scanf("%lld", &telefone2); // Lendo o novo telefone digitado pelo usuário
    clearBuffer(); // Chamando a função clearBuffer para limpar o buffer do teclado

    // Verificar se o telefone já existe
    for (int i = 0; i < *pos2; i++) {
        if (i != indice && contatos2[i].telefone2 == telefone2) {
            return TELEFONE_DUPLICADO;
        }
    }

    contatos2[indice].telefone2 = telefone2;

    return OK; // Retornando código de sucesso na execução
}


ERRO salvar(Agenda contatos[], int *pos) { // Função de salvar contatos, recebe um array de contatos e um ponteiro para a posição atual dos contatos
    FILE *file = fopen("agenda.bin", "wb"); // Abrindo o arquivo "agenda.bin" para escrita binária
    if (file == NULL) // Verificando se houve erro ao abrir o arquivo
        return ABRIR; // Retornando código de erro ao abrir o arquivo

    if (fwrite(pos, sizeof(int), 1, file) != 1) { // Gravando a quantidade de contatos no arquivo
        fclose(file); // Fechando o arquivo
        return ESCREVER; // Retornando código de erro ao escrever no arquivo
    }

    if (fwrite(contatos, sizeof(Agenda), *pos, file) != (size_t)*pos) { // Gravando os contatos no arquivo
        fclose(file); // Fechando o arquivo
        return ESCREVER; // Retornando código de erro ao escrever no arquivo
    }

    if (fclose(file) != 0) // Verificando se houve erro ao fechar o arquivo
        return FECHAR; // Retornando código de erro ao fechar o arquivo

    return OK; // Retornando código de sucesso na execução
}

ERRO salvar_trabalho(Agenda2 contatos2[], int *pos2) { // Função de salvar contatos, recebe um array de contatos e um ponteiro para a posição atual dos contatos
    FILE *file = fopen("agenda2.bin", "wb"); // Abrindo o arquivo "agenda.bin" para escrita binária
    if (file == NULL) // Verificando se houve erro ao abrir o arquivo
        return ABRIR; // Retornando código de erro ao abrir o arquivo

    if (fwrite(pos2, sizeof(int), 1, file) != 1) { // Gravando a quantidade de contatos no arquivo
        fclose(file); // Fechando o arquivo
        return ESCREVER; // Retornando código de erro ao escrever no arquivo
    }

    if (fwrite(contatos2, sizeof(Agenda2), *pos2, file) != (size_t)*pos2) { // Gravando os contatos no arquivo
        fclose(file); // Fechando o arquivo
        return ESCREVER; // Retornando código de erro ao escrever no arquivo
    }

    if (fclose(file) != 0) // Verificando se houve erro ao fechar o arquivo
        return FECHAR; // Retornando código de erro ao fechar o arquivo

    return OK; // Retornando código de sucesso na execução
}

ERRO carregar(Agenda contatos[], int *pos) { // Função de carregar contatos, recebe um array de contatos e um ponteiro para a posição atual dos contatos
    FILE *file = fopen("agenda2.bin", "rb"); // Abrindo o arquivo "agenda.bin" para leitura binária
    if (file == NULL) // Verificando se houve erro ao abrir o arquivo
        return ABRIR; // Retornando código de erro ao abrir o arquivo

    if (fread(pos, sizeof(int), 1, file) != 1) { // Lendo a quantidade de contatos do arquivo
        fclose(file); // Fechando o arquivo
        return LER; // Retornando código de erro ao ler o arquivo
    }

    if (fread(contatos, sizeof(Agenda2), *pos, file) != (size_t)*pos) { // Lendo os contatos do arquivo
        fclose(file); // Fechando o arquivo
        return LER; // Retornando código de erro ao ler o arquivo
    }

    if (fclose(file) != 0) // Verificando se houve erro ao fechar o arquivo
        return FECHAR; // Retornando código de erro ao fechar o arquivo

    return OK; // Retornando código de sucesso na execução
}

ERRO carregar_trabalho(Agenda2 contatos2[], int *pos2) { // Função de carregar contatos, recebe um array de contatos e um ponteiro para a posição atual dos contatos
    FILE *file = fopen("agenda.bin", "rb"); // Abrindo o arquivo "agenda.bin" para leitura binária
    if (file == NULL) // Verificando se houve erro ao abrir o arquivo
        return ABRIR; // Retornando código de erro ao abrir o arquivo

    if (fread(pos2, sizeof(int), 1, file) != 1) { // Lendo a quantidade de contatos do arquivo
        fclose(file); // Fechando o arquivo
        return LER; // Retornando código de erro ao ler o arquivo
    }

    if (fread(contatos2, sizeof(Agenda2), *pos2, file) != (size_t)*pos2) { // Lendo os contatos do arquivo
        fclose(file); // Fechando o arquivo
        return LER; // Retornando código de erro ao ler o arquivo
    }

    if (fclose(file) != 0) // Verificando se houve erro ao fechar o arquivo
        return FECHAR; // Retornando código de erro ao fechar o arquivo

    return OK; // Retornando código de sucesso na execução
}
