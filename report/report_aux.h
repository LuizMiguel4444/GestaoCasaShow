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
char* get_data_in(void);
char* get_data_fin(void);



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
