#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "report.h"
#include "../aux/aux.h"
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
    printf("###              = = = = = = = = Relatório Shows = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    printf("###              Cadastro realizado em **/**/**** às **/**.                 ###\n");
    printf("###                                                                         ###\n");
    printf("###              Dados do show:                                             ###\n");
    printf("###                                                                         ###\n");
    printf("###              Atrações do show: ***** ***** ********                     ###\n");
    printf("###              Data do show: **/**/****                                   ###\n");
    printf("###              Hora do show: **:**                                        ###\n");
    printf("###              Quant. de ingressos do show: ***                           ###\n");
    printf("###              Valor do ingresso do show: ***.**                          ###\n");
    printf("###              Id do show: ****                                           ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    getchar();
}

void report_atraction(void)
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
    printf("###              = = = = = = = Relatório  Atrações = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    printf("###              Cadastro realizado em **/**/**** às **/**.                 ###\n");
    printf("###                                                                         ###\n");
    printf("###              Dados da atração:                                          ###\n");
    printf("###                                                                         ###\n");
    printf("###              Nome da atração: ***** ***** ********                      ###\n");
    printf("###              Valor do cachê da atração: *****.**                        ###\n");
    printf("###              Email de contato da atração: ****@*****.***                ###\n");
    printf("###              Número de contato da atração: ***********                  ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    getchar();
}

void report_client(void)
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
    printf("###              = = = = = = = Relatório  Clientes = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    printf("###              Cadastro realizado em **/**/**** às **/**.                 ###\n");
    printf("###                                                                         ###\n");
    printf("###              Dados do cliente:                                          ###\n");
    printf("###                                                                         ###\n");
    printf("###              Nome do cliente: ***** ***** ********                      ###\n");
    printf("###              CPF do cliente: ***********                                ###\n");
    printf("###              Email do cliente: ****@*****.***                           ###\n");
    printf("###              Número do cliente: ***********                             ###\n");
    printf("###              Id do cliente: ****                                        ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    getchar();
}

void report_buy(void)
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
    printf("###              = = = = = = =  Relatório  Vendas  = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    printf("###              Cadastro realizado em **/**/**** às **/**.                 ###\n");
    printf("###                                                                         ###\n");
    printf("###              Dados da venda:                                            ###\n");
    printf("###                                                                         ###\n");
    printf("###              Id do show relacionado à venda: ****                       ###\n");
    printf("###              Id do cliente relacionado à venda: ****                    ###\n");
    printf("###              Quantidade de ingressos da venda: **                       ###\n");
    printf("###              Valor final da venda: ***.**                               ###\n");
    printf("###              Id da venda: ****                                          ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    getchar();
}
