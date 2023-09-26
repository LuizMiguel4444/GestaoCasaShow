#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "show.h"
#include "atraction.h"
#include "client.h"
#include "buy.h"
#include "report.h"
#include "util.h"
#ifndef cores
#define cores
#define ciano(texto) printf("\33[1;36m %s \33[0m", texto)
#define amarelo(texto) printf("\33[1;33m %s \33[0m", texto)
#endif

// Functions signature
int main_menu(void);
void about(void);
void dev(void);
void welcome(void);
void end(void);

// Main program
int main(void)
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    welcome();
    int resp1;
    do
    {
        resp1 = main_menu(); printf("<%d>\n", resp1); getchar();
        switch (resp1)
        {
            case 1:
                modulo_show();
                break;
            case 2:
                modulo_atraction();
                break;
            case 3:
                modulo_client();
                break;
            case 4:
                modulo_buy();
                break;
            case 5:
                modulo_report();
                break;
            case 6:
                about();
                break;
            case 7:
                dev();
                break;
            case 0:
                end();
                break;
        }
    } while (resp1 != 0); printf("ok"); 
    return 0;
}

// Functions
int main_menu(void)
{
    int resp;
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
    do {
        printf("###                       Escolha a opção que deseja: ");
        scanf("%d", &resp); printf("<%d>\n", resp);
        getchar();
        if (ehDigito(resp)){
            printf("###                                                                         ###\n");
            printf("###############################################################################\n");
        } else {
            printf("###                       Escolha a opção que deseja: ");
            scanf("%d", &resp); printf("<%d>\n", resp);
            getchar();
        }
    } while (!ehDigito(resp));
    return resp;
}

void about(void)
{
    char go;
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
    scanf("%c", &go);
    getchar();
}

void dev(void)
{
    char go;
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
    scanf("%c", &go);
    getchar();
}

void welcome(void)
{
    char go;
    system("clear || cls");
    printf("########                                                               ######\n");
    printf("#########                                                             #######\n");
    printf("       ###                                                           ###\n");
    printf("       #####                                                       #####\n");
    printf("       #######                                                   #######\n");
    printf("      ##########                                               ##########\n");
    printf("     #############                                           #############\n");
    printf("      ##############                                       ##############\n");
    printf("        ##############                                   ##############\n");
    printf("          ########                                           #########\n");
    printf("            ####                                                ####\n");
    printf("             ##                                                  ##\n");
    ciano("                  ######                              ######\n");
    ciano("                 ########                          ########\n");
    ciano("                 ##########                      ##########\n");
    ciano("                 ############                  ############\n");
    ciano("                 ##############              ##############\n");
    ciano("                 ################          ################\n");
    ciano("                 ##################      ##################\n");
    ciano("                 ####################  ####################\n");
    ciano("                 ##########################################\n");
    ciano("                 ##########################################\n");
    ciano("                   ######################################\n");
    ciano("                    ####################################\n");
    ciano("                       ##############################\n");
    printf("\n");
    amarelo("                      SEJA BEM-VINDO AO GESTÃO CASA SHOW\n");
    printf("\n");
    printf("               ##################################################\n");
    printf("                ##############################################\n");
    printf("                    ######################################\n");
    printf("                          ##########################\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para ir ao Menu Principal... <<<");
    scanf("%c", &go);
}

void end(void)
{
    system("clear || cls");
    printf("########                                                             ######\n");
    printf("#########                                                           #######\n");
    printf("       ###                                                         ###\n");
    printf("       #####                                                     #####\n");
    printf("       #######                                                 #######\n");
    printf("      ##########                                             ##########\n");
    printf("     #############                                         #############\n");
    printf("      ##############                                     ##############\n");
    printf("        ##############                                 ##############\n");
    printf("          ########                                         #########\n");
    printf("            ####                                              ####\n");
    printf("             ##                                                ##\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    amarelo("                             FIM DO ESPETÁCULO\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("             ##################################################\n");
    printf("               ##############################################\n");
    printf("                   ######################################\n");
    printf("                         ##########################\n");
}
