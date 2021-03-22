#include <stdio.h>

int soma(int num1, int num2){
    return num1 + num2;
}

int main(){
    int num1 = 0, num2 = 0;
    printf("Digite dois numeros que voce deseja somar: ");
    scanf("%d%d", &num1, &num2);

    int resultado = soma(num1, num2);
    printf("%d + %d = %d", num1, num2, resultado);

    return 0;

}