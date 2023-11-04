typedef struct buy Buy;

struct buy {
    char id_show[5];
    char cpf_cli[16];
    char quant[8];
    char valor[10];
    char id_ven[5];
    char status;
    int day;
    int month;
    int year;
    int hour;
    int minute;
};

void modulo_buy(void);
char buy_menu(void);
void buy_menu_screen(void);
Buy *cred_buy(void);
Buy *cred_buy_sem_id(void);
char *screen_busc_buy(void);
char *screen_upd_buy(void);
void buy_inputs(Buy*, Show*, Client*);
void buy_inputs_sem_id(Buy*);
Buy *procura_buy(char*);
int procura_id_buy(char*);
void print_dados_buy(Buy*);
void print_dados_buy_upd(Buy*);
void print_dados_buy_rep(Buy*);

void gravar_buy(Buy*);
void error_screen_file_buy(void);
void pesquisa_buy(void);
void update_buy(void);
void regravar_buy(Buy*);
void get_data_hour_buy(Buy*);
