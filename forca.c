#include <stdio.h>
#include <string.h>

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

void palavrasecreta () {
    sprintf(secretword, "MELANCIA");
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
    
    int acertou = 0;

    palavrasecreta(secretword);
    abertura ();

    do {

        desenhaforca(secretword, chutes, chutesdados);   
        chuta(chutes, &chutesdados);

    } while (!acertou && !enforcou());

}