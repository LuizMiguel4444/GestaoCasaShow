// Functions
char report_menu_fil(void);
char report_menu_fil_buy(void);
void report_menu_screen_fil(void);
void report_menu_screen_fil_buy(void);
void modulo_report_atr(void);
void modulo_report_buy(void);
void modulo_report_cli(void);
void modulo_report_show(void);

char* contador_quantidade(char, int, int, int);
int comparar(const void *, const void *);
char* get_data_in(void);
char* get_data_fin(void);
char* get_nome_busc(void);

int aux_report_4_atr(Atraction*, FILE*, char);
int aux_report_5_atr(Atraction*, FILE*, char);
int aux_report_6_atr(Atraction*, FILE*, char);
void print_func_in_malloc_atr(Atraction*, Atraction*, char);
void free_func_in_malloc_atr(Atraction*, Atraction*);

int aux_report_2_buy(Buy*, FILE*, char, float*);
int aux_report_3_buy(Buy*, FILE*, char, float*);
int aux_report_4_buy(Buy*, FILE*, char, float*);
int aux_report_5_buy(Buy*, FILE*, char, float*);
void print_func_in_malloc_buy(Buy*, Buy*, char);
void free_func_in_malloc_buy(Buy*, Buy*);

int aux_report_4_cli(Client*, FILE*, char);
int aux_report_5_cli(Client*, FILE*, char);
int aux_report_6_cli(Client*, FILE*, char);
void print_func_in_malloc_cli(Client*, Client*, char);
void free_func_in_malloc_cli(Client*, Client*);

int aux_report_4_show(Show*, FILE*, char);
int aux_report_5_show(Show*, FILE*, char);
int aux_report_6_show(Show*, FILE*, char);
void print_func_in_malloc_show(Show*, Show*, char);
void free_func_in_malloc_show(Show*, Show*);



// Screen Functions
void screen_report_atr(void);
void screen_report_buy(void);
void screen_report_cli(void);
void screen_report_show(void);

void screen_quant_total_atr(char*);
void screen_quant_e_valor_total_buy(char*, char*);
void screen_quant_total_cli(char*);
void screen_quant_total_show(char*);

void print_if_in_filter_atr(Atraction*, char);
void print_if_in_filter_buy(Buy*, char);
void print_if_in_filter_cli(Client*, char);
void print_if_in_filter_show(Show*, char);
