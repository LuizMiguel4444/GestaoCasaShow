void limpa_buffer(void);
int val_entrada(char *entrada);
int ehDigito(char c);
int ehDigitoMax(char c, char max);
int ehLetra(char c);
int ehLetraeEspaco(char c);
int valNome(char *nome);
int ehBissexto(int aa);
int ehData(int dd, int mm, int aa);
int data_validacao(char data[]);
char* corrige_data(char *data);
int valData(char *data);
int val_id(char *id, int tam);
int val_email(char *email);
int ehDigitoDinheiro(char c);
float ehdinheiro(char *c);
int check_quant_cad(char *c);
int check_quant_venda(char *c);
int validarFone(char *fone);
int validarCPF(char *cpf);
int ehHora(char c);
int hour_validacao(char hour[]);
char* corrige_hour(char hour[]);
int val_hour(char hour[]);
char* input(void);
char* duplica(char* s);


char *leLinha(char *linha, int tamanhoMaximo);