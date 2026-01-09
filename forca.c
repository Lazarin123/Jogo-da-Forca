

char secretword[TAMANHO_PALAVRA];
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

    int erros = chuteserrados();

    printf("                \n");
    printf(" ________       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros >=1? '(' : ' '), (erros >=1?'_' : ' '),(erros >=1? ')' : ' '));
    printf(" |      %c%c%c  \n", (erros >=3? '\\' : ' '),(erros >=2? '|' : ' '),(erros >=3? '/' : ' '));
    printf(" |       %c     \n", (erros >=2? '|' : ' '));
    printf(" |      %c %c   \n", (erros >=4? '/' : ' '),(erros >=4? '\\' : ' '));
    printf(" |              \n");
    printf("_|__            \n");
    printf("\n\n");

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

        char novapalavra[TAMANHO_PALAVRA];
        printf("Qual a nova palavra? ");
        scanf("%s", novapalavra);

        printf("Adicionando nova palavra...\n");
        printf("Aguarde...\n\n");
        printf("Nova palavra adicionada com sucesso!\n\n");

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

int chuteserrados () {
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

    return erros;
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
    return chuteserrados() >= 5;
}

int main () {
    palavrasecreta(secretword);
    abertura ();

    do {

        desenhaforca(secretword, chutes, chutesdados);   
        chuta(chutes, &chutesdados);

    } while (!acertou() && !enforcou());

    if (acertou()) {
        printf("Parabens, voce acertou a palavra secreta: %s\n", secretword);

        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");
    } else {
        printf("Que pena, voce foi enforcado!\n");
        printf("A palavra era: ***%s***\n", secretword);

        printf("    _______________         \n");
        printf("   /               \\       \n"); 
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
    }

    adicionapalavra();
    printf("Fim de jogo!\n");
}
