#include <stdio.h>

char* ler3Letras(){
    static char letras[3];
    for(int i = 0; i < 3; i++){
        printf("Digite a #%d letra: ", i + 1);
        scanf(" %c", &letras[i]);
    }
    return letras;
}

int main(){
    char* resultado = ler3Letras();
    for(int i = 0; i < 3; i++){
        printf("%c, ", resultado[i]);
    }

    return 0;
}