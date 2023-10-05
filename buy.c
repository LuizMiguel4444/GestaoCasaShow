#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "buy.h"
#include "util.h"

void modulo_buy(void)
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    int resp;
    do
    {
        resp = buy_menu();
        switch (resp)
        {
            case '1':
                cred_buy();
                break;
            case '2':
                read_buy();
                break;
            case '3':
                upd_buy();
                break;
            case '0':
                system("cls || clear");
                break;
        }
    } while (resp != '0');
}

char buy_menu(void)
{
    char resp[256];
    do {
        buy_menu_screen();
        scanf("%s", resp);
        limpa_buffer();
    } while (!ehDigitoMax(resp[0], '3') || !val_entrada(resp));
    return resp[0];
}

void buy_menu_screen(void)
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
        printf("###              = = = = = = = = = Menu Vendas = = = = = = = = =            ###\n");
        printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
        printf("###                                                                         ###\n");
        printf("###              1. Cadastrar uma nova venda                                ###\n");
        printf("###              2. Pesquisar os dados de uma venda                         ###\n");
        printf("###              3. Editar o cadastro de uma venda                          ###\n");
        printf("###              0. Voltar ao Menu Principal                                ###\n");
        printf("###                                                                         ###\n");
        printf("###              Escolha a opção que deseja: ");
}

void cred_buy(void)
{
    char go;
    char *id_show, *id_cli, *quant, *valor;
    id_show = (char*) malloc(5*sizeof(char));
    id_cli = (char*) malloc(5*sizeof(char));
    quant = (char*) malloc(5*sizeof(char));
    valor = (char*) malloc(8*sizeof(char));
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
    printf("###              = = = = = = = = Cadastrar Venda = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    buy_val(id_show, id_cli, quant, valor);
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###              Quant. de ingressos vendidos: x + %s\n", quant);
    printf("###              Quant. de ingressos que restam: x - %s\n", quant);
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    scanf("%c", &go);
}

void read_buy(void)
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
    printf("###              = = = = = = = = Pesquisar Venda = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    buy_id_check();
}

void upd_buy(void)
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
    printf("###              = = = = = = = =  Editar  Venda  = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    buy_id_check();
}

void buy_val(char *id_show, char *id_cli, char *quant, char *valor)
{
    int tam = 4;
    do {
        printf("###              Id do show (4 dígitos): ");
        scanf("%s", id_show);
        limpa_buffer();
    } while (!val_id(id_show, tam));
    do {
        printf("###              Id do cliente (4 dígitos): ");
        scanf("%s", id_cli);
        limpa_buffer();
    } while (!val_id(id_cli, tam));
    do {
        printf("###              Quant. de ingressos: ");
        scanf("%s", quant);
        limpa_buffer();
    } while (!ehdinheiro(quant));
    do {
        printf("###              Valor final: ");
        scanf("%s", valor);
        limpa_buffer();
    } while (!ehdinheiro(valor));
}

void buy_id_check(void)
{
    char *id;
    id = (char*) malloc(5*sizeof(char));
    int tam = 4;
    char go;
    do {
        printf("###              Informe o Id da venda (4 dígitos): ");
        scanf("%s", id);
        limpa_buffer();
    } while (!val_id(id, tam));
    if (strcmp(id, "1000") == 0) {
        print_dados_buy();
    }
    else {
        printf("###                                                                         ###\n");
        printf("###              Id da venda não encontrado!                                ###\n");
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
        scanf("%c", &go);
    }
}

void print_dados_buy(void)
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
    printf("###              Id do show: Em desenvolvimento...                          ###\n");
    printf("###              Id do cliente: Em desenvolvimento...                       ###\n");
    printf("###              Quant. de ingressos: Em desenvolvimento...                 ###\n");
    printf("###              Valor final: Em desenvolvimento...                         ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    scanf("%c", &go);
}
