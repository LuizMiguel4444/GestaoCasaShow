#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "atraction.h"
#include "../aux/aux.h"
#include "../util/util.h"

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
            upd_atraction(atracao);
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
    } while (!ehDigitoMax(resp[0], '4') || !val_entrada(resp));
    return resp[0];
}

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
    getchar();
    return atr;
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
    do
    {
        printf("###              Informe o Id da atração (4 dígitos): ");
        scanf("%s", id);
        limpa_buffer();
    } while (!val_id(id, 4));
    printf("###                                                                         ###\n");
    return id;
}

void upd_atraction(Atraction *atr)
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
    printf("###              = = = = = = = = Editar  Atração = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    // atraction_id_check(atr);
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
        printf("###              Informe o Id da atração (4 dígitos): ");
        scanf("%s", id);
        limpa_buffer();
    } while (!val_id(id, 4));
    printf("###                                                                         ###\n");
    return id;
}

void atraction_inputs(Atraction *atr)
{
    get_nome(atr->nome, "a atração");
    get_cache(atr->cache, "a atração (com casa decimal)");
    get_email(atr->email, "e contato");
    get_num(atr->num, "e contato (com DDD)");
    get_id(atr->id, "a atração (4 dígitos)");
    atr->status = 'c';
}

Atraction *procura_atraction(char *id)
{
    FILE *fp;
    Atraction *atr;

    atr = (Atraction *)malloc(sizeof(Atraction));
    fp = fopen("atractions.dat", "rb");
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

void print_dados_atraction(Atraction *atr)
{
    if (atr == NULL)
    {
        screen_null_id_error("da atração");
    }
    else
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
        printf("###              Informações do Id digitado (%s):                         ###\n", atr->id);
        printf("###                                                                         ###\n");
        printf("###              Nome da atração: %s\n", atr->nome);
        printf("###              Valor do cachê da atração: %s\n", atr->cache);
        printf("###              Email de contato da atração: %s\n", atr->email);
        printf("###              Número de contato da atração: %s\n", atr->num);
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
    }
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    getchar();
}

void gravar_atr(Atraction *atr)
{
    FILE *fp_atr;
    fp_atr = fopen("atractions.dat", "ab");
    if (fp_atr == NULL)
    {
        error_screen_file_atr();
    }
    fwrite(atr, sizeof(Atraction), 1, fp_atr);
    fclose(fp_atr);
    free(atr);
}

void error_screen_file_atr(void)
{
    system("cls || clear");
    printf("#############################################################################\n");
    printf("###                                                                       ###\n");
    printf("###           = = = = = = = = = = = = = = = = = = = = = = = =             ###\n");
    printf("###           = = = = = = = Ops!  Ocorreu um erro = = = = = =             ###\n");
    printf("###           = = =  Não foi possível acessar o arquivo = = =             ###\n");
    printf("###           = = =  com informações sobre as atrações  = = =             ###\n");
    printf("###                                                                       ###\n");
    printf("#############################################################################\n");
    printf("\t\t>>> Tecle ENTER para continuar! <<<");
    getchar();
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

void remove_atr(Atraction *atr)
{
    int achou = 0;
    FILE *fp;
    Atraction *atrArq;
    atrArq = (Atraction *)malloc(sizeof(Atraction));
    fp = fopen("atractions.dat", "r+b");
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
        screen_null_id_error("da atração");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
        getchar();
    }
    fclose(fp);
    free(atrArq);
}

void excluir_atr(void)
{
    Atraction *atr;
    char *id;

    atr = (Atraction *)malloc(sizeof(Atraction));
    id = del_atraction();
    atr = procura_atraction(id);
    if (atr == NULL) {
        screen_null_id_error("da atração");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
        getchar();
    } else {
        atr->status = 'x';
        remove_atr(atr);
        free(atr);
    }
    free(id);
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
    getchar();
}
