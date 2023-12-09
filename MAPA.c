#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "locale.h"
#define ATEND 100

//Struct usada para o cadastro e armazenamento de dados dos usuários.
struct pessoa {
    char nome[100];
    char cpf[20];
    int setor;
};
//teste
int contador = 0;
struct pessoa cadastro[ATEND];

//Bloco para a chamada de funções.
void listagem (int i);
void solicitarAtendimento();
void listarAtendimentos();
void listarAtendimentosSetor();
void pausaLimpa();
void cadastroNomeCPF();
void menu();
void atendimento(int setor);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int opcao = 0;

    do
    {
        printf("===============================================\n");
        printf("Bem-vindo ao menu de atendimento!\n");
        printf("Por favor, selecione uma das opções\n");
        printf("===============================================\n");
        printf("1 - Solicitar Atendimento\n");
        printf("2 - Listar Atendimentos Registrados\n");
        printf("3 - Listar Atendimentos por Setor\n");
        printf("4 - Sair\n");
        fflush(stdin);
        scanf("%d", &opcao);
        system("cls");
        switch (opcao) {
            case 1:
                solicitarAtendimento();
                break;
            case 2:
                listarAtendimentos();
                break;
            case 3:
                listarAtendimentosSetor();
                break;
            case 4:
                break;
            default:
                printf("Insira uma operação válida.\n");
                pausaLimpa();
                break;
        }
    }
    while(opcao != 4);

    return 0;
}


void solicitarAtendimento()
{
    int opcao = 0;
    menu();
    printf("5 - Voltar\n");
    fflush(stdin);
    scanf("%d", &opcao);
    system("cls");
    switch (opcao) {
        case 1:
            atendimento(1);
            system("cls");
            break;
        case 2:
            atendimento(2);
            system("cls");
            break;
        case 3:
            atendimento(3);
            system("cls");
            break;
        case 4:
            atendimento(4);
            system("cls");
            break;
        case 5:
            system("cls");
            break;
        default:
            printf("Insira uma operação válida.\n");
            pausaLimpa();
            break;
    }
}

void listarAtendimentos()
{
    for (int i = 0; i < contador; ++i)
    {
        listagem (i);
    }
    pausaLimpa();
}

void listarAtendimentosSetor()
{
    int opcao = 0;
    menu();
    fflush(stdin);
    scanf("%d", &opcao);
    int existe = 0;
    system("cls");
    for (int i = 0; i < contador; ++i)
    {
        if (cadastro[i].setor == opcao)
        {
            existe  = 1;
            listagem (i);
        }
    }
    if (existe == 0) {
        printf("Nenhuma solicitação no setor.\n");
        pausaLimpa();
    }
    pausaLimpa();
}

void listagem(int i)
{
    //comparar tamanho da entrada do usuário para definir se é CPF ou CNPJ.
    unsigned long long tamanho = strlen(cadastro[i].cpf);
    if(tamanho <= 15)
        printf("Nome:\t%s\nCPF:\t%s\n", cadastro[i].nome, cadastro[i].cpf);
    else if (tamanho >15 && tamanho <=  19)
        printf("Nome:\t%s\nCNPJ:\t%s\n", cadastro[i].nome, cadastro[i].cpf);
    else
        printf("Número de caracteres inválido.\n");
    switch (cadastro[i].setor) {
        case 1:
            printf("Tipo Atendimento - 1 - Abertura de Conta\n");
            printf("===============================================\n");
            break;
        case 2:
            printf("Tipo Atendimento - 2 - Caixa\n");
            printf("===============================================\n");
            break;
        case 3:
            printf("Tipo Atendimento - 3 - Gerente Pessoa Física\n");
            printf("===============================================\n");
            break;
        case 4:
            printf("Tipo Atendimento - 4 - Gerente Pessoa Jurídica\n");
            printf("===============================================\n");
            break;
        default:
            break;
    }
}
void pausaLimpa()
{
    system("pause");
    system("cls");
}
void cadastroNomeCPF()
{
    while (getchar() != '\n');
    printf("Digite seu nome: \n");
    fflush(stdin);
    fgets(cadastro[contador].nome, sizeof(cadastro[contador].nome), stdin);
    cadastro[contador].nome[strcspn(cadastro[contador].nome, "\n")] = '\0';
    printf("Digite seu CPF/CNPJ(Com pontuação): \n");
    fflush(stdin);
    fgets(cadastro[contador].cpf, sizeof(cadastro[contador].cpf), stdin);
    cadastro[contador].cpf[strcspn(cadastro[contador].cpf, "\n")] = '\0';
}
void menu()
{
    printf("===============================================\n");
    printf("Bem-vindo ao menu de atendimento!\n");
    printf("Por favor, selecione uma das opções\n");
    printf("===============================================\n");
    printf("1 - Abertura de Conta\n");
    printf("2 - Caixa\n");
    printf("3 - Gerente Pessoa Física\n");
    printf("4 - Gerente Pessoa jurídica\n");
}
void atendimento(int setor)
{
    if (contador < ATEND)
    {
        cadastroNomeCPF();
        cadastro[contador].setor = setor;
        contador++;
        system("cls");
    }
}