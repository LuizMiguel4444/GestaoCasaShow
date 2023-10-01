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
            case '1':
                cred_show();
                break;
            case '2':
                read_show();
                break;
            case '3':
                upd_show();
                break;
            case '4':
                del_show();
                break;
            case '0':
                system("cls || clear");
                break;
        }
    } while (resp != '0');
}

char show_menu(void)
{
    char resp;
    do {
        show_menu_screen();
        scanf("%c", &resp);
        limpa_buffer();
    } while (!ehDigitoMax(resp, '4'));
    return resp;
}

void show_menu_screen(void)
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
}

void cred_show(void)
{
    char go;
    char *atraction, *data, *local, *quant, *valor, *id;
    atraction = (char*) malloc(50*sizeof(char));
    data = (char*) malloc(8*sizeof(char));
    local = (char*) malloc(50*sizeof(char));
    quant = (char*) malloc(10*sizeof(char));
    valor = (char*) malloc(16*sizeof(char));
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
    printf("###              = = = = = = = = Cadastrar  Show = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    show_val(atraction, data, local, quant, valor, id);
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    scanf("%c", &go);
}

void read_show(void)
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
    printf("###              = = = = = = = = Pesquisar  Show = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    do {
        printf("###              Informe o Id do show (4 dígitos): ");
        scanf("%s", id);
        limpa_buffer();
    } while (!val_id(id, tam));
    if (*id == 1000) {
        print_dados();
    }
    else {
        printf("###                                                                         ###\n");
        printf("###              Id do show não encontrado!                                 ###\n");
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
        scanf("%c", &go);
    }
}

void upd_show(void)
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
    printf("###              = = = = = = = =  Editar Show  = = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    do {
        printf("###              Informe o Id do show (4 dígitos): ");
        scanf("%s", id);
        limpa_buffer();
    } while (!val_id(id, tam));
    if (*id == 1000) {
        print_dados();
    }
    else {
        printf("###                                                                         ###\n");
        printf("###              Id do show não encontrado!                                 ###\n");
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
        scanf("%c", &go);
    }
}

void del_show(void)
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
    printf("###              = = = = = = = = Excluir  Show = = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    do {
        printf("###              Informe o Id do show (4 dígitos): ");
        scanf("%s", id);
        limpa_buffer();
    } while (!val_id(id, tam));
    if (*id == 1000) {
        print_dados();
    }
    else {
        printf("###                                                                         ###\n");
        printf("###              Id do show não encontrado!                                 ###\n");
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
        scanf("%c", &go);
    }
}

void show_val(char *atraction, char *data, char *local, char *quant, char *valor, char *id)
{
    int tam = 4;
    do {
        printf("###              Atração: ");
        scanf("%s", atraction);
        limpa_buffer();
    } while (!valNome(atraction));
    do {
        printf("###              Data (dd/mm/aaaa): ");
        scanf("%s", data);
        limpa_buffer();
    } while (!valData(data));
    do {
        printf("###              Local: ");
        scanf("%s", local);
        limpa_buffer();
    } while (!valNome(local));
    do {
        printf("###              Quant. de ingressos (apenas numeros): ");
        scanf("%s", quant);
        limpa_buffer();
    } while (!ehdinheiro(quant));
    do {
        printf("###              Valor do ingresso: ");
        scanf("%s", valor);
        limpa_buffer();
    } while (!ehdinheiro(valor));
    do {
        printf("###              Id do show (4 dígitos): ");
        scanf("%s", id);
        limpa_buffer();
    } while (!val_id(id, tam));
}
