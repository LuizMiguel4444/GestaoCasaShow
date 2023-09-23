#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "locals.h"
#include "util.h"

void modulo_locals(void)
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    int resp;
    do
    {
        resp = locals_menu();
        switch (resp)
        {
            case 1:
                cred_locals();
                break;
            case 2:
                read_locals();
                break;
            case 3:
                upd_locals();
                break;
            case 4:
                del_locals();
                break;
            case 0:
                system("cls || clear");
                break;
        }
    } while (resp != 0);
}

int locals_menu(void)
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
        printf("###              = = = = = = = = = menu aocais = = = = = = = = =            ###\n");
        printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
        printf("###                                                                         ###\n");
        printf("###              1. Cadastrar um novo local                                 ###\n");
        printf("###              2. Pesquisar os dados de um local                          ###\n");
        printf("###              3. Editar o cadastro de um local                           ###\n");
        printf("###              4. Excluir um local do sistema                             ###\n");
        printf("###              0. Voltar ao menu arincipal                                ###\n");
        printf("###                                                                         ###\n");
        printf("###              Escolha a opção que deseja: ");
        scanf("%d", &resp);
        getchar();
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
        return resp;
}

void cred_locals(void)
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
    printf("###              = = = = = = = Cadastrar  local    = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    printf("###              Nome do local: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", skip);
    getchar();
    printf("###              Email da gestão do local: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ@.]", skip);
    getchar();
    printf("###              Número de contato da gestão do local: ");
    scanf("%[0-9/ -()]", skip);
    getchar();
    printf("###              Valor da locação do local: ");
    scanf("%[0-9/.,]", skip);
    getchar();
    printf("###              Id do local: ");
    scanf("%[0-9]", skip);
    getchar();
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    scanf("%c", &go);
}

void read_locals(void)
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
    printf("###              = = = = = = = = Pesquisar local = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    printf("###              Informe o Id do local: ");
    scanf("%d", &go);
    getchar();
    if (go == 1000)
    {
        print_dados();
    }
    else
    {
        printf("###                                                                         ###\n");
        printf("###              Id do local não encontrado!                                ###\n");
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
        scanf("%c", &go1);
    }
}

void upd_locals(void)
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
    printf("###              = = = = = = = =  Editar  local  = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    printf("###              Informe o Id do local: ");
    scanf("%d", &go);
    getchar();
    if (go == 1000)
    {
        print_dados();
    }
    else
    {
        printf("###                                                                         ###\n");
        printf("###              Id do local não encontrado!                                ###\n");
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
        scanf("%c", &go1);
    }
}

void del_locals(void)
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
    printf("###              = = = = = = = = Excluir Local = = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    printf("###              Informe o Id do local: ");
    scanf("%d", &go);
    getchar();
    if (go == 1000)
    {
        print_dados();
    }
    else
    {
        printf("###                                                                         ###\n");
        printf("###              Id do local não encontrado!                                ###\n");
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
        scanf("%c", &go1);
    }
}
