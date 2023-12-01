#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>
#include "show/show.h"
#include "atraction/atraction.h"
#include "client/client.h"
#include "buy/buy.h"
#include "report/report.h"
#include "auxiliar/auxiliar.h"
#include "util/util.h"



// Functions signature
void creat_files(const char* folder, const char* name);
void welcome(void);
void main_menu_screen(void);
char main_menu(void);
void about(void);
void dev(void);
void end(void);
Client *cria_cliente_fantasma(void);
void dados_fantasma(Client* cli);



// File creation
void creat_files(const char* folder, const char* name)
{
    FILE *fp;
    char path[256];
    snprintf(path, sizeof(path), "%s/%s", folder, name);
    fp = fopen(path, "rb");

    if (fp == NULL) {
        fp = fopen(path, "wb");
        if (fp == NULL) {
            printf("Erro ao criar arquivos.\n");
            printf("O programa será encerrado!");
            exit(1);
        }
        fclose(fp);
    }
}



// Main program
int main(void)
{
    Client* cliente;
    creat_files("atraction", "atractions.dat");
    creat_files("buy", "buys.dat");
    creat_files("client", "clients.dat");
    cliente = cria_cliente_fantasma();
    gravar_client(cliente);
    creat_files("show", "shows.dat");
    setlocale(LC_ALL, "Portuguese_Brazil");
    welcome();
    char resp;
    do
    {
        resp = main_menu();
        switch (resp)
        {
            case '1':
                modulo_show();
                break;
            case '2':
                modulo_atraction();
                break;
            case '3':
                modulo_client();
                break;
            case '4':
                modulo_buy();
                break;
            case '5':
                modulo_report();
                break;
            case '6':
                about();
                break;
            case '7':
                dev();
                break;
            case '0':
                end();
                break;
        }
    } while (resp != '0'); 
    return 0;
}



// Functions
void welcome(void)
{
    int height = 11;
    int width = 70;
    char message[] = "SEJA BEM-VINDO AO GESTAO CASA SHOW!";
    int messageLength = strlen(message);

    for (int i = width / 2; i >= 0; i--) { // Loop que controla o efeito de animação.
        printf("\033[H\033[J"); // Limpa a tela

        for (int j = 0; j < height; j++) { // Loop para percorrer as linhas da "janela".
            for (int k = 0; k < width; k++) { // Loop para percorrer as colunas da "janela".
                if (k <= i || k >= width - i - 1) { // imprime o caractere '/' para criar uma borda.
                    printf("/");
                } else if (j == height / 2) { // Se j estiver na metade da altura da "janela", então é a linha onde a mensagem deve ser exibida.
                    int messagePosition = (width - messageLength) / 2; // Calcula a posição inicial da mensagem para centralizá-la na "janela".
                    if (k >= messagePosition && k < messagePosition + messageLength) { // Se k estiver dentro da faixa onde a mensagem deve ser exibida:
                        printf("%c", message[k - messagePosition]); // Imprime o caractere correspondente na mensagem.
                    } else { // Caso contrário, imprime um espaço em branco para preencher o espaço vazio.
                        printf(" ");
                    }
                } else { // Para todas as outras linhas, imprime espaços em branco para preencher a "janela".
                    printf(" ");
                }
            }
            printf("\n"); // Ao final de cada linha, imprime uma quebra de linha.
        }
        usleep(80000); // Espera por 0.08 segundo antes de atualizar a próxima animação.
    }
    printf("\n");
    printf("\t   >>> Tecle ENTER para ir ao Menu Principal... <<<");
    limpa_buffer();
} // AUTOR: LUIZ MIGUEL, FEITO COM AJUDA DO CHAT-GPT /// GIT: https://github.com/LuizMiguel4444

void main_menu_screen(void)
{
    system("clear || cls");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###      ============================================================       ###\n");
    printf("###      ========= Sistema de Gestão para uma Casa de Shows =========       ###\n");
    printf("###      ============================================================       ###\n");
    printf("###                                                                         ###\n");
    printf("###                             1. Menu Shows                               ###\n");
    printf("###                            2. Menu Atrações                             ###\n");
    printf("###                            3. Menu Clientes                             ###\n");
    printf("###                             4. Menu Vendas                              ###\n");
    printf("###                           5. Menu Relatórios                            ###\n");
    printf("###                                6. Sobre                                 ###\n");
    printf("###                              7. Créditos                                ###\n");
    printf("###                                0. Sair                                  ###\n");
    printf("###                                                                         ###\n");
    printf("###                       Escolha a opção que deseja: ");
}

char main_menu(void)
{
    char resp[256];
    do {
        main_menu_screen();
        scanf("%s", resp);
        limpa_buffer();
        if (!ehDigitoMax(resp[0], '7')  || !val_entrada(resp)) {
            screen_error_input();
            limpa_linha();
        }
    } while (!ehDigitoMax(resp[0], '7')  || !val_entrada(resp));
    return resp[0];
}

void about(void)
{
    system("clear || cls");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###      ============================================================       ###\n");
    printf("###      ========= Sistema de Gestão para uma Casa de Shows =========       ###\n");
    printf("###      ============================================================       ###\n");
    printf("###                                                                         ###\n");
    printf("###      Programa criado para disciplina DCT1106 -- Programação, com        ###\n");
    printf("###      fins de obtenção de conhecimento e nota. O programa contém         ###\n");
    printf("###      os principais módulos e funcionalidades que serão exigidos         ###\n");
    printf("###      na avaliação dos projetos repassados pelo professor Flavius        ###\n");
    printf("###      ao longo da disciplina.                                            ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao Menu Principal... <<<");
    limpa_buffer();
}

void dev(void)
{
    system("clear || cls");
    printf("###############################################################################\n");
    printf("###                                                                         ###\n");
    printf("###      ============================================================       ###\n");
    printf("###      ========= Sistema de Gestão para uma Casa de Shows =========       ###\n");
    printf("###      ============================================================       ###\n");
    printf("###                                                                         ###\n");
    printf("###      Este projeto foi desenvolvido por:                                 ###\n");
    printf("###      Luiz Miguel Santos Silva                                           ###\n");
    printf("###                                                                         ###\n");
    printf("###      Contatos:                                                          ###\n");
    printf("###      E-mail: luiz.santos.090@ufrn.edu.br                                ###\n");
    printf("###      Instagram: luiz__miguel10                                          ###\n");
    printf("###      GitHub: https://github.com/LuizMiguel4444                          ###\n");
    printf("###                                                                         ###\n");
    printf("###############################################################################\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao Menu Principal... <<<");
    limpa_buffer();
}

void end(void)
{
    int height = 11;
    int width = 70;
    char message[] = "F I M    D O    E S P E T A C U L O";
    int messageLength = strlen(message);

    for (int i = 0; i <= width / 2; i++) { // Loop que controla o efeito de animação.
        printf("\033[H\033[J"); // Limpa a tela

        for (int j = 0; j < height; j++) { // Loop para percorrer as linhas da "janela".
            for (int k = 0; k < width; k++) { // Loop para percorrer as colunas da "janela".
                if (k <= i) {
                    printf("\\"); // Imprime "\" no lado esquerdo.
                } else if (k >= width - i - 1) {
                    printf("/"); // Imprime "/" no lado direito.
                } else {
                    if (j == height / 2 && k >= (width - messageLength) / 2 && k < (width + messageLength) / 2) {
                        // Se j estiver na metade da altura da "janela" e k estiver na faixa onde a mensagem deve ser exibida:
                        // Imprime o caractere correspondente na mensagem.
                        printf("%c", message[k - (width - messageLength) / 2]);
                    } else { // Caso contrário, imprime um espaço em branco para preencher o espaço vazio.
                        printf(" ");
                    }
                }
            }
            printf("\n"); // Ao final de cada linha, imprime uma quebra de linha.
        }
        usleep(80000); // Espera por 0.08 segundo antes de atualizar a próxima animação.

        for (int j = 0; j < height; j++) { // Limpa a linha da frase para que ela desapareça.
            printf("\e[A\e[K"); // Move o cursor uma linha para cima e limpa a linha.
        }
    }
} // AUTOR: LUIZ MIGUEL, FEITO COM AJUDA DO CHAT-GPT /// GIT: https://github.com/LuizMiguel4444

Client *cria_cliente_fantasma(void)
{
    Client *cli;
    cli = (Client*) malloc(sizeof(Client) + 1);
    dados_fantasma(cli);
    return cli;
}

void dados_fantasma(Client* cli)
{
    char* nome = "null";
    strcpy(cli->nome, nome);
    char* cpf = "000";
    strcpy(cli->cpf, cpf);
    char* email = "null@null.null";
    strcpy(cli->email, email);
    char* num = "000000000";
    strcpy(cli->num, num);
    cli -> status = 'c';
    get_data_hour_cli(cli);
}
