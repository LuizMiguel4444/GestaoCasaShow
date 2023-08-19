#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Functions signature
void main_menu(void);
void show_menu(void);
void cred_show(void);
void read_show(void);
void upd_show(void);
void del_show(void);
void about(void);
void dev(void);

// Functions
void main_menu(void)
{
    // char resp;
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
    printf("///                           2. Menu Ingressos                             ///\n");
    printf("///                           3. Menu FeedBacks                             ///\n");
    printf("///                           4. Menu Relat�rios                            ///\n");
    printf("///                                0. Sair                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///                       Escolha a op��o que deseja:                       ///\n");
    printf("///                         Em desenvolvimento ...                          ///\n");
    // scanf("%c", &resp);
    // getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para ir a pr�xima tela <<<\n");
    getchar();
}

void about(void)
{
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
    printf("\n");
    printf("\t\t>>> Tecle ENTER para ir a pr�xima tela <<<\n");
    getchar();
}

void dev(void)
{
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
    printf("\n");
    printf("\t\t>>> Tecle ENTER para ir a pr�xima tela <<<\n");
    getchar();
}

void show_menu(void)
{
    // char resp;
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
    printf("///            0. Voltar ao menu anterior                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a op��o que deseja:                                  ///\n");
    printf("///            Em desenvolvimento ...                                       ///\n");
    // scanf("%c", &resp);
    // getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para ir a pr�xima tela <<<\n");
    getchar();
}

void cred_show(void)
{
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
    printf("\n");
    printf("\t\t>>> Tecle ENTER para ir a pr�xima tela <<<\n");
    getchar();
}

void read_show(void)
{
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
    printf("///            Informe a atra��o:                                           ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para ir a pr�xima tela <<<\n");
    getchar();
}

void upd_show(void)
{
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
    printf("///            Informe a atra��o:                                           ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para ir a pr�xima tela <<<\n");
    getchar();
}

void del_show(void)
{
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
    printf("///            Informe a atra��o:                                           ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para ir a pr�xima tela <<<\n");
    getchar();
}

// Main program
int main(void)
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    main_menu();
    show_menu();
    cred_show();
    read_show();
    upd_show();
    del_show();
    about();
    dev();
    return 0;
}