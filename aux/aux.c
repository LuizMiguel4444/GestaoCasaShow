#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "../show/show.h"
#include "../atraction/atraction.h"
#include "../client/client.h"
#include "../buy/buy.h"
#include "../report/report.h"
#include "aux.h"
#include "../util/util.h"

void get_nome(char* nome, char* modulo)
{
  do {
    printf("###              Nome d%s (sem acentos ou ç): ", modulo);
    scanf(" %50[^\n]", nome);
    limpa_buffer();
    if (!valNome(nome)) {
      screen_error_input_name();
      limpa_linha(); limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!valNome(nome));
}

void get_nome_upd(char* nome, char* modulo)
{
  do {
    printf("\n\t\t    Novo nome %s  (sem acentos ou ç): ", modulo);
    scanf(" %55[^\n]", nome);
    limpa_buffer();
    if (!valNome(nome)) {
      screen_error_input();
      limpa_linha(); limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!valNome(nome));
}

void get_cache(char* cache, char* modulo)
{
  do {
    printf("###              Cachê d%s: ", modulo);
    scanf("%s", cache);
    limpa_buffer();
    if (!ehdinheiro(cache)) {
      screen_error_input();
      limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!ehdinheiro(cache));
}

void get_cache_upd(char* cache, char* modulo)
{
  do {
    printf("\n\t\t    Novo cachê %s (com casa decimal): ", modulo);
    scanf("%s", cache);
    limpa_buffer();
    if (!ehdinheiro(cache)) {
      screen_error_input();
      limpa_linha(); limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!ehdinheiro(cache));
}

void get_email(char* email, char* modulo)
{
  do {
    printf("###              Email d%s: ", modulo);
    scanf("%[a-z0-9@.]", email);
    limpa_buffer();
    if (!val_email(email)) {
      screen_error_input();
      limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!val_email(email));
}

void get_email_upd(char* email, char* modulo)
{
  do {
    printf("\n\t\t    Novo email %s: ", modulo);
    scanf("%[a-z0-9@.]", email);
    limpa_buffer();
    if (!val_email(email)) {
      screen_error_input();
      limpa_linha(); limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!val_email(email));
}

void get_num(char* num, char* modulo)
{
  do{
    printf("###              Número d%s: ", modulo);
    scanf("%s", num);
    limpa_buffer();
    if (!validarFone(num)) {
      screen_error_input();
      limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!validarFone(num));
}

void get_num_upd(char* num, char* modulo)
{
  do {
    printf("\n\t\t    Novo número %s (com DDD): ", modulo);
    scanf("%s", num);
    limpa_buffer();
    if (!validarFone(num)) {
      screen_error_input();
      limpa_linha(); limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!validarFone(num));
}

void get_id(char* id, char* modulo)
{
  do {
    printf("###              Id d%s: ", modulo);
    scanf("%s", id);
    limpa_buffer();
    if (!val_id(id, 4)) {
      screen_error_input();
      limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!val_id(id, 4));
}

void get_quant_cad(char* quant, char* modulo)
{
  do {
    printf("###              Quant. de %s: ", modulo);
    scanf("%s", quant);
    limpa_buffer();
    if (!check_quant_cad(quant)) {
      screen_error_input();
      limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!check_quant_cad(quant));
}

void get_quant_cad_upd(char* quant, char* modulo)
{
  do {
    printf("\n\t\t    Nova quant. de %s: ", modulo);
    scanf("%s", quant);
    limpa_buffer();
    if (!check_quant_cad(quant)) {
      screen_error_input();
      limpa_linha(); limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!check_quant_cad(quant));
}

void get_quant_venda(char* quant, char* modulo)
{
  do {
    printf("###              Quant. de %s: ", modulo);
    scanf("%s", quant);
    limpa_buffer();
    if (!check_quant_venda(quant)) {
      screen_error_input();
      limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!check_quant_venda(quant));
}

void get_quant_venda_upd(char* quant, char* modulo)
{
  do {
    printf("\n\t\t   Nova quant. de %s: ", modulo);
    scanf("%s", quant);
    limpa_buffer();
    if (!check_quant_venda(quant)) {
      screen_error_input();
      limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!check_quant_venda(quant));
}

void get_valor(char* valor, char* modulo)
{
  do {
    printf("###              Valor %s: ", modulo);
    scanf("%s", valor);
    limpa_buffer();
    if (!ehdinheiro(valor)) {
      screen_error_input();
      limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!ehdinheiro(valor));
}

void get_valor_upd(char* valor, char* modulo)
{
  do {
    printf("\n\t\t    Novo valor %s: ", modulo);
    scanf("%s", valor);
    limpa_buffer();
    if (!ehdinheiro(valor)) {
      screen_error_input();
      limpa_linha(); limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!ehdinheiro(valor));
}

void get_cpf(char* cpf)
{
  do {
    printf("###              CPF do cliente (apenas números): ");
    scanf("%[0-9-.]", cpf);
    limpa_buffer();
    if (!validarCPF(cpf)) {
      screen_error_input();
      limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!validarCPF(cpf));
}

void get_cpf_upd(char* cpf)
{
  do {
    printf("\n\t\t   Novo CPF do cliente (apenas números): ");
    scanf("%[0-9-.]", cpf);
    limpa_buffer();
    if (!validarCPF(cpf)) {
      screen_error_input();
      limpa_linha(); limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!validarCPF(cpf));
}

void get_data(char* data)
{
  do {
    printf("###              Data (dd/mm/aaaa): ");
    scanf("%s", data);
    limpa_buffer();
    if (!valData(data)) {
      screen_error_input();
      limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!valData(data));
}

void get_data_upd(char* data)
{
  do {
    printf("\n\t\t    Nova data (dd/mm/aaaa): ");
    scanf("%s", data);
    limpa_buffer();
    if (!valData(data)) {
      screen_error_input();
      limpa_linha(); limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!valData(data));
}

void get_hour(char* hour)
{
  do {
    printf("###              Horário (hh:mm): ");
    scanf("%s", hour);
    limpa_buffer();
    if (!val_hour(hour)) {
      screen_error_input();
      limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!val_hour(hour));
}

void get_hour_upd(char* hour)
{
  do {
    printf("\n\t\t    Novo horário (hh:mm): ");
    scanf("%s", hour);
    limpa_buffer();
    if (!val_hour(hour)) {
      screen_error_input();
      limpa_linha(); limpa_linha(); limpa_linha(); limpa_linha();
    }
  } while (!val_hour(hour));
}

void screen_null_id_error(char* modulo)
{
  printf("###############################################################################\n");
  printf("###                                                                         ###\n");
  printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
  printf("###                       Id %s não encontrado\n", modulo);
  printf("###              = = = = = = = = = = = = = = = = = = = = = = = =            ###\n");
  printf("###                                                                         ###\n");
  printf("###############################################################################\n");
}

void screen_error_input(void)
{
  printf("\n\tEntrada inválida! Por favor, tecle ENTER e tente novamente...");
  getchar();
}

void screen_error_input_name(void)
{
  printf("\n\tEntrada inválida! Por favor, tecle ENTER e tente novamente...");
  printf("\n\tNomes próprios devem iniciar com letra maiúscula!");
  getchar();
}

void screen_error_input_resp(void)
{
  printf("\n\t     Entrada inválida! Por favor, tecle ENTER e tente novamente...");
  getchar();
}

void screen_error_input_id(char* chave)
{
  printf("\n\tO %s digitado já foi cadastrado! Por favor, insira um %s válido...", chave, chave);
  getchar();
}

void screen_error_input_n_exist(char* chave)
{
  printf("\n\tO %s digitado não foi cadastrado! Por favor, insira um %s válido existente...", chave, chave);
  getchar();
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
  if (resp[0] == 's') {
    return 1;
  } else {
    return 0;
  }
}
