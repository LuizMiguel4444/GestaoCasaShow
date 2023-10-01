#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "atraction.h"
#include "util.h"

void modulo_atraction(void)
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    int resp;
    do
    {
        resp = atraction_menu();
        switch (resp)
        {
            case '1':
                cred_atraction();
                break;
            case '2':
                read_atraction();
                break;
            case '3':
                upd_atraction();
                break;
            case '4':
                del_atraction();
                break;
            case '0':
                system("cls || clear");
                break;
        }
    } while (resp != '0');
}

char atraction_menu(void)
{
    char resp;
    do {
        atraction_menu_screen();
        scanf("%c", &resp);
        limpa_buffer();
    } while (!ehDigitoMax(resp, '4'));
    return resp;
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

void cred_atraction(void)
{
    char go;
    char *nome, *cache, *email, *num;
    nome = (char*) malloc(50*sizeof(char));
    cache = (char*) malloc(10*sizeof(char));
    email = (char*) malloc(50*sizeof(char));
    num = (char*) malloc(20*sizeof(char));
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
    atraction_val(nome, cache, email, num);
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    scanf("%c", &go);
}
///////////////////////////////// MOSTRAR A FLAVIUS /////////////////////////////////
void read_atraction(void)
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
    printf("###              = = = = = = =  Pesquisar Atração  = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    do {
        printf("###              Informe o Id da atração (4 dígitos): ");
        scanf("%s", id);
        printf("<%d>", *id);
        limpa_buffer();
    } while (!val_id(id, tam));
    if (*id == 1000) {
        print_dados();
    }
    else {
        printf("###                                                                         ###\n");
        printf("###              Id da atração não encontrado!                              ###\n");
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
        scanf("%c", &go);
    }
}

void upd_atraction(void)
{
    char *id;
    id = (char*) malloc(10*sizeof(char));
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
    printf("###              = = = = = = = = Editar  Atração = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    do {
        printf("###              Informe o Id da atração (4 dígitos): ");
        scanf("%s", id);
        limpa_buffer();
    } while (!val_id(id, tam));
    if (*id == 1000) {
        print_dados();
    }
    else {
        printf("###                                                                         ###\n");
        printf("###              Id da atração não encontrado!                              ###\n");
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
        scanf("%c", &go);
    }
}

void del_atraction(void)
{
    char *id;
    id = (char*) malloc(10*sizeof(char));
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
    printf("###              = = = = = = =  Excluir Atração  = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    do {
        printf("###              Informe o Id da atração (4 dígitos): ");
        scanf("%s", id);
        limpa_buffer();
    } while (!val_id(id, tam));
    if (*id == 1000) {
        print_dados();
    }
    else {
        printf("###                                                                         ###\n");
        printf("###              Id da atração não encontrado!                              ###\n");
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
        scanf("%c", &go);
    }
}

void atraction_val(char *nome, char *cache, char *email, char *num)
{
    do {
        printf("###              Nome da atração: ");
        scanf("%s", nome);
        limpa_buffer();
    } while (!valNome(nome));
    do {
        printf("###              Valor do cachê: ");
        scanf("%s", cache);
        limpa_buffer();
    } while (!ehdinheiro(cache));
    do {
        printf("###              Email de contato: ");
        scanf("%[a-z0-9@.]", email);
        limpa_buffer();
    } while (!val_email(email));
    do{
        printf("###              Número de contato (com DDD): ");
        scanf("%s", num);
        limpa_buffer();
    } while (!validarFone(num));
}
