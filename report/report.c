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
    screen_report_atr();
    int quant_atr_total = 0;
    int quant_atr_at = 0;
    int quant_atr_inat = 0;
    while(fread(atr, sizeof(Atraction), 1, fp)) {
        print_if_in_filter_atr(atr, escolha);
        quant_atr_total += 1;
        if (atr->status == 'c') {
            quant_atr_at += 1;
        }
        else if (atr->status == 'x') {
            quant_atr_inat += 1;
        }
    }
    char* quant_str = contador_quantidade(escolha, quant_atr_total, quant_atr_at, quant_atr_inat);
    screen_quant_total_atr(quant_str);
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
    screen_report_buy();
    int quant_vendas = 0;
    float valor_total = 0;
    while(fread(b, sizeof(Buy), 1, fp)) {
        print_if_in_filter_buy(b, escolha);
        quant_vendas += 1;
        float valor_compra = strtof(b->valor, NULL);
        valor_total += valor_compra;
    }
    char quant_str[8];
    snprintf(quant_str, sizeof(quant_str), "%d", quant_vendas);
    char valor_str[20];
    snprintf(valor_str, sizeof(valor_str), "%.2f", valor_total);
    screen_quant_e_valor_total_buy(quant_str, valor_str);
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
    screen_report_cli();
    int quant_cli_total = 0;
    int quant_cli_at = 0;
    int quant_cli_inat = 0;
    while(fread(cli, sizeof(Client), 1, fp)) {
        print_if_in_filter_cli(cli, escolha);
        quant_cli_total += 1;
        if (cli->status == 'c') {
            quant_cli_at += 1;
        }
        else if (cli->status == 'x') {
            quant_cli_inat += 1;
        }
    }
    char* quant_str = contador_quantidade(escolha, quant_cli_total, quant_cli_at, quant_cli_inat);
    screen_quant_total_cli(quant_str);
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
    screen_report_show();
    int quant_show_total = 0;
    int quant_show_at = 0;
    int quant_show_inat = 0;
    while(fread(sh, sizeof(Show), 1, fp)) {
        print_if_in_filter_show(sh, escolha);
        quant_show_total += 1;
        if (sh->status == 'c') {
            quant_show_at += 1;
        }
        else if (sh->status == 'x') {
            quant_show_inat += 1;
        }
    }
    char* quant_str = contador_quantidade(escolha, quant_show_total, quant_show_at, quant_show_inat);
    screen_quant_total_show(quant_str);
    fclose(fp);
    free(sh);
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    limpa_buffer();
}
