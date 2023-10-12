#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "client.h"
#include "util.h"

void modulo_client(void)
{
    Client* fulano;
    setlocale(LC_ALL, "Portuguese_Brazil");
    int resp;
    do
    {
        resp = client_menu();
        switch (resp)
        {
            case '1':
                fulano = cred_client();
                break;
            case '2':
                read_client(fulano);
                break;
            case '3':
                upd_client(fulano);
                break;
            case '4':
                del_client(fulano);
                break;
            case '0':
                system("cls || clear");
                break;
        }
    } while (resp != '0');
}

char client_menu(void)
{
    char resp[256];
    do {
        client_menu_screen();
        scanf("%s", resp);
        limpa_buffer();
    } while (!ehDigitoMax(resp[0], '4') || !val_entrada(resp));
    return resp[0];
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
    printf("###              0. Voltar ao menu principal                                ###\n");
    printf("###                                                                         ###\n");
    printf("###              Escolha a opção que deseja: ");
}

Client *cred_client(void)
{
    Client *cli;
    cli = (Client*) malloc(sizeof(Client) + 1);
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
    client_val(cli);
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    getchar();
    return cli;
}

void read_client(const Client* cli)
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
    printf("###              = = = = = = =  Pesquisar Cliente  = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    client_id_check(cli);
}

void upd_client(Client* cli)
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
    printf("###              = = = = = = = = Editar  Cliente = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    client_id_check(cli);
}

void del_client(Client* cli)
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
    printf("###              = = = = = = =  Excluir Cliente  = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    client_id_check(cli);
}

void client_val(Client* cli)
{
    int tam = 4;
    do {
        printf("###              Nome do cliente: ");
        scanf("%s", cli -> nome);
        limpa_buffer();
    } while (!valNome(cli  -> nome));
    do {
        printf("###              CPF do cliente (apenas números): ");
        scanf("%[0-9-.]", cli -> cpf);
        limpa_buffer();
    } while (!validarCPF(cli -> cpf));
    do {
        printf("###              Email do cliente: ");
        scanf("%[a-z0-9@.]", cli -> email);
        limpa_buffer();
    } while (!val_email(cli -> email));
    do {
        printf("###              Número do cliente: ");
        scanf("%s", cli -> num);
        limpa_buffer();
    } while (!validarFone(cli -> num));
    do {
        printf("###              Id do cliente (4 dígitos): ");
        scanf("%s", cli -> id);
        limpa_buffer();
    } while (!val_id(cli -> id, tam));
}

void client_id_check(const Client* cli)
{
    char *id;
    id = (char*) malloc(5*sizeof(char));
    int tam = 4;
    char go;
    do {
        printf("###              Informe o Id do cliente: ");
        scanf("%s", id);
        limpa_buffer();
    } while (!val_id(id, tam));
    if (strcmp(id, "0000") == 0) {
        print_dados_client(cli);
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

void print_dados_client(const Client* cli)
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
    printf("###              Informações do Id digitado (Id):                           ###\n");
    printf("###                                                                         ###\n");
    printf("###              Nome do cliente: %s\n", cli -> nome);
    printf("###              CPF do cliente: %s\n", cli -> cpf);
    printf("###              Email do cliente: %s\n", cli -> email);
    printf("###              Número do cliente: %s\n", cli -> num);
    printf("###              Id do cliente: %s\n", cli -> id);
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    getchar();
}
