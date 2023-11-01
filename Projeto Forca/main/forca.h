#define TAMANHO_PALAVRA 20

typedef struct{
    int dif;
    char personagem[5][3];
}partida;

typedef struct{
    char* nome;
    float pontos;
}pontuacao;

void chuta(int* c, char a[26]);
void jachutou(int* achou,int i, int c, char p[TAMANHO_PALAVRA], char a[26]);
void imprimepalavra(char p[TAMANHO_PALAVRA], int c, char a[26]);
void escolhepalavra(char p[TAMANHO_PALAVRA]);
int acertou(char p[TAMANHO_PALAVRA], int c, char a[26]);
int chuteserrados(int c, char p[TAMANHO_PALAVRA], char a[26]);