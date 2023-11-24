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
        if (!ehDigitoMax(resp[0], '5')  || !val_entrada(resp)) {
            screen_error_input();
            limpa_linha();
        }
    } while (!ehDigitoMax(resp[0], '5') || !val_entrada(resp));
    return resp[0];
}

char report_menu_fil_buy(void)
{
    char resp[256];
    do {
        report_menu_screen_fil_buy();
        scanf("%s", resp);
        limpa_buffer();
        if (!ehDigitoMax(resp[0], '3')  || !val_entrada(resp)) {
            screen_error_input();
            limpa_linha();
        }
    } while (!ehDigitoMax(resp[0], '3') || !val_entrada(resp));
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
    printf("###                           4. Buscar entre Datas                         ###\n");
    printf("###                             5. Buscar por Nome                          ###\n");
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
    printf("###                             1. Listar Todos                             ###\n");
    printf("###                           2. Buscar entre Datas                         ###\n");
    printf("###                            3. Buscar por Nome                           ###\n");
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
            case '4':
                report_atraction(resp);
                break;
            case '5':
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
            case '2':
                report_buy(resp);
                break;
            case '3':
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
            case '4':
                report_client(resp);
                break;
            case '5':
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
            case '4':
                report_show(resp);
                break;
            case '5':
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
    else if (escolha == '4') {
        snprintf(quant_str, 8, "%d", quant_total);
    }
    else if (escolha == '5') {
        snprintf(quant_str, 8, "%d", quant_total);
    }
    return quant_str;
}

char* get_data_in(void)
{
    char* data_inicial;
    do {
        printf("\n\t\t\tDigite a data inicial (dd/mm/aaaa): ");
        data_inicial = input();
        limpa_buffer();
        if (!valDataBusc(data_inicial)) {
            screen_error_input();
            limpa_linha(); limpa_linha(); limpa_linha(); limpa_linha();
        }
    } while (!valDataBusc(data_inicial));
    return data_inicial;
}

char* get_data_fin(void)
{
    char* data_final;
    do {
        printf("\n\t\t\tDigite a data final (dd/mm/aaaa): ");
        data_final = input();
        limpa_buffer();
        if (!valDataBusc(data_final)) {
            screen_error_input();
            limpa_linha(); limpa_linha(); limpa_linha(); limpa_linha();
        }
    } while (!valDataBusc(data_final));
    return data_final;
}

char* get_nome_busc(void)
{
    char *nome;
    do
    {
        printf("\n\t\t\t   Digite o nome: ");
        nome = input();
        limpa_buffer();
        if (!valNome(nome))
        {
            screen_error_input_name();
            limpa_linha(); limpa_linha(); limpa_linha(); limpa_linha(); limpa_linha();
        }
    } while (!valNome(nome));
    return nome;
}

int aux_report_4_atr(Atraction* atr, FILE* fp, char escolha)
{
    int quant_atr_total = 0;
    char* data_in = get_data_in();
    char* data_fin = get_data_fin();
    system("clear || cls");
    screen_report_atr();
    while(fread(atr, sizeof(Atraction), 1, fp)) {
    int esta_dentro = compara_datas(atr->date, data_in, data_fin);
        if (esta_dentro == 1) {
            print_if_in_filter_atr(atr, escolha);
            quant_atr_total += 1;
        }
    }
    return quant_atr_total;
}

int aux_report_4_buy(Buy* b, FILE* fp, char escolha, float* valor_total)
{
    int quant_buy_total = 0;
    char* data_in = get_data_in();
    char* data_fin = get_data_fin();
    system("clear || cls");
    screen_report_buy();
    while(fread(b, sizeof(Buy), 1, fp)) {
    int esta_dentro = compara_datas(b->date, data_in, data_fin);
        if (esta_dentro == 1) {
            print_if_in_filter_buy(b, escolha);
            quant_buy_total += 1;
            float valor_compra = strtof(b->valor, NULL);
            *valor_total += valor_compra;
        }
    }
    return quant_buy_total;
}

int aux_report_4_cli(Client* cli, FILE* fp, char escolha)
{
    int quant_cli_total = 0;
    char* data_in = get_data_in();
    char* data_fin = get_data_fin();
    system("clear || cls");
    screen_report_cli();
    while(fread(cli, sizeof(Client), 1, fp)) {
    int esta_dentro = compara_datas(cli->date, data_in, data_fin);
        if (esta_dentro == 1) {
            print_if_in_filter_cli(cli, escolha);
            quant_cli_total += 1;
        }
    }
    return quant_cli_total;
}

int aux_report_4_show(Show* sh, FILE* fp, char escolha)
{
    int quant_show_total = 0;
    char* data_in = get_data_in();
    char* data_fin = get_data_fin();
    system("clear || cls");
    screen_report_show();
    while(fread(sh, sizeof(Show), 1, fp)) {
    int esta_dentro = compara_datas(sh->date, data_in, data_fin);
        if (esta_dentro == 1) {
            print_if_in_filter_show(sh, escolha);
            quant_show_total += 1;
        }
    }
    return quant_show_total;
}

int aux_report_5_atr(Atraction* atr, FILE* fp, char escolha)
{
    int quant_atr_total = 0;
    char* nome = get_nome_busc();
    system("clear || cls");
    screen_report_atr();
    while(fread(atr, sizeof(Atraction), 1, fp)) {
        if (strstr(atr->nome, nome) != NULL) {
            print_if_in_filter_atr(atr, escolha);
            quant_atr_total += 1;
        }
    }
    return quant_atr_total;
}

int aux_report_5_buy(Buy* b, FILE* fp, char escolha, float* valor_total)
{
    Client* cli;
    int quant_buy_total = 0;
    char* nome = get_nome_busc();
    system("clear || cls");
    screen_report_buy();
    while(fread(b, sizeof(Buy), 1, fp)) {
        cli = procura_client(b -> cpf_cli);
        if (strstr(cli->nome, nome) != NULL) {
            print_if_in_filter_buy(b, escolha);
            quant_buy_total += 1;
            float valor_compra = strtof(b->valor, NULL);
            *valor_total += valor_compra;
        }
    }
    return quant_buy_total;
}

int aux_report_5_cli(Client* cli, FILE* fp, char escolha)
{
    int quant_cli_total = 0;
    char* nome = get_nome_busc();
    system("clear || cls");
    screen_report_cli();
    while(fread(cli, sizeof(Client), 1, fp)) {
        if (strstr(cli->nome, nome) != NULL) {
            print_if_in_filter_cli(cli, escolha);
            quant_cli_total += 1;
        }
    }
    return quant_cli_total;
}

int aux_report_5_show(Show* sh, FILE* fp, char escolha)
{
    int quant_show_total = 0;
    char* nome = get_nome_busc();
    system("clear || cls");
    screen_report_show();
    while(fread(sh, sizeof(Show), 1, fp)) {
        if (strstr(sh->atraction, nome) != NULL) {
            print_if_in_filter_show(sh, escolha);
            quant_show_total += 1;
        }
    }
    return quant_show_total;
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
    printf("###                SHOW             |             NOME             |    VALOR    |   ID    ###\n");
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
        case '4':
            printf("### --------------------------------------------------------------------------------------------- ###\n");
            print_dados_atraction_rep(atr);
            printf("### --------------------------------------------------------------------------------------------- ###\n");
            break;
        case '5':
            printf("### --------------------------------------------------------------------------------------------- ###\n");
            print_dados_atraction_rep(atr);
            printf("### --------------------------------------------------------------------------------------------- ###\n");
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
            printf("### -------------------------------------------------------------------------------------- ###\n");
            print_dados_buy_rep(b);
            printf("### -------------------------------------------------------------------------------------- ###\n");
            break;
        case '3':
            printf("### -------------------------------------------------------------------------------------- ###\n");
            print_dados_buy_rep(b);
            printf("### -------------------------------------------------------------------------------------- ###\n");
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
