#include "stdio.h"
#include "operacoes.h"

int main(){
    double num1, num2;
    printf("Digite um numero: ");
    scanf("%lf", &num1);
    printf("Digite outro numero: ");
    scanf("%lf", &num2);

    int op;
    printf("Digite 1 para somar, 2 para subtrair, 3 para multiplicar ou 4 para dividir: ");
    scanf("%d", &op);

    double resultado;
    if(op == 1){
        resultado = somar(num1, num2);
    }
    else if(op == 2){
        resultado = subtrair(num1, num2);
    }
    else if(op == 3){
        resultado = multiplicar(num1, num2);
    }
    else if(op == 4){
        resultado = dividir(num1, num2);
    }

    printf("Resultado: %.2lf\n", resultado);
    return 0;
}