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
void read_client(Client*);
void upd_client(Client*);
void del_client(Client*);
void client_inputs(Client*);
void client_id_check(Client*);
void print_dados_client(Client*);
