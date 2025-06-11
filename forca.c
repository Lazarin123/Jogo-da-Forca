#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "forca.h"

char secretword[20];
char chutes[26];
int chutesdados = 0;

void abertura () {
    printf("***********************\n");
    printf("*****Jogo da Forca*****\n");
    printf("***********************\n");
}

void chuta() {
    char chute;
    scanf(" %c", &chute);

    chutes[chutesdados] = chute;
    chutesdados++;
}

int jachutou (char letra) {
    int achou = 0;

    for (int j = 0; j < chutesdados; j++) {
        if (chutes[j] == letra) {
            achou = 1;
            break;
        }
    }
    return achou;
}

void desenhaforca () {
    for(int i = 0; i < strlen(secretword); i++) {

            int achou = jachutou(secretword[i]);

            if (achou) {
                printf("%c ", secretword[i]);
            } else {
            printf("_ ");
            }

        }
        printf("\n");

}

void adicionapalavra () {
    char deseja;

    printf("Voce deseja adicionar uma nova palavra ao jogo? (S/N)\n");
    scanf(" %c", &deseja);

    if(deseja == 'S' || deseja == 's') {

        printf("Adicionando nova palavra...\n");

        char novapalavra[20];
        printf("Qual a nova palavra? ");
        scanf("%s", novapalavra);

        FILE* f;
        f = fopen("nomes.txt", "r+");
            if(f == 0) {
                printf("Desculpe, mas o banco de dados nao esta disponivel.\n\n");
                exit(1);
            }

        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;
        
        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);        

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novapalavra);

        fclose(f);
    } 
}

void palavrasecreta () {
    FILE* f;

    f = fopen("nomes.txt", "r");
    if(f == 0) {
        printf("Desculpe, mas o banco de dados nao esta disponivel.\n\n");
        exit(1);
    }

    int qtdpalavras;
    fscanf(f, "%d", &qtdpalavras);

    srand(time(0));
    int randomico = rand() % qtdpalavras;

    for (int i = 0; i<= randomico; i++) {
        fscanf(f, "%s", secretword);
    }

    fclose(f);
}

int acertou () {
    for (int i = 0; i < strlen(secretword); i++){
        if(!jachutou(secretword[i])) {
            return 0; 
        }
    }
    return 1;
}

int enforcou () {
    int erros = 0;

    for (int i = 0; i < chutesdados; i++){
        int existe = 0;

        for (int j = 0; j < strlen(secretword); j++) {
            if (chutes[i] == secretword[j]) {
                existe = 1;
                break;
            }   
        } 
        if (!existe) erros++;
    }

    return erros >= 5;

}

int main () {
    palavrasecreta(secretword);
    abertura ();

    do {

        desenhaforca(secretword, chutes, chutesdados);   
        chuta(chutes, &chutesdados);

    } while (!acertou() && !enforcou());
    
    adicionapalavra();
}