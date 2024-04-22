// Definindo uma "variável" global e constante para a quantidade máxima de contatos que podem ser armazenados na agenda
#define LIMITE_AGENDA 255 

typedef struct { // Definindo uma estrutura para armazenar as informações dentro de cada contato
    char nome[20]; // Declarando variável do tipo string com 20 caracteres para armazenar o nome do contato
    char sobrenome[100]; // Declarando variável do tipo string com 100 caracteres para armazenar o sobrenome do contato
    char email[100]; // Declarando variável do tipo string com 100 caracteres para armazenar o email do contato
    long int telefone; // Declarando variável do tipo inteiro longo para armazenar o telefone do contato
} Agenda; // Definindo o nome da estrutura como Agenda

typedef enum {OK, MAX_CONTATOS, SEM_CONTATOS, CONTATO_NAO_ENCONTRADO, ABRIR, FECHAR, ESCREVER, LER} ERRO;// Definindo uma enumeração de códigos de erro para ficar mais legível de identificar o que cada código significa

typedef ERRO (*funcao)(Agenda[], int*); // Definindo um tipo de função que recebe um array de contatos e um ponteiro para a posição atual dos contatos, e retorna um código de erro

ERRO adicionar(Agenda contatos[], int *pos); // Assinatura da função de adicionar contato
ERRO listar(Agenda contatos[], int *pos); // Assinatura da função de listar contatos

void clearBuffer(); // Assinatura da função de limpar buffer