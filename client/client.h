// Struct
typedef struct client Client;

struct client
{
    char nome[56];
    char cpf[16];
    char email[56];
    char num[12];
    char status;
    char date[12];
    int hour;
    int minute;
};



// Functions
void modulo_client(void);
char client_menu(void);
Client *cred_client(void);
void client_inputs(Client*);
void get_data_hour_cli(Client*);
char *screen_busc_client(void);
char *screen_upd_client(void);
void update_cli(void);
void qual_campo_cli(Client*);
char *del_client(void);



// File Functions
void gravar_client(Client*);
void pesquisa_cli(void);
Client *procura_client(char*);
int procura_cpf_client(char*);
int procura_cpf_client_fantasm(char*);
void regravar_cli(Client*);
void remove_cli(Client*);
void excluir_cli(void);



// Screen Functions
void client_menu_screen(void);
void print_dados_client(Client*);
void print_dados_client_upd(Client*);
void print_dados_client_rep(Client*);
void screen_del_ok_cli(void);
void screen_del_cli_block(void);
void screen_null_cpf_error(void);
void error_screen_file_cli(void);
