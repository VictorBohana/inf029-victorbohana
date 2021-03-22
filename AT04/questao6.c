#include <stdio.h>

char* ler3Letras(char a, char b, char c){
    static char letras[3];
    letras[0] = a;
    letras[1] = b;
    letras[2] = c;

    return letras;
}

int main(){
    char a, b, c;
    printf("Digite 3 letras: ");
    scanf("%c %c %c", &a, &b, &c);

    char* resultado = ler3Letras(a, b, c);
    for(int i = 0; i < 3; i++){
        printf("%c, ", resultado[i]);
    }

    return 0;
}