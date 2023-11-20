#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include "../atraction/atraction.h"
#include "client.h"
#include "../auxiliar/auxiliar.h"
#include "../util/util.h"



// Functions
void modulo_client(void)
{
    Client* cliente;
    setlocale(LC_ALL, "Portuguese_Brazil");
    int resp;
    do
    {
        resp = client_menu();
        switch (resp)
        {
            case '1':
                cliente = cred_client();
                gravar_client(cliente);
                break;
            case '2':
                pesquisa_cli();
                break;
            case '3':
                update_cli();
                break;
            case '4':
                excluir_cli();
                break;
            case '0':
                system("cls || clear");
                break;
        }
    } while (resp != '0');
}

char client_menu(void)
{
    char resp[256];
    do {
        client_menu_screen();
        scanf("%s", resp);
        limpa_buffer();
        if (!ehDigitoMax(resp[0], '4')  || !val_entrada(resp)) {
            screen_error_input();
            limpa_linha();
        }
    } while (!ehDigitoMax(resp[0], '4') || !val_entrada(resp));
    return resp[0];
}

Client *cred_client(void)
{
    Client *cli;
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
    printf("###              = = = = = = =  Cadastrar Cliente  = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    client_inputs(cli);
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    limpa_buffer();
    return cli;
}

void client_inputs(Client* cli)
{
    char* nome = get_nome("o cliente");
    strcpy(cli->nome, nome);
    do {
        char* cpf = get_cpf();
        strcpy(cli->cpf, cpf);
        if (!procura_cpf_client(cli->cpf)) {
            if (strcmp(cli->cpf, "000") == 0) {
                screen_error_input_id("CPF");
                limpa_linha(); limpa_linha(); limpa_linha();
            } else {
                screen_error_input_id("CPF");
                limpa_linha(); limpa_linha(); limpa_linha();
            }
        }
    } while (!procura_cpf_client(cli->cpf));
    char* email = get_email("o cliente");
    strcpy(cli->email, email);
    char* num = get_num("o cliente", 40);
    strcpy(cli->num, num);
    cli -> status = 'c';
    get_data_hour_cli(cli);
}

void get_data_hour_cli(Client *cli)
{
    time_t currentTime;
    time(&currentTime);
    struct tm *timeInfo;
    timeInfo = localtime(&currentTime);
    cli->day = timeInfo->tm_mday;
    cli->month = timeInfo->tm_mon + 1;
    cli->year = timeInfo->tm_year + 1900;
    cli->hour = timeInfo->tm_hour;
    cli->minute = timeInfo->tm_min;
}

char *screen_busc_client(void)
{
    char *cpf;
    cpf = (char *)malloc(5 * sizeof(char));
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
    printf("###              = = = = = = =  Pesquisar Cliente  = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    do {
        printf("###              Informe o CPF do cliente: ");
        scanf("%s", cpf);
        limpa_buffer();
        if (!validarCPF(cpf)) {
            screen_error_input();
            limpa_linha(); limpa_linha(); limpa_linha();
        }
    } while (!validarCPF(cpf));
    printf("###                                                                         ###\n");
    return cpf;
}

char *screen_upd_client(void)
{
    char *cpf;
    cpf = (char *)malloc(5 * sizeof(char));
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
    printf("###              = = = = = = = = Editar  Cliente = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    do {
        printf("###              Informe o CPF do cliente: ");
        scanf("%s", cpf);
        limpa_buffer();
        if (!validarCPF(cpf)) {
            screen_error_input();
            limpa_linha(); limpa_linha(); limpa_linha();
        }
    } while (!validarCPF(cpf));
    printf("###                                                                         ###\n");
    return cpf;
}

void update_cli(void)
{
    Client *cli;
    char *cpf;
    int resp;

    cpf = screen_upd_client();
    cli = procura_client(cpf);
    if (cli == NULL) {
        screen_null_cpf_error();
        printf("\n\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
        limpa_buffer();
    }
    else {
        print_dados_client_upd(cli);
        resp = certeza_upd("desse cliente");
        if (resp) {
            regravar_cli(cli);
        } else {
            printf("\n\t\t                        Ok!\n");
            printf("\n\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
            limpa_buffer();
        }
    }
    free(cpf);
    free(cli);
}

void qual_campo_cli(Client *cli)
{
    char resp[256];
    printf("\n\t\t\t\t    1 - Nome\n");
    printf("\t\t\t\t    2 - Email\n");
    printf("\t\t\t\t    3 - Número\n");
    do {
        printf("\n\t\t    Digite o número do campo que deseja editar: ");
        scanf("%s", resp);
        limpa_buffer();
        if (!ehDigitoMax(resp[0], '3')  || !val_entrada(resp)) {
            screen_error_input_resp();
            limpa_linha(); limpa_linha(); limpa_linha(); limpa_linha();
        }
    } while (!ehDigitoMax(resp[0], '3')  || !val_entrada(resp));
    switch (resp[0]) {
        case '1':
            char* nome = get_nome_upd("do cliente");
            strcpy(cli->nome, nome);
            printf("\n\t\t    >>> Nome do cliente editado com sucesso. <<<");
            limpa_buffer();
            break;
        case '2':
            char* email = get_email_upd("de contato");
            strcpy(cli->email, email);
            printf("\n\t\t    >>> Email do cliente editado com sucesso. <<<");
            limpa_buffer();
            break;
        case '3':
            char* num = get_num_upd("de contato");
            strcpy(cli->num, num);
            printf("\n\t\t    >>> Número do cliente editado com sucesso. <<<");
            limpa_buffer();
            break;
    }
}

char *del_client(void)
{
    char *cpf;
    cpf = (char *)malloc(5 * sizeof(char));
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
    printf("###              = = = = = = =  Excluir Cliente  = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    do {
        printf("###              Informe o CPF do cliente: ");
        scanf("%s", cpf);
        limpa_buffer();
        if (!validarCPF(cpf)) {
            screen_error_input();
            limpa_linha(); limpa_linha(); limpa_linha();
        }
    } while (!validarCPF(cpf));
    printf("###                                                                         ###\n");
    return cpf;
}



// File Functions
void gravar_client(Client* cli)
{
	FILE* fp_cli;
	fp_cli = fopen("client/clients.dat", "ab");
	if (fp_cli == NULL) {
		error_screen_file_cli();
	}
	fwrite(cli, sizeof(Client), 1, fp_cli);
	fclose(fp_cli);
    free(cli);
}

void pesquisa_cli(void)
{
    Client *cli;
    char *cpf;

    cpf = screen_busc_client();
    cli = procura_client(cpf);
    print_dados_client(cli);
    free(cli);
    free(cpf);
}

Client *procura_client(char *cpf)
{
    FILE *fp;
    Client *cli;

    cli = (Client *)malloc(sizeof(Client));
    fp = fopen("client/clients.dat", "rb");
    if (fp == NULL) {
        error_screen_file_cli();
    }
    while (fread(cli, sizeof(Client), 1, fp)) {
        if ((strcmp(cli->cpf, cpf) == 0) && (cli->status == 'c')) {
            fclose(fp);
            return cli;
        }
    }
    fclose(fp);
    return NULL;
}

int procura_cpf_client(char *cpf)
{
    FILE *fp;
    Client *cli;

    cli = (Client *)malloc(sizeof(Client));
    fp = fopen("client/clients.dat", "rb");
    while (fread(cli, sizeof(Client), 1, fp)) {
        if ((strcmp(cli->cpf, cpf) == 0) && cli->status == 'c') {
            fclose(fp);
            return 0;
        }
    }
    fclose(fp);
    return 1;
}

int procura_cpf_client_fantasm(char *cpf)
{
    FILE *fp;
    Client *cli;

    cli = (Client *)malloc(sizeof(Client));
    fp = fopen("client/clients.dat", "rb");
    while (fread(cli, sizeof(Client), 1, fp)) {
        if ((strcmp(cli->cpf, cpf) == 0) || (strcmp(cli->cpf, "000") == 0)) {
            fclose(fp);
            return 0;
        }
    }
    fclose(fp);
    return 1;
}

void regravar_cli(Client *cli)
{
    int achou = 0;
    FILE *fp;
    Client *cliLido;

    cliLido = (Client *)malloc(sizeof(Client));
    fp = fopen("client/clients.dat", "r+b");
    if (fp == NULL) {
        error_screen_file_cli();
    }
    while(!feof(fp)) {
        fread(cliLido, sizeof(Client), 1, fp);
        if (strcmp(cliLido->cpf, cli->cpf) == 0) {
            achou = 1;
            qual_campo_cli(cli);
            fseek(fp, -1 * sizeof(Client), SEEK_CUR);
            fwrite(cli, sizeof(Client), 1, fp);
            break;
        }
    }
    if (!achou) {
        screen_null_id_error("CPF do cliente");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
        limpa_buffer();
    }
    fclose(fp);
    free(cliLido);
}

void remove_cli(Client *cli)
{
    int achou = 0;
    FILE *fp;
    Client *cliArq;
    cliArq = (Client *)malloc(sizeof(Client));
    fp = fopen("client/clients.dat", "r+b");
    if (fp == NULL) {
        error_screen_file_cli();
    }
    while (!feof(fp)) {
        fread(cliArq, sizeof(Client), 1, fp);
        if ((strcmp(cliArq->cpf, cli->cpf) == 0) && (strcmp(cliArq->cpf, "000") == 0)) {
            achou = 1;
            screen_del_cli_block();
        }
        else if ((strcmp(cliArq->cpf, cli->cpf) == 0) && (cliArq->status != 'x')) {
            achou = 1;
            cliArq->status = 'x';
            fseek(fp, -1 * sizeof(Client), SEEK_CUR);
            fwrite(cliArq, sizeof(Client), 1, fp);
            screen_del_ok_cli();
        }
    }
    if (!achou) {
        screen_null_id_error("CPF do cliente");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
        limpa_buffer();
    }
    fclose(fp);
    free(cliArq);
}

void excluir_cli(void)
{
    Client *cli;
    char *cpf;
    int resp;

    cli = (Client *)malloc(sizeof(Client));
    cpf = del_client();
    cli = procura_client(cpf);
    if (cli == NULL) {
        screen_null_cpf_error();
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
        limpa_buffer();
    } else {
        print_dados_client_upd(cli);
        resp = certeza_del("desse cliente");
        if (resp) {
            printf("\n");
            cli->status = 'x';
            remove_cli(cli);
            free(cli);
        } else {
            printf("\n\t\t                        Ok!\n");
            printf("\n\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
            limpa_buffer();
        }
    }
    free(cpf);
}



// Screen Functions
void client_menu_screen(void)
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
    printf("###              = = = = = = = =  Menu Clientes  = = = = = = = =            ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    printf("###              1. Cadastrar um novo cliente                               ###\n");
    printf("###              2. Pesquisar os dados de um cliente                        ###\n");
    printf("###              3. Editar o cadastro de um cliente                         ###\n");
    printf("###              4. Excluir um cliente do sistema                           ###\n");
    printf("###              0. Voltar ao menu principal                                ###\n");
    printf("###                                                                         ###\n");
    printf("###              Escolha a opção que deseja: ");
}

void print_dados_client(Client* cli)
{
    if (cli == NULL) {
        screen_null_id_error("CPF do cliente");
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
        printf("###              Cadastro realizado em %02d/%02d/%d às %02d:%02d.                 ###\n", cli->day, cli->month, cli->year, cli->hour, cli->minute);
        printf("###                                                                         ###\n");
        printf("###              Informações do CPF digitado:                               ###\n");
        printf("###                                                                         ###\n");
        printf("###              Nome do cliente: %s###\n", centralizar_texto(cli -> nome, 42, -1));
        printf("###              CPF do cliente: %s###\n", centralizar_texto(cli -> cpf, 43, -1));
        printf("###              Email do cliente: %s###\n", centralizar_texto(cli -> email, 41, -1));
        printf("###              Número do cliente: %s###\n", centralizar_texto(cli -> num, 40, -1));
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
    }
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    limpa_buffer();
}

void print_dados_client_upd(Client* cli)
{
    if (cli == NULL) {
        screen_null_id_error("CPF do cliente");
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
        printf("###              Informações do CPF digitado:                               ###\n");
        printf("###                                                                         ###\n");
        printf("###              Nome do cliente: %s###\n", centralizar_texto(cli -> nome, 42, -1));
        printf("###              CPF do cliente: %s###\n", centralizar_texto(cli -> cpf, 43, -1));
        printf("###              Email do cliente: %s###\n", centralizar_texto(cli -> email, 41, -1));
        printf("###              Número do cliente: %s###\n", centralizar_texto(cli -> num, 40, -1));
        printf("###                                                                         ###\n");
        printf("###############################################################################\n");
    }
}

void print_dados_client_rep(Client* cli)
{
    if (cli == NULL) {
        printf("Erro na abertura do arquivo!\n");
        printf("Não é possível continuar este programa...\n");
        exit(1);
    } else {
        printf("### |%s", centralizar_texto(cli -> nome, 47, 0));
        printf("| %s| ###\n", centralizar_texto(cli -> cpf, 20, 0));
    }
}

void screen_del_ok_cli(void)
{
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###                     Cliente excluído com sucesso!!!                     ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    limpa_buffer();
}

void screen_del_cli_block(void)
{
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###                 Esse cliente não pode ser excluído!!!                   ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    limpa_buffer();
}

void screen_null_cpf_error(void)
{
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                       CPF do cliente não encontrado\n");
    printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
}

void error_screen_file_cli(void)
{
	system("cls || clear");
    printf("#############################################################################\n");
	printf("###                                                                       ###\n");
	printf("###           = = = = = = = = = = = = = = = = = = = = = = = =             ###\n");
	printf("###           = = = = = = = Ops! Ocorreu um erro! = = = = = =             ###\n");
	printf("###           = = =  Não foi possível acessar o arquivo = = =             ###\n");
	printf("###           = = =  com informações sobre os clientes  = = =             ###\n");
	printf("###                                                                       ###\n");
    printf("#############################################################################\n");
	printf("\t\t    >>> Tecle ENTER para continuar! <<<");
	limpa_buffer();
}
