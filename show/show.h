typedef struct show Show;

struct show
{
    char atraction[56];
    char data[12];
    char hora[6];
    char quant[8];
    char quant_rest[8];
    char valor[10];
    char id[5];
    char status;
    int day;
    int month;
    int year;
    int hour;
    int minute;
};

void modulo_show(void);
char show_menu(void);
void show_menu_screen(void);
Show *cred_show(void);
char *screen_busc_show(void);
char *screen_upd_show(void);
char *del_show(void);
void show_inputs(Show*);
Show *procura_show(char*);
int procura_id_show(char*);
char* retorna_valor_show(char*);
void print_dados_show(Show*);
void print_dados_show_upd(Show*);
void print_dados_show_rep(Show*);

void gravar_show(Show*);
void error_screen_file_show(void);
void pesquisa_show(void);
void remove_show(Show*);
void excluir_show(void);
void screen_del_ok_show(void);
void update_show(void);
void regravar_show(Show*);
void get_data_hour_sh(Show*);
void qual_campo_show(Show*);
char* gera_id_show(void);
