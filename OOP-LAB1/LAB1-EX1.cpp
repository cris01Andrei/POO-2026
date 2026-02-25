#include <stdio.h>

int my_atoi(const char* s) {
    int res = 0;
    int i = 0;
    

    while (s[i] == ' ' || s[i] == '\n' || s[i] == '\r' || s[i] == '\t') i++;

   
    while (s[i] >= '0' && s[i] <= '9') {
        res = res * 10 + (s[i] - '0');
        i++;
    }
    return res;
}

int main() {
    FILE* f = fopen("in.txt", "r");
    if (f == NULL) {
        printf("Eroare la deschiderea fisierului!\n");
        return 1;
    }

    char line[256];
    long long totalSum = 0;

    while (fgets(line, sizeof(line), f)) {
        totalSum += my_atoi(line);
    }

    printf("%lld\n", totalSum);

    fclose(f);
    return 0;
}