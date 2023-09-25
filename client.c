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
            case 1:
                cred_client();
                break;
            case 2:
                read_client();
                break;
            case 3:
                upd_client();
                break;
            case 4:
                del_client();
                break;
            case 0:
                system("cls || clear");
                break;
        }
    } while (resp != 0);
}

int client_menu(void)
{
    int resp;
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
        scanf("%d", &resp);
        getchar();
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
        return resp;
}

void cred_client(void)
{
    char go;
    char* skip;
    skip = (char*) malloc(30*sizeof(char));
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
    printf("###              Nome do cliente: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", skip);
    getchar();
    printf("###              CPF do cliente: ");
    scanf("%[0-9 /-.]", skip);
    getchar();
    printf("###              Email do cliente: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ@.]", skip);
    getchar();
    printf("###              Número do cliente: ");
    scanf("%[0-9/ -()]", skip);
    getchar();
    printf("###              Id do cliente: ");
    scanf("%[0-9]", skip);
    getchar();
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    scanf("%c", &go);
}

void read_client(void)
{
    int go;
    char go1;
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
    printf("###              Informe o Id do cliente: ");
    scanf("%d", &go);
    getchar();
    if (go == 0)
    {
        print_dados();
    }
    else
    {
        printf("###                                                                         ###\n");
        printf("###              Id do cliente não encontrado!                              ###\n");
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
        scanf("%c", &go1);
    }
}

void upd_client(void)
{
    int go;
    char go1;
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
    printf("###              Informe o Id do cliente: ");
    scanf("%d", &go);
    getchar();
    if (go == 0)
    {
        print_dados();
    }
    else
    {
        printf("###                                                                         ###\n");
        printf("###              Id do cliente não encontrado!                              ###\n");
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
        scanf("%c", &go1);
    }
}

void del_client(void)
{
    int go;
    char go1;
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
    printf("###              Informe o Id do cliente: ");
    scanf("%d", &go);
    getchar();
    if (go == 0)
    {
        print_dados();
    }
    else
    {
        printf("###                                                                         ###\n");
        printf("###              Id do cliente não encontrado!                              ###\n");
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
        scanf("%c", &go1);
    }
}
