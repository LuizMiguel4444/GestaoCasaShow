#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "inputs.h"
#include "util.h"

void get_nome(char* nome, char* modulo) {
  do {
    printf("###              Nome d%s: ", modulo);
    scanf(" %50[^\n]", nome);
    limpa_buffer();
  } while (!valNome(nome));
}

void get_cache(char* cache, char* modulo) {
  do {
    printf("###              Valor d%s: ", modulo);
    scanf("%s", cache);
    limpa_buffer();
  } while (!ehdinheiro(cache));
}

void get_email(char* email, char* modulo) {
  do {
    printf("###              Email d%s: ", modulo);
    scanf("%[a-z0-9@.]", email);
    limpa_buffer();
  } while (!val_email(email));
}

void get_num(char* num, char* modulo) {
  do{
    printf("###              Número d%s: ", modulo);
    scanf("%s", num);
    limpa_buffer();
  } while (!validarFone(num));
}

void get_id(char* id, char* modulo) {
  int tam = 4;
  do {
    printf("###              Id d%s: ", modulo);
    scanf("%s", id);
    limpa_buffer();
  } while (!val_id(id, tam));
}
