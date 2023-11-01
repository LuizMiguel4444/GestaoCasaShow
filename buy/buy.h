typedef struct buy Buy;

struct buy {
char id_show[5];
char id_cli[5];
char quant[8];
char valor[10];
char id_ven[5];
char status;
};

void modulo_buy(void);
char buy_menu(void);
void buy_menu_screen(void);
Buy *cred_buy(void);
char *screen_read_buy(void);
void upd_buy(Buy*);
void buy_inputs(Buy*);
Buy *procura_buy(char*);
void print_dados_buy(Buy*);

void gravar_buy(Buy*);
void error_screen_file_buy(void);
void pesquisa_buy(void);
