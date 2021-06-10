#include "stdio.h"

int questao1(int num){
    if(num <= 1) 
        return 1;
    else 
        return num * questao1(num - 1);
}

int questao2(int num){
    if(num == 1 || num == 2) 
        return 1;
    else 
        return questao2(num - 1) + questao2(num - 2);
}

int questao3(int num){
    if(num == 0) 
        return num;
    else{
        printf("%d", num % 10);
        num = num / 10;
        return questao3(num);
    }
}

int questao4(int *vetor, int tamanho){
    if(tamanho == 0)
        return 0;
    else{
        return vetor[tamanho - 1] + questao4(vetor, tamanho - 1);
    }
}

int questao5(int num){
    if(num == 0){
        return 0;
    }
    else{
        return num + questao5(num - 1);
    }
}

int questao6(int k, int n){
    if(n == 0)
        return 1;
    else{
        return k * questao6(k, n - 1);
    }
}