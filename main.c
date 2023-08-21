#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Functions signature
int main_menu();
int show_menu();
char cred_show();
char read_show();
char upd_show();
char del_show();
void about(void);
void dev(void);
void welcome(void);
void end(void);

// Functions
int main_menu()
{
    int resp;
    system("clear || cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
    printf("///               Departamento de Computação e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
    printf("///         Projeto -- Sistema de Gestão para uma Casa de Shows             ///\n");
    printf("///           Developed by LuizMiguel4444 -- since Aug, 2023                ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///      ============================================================       ///\n");
    printf("///      ========= Sistema de Gestão para uma Casa de Shows =========       ///\n");
    printf("///      ============================================================       ///\n");
    printf("///                                                                         ///\n");
    printf("///                             1. Menu Shows                               ///\n");
    printf("///                           2. Menu Ingressos --> Em desenvilvimento      ///\n");
    printf("///                           3. Menu FeedBacks --> Em desenvilvimento      ///\n");
    printf("///                           4. Menu Relatórios --> Em desenvilvimento     ///\n");
    printf("///                                5. Sobre                                 ///\n");
    printf("///                              6. Créditos                                ///\n");
    printf("///                                0. Sair                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///                       Escolha a opção que deseja: ");
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
    printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
    printf("///               Departamento de Computação e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
    printf("///         Projeto -- Sistema de Gestão para uma Casa de Shows             ///\n");
    printf("///           Developed by LuizMiguel4444 -- since Aug, 2023                ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///      ============================================================       ///\n");
    printf("///      ========= Sistema de Gestão para uma Casa de Shows =========       ///\n");
    printf("///      ============================================================       ///\n");
    printf("///                                                                         ///\n");
    printf("///      Programa criado para disciplina DCT1106 -- Programação, com        ///\n");
    printf("///      fins de obtenção de conhecimento e nota. O programa contém         ///\n");
    printf("///      os principais módulos e funcionalidades que serão exigidos         ///\n");
    printf("///      na avalição dos projetos repassados pelo professor Flavius         ///\n");
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
    printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
    printf("///               Departamento de Computação e Tecnologia                   ///\n");
    printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
    printf("///         Projeto -- Sistema de Gestão para uma Casa de Shows             ///\n");
    printf("///           Developed by LuizMiguel4444 -- since Aug, 2023                ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///      ============================================================       ///\n");
    printf("///      ========= Sistema de Gestão para uma Casa de Shows =========       ///\n");
    printf("///      ============================================================       ///\n");
    printf("///                                                                         ///\n");
    printf("///      Este projeto foi desenvolvido por:                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///      Luiz Miguel Santos Silva                                           ///\n");
    printf("///      E-mail: luiz.santos.090@ufrn.edu.br                                ///\n");
    printf("///      Instagram: luiz__miguel10                                          ///\n");
    printf("///      GitHub: https://github.com/LuizMiguel4444/GestãoCasaShow.git       ///\n");
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
    printf("########                                                                  ######\n");
    printf("#########                                                                #######\n");
    printf("       ###                                                              ###\n");
    printf("       #####                                                          #####\n");
    printf("       #######                                                      #######\n");
    printf("      ##########                                                  ##########\n");
    printf("     #############                                              #############\n");
    printf("      ##############                                          ##############\n");
    printf("        ##############                                      ##############\n");
    printf("          ########                                              #########\n");
    printf("            ####                                                   ####\n");
    printf("              ##    ######                              ######     ##\n");
    printf("                    ########                          ########\n");
    printf("                    ##########                      ##########\n");
    printf("                    ############                  ############\n");
    printf("                    ##############              ##############\n");
    printf("                    ################          ################\n");
    printf("                    ##################      ##################\n");
    printf("                    ####################  ####################\n");
    printf("                    ##########################################\n");
    printf("                    ##########################################\n");
    printf("                      ######################################\n");
    printf("                       ####################################\n");
    printf("                          ##############################\n");
    printf("\n");
    printf("                        SEJA BEM-VINDO AO GESTÃO CASA SHOW\n");
    printf("\n");
    printf("                ##################################################\n");
    printf("                  ##############################################\n");
    printf("                      ######################################\n");
    printf("                            ##########################\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para ir ao Menu Principal... <<<");
    scanf("%c", &go);
}

void end(void)
{
    system("clear || cls");
    printf("########                                                                  ######\n");
    printf("#########                                                                #######\n");
    printf("       ###                                                              ###\n");
    printf("       #####                                                          #####\n");
    printf("       #######                                                      #######\n");
    printf("      ##########                                                  ##########\n");
    printf("     #############                                              #############\n");
    printf("      ##############                                          ##############\n");
    printf("        ##############                                      ##############\n");
    printf("          ########                                              #########\n");
    printf("            ####                                                   ####\n");
    printf("              ##    ######                              ######     ##\n");
    printf("                    ########                          ########\n");
    printf("                    ##########                      ##########\n");
    printf("                    ############                  ############\n");
    printf("                    ##############              ##############\n");
    printf("                    ################          ################\n");
    printf("                    ##################      ##################\n");
    printf("                    ####################  ####################\n");
    printf("                    ##########################################\n");
    printf("                    ##########################################\n");
    printf("                      ######################################\n");
    printf("                       ####################################\n");
    printf("                          ##############################\n");
    printf("\n");
    printf("                                 FIM DO ESPETÁCULO\n");
    printf("\n");
    printf("                ##################################################\n");
    printf("                  ##############################################\n");
    printf("                      ######################################\n");
    printf("                            ##########################\n");
}

int show_menu()
{
    int resp;
    system("clear || cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            =============   Gestão Casa Shows   ===============          ///\n");
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
    printf("///            Escolha a opção que deseja: ");
    scanf("%d", &resp);
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    return resp;
}

char cred_show()
{
    char go;
    system("clear || cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            =============   Gestão Casa Shows   ===============          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Cadastrar  Show = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Atração:                                                     ///\n");
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
    return go;
}

char read_show()
{
    char go;
    system("clear || cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            =============   Gestão Casa Shows   ===============          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Pesquisar  Show = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe a atração:                                           ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao Menu Principal... <<<");
    scanf("%c", &go);
    getchar();
    return go;
}

char upd_show()
{
    char go;
    system("clear || cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            =============   Gestão Casa Shows   ===============          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = =  Editar Show  = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe a atração:                                           ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao Menu Principal... <<<");
    scanf("%c", &go);
    getchar();
    return go;
}

char del_show()
{
    char go;
    system("clear || cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            =============   Gestão Casa Shows   ===============          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Excluir  Show = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe a atração:                                           ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao Menu Principal... <<<");
    scanf("%c", &go);
    getchar();
    return go;
}

// Main program
int main()
{
    int i;
    i = 0;
    setlocale(LC_ALL, "Portuguese_Brazil");
    welcome();
    while (i < 1)
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
}