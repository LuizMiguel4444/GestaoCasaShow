#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
/// Função que limpa a linha de cima
///
void limpa_linha(void)
{
  printf("\033[1A");
  printf("\033[K");
} // AUTOR: LUIZ MIGUEL COM AJUDA DO CHAT-GPT /// GIT: https://github.com/LuizMiguel4444

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
/// Retorna 1 se o caractere recebido for uma alfabético ou um espaço
/// (letra entre 'A' e 'Z' ou 'a' e 'z') ou retorna 0 caso contrário
///
int ehLetraeEspacoeAcento(char c)
{
  int a = c;
  if (c >= 'A' && c <= 'Z') {
    return 1;
  } else if (c >= 'a' && c <= 'z') {
    return 1;
  } else if (c == ' ') {
    return 1;
  } else if (a < 0) {
    return 1;
  } else {
    return 0;
  }
} // AUTOR: LUIZ MIGUEL /// GIT: https://github.com/LuizMiguel4444

///////////////////////////////////////////////////////////////////////////////
/// Retorna 1 se string recebido for exclusivamente alfabético ou
/// retorna 0 caso contrário
///
int valNome(char *nome)
{
  for (int i = 0; nome[i] != '\0'; i++) {
    if (strlen(nome) < 3) {
      return 0;
    }
    if (!ehLetraeEspacoeAcento(nome[i])) {
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
/// Retorna 1 se string recebido corresponder a uma data válida 
/// (contagem de dia, mês, ano) ou retorna 0 caso contrário
///
int data_validacao(char data[])
{
  int dia, mes, ano;
  for (int i = 0; i < strlen(data); i++) {
    if ((data[0] == '/') || (data[1] == '/') || (data[3] == '/') ||
        (data[4] == '/') || (data[6] == '/') || (data[7] == '/') ||
        (data[8] == '/') || (data[9] == '/')) {
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
  if (ano < year) {
    return 0;
  }
  else if ((mes < mon) && (ano == year)) {
    return 0;
  }
  else if ((dia < day) && (mes == mon) && (ano == year)) {
    return 0;
  }
  return 1;  
} // MODIFICADO DE: FLAVIUS GORGÔNIO E ANTONIO MANIERO /// GIT: https://github.com/flaviusgorgonio E GIT: https://github.com/maniero

///////////////////////////////////////////////////////////////////////////////
/// Recebe uma data sem barras (ddmmaaaa) e retorna essa data
/// com barras (dd/mm/aaaa)
///
char* corrige_data(char *data)
{
  data[8] = data[7];
  data[9] = data[8];
  data[8] = data[6];
  data[7] = data[5];
  data[6] = data[4];
  data[4] = data[3];
  data[3] = data[2];
  data[2] = '/';
  data[5] = '/';
  data[10] = '\0';
  return data;
} // AUTOR: LUIZ MIGUEL /// GIT: https://github.com/LuizMiguel4444

///////////////////////////////////////////////////////////////////////////////
/// Retorna 1 se string recebido corresponder a uma data válida (apenas dígitos
/// e no formato: ddmmaaaa) ou retorna 0 caso contrário
///
int valData(char *data)
{
  int check;
  char* new_data;
  if (strlen(data) == 10) {
    for (int i = 0; i < strlen(data); i++) {
      if (!ehHora(data[i]) || (data[2] != '/') || (data[5] != '/')) {
        return 0;
      } 
    }
    check = data_validacao(data);
  }
  else if (strlen(data) == 8) {
    for (int i = 0; i < strlen(data); i++) {
      if (!ehDigito(data[i]) || (data[i] == '/')) {
        return 0;
      }
    }
    new_data = corrige_data(data);
    check = data_validacao(new_data);
  }
  else if (strlen(data) != 8 && strlen(data) != 10) {
    return 0;
  }
  if (check != 1) {
    return 0;
  } else {
    return 1;
  }
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
    if((sscanf( email, "%[^@ \t\n]@%[^. \t\n].%3[^ \t\n]", usuario, site, dominio ) != 3 ) || strlen(email) > 40) {
      return 0;
    }
    return 1;
}  // AUTOR: LACOBUS /// STACKOVERFLOW: https://pt.stackoverflow.com/questions/310096/como-validar-um-e-mail-em-c

///////////////////////////////////////////////////////////////////////////////
/// Retorna 1 se o caractere recebido for um dígito monetário
/// (entre 0 e 9 ou um '.') ou retorna 0 caso contrário
///
int ehDigitoDinheiro(char c)
{
  if ((c >= '0' && c <= '9') || (c == '.')) {
    return 1;
  } else {
    return 0;
  }
} // AUTOR: LUIZ MIGUEL /// GIT: https://github.com/LuizMiguel4444

///////////////////////////////////////////////////////////////////////////////
/// Retorna 1 se string recebido corresponder a apenas digitos
/// monetários e '.' ou retorna 0 caso contrário
///
float ehdinheiro(char *c)
{
  int ponto = strlen(c) - 3;
  for (int i = 0; c[i] != '\0'; i++) {
    if (!ehDigitoDinheiro(c[i]) || strlen(c) < 5 || c[0] == '0') {
      return 0;
    }
    else if (c[ponto] != '.') {
      return 0;
    }
  }
	return 1;
} // AUTOR: LUIZ MIGUEL /// GIT: https://github.com/LuizMiguel4444

///////////////////////////////////////////////////////////////////////////////
/// Retorna 1 se string recebido corresponder a apenas digitos com tamanho 
/// maior do que '1' e valor diferente de '0' ou retorna 0 caso contrário
///
int check_quant_cad(char *c) {
  for (int i = 0; c[i] != '\0'; i++) {
    if (!ehDigito(c[i]) || strlen(c) < 2 || c[0] == '0') {
      return 0;
    }
  }
  return 1;  
} // AUTOR: LUIZ MIGUEL /// GIT: https://github.com/LuizMiguel4444

///////////////////////////////////////////////////////////////////////////////
/// Retorna 1 se string recebido corresponder a apenas digitos com 
/// valor diferente de '0' ou retorna 0 caso contrário
///
int check_quant_venda(char *c) {
  for (int i = 0; c[i] != '\0'; i++) {
    if (!ehDigito(c[i]) || strlen(c) < 1 || c[0] == '0') {
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
    if (strcmp(cpf, "000") == 0) {
      return 1; /// Esse é um CPF fantasma!!!
    }
    else if(strlen(cpf) != 11)
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
  if ((c >= '0' && c <= '9') || (c == ':') || (c == '/')) {
    return 1;
  } else {
    return 0;
  }
} // AUTOR: LUIZ MIGUEL /// GIT: https://github.com/LuizMiguel4444

///////////////////////////////////////////////////////////////////////////////
/// Retorna 1 se string recebido corresponder a uma hora válida 
/// (a[1] < 2, a[2] < 4 ...) ou retorna 0 caso contrário
///
int hour_validacao(char hour[]) {
  for (int i = 0; i < strlen(hour); i++) {
    if (((hour[0] > '2')) || (hour[3] > '5')) {
      return 0;
    }
    if (((hour[0] < '0')) || ((hour[1] < '0')) || (hour[3] < '0') || (hour[4] < '0')) {
      return 0;
    }
    if (((hour[0] == '2')) && ((hour[1] > '3'))) {
      return 0;
    }
  }
  return 1;  
} // AUTOR: LUIZ MIGUEL /// GIT: https://github.com/LuizMiguel4444

///////////////////////////////////////////////////////////////////////////////
/// Recebe uma hora sem dois pontos (hhmm) e retorna essa hora
/// com dois pontos (hh:mm)
///
char* corrige_hour(char hour[])
{
  hour[4] = hour[3];
  hour[3] = hour[2];
  hour[2] = ':';
  hour[5] = '\0';
  return hour;
}

///////////////////////////////////////////////////////////////////////////////
/// Retorna 1 se string recebido corresponder a uma hora válida 
/// (hh:mm) ou retorna 0 caso contrário
///
int val_hour(char hour[])
{
  int check;
  char* new_hour;
  if (strlen(hour) == 5) {
    for (int i = 0; i < strlen(hour); i++) {
      if ((!ehHora(hour[i])) || (hour[2] != ':') || (hour[0] == ':') || (hour[1] == ':') || (hour[3] == ':') || (hour[4] == ':')) {
        return 0;
      }
    }
    check = hour_validacao(hour);
  }
  else if (strlen(hour) == 4) {
    for (int i = 0; i < strlen(hour); i++) {
      if ((!ehHora(hour[i]) || (hour[i]) == ':')) {
          return 0;
      }
    }
    new_hour = corrige_hour(hour);
    check = hour_validacao(new_hour);
  }
  else if (strlen(hour) != 4 && strlen(hour) != 5) {
    return 0;
  }
  if (check != 1) {
    return 0;
  } else {
    return 1;
  }
} // AUTOR: LUIZ MIGUEL /// GIT: https://github.com/LuizMiguel4444

///////////////////////////////////////////////////////////////////////////////
/// Função que simula o input da linguagem python
///
char* input(void)
{
  char linha[256];
  scanf(" %255[^\n]", linha);
  return duplica(linha);
} // AUTOR: FLAVIUS GORGÔNIO /// GIT: https://github.com/flaviusgorgonio

/////////////////////////////////////////////////////////////////////////////////
///// Auxilía na função que simula o input da linguagem python 
/////
char* duplica(char* s)
{
  int n;
  n = strlen(s) + 1;
  char* d = (char*) malloc(n * sizeof(char));
  strcpy(d, s);
  return d;
} // AUTOR: FLAVIUS GORGÔNIO /// GIT: https://github.com/flaviusgorgonio

///////////////////////////////////////////////////////////////////////////////
/// Função que simula o input da linguagem python
///
char *leLinha(char *linha, int tamanhoMaximo)
{
    if (fgets(linha, tamanhoMaximo, stdin) != NULL) {
        char *quebraLinha = strchr(linha, '\n');
        if (quebraLinha != NULL) {
            *quebraLinha = '\0';
        }
    }
  return linha;
} // AUTOR: LUIZ MIGUEL COM AJUDA DO CHAT-GPT /// GIT: https://github.com/LuizMiguel4444

///////////////////////////////////////////////////////////////////////////////
/// Função centraliza o texto inserido
///
char* centralizar_texto(char* texto, int tam, int horizontal) {
    int tam_texto = strlen(texto);

    for(int c = 0;c < tam_texto;c++) {
        if(texto[c] < 0) {
            tam++;
            c++;
        }
    }
    int pos;
    if(horizontal == 1) {
        pos = tam - tam_texto;
    } else if (horizontal == -1) {
        pos = 0;
    } else {
        pos = tam/2 - tam_texto/2;
    }

    char *str= malloc((tam + 1)*sizeof(char));
    for(int c = 0; c < tam; c++) {
        if(c >= pos && c < (pos + tam_texto)) {
            str[c] = texto[c-pos];
        } else {
            str[c] = ' ';
        }
    }
    str[tam] = '\0';
    return str;
} // AUTOR: EMANUEL ALVES // GIT: https://github.com/Faltrenn
