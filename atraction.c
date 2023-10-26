#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "atraction.h"
#include "util.h"

void modulo_atraction(void)
{
    Atraction* fulano;
    setlocale(LC_ALL, "Portuguese_Brazil");
    int resp;
    do
    {
        resp = atraction_menu();
        switch (resp)
        {
            case '1':
                fulano = cred_atraction();
                break;
            case '2':
                read_atraction(fulano);
                break;
            case '3':
                upd_atraction(fulano);
                break;
            case '4':
                del_atraction(fulano);
                break;
            case '0':
                system("cls || clear");
                break;
        }
    } while (resp != '0');
}

char atraction_menu(void)
{
    char resp[256];
    do {
        atraction_menu_screen();
        scanf("%s", resp);
        limpa_buffer();
    } while (!ehDigitoMax(resp[0], '4') || !val_entrada(resp));
    return resp[0];
}

void atraction_menu_screen(void)
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
        printf("###              = = = = = = = =  Menu Atrações  = = = = = = = =            ###\n");
        printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
        printf("###                                                                         ###\n");
        printf("###              1. Cadastrar uma nova atração                              ###\n");
        printf("###              2. Pesquisar os dados de uma atração                       ###\n");
        printf("###              3. Editar o cadastro de uma atração                        ###\n");
        printf("###              4. Excluir uma atração do sistema                          ###\n");
        printf("###              0. Voltar ao Menu Principal                                ###\n");
        printf("###                                                                         ###\n");
        printf("###              Escolha a opção que deseja: ");
}

Atraction *cred_atraction(void)
{
    Atraction *atr;
    atr = (Atraction*) malloc(sizeof(Atraction) + 1);
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
    printf("###              = = = = = = =  Cadastrar Atração  = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    atraction_val(atr);
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    getchar();
    return atr;
}

void read_atraction(const Atraction* atr)
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
    printf("###              = = = = = = =  Pesquisar Atração  = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    atraction_id_check(atr);
}

void upd_atraction(Atraction* atr)
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
    printf("###              = = = = = = = = Editar  Atração = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    atraction_id_check(atr);
}

void del_atraction(Atraction* atr)
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
    printf("###              = = = = = = =  Excluir Atração  = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    atraction_id_check(atr);
}

void atraction_val(Atraction* atr)
{
    int tam = 4;
    do {
        printf("###              Nome da atração: ");
        scanf("%s", atr -> nome);
        limpa_buffer();
    } while (!valNome(atr -> nome));
    do {
        printf("###              Valor do cachê: ");
        scanf("%s", atr -> cache);
        limpa_buffer();
    } while (!ehdinheiro(atr -> cache));
    do {
        printf("###              Email de contato: ");
        scanf("%[a-z0-9@.]", atr -> email);
        limpa_buffer();
    } while (!val_email(atr -> email));
    do{
        printf("###              Número de contato (com DDD): ");
        scanf("%s", atr -> num);
        limpa_buffer();
    } while (!validarFone(atr -> num));
    do {
        printf("###              Id da atração (4 dígitos): ");
        scanf("%s", atr -> id);
        limpa_buffer();
    } while (!val_id(atr -> id, tam));
    atr -> status = 'c';
}

void atraction_id_check(const Atraction* atr)
{
    char *id;
    id = (char*) malloc(5*sizeof(char));
    int tam = 4;
    do {
        printf("###              Informe o Id da atração (4 dígitos): ");
        scanf("%s", id);
        limpa_buffer();
    } while (!val_id(id, tam));
    if (strcmp(id, "1000") == 0) {
        print_dados_atraction(atr);
    }
    else {
        printf("###                                                                         ###\n");
        printf("###              Id da atração não encontrado!                              ###\n");
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
        getchar();
    }
}

void print_dados_atraction(const Atraction* atr)
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
    printf("###              Nome da atração: %s\n", atr -> nome);
    printf("###              Valor do cachê da atração: %s\n", atr -> cache);
    printf("###              Email de contato da atração: %s\n", atr -> email);
    printf("###              Número de contato da atração: %s\n", atr -> num);
    printf("###              Id da atração: %s\n", atr -> id);
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    getchar();
}
