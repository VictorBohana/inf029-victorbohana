// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome:
//  email:
//  Matrícula:
//  Semestre:

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 20/06/2018 - 19/08/2016

// #################################################

#include <stdio.h>

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma = 0;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
    int fat = 1;
    return fat;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */

typedef struct DQ{
    char sDia[3];
    char sMes[3];
    char sAno[5];
    int isValid;

} DataQuebrada;
// {3,1,/,1,0,/,2,0,0,0}
// {3,1,/,1,0,/,2,0}
// {3,1,/,1,/,2,0,0,0}
// {3,1,/,1,/,2,0}
// {3,/,1,/,2,0,0,0}
// {3,/,1,/,2,0}
// {3,/,1,0,/,2,0,0,0}
// {3,/,1,0,/,2,0}
DataQuebrada quebraData(char* data){
    DataQuebrada dataQuebrada;
    if(data[2] == '/')
    {
        dataQuebrada.sDia[0] = data[0];
        dataQuebrada.sDia[1] = data[1];

        if(data[5] == '/')
        {
            dataQuebrada.sMes[0] = data[3];
            dataQuebrada.sMes[1] = data[4];

            if(data[10] == '\0')
            {
                dataQuebrada.sAno[0] = data[6];
                dataQuebrada.sAno[1] = data[7];
                dataQuebrada.sAno[2] = data[8];
                dataQuebrada.sAno[3] = data[9];

                dataQuebrada.isValid = 1;
            }
            else if(data[8] == '\0')
            {
                dataQuebrada.sAno[0] = data[6];
                dataQuebrada.sAno[1] = data[7];

                dataQuebrada.isValid = 1;
            }
            

        } 
        else if(data[4] == '/') 
        {
            dataQuebrada.sMes[0] = data[3];

            if(data[9] == '\0')
            {
                dataQuebrada.sAno[0] = data[5];
                dataQuebrada.sAno[1] = data[6];
                dataQuebrada.sAno[2] = data[7];
                dataQuebrada.sAno[3] = data[8];

                dataQuebrada.isValid = 1;
            }
            else if(data[7] == '\0')
            {
                dataQuebrada.sAno[0] = data[5];
                dataQuebrada.sAno[1] = data[6];

                dataQuebrada.isValid = 1;
            }
        }
    }
    else if(data[1] == '/')
    {
        dataQuebrada.sDia[0] = data[0];
        if(data[4] == '/')
        {
            dataQuebrada.sMes[0] = data[2];
            dataQuebrada.sMes[1] = data[3];

            if(data[9] == '\0')
            {
                dataQuebrada.sAno[0] = data[5];
                dataQuebrada.sAno[1] = data[6];
                dataQuebrada.sAno[2] = data[7];
                dataQuebrada.sAno[3] = data[8];

                dataQuebrada.isValid = 1;
            }
            else if(data[7] == '\0')
            {
                dataQuebrada.sAno[0] = data[5];
                dataQuebrada.sAno[1] = data[6];

                dataQuebrada.isValid = 1;
            }
        } 
        else if(data[3] == '/') 
        {
            dataQuebrada.sMes[0] = data[2];

            if(data[8] == '\0')
            {
                dataQuebrada.sAno[0] = data[4];
                dataQuebrada.sAno[1] = data[5];
                dataQuebrada.sAno[2] = data[6];
                dataQuebrada.sAno[3] = data[7];

                dataQuebrada.isValid = 1;
            }
            else if(data[6] == '\0')
            {
                dataQuebrada.sAno[0] = data[4];
                dataQuebrada.sAno[1] = data[5];

                dataQuebrada.isValid = 1;
            }
        }
    }
    else dataQuebrada.isValid = 0;

    return dataQuebrada;
}

int validarData(int dia, int mes, int ano)
{
    if(dia <= 0 || dia > 31) return 0;
    if(mes <= 0 || mes > 12) return 0;

    if(ano % 4 == 0 && ano % 100 != 0 || ano % 400 == 0)
    {
        switch(mes)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if(dia <= 31) return 1;
                
                break;
            case 2: 
                if(dia <= 29) return 1;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if(dia <= 30) return 1;
                break;
            default:
                return 0;
        }
    } 
    else 
    {
        switch(mes)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if(dia <= 31) return 1;
                break;
            case 2: 
                if(dia <= 28) return 1;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if(dia <= 30) return 1;
                break;
            default:
                return 0;
        }
    }
    return 0;
}

int q1(char *data)
{
    int datavalida = 1;

    //quebrar a string data em strings sDia, sMes, sAno
    DataQuebrada dataQuebrada = quebraData(data);

    //converter sDia, sMes e sAno em inteiros (ex: atoi)
    int iDia, iMes, iAno;

    iDia = atoi(dataQuebrada.sDia);
    iMes = atoi(dataQuebrada.sMes);
    iAno = atoi(dataQuebrada.sAno);

    datavalida = validarData(iDia, iMes, iAno);

    //printf("%s\n", data);
    printf("%s\n", data);

    if (datavalida)
        return 1;
    else
        return 0;
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
 */
int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos)
{

    //calcule os dados e armazene nas três variáveis a seguir
    int nDias, nMeses, nAnos;

    if (q1(datainicial) == 0)
        return 2;

    nDias = 4;
    nMeses = 10;
    nAnos = 2;

    /*mantenha o código abaixo, para salvar os dados em 
    nos parâmetros da funcao
    */
    *qtdDias = nDias;
    *qtdAnos = nAnos;
    *qtdMeses = nMeses;

    //coloque o retorno correto
    return 1;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = -1;

    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = -1;

    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
    char numString[100];
    snprintf(numString, 100, "%d", num);
    
    int tamanho;
    for(tamanho = 0; numString[tamanho] != '\0'; ++tamanho);
    if(tamanho == 1) return num;

    tamanho = tamanho - 1;

    char numStringInvertida[100];
    for(int i = tamanho; i >= 0; --i)
    {
        numStringInvertida[tamanho - i] = numString[i];
    }

    int numInvertido = atoi(numStringInvertida);
    return numInvertido;
}

/*
 Q5 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias = 0;
    char numBaseString[1000], numBuscaString[1000];
    snprintf(numBaseString, 1000, "%d", numerobase);
    snprintf(numBuscaString, 1000, "%d", numerobusca);

    int numBaseTam, numBuscaTam;
    for(numBaseTam = 0; numBaseString[numBaseTam] != '\0'; ++numBaseTam);
    for(numBuscaTam = 0; numBuscaString[numBuscaTam] != '\0'; ++numBuscaTam);

    int contador = 0;
    for(int i = 0; i < numBaseTam; ++i)
    {   
        for(int j = 0; j < numBuscaTam; ++j)
        {
            if(numBaseString[i + j] == numBuscaString[j]) ++contador;
        }

        if(contador == numBuscaTam)
        {
            ++qtdOcorrencias;
            if(numBuscaTam > 1) ++i;
        }

        contador = 0;
    }
    return qtdOcorrencias;
}
