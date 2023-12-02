// Struct
typedef struct atraction Atraction;

struct atraction
{
    char nome[56];
    char cache[16];
    char email[56];
    char num[12];
    char id[5];
    char status;
    char date[12];
    int hour;
    int minute;
    Atraction *prox;
};



// Functions
void modulo_atraction(void);
char atraction_menu(void);
Atraction *cred_atraction(void);
void atraction_inputs(Atraction*);
void get_data_hour_atr(Atraction*);
char *screen_busc_atraction(void);
char *screen_upd_atraction(void);
void update_atr(void);
void qual_campo_atr(Atraction*);
char *del_atraction(void);



// File Functions
void gravar_atr(Atraction*);
void pesquisa_atr(void);
Atraction *procura_atraction(char*);
void regravar_atr(Atraction*);
void remove_atr(Atraction*);
void excluir_atr(void);
char* gera_id_atr(void);



// Screen Functions
void atraction_menu_screen(void);
void print_dados_atraction(Atraction*);
void print_dados_atraction_upd(Atraction*);
void print_dados_atraction_rep(Atraction*);
void screen_del_ok_atr(void);
void error_screen_file_atr(void);
