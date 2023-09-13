#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "ticket.h"
#include "util.h"

void modulo_ticket(void)
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    int resp;
    do
    {
        resp = ticket_menu();
        switch (resp)
        {
            case 1:
                cred_ticket();
                break;
            case 2:
                read_ticket();
                break;
            case 3:
                upd_ticket();
                break;
            case 4:
                del_ticket();
                break;
            case 0:
                system("cls || clear");
                break;
        }
    } while (resp != 0);
}

int ticket_menu(void)
{
    int resp;
        system("clear || cls");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                         ///\n");
        printf("///            ===================================================          ///\n");
        printf("///            =============   Gestão Casa Shows   ===============          ///\n");
        printf("///            ===================================================          ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                         ///\n");
        printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
        printf("///              = = = = = = = = Menu  Ingressos = = = = = = = =            ///\n");
        printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
        printf("///                                                                         ///\n");
        printf("///              1. Cadastrar um novo ingresso                              ///\n");
        printf("///              2. Pesquisar os dados de um ingresso                       ///\n");
        printf("///              3. Editar o cadastro de um ingresso                        ///\n");
        printf("///              4. Excluir um ingresso do sistema                          ///\n");
        printf("///              0. Voltar ao Menu Principal                                ///\n");
        printf("///                                                                         ///\n");
        printf("///              Escolha a opção que deseja: ");
        scanf("%d", &resp);
        getchar();
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        return resp;
}

void cred_ticket(void)
{
    char go;
    char* skip;
    skip = (char*) malloc(8*sizeof(char));
    system("clear || cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            =============   Gestão Casa Shows   ===============          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///              = = = = = = = Cadastrar Ingressso = = = = = = =            ///\n");
    printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("///              Informe o Id do ingresso: ");
    scanf("%[0-9]", skip);
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao Menu Principal... <<<");
    scanf("%c", &go);
    getchar();
}

void read_ticket(void)
{
    int go;
    char go1;
    system("clear || cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            =============   Gestão Casa Shows   ===============          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///              = = = = = = = Pesquisar  Ingresso = = = = = = =            ///\n");
    printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("///              Informe o Id do ingresso:");
    scanf("%d", &go);
    getchar();
    if (go != 1000)
    {
        print_dados();
    }
    else
    {
        printf("///                                                                         ///\n");
        printf("///              Id do ingresso não encontrado!                             ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao Menu Principal... <<<");
        scanf("%c", &go1);
    }
}

void upd_ticket(void)
{
    int go;
    char go1;
    system("clear || cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            =============   Gestão Casa Shows   ===============          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///              = = = = = = = = Editar Ingresso = = = = = = = =            ///\n");
    printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("///              Informe o Id do ingresso:");
    scanf("%d", &go);
    getchar();
    if (go != 1000)
    {
        print_dados();
    }
    else
    {
        printf("///                                                                         ///\n");
        printf("///              Id do ingresso não encontrado!                             ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao Menu Principal... <<<");
        scanf("%c", &go1);
    }
}

void del_ticket(void)
{
    int go;
    char go1;
    system("clear || cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            =============   Gestão Casa Shows   ===============          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///              = = = = = = = Excluir  Ingresso = = = = = = = =            ///\n");
    printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("///              Informe o Id do ingresso:");
    scanf("%d", &go);
    getchar();
    if (go != 1000)
    {
        print_dados();
    }
    else
    {
        printf("///                                                                         ///\n");
        printf("///              Id do ingresso não encontrado!                             ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao Menu Principal... <<<");
        scanf("%c", &go1);
    }
}
