typedef struct atraction Atraction;

struct atraction
{
    char nome[56];
    char cache[16];
    char email[56];
    char num[12];
    char id[5];
    char status;
    int day;
    int month;
    int year;
    int hour;
    int minute;
};

void modulo_atraction(void);
char atraction_menu(void);
void atraction_menu_screen(void);
Atraction *cred_atraction(void);
char *screen_busc_atraction(void);
char *screen_upd_atraction(void);
char *del_atraction(void);
void atraction_inputs(Atraction*);
Atraction *procura_atraction(char*);
int procura_id_atraction(char*);
void print_dados_atraction(Atraction*);
void print_dados_atraction_upd(Atraction*);
void print_dados_atraction_rep(Atraction*);

void gravar_atr(Atraction*);
void error_screen_file_atr(void);
void pesquisa_atr(void);
void remove_atr(Atraction*);
void excluir_atr(void);
void screen_del_ok_atr(void);
void update_atr(void);
void regravar_atr(Atraction*);
void get_data_hour_atr(Atraction*);
void qual_campo_atr(Atraction*);
char* gera_id_atr(void);
