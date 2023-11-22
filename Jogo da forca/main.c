#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "forca.c"
#include "termforca.h"

char palavrasecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutesdados = 0;
partida jogo;
pontuacao jogo_pontuacao;

int main(void){

    abertura();
    inserenome();

    inseredif();

    escolhepalavra(palavrasecreta, &jogo);
    criaboneco(&jogo);

    do{
        desenhaforca();
        imprimechutes();
        imprimepalavra(palavrasecreta, chutesdados, chutes);
        chuta(&chutesdados, chutes);

        limpa();
        abertura();

    }while(!acertou(palavrasecreta, chutesdados, chutes) && !enforcou());

    desenhaforca();

    if(acertou(palavrasecreta, chutesdados, chutes)){
        imprimepalavra(palavrasecreta, chutesdados, chutes);
        printf("\n\nPARABENS!!! VOCE GANHOU!\n\n\n");
    }else{
        printf("\nVoce perdeu, boa sorte na proxima vez!\n");
        printf("A palavra era **%s**\n\n",palavrasecreta);
    }
}

void abertura(){
    printf("*****************\n");
    printf("* JOGO DE FORCA *\n");
    printf("*****************\n\n");
}

void desenhaforca(){

    int erros = chuteserrados(chutesdados, palavrasecreta, chutes);

    printf("                  \n");
    printf("  ________        \n");
    printf(" |/       |       \n");
    printf(" |       %c%c%c   \n", (erros >= 1 ? jogo.personagem[0][0]:' '), (erros >= 1 ? jogo.personagem[0][1]:' '), (erros >= 1 ? jogo.personagem[0][2]:' '));
    printf(" |       %c%c%c   \n", (erros >= 3 ? jogo.personagem[1][0]:' '), (erros >= 2 ? jogo.personagem[1][1]:' '), (erros >= 4 ? jogo.personagem[1][2]:' '));
    printf(" |        %c      \n", (erros >= 2 ? jogo.personagem[2][1]:' '));
    printf(" |       %c %c    \n", (erros >= 5 ? jogo.personagem[3][0]:' '),( erros >= 6 ? jogo.personagem[3][2]:' '));
    printf(" |                \n");
    printf("_|___             \n");
    printf("\n\n");

}

int enforcou(){
    return chuteserrados(chutesdados, palavrasecreta, chutes) >= 6;
}

void alocanome(){
    char buffer[100];
    printf("Digite seu nome: ");
    scanf("%99s", buffer);

    jogo_pontuacao.nome = malloc(strlen(buffer)+1);

    strcpy(jogo_pontuacao.nome, buffer);
}

int nomevalido(){
    bool nome_valido = true;
    for(int i=0; jogo_pontuacao.nome[i] != '\0'; i++){
        if(!isalpha(jogo_pontuacao.nome[i])){
            nome_valido = false;
            break;
        }
        jogo_pontuacao.nome[i] = toupper(jogo_pontuacao.nome[i]); 
    }
    if(!nome_valido){
        printf("Por favor, digite um nome válido apenas com letras do alfabeto.\n");
        free(jogo_pontuacao.nome);
        return 0;
    }else{
        limpa();
        abertura();
        printf("Bem-vindo, %s!\n", jogo_pontuacao.nome);
        return 1;
    }
}

void inserenome(){
    do{
        alocanome();
    }while(!nomevalido());
}

void entradadifvalida(){
    int buffer;

    printf("Escolha a dificuldade: \n");
    printf("1 - Facil\n");
    printf("2 - Media\n");
    printf("3 - Dificil\n");
    printf("- ");
    buffer = scanf("%d", &jogo.dif);

    while(buffer != 1){
        while(getchar() != '\n'){}
        printf("\nEntrada invalida, por favor digite uma das opcoes - ");
        buffer = scanf("%d", &jogo.dif);
    }
}

int difvalida(){
    bool dif_valida = true;
    switch(jogo.dif){
        case 1:
        limpa();
        abertura();
        printf("Facil, ta so se aquecendo ne?\n");
        break;
        case 2:
        limpa();
        abertura();
        printf("Medio, o famoso tradicional!\n");
        break;
        case 3:
        limpa();
        abertura();
        printf("Dificil, entao voce gosta de desafio!\n");
        break;
        default:
        printf("Por favor, insira uma das opcoes de 1 a 3.\n");
        dif_valida = false;
        break;
    }
    if(!dif_valida){
        return 0;
    }else{
        return 1;
    }
}

void inseredif(){
    do{
        entradadifvalida();
        
    }while(!difvalida());
}

void pontos(){
    float timer;

    jogo_pontuacao.pontos = jogo_pontuacao.pontos - timer;

    /*Em desenvolvimento...*/
}

void pontostotais(){
    int erros = chuteserrados(chutesdados, palavrasecreta, chutes);

    /*Em desenvolvimento...*/
}

void criaboneco(partida* jogo){
    char personagem_temp[4][3] = {
        {'(','_',')'},
        {'_','|','_'},
        {' ','|',' '},
        {'/',' ','\\'}
    };

    for(int i=0; i<4; i++){
        for(int j=0; j<3; j++){
            jogo->personagem[i][j] = personagem_temp[i][j];
        }
    }
}

void limpa(){
    system("clear");
}

void imprimechutes(){
    printf("Seus chutes errados:");
    for(int i=0; i<chutesdados; i++){
        if(chuteerrado(i)){
            printf(" %c",chutes[i]);
        }
    }
    printf("\n\n");
}

int chuteerrado(int i){
    for(int j=0; j<strlen(palavrasecreta); j++){
        if(chutes[i] == palavrasecreta[j]){
            return 0;
        }
    }
    return 1;
}