#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#ifndef cores
#define cores
#define ciano(texto) printf("\33[1;36m %s \33[0m", texto)
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
int ticket_menu(void);
void cred_ticket(void);
void read_ticket(void);
void upd_ticket(void);
void del_ticket(void);
int contract_menu(void);
void cred_contract(void);
void read_contract(void);
void upd_contract(void);
void del_contract(void);
void report_menu(void);
void error(void);

// Main program
int main(void)
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    welcome();
    int resp1;
    do
    {
        resp1 = main_menu();
        switch (resp1)
        {
            case 1:
                show_menu();
                break;
            case 2:
                ticket_menu();
                break;
            case 3:
                contract_menu();
                break;
            case 4:
                report_menu();
                break;
            case 5:
                about();
                break;
            case 6:
                dev();
                break;
            case 0:
                end();
                break;
        }
    } while (resp1 != 0);
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
    printf("///                           2. Menu Ingressos                             ///\n");
    printf("///                           3. Menu Contratos                             ///\n");
    printf("///                           4. Menu Relatórios                            ///\n");
    printf("///                                5. Sobre                                 ///\n");
    printf("///                              6. Créditos                                ///\n");
    printf("///                                0. Sair                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///                       Escolha a opção que deseja:");
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
    printf("///      na avaliação dos projetos repassados pelo professor Flavius        ///\n");
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
    printf("///      Luiz Miguel Santos Silva                                           ///\n");
    printf("///                                                                         ///\n");
    printf("///      Contatos:                                                          ///\n");
    printf("///      E-mail: luiz.santos.090@ufrn.edu.br                                ///\n");
    printf("///      Instagram: luiz__miguel10                                          ///\n");
    printf("///      GitHub: https://github.com/LuizMiguel4444                          ///\n");
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

int show_menu(void)
{
    int resp;
    do
    {
        system("clear || cls");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                         ///\n");
        printf("///            ===================================================          ///\n");
        printf("///            =============   Gestão Casa Shows   ===============          ///\n");
        printf("///            ===================================================          ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                         ///\n");
        printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
        printf("///              = = = = = = = = = Menu  Shows = = = = = = = = =            ///\n");
        printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
        printf("///                                                                         ///\n");
        printf("///              1. Cadastrar um novo show                                  ///\n");
        printf("///              2. Pesquisar os dados de um show                           ///\n");
        printf("///              3. Editar o cadastro de um show                            ///\n");
        printf("///              4. Excluir um show do sistema                              ///\n");
        printf("///              0. Voltar ao Menu Principal                                ///\n");
        printf("///                                                                         ///\n");
        printf("///              Escolha a opção que deseja:");
        scanf("%d", &resp);
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        switch (resp)
        {
            case 1:
                cred_show();
                break;
            case 2:
                read_show();
                break;
            case 3:
                upd_show();
                break;
            case 4:
                del_show();
                break;
            case 0:
                system("cls || clear");
                break;
        }
    } while (resp != 0);
    return 0;
}

void cred_show(void)
{
    char go;
    char* skip;
    skip = (char*) malloc(30*sizeof(char));
    system("clear || cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            =============   Gestão Casa Shows   ===============          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///              = = = = = = = = Cadastrar  Show = = = = = = = =            ///\n");
    printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("///              Atração: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", skip);
    getchar();
    printf("\n///              Data (dd/mm/aaaa): ");
    scanf("%[0-9/]", skip);
    getchar();
    printf("///              Local:");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", skip);
    getchar();
    printf("///              Quant. de ingressos (apenas numeros): ");
    scanf("%[0-9]", skip);
    getchar();
    printf("///              Id destinado aos ingressos (apenas numeros): ");
    scanf("%[0-9]", skip);
    getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    scanf("%c", &go);
}

void read_show(void)
{
    int go;
    char go1;
    system("clear || cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            =============   Gestão Casa Shows   ===============          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///              = = = = = = = = Pesquisar  Show = = = = = = = =            ///\n");
    printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("///              Informe o Id dos ingressos do show:");
    scanf("%d", &go);
    getchar();
    if (go != 1000)
    {
        print_dados();
    }
    else
    {
        printf("///                                                                         ///\n");
        printf("///              Id do show não encontrado!                                 ///\n");
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
    printf("///            =============   Gestão Casa Shows   ===============          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///              = = = = = = = =  Editar Show  = = = = = = = = =            ///\n");
    printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("///              Informe o Id dos ingressos do show:");
    scanf("%d", &go);
    getchar();
    if (go != 1000)
    {
        print_dados();
    }
    else
    {
        printf("///                                                                         ///\n");
        printf("///              Id do show não encontrado!                                 ///\n");
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
    printf("///            =============   Gestão Casa Shows   ===============          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///              = = = = = = = = Excluir  Show = = = = = = = = =            ///\n");
    printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("///              Informe o Id dos ingressos do show:");
    scanf("%d", &go);
    getchar();
    if (go != 1000)
    {
        print_dados();
    }
    else
    {
        printf("///                                                                         ///\n");
        printf("///              Id do show não encontrado!                                 ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao Menu Principal... <<<");
        scanf("%c", &go1);
    }
}

int ticket_menu(void)
{
    int resp;
    do 
    {
        system("clear || cls");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                         ///\n");
        printf("///            ===================================================          ///\n");
        printf("///            =============   Gestão Casa Shows   ===============          ///\n");
        printf("///            ===================================================          ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                         ///\n");
        printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
        printf("///              = = = = = = = = Menu  Ingressos = = = = = = = =            ///\n");
        printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
        printf("///                                                                         ///\n");
        printf("///              1. Cadastrar um novo ingresso                              ///\n");
        printf("///              2. Pesquisar os dados de um ingresso                       ///\n");
        printf("///              3. Editar o cadastro de um ingresso                        ///\n");
        printf("///              4. Excluir um ingresso do sistema                          ///\n");
        printf("///              0. Voltar ao Menu Principal                                ///\n");
        printf("///                                                                         ///\n");
        printf("///              Escolha a opção que deseja:");
        scanf("%d", &resp);
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        switch (resp)
            {
                case 1:
                    cred_ticket();
                    break;
                case 2:
                    read_ticket();
                    break;
                case 3:
                    upd_ticket();
                    break;
                case 4:
                    del_ticket();
                    break;
                case 0:
                    system("cls || clear");
                    break;
        }
    } while (resp != 0);
    return 0;
}

void cred_ticket(void)
{
    char go;
    char* skip;
    skip = (char*) malloc(8*sizeof(char));
    system("clear || cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            =============   Gestão Casa Shows   ===============          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///              = = = = = = = Cadastrar Ingressso = = = = = = =            ///\n");
    printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("///              Informe o Id do ingresso:                                  ///\n");
    scanf("%[0-9]", skip);
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao Menu Principal... <<<");
    scanf("%c", &go);
    getchar();
}

void read_ticket(void)
{
    int go;
    char go1;
    system("clear || cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            =============   Gestão Casa Shows   ===============          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///              = = = = = = = Pesquisar  Ingresso = = = = = = =            ///\n");
    printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("///              Informe o Id do ingresso:");
    scanf("%d", &go);
    getchar();
    if (go != 1000)
    {
        print_dados();
    }
    else
    {
        printf("///                                                                         ///\n");
        printf("///              Id do ingresso não encontrado!                             ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao Menu Principal... <<<");
        scanf("%c", &go1);
    }
}

void upd_ticket(void)
{
    int go;
    char go1;
    system("clear || cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            =============   Gestão Casa Shows   ===============          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///              = = = = = = = = Editar Ingresso = = = = = = = =            ///\n");
    printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("///              Informe o Id do ingresso:");
    scanf("%d", &go);
    getchar();
    if (go != 1000)
    {
        print_dados();
    }
    else
    {
        printf("///                                                                         ///\n");
        printf("///              Id do ingresso não encontrado!                             ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao Menu Principal... <<<");
        scanf("%c", &go1);
    }
}

void del_ticket(void)
{
    int go;
    char go1;
    system("clear || cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            =============   Gestão Casa Shows   ===============          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///              = = = = = = = Excluir  Ingresso = = = = = = = =            ///\n");
    printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("///              Informe o Id do ingresso:");
    scanf("%d", &go);
    getchar();
    if (go != 1000)
    {
        print_dados();
    }
    else
    {
        printf("///                                                                         ///\n");
        printf("///              Id do ingresso não encontrado!                             ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao Menu Principal... <<<");
        scanf("%c", &go1);
    }
}

int contract_menu(void)
{
    int resp;
    do
    {
        system("clear || cls");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                         ///\n");
        printf("///            ===================================================          ///\n");
        printf("///            =============   Gestão Casa Shows   ===============          ///\n");
        printf("///            ===================================================          ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("///                                                                         ///\n");
        printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
        printf("///              = = = = = = = = Menu  Contratos = = = = = = = =            ///\n");
        printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
        printf("///                                                                         ///\n");
        printf("///              1. Cadastrar um novo contrato                              ///\n");
        printf("///              2. Pesquisar os dados de um contrato                       ///\n");
        printf("///              3. Editar o cadastro de um contrato                        ///\n");
        printf("///              4. Excluir um contrato do sistema                          ///\n");
        printf("///              0. Voltar ao Menu Principal                                ///\n");
        printf("///                                                                         ///\n");
        printf("///              Escolha a opção que deseja:");
        scanf("%d", &resp);
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        switch (resp)
        {
            case 1:
                cred_contract();
                break;
            case 2:
                read_contract();
                break;
            case 3:
                upd_contract();
                break;
            case 4:
                del_contract();
                break;
            case 0:
                system("cls || clear");
                break;
        }
    } while (resp != 0);
    return 0;
}

void cred_contract(void)
{
    char go;
    char* skip;
    skip = (char*) malloc(8*sizeof(char));
    system("clear || cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            =============   Gestão Casa Shows   ===============          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///              = = = = = = = Cadastrar  Contrato = = = = = = =            ///\n");
    printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("///              Informe o Id do contrato:                                  ///\n");
    scanf("%[0-9]", skip);
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao Menu Principal... <<<");
    scanf("%c", &go);
    getchar();
}

void read_contract(void)
{
    int go;
    char go1;
    system("clear || cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            =============   Gestão Casa Shows   ===============          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///              = = = = = = = Pesquisar  Contrato = = = = = = =            ///\n");
    printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("///              Informe o Id do contrato:");
    scanf("%d", &go);
    getchar();
    if (go != 1000)
    {
        print_dados();
    }
    else
    {
        printf("///                                                                         ///\n");
        printf("///              Id do contrato não encontrado!                             ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao Menu Principal... <<<");
        scanf("%c", &go1);
    }
}

void upd_contract(void)
{
    int go;
    char go1;
    system("clear || cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            =============   Gestão Casa Shows   ===============          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///              = = = = = = = = Editar Contrato = = = = = = = =            ///\n");
    printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("///              Informe o Id do contrato:");
    scanf("%d", &go);
    getchar();
    if (go != 1000)
    {
        print_dados();
    }
    else
    {
        printf("///                                                                         ///\n");
        printf("///              Id do contrato não encontrado!                             ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao Menu Principal... <<<");
        scanf("%c", &go1);
    }
}

void del_contract(void)
{
    int go;
    char go1;
    system("clear || cls");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            =============   Gestão Casa Shows   ===============          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///              = = = = = = = Excluir  Contrsto = = = = = = = =            ///\n");
    printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("///              Informe o Id do contrato:");
    scanf("%d", &go);
    getchar();
    if (go != 1000)
    {
        print_dados();
    }
    else
    {
        printf("///                                                                         ///\n");
        printf("///              Id do contrato não encontrado!                             ///\n");
        printf("///                                                                         ///\n");
        printf("///////////////////////////////////////////////////////////////////////////////\n");
        printf("\n");
        printf("\t\t>>> Tecle ENTER para voltar ao Menu Principal... <<<");
        scanf("%c", &go1);
    }
}

void report_menu(void)
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
    printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///              = = = = = = = = Menu  Relatório = = = = = = = =            ///\n");
    printf("///              = = = = = = = = = = = = = = = = = = = = = = = =            ///\n");
    printf("///                                                                         ///\n");
    printf("///              Apresenta os dados do relatório...                         ///\n");
    printf("///                                                                         ///\n");
    printf("///              Em desenvolvimento...                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao Menu Principal... <<<");
    scanf("%c", &go);
    getchar();
}

void print_dados(void)
{
    char go;
    system("cls || clear");
    printf("\n");
    printf("Mostra os dados na tela...\n");
    printf("\n");
    printf("Em desenvolvimento...\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao Menu Principal... <<<");
    scanf("%c", &go);
}

void error(void)
{
    char go;
    printf("\n");
    printf("Opção inválida!\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao Menu Principal... <<<");
    scanf("%c\n", &go);
}
