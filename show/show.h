// Struct
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
    char date[12];
    int hour;
    int minute;
};



// Functions
void modulo_show(void);
char show_menu(void);
Show *cred_show(void);
void show_inputs(Show*);
void get_data_hour_sh(Show*);
char *screen_busc_show(void);
char *screen_upd_show(void);
void update_show(void);
void qual_campo_show(Show*);
char *del_show(void);



// File Functions
void gravar_show(Show*);
void pesquisa_show(void);
Show *procura_show(char*);
char* retorna_valor_show(char*);
void regravar_show(Show*);
void remove_show(Show*);
void excluir_show(void);
char* gera_id_show(void);



// Screen Functions
void show_menu_screen(void);
void print_dados_show(Show*);
void print_dados_show_upd(Show*);
void print_dados_show_rep(Show*);
void screen_del_ok_show(void);
void error_screen_file_show(void);
