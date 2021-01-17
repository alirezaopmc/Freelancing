#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char text[1024][1024], word[1025][1024];
    
    int n = 0;
    while( scanf("%[^\n]", text[n]) != EOF ) {
        n++;
    }

    for(int i = 0; i < n; i++) {
        char *token = strtok(text[i], " ");
        int j = 0;
        while(token != NULL) {
            strcpy(word[j++], token);
            token = strtok(NULL, " ");
        }
    }

    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if (strcmp(word[i], word[j]) > 0) {
                    strcpy(word[1024], text[i]);
                    strcpy(text[i], text[j]);
                    strcpy(text[j], word[0]);
            }
        }
    }

    int j = 1;
    strcpy(word[0], text[0]);
    for(int i = 1; i < n; i++) {
        if (strcmp(text[i], text[i-1]) != 0) {
            strcpy(word[j++], text[i]);
        }
    }

    for(int i=0; i < j; i++) {
        printf("%s\n", word[i]);
    }
}