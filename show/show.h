typedef struct show Show;

struct show
{
char atraction[56];
char data[12];
char hour[6];
char quant[8];
char valor[10];
char id[5];
char status;
};

void modulo_show(void);
char show_menu(void);
void show_menu_screen(void);
Show *cred_show(void);
Show *cred_show_sem_id(void);
char *screen_busc_show(void);
char *screen_upd_show(void);
char *del_show(void);
void show_inputs(Show*);
void show_inputs_sem_id(Show*);
Show *procura_show(char*);
void print_dados_show(Show*);
void print_dados_show_upd(Show*);

void gravar_show(Show*);
void error_screen_file_show(void);
void pesquisa_show(void);
void remove_show(Show*);
void excluir_show(void);
void screen_del_ok_show(void);
void update_show(void);
void regravar_show(Show*);
