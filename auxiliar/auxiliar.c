#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "../show/show.h"
#include "../atraction/atraction.h"
#include "../client/client.h"
#include "../buy/buy.h"
#include "../report/report.h"
#include "../report/report_aux.h"
#include "auxiliar.h"
#include "../util/util.h"



// Functions
char* get_nome(char* modulo)
{
  char* nome;
  do {
    printf("###              Nome d%s: ", modulo);
    nome = input();
    limpa_buffer();
    limpa_linha();
    printf("###              Nome d%s: %s###\n", modulo, centralizar_texto(nome, 42, -1));
    if (!valNome(nome)) {
      screen_error_input_name();
      limpa_linha(); limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!valNome(nome));
  converte_para_minusculo(nome);
  return nome;
}

char* get_nome_upd(char* modulo)
{
  char* nome;
  do {
    printf("\n\t\t    Novo nome %s: ", modulo);
    nome = input();
    limpa_buffer();
    if (!valNome(nome)) {
      screen_error_input_name();
      limpa_linha(); limpa_linha(); limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!valNome(nome));
  converte_para_minusculo(nome);
  return nome;
}

char* get_cache(char* modulo)
{
  char* cache;
  do {
    printf("###              Cachê d%s: ", modulo);
    cache = input();
    limpa_buffer();
    limpa_linha();
    printf("###              Cachê d%s: %s###\n", modulo, centralizar_texto(cache, 22, -1));
    if (!ehdinheiro(cache)) {
      screen_error_input();
      limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!ehdinheiro(cache));
  return cache;
}

char* get_cache_upd(char* modulo)
{
  char* cache;
  do {
    printf("\n\t\t    Novo cachê %s (com casa decimal): ", modulo);
    cache = input();
    limpa_buffer();
    if (!ehdinheiro(cache)) {
      screen_error_input();
      limpa_linha(); limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!ehdinheiro(cache));
  return cache;
}

char* get_email(char* modulo)
{
  char* email;
  do {
    printf("###              Email d%s: ", modulo);
    email = input();
    limpa_buffer();
    limpa_linha();
    printf("###              Email d%s: %s###\n", modulo, centralizar_texto(email, 41, -1));
    if (!val_email(email)) {
      screen_error_input();
      limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!val_email(email));
  return email;
}

char* get_email_upd(char* modulo)
{
  char* email;
  do {
    printf("\n\t\t    Novo email %s: ", modulo);
    email = input();
    limpa_buffer();
    if (!val_email(email)) {
      screen_error_input();
      limpa_linha(); limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!val_email(email));
  return email;
}

char* get_num(char* modulo, int tam)
{
  char* num;
  do{
    printf("###              Número d%s: ", modulo);
    num = input();
    limpa_buffer();
    limpa_linha();
    printf("###              Número d%s: %s###\n", modulo, centralizar_texto(num, tam, -1));
    if (!validarFone(num)) {
      screen_error_input();
      limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!validarFone(num));
  return num;
}

char* get_num_upd(char* modulo)
{
  char* num;
  do {
    printf("\n\t\t    Novo número %s (com DDD): ", modulo);
    num = input();
    limpa_buffer();
    if (!validarFone(num)) {
      screen_error_input();
      limpa_linha(); limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!validarFone(num));
  return num;
}

char* get_id(char* modulo, int tam)
{
  char* id;
  do {
    printf("###              Id d%s: ", modulo);
    id = input();
    limpa_buffer();
    limpa_linha();
    printf("###              Id d%s: %s###\n", modulo, centralizar_texto(id, tam, -1));
    if (!val_id(id)) {
      screen_error_input();
      limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!val_id(id));
  return id;
}

char* get_quant_cad(char* modulo)
{
  char* quant;
  do {
    printf("###              Quant. de %s: ", modulo);
    quant = input();
    limpa_buffer();
    limpa_linha();
    printf("###              Quant. de %s: %s###\n", modulo, centralizar_texto(quant, 38, -1));
    if (!check_quant_cad(quant)) {
      screen_error_input();
      limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!check_quant_cad(quant));
  return quant;
}

char* get_quant_cad_upd(char* modulo)
{
  char* quant;
  do {
    printf("\n\t\t    Nova quant. de %s: ", modulo);
    quant = input();
    limpa_buffer();
    if (!check_quant_cad(quant)) {
      screen_error_input();
      limpa_linha(); limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!check_quant_cad(quant));
  return quant;
}

char* get_quant_venda(char* modulo)
{
  char* quant;
  do {
    printf("###              Quant. de %s: ", modulo);
    quant = input();
    limpa_buffer();
    limpa_linha();
    printf("###              Quant. de %s: %s###\n", modulo, centralizar_texto(quant, 38, -1));
    if (!check_quant_venda(quant)) {
      screen_error_input();
      limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!check_quant_venda(quant));
  return quant;
}

char* get_quant_venda_upd(char* modulo)
{
  char* quant;
  do {
    printf("\n\t\t   Nova quant. de %s: ", modulo);
    quant = input();
    limpa_buffer();
    if (!check_quant_venda(quant)) {
      screen_error_input();
      limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!check_quant_venda(quant));
  return quant;
}

char* get_valor(char* modulo)
{
  char* valor;
  do {
    printf("###              Valor %s: ", modulo);
    valor = input();
    limpa_buffer();
    limpa_linha();
    printf("###              Valor %s: %s###\n", modulo, centralizar_texto(valor, 21, -1));
    if (!ehdinheiro(valor)) {
      screen_error_input();
      limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!ehdinheiro(valor));
  return valor;
}

char* get_valor_upd(char* modulo)
{
  char* valor;
  do {
    printf("\n\t\t    Novo valor %s: ", modulo);
    valor = input();
    limpa_buffer();
    if (!ehdinheiro(valor)) {
      screen_error_input();
      limpa_linha(); limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!ehdinheiro(valor));
  return valor;
}

char* get_cpf(void)
{
  char* cpf;
  do {
    printf("###              CPF do cliente (apenas números): ");
    cpf = input();
    limpa_buffer();
    limpa_linha();
    printf("###              CPF do cliente (apenas números): %s###\n", centralizar_texto(cpf, 26, -1));
    if (!validarCPF(cpf)) {
      screen_error_input();
      limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!validarCPF(cpf));
  return cpf;
}

char* get_cpf_upd(void)
{
  char* cpf;
  do {
    printf("\n\t\t   Novo CPF do cliente (apenas números): ");
    cpf = input();
    limpa_buffer();
    if (!validarCPF(cpf)) {
      screen_error_input();
      limpa_linha(); limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!validarCPF(cpf));
  return cpf;
}

char* get_data(void)
{
  char* data;
  do {
    printf("###              Data (dd/mm/aaaa): ");
    data = input();
    limpa_buffer();
    limpa_linha();
    printf("###              Data (dd/mm/aaaa): %s###\n", centralizar_texto(data, 40, -1));
    if (!valData(data)) {
      screen_error_input();
      limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!valData(data));
  return data;
}

char* get_data_upd(void)
{
  char* data;
  do {
    printf("\n\t\t    Nova data (dd/mm/aaaa): ");
    data = input();
    limpa_buffer();
    if (!valData(data)) {
      screen_error_input();
      limpa_linha(); limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!valData(data));
  return data;
}

char* get_hour(void)
{
  char* hour;
  do {
    printf("###              Horário (hh:mm): ");
    hour = input();
    limpa_buffer();
    limpa_linha();
    printf("###              Horário (hh:mm): %s###\n", centralizar_texto(hour, 42, -1));
    if (!val_hour(hour)) {
      screen_error_input();
      limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!val_hour(hour));
  return hour;
}

char* get_hour_upd(void)
{
  char* hour;
  do {
    printf("\n\t\t    Novo horário (hh:mm): ");
    hour = input();
    limpa_buffer();
    if (!val_hour(hour)) {
      screen_error_input();
      limpa_linha(); limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!val_hour(hour));
  return hour;
}

int check_quant_cad(char *c) {
  for (int i = 0; c[i] != '\0'; i++) {
    if (!ehDigito(c[i]) || strlen(c) < 2 || c[0] == '0') {
      return 0;
    }
  }
  return 1;  
}

int check_quant_venda(char *c) {
  for (int i = 0; c[i] != '\0'; i++) {
    if (!ehDigito(c[i]) || strlen(c) < 1 || c[0] == '0') {
      return 0;
    }
  }
  return 1;  
}

char certeza_upd(char* modulo)
{
  char resp[256];
  do {
    printf("\n\t\tDeseja mesmo alterar os dados %s (s/n)? ", modulo);
    scanf("%s", resp);
    limpa_buffer();
    if ((resp[0] != 's' && resp[0] != 'n') || strlen(resp) > 1) {
        screen_error_input_resp();
        limpa_linha(); limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while ((resp[0] != 's' && resp[0] != 'n') || strlen(resp) > 1);
  converte_para_minusculo(resp);
  if (resp[0] == 's') {
    return 1;
  } else {
    return 0;
  }
}

char certeza_del(char* modulo)
{
  char resp[256];
  do {
    printf("\n\t\tDeseja mesmo excluir os dados %s (s/n)? ", modulo);
    scanf("%s", resp);
    limpa_buffer();
    if ((resp[0] != 's' && resp[0] != 'n') || strlen(resp) > 1) {
        screen_error_input_resp();
        limpa_linha(); limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while ((resp[0] != 's' && resp[0] != 'n') || strlen(resp) > 1);
  converte_para_minusculo(resp);
  if (resp[0] == 's') {
    return 1;
  } else {
    return 0;
  }
}



// Screen Functions
void screen_null_id_error(char* modulo)
{
  printf("###############################################################################\n");
  printf("###                                                                         ###\n");
  printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
  printf("###                       %s não encontrado\n", modulo);
  printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
  printf("###                                                                         ###\n");
  printf("###############################################################################\n");
}

void screen_error_input(void)
{
  printf("\n\tEntrada inválida! Por favor, tecle ENTER e tente novamente...");
  limpa_buffer();
}

void screen_error_input_name(void)
{
  printf("\n\tEntrada inválida! Por favor, tecle ENTER e tente novamente...");
  printf("\n\tSe o nome digitado for muito extenso, abrevie por favor!");
  limpa_buffer();
}

void screen_error_input_resp(void)
{
  printf("\n\t     Entrada inválida! Por favor, tecle ENTER e tente novamente...");
  limpa_buffer();
}

void screen_error_input_id(char* chave)
{
  printf("\n\tO %s digitado já foi cadastrado! Por favor, insira um %s válido...", chave, chave);
  limpa_buffer();
}

void screen_error_input_n_exist(char* chave)
{
  printf("\n\tO %s digitado não foi cadastrado! Por favor, insira um %s válido cadastrado...", chave, chave);
  limpa_buffer();
}
