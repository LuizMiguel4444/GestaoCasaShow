#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include "show.h"
#include "../atraction/atraction.h"
#include "../auxiliar/auxiliar.h"
#include "../util/util.h"



// Functions
void modulo_show(void)
{
    Show* show;
    setlocale(LC_ALL, "Portuguese_Brazil");
    int resp;
    do
    {
        resp = show_menu();
        switch (resp)
        {
            case '1':
                show = cred_show();
                gravar_show(show);
                break;
            case '2':
                pesquisa_show();
                break;
            case '3':
                update_show();
                break;
            case '4':
                excluir_show();
                break;
            case '0':
                system("cls || clear");
                break;
        }
    } while (resp != '0');
}

char show_menu(void)
{
    char resp[256];
    do {
        show_menu_screen();
        scanf("%s", resp);
        limpa_buffer();
        if (!ehDigitoMax(resp[0], '4')  || !val_entrada(resp)) {
            screen_error_input();
            limpa_linha();
        }
    } while (!ehDigitoMax(resp[0], '4') || !val_entrada(resp));
    return resp[0];
}

Show *cred_show(void)
{
    Show *sh;
    sh = (Show*) malloc(sizeof(Show) + 1);
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
    printf("###              = = = = = = = = Cadastrar  Show = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    show_inputs(sh);
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    limpa_buffer();
    return sh;
}

void show_inputs(Show* sh)
{
    char* nome = get_nome("a atração");
    strcpy(sh->atraction, nome);
    char* data = get_data();
    strcpy(sh->data, data);
    char* hora = get_hour();
    strcpy(sh->hora, hora);
    char* quant = get_quant_cad("ingressos");
    strcpy(sh->quant, quant);
    snprintf(sh -> quant_rest, sizeof(sh -> quant_rest), "%s", sh -> quant);
    char* valor = get_valor("do ingresso (com casa decimal)");
    strcpy(sh->valor, valor);
    char* id = gera_id_show();
    snprintf(sh -> id, sizeof(sh -> id), "%s", id);
    sh -> status = 'c';
    get_data_hour_sh(sh);
}

void get_data_hour_sh(Show *sh)
{
    time_t currentTime;
    time(&currentTime);
    struct tm *timeInfo;
    timeInfo = localtime(&currentTime);
    int day = timeInfo->tm_mday;
    char dia[4];
    snprintf(dia, sizeof(dia), "%d", day);
    if (strlen(dia) < 2) {
        dia[1] = dia[0];
        dia[0] = '0';
        dia[2] = '\0';
    }
    int month = timeInfo->tm_mon + 1;
    char mes[4];
    snprintf(mes, sizeof(mes), "%d", month);
    if (strlen(mes) < 2) {
        mes[1] = mes[0];
        mes[0] = '0';
        mes[2] = '\0';
    }
    int year = timeInfo->tm_year + 1900;
    char ano[6];
    snprintf(ano, sizeof(ano), "%d", year);
    strcat(dia, mes);
    strcat(dia, ano);
    strcpy(sh->date, dia);
    sh->hour = timeInfo->tm_hour;
    sh->minute = timeInfo->tm_min;
}

char *screen_busc_show(void)
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
    printf("###              = = = = = = = = Pesquisar  Show = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    do {
        printf("###              Informe o Id do show: ");
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

char *screen_upd_show(void)
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
    printf("###              = = = = = = = =  Editar Show  = = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    do {
        printf("###              Informe o Id do show: ");
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

void update_show(void)
{
    Show *sh;
    char *id;
    int resp;

    id = screen_upd_show();
    sh = procura_show(id);
    if (sh == NULL) {
        screen_null_id_error("Id do show");
        printf("\n\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
        limpa_buffer();
    }
    else {
        print_dados_show_upd(sh);
        resp = certeza_upd("desse show");
        if (resp) {
            regravar_show(sh);
        } else {
            printf("\n\t\t                        Ok!\n");
            printf("\n\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
            limpa_buffer();
        }
    }
    free(id);
    free(sh);
}

void qual_campo_show(Show *sh)
{
    char resp[256];
    printf("\n\t\t\t\t   1 - Nome\n");
    printf("\t\t\t\t   2 - Data\n");
    printf("\t\t\t\t   3 - Hora\n");
    printf("\t\t\t\t   4 - Quant.\n");
    printf("\t\t\t\t   5 - Valor\n");
    do {
        printf("\n\t\t    Digite o número do campo que deseja editar: ");
        scanf("%s", resp);
        limpa_buffer();
        if (!ehDigitoMax(resp[0], '5')  || !val_entrada(resp)) {
            screen_error_input_resp();
            limpa_linha(); limpa_linha(); limpa_linha(); limpa_linha();
        }
    } while (!ehDigitoMax(resp[0], '5')  || !val_entrada(resp));
    int old_quant = atoi(sh->quant);
    char* nome;
    char* data;
    char* hora;
    char* quant;
    char* valor;
    switch (resp[0]) {
        case '1':
            nome = get_nome_upd("da atração");
            strcpy(sh->atraction, nome);
            printf("\n\t\t    >>> Nome da atração editado com sucesso. <<<");
            limpa_buffer();
            break;
        case '2':
            data = get_data_upd();
            strcpy(sh->data, data);
            printf("\n\t\t    >>> Data editada com sucesso. <<<");
            limpa_buffer();
            break;
        case '3':
            hora = get_hour_upd();
            strcpy(sh->hora, hora);
            printf("\n\t\t    >>> Horário editado com sucesso. <<<");
            limpa_buffer();
            break;
        case '4':
            quant = get_quant_cad_upd("ingressos");
            strcpy(sh->quant, quant);
            int new_quant = atoi(sh->quant);
            int restante = atoi(sh->quant_rest);
            if (new_quant < (old_quant - restante)) {
                snprintf(sh->quant, sizeof(sh->quant), "%d", old_quant);
                printf("\n\t\t    Impossível diminuir para essa quantidade de ingressos!\n");
                printf("\n\t\t    Tecle Enter para voltar ao menu anterior...");
                limpa_buffer();
                break;
            } else {
                int diferenca = new_quant - old_quant;
                int new_rest = restante + diferenca;
                snprintf(sh->quant_rest, sizeof(sh->quant_rest), "%d", new_rest);
                printf("\n\t\t    >>> Quant. de ingressos editada com sucesso. <<<");
                limpa_buffer();
                break;
            }
        case '5':
            valor = get_valor_upd("do ingresso (com casa decimal)");
            strcpy(sh->valor, valor);
            printf("\n\t\t    >>> Valor do ingresso editado com sucesso. <<<");
            limpa_buffer();
            break;
    }
}

char *del_show(void)
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
    printf("###              = = = = = = = = Excluir  Show = = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    do
    {
        printf("###              Informe o Id do show: ");
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



// File Functions
void gravar_show(Show* sh) 
{
	FILE* fp_sh;
	fp_sh = fopen("show/shows.dat", "ab");
	if (fp_sh == NULL) {
		error_screen_file_show();
	}
	fwrite(sh, sizeof(Show), 1, fp_sh);
	fclose(fp_sh);
    free(sh);
}

void pesquisa_show(void)
{
    Show *sh;
    char *id;

    id = screen_busc_show();
    sh = procura_show(id);
    print_dados_show(sh);
    free(sh);
    free(id);
}

Show *procura_show(char *id)
{
    FILE *fp;
    Show *sh;

    sh = (Show *)malloc(sizeof(Show));
    fp = fopen("show/shows.dat", "rb");
    if (fp == NULL) {
        error_screen_file_show();
    }
    while (fread(sh, sizeof(Show), 1, fp)) {
        if ((strcmp(sh->id, id) == 0) && (sh->status == 'c')) {
            fclose(fp);
            return sh;
        }
    }
    fclose(fp);
    return NULL;
}

char* retorna_valor_show(char *id)
{
    FILE *fp;
    Show *sh;

    sh = (Show *)malloc(sizeof(Show));
    fp = fopen("show/shows.dat", "rb");
    while (fread(sh, sizeof(Show), 1, fp)) {
        if ((strcmp(sh->id, id) == 0)) {
            fclose(fp);
            return sh->valor;
        }
    }
    fclose(fp);
    return sh->valor;
}

void regravar_show(Show *sh)
{
    int achou = 0;
    FILE *fp;
    Show *showLido;

    showLido = (Show *)malloc(sizeof(Show));
    fp = fopen("show/shows.dat", "r+b");
    if (fp == NULL) {
        error_screen_file_show();
    }
    while(!feof(fp)) {
        fread(showLido, sizeof(Show), 1, fp);
        if (strcmp(showLido->id, sh->id) == 0) {
            achou = 1;
            qual_campo_show(sh);
            fseek(fp, -1 * sizeof(Show), SEEK_CUR);
            fwrite(sh, sizeof(Show), 1, fp);
            break;
        }
    }
    if (!achou) {
        screen_null_id_error("Id do show");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
        limpa_buffer();
    }
    fclose(fp);
    free(showLido);
}

void remove_show(Show *sh)
{
    int achou = 0;
    FILE *fp;
    Show *shArq;
    shArq = (Show *)malloc(sizeof(Show));
    fp = fopen("show/shows.dat", "r+b");
    if (fp == NULL) {
        error_screen_file_show();
    }
    while (!feof(fp)) {
        fread(shArq, sizeof(Show), 1, fp);
        if ((strcmp(shArq->id, sh->id) == 0) && (shArq->status != 'x')) {
            achou = 1;
            shArq->status = 'x';
            fseek(fp, -1 * sizeof(Show), SEEK_CUR);
            fwrite(shArq, sizeof(Show), 1, fp);
            screen_del_ok_show();
        }
    }
    if (!achou) {
        screen_null_id_error("Id do show");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
        limpa_buffer();
    }
    fclose(fp);
    free(shArq);
}

void excluir_show(void)
{
    Show *sh;
    char *id;
    int resp; 

    sh = (Show *)malloc(sizeof(Show));
    id = del_show();
    sh = procura_show(id);
    if (sh == NULL) {
        screen_null_id_error("Id do show");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
        limpa_buffer();
    } else {
        print_dados_show_upd(sh);
        resp = certeza_del("desse show");
        if (resp) {
            printf("\n");
            sh->status = 'x';
            remove_show(sh);
            free(sh);
        } else {
            printf("\n\t\t                        Ok!\n");
            printf("\n\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
            limpa_buffer();
        }
    }
    free(id);
}

char* gera_id_show(void)
{
    FILE *fp;
    fp = fopen("show/shows.dat", "rb");
    if (fp == NULL) {
        return "1";
    }
    fseek(fp, 0, SEEK_END);
    if ((long)ftell(fp) == 0) {
        fclose(fp);
        return "1";
    }
    else {
        fseek(fp, -((long)sizeof(Show)), SEEK_END);
        Show* sh;
        sh = (Show*)malloc(sizeof(Show));
        fread(sh, sizeof(Show), 1, fp);
        int id_int = atoi(sh->id);
        int id_soma = id_int + 1;
        char id_string[5];
        snprintf(id_string, sizeof(id_string), "%d", id_soma);
        char* id = id_string;
        fclose(fp);
        return id;
    }
}



// Screen Functions
void show_menu_screen(void)
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
    printf("###              = = = = = = = = = Menu  Shows = = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    printf("###              1. Cadastrar um novo show                                  ###\n");
    printf("###              2. Pesquisar os dados de um show                           ###\n");
    printf("###              3. Editar o cadastro de um show                            ###\n");
    printf("###              4. Excluir um show do sistema                              ###\n");
    printf("###              0. Voltar ao Menu Principal                                ###\n");
    printf("###                                                                         ###\n");
    printf("###              Escolha a opção que deseja: ");
}

void print_dados_show(Show* sh)
{
    if (sh == NULL) {
        screen_null_id_error("Id do show");
    } else {
        char* new_date;
        new_date = corrige_data_add_barras(sh -> date);
        char* new_date_show;
        new_date_show = corrige_data_add_barras(sh -> data);
        system("clear || cls");
        printf("###############################################################################\n");
        printf("###                                                                         ###\n");
        printf("###            ===================================================          ###\n");
        printf("###            =============   Gestão Casa Shows   ===============          ###\n");
        printf("###            ===================================================          ###\n");
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
        printf("###                                                                         ###\n");
        printf("###              Cadastro realizado em %s às %02d:%02d.                 ###\n", new_date, sh -> hour, sh -> minute);
        printf("###                                                                         ###\n");
        printf("###              Informações do Id digitado: %s###\n", centralizar_texto(sh -> id, 31, -1));
        printf("###                                                                         ###\n");
        printf("###              Atração: %s###\n", centralizar_texto(sh -> atraction, 50, -1));
        printf("###              Data: %s###\n", centralizar_texto(new_date_show, 53, -1));
        printf("###              Hora: %s###\n", centralizar_texto(sh -> hora, 53, -1));
        printf("###              Quant. de ingressos: %s###\n", centralizar_texto(sh -> quant, 38, -1));
        printf("###              Quant. de ingressos restante: %s###\n", centralizar_texto(sh -> quant_rest, 29, -1));
        printf("###              Valor do ingresso: R$%s###\n", centralizar_texto(sh -> valor, 38, -1));
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
    }
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    limpa_buffer();
}

void print_dados_show_upd(Show* sh)
{
    if (sh == NULL) {
        screen_null_id_error("Id do show");
    } else {
        char* new_date_show;
        new_date_show = corrige_data_add_barras(sh -> data);
        system("clear || cls");
        printf("###############################################################################\n");
        printf("###                                                                         ###\n");
        printf("###            ===================================================          ###\n");
        printf("###            =============   Gestão Casa Shows   ===============          ###\n");
        printf("###            ===================================================          ###\n");
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
        printf("###                                                                         ###\n");
        printf("###              Informações do Id digitado: %s###\n", centralizar_texto(sh -> id, 31, -1));
        printf("###                                                                         ###\n");
        printf("###              Atração: %s###\n", centralizar_texto(sh -> atraction, 50, -1));
        printf("###              Data: %s###\n", centralizar_texto(new_date_show, 53, -1));
        printf("###              Hora: %s###\n", centralizar_texto(sh -> hora, 53, -1));
        printf("###              Quant. de ingressos: %s###\n", centralizar_texto(sh -> quant, 38, -1));
        printf("###              Valor do ingresso: R$%s###\n", centralizar_texto(sh -> valor, 38, -1));
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
    }
}

void print_dados_show_rep(Show* sh)
{
    if (sh == NULL) {
        printf("Erro na abertura do arquivo!\n");
        printf("Não é possível continuar este programa...\n");
        exit(1);
    } else {
        printf("### |%s", centralizar_texto(sh -> atraction, 52, 0));
        printf("|%s| ###\n", centralizar_texto(sh -> id, 16, 0));
    }
}

void screen_del_ok_show(void)
{
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###                       Show excluído com sucesso!!!                      ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    limpa_buffer();
}

void error_screen_file_show(void) 
{
	system("cls || clear");
    printf("#############################################################################\n");
	printf("###                                                                       ###\n");
	printf("###           = = = = = = = = = = = = = = = = = = = = = = = =             ###\n");
	printf("###           = = = = = = = Ops! Ocorreu um erro! = = = = = =             ###\n");
	printf("###           = = =  Não foi possível acessar o arquivo = = =             ###\n");
	printf("###           = = = = com informações  sobre os shows = = = =             ###\n");
	printf("###                                                                       ###\n");
    printf("#############################################################################\n");
	printf("\t\t    >>> Tecle ENTER para continuar! <<<");
	limpa_buffer();
}
