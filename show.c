#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "show.h"
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
                break;
            case '2':
                read_show(fulano);
                break;
            case '3':
                upd_show(fulano);
                break;
            case '4':
                del_show(fulano);
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
    printf("###              Escolha a opção que deseja:");
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
    show_val(sh);
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    getchar();
    return sh;
}

void read_show(const Show* sh)
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
    printf("###              = = = = = = = = Pesquisar  Show = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    show_id_check(sh);
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
    show_id_check(sh);
}

void del_show(Show* sh)
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
    printf("###              = = = = = = = = Excluir  Show = = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    show_id_check(sh);
}

void show_val(Show* sh)
{
    int tam = 4;
    do {
        printf("###              Atração: ");
        scanf("%s", sh -> atraction);
        limpa_buffer();
    } while (!valNome(sh -> atraction));
    do {
        printf("###              Data (dd/mm/aaaa): ");
        scanf("%s", sh -> data);
        limpa_buffer();
    } while (!valData(sh -> data));
    do {
        printf("###              Hora (hh:mm): ");
        scanf("%s", sh -> hour);
        limpa_buffer();
    } while (!val_hour(sh -> hour));
    do {
        printf("###              Quant. de ingressos (apenas numeros): ");
        scanf("%s", sh -> quant);
        limpa_buffer();
    } while (!ehdinheiro(sh -> quant));
    do {
        printf("###              Valor do ingresso: ");
        scanf("%s", sh -> valor);
        limpa_buffer();
    } while (!ehdinheiro(sh -> valor));
    do {
        printf("###              Id do show (4 dígitos): ");
        scanf("%s", sh -> id);
        limpa_buffer();
    } while (!val_id(sh -> id, tam));
}

void show_id_check(const Show* sh)
{
    char *id;
    id = (char*) malloc(5*sizeof(char));
    int tam = 4;
    char go;
    do {
        printf("###              Informe o Id do show (4 dígitos): ");
        scanf("%s", id);
        limpa_buffer();
    } while (!val_id(id, tam));
    if (strcmp(id, "1000") == 0) {
        print_dados_show(sh);
    }
    else {
        printf("###                                                                         ###\n");
        printf("###              Id do show não encontrado!                                 ###\n");
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
        scanf("%c", &go);
    }
}

void print_dados_show(const Show* sh)
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
    printf("###              Informações do Id digitado (Id):                           ###\n");
    printf("###                                                                         ###\n");
    printf("###              Atração: %s\n", sh -> atraction);
    printf("###              Data: %s\n", sh -> data);
    printf("###              Hora: %s\n", sh -> hour);
    printf("###              Quant. de ingressos: %s\n", sh -> quant);
    printf("###              Valor do ingresso: %s\n", sh -> valor);
    printf("###              Id do show: %s\n", sh -> id);
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    getchar();
}
