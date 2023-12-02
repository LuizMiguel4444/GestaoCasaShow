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
        if (!ehDigitoMax(resp[0], '6')  || !val_entrada(resp)) {
            screen_error_input();
            limpa_linha();
        }
    } while (!ehDigitoMax(resp[0], '6') || !val_entrada(resp));
    return resp[0];
}

char report_menu_fil_buy(void)
{
    char resp[256];
    do {
        report_menu_screen_fil_buy();
        scanf("%s", resp);
        limpa_buffer();
        if (!ehDigitoMax(resp[0], '5')  || !val_entrada(resp)) {
            screen_error_input();
            limpa_linha();
        }
    } while (!ehDigitoMax(resp[0], '5') || !val_entrada(resp));
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
    printf("###                           6. Em ordem alfabética                        ###\n");
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
    printf("###                           4. Em ordem de valor                          ###\n");
    printf("###                          5. Em ordem alfabética                         ###\n");
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
            case '6':
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
            case '4':
                report_buy(resp);
                break;
            case '5':
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
            case '6':
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
            case '6':
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
    else if (escolha == '6') {
        snprintf(quant_str, 8, "%d", quant_total);
    }
    return quant_str;
}

int comparar(const void *a, const void *b)
{
    const Buy *buy_a = (const Buy *)a;
    const Buy *buy_b = (const Buy *)b;
    float valor_a = strtof(buy_a->valor, NULL);
    float valor_b = strtof(buy_b->valor, NULL);

    if (valor_a < valor_b) return 1;
    if (valor_a > valor_b) return -1;
    return 0;
} // Feito com ajuda do chat-GPT

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
        if (!valNome(nome, 1))
        {
            screen_error_input_name();
            limpa_linha(); limpa_linha(); limpa_linha(); limpa_linha(); limpa_linha();
        }
    } while (!valNome(nome, 1));
    converte_para_minusculo(nome);
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

int aux_report_6_atr(Atraction* atr, FILE* fp, char escolha)
{
    int quant_atr_total = 0;
    Atraction* lista;
    lista = NULL;
    system("clear || cls");
    screen_report_atr();
    while(fread(atr, sizeof(Atraction), 1, fp)) {
        quant_atr_total += 1;
        atr->prox = NULL;
        if ((lista == NULL) || (strcmp(atr->nome, lista->nome) < 0)) {
            atr->prox = lista;
            lista = atr;
        } else {
            Atraction *anterior = lista;
            Atraction *atual = lista->prox;
            while ((atual != NULL) && strcmp(atual->nome, atr->nome) < 0) {
                anterior = atual;
                atual = atual->prox;
            }
            anterior->prox = atr;
            atr->prox = atual;
        }
        atr = (Atraction*)malloc(sizeof(Atraction));
    }
    print_func_in_malloc_atr(atr, lista, escolha);
    free_func_in_malloc_atr(atr, lista);
    return quant_atr_total;
}

void print_func_in_malloc_atr(Atraction* atr, Atraction* lista, char escolha)
{
    atr = lista;
    while (atr != NULL) {
        print_if_in_filter_atr(atr, escolha);
        atr = atr->prox;
    }
}

void free_func_in_malloc_atr(Atraction* atr, Atraction* lista)
{
    atr = lista;
    while (lista != NULL) {
        lista = lista->prox;
        free(atr);
        atr = lista;
    }
}

int aux_report_2_buy(Buy* b, FILE* fp, char escolha, float* valor_total)
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

int aux_report_3_buy(Buy* b, FILE* fp, char escolha, float* valor_total)
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

int aux_report_4_buy(Buy* b, FILE* fp, char escolha, float* valor_total)
{
    system("clear || cls");
    screen_report_buy();

    Buy* array = (Buy*)malloc(100 * sizeof(Buy));
    int quant_buy_total = 0;
    int tam_array = 0;
    Buy temp;

    while(fread(&temp, sizeof(Buy), 1, fp) && tam_array < 100) {
        array[tam_array] = temp;
        tam_array++;
        quant_buy_total += 1;
        float valor_compra = strtof(temp.valor, NULL);
        *valor_total += valor_compra;
    }

    qsort(array, tam_array, sizeof(Buy), comparar);

    for (int i = 0; i < tam_array; i++) {
        print_if_in_filter_buy(&array[i], escolha);
    }

    free(array);
    return quant_buy_total;
}

int aux_report_5_buy(Buy* b, FILE* fp, char escolha, float* valor_total)
{
    int quant_buy_total = 0;
    Buy* lista;
    lista = NULL;
    Client* cli;
    Client* lista_cli;
    lista_cli = NULL;
    system("clear || cls");
    screen_report_buy();
    while(fread(b, sizeof(Buy), 1, fp)) {
        cli = procura_client(b -> cpf_cli);
        quant_buy_total += 1;
        b->prox = NULL;
        cli->prox = NULL;
        if ((lista == NULL) || (strcmp(cli->nome, lista_cli->nome) < 0)) {
            b->prox = lista;
            lista = b;
            cli->prox = lista_cli;
            lista_cli = cli;
        } else {
            Buy *anterior = lista;
            Buy *atual = lista->prox;
            Client *cli_anterior = lista_cli;
            Client *cli_atual = lista_cli->prox;
            while ((atual != NULL) && strcmp(cli_atual->nome, cli->nome) < 0) {
                anterior = atual;
                atual = atual->prox;
                cli_anterior = cli_atual;
                cli_atual = cli_atual->prox;
            }
            anterior->prox = b;
            b->prox = atual;
            cli_anterior->prox = cli;
            cli->prox = cli_atual;
        }
        b = (Buy*)malloc(sizeof(Buy));
        cli = (Client*)malloc(sizeof(Client));
    }
    print_func_in_malloc_buy(b, lista, escolha);
    free_func_in_malloc_buy(b, lista);
    return quant_buy_total;
}

void print_func_in_malloc_buy(Buy* b, Buy* lista, char escolha)
{
    b = lista;
    while (b != NULL) {
        print_if_in_filter_buy(b, escolha);
        b = b->prox;
    }
}

void free_func_in_malloc_buy(Buy* b, Buy* lista)
{
    b = lista;
    while (lista != NULL) {
        lista = lista->prox;
        free(b);
        b = lista;
    }
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

int aux_report_6_cli(Client* cli, FILE* fp, char escolha)
{
    int quant_cli_total = 0;
    Client* lista;
    lista = NULL;
    system("clear || cls");
    screen_report_cli();
    while(fread(cli, sizeof(Client), 1, fp)) {
        quant_cli_total += 1;
        cli->prox = NULL;
        if ((lista == NULL) || (strcmp(cli->nome, lista->nome) < 0)) {
            cli->prox = lista;
            lista = cli;
        } else {
            Client *anterior = lista;
            Client *atual = lista->prox;
            while ((atual != NULL) && strcmp(atual->nome, cli->nome) < 0) {
                anterior = atual;
                atual = atual->prox;
            }
            anterior->prox = cli;
            cli->prox = atual;
        }
        cli = (Client*)malloc(sizeof(Client));
    }
    print_func_in_malloc_cli(cli, lista, escolha);
    free_func_in_malloc_cli(cli, lista);
    return quant_cli_total;
}

void print_func_in_malloc_cli(Client* cli, Client* lista, char escolha)
{
    cli = lista;
    while (cli != NULL) {
        print_if_in_filter_cli(cli, escolha);
        cli = cli->prox;
    }
}

void free_func_in_malloc_cli(Client* cli, Client* lista)
{
    cli = lista;
    while (lista != NULL) {
        lista = lista->prox;
        free(cli);
        cli = lista;
    }
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

int aux_report_6_show(Show* sh, FILE* fp, char escolha)
{
    int quant_show_total = 0;
    Show* lista;
    lista = NULL;
    system("clear || cls");
    screen_report_show();
    while(fread(sh, sizeof(Show), 1, fp)) {
        quant_show_total += 1;
        sh->prox = NULL;
        if ((lista == NULL) || (strcmp(sh->atraction, lista->atraction) < 0)) {
            sh->prox = lista;
            lista = sh;
        } else {
            Show *anterior = lista;
            Show *atual = lista->prox;
            while ((atual != NULL) && strcmp(atual->atraction, sh->atraction) < 0) {
                anterior = atual;
                atual = atual->prox;
            }
            anterior->prox = sh;
            sh->prox = atual;
        }
        sh = (Show*)malloc(sizeof(Show));
    }
    print_func_in_malloc_show(sh, lista, escolha);
    free_func_in_malloc_show(sh, lista);
    return quant_show_total;
}

void print_func_in_malloc_show(Show* sh, Show* lista, char escolha)
{
    sh = lista;
    while (sh != NULL) {
        print_if_in_filter_show(sh, escolha);
        sh = sh->prox;
    }
}

void free_func_in_malloc_show(Show* sh, Show* lista)
{
    sh = lista;
    while (lista != NULL) {
        lista = lista->prox;
        free(sh);
        sh = lista;
    }
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
        case '6':
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
        case '4':
            printf("### -------------------------------------------------------------------------------------- ###\n");
            print_dados_buy_rep(b);
            printf("### -------------------------------------------------------------------------------------- ###\n");
            break;
        case '5':
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
        case '4':
            printf("### ----------------------------------------------------------------------- ###\n");
            print_dados_client_rep(cli);
            printf("### ----------------------------------------------------------------------- ###\n");
            break;
        case '5':
            printf("### ----------------------------------------------------------------------- ###\n");
            print_dados_client_rep(cli);
            printf("### ----------------------------------------------------------------------- ###\n");
            break;
        case '6':
            printf("### ----------------------------------------------------------------------- ###\n");
            print_dados_client_rep(cli);
            printf("### ----------------------------------------------------------------------- ###\n");
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
        case '4':
            printf("### ----------------------------------------------------------------------- ###\n");
            print_dados_show_rep(sh);
            printf("### ----------------------------------------------------------------------- ###\n");
            break;
        case '5':
            printf("### ----------------------------------------------------------------------- ###\n");
            print_dados_show_rep(sh);
            printf("### ----------------------------------------------------------------------- ###\n");
            break;
        case '6':
            printf("### ----------------------------------------------------------------------- ###\n");
            print_dados_show_rep(sh);
            printf("### ----------------------------------------------------------------------- ###\n");
            break;
    }
}
