#include <stdio.h>

struct Numeros
{
    int num1;
    int num2;
    int num3;
    int num4;
};

struct Numeros ler4numeros(int num1, int num2, int num3, int num4){
    struct Numeros x;
    
    x.num1 = num1;
    x.num2 = num2;
    x.num3 = num3;
    x.num4 = num4;

    return x;
}

int main(){
    printf("Digite 4 numeros: ");
    int num1, num2, num3, num4;
    scanf("%d%d%d%d", &num1, &num2, &num3, &num4);

    struct Numeros resultado = ler4numeros(num1, num2, num3, num4);
    printf("%d %d %d %d\n", resultado.num1, resultado.num2, resultado.num3, resultado.num4);
    
    return 0;
}