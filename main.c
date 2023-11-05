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
#include "aux/aux.h"
#include "util/util.h"

// Functions signature
void creat_files(const char* folder, const char* name);
char main_menu(void);
void main_menu_screen(void);
void about(void);
void dev(void);
void welcome(void);
void end(void);

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
    creat_files("atraction", "atractions.dat");
    creat_files("buy", "buys.dat");
    creat_files("client", "clients.dat");
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
    getchar();
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
    getchar();
}

void welcome(void)
{
    int height = 11;
    int width = 70;
    char message[] = "SEJA BEM-VINDO AO GESTAO CASA SHOW!";
    int messageLength = strlen(message);

    for (int i = width / 2; i >= 0; i--) {
        printf("\033[H\033[J"); // Limpa a tela

        for (int j = 0; j < height; j++) {
            for (int k = 0; k < width; k++) {
                if (k <= i || k >= width - i - 1) {
                    printf("/");
                } else if (j == height / 2) {
                    int messagePosition = (width - messageLength) / 2;
                    if (k >= messagePosition && k < messagePosition + messageLength) {
                        printf("%c", message[k - messagePosition]);
                    } else {
                        printf(" ");
                    }
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
        usleep(80000); // Espera por 0.08 segundo
    }
    printf("\n");
    printf("\t   >>> Tecle ENTER para ir ao Menu Principal... <<<");
    getchar();
} // AUTOR: LUIZ MIGUEL, FEITO COM AJUDA DO CHAT-GPT /// GIT: https://github.com/LuizMiguel4444

void end(void)
{
    int height = 11;
    int width = 70;
    char message[] = "F I M    D O    E S P E T A C U L O";
    int messageLength = strlen(message);

    for (int i = 0; i <= width / 2; i++) {
        printf("\033[H\033[J"); // Limpa a tela

        for (int j = 0; j < height; j++) {
            for (int k = 0; k < width; k++) {
                if (k <= i || k >= width - i - 1) {
                    printf("/");
                } else {
                    if (j == height / 2 && k >= (width - messageLength) / 2 && k < (width + messageLength) / 2) {
                        printf("%c", message[k - (width - messageLength) / 2]);
                    } else {
                        printf(" ");
                    }
                }
            }
            printf("\n");
        }
        usleep(80000); // Espera por 0.08 segundo

        // Limpa a linha da frase para que ela desapareça
        for (int j = 0; j < height; j++) {
            printf("\e[A\e[K"); // Move o cursor uma linha para cima e limpa a linha
        }
    }
} // AUTOR: LUIZ MIGUEL, FEITO COM AJUDA DO CHAT-GPT /// GIT: https://github.com/LuizMiguel4444

// fazer funcionar a edição por campo