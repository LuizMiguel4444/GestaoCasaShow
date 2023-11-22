#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include "atraction.h"
#include "../auxiliar/auxiliar.h"
#include "../util/util.h"



// Functions
void modulo_atraction(void)
{
    Atraction *atracao;
    setlocale(LC_ALL, "Portuguese_Brazil");
    int resp;
    do
    {
        resp = atraction_menu();
        switch (resp)
        {
        case '1':
            atracao = cred_atraction();
            gravar_atr(atracao);
            break;
        case '2':
            pesquisa_atr();
            break;
        case '3':
            update_atr();
            break;
        case '4':
            excluir_atr();
            break;
        case '0':
            system("cls || clear");
            break;
        }
    } while (resp != '0');
}

char atraction_menu(void)
{
    char resp[256];
    do
    {
        atraction_menu_screen();
        scanf("%s", resp);
        limpa_buffer();
        if (!ehDigitoMax(resp[0], '4') || !val_entrada(resp))
        {
            screen_error_input();
            limpa_linha();
        }
    } while (!ehDigitoMax(resp[0], '4') || !val_entrada(resp));
    return resp[0];
}

Atraction *cred_atraction(void)
{
    Atraction *atr;
    atr = (Atraction *)malloc(sizeof(Atraction) + 1);
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
    printf("###              = = = = = = =  Cadastrar Atração  = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    atraction_inputs(atr);
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    limpa_buffer();
    return atr;
}

void atraction_inputs(Atraction *atr)
{
    char* nome = get_nome("a atração");
    strcpy(atr->nome, nome);
    char* cache = get_cache("a atração (com casa decimal)");
    strcpy(atr->cache, cache);
    char* email = get_email("e contato");
    strcpy(atr->email, email);
    char* num = get_num("e contato (com DDD)", 30);
    strcpy(atr->num, num);
    char* id = gera_id_atr();
    snprintf(atr->id, sizeof(atr->id), "%s", id);
    atr->status = 'c';
    get_data_hour_atr(atr);
}

void get_data_hour_atr(Atraction *atr)
{
    time_t currentTime;
    time(&currentTime);
    struct tm *timeInfo;
    timeInfo = localtime(&currentTime);
    atr->day = timeInfo->tm_mday;
    atr->month = timeInfo->tm_mon + 1;
    atr->year = timeInfo->tm_year + 1900;
    atr->hour = timeInfo->tm_hour;
    atr->minute = timeInfo->tm_min;
}

char *screen_busc_atraction(void)
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
    printf("###              = = = = = = =  Pesquisar Atração  = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    do {
        printf("###              Informe o Id da atração: ");
        scanf("%s", id);
        limpa_buffer();
        if (!val_id(id)) {
            screen_error_input();
            limpa_linha(); limpa_linha(); limpa_linha();
        }
    } while (!val_id(id));
    printf("###                                                                         ###\n");
    return id;
}

char *screen_upd_atraction(void)
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
    printf("###              = = = = = = = = Editar  Atração = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    do {
        printf("###              Informe o Id da atração: ");
        scanf("%s", id);
        limpa_buffer();
        if (!val_id(id)) {
            screen_error_input();
            limpa_linha(); limpa_linha(); limpa_linha();
        }
    } while (!val_id(id));
    printf("###                                                                         ###\n");
    return id;
}

void update_atr(void)
{
    Atraction *atr;
    char *id;
    int resp;

    id = screen_upd_atraction();
    atr = procura_atraction(id);
    if (atr == NULL) {
        screen_null_id_error("Id da atração");
        printf("\n\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
        limpa_buffer();
    }
    else {
        print_dados_atraction_upd(atr);
        resp = certeza_upd("dessa atração");
        if (resp) {
            regravar_atr(atr);
        } else {
            printf("\n\t\t                        Ok!\n");
            printf("\n\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
            limpa_buffer();
        }
    }
    free(id);
    free(atr);
}

void qual_campo_atr(Atraction *atr)
{
    char resp[256];
    printf("\n\t\t\t\t    1 - Nome\n");
    printf("\t\t\t\t    2 - Cachê\n");
    printf("\t\t\t\t    3 - Email\n");
    printf("\t\t\t\t    4 - Número\n");
    do {
        printf("\n\t\t    Digite o número do campo que deseja editar: ");
        scanf("%s", resp);
        limpa_buffer();
        if (!ehDigitoMax(resp[0], '4')  || !val_entrada(resp)) {
            screen_error_input_resp();
            limpa_linha(); limpa_linha(); limpa_linha(); limpa_linha();
        }
    } while (!ehDigitoMax(resp[0], '4')  || !val_entrada(resp));
    char* nome;
    char* cache;
    char* email;
    char* num;
    switch (resp[0]) {
        case '1':
            nome = get_nome_upd("da atração");
            strcpy(atr->nome, nome);
            printf("\n\t\t    >>> Nome da atração editado com sucesso. <<<");
            limpa_buffer();
            break;
        case '2':
            cache = get_cache_upd("da atração");
            strcpy(atr->cache, cache);
            printf("\n\t\t    >>> Cachê da atração editado com sucesso. <<<");
            limpa_buffer();
            break;
        case '3':
            email = get_email_upd("de contato");
            strcpy(atr->email, email);
            printf("\n\t\t    >>> Email da atração editado com sucesso. <<<");
            limpa_buffer();
            break;
        case '4':
            num = get_num_upd("de contato");
            strcpy(atr->num, num);
            printf("\n\t\t    >>> Número da atração editado com sucesso. <<<");
            limpa_buffer();
            break;
    }
}

char *del_atraction(void)
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
    printf("###              = = = = = = =  Excluir Atração  = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    do
    {
        printf("###              Informe o Id da atração: ");
        scanf("%s", id);
        limpa_buffer();
        if (!val_id(id))
        {
            screen_error_input();
            limpa_linha();
            limpa_linha();
            limpa_linha();
        }
    } while (!val_id(id));
    printf("###                                                                         ###\n");
    return id;
}



// File Functions
void gravar_atr(Atraction *atr)
{
    FILE *fp_atr;
    fp_atr = fopen("atraction/atractions.dat", "ab");
    if (fp_atr == NULL) {
        error_screen_file_atr();
    }
    fwrite(atr, sizeof(Atraction), 1, fp_atr);
    fclose(fp_atr);
    free(atr);
}

void pesquisa_atr(void)
{
    Atraction *atr;
    char *id;

    id = screen_busc_atraction();
    atr = procura_atraction(id);
    print_dados_atraction(atr);
    free(atr);
    free(id);
}

Atraction *procura_atraction(char *id)
{
    FILE *fp;
    Atraction *atr;

    atr = (Atraction *)malloc(sizeof(Atraction));
    fp = fopen("atraction/atractions.dat", "rb");
    if (fp == NULL) {
        error_screen_file_atr();
    }
    while (fread(atr, sizeof(Atraction), 1, fp)) {
        if ((strcmp(atr->id, id) == 0) && (atr->status == 'c')) {
            fclose(fp);
            return atr;
        }
    }
    fclose(fp);
    return NULL;
}

void regravar_atr(Atraction *atr)
{
    int achou = 0;
    FILE *fp;
    Atraction *atrLido;

    atrLido = (Atraction *)malloc(sizeof(Atraction));
    fp = fopen("atraction/atractions.dat", "r+b");
    if (fp == NULL) {
        error_screen_file_atr();
    }
    while(!feof(fp)) {
        fread(atrLido, sizeof(Atraction), 1, fp);
        if (strcmp(atrLido->id, atr->id) == 0) {
            achou = 1;
            qual_campo_atr(atr);
            fseek(fp, -1 * sizeof(Atraction), SEEK_CUR);
            fwrite(atr, sizeof(Atraction), 1, fp);
            break;
        }
    }
    if (!achou) {
        screen_null_id_error("Id da atração");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
        limpa_buffer();
    }
    fclose(fp);
    free(atrLido);
}

void remove_atr(Atraction *atr)
{
    int achou = 0;
    FILE *fp;
    Atraction *atrArq;
    atrArq = (Atraction *)malloc(sizeof(Atraction));
    fp = fopen("atraction/atractions.dat", "r+b");
    if (fp == NULL) {
        error_screen_file_atr();
    }
    while (!feof(fp)) {
        fread(atrArq, sizeof(Atraction), 1, fp);
        if ((strcmp(atrArq->id, atr->id) == 0) && (atrArq->status != 'x')) {
            achou = 1;
            atrArq->status = 'x';
            fseek(fp, -1 * sizeof(Atraction), SEEK_CUR);
            fwrite(atrArq, sizeof(Atraction), 1, fp);
            screen_del_ok_atr();
        }
    }
    if (!achou) {
        screen_null_id_error("Id da atração");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
        limpa_buffer();
    }
    fclose(fp);
    free(atrArq);
}

void excluir_atr(void)
{
    Atraction *atr;
    char *id;
    int resp;

    atr = (Atraction *)malloc(sizeof(Atraction));
    id = del_atraction();
    atr = procura_atraction(id);
    if (atr == NULL) {
        screen_null_id_error("Id da atração");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
        limpa_buffer();
    } else {
        print_dados_atraction_upd(atr);
        resp = certeza_del("dessa atração");
        if (resp) {
            printf("\n");
            atr->status = 'x';
            remove_atr(atr);
            free(atr);
        } else {
            printf("\n\t\t                        Ok!\n");
            printf("\n\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
            limpa_buffer();
        }
    }
    free(id);
}

char* gera_id_atr(void)
{
    FILE *fp;
    fp = fopen("atraction/atractions.dat", "rb");
    if (fp == NULL) {
        return "1";
    }
    fseek(fp, 0, SEEK_END);
    if ((long)ftell(fp) == 0) {
        fclose(fp);
        return "1";
    }
    else {
        fseek(fp, -((long)sizeof(Atraction)), SEEK_END);
        Atraction* atr;
        atr = (Atraction*)malloc(sizeof(Atraction));
        fread(atr, sizeof(Atraction), 1, fp);
        int id_int = atoi(atr->id);
        int id_soma = id_int + 1;
        char id_string[5];
        snprintf(id_string, sizeof(id_string), "%d", id_soma);
        char* id = id_string;
        fclose(fp);
        return id;
    }
}



// Screen Functions
void atraction_menu_screen(void)
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
    printf("###              = = = = = = = =  Menu Atrações  = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    printf("###              1. Cadastrar uma nova atração                              ###\n");
    printf("###              2. Pesquisar os dados de uma atração                       ###\n");
    printf("###              3. Editar o cadastro de uma atração                        ###\n");
    printf("###              4. Excluir uma atração do sistema                          ###\n");
    printf("###              0. Voltar ao Menu Principal                                ###\n");
    printf("###                                                                         ###\n");
    printf("###              Escolha a opção que deseja: ");
}

void print_dados_atraction(Atraction *atr)
{
    if (atr == NULL) {
        screen_null_id_error("Id da atração");
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
        printf("###              Cadastro realizado em %02d/%02d/%d às %02d:%02d.                 ###\n", atr->day, atr->month, atr->year, atr->hour, atr->minute);
        printf("###                                                                         ###\n");
        printf("###              Informações do Id digitado: %s###\n", centralizar_texto(atr->id, 31, -1));
        printf("###                                                                         ###\n");
        printf("###              Nome da atração: %s###\n", centralizar_texto(atr->nome, 42, -1));
        printf("###              Valor do cachê da atração: R$%s###\n", centralizar_texto(atr->cache, 30, -1));
        printf("###              Email de contato da atração: %s###\n", centralizar_texto(atr->email, 30, -1));
        printf("###              Número de contato da atração: %s###\n", centralizar_texto(atr->num, 29, -1));
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
    }
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    limpa_buffer();
}

void print_dados_atraction_upd(Atraction *atr)
{
    if (atr == NULL) {
        screen_null_id_error("Id da atração");
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
        printf("###              Informações do Id digitado: %s###\n", centralizar_texto(atr->id, 31, -1));
        printf("###                                                                         ###\n");
        printf("###              Nome da atração: %s###\n", centralizar_texto(atr->nome, 42, -1));
        printf("###              Valor do cachê da atração: R$%s###\n", centralizar_texto(atr->cache, 30, -1));
        printf("###              Email de contato da atração: %s###\n", centralizar_texto(atr->email, 30, -1));
        printf("###              Número de contato da atração: %s###\n", centralizar_texto(atr->num, 29, -1));
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
    }
}

void print_dados_atraction_rep(Atraction *atr)
{
    if (atr == NULL) {
        printf("Erro na abertura do arquivo!\n");
        printf("Não é possível continuar este programa...\n");
        exit(1);
    } else {
        printf("### |%s", centralizar_texto(atr->nome, 34, 0));
        printf("|%s", centralizar_texto(atr->email, 42, 0));
        printf(" | %s| ###\n", centralizar_texto(atr -> id, 11, 0));
    }
}

void screen_del_ok_atr(void)
{
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###                     Atração excluída com sucesso!!!                     ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    limpa_buffer();
}

void error_screen_file_atr(void)
{
    system("cls || clear");
    printf("#############################################################################\n");
    printf("###                                                                       ###\n");
    printf("###           = = = = = = = = = = = = = = = = = = = = = = = =             ###\n");
    printf("###           = = = = = = = Ops! Ocorreu um erro! = = = = = =             ###\n");
    printf("###           = = =  Não foi possível acessar o arquivo = = =             ###\n");
    printf("###           = = =  com informações sobre as atrações  = = =             ###\n");
    printf("###                                                                       ###\n");
    printf("#############################################################################\n");
    printf("\t\t    >>> Tecle ENTER para continuar! <<<");
    limpa_buffer();
}
