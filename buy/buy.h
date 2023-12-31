// Struct
typedef struct buy Buy;

struct buy
{
    char id_show[5];
    char cpf_cli[16];
    char quant[8];
    char valor[10];
    char id_ven[5];
    char status;
    char date[12];
    int hour;
    int minute;
    Buy* prox;
};



// Functions
void modulo_buy(void);
char buy_menu(void);
Buy *cred_buy(void);
void buy_inputs(Buy*);
void corrige_valor_final(char*, char*, char*);
int verify_buy_ticket(Buy*, Show*);
void get_data_hour_buy(Buy*);
char *screen_busc_buy(void);
char *screen_upd_buy(void);
void update_buy(void);
void update_tickets_rest(Buy*, Show*);
void qual_campo_buy(Buy*);



// File Functions
void gravar_buy(Buy*);
void pesquisa_buy(void);
Buy *procura_buy(char*);
void regravar_buy(Buy*);
void regravar_restante(Buy*, Show*);
char* gera_id_buy(void);



// Screen Functions
void buy_menu_screen(void);
void print_dados_buy(Buy*);
void print_dados_buy_upd(Buy*);
void print_dados_buy_rep(Buy*);
void error_screen_file_buy(void);
