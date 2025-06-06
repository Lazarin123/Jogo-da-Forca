#include <stdio.h>
#include <string.h>

void abertura () {
    printf("***********************\n");
    printf("*****Jogo da Forca*****\n");
    printf("***********************\n");
}

void chuta(char chutes[26], int* tentativas) {
    char chute;
    scanf(" %c", &chute);

    chutes[(*tentativas)] = chute;
    (*tentativas)++;
}

int jachutou (char letra, char chutes[26], int tentativas) {
    int achou = 0;

    for (int j = 0; j < tentativas; j++) {
        if (chutes[j] == letra) {
            achou = 1;
            break;
        }
    }
    return achou;
}

void desenhaforca (char secretword[20], char chutes[26], int tentativas) {
    for(int i = 0; i < strlen(secretword); i++) {

            int achou = jachutou(secretword[i], chutes, tentativas);

            if (achou) {
                printf("%c ", secretword[i]);
            } else {
            printf("_ ");
            }

        }
        printf("\n");

}

int main () {
    char secretword[20];
    
    sprintf(secretword, "MELANCIA");

    int acertou = 0;
    int enforcou = 0;

    char chutes[26];
    int tentativas = 0;

    abertura ();

    do {

        desenhaforca(secretword, chutes, tentativas);   

        chuta(chutes, &tentativas);

    } while (!acertou && !enforcou);

}