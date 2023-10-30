typedef struct client Client;

struct client {
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
char *screen_read_client(void);
void upd_client(Client*);
void del_client(Client*);
void client_inputs(Client*);
Client *procura_client(char*);
void print_dados_client(Client*);

void gravar_client(Client*);
void error_screen_file_cli(void);
void pesquisa_cli(void);
