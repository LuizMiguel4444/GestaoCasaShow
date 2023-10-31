#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "show.h"
#include "aux.h"
#include "util.h"

void modulo_show(void)
{
    Show* fulano;
    setlocale(LC_ALL, "Portuguese_Brazil");
    int resp;
    do
    {
        resp = show_menu();
        switch (resp)
        {
            case '1':
                fulano = cred_show();
                gravar_show(fulano);
                break;
            case '2':
                pesquisa_show();
                break;
            case '3':
                upd_show(fulano);
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
    } while (!ehDigitoMax(resp[0], '4') || !val_entrada(resp));
    return resp[0];
}

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
    getchar();
    return sh;
}

char *screen_read_show(void)
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
        printf("###              Informe o Id do show (4 dígitos): ");
        scanf("%s", id);
        limpa_buffer();
    } while (!val_id(id, 4));
    printf("###                                                                         ###\n");
    return id;
}

void upd_show(Show* sh)
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
    printf("###              = = = = = = = =  Editar Show  = = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    // show_id_check(sh);
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
        printf("###              Informe o Id do show (4 dígitos): ");
        scanf("%s", id);
        limpa_buffer();
    } while (!val_id(id, 4));
    printf("###                                                                         ###\n");
    return id;
}

void show_inputs(Show* sh)
{
    get_nome(sh -> atraction, "a atração");
    get_data(sh -> data);
    get_hour(sh -> hour);
    get_quant_cad(sh -> quant, "ingressos");
    get_valor(sh -> valor, "do ingresso (com casa decimal)");
    get_id(sh -> id, "o show (4 dígitos)");
    sh -> status = 'c';
}

Show *procura_show(char *id)
{
    FILE *fp;
    Show *sh;

    sh = (Show *)malloc(sizeof(Show));
    fp = fopen("shows.dat", "rb");
    if (fp == NULL)
    {
        error_screen_file_show();
    }
    while (fread(sh, sizeof(Show), 1, fp))
    {
        if ((strcmp(sh->id, id) == 0) && (sh->status == 'c'))
        {
            fclose(fp);
            return sh;
        }
    }
    fclose(fp);
    return NULL;
}

void print_dados_show(Show* sh)
{
    if (sh == NULL) {
        screen_null_id_error("do show");
    } else {
        system("clear || cls");
        printf("###############################################################################\n");
        printf("###                                                                         ###\n");
        printf("###            ===================================================          ###\n");
        printf("###            =============   Gestão Casa Shows   ===============          ###\n");
        printf("###            ===================================================          ###\n");
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
        printf("###                                                                         ###\n");
        printf("###              Informações do Id digitado (%s):                         ###\n", sh -> id);
        printf("###                                                                         ###\n");
        printf("###              Atração: %s\n", sh -> atraction);
        printf("###              Data: %s\n", sh -> data);
        printf("###              Hora: %s\n", sh -> hour);
        printf("###              Quant. de ingressos: %s\n", sh -> quant);
        printf("###              Valor do ingresso: %s\n", sh -> valor);
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
    }
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    getchar();
}

void gravar_show(Show* sh) 
{
	FILE* fp_sh;
	fp_sh = fopen("shows.dat", "ab");
	if (fp_sh == NULL) {
		error_screen_file_show();
	}
	fwrite(sh, sizeof(Show), 1, fp_sh);
	fclose(fp_sh);
    free(sh);
}

void error_screen_file_show(void) 
{
	system("cls || clear");
    printf("#############################################################################\n");
	printf("###                                                                       ###\n");
	printf("###           = = = = = = = = = = = = = = = = = = = = = = = =             ###\n");
	printf("###           = = = = = = = Ops!  Ocorreu um erro = = = = = =             ###\n");
	printf("###           = = =  Não foi possível acessar o arquivo = = =             ###\n");
	printf("###           = = = = com informações  sobre os shows = = = =             ###\n");
	printf("###                                                                       ###\n");
    printf("#############################################################################\n");
	printf("\t\t>>> Tecle ENTER para continuar! <<<");
	getchar();
}

void pesquisa_show(void)
{
    Show *sh;
    char *id;

    id = screen_read_show();
    sh = procura_show(id);
    print_dados_show(sh);
    free(sh);
    free(id);
}

void remove_show(Show *sh)
{
    int achou = 0;
    FILE *fp;
    Show *shArq;
    shArq = (Show *)malloc(sizeof(Show));
    fp = fopen("shows.dat", "r+b");
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
        screen_null_id_error("do show");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
        getchar();
    }
    fclose(fp);
    free(shArq);
}

void excluir_show(void)
{
    Show *sh;
    char *id;

    sh = (Show *)malloc(sizeof(Show));
    id = del_show();
    sh = procura_show(id);
    if (sh == NULL) {
        screen_null_id_error("do show");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
        getchar();
    } else {
        sh->status = 'x';
        remove_show(sh);
        free(sh);
    }
    free(id);
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
    getchar();
}
