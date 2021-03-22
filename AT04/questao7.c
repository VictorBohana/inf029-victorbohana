#include <stdio.h>

struct Palavras
{
    char palavra1[30];
    char palavra2[30];
    char palavra3[30];
};


struct Palavras ler3palavras(char* p1, char* p2, char* p3){
    struct Palavras x;

    for(int i = 0; i < 30; i++){
        x.palavra1[i] = p1[i]; 
    }

    for(int i = 0; i < 30; i++){
        x.palavra2[i] = p2[i]; 
    }

    for(int i = 0; i < 30; i++){
        x.palavra3[i] = p3[i]; 
    }

    return x;
}

int main(){
    char p1[30], p2[30], p3[30];
    printf("Insira 3 palavras: ");
    scanf("%s%s%s", p1, p2, p3);

    struct Palavras resultado = ler3palavras(p1, p2, p3);
    
    printf("%s %s %s \n", resultado.palavra1, resultado.palavra2, resultado.palavra3);
    return 0;
}