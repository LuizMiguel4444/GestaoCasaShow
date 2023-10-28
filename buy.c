#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "buy.h"
#include "inputs.h"
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
    buy_inputs(b);
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

void read_buy(Buy* b)
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

void buy_inputs(Buy* b)
{
    get_id(b -> id_show, "o show (4 dígitos)");
    get_id(b -> id_cli, "o cliente (4 dígitos)");
    get_quant(b -> quant, "ingressos");
    get_valor(b -> valor, "final");
    get_id(b -> id_ven, "a venda (4 dígitos)");
    b -> status = 'f';
}

void buy_id_check(Buy* b)
{
    get_id(b -> id_ven, "a venda (4 dígitos)");
    if (strcmp(b -> id_ven, "1000") == 0) {
        print_dados_buy(b);
    }
    else {
        printf("###                                                                         ###\n");
        printf("###              Id da venda não encontrado!                                ###\n");
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
        getchar();
    }
}

void print_dados_buy(Buy* b)
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
    printf("###              Id da venda: %s\n", b -> id_ven);
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    getchar();
}
