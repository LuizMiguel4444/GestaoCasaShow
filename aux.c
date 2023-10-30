#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "aux.h"
#include "util.h"

void get_nome(char* nome, char* modulo)
{
  do {
    printf("###              Nome d%s: ", modulo);
    scanf(" %50[^\n]", nome);
    limpa_buffer();
  } while (!valNome(nome));
}

void get_cache(char* cache, char* modulo)
{
  do {
    printf("###              Cachê d%s: ", modulo);
    scanf("%s", cache);
    limpa_buffer();
  } while (!ehdinheiro(cache));
}

void get_email(char* email, char* modulo)
{
  do {
    printf("###              Email d%s: ", modulo);
    scanf("%[a-z0-9@.]", email);
    limpa_buffer();
  } while (!val_email(email));
}

void get_num(char* num, char* modulo)
{
  do{
    printf("###              Número d%s: ", modulo);
    scanf("%s", num);
    limpa_buffer();
  } while (!validarFone(num));
}

void get_id(char* id, char* modulo)
{
  do {
    printf("###              Id d%s: ", modulo);
    scanf("%s", id);
    limpa_buffer();
  } while (!val_id(id, 4));
}

void get_quant_cad(char* quant, char* modulo)
{
  do {
    printf("###              Quant. de %s: ", modulo);
    scanf("%s", quant);
    limpa_buffer();
  } while (!check_quant_cad(quant));
}

void get_quant_venda(char* quant, char* modulo)
{
  do {
    printf("###              Quant. de %s: ", modulo);
    scanf("%s", quant);
    limpa_buffer();
  } while (!check_quant_venda(quant));
}

void get_valor(char* valor, char* modulo)
{
  do {
    printf("###              Valor %s: ", modulo);
    scanf("%s", valor);
    limpa_buffer();
  } while (!ehdinheiro(valor));
}

void get_cpf(char* cpf)
{
  do {
    printf("###              CPF do cliente (apenas números): ");
    scanf("%[0-9-.]", cpf);
    limpa_buffer();
  } while (!validarCPF(cpf));
}

void get_data(char* data)
{
  do {
    printf("###              Data (dd/mm/aaaa): ");
    scanf("%s", data);
    limpa_buffer();
  } while (!valData(data));
}

void get_hour(char* hour)
{
  do {
    printf("###              Hora (hh:mm): ");
    scanf("%s", hour);
    limpa_buffer();
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
