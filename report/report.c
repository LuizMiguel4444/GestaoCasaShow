#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "../show/show.h"
#include "../atraction/atraction.h"
#include "../client/client.h"
#include "../buy/buy.h"
#include "report.h"
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
                report_show();
                break;
            case '2':
                report_atraction();
                break;
            case '3':
                report_client();
                break;
            case '4':
                report_buy();
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
    printf("###                         1. Ver relatório de Shows                       ###\n");
    printf("###                        2. Ver relatório de Atrações                     ###\n");
    printf("###                        3. Ver relatório de Clientes                     ###\n");
    printf("###                         4. Ver relatório de Vendas                      ###\n");
    printf("###                         0. Voltar ao menu anterior                      ###\n");
    printf("###                                                                         ###\n");
    printf("###                       Escolha a opção que deseja: ");
}

void report_show(void)
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
    while(fread(sh, sizeof(Show), 1, fp)) {
        //if (sh -> status != 'x') {
        printf("###############################################################################\n");
        printf("###                                                                         ###\n");
        printf("###              Cadastro realizado em %02d/%02d/%d às %02d:%02d.                 ###\n", sh->day, sh->month, sh->year, sh->hour, sh->minute);
        printf("###                                                                         ###\n");
        print_dados_show_rep(sh);
        //}
    }
    fclose(fp);
    free(sh);
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    getchar();
}

void report_atraction(void)
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
    while(fread(atr, sizeof(Atraction), 1, fp)) {
        //if (atr -> status != 'x') {
        printf("###############################################################################\n");
        printf("###                                                                         ###\n");
        printf("###              Cadastro realizado em %02d/%02d/%d às %02d:%02d.                 ###\n", atr->day, atr->month, atr->year, atr->hour, atr->minute);
        printf("###                                                                         ###\n");
        print_dados_atraction_rep(atr);
        //}
    }
    fclose(fp);
    free(atr);
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    getchar();
}

void report_client(void)
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
    while(fread(cli, sizeof(Client), 1, fp)) {
        //if (cli -> status != 'x') {
        printf("###############################################################################\n");
        printf("###                                                                         ###\n");
        printf("###              Cadastro realizado em %02d/%02d/%d às %02d:%02d.                 ###\n", cli->day, cli->month, cli->year, cli->hour, cli->minute);
        printf("###                                                                         ###\n");
        print_dados_client_rep(cli);
        //}
    }
    fclose(fp);
    free(cli);
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    getchar();
}

void report_buy(void)
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
    while(fread(b, sizeof(Buy), 1, fp)) {
        //if (b -> status != 'x') {
        printf("###############################################################################\n");
        printf("###                                                                         ###\n");
        printf("###              Cadastro realizado em %02d/%02d/%d às %02d:%02d.                 ###\n", b->day, b->month, b->year, b->hour, b->minute);
        printf("###                                                                         ###\n");
        print_dados_buy_rep(b);
        //}
    }
    fclose(fp);
    free(b);
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    getchar();
}
