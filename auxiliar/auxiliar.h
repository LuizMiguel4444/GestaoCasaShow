// Functions

char* get_nome(char* modulo);
char* get_nome_upd(char* modulo);
char* get_cache(char* modulo);
char* get_cache_upd(char* modulo);
char* get_email(char* modulo);
char* get_email_upd(char* modulo);
char* get_num(char* modulo, int tam);
char* get_num_upd(char* modulo);
char* get_id(char* modulo, int tam);
char* get_quant_cad(char* modulo);
char* get_quant_cad_upd(char* modulo);
char* get_quant_venda(char* modulo);
char* get_quant_venda_upd(char* modulo);
char* get_valor(char* modulo);
char* get_valor_upd(char* modulo);
char* get_cpf(void);
char* get_cpf_upd(void);
char* get_data(void);
char* get_data_upd(void);
char* get_hour(void);
char* get_hour_upd(void);
int check_quant_cad(char *c);
int check_quant_venda(char *c);
char certeza_upd(char* modulo);
char certeza_del(char* modulo);



// Screen Functions
void screen_null_id_error(char* modulo);
void screen_error_input(void);
void screen_error_input_name(void);
void screen_error_input_resp(void);
void screen_error_input_id(char* chave);
void screen_error_input_n_exist(char* chave);
