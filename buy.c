#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "buy.h"
#include "util.h"

void modulo_buy(void)
{
    Buy* fulano;
    setlocale(LC_ALL, "Portuguese_Brazil");
    int resp;
    do
    {
        resp = buy_menu();
        switch (resp)
        {
            case '1':
                fulano = cred_buy();
                break;
            case '2':
                read_buy(fulano);
                break;
            case '3':
                upd_buy(fulano);
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

Buy *cred_buy(void)
{
    Buy *b;
    b = (Buy*) malloc(sizeof(Buy) + 1);
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
    buy_val(b);
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###              Quant. de ingressos vendidos: x + %s\n", b -> quant);
    printf("###              Quant. de ingressos que restam: x - %s\n", b -> quant);
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    getchar();
    return b;
}

void read_buy(const Buy* b)
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
    buy_id_check(b);
}

void upd_buy(Buy* b)
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
    buy_id_check(b);
}

void buy_val(Buy* b)
{
    int tam = 4;
    do {
        printf("###              Id do show (4 dígitos): ");
        scanf("%s", b -> id_show);
        limpa_buffer();
    } while (!val_id(b -> id_show, tam));
    do {
        printf("###              Id do cliente (4 dígitos): ");
        scanf("%s", b -> id_cli);
        limpa_buffer();
    } while (!val_id(b -> id_cli, tam));
    do {
        printf("###              Quant. de ingressos: ");
        scanf("%s", b -> quant);
        limpa_buffer();
    } while (!ehdinheiro(b -> quant));
    do {
        printf("###              Valor final: ");
        scanf("%s", b -> valor);
        limpa_buffer();
    } while (!ehdinheiro(b -> valor));
}

void buy_id_check(const Buy* b)
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
        print_dados_buy(b);
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

void print_dados_buy(const Buy* b)
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
    printf("###              Id do show: %s\n", b -> id_show);
    printf("###              Id do cliente: %s\n", b -> id_cli);
    printf("###              Quant. de ingressos: %s\n", b -> quant);
    printf("###              Valor final: %s\n", b -> valor);
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    getchar();
}
