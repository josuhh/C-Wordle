#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
 
#define MAX_WORDS 5481
#define MAX_LENGTH 6
 
int main() {
    FILE *wordBase;
    
    wordBase = fopen("wordBase.txt", "r");
    if (wordBase == NULL) {
        printf("Error: wordBase.txt not found!\n");
        return 1;
    }

    char secret_words[MAX_WORDS][MAX_LENGTH];
    int count = 0;
    
    char secret[6];
    char input[6];
    
    while (fscanf(wordBase, "%s", secret_words[count]) != EOF) {
        count++;
    }
    fclose(wordBase);
    
    srand(time(NULL));
    int random_index = rand() % count;
    strcpy(secret, secret_words[random_index]);
    
    printf("Welcome to C-Wordle!\n");
    for (int attempt = 0; attempt < 6; attempt++) {
        printf("Attempt: %d\n", attempt + 1);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        while (strlen(input) != 5 || strchr(input, ' ') != NULL) {
            if (strchr(input, ' ') != NULL) {
                printf("Word must not contain spaces. Try again: \n");
            }
            else {
                printf("Word must be 5 letters. Try again: \n");
            }
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = '\0';
        }
        
        for (int i = 0; i < 5; i++) input[i] = tolower(input[i]);

        int status[5] = {0};
        int secret_used[5] = {0};

        for (int i = 0; i < 5; i++) {
            if (input[i]==secret[i]) {
                status[i] = 1;
                secret_used[i] = 1;
            }
        }
        for (int i = 0; i < 5; i++) {
            if (status[i] == 0) {
                for (int c = 0; c < 5; c++) {
                    if (secret_used[c] == 0 &&  input[i] == secret[c]) {
                        status[i] = 2;
                        secret_used[c] = 1;
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
            printf("You got it right on your %dth attempt!\n", attempt + 1);
            return 0; 
        }
    }
    printf("You have no more attempts! The word was: %s\n", secret);
    return 0;
}