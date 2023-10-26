typedef struct buy Buy;

struct buy {
char id_show[5];
char id_cli[5];
char quant[8];
char valor[10];
char status;
};

void modulo_buy(void);
char buy_menu(void);
void buy_menu_screen(void);
Buy *cred_buy(void);
void read_buy(const Buy*);
void upd_buy(Buy*);
void buy_val(Buy*);
void buy_id_check(const Buy*);
void print_dados_buy(const Buy*);
