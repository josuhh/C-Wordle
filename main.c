#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
 
#define MAX_PALAVRAS 5481
#define TAM_MAX 6
 
int main() {
    FILE *wordBase;
    
    wordBase = fopen("wordBase.txt", "r");
    if (wordBase == NULL) {
        printf("Erro: Arquivo wordBase.txt nao encontrado!\n");
        return 1;
    }

    char palavras_secretas[MAX_PALAVRAS][TAM_MAX];
    int count = 0;
    
    char secret[6];
    char input[6];
    
    while (fscanf(wordBase, "%s", palavras_secretas[count]) != EOF) {
        count++;
    }
    fclose(wordBase);
    
    srand(time(NULL));
    int indice_sorteado = rand() % count;
    strcpy(secret, palavras_secretas[indice_sorteado]);
    
    printf("Bem-vindo ao Term.ooo em C!\n");
    for (int tentativa = 0; tentativa < 6; tentativa++) {
        printf("Tentativa: %d\n", tentativa + 1);
        scanf("%5s", input);
        
        for (int i = 0; i < 5; i++) input[i] = tolower(input[i]);

        int status[5] = {0};
        int secret_usada[5] = {0};

        for (int i = 0; i < 5; i++) {
            if (input[i]==secret[i]) {
                status[i] = 1;
                secret_usada[i] = 1;
            }
        }
        for (int i = 0; i < 5; i++) {
            if (status[i] == 0) {
                for (int c = 0; c < 5; c++) {
                    if (secret_usada[c] == 0 &&  input[i] == secret[c]) {
                        status[i] = 2;
                        secret_usada[c] = 1;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < 5; i++) {
            printf("%d|", status[i]);
        }
        printf("\n");
 
        if (strcmp(input, secret) == 0) {
            printf("Voce acertou em %d tentativas!\n", tentativa + 1);
            return 0; 
        }
    }
    printf("Suas tentativas acabaram! A palavra era: %s\n", secret);
    return 0;
}