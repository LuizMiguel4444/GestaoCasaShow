typedef struct atraction Atraction;

struct atraction
{
    char nome[56];
    char cache[16];
    char email[56];
    char num[12];
    char id[5];
    char status;
};

void modulo_atraction(void);
char atraction_menu(void);
void atraction_menu_screen(void);
Atraction *cred_atraction(void);
char *screen_read_atraction(void);
void upd_atraction(Atraction*);
void del_atraction(Atraction*);
void atraction_inputs(Atraction*);
Atraction *procura_atraction(char*);
void print_dados_atraction(Atraction*);

void gravar_atr(Atraction*);
void error_screen_file_atr(void);
void pesquisa_atr(void);
