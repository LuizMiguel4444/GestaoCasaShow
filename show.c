#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "show.h"
#include "util.h"

void modulo_show(void)
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    int resp;
    do
    {
        resp = show_menu();
        switch (resp)
        {
            case 1:
                cred_show();
                break;
            case 2:
                read_show();
                break;
            case 3:
                upd_show();
                break;
            case 4:
                del_show();
                break;
            case 0:
                system("cls || clear");
                break;
        }
    } while (resp != 0);
}

int show_menu(void)
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
        printf("###              = = = = = = = = = Menu  Shows = = = = = = = = =            ###\n");
        printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
        printf("###                                                                         ###\n");
        printf("###              1. Cadastrar um novo show                                  ###\n");
        printf("###              2. Pesquisar os dados de um show                           ###\n");
        printf("###              3. Editar o cadastro de um show                            ###\n");
        printf("###              4. Excluir um show do sistema                              ###\n");
        printf("###              0. Voltar ao Menu Principal                                ###\n");
        printf("###                                                                         ###\n");
        printf("###              Escolha a opção que deseja:");
        scanf("%d", &resp);
        getchar();
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
        return resp;
}

void cred_show(void)
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
    printf("###              = = = = = = = = Cadastrar  Show = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    printf("###              Atração: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", skip);
    getchar();
    printf("###              Data (dd/mm/aaaa): ");
    scanf("%[0-9/]", skip);
    getchar();
    printf("###              Local:");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", skip);
    getchar();
    printf("###              Quant. de ingressos (apenas numeros): ");
    scanf("%[0-9]", skip);
    getchar();
    printf("###              Id destinado aos ingressos (apenas numeros): ");
    scanf("%[0-9]", skip);
    getchar();
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    scanf("%c", &go);
}

void read_show(void)
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
    printf("###              = = = = = = = = Pesquisar  Show = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    printf("###              Informe o Id dos ingressos do show:");
    scanf("%d", &go);
    getchar();
    if (go == 1000)
    {
        print_dados();
    }
    else
    {
        printf("###                                                                         ###\n");
        printf("###              Id do show não encontrado!                                 ###\n");
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao Menu Principal... <<<");
        scanf("%c", &go1);
    }
}

void upd_show(void)
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
    printf("###              = = = = = = = =  Editar Show  = = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    printf("###              Informe o Id dos ingressos do show:");
    scanf("%d", &go);
    getchar();
    if (go == 1000)
    {
        print_dados();
    }
    else
    {
        printf("###                                                                         ###\n");
        printf("###              Id do show não encontrado!                                 ###\n");
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao Menu Principal... <<<");
        scanf("%c", &go1);
    }
}

void del_show(void)
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
    printf("###              = = = = = = = = Excluir  Show = = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    printf("###              Informe o Id dos ingressos do show:");
    scanf("%d", &go);
    getchar();
    if (go == 1000)
    {
        print_dados();
    }
    else
    {
        printf("###                                                                         ###\n");
        printf("###              Id do show não encontrado!                                 ###\n");
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao Menu Principal... <<<");
        scanf("%c", &go1);
    }
}