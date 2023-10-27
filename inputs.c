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

