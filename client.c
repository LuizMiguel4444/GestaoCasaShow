#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "client.h"
#include "util.h"

void modulo_client(void)
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    int resp;
    do
    {
        resp = client_menu();
        switch (resp)
        {
            case '1':
                cred_client();
                break;
            case '2':
                read_client();
                break;
            case '3':
                upd_client();
                break;
            case '4':
                del_client();
                break;
            case '0':
                system("cls || clear");
                break;
        }
    } while (resp != '0');
}

char client_menu(void)
{
    char resp;
    do {
        client_menu_screen();
        scanf("%c", &resp);
        limpa_buffer();
    } while (!ehDigitoMax(resp, '4'));
    return resp;
}

void client_menu_screen(void)
{
    system("clear || cls");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###            ===================================================          ###\n");
    printf("###            =============   Gestão Casa Shows   ===============          ###\n");
    printf("###            ===================================================          ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###              = = = = = = = =  Menu Clientes  = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    printf("###              1. Cadastrar um novo cliente                               ###\n");
    printf("###              2. Pesquisar os dados de um cliente                        ###\n");
    printf("###              3. Editar o cadastro de um cliente                         ###\n");
    printf("###              4. Excluir um cliente do sistema                           ###\n");
    printf("###              0. Voltar ao menu arincipal                                ###\n");
    printf("###                                                                         ###\n");
    printf("###              Escolha a opção que deseja: ");
}

void cred_client(void)
{
    char go;
    char *nome, *cpf, *email, *num, *id;
    nome = (char*) malloc(50*sizeof(char));
    cpf = (char*) malloc(20*sizeof(char));
    email = (char*) malloc(50*sizeof(char));
    num = (char*) malloc(20*sizeof(char));
    id = (char*) malloc(4*sizeof(char));
    system("clear || cls");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###            ===================================================          ###\n");
    printf("###            =============   Gestão Casa Shows   ===============          ###\n");
    printf("###            ===================================================          ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###              = = = = = = =  Cadastrar Cliente  = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    client_val(nome, cpf, email, num, id);
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    scanf("%c", &go);
}

void read_client(void)
{
    char *id;
    id = (char*) malloc(4*sizeof(char));
    int tam = 4;
    char go;
    system("clear || cls");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###            ===================================================          ###\n");
    printf("###            =============   Gestão Casa Shows   ===============          ###\n");
    printf("###            ===================================================          ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###              = = = = = = =  Pesquisar Cliente  = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    do {
        printf("###              Informe o Id do cliente: ");
        scanf("%s", id);
        limpa_buffer();
    } while (!val_id(id, tam));
    if (*id == 0) {
        print_dados_client();
    }
    else {
        printf("###                                                                         ###\n");
        printf("###              Id do cliente não encontrado!                              ###\n");
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
        scanf("%c", &go);
    }
}

void upd_client(void)
{
    char *id;
    id = (char*) malloc(4*sizeof(char));
    int tam = 4;
    char go;
    system("clear || cls");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###            ===================================================          ###\n");
    printf("###            =============   Gestão Casa Shows   ===============          ###\n");
    printf("###            ===================================================          ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###              = = = = = = = = Editar  Cliente = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    do {
        printf("###              Informe o Id do cliente: ");
        scanf("%s", id);
        limpa_buffer();
    } while (!val_id(id, tam));
    if (*id == 0) {
        print_dados_client();
    }
    else {
        printf("###                                                                         ###\n");
        printf("###              Id do cliente não encontrado!                              ###\n");
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
        scanf("%c", &go);
    }
}

void del_client(void)
{
    char *id;
    id = (char*) malloc(4*sizeof(char));
    int tam = 4;
    char go;
    system("clear || cls");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###            ===================================================          ###\n");
    printf("###            =============   Gestão Casa Shows   ===============          ###\n");
    printf("###            ===================================================          ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###              = = = = = = =  Excluir Cliente  = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    do {
        printf("###              Informe o Id do cliente: ");
        scanf("%s", id);
        limpa_buffer();
    } while (!val_id(id, tam));
    if (*id == 0) {
        print_dados_client();
    }
    else {
        printf("###                                                                         ###\n");
        printf("###              Id do cliente não encontrado!                              ###\n");
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
        scanf("%c", &go);
    }
}

void client_val(char *nome, char *cpf, char *email, char *num, char *id)
{
    int tam = 4;
    do {
        printf("###              Nome do cliente: ");
        scanf("%s", nome);
        limpa_buffer();
    } while (!valNome(nome));
    do {
        printf("###              CPF do cliente: ");
        scanf("%[0-9-.]", cpf);
        limpa_buffer();
    } while (!validarCPF(cpf));
    do {
        printf("###              Email do cliente: ");
        scanf("%[a-z0-9@.]", email);
        limpa_buffer();
    } while (!val_email(email));
    do {
        printf("###              Número do cliente: ");
        scanf("%s", num);
        limpa_buffer();
    } while (!validarFone(num));
    do {
        printf("###              Id do cliente (4 dígitos): ");
        scanf("%s", id);
        limpa_buffer();
    } while (!val_id(id, tam));
}

void print_dados_client(void)
{
    char go;
    system("clear || cls");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###            ===================================================          ###\n");
    printf("###            =============   Gestão Casa Shows   ===============          ###\n");
    printf("###            ===================================================          ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###              Informações do Id digitado (Id):                           ###\n");
    printf("###                                                                         ###\n");
    printf("###              Nome do cliente: Em desenvolvimento...                     ###\n");
    printf("###              CPF do cliente: Em desenvolvimento...                      ###\n");
    printf("###              Email do cliente: Em desenvolvimento...                    ###\n");
    printf("###              Número do cliente: Em desenvolvimento...                   ###\n");
    printf("###              Id do cliente: Em desenvolvimento...                       ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    scanf("%c", &go);
}
