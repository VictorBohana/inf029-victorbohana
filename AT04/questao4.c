#include <stdio.h>

int * ler3Numeros(int num1, int num2, int num3){
    static int array[3];
    
    array[0] = num1;
    array[1] = num2;
    array[2] = num3;

    return array;
}

int main(){
    int num1, num2, num3;
    printf("Insira 3 numeros: ");
    scanf("%d%d%d", &num1, &num2, &num3);

    int* vetor = ler3Numeros(num1, num2, num3);
    printf("\nNumeros: %d, %d, %d", vetor[0], vetor[1], vetor[2]);

    return 0;
}