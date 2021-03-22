#include <stdio.h>

int subtrai(int num1, int num2, int num3){
    return num1 - num2 - num3;
}

int main(){
    int num1 = 0, num2 = 0, num3 = 0;
    printf("Digite tres numeros que voce deseja subtrair: ");
    scanf("%d%d%d", &num1, &num2, &num3);

    int resultado = subtrai(num1, num2, num3);
    printf("%d - %d - %d = %d", num1, num2, num3, resultado);

    return 0;
}   