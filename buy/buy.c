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
#include "../auxiliar/auxiliar.h"
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

void buy_inputs(Buy* b)
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
        if (procura_cpf_client_fantasm(b->cpf_cli)) {
            screen_error_input_n_exist("CPF");
            limpa_linha(); limpa_linha(); limpa_linha();
        }
    } while (procura_cpf_client_fantasm(b->cpf_cli));
    get_quant_venda(b -> quant, "ingressos");
    corrige_valor_final(b->quant, b->id_show, b->valor);
    do {
        get_id(b->id_ven, "a venda (4 dígitos)");
        if (!procura_id_buy(b->id_ven)) {
            screen_error_input_id("Id");
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
        if (procura_cpf_client_fantasm(b->cpf_cli)) {
            screen_error_input_n_exist("CPF");
            limpa_linha(); limpa_linha(); limpa_linha();
        }
    } while (procura_cpf_client_fantasm(b->cpf_cli));
    get_quant_venda(b -> quant, "ingressos");
    corrige_valor_final(b->quant, b->id_show, b->valor);
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
        if ((strcmp(b->id_ven, id) == 0) && b->status == 'f') {
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
        screen_null_id_error("Id da venda");
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
        printf("###              Id do show: %s###\n", centralizar_texto(b -> id_show, 47, -1));
        printf("###              CPF do cliente: %s###\n", centralizar_texto(b -> cpf_cli, 43, -1));
        printf("###              Quant. de ingressos: %s###\n", centralizar_texto(b -> quant, 38, -1));
        printf("###              Valor final: R$%s###\n", centralizar_texto(b -> valor, 44, -1));
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
        screen_null_id_error("Id da venda");
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
        printf("###              Id do show: %s###\n", centralizar_texto(b -> id_show, 47, -1));
        printf("###              CPF do cliente: %s###\n", centralizar_texto(b -> cpf_cli, 43, -1));
        printf("###              Quant. de ingressos: %s###\n", centralizar_texto(b -> quant, 38, -1));
        printf("###              Valor final: R$%s###\n", centralizar_texto(b -> valor, 44, -1));
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
        printf("###              Id do show: %s###\n", centralizar_texto(b -> id_show, 47, -1));
        printf("###              CPF do cliente: %s###\n", centralizar_texto(b -> cpf_cli, 43, -1));
        printf("###              Quant. de ingressos: %s###\n", centralizar_texto(b -> quant, 38, -1));
        printf("###              Valor final: R$%s###\n", centralizar_texto(b -> valor, 44, -1));
        printf("###              Id da venda: %s###\n", centralizar_texto(b -> id_ven, 46, -1));
        if (b -> status == 'f') {
            char status[] = "Finalizada";
            printf("###              Status da venda: %s###\n", centralizar_texto(status, 42, -1));
        }
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
        screen_null_id_error("Id da venda");
        printf("\n\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
        getchar();
    }
    else {
        print_dados_buy_upd(b);
        resp = certeza_upd("dessa venda");
        if (resp) {
            regravar_buy(b);
        } else {
            printf("\n\t\t                        Ok!\n");
            printf("\n\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
            getchar();
        }
    }
    free(id);
    free(b);
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
            qual_campo_buy(b);
            fseek(fp, -1 * sizeof(Buy), SEEK_CUR);
            fwrite(b, sizeof(Buy), 1, fp);
            break;
        }
    }
    if (!achou) {
        screen_null_id_error("Id da venda");
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

void qual_campo_buy(Buy *b)
{
    char resp[256];
    printf("\n\t\t\t     1 - CPF do cliente\n");
    do {
        printf("\n\t\t   Digite o número do campo que deseja editar: ");
        scanf("%s", resp);
        limpa_buffer();
        if (!ehDigitoMax(resp[0], '1')  || !val_entrada(resp)) {
            screen_error_input_resp();
            limpa_linha(); limpa_linha(); limpa_linha(); limpa_linha();
        }
    } while (!ehDigitoMax(resp[0], '1')  || !val_entrada(resp));
    switch (resp[0]) {
        case '1':
            do {
                get_cpf_upd(b->cpf_cli);
                if (procura_cpf_client_fantasm(b->cpf_cli)) {
                    screen_error_input_n_exist("CPF");
                    limpa_linha(); limpa_linha(); limpa_linha();
                }
            } while (procura_cpf_client_fantasm(b->cpf_cli));
            printf("\n\t\t   >>> CPF do cliente editado com sucesso. <<<");
            getchar();
            break;
    }
}

void corrige_valor_final(char* quant, char* id_show, char* valor)
{
    int quant_ing = atoi(quant); // Converte a string para int.
    char* valor_string = retorna_valor_show(id_show);
    float valor_ing = strtof(valor_string, NULL); // Converte a string para float.
    float valor_final = quant_ing * valor_ing;
    char valor_final_para_string[20];
    snprintf(valor_final_para_string, sizeof(valor_final_para_string), "%.2f", valor_final);
    memcpy(valor, valor_final_para_string, sizeof(valor_final_para_string)); // Copia dados de um array para outro array.
}
