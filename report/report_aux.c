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

void report_menu_screen_fil(void)
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
        resp = report_menu_fil();
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



