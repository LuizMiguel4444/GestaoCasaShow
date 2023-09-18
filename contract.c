#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "contract.h"
#include "util.h"

void modulo_contract(void)
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    int resp;
    do
    {
        resp = contract_menu();
        switch (resp)
        {
            case 1:
                cred_contract();
                break;
            case 2:
                read_contract();
                break;
            case 3:
                upd_contract();
                break;
            case 4:
                del_contract();
                break;
            case 0:
                system("cls || clear");
                break;
        }
    } while (resp != 0);
}

int contract_menu(void)
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
        printf("###              = = = = = = = = Menu  Contratos = = = = = = = =            ###\n");
        printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
        printf("###                                                                         ###\n");
        printf("###              1. Cadastrar um novo contrato                              ###\n");
        printf("###              2. Pesquisar os dados de um contrato                       ###\n");
        printf("###              3. Editar o cadastro de um contrato                        ###\n");
        printf("###              4. Excluir um contrato do sistema                          ###\n");
        printf("###              0. Voltar ao Menu Principal                                ###\n");
        printf("###                                                                         ###\n");
        printf("###              Escolha a opção que deseja: ");
        scanf("%d", &resp);
        getchar();
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
        return resp;
}

void cred_contract(void)
{
    char go;
    char* skip;
    skip = (char*) malloc(8*sizeof(char));
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
    printf("###              = = = = = = = Cadastrar  Contrato = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    printf("###              Informe o Id do contrato: ");
    scanf("%[0-9]", skip);
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao Menu Principal... <<<");
    scanf("%c", &go);
    getchar();
}

void read_contract(void)
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
    printf("###              = = = = = = = Pesquisar  Contrato = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    printf("###              Informe o Id do contrato:");
    scanf("%d", &go);
    getchar();
    if (go == 1000)
    {
        print_dados();
    }
    else
    {
        printf("###                                                                         ###\n");
        printf("###              Id do contrato não encontrado!                             ###\n");
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao Menu Principal... <<<");
        scanf("%c", &go1);
    }
}

void upd_contract(void)
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
    printf("###              = = = = = = = = Editar Contrato = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    printf("###              Informe o Id do contrato:");
    scanf("%d", &go);
    getchar();
    if (go == 1000)
    {
        print_dados();
    }
    else
    {
        printf("###                                                                         ###\n");
        printf("###              Id do contrato não encontrado!                             ###\n");
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao Menu Principal... <<<");
        scanf("%c", &go1);
    }
}

void del_contract(void)
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
    printf("###              = = = = = = = Excluir  Contrsto = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    printf("###              Informe o Id do contrato:");
    scanf("%d", &go);
    getchar();
    if (go == 1000)
    {
        print_dados();
    }
    else
    {
        printf("###                                                                         ###\n");
        printf("###              Id do contrato não encontrado!                             ###\n");
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao Menu Principal... <<<");
        scanf("%c", &go1);
    }
}
