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