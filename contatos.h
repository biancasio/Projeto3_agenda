// Definindo uma "variável" global e constante para a quantidade máxima de contatos que podem ser armazenados na agenda
#define LIMITE_AGENDA_PESSOAL 255 
#define LIMITE_AGENDA_TRABALHO 255 

typedef struct { // Definindo uma estrutura para armazenar as informações dentro de cada contato
    char nome[20]; // Declarando variável do tipo string com 20 caracteres para armazenar o nome do contato
    char sobrenome[100]; // Declarando variável do tipo string com 100 caracteres para armazenar o sobrenome do contato
    char email[100]; // Declarando variável do tipo string com 100 caracteres para armazenar o email do contato
    long  long int telefone; // Declarando variável do tipo inteiro longo para armazenar o telefone do contato
} Agenda; // Definindo o nome da estrutura como Agenda

typedef struct { // Definindo uma estrutura para armazenar as informações dentro de cada contato
    char nome2[20]; // Declarando variável do tipo string com 20 caracteres para armazenar o nome do contato
    char sobrenome2[100]; // Declarando variável do tipo string com 100 caracteres para armazenar o sobrenome do contato
    char email2[100]; // Declarando variável do tipo string com 100 caracteres para armazenar o email do contato
    long  long int telefone2; // Declarando variável do tipo inteiro longo para armazenar o telefone do contato
} Agenda2; // Definindo o nome da estrutura como Agenda

typedef enum {OK, MAX_CONTATOS, SEM_CONTATOS, CONTATO_NAO_ENCONTRADO, ABRIR, FECHAR, ESCREVER, LER, TELEFONE_DUPLICADO, EMAIL_INVALIDO} ERRO;
// Definindo uma enumeração de códigos de erro para ficar mais legível de identificar o que cada código significa

typedef ERRO (*funcao)(Agenda[], int*); // Definindo um tipo de função que recebe um array de contatos e um ponteiro para a posição atual dos contatos, e retorna um código de erro
typedef ERRO (*funcao2)(Agenda2[], int*);

ERRO adicionar(Agenda contatos[], int *pos); // Assinatura da função de adicionar contato
ERRO adicionar_trabalho(Agenda2 contatos2[], int *pos2); // Assinatura da função de adicionar contato
ERRO listar(Agenda contatos[], int *pos); // Assinatura da função de listar contatos
ERRO listar_trabalho(Agenda2 contatos2[], int *pos2); // Assinatura da função de listar contatos
ERRO deletar(Agenda contatos[], int *pos); // Assinatura da função de deletar contato
ERRO deletar_trabalho(Agenda2 contatos2[], int *pos2); // Assinatura da função de deletar contato
ERRO alterar(Agenda contatos[], int *pos); // Assinatura da função de alterar contato
ERRO alterar_trabalho(Agenda2 contatos2[], int *pos2); // Assinatura da função de alterar contato
ERRO salvar(Agenda contatos[], int *pos); // Assinatura da função de salvar contatos
ERRO salvar_trabalho(Agenda2 contatos2[], int *pos2); // Assinatura da função de salvar contatos
ERRO carregar(Agenda contatos[], int *pos); // Assinatura da função de carregar contatos
ERRO carregar_trabalho(Agenda2 contatos2[], int *pos2); // Assinatura da função de carregar contatos

int validarEmail(const char *email); 
int validarEmail(const char *email2); // Declaração da função de validação de email

void clearBuffer(); // Assinatura da função de limpar buffer