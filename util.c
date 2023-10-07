#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "util.h"

///////////////////////////////////////////////////////////////////////////////
/// Função que limpa o buffer do teclado
///
void limpa_buffer(void) 
{
    int entrada;
    do {
        entrada = fgetc(stdin);
    } while (entrada != EOF && entrada != '\n');
} // AUTOR: GUILHERME BERNAL /// STACKOVERFLOW: https://pt.stackoverflow.com/questions/9427/limpeza-do-buffer-do-teclado-ap%C3%B3s-scanf

///////////////////////////////////////////////////////////////////////////////
/// Função que retorna 1 caso a entrada tiver mais de 1 caractere
/// e retorna 0 caso contrário
///
int val_entrada(char *entrada)
{
  if (strlen(entrada) > 1) {
    return 0;
  }
  return 1;
} // AUTOR: LUIZ MIGUEL /// GIT: https://github.com/LuizMiguel4444

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
} // AUTOR: LUIZ MIGUEL /// GIT: https://github.com/LuizMiguel4444

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
/// Retorna 1 se string recebido for exclusivamente alfabético ou
/// retorna 0 caso contrário
///
int valNome(char *nome)
{
  for (int i = 0; nome[i] != '\0'; i++) {
    if (!ehLetra(nome[i])) {
      return 0;
    }
  }
	return 1;
}  // AUTOR: FLAVIUS GORGÔNIO /// GIT: https://github.com/flaviusgorgonio

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
/// Retorna 1 se string recebido corresponder a uma data válida (apenas dígitos
/// e no formato: ddmmaaaa) ou retorna 0 caso contrário
///
int valData(char *data)
{
  int tam, dia, mes, ano;
  tam = strlen(data);
  if (tam == 10) {
    for (int i = 0; i < tam; i++) {
      if (!ehDigito(data[i]) || (data[2] != '/') || (data[5] != '/')) {
        return 0;
      }
    }
    dia = (data[0] - '0') * 10 + (data[1] - '0');
    mes = (data[3] - '0') * 10 + (data[4] - '0');
    ano = (data[6] - '0') * 1000 + (data[7] - '0') * 100 + 
          (data[8] - '0') * 10 + (data[9] - '0');
    if (!ehData(dia, mes, ano)) {
      return 0;
    }
    int day, mon, year;
    time_t hoje;
    hoje = time(NULL);
    struct tm tm = *localtime(&hoje);
    day = tm.tm_mday;
    mon = tm.tm_mon + 1;
    year = tm.tm_year + 1900;
    if ((dia > day) || (mes > mon) || (ano > year)) {
      return 0;
    }
  }

  if (tam == 8) {
    for (int i = 0; i < tam; i++) {
      if (!ehDigito(data[i]) || (data[i] == '/')) {
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
    int day, mon, year;
    time_t hoje;
    hoje = time(NULL);
    struct tm tm = *localtime(&hoje);
    day = tm.tm_mday;
    mon = tm.tm_mon + 1;
    year = tm.tm_year + 1900;
    if ((dia > day) || (mes > mon) || (ano > year)) {
      return 0;
    }
  }

  else {
    return 0;
  }

  return 1;
}  // MODIFICADO DE: FLAVIUS GORGÔNIO E ANTONIO MANIERO /// GIT: https://github.com/flaviusgorgonio E GIT: https://github.com/maniero

///////////////////////////////////////////////////////////////////////////////
/// Retorna 1 se string (com tamanhos específicos) recebido corresponder  
/// a um id válido (apenas dígitos) ou retorna 0 caso contrário
///
int val_id(char *id, int tam)
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

///////////////////////////////////////////////////////////////////////////////
/// Retorna 1 se string recebido corresponder a um email válido 
/// ou retorna 0 caso contrário
///
int val_email(char *email )
{
    char usuario[256], site[256], dominio[256];
    if( sscanf( email, "%[^@ \t\n]@%[^. \t\n].%3[^ \t\n]", usuario, site, dominio ) != 3 )
        return 0;
    return 1;
}  // AUTOR: LACOBUS /// STACKOVERFLOW: https://pt.stackoverflow.com/questions/310096/como-validar-um-e-mail-em-c

///////////////////////////////////////////////////////////////////////////////
/// Retorna 1 se string recebido corresponder a apenas digitos com tamanho 
/// maior do que 1 ou retorna 0 caso contrário
///
float ehdinheiro(char *c)
{
  for (int i = 0; c[i] != '\0'; i++) {
    if (!ehDigito(c[i]) || strlen(c) < 2 || c[0] == '0') {
      return 0;
    }
  }
	return 1;
} // AUTOR: LUIZ MIGUEL /// GIT: https://github.com/LuizMiguel4444

///////////////////////////////////////////////////////////////////////////////
/// Retorna 1 se string recebido corresponder a um número de celular válido 
/// (apenas dígitos) ou retorna 0 caso contrário
///
int validarFone(char *fone)
{
  int tam;
  tam = strlen(fone);
  if (tam != 11) {
    return 0;
  }
  for (int i = 0; i < tam; i++) {
    if (!ehDigito(fone[i])) {
        return 0;
    }
  }
  return 1;
}  // AUTOR: FLAVIUS GORGÔNIO /// GIT: https://github.com/flaviusgorgonio

///////////////////////////////////////////////////////////////////////////////
/// Retorna 1 se string recebido corresponder a um cpf válido 
/// ou retorna 0 caso contrário
///
int validarCPF(char *cpf)
{
    int i, j, digito1 = 0, digito2 = 0;
    if(strlen(cpf) != 11)
        return 0;
    else if((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || (strcmp(cpf,"22222222222") == 0) ||
            (strcmp(cpf,"33333333333") == 0) || (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
            (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || (strcmp(cpf,"88888888888") == 0) ||
            (strcmp(cpf,"99999999999") == 0) || (strcmp(cpf,"12345678909") == 0))
        return 0; ///se o CPF tiver todos os números iguais ele é inválido.
    else
    {
        ///digito 1---------------------------------------------------
        for(i = 0, j = 10; i < strlen(cpf)-2; i++, j--) ///multiplica os números de 10 a 2 e soma os resultados dentro de digito1
            digito1 += (cpf[i]-48) * j;
        digito1 %= 11;
        if(digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if((cpf[9]-48) != digito1)
            return 0; ///se o digito 1 não for o mesmo que o da validação CPF é inválido
        else
        ///digito 2--------------------------------------------------
        {
            for(i = 0, j = 11; i < strlen(cpf)-1; i++, j--) ///multiplica os números de 11 a 2 e soma os resultados dentro de digito2
                    digito2 += (cpf[i]-48) * j;
        digito2 %= 11;
        if(digito2 < 2)
            digito2 = 0;
        else
            digito2 = 11 - digito2;
        if((cpf[10]-48) != digito2)
            return 0; ///se o digito 2 não for o mesmo que o da validação CPF é inválido
        }
    }
    return 1;
}  // AUTOR: EDUARDO EDSON /// GIT: https://github.com/eduardoedson

///////////////////////////////////////////////////////////////////////////////
/// Retorna 1 se string recebido corresponder a uma hora válida 
/// (apenas digitos e um ':') ou retorna 0 caso contrário
///
int ehHora(char c)
{
  if ((c >= '0' && c <= '9') || (c == ':')) {
    return 1;
  } else {
    return 0;
  }
} // AUTOR: LUIZ MIGUEL /// GIT: https://github.com/LuizMiguel4444

///////////////////////////////////////////////////////////////////////////////
/// Retorna 1 se string recebido corresponder a uma hora válida 
/// (hh:mm) ou retorna 0 caso contrário
///
int val_hour(char hour[])
{
  int tam;
  tam = strlen(hour);
  if (tam == 5) {
    for (int i = 0; i < tam; i++) {
      if ((!ehHora(hour[i])) || (hour[2] != ':')) {
        return 0;
      }
      if (((hour[0] > '2')) || ((hour[1] > '3')) || (hour[3] > '5')) {
        return 0;
      }
      if (((hour[0] < '0')) || ((hour[1] < '0')) || (hour[3] < '0') || (hour[4] < '0')) {
        return 0;
      }
    }
  }

  else if (tam == 4) {
    for (int i = 0; i < tam; i++) {
      if ((!ehHora(hour[i]) || (hour[i]) == ':')) {
        return 0;
      }
      if (((hour[0] > '2')) || ((hour[1] > '3')) || (hour[2] > '5')) {
        return 0;
      }
      if (((hour[0] < '0')) || ((hour[1] < '0')) || (hour[2] < '0') || (hour[3] < '0')) {
        return 0;
      }
    }
  }

  else {
    return 0;
  }

  return 1;
} // AUTOR: LUIZ MIGUEL /// GIT: https://github.com/LuizMiguel4444
