typedef struct atraction Atraction;

struct atraction {
char nome[56];
char cache[16];
char email[56];
char num[12];
char id[5];
};

void modulo_atraction(void);
char atraction_menu(void);
void atraction_menu_screen(void);
Atraction *cred_atraction(void);
void read_atraction(const Atraction*);
void upd_atraction(Atraction*);
void del_atraction(Atraction*);
void atraction_val(Atraction*);
void atraction_id_check(const Atraction*);
void print_dados_atraction(const Atraction*);
