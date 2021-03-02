#include <stdio.h>

int main(){
    printf("Ola usuario, escolha uma das opcoes abaixo \n0 - Sair\n1 - Somar\n2 - Subtrair\n3 - Multiplicar\n4 - Dividir\n");
    int opcao;
    scanf("%d", &opcao);
    
    int num1 = 0;
    int num2 = 0;
    switch(opcao){
        case 0:
            printf("Tchau!\n");
            break;
        case 1:
            printf("Digite os numeros que deseja somar: ");
            scanf("%d %d",&num1, &num2);
            printf("%d + %d = %d\n", num1, num2, num1+ num2);
            break;
        case 2:
            printf("Digite os numeros que deseja subtrair: ");
            scanf("%d %d",&num1, &num2);
            printf("%d - %d = %d\n", num1, num2, num1 - num2);
            break;
        case 3:
            printf("Digite os numeros que deseja multiplicar: ");
            scanf("%d %d",&num1, &num2);
            printf("%d x %d = %d\n", num1, num2, num1 * num2);
            break;
        case 4:
            printf("Digite os numeros que deseja dividir: ");
            scanf("%d %d",&num1, &num2);
            printf("%d / %d = %d\n", num1, num2, num1 / num2);
            break;
        default:
            printf("Opcao nao reconhecida.\n");
            break;
    }
    return 0;
}