#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#ifndef cores
#define cores
#define ciano(texto) printf("\33[0;36m %s \33[0m", texto)
#define cinza(texto) printf("\33[1;30m %s \33[0m", texto)
#define amarelo(texto) printf("\33[1;33m %s \33[0m", texto)
#endif

// Functions signature
int main_menu(void);
int show_menu(void);
void cred_show(void);
void read_show(void);
void upd_show(void);
void del_show(void);
void about(void);
void dev(void);
void welcome(void);
void end(void);
void print_dados(void);

// Main program
int main(void)
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    welcome();
    while (1)
    {
        int resp1 = main_menu();
        if (resp1 == 1)
        {
            int resp2 = show_menu();
            if (resp2 == 1)
            {
                cred_show();
            }
            else if (resp2 == 2)
            {
                read_show();
            }
            else if (resp2 == 3)
            {
                upd_show();
            }
            else if (resp2 == 4)
            {
                del_show();
            }
            else
            {
                system("cls || clear");
            }
        }
        else if (resp1 == 2 || resp1 == 3 || resp1 == 4)
        {
            char go;
            system("cls || clear");
            printf("Em desenvolvimento!\n");
            printf("\n");
            printf(">>> Tecle Enter para voltar ao Menu Principal... <<<");
            scanf("%c", &go);
            getchar();
        }
        else if (resp1 == 5)
        {
            about();
        }
        else if (resp1 == 6)
        {
            dev();
        }
        else
        {
            end();
            break;
        }
    }
    return 0;
}

// Functions
int main_menu(void)
{
    int resp;
    system("clear || cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Serid�                     ///\n");
    printf("///               Departamento de Computa��o e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programa��o                      ///\n");
    printf("///         Projeto -- Sistema de Gest�o para uma Casa de Shows             ///\n");
    printf("///           Developed by LuizMiguel4444 -- since Aug, 2023                ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///      ============================================================       ///\n");
    printf("///      ========= Sistema de Gest�o para uma Casa de Shows =========       ///\n");
    printf("///      ============================================================       ///\n");
    printf("///                                                                         ///\n");
    printf("///                             1. Menu Shows                               ///\n");
    printf("///                           2. Menu Ingressos --> Em desenvilvimento      ///\n");
    printf("///                           3. Menu Contratos --> Em desenvilvimento      ///\n");
    printf("///                           4. Menu Relat�rios --> Em desenvilvimento     ///\n");
    printf("///                                5. Sobre                                 ///\n");
    printf("///                              6. Cr�ditos                                ///\n");
    printf("///                                0. Sair                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///                       Escolha a op��o que deseja: ");
    scanf("%d", &resp);
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    return resp;
}

void about(void)
{
    char go;
    system("clear || cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Serid�                     ///\n");
    printf("///               Departamento de Computa��o e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programa��o                      ///\n");
    printf("///         Projeto -- Sistema de Gest�o para uma Casa de Shows             ///\n");
    printf("///           Developed by LuizMiguel4444 -- since Aug, 2023                ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///      ============================================================       ///\n");
    printf("///      ========= Sistema de Gest�o para uma Casa de Shows =========       ///\n");
    printf("///      ============================================================       ///\n");
    printf("///                                                                         ///\n");
    printf("///      Programa criado para disciplina DCT1106 -- Programa��o, com        ///\n");
    printf("///      fins de obten��o de conhecimento e nota. O programa cont�m         ///\n");
    printf("///      os principais m�dulos e funcionalidades que ser�o exigidos         ///\n");
    printf("///      na avali��o dos projetos repassados pelo professor Flavius         ///\n");
    printf("///      ao longo da disciplina.                                            ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao Menu Principal... <<<");
    scanf("%c", &go);
    getchar();
}

void dev(void)
{
    char go;
    system("clear || cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Serid�                     ///\n");
    printf("///               Departamento de Computa��o e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programa��o                      ///\n");
    printf("///         Projeto -- Sistema de Gest�o para uma Casa de Shows             ///\n");
    printf("///           Developed by LuizMiguel4444 -- since Aug, 2023                ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///      ============================================================       ///\n");
    printf("///      ========= Sistema de Gest�o para uma Casa de Shows =========       ///\n");
    printf("///      ============================================================       ///\n");
    printf("///                                                                         ///\n");
    printf("///      Este projeto foi desenvolvido por:                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///      Luiz Miguel Santos Silva                                           ///\n");
    printf("///      E-mail: luiz.santos.090@ufrn.edu.br                                ///\n");
    printf("///      Instagram: luiz__miguel10                                          ///\n");
    printf("///      GitHub: https://github.com/LuizMiguel4444/Gest�oCasaShow.git       ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao Menu Principal... <<<");
    scanf("%c", &go);
    getchar();
}

void welcome(void)
{
    char go;
    system("clear || cls");
    cinza("########                                                                ######\n");
    cinza("#########                                                            #######\n");
    cinza("       ###                                                          ###\n");
    cinza("       #####                                                      #####\n");
    cinza("       #######                                                  #######\n");
    cinza("      ##########                                              ##########\n");
    cinza("     #############                                          #############\n");
    cinza("      ##############                                      ##############\n");
    cinza("        ##############                                  ##############\n");
    cinza("          ########                                          #########\n");
    cinza("            ####                                               ####\n");
    cinza("             ##                                                 ##\n");
    ciano("                  ######                              ######\n");
    ciano("                  ########                          ########\n");
    ciano("                  ##########                      ##########\n");
    ciano("                  ############                  ############\n");
    ciano("                  ##############              ##############\n");
    ciano("                  ################          ################\n");
    ciano("                  ##################      ##################\n");
    ciano("                  ####################  ####################\n");
    ciano("                  ##########################################\n");
    ciano("                  ##########################################\n");
    ciano("                    ######################################\n");
    ciano("                     ####################################\n");
    ciano("                        ##############################\n");
    printf("\n");
    amarelo("                       SEJA BEM-VINDO AO GEST�O CASA SHOW\n");
    printf("\n");
    cinza("               ##################################################\n");
    cinza("                ##############################################\n");
    cinza("                    ######################################\n");
    cinza("                          ##########################\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para ir ao Menu Principal... <<<");
    scanf("%c", &go);
}

void end(void)
{
        char go;
    system("clear || cls");
    cinza("########                                                                ######\n");
    cinza("#########                                                            #######\n");
    cinza("       ###                                                          ###\n");
    cinza("       #####                                                      #####\n");
    cinza("       #######                                                  #######\n");
    cinza("      ##########                                              ##########\n");
    cinza("     #############                                          #############\n");
    cinza("      ##############                                      ##############\n");
    cinza("        ##############                                  ##############\n");
    cinza("          ########                                          #########\n");
    cinza("            ####                                               ####\n");
    cinza("             ##                                                 ##\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    amarelo("                                 FIM DO ESPETÁCULO\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    cinza("               ##################################################\n");
    cinza("                 ##############################################\n");
    cinza("                     ######################################\n");
    cinza("                           ##########################\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para ir ao Menu Principal... <<<");
    scanf("%c", &go);
}

int show_menu(void)
{
    int resp;
    system("clear || cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            =============   Gest�o Casa Shows   ===============          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = Menu  Shows = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastrar um novo show                                    ///\n");
    printf("///            2. Pesquisar os dados de um show                             ///\n");
    printf("///            3. Editar o cadastro de um show                              ///\n");
    printf("///            4. Excluir um show do sistema                                ///\n");
    printf("///            0. Voltar ao Menu Principal                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a op��o que deseja: ");
    scanf("%d", &resp);
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    return resp;
}

void cred_show(void)
{
    char go;
    system("clear || cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            =============   Gest�o Casa Shows   ===============          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Cadastrar  Show = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Atra��o:                                                     ///\n");
    printf("///            Data (dd/mm/aaaa):                                           ///\n");
    printf("///            Local:                                                       ///\n");
    printf("///            Quant. de ingressos (apenas numeros):                        ///\n");
    printf("///            Id destinado aos ingressos (apenas numeros):                 ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao Menu Principal... <<<");
    scanf("%c", &go);
    getchar();
}

void read_show(void)
{
    int go;
    char go1;
    system("clear || cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            =============   Gest�o Casa Shows   ===============          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Pesquisar  Show = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o Id dos ingressos do show: ");
    scanf("%d", &go);
    getchar();
    if (go != 1000)
    {
        print_dados();
    }
    else
    {
        printf("///                                                                         ///\n");
        printf("///            Id do show n�o encontrado!                                   ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao Menu Principal... <<<");
        scanf("%c", &go1);
    }
}

void upd_show(void)
{
    int go;
    char go1;
    system("clear || cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            =============   Gest�o Casa Shows   ===============          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = =  Editar Show  = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o Id dos ingressos do show: ");
    scanf("%d", &go);
    getchar();
    if (go != 1000)
    {
        print_dados();
    }
    else
    {
        printf("///                                                                         ///\n");
        printf("///            Id do show n�o encontrado!                                   ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao Menu Principal... <<<");
        scanf("%c", &go1);
    }
}

void del_show(void)
{
    int go;
    char go1;
    system("clear || cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            =============   Gest�o Casa Shows   ===============          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Excluir  Show = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o Id dos ingressos do show: ");
    scanf("%d", &go);
    getchar();
    if (go != 1000)
    {
        print_dados();
    }
    else
    {
        printf("///                                                                         ///\n");
        printf("///            Id do show n�o encontrado!                                   ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao Menu Principal... <<<");
        scanf("%c", &go1);
    }
}

void print_dados(void)
{
    char go;
    system("cls || clear");
    printf("\n");
    printf("Mostra os dados do show...\n");
    printf("\n");
    printf("Em desenvolvimento...\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao Menu Principal... <<<");
    scanf("%c", &go);
}
