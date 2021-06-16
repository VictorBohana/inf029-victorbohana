#include "stdio.h"
#include "questoes.h"

int main(){
    testeQ1();
    testeQ2();
    testeQ3();
    testeQ4();
    testeQ5();
    testeQ6();
    testeQ7();
    testeQ8();
    testeQ10();
    testeQ11();
    testeQ12();
    testeQ13();
    testeQ14();
    testeQ15();
    testeQ16();
}

void printQuestao(char* questao){
    printf("=== %s ===\n", questao);
}

void printFinal(){
    printf("==================\n");
}

void testeQ1(){
    printQuestao("Questao 01");
    int x = 5;
    printf("Fatorial de %d: %d\n", x, questao1(x));
    printFinal();
}

void testeQ2(){
    printQuestao("Questao 02");
    int x = 5;
    printf("Sequencia Fibonnaci ate o %d termo: ", x);
    for(int i = 0; i < x; i++)
    {
        int res = questao2(i);
        printf("%d ", res);
    }
    printf("\n");
    printFinal();
}

void testeQ3(){
    printQuestao("Questao 03");
    int x = 123;
    printf("Inverso de %d = ", x);
    questao3(x);
    printf("\n");
    printFinal();
}

void testeQ4(){
    printQuestao("Questao 04");
    int x[5] = {1, 2, 3, 4, 5};
    int tam = sizeof(x) / sizeof(int);
    printf("Somatorio de todos os elementos do vetor x: ");
    for(int i = 0; i < tam; i++){
        if(i != tam - 1){
            printf("%d + ", x[i]);
        } else{
            printf("%d = ", x[i]);
        }
    }
    printf("%d", questao4(x, tam));

    printf("\n");
    printFinal();
}

void testeQ5(){
    printQuestao("Questao 05");
    int x = 10;
    printf("Somatorio de 1 a %d = %d", x, questao5(x));

    printf("\n");
    printFinal();
}

void testeQ6(){
    printQuestao("Questao 06");
    int k = 3;
    int n = 4;
    printf("%d elevado a %d = %d", k, n, questao6(k, n));

    printf("\n");
    printFinal();
}

void testeQ7(){
    printQuestao("Questao 07");
    int tam = 100;
    int vetor[tam];

    printf("Vetor original: ");
    for(int i = 0; i < tam; i++)
    {
        vetor[i] = i + 1;
        if(i % 10 == 0) printf("\n");
        printf("%d ", vetor[i]);
    }
    printf("\n\n");
    printf("Vetor invertido: ");
    questao7(vetor, 0);

    for(int i = 0; i < tam; i++)
    {
        if(i % 10 == 0) printf("\n");
        printf("%d ", vetor[i]);
    }

    printf("\n");
    printFinal();
}

void testeQ8(){
    printQuestao("Questao 08");
    int k = 12;
    int n = 9;
    printf("MDC de %d e %d = %d\n", k, n, questao8(k, n));
    printFinal();
}

void testeQ10(){
    printQuestao("Questao 10");
    int k = 2;
    int n = 2022;
    int ocorrencias = 0;
    questao10(n, k, &ocorrencias);
    printf("O numero %d ocorre em %d %d vezes\n", k, n, ocorrencias);
    printFinal();
}

void testeQ11(){
    printQuestao("Questao 11");
    int multiplicador = 6;
    int multiplicando = 4;
    printf("Multiplicando %d por %d usando soma: %d\n", multiplicando, multiplicador, questao11(multiplicando, multiplicador));
    printFinal();
}

void testeQ12(){
    printQuestao("Questao 12");
    int num = 10;
    printf("Numeros de 0 a %d em ordem crescente: ", num);
    questao12(num);

    printf("\n");
    printFinal();
}

void testeQ13(){
    printQuestao("Questao 13");
    int num = 10;
    printf("Numeros de 0 a %d em ordem decrescente: ", num);
    questao13(num);

    printf("\n");
    printFinal();
}

void testeQ14(){
    printQuestao("Questao 14");
    int num = 10;
    printf("Numeros pares de 0 a %d em ordem crescente: ", num);
    questao14(num);

    printf("\n");
    printFinal();
}

void testeQ15(){
    printQuestao("Questao 15");
    int num = 10;
    printf("Numeros pares de 0 a %d em ordem decrescente: ", num);
    questao15(num);

    printf("\n");
    printFinal();
}

void testeQ16(){
    printQuestao("Questao 16");
    int x = 5;
    printf("O Fatorial duplo de %d = %d\n", x, questao16(x));
    printFinal();
}