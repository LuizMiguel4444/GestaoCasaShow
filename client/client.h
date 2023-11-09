typedef struct client Client;

struct client
{
    char nome[56];
    char cpf[16];
    char email[56];
    char num[12];
    char status;
    int day;
    int month;
    int year;
    int hour;
    int minute;
};

void modulo_client(void);
char client_menu(void);
void client_menu_screen(void);
Client *cred_client(void);
char *screen_busc_client(void);
char *screen_upd_client(void);
char *del_client(void);
void client_inputs(Client*);
Client *procura_client(char*);
int procura_cpf_client(char*);
int procura_cpf_client_fantasm(char*);
void print_dados_client(Client*);
void print_dados_client_upd(Client*);
void print_dados_client_rep(Client*);

void gravar_client(Client*);
void error_screen_file_cli(void);
void pesquisa_cli(void);
void remove_cli(Client*);
void excluir_cli(void);
void screen_del_ok_cli(void);
void screen_del_cli_block(void);
void update_cli(void);
void regravar_cli(Client*);
void screen_null_cpf_error(void);
void get_data_hour_cli(Client*);
void qual_campo_cli(Client*);
