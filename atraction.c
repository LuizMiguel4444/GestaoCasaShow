#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
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

void cred_atraction(void)
{
    char go;
    char *nome, *cache, *email, *num;
    nome = (char*) malloc(50*sizeof(char));
    cache = (char*) malloc(10*sizeof(char));
    email = (char*) malloc(50*sizeof(char));
    num = (char*) malloc(12*sizeof(char));
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

void read_atraction(void)
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
    atraction_id_check();
}

void upd_atraction(void)
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
    atraction_id_check();
}

void del_atraction(void)
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
    atraction_id_check();
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

void atraction_id_check(void)
{
    char *id;
    id = (char*) malloc(5*sizeof(char));
    int tam = 4;
    char go;
    do {
        printf("###              Informe o Id da atração (4 dígitos): ");
        scanf("%s", id);
        limpa_buffer();
    } while (!val_id(id, tam));
    if (strcmp(id, "1000") == 0) {
        print_dados_atraction();
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

void print_dados_atraction(void)
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
    printf("###              Nome da atração: Em desenvolvimento...                     ###\n");
    printf("###              Valor do cachê da atração: Em desenvolvimento...           ###\n");
    printf("###              Email de contato da atração: Em desenvolvimento...         ###\n");
    printf("###              Número de contato da atração: Em desenvolvimento...        ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    scanf("%c", &go);
}
