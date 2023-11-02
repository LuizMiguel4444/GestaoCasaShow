typedef struct client Client;

struct client
{
char nome[56];
char cpf[16];
char email[56];
char num[12];
char id[5];
char status;
};

void modulo_client(void);
char client_menu(void);
void client_menu_screen(void);
Client *cred_client(void);
Client *cred_client_sem_id(void);
char *screen_busc_client(void);
char *screen_upd_client(void);
char *del_client(void);
void client_inputs(Client*);
void client_inputs_sem_id(Client*);
Client *procura_client(char*);
void print_dados_client(Client*);
void print_dados_client_upd(Client*);

void gravar_client(Client*);
void error_screen_file_cli(void);
void pesquisa_cli(void);
void remove_cli(Client*);
void excluir_cli(void);
void screen_del_ok_cli(void);
void update_cli(void);
void regravar_cli(Client*);
