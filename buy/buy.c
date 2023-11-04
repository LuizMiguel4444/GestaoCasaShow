#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include "../show/show.h"
#include "../atraction/atraction.h"
#include "../client/client.h"
#include "buy.h"
#include "../report/report.h"
#include "../aux/aux.h"
#include "../util/util.h"

void modulo_buy(void)
{
    Buy* venda;
    setlocale(LC_ALL, "Portuguese_Brazil");
    int resp;
    do
    {
        resp = buy_menu();
        switch (resp)
        {
            case '1':
                venda = cred_buy();
                gravar_buy(venda);
                break;
            case '2':
                pesquisa_buy();
                break;
            case '3':
                update_buy();
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
        if (!ehDigitoMax(resp[0], '3')  || !val_entrada(resp)) {
            screen_error_input();
            limpa_linha();
        }
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
    Show *sh;
    Client *cli;
    b = (Buy*) malloc(sizeof(Buy) + 1);
    sh = (Show*) malloc(sizeof(Show) + 1);
    cli = (Client*) malloc(sizeof(Client) + 1);
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
    buy_inputs(b, sh, cli);
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    getchar();
    return b;
}

Buy *cred_buy_sem_id(void)
{
    Buy *b;
    b = (Buy *)malloc(sizeof(Buy) + 1);
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
    buy_inputs_sem_id(b);
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    getchar();
    return b;
}

char *screen_busc_buy(void)
{
    char *id;
    id = (char *)malloc(5 * sizeof(char));
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
    do {
        printf("###              Informe o Id da venda (4 dígitos): ");
        scanf("%s", id);
        limpa_buffer();
        if (!val_id(id, 4)) {
            screen_error_input();
            limpa_linha(); limpa_linha(); limpa_linha();
        }
    } while (!val_id(id, 4));
    printf("###                                                                         ###\n");
    return id;
}

char *screen_upd_buy(void)
{
    char *id;
    id = (char *)malloc(5 * sizeof(char));
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
    do {
        printf("###              Informe o Id da venda (4 dígitos): ");
        scanf("%s", id);
        limpa_buffer();
        if (!val_id(id, 4)) {
            screen_error_input();
            limpa_linha(); limpa_linha(); limpa_linha();
        }
    } while (!val_id(id, 4));
    printf("###                                                                         ###\n");
    return id;
}

void buy_inputs(Buy* b, Show* sh, Client* cli)
{
    do {
        get_id(b->id_show, "o show (4 dígitos)");
        if (procura_id_show(b->id_show)) {
            screen_error_input_n_exist("Id");
            limpa_linha(); limpa_linha(); limpa_linha();
        }
    } while (procura_id_show(b->id_show));
    do {
        get_cpf(b->cpf_cli);
        if (procura_cpf_client(b->cpf_cli)) {
            screen_error_input_n_exist("CPF");
            limpa_linha(); limpa_linha(); limpa_linha();
        }
    } while (procura_cpf_client(b->cpf_cli));
    get_quant_venda(b -> quant, "ingressos");
    get_valor(b -> valor, "final (com casa decimal)");
    do {
        get_id(b->id_ven, "a venda (4 dígitos)");
        if (!procura_id_buy(b->id_ven)) {
            screen_error_input_id();
            limpa_linha(); limpa_linha(); limpa_linha();
        }
    } while (!procura_id_buy(b->id_ven));
    b -> status = 'f';
    get_data_hour_buy(b);
}

void buy_inputs_sem_id(Buy* b)
{
    do {
        get_id(b->id_show, "o show (4 dígitos)");
        if (procura_id_show(b->id_show)) {
            screen_error_input_n_exist("Id");
            limpa_linha(); limpa_linha(); limpa_linha();
        }
    } while (procura_id_show(b->id_show));
    do {
        get_cpf(b->cpf_cli);
        if (procura_cpf_client(b->cpf_cli)) {
            screen_error_input_n_exist("CPF");
            limpa_linha(); limpa_linha(); limpa_linha();
        }
    } while (procura_cpf_client(b->cpf_cli));
    get_quant_venda(b -> quant, "ingressos");
    get_valor(b -> valor, "final (com casa decimal)");
    b -> status = 'f';
    get_data_hour_buy(b);
}

Buy *procura_buy(char *id)
{
    FILE *fp;
    Buy *b;

    b = (Buy*)malloc(sizeof(Buy));
    fp = fopen("buy/buys.dat", "rb");
    if (fp == NULL) {
        error_screen_file_buy();
    }
    while (fread(b, sizeof(Buy), 1, fp)) {
        if ((strcmp(b->id_ven, id) == 0) && (b->status == 'f')) {
            fclose(fp);
            return b;
        }
    }
    fclose(fp);
    return NULL;
}

int procura_id_buy(char *id)
{
    FILE *fp;
    Buy *b;

    b = (Buy*)malloc(sizeof(Buy));
    fp = fopen("buy/buys.dat", "rb");
    while (fread(b, sizeof(Buy), 1, fp)) {
        if ((strcmp(b->id_ven, id) == 0)) {
            fclose(fp);
            return 0;
        }
    }
    fclose(fp);
    return 1;
}

void print_dados_buy(Buy* b)
{
    if (b == NULL) {
        screen_null_id_error("da venda");
    }
    else {
        system("clear || cls");
        printf("###############################################################################\n");
        printf("###                                                                         ###\n");
        printf("###            ===================================================          ###\n");
        printf("###            =============   Gestão Casa Shows   ===============          ###\n");
        printf("###            ===================================================          ###\n");
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
        printf("###                                                                         ###\n");
        printf("###              Informações do Id digitado (%s):                         ###\n", b -> id_ven);
        printf("###                                                                         ###\n");
        printf("###              Id do show: %s\n", b -> id_show);
        printf("###              CPF do cliente: %s\n", b -> cpf_cli);
        printf("###              Quant. de ingressos: %s\n", b -> quant);
        printf("###              Valor final: %s\n", b -> valor);
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
    }
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    getchar();
}

void print_dados_buy_upd(Buy* b)
{
    if (b == NULL) {
        screen_null_id_error("da venda");
    }
    else {
        system("clear || cls");
        printf("###############################################################################\n");
        printf("###                                                                         ###\n");
        printf("###            ===================================================          ###\n");
        printf("###            =============   Gestão Casa Shows   ===============          ###\n");
        printf("###            ===================================================          ###\n");
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
        printf("###                                                                         ###\n");
        printf("###              Informações do Id digitado (%s):                         ###\n", b -> id_ven);
        printf("###                                                                         ###\n");
        printf("###              Id do show: %s\n", b -> id_show);
        printf("###              CPF do cliente: %s\n", b -> cpf_cli);
        printf("###              Quant. de ingressos: %s\n", b -> quant);
        printf("###              Valor final: %s\n", b -> valor);
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
    }
}

void print_dados_buy_rep(Buy* b)
{
    if (b == NULL) {
        printf("Erro na abertura do arquivo!\n");
        printf("Não é possível continuar este programa...\n");
        exit(1);
    } else {
        printf("###############################################################################\n");
        printf("###                                                                         ###\n");
        printf("###              Id do show: %s\n", b -> id_show);
        printf("###              CPF do cliente: %s\n", b -> cpf_cli);
        printf("###              Quant. de ingressos: %s\n", b -> quant);
        printf("###              Valor final: %s\n", b -> valor);
        printf("###              Id da venda: %s\n", b -> id_ven);
        printf("###              Status da venda: %c\n", b -> status);
        printf("###                                                                         ###\n");
        printf("###############################################################################\n\n");
    }
}

void gravar_buy(Buy* b) 
{
	FILE* fp_b;
	fp_b = fopen("buy/buys.dat", "ab");
	if (fp_b == NULL) {
		error_screen_file_buy();
	}
	fwrite(b, sizeof(Buy), 1, fp_b);
	fclose(fp_b);
    free(b);
}

void error_screen_file_buy(void) 
{
	system("cls || clear");
    printf("#############################################################################\n");
	printf("###                                                                       ###\n");
	printf("###           = = = = = = = = = = = = = = = = = = = = = = = =             ###\n");
	printf("###           = = = = = = = Ops! Ocorreu um erro! = = = = = =             ###\n");
	printf("###           = = =  Não foi possível acessar o arquivo = = =             ###\n");
	printf("###           = = = = com informações sobre as vendas = = = =             ###\n");
	printf("###                                                                       ###\n");
    printf("#############################################################################\n");
	printf("\t\t    >>> Tecle ENTER para continuar! <<<");
	getchar();
}

void pesquisa_buy(void)
{
    Buy *b;
    char *id;

    id = screen_busc_buy();
    b = procura_buy(id);
    print_dados_buy(b);
    free(b);
    free(id);
}

void update_buy(void)
{
    Buy *b;
    char *id;
    int resp;

    id = screen_upd_buy();
    b = procura_buy(id);
    if (b == NULL) {
        screen_null_id_error("da venda");
        printf("\n\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
        getchar();
    }
    else {
        print_dados_buy_upd(b);
        resp = certeza_upd("dessa venda");
        if (resp) {
            b = cred_buy_sem_id();
            strcpy(b->id_ven, id);
            regravar_buy(b);
            free(b);
        } else {
            printf("\n\t\t                        Ok!\n");
            printf("\n\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
            getchar();
        }
    }
    free(id);
}

void regravar_buy(Buy *b)
{
    int achou = 0;
    FILE *fp;
    Buy *buyLido;

    buyLido = (Buy *)malloc(sizeof(Buy));
    fp = fopen("buy/buys.dat", "r+b");
    if (fp == NULL) {
        error_screen_file_buy();
    }
    while(!feof(fp)) {
        fread(buyLido, sizeof(Buy), 1, fp);
        if (strcmp(buyLido->id_ven, b->id_ven) == 0) {
            achou = 1;
            fseek(fp, -1 * sizeof(Buy), SEEK_CUR);
            fwrite(b, sizeof(Buy), 1, fp);
            break;
        }
    }
    if (!achou) {
        screen_null_id_error("da venda");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
        getchar();
    }
    fclose(fp);
    free(buyLido);
}

void get_data_hour_buy(Buy *b)
{
    time_t currentTime;
    time(&currentTime);
    struct tm *timeInfo;
    timeInfo = localtime(&currentTime);
    b->day = timeInfo->tm_mday;
    b->month = timeInfo->tm_mon + 1;
    b->year = timeInfo->tm_year + 1900;
    b->hour = timeInfo->tm_hour;
    b->minute = timeInfo->tm_min;
}