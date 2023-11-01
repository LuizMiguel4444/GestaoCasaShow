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
char *screen_read_show(void);
void upd_show(Show*);
char *del_show(void);
void show_inputs(Show*);
Show *procura_show(char*);
void print_dados_show(Show*);

void gravar_show(Show*);
void error_screen_file_show(void);
void pesquisa_show(void);
void remove_show(Show*);
void excluir_show(void);
void screen_del_ok_show(void);
