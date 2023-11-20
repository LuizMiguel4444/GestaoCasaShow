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

void modulo_report(void)
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    int resp;
    do
    {
        resp = report_menu();
        switch (resp)
        {
            case '1':
                modulo_report_show();
                break;
            case '2':
                modulo_report_atr();
                break;
            case '3':
                modulo_report_cli();
                break;
            case '4':
                modulo_report_buy();
                break;
            case '0':
                system("cls || clear");
                break;
        }
    } while (resp != '0');
}

char report_menu(void)
{
    char resp[256];
    do {
        report_menu_screen();
        scanf("%s", resp);
        limpa_buffer();
        if (!ehDigitoMax(resp[0], '4')  || !val_entrada(resp)) {
            screen_error_input();
            limpa_linha();
        }
    } while (!ehDigitoMax(resp[0], '4') || !val_entrada(resp));
    return resp[0];
}

void report_menu_screen(void)
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
    printf("###              = = = = = = = = Menu  Relatório = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    printf("###                          1. Relatório de Shows                          ###\n");
    printf("###                         2. Relatório de Atrações                        ###\n");
    printf("###                         3. Relatório de Clientes                        ###\n");
    printf("###                          4. Relatório de Vendas                         ###\n");
    printf("###                        0. Voltar ao menu anterior                       ###\n");
    printf("###                                                                         ###\n");
    printf("###                        Escolha a opção que deseja: ");
}

void report_atraction(char escolha)
{
    FILE *fp;
    Atraction *atr;
    atr = (Atraction*) malloc(sizeof(Atraction));
    fp = fopen("atraction/atractions.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo!\n");
        printf("Não é possível continuar este programa...\n");
        exit(1);
    }
    system("clear || cls");
    printf("#####################################################################################################\n");
    printf("###                                                                                               ###\n");
    printf("###                NOME                |                   EMAIL                   |     ID       ###\n");
    printf("###                                                                                               ###\n");
    printf("#####################################################################################################\n");
    printf("###                                                                                               ###\n");
    while(fread(atr, sizeof(Atraction), 1, fp)) {
        print_if_in_filter_atr(atr, escolha);
    }
    printf("###                                                                                               ###\n");
    printf("#####################################################################################################\n\n");
    fclose(fp);
    free(atr);
    printf("\t\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    limpa_buffer();
}

void report_buy(char escolha)
{
    FILE *fp;
    Buy *b;
    b = (Buy*) malloc(sizeof(Buy));
    fp = fopen("buy/buys.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo!\n");
        printf("Não é possível continuar este programa...\n");
        exit(1);
    }
    system("clear || cls");
    printf("##############################################################################################\n");
    printf("###                                                                                        ###\n");
    printf("###                  SHOW               |       CPF       |       VALOR       |    ID      ###\n");
    printf("###                                                                                        ###\n");
    printf("##############################################################################################\n");
    printf("###                                                                                        ###\n");
    while(fread(b, sizeof(Buy), 1, fp)) {
        print_if_in_filter_buy(b, escolha);
    }
    printf("###                                                                                        ###\n");
    printf("##############################################################################################\n\n");
    fclose(fp);
    free(b);
    printf("\t\t     >>> Tecle ENTER para voltar ao menu anterior... <<<");
    limpa_buffer();
}

void report_client(char escolha)
{
    FILE *fp;
    Client *cli;
    cli = (Client*) malloc(sizeof(Client));
    fp = fopen("client/clients.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo!\n");
        printf("Não é possível continuar este programa...\n");
        exit(1);
    }
    system("clear || cls");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###                       NOME                      |          CPF          ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    while(fread(cli, sizeof(Client), 1, fp)) {
        print_if_in_filter_cli(cli, escolha);
    }
    printf("###                                                                         ###\n");
    printf("###############################################################################\n\n");
    fclose(fp);
    free(cli);
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    limpa_buffer();
}

void report_show(char escolha)
{
    FILE *fp;
    Show *sh;
    sh = (Show*) malloc(sizeof(Show));
    fp = fopen("show/shows.dat", "rb");
    if (fp == NULL) {
        printf("Erro na abertura do arquivo!\n");
        printf("Não é possível continuar este programa...\n");
        exit(1);
    }
    system("clear || cls");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###                         ATRAÇÃO                      |       ID         ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    while(fread(sh, sizeof(Show), 1, fp)) {
        print_if_in_filter_show(sh, escolha);
    }
    printf("###                                                                         ###\n");
    printf("###############################################################################\n\n");
    fclose(fp);
    free(sh);
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    limpa_buffer();
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
