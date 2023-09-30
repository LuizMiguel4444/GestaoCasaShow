#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

///////////////////////////////////////////////////////////////////////////////
/// Função que limpa o buffer
///
void limpa_buffer(void) {
    int entrada;
    do {
        entrada = fgetc(stdin);
    } while (entrada != EOF && entrada != '\n');
}

///////////////////////////////////////////////////////////////////////////////
/// Função que barra entrada dependendo do tamanho
///
int conta_entrada(char *entrada) {
  //do {
      if (strlen(entrada) > 1){
        return 0;
      }
  //} while (strlen(entrada) != 1);
  return 1;
}

///////////////////////////////////////////////////////////////////////////////
/// Printa dados fictícios na tela e induz volta a tela anterior
///
void print_dados(void)
{
    char go;
    system("cls || clear");
    printf("\n");
    printf("Mostra os dados na tela...\n");
    printf("\n");
    printf("Em desenvolvimento...\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    scanf("%c", &go);
}

///////////////////////////////////////////////////////////////////////////////
/// Printa uma mensagem de erro e induz volta a tela anterior
///
void error(void)
{
    char go;
    printf("\n");
    printf("Opção inválida!\n");
    printf("\n");
    printf("\t\t>>> Tecle ENTER para voltar ao menu anterior... <<<");
    scanf("%c\n", &go);
}

///////////////////////////////////////////////////////////////////////////////
/// Retorna 1 se o caractere recebido for um dígito (entre 0 e 9)
/// retorna 0 caso contrário
///
int ehDigito(char c)
{
  if (c >= '0' && c <= '9') {
    return 1;
  } else {
    return 0;
  }
} // AUTOR: FLAVIUS GORGÔNIO /// GIT: https://github.com/flaviusgorgonio

///////////////////////////////////////////////////////////////////////////////
/// Retorna 1 se o caractere recebido for um dígito entre os números passados
/// como parâmetro e retorna 0 caso contrário
///
int ehDigitoMax(char c, char max)
{
  if (c >= '0' && c <= max) {
    return 1;
  } else {
    return 0;
  }
}

///////////////////////////////////////////////////////////////////////////////
/// Retorna 1 se o caractere recebido for uma alfabético 
/// (letra entre 'A' e 'Z' ou 'a' e 'z') ou retorna 0 caso contrário
///
int ehLetra(char c)
{
  if (c >= 'A' && c <= 'Z') {
    return 1;
  } else if (c >= 'a' && c <= 'z') {
    return 1;
  } else {
    return 0;
  }
} // AUTOR: FLAVIUS GORGÔNIO /// GIT: https://github.com/flaviusgorgonio

///////////////////////////////////////////////////////////////////////////////
/// Retorna 1 se ano for bissexto (divisível por 4, não divisível por ...
/// 100 ou divisível por 400) e retorna 0 caso contrário
///
int ehBissexto(int aa)
{
  if ((aa % 4 == 0) && (aa % 100 != 0)) {
    return 1;
  } else if (aa % 400 == 0) {
    return 1;
  } else {
    return 0;
  }
}  // AUTOR: FLAVIUS GORGÔNIO /// GIT: https://github.com/flaviusgorgonio

///////////////////////////////////////////////////////////////////////////////
/// Retorna 1 se dia, mes e ano correspondem a uma data válida, inclusive
/// em anos bissextos, ou retorna 0 caso contrário
///
int ehData(int dd, int mm, int aa)
{
  int maiorDia;
  if (aa < 0 || mm < 1 || mm > 12)
    return 0;
  if (mm == 2) {
    if (ehBissexto(aa)) 
      maiorDia = 29;
    else
      maiorDia = 28;
  } else if (mm == 4 || mm == 6 || mm == 9 || mm == 11) {
    maiorDia = 30;
  } else
    maiorDia = 31;
  if (dd < 1 || dd > maiorDia)
    return 0;
  return 1;
} // AUTOR: FLAVIUS GORGÔNIO /// GIT: https://github.com/flaviusgorgonio

///////////////////////////////////////////////////////////////////////////////
/// Retorna 1 se string recebido for exclusivamente alfabético ou
/// retorna 0 caso contrário
///
int valNome(char* nome)
{
  for (int i=0; nome[i]!='\0'; i++) {
    if (!ehLetra(nome[i])) {
      return 0;
    }
  }
	return 1;
}  // AUTOR: FLAVIUS GORGÔNIO /// GIT: https://github.com/flaviusgorgonio

///////////////////////////////////////////////////////////////////////////////
/// Retorna 1 se string recebido corresponder a uma data válida (apenas dígitos
/// e no formato: ddmmaaaa) ou retorna 0 caso contrário
///
int valData(char* data)
{
  int tam, dia, mes, ano;
  tam = strlen(data);
  if (tam != 8) {
    return 0;
  }
  for (int i = 0; i < tam; i++) {
    if (!ehDigito(data[i])) {
      return 0;
    }
  }
  dia = (data[0] - '0') * 10 + (data[1] - '0');
  mes = (data[2] - '0') * 10 + (data[3] - '0');
  ano = (data[4] - '0') * 1000 + (data[5] - '0') * 100 + 
        (data[6] - '0') * 10 + (data[7] - '0');
  if (!ehData(dia, mes, ano)) {
    return 0;
  }
  return 1;
}  // AUTOR: FLAVIUS GORGÔNIO /// GIT: https://github.com/flaviusgorgonio

////// FUNÇÃO DE ID/CODIGO
int val_id(char* id, int tam)
{
  
    int i;

    // quantidade de digitos
    for (i = 0; i < tam; i++) {
        if (id[i] == '\0') {
            return 0;
        }
    }
    if (id[i] != '\0') {
        return 0;
    }
    
    // apenas digitos numericos
    for (i = 0; i < tam; i++) {
        if (!ehDigito(id[i])) {
            return 0;
        }
    }

    // ID valido
    return 1;
}  // MODIFICADO DE: MATHEUS QUIRINO FERNANDES FIGUEIREDO /// GIT: https://github.com/quirinof

int val_email(char * email )
{
    char usuario[256], site[256], dominio[256];
    if( sscanf( email, "%[^@ \t\n]@%[^. \t\n].%3[^ \t\n]", usuario, site, dominio ) != 3 )
        return 0;
    return 1;
}

float ehdinheiro(char * c)
{
  if (*c >= '0' && *c <= '9') {
    return 1;
  } else {
    return 0;
  }
}
