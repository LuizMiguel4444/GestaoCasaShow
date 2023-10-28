typedef struct show Show;

struct show {
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
void read_show(Show*);
void upd_show(Show*);
void del_show(Show*);
void show_inputs(Show*);
void show_id_check(Show*);
void print_dados_show(Show*);

void gravar_show(Show*);
void error_screen_file_show(void);
