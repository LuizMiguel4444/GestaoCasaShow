#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "../show/show.h"
#include "../atraction/atraction.h"
#include "../client/client.h"
#include "../buy/buy.h"
#include "report.h"
#include "report_aux.h"
#include "../auxiliar/auxiliar.h"
#include "../util/util.h"



// Functions
char report_menu_fil(void)
{
    char resp[256];
    do {
        report_menu_screen_fil();
        scanf("%s", resp);
        limpa_buffer();
        if (!ehDigitoMax(resp[0], '3')  || !val_entrada(resp)) {
            screen_error_input();
            limpa_linha();
        }
    } while (!ehDigitoMax(resp[0], '3') || !val_entrada(resp));
    return resp[0];
}

char report_menu_fil_buy(void)
{
    char resp[256];
    do {
        report_menu_screen_fil_buy();
        scanf("%s", resp);
        limpa_buffer();
        if (!ehDigitoMax(resp[0], '1')  || !val_entrada(resp)) {
            screen_error_input();
            limpa_linha();
        }
    } while (!ehDigitoMax(resp[0], '1') || !val_entrada(resp));
    return resp[0];
}

void report_menu_screen_fil(void)
{
    system("clear || cls");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###            ===================================================          ###\n");
    printf("###            ==============   Gestão Casa Shows   ==============          ###\n");
    printf("###            ===================================================          ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###              = = = = = = = = =  Relatório  = = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    printf("###                              1. Listar Todos                            ###\n");
    printf("###                          2. Listar apenas Ativos                        ###\n");
    printf("###                         3. Listar apenas Inativos                       ###\n");
    printf("###                         0. Voltar ao menu anterior                      ###\n");
    printf("###                                                                         ###\n");
    printf("###                        Escolha a opção que deseja: ");
}

void report_menu_screen_fil_buy(void)
{
    system("clear || cls");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###            ===================================================          ###\n");
    printf("###            ==============   Gestão Casa Shows   ==============          ###\n");
    printf("###            ===================================================          ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###              = = = = = = = = =  Relatório  = = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    printf("###                              1. Listar Todos                            ###\n");
    printf("###                         0. Voltar ao menu anterior                      ###\n");
    printf("###                                                                         ###\n");
    printf("###                        Escolha a opção que deseja: ");
}

void modulo_report_atr(void)
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    char resp;
    do
    {
        resp = report_menu_fil();
        switch (resp)
        {
            case '1':
                report_atraction(resp);
                break;
            case '2':
                report_atraction(resp);
                break;
            case '3':
                report_atraction(resp);
                break;
            case '0':
                system("cls || clear");
                break;
        }
    } while (resp != '0');
}

void modulo_report_buy(void)
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    char resp;
    do
    {
        resp = report_menu_fil_buy();
        switch (resp)
        {
            case '1':
                report_buy(resp);
                break;
            case '0':
                system("cls || clear");
                break;
        }
    } while (resp != '0');
}

void modulo_report_cli(void)
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    char resp;
    do
    {
        resp = report_menu_fil();
        switch (resp)
        {
            case '1':
                report_client(resp);
                break;
            case '2':
                report_client(resp);
                break;
            case '3':
                report_client(resp);
                break;
            case '0':
                system("cls || clear");
                break;
        }
    } while (resp != '0');
}

void modulo_report_show(void)
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    char resp;
    do
    {
        resp = report_menu_fil();
        switch (resp)
        {
            case '1':
                report_show(resp);
                break;
            case '2':
                report_show(resp);
                break;
            case '3':
                report_show(resp);
                break;
            case '0':
                system("cls || clear");
                break;
        }
    } while (resp != '0');
}

char* contador_quantidade(char escolha, int quant_total, int quant_at, int quant_inat)
{
    char* quant_str;
    quant_str = (char*)malloc(8*sizeof(char));
    if (escolha == '1') {
        snprintf(quant_str, 8, "%d", quant_total);
    }
    else if (escolha == '2') {
        snprintf(quant_str, 8, "%d", quant_at);
    }
    else if (escolha == '3') {
        snprintf(quant_str, 8, "%d", quant_inat);
    }
    return quant_str;
}



// Screen Functions
void screen_report_atr(void)
{
    system("clear || cls");
    printf("#####################################################################################################\n");
    printf("###                                                                                               ###\n");
    printf("###                NOME                |                   EMAIL                   |     ID       ###\n");
    printf("###                                                                                               ###\n");
    printf("#####################################################################################################\n");
    printf("###                                                                                               ###\n");
}

void screen_report_buy(void)
{
    system("clear || cls");
    printf("##############################################################################################\n");
    printf("###                                                                                        ###\n");
    printf("###                  SHOW               |       CPF       |       VALOR       |    ID      ###\n");
    printf("###                                                                                        ###\n");
    printf("##############################################################################################\n");
    printf("###                                                                                        ###\n");
}

void screen_report_cli(void)
{
    system("clear || cls");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###                       NOME                      |          CPF          ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
}

void screen_report_show(void)
{
    system("clear || cls");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###                         ATRAÇÃO                      |       ID         ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
}

void screen_quant_total_atr(char* quant_str)
{
    printf("###                                                                                               ###\n");
    printf("#####################################################################################################\n");
    printf("###                                                                                               ###\n");
    printf("###                                 Quantidade Total de Atrações: %s###\n", centralizar_texto(quant_str, 32, -1));
    printf("###                                                                                               ###\n");
    printf("#####################################################################################################\n\n");
}

void screen_quant_e_valor_total_buy(char* quant_str, char* valor_str)
{
    printf("###                                                                                        ###\n");
    printf("##############################################################################################\n");
    printf("###                                                                                        ###\n");
    printf("###                             Quantidade Total de Vendas: %s###\n", centralizar_texto(quant_str, 31, -1));
    printf("###                                                                                        ###\n");
    printf("###                             Valor Total das Vendas: %s###\n", centralizar_texto(valor_str, 35, -1));
    printf("###                                                                                        ###\n");
    printf("##############################################################################################\n\n");
}

void screen_quant_total_cli(char* quant_str)
{
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###                     Quantidade Total de Clientes: %s###\n", centralizar_texto(quant_str, 22, -1));
    printf("###                                                                         ###\n");
    printf("###############################################################################\n\n");
}

void screen_quant_total_show(char* quant_str)
{
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###                        Quantidade Total de Shows: %s###\n", centralizar_texto(quant_str, 22, -1));
    printf("###                                                                         ###\n");
    printf("###############################################################################\n\n");
}

void print_if_in_filter_atr(Atraction* atr, char escolha)
{
    switch (escolha) {
        case '1':
            printf("### --------------------------------------------------------------------------------------------- ###\n");
            print_dados_atraction_rep(atr);
            printf("### --------------------------------------------------------------------------------------------- ###\n");
            break;
        case '2':
            if (atr -> status != 'x') {
                printf("### --------------------------------------------------------------------------------------------- ###\n");
                print_dados_atraction_rep(atr);
                printf("### --------------------------------------------------------------------------------------------- ###\n");
            }
            break;
        case '3':
            if (atr -> status == 'x') {
                printf("### --------------------------------------------------------------------------------------------- ###\n");
                print_dados_atraction_rep(atr);
                printf("### --------------------------------------------------------------------------------------------- ###\n");
            }
            break;
    }
}

void print_if_in_filter_buy(Buy* b, char escolha)
{
    switch (escolha) {
        case '1':
            printf("### -------------------------------------------------------------------------------------- ###\n");
            print_dados_buy_rep(b);
            printf("### -------------------------------------------------------------------------------------- ###\n");
            break;
        case '2':
            if (b -> status != 'x') {
                printf("### -------------------------------------------------------------------------------------- ###\n");
                print_dados_buy_rep(b);
                printf("### -------------------------------------------------------------------------------------- ###\n");
            }
            break;
        case '3':
            if (b -> status == 'x') {
                printf("### -------------------------------------------------------------------------------------- ###\n");
                print_dados_buy_rep(b);
                printf("### -------------------------------------------------------------------------------------- ###\n");
            }
            break;
    }
}

void print_if_in_filter_cli(Client* cli, char escolha)
{
    switch (escolha) {
        case '1':
            printf("### ----------------------------------------------------------------------- ###\n");
            print_dados_client_rep(cli);
            printf("### ----------------------------------------------------------------------- ###\n");
            break;
        case '2':
            if (cli -> status != 'x') {
                printf("### ----------------------------------------------------------------------- ###\n");
                print_dados_client_rep(cli);
                printf("### ----------------------------------------------------------------------- ###\n");
            }
            break;
        case '3':
            if (cli -> status == 'x') {
                printf("### ----------------------------------------------------------------------- ###\n");
                print_dados_client_rep(cli);
                printf("### ----------------------------------------------------------------------- ###\n");
            }
            break;
    }
}

void print_if_in_filter_show(Show* sh, char escolha)
{
    switch (escolha) {
        case '1':
            printf("### ----------------------------------------------------------------------- ###\n");
            print_dados_show_rep(sh);
            printf("### ----------------------------------------------------------------------- ###\n");
            break;
        case '2':
            if (sh -> status != 'x') {
                printf("### ----------------------------------------------------------------------- ###\n");
                print_dados_show_rep(sh);
                printf("### ----------------------------------------------------------------------- ###\n");
            }
            break;
        case '3':
            if (sh -> status == 'x') {
                printf("### ----------------------------------------------------------------------- ###\n");
                print_dados_show_rep(sh);
                printf("### ----------------------------------------------------------------------- ###\n");
            }
            break;
    }
}
