#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000];
    char words[100][100];
    int count = 0;

    printf("Introduceti propozitia: ");
    scanf("%[^\n]", sentence);

   
    char* p = strtok(sentence, " ");
    while (p != NULL) {
        strcpy(words[count++], p);
        p = strtok(NULL, " ");
    }

   
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            int lenI = strlen(words[i]);
            int lenJ = strlen(words[j]);

            int swapNeeded = 0;
            if (lenI < lenJ) {
                swapNeeded = 1;
            } else if (lenI == lenJ) {
                if (strcmp(words[i], words[j]) > 0) {
                    swapNeeded = 1;
                }
            }

            if (swapNeeded) {
                char temp[100];
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
        }
    }

   
    for (int i = 0; i < count; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}