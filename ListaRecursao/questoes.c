#include "stdio.h"

int questao1(int num){
    if(num <= 1) 
        return 1;
    else 
        return num * questao1(num - 1);
}

int questao2(int num){
    if(num == 0){
        return 0;
    }
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

void questao7(int *vetor, int contador){
    int aux;
    if(contador < 100)
    {
        aux = vetor[contador];
        vetor[contador] = vetor[99 - contador];
        vetor[99 - contador] = aux;
        questao7(vetor, contador + 1);
    }
}

int questao8(int num1, int num2){
    if(num2 == 0){
        return num1;
    } else {
        return questao8(num2, num1 % num2);
    }
}

int questao10(int num, int numBusca, int *numOcorrencias){
    if(num == 0) return 0;
    else{
        if(num % 10 == numBusca){
            *numOcorrencias = *numOcorrencias + 1;
        }
        num = num / 10;
        return questao10(num, numBusca, numOcorrencias);
    }
}

int questao11(int multiplicando, int multiplicador) {
	if(multiplicando == 0 || multiplicador == 0){
        return 0;
    }
	else{
        if(multiplicador > 0){
            return multiplicando + questao11(multiplicando, multiplicador - 1);
        }
    }	
}

void questao12(int num) {
	if(num > 0){
        questao12(num - 1);
    }

	printf("%d ", num);
}

void questao13(int num) {
    printf("%d ", num);

	if(num > 0){
        questao13(num - 1);
    }
}

void questao14(int num) {
	if(num > 0){
		questao14(num - 1);
    }

	if(num % 2 == 0){
        printf("%d ", num);
    }
}

void questao15(int num) {
	if(num % 2 == 0){
        printf("%d ", num);
    }

	if(num > 0){
        questao15(num - 1);
    }
}

int questao16(int num) {
	if(num == 1 || num % 2 == 0){
        return 1;
    } else{
        return num * questao16(num - 2);
    }
}