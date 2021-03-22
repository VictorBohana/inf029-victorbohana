#include <stdio.h>

int fatorial(int num){
    int fat = 1;
    if(num < 0){
        return -1;
    }
    else if(num == 0){
        fat = 1;
    }
    else{
        for(int i = num; i > 0; i--){
            fat *= i;
        }
    }
    return fat;
}

int main(){
    int num1;
    printf("Digite o numero que voce quer calcular o fatorial: ");
    scanf("%d", &num1);

    int resultado = fatorial(num1);
    if(resultado == -1){
        printf("Nao foi possivel calcular o fatorial deste numero.\n");
    } else {
        printf("%d\n", resultado);
    }
    return 0;

}