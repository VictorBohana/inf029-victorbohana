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
//  Nome: Joao Victor Rodrigues Bohana
//  email: victorbohana@gmail.com
//  Matrícula: 20192160021
//  Semestre: 2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 20/06/2018 - 19/08/2016

// #################################################

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <wctype.h>
#include <stddef.h>

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
    char sAno[4];
    int isValid;

} DataQuebrada;

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
            if(ano % 4 == 0 && ano % 100 != 0 || ano % 400 == 0)
            {
                if(dia <= 29) return 1;
            }
            else 
            {
                if(dia <= 28) return 1;
            }
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
    DataQuebrada dataInicialQ = quebraData(datainicial);
    DataQuebrada dataFinalQ = quebraData(datafinal);

    int diaInicial, mesInicial, anoInicial, diaFinal, mesFinal, anoFinal;

    diaInicial = atoi(dataInicialQ.sDia);
    mesInicial = atoi(dataInicialQ.sMes);
    anoInicial = atoi(dataInicialQ.sAno);

    diaFinal = atoi(dataFinalQ.sDia);
    mesFinal = atoi(dataFinalQ.sMes);
    anoFinal = atoi(dataFinalQ.sAno);

    int isDataInicialValida, isDataFinalValida;

    isDataInicialValida = validarData(diaInicial, mesInicial, anoInicial);
    isDataFinalValida = validarData(diaFinal, mesFinal, anoFinal);

    if(isDataInicialValida == 0) {  
        return 2;
    }

    if(isDataFinalValida == 0){ 
        return 3;
    }

    if(anoInicial > anoFinal || anoInicial == anoFinal && mesInicial > mesFinal || anoInicial == anoFinal && mesInicial == mesFinal 
        && diaInicial > diaFinal) return 4;

    //calcule os dados e armazene nas três variáveis a seguir
    int nDias = 0, nMeses = 0, nAnos = 0;

    nDias = diaFinal - diaInicial;
    if(nDias < 0)
    {
        nMeses = nMeses - 1;
        switch (mesInicial)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                nDias = nDias + 31;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                nDias = nDias + 30;
                break;
            case 2:
                if(anoInicial % 4 == 0 && anoInicial % 100 != 0 || anoInicial % 400 == 0)
                {
                    nDias = nDias + 29;
                }
                else nDias = nDias + 28;
                break;
            default:
                break;
        }
    }
    nMeses = mesFinal - mesInicial;
    nAnos = anoFinal - anoInicial;

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

void removeAcento(wchar_t *texto)
{
    for(int i = 0; texto[i] != '\0'; i++)
    {
        if(texto[i] == L'Á' || texto[i] == L'À' || texto[i] == L'Ã' || texto[i] == L'Â' || texto[i] == L'Ä') texto[i] = 'A';
        else if(texto[i] == L'á' || texto[i] == L'à' || texto[i] == L'ã' || texto[i] == L'â' || texto[i] == L'ä') texto[i] = 'a';
        else if(texto[i] == L'É' || texto[i] == L'È' || texto[i] == L'Ẽ' || texto[i] == L'Ê' || texto[i] == L'Ë') texto[i] = 'E';
        else if(texto[i] == L'é' || texto[i] == L'è' || texto[i] == L'ẽ' || texto[i] == L'ê' || texto[i] == L'ë') texto[i] = 'e';
        else if(texto[i] == L'Í' || texto[i] == L'Ì' || texto[i] == L'Ĩ' || texto[i] == L'Î' || texto[i] == L'Ï') texto[i] = 'I';
        else if(texto[i] == L'í' || texto[i] == L'ì' || texto[i] == L'ĩ' || texto[i] == L'î' || texto[i] == L'ï') texto[i] = 'i';
        else if(texto[i] == L'Ó' || texto[i] == L'Ò' || texto[i] == L'Õ' || texto[i] == L'Ô' || texto[i] == L'Ö') texto[i] = 'O';
        else if(texto[i] == L'ó' || texto[i] == L'ò' || texto[i] == L'õ' || texto[i] == L'ô' || texto[i] == L'ö') texto[i] = 'o';
        else if(texto[i] == L'Ú' || texto[i] == L'Ù' || texto[i] == L'Ũ' || texto[i] == L'Û' || texto[i] == L'Ü') texto[i] = 'U';
        else if(texto[i] == L'ú' || texto[i] == L'ù' || texto[i] == L'ũ' || texto[i] == L'û' || texto[i] == L'ü') texto[i] = 'u';
        else if(texto[i] == L'Ç') texto[i] = 'C';
        else if(texto[i] == L'ç') texto[i] = 'c';
    }
}

int q3(wchar_t *texto, wchar_t c, int isCaseSensitive)
{
    removeAcento(texto);
    removeAcento(&c);

    int qtdOcorrencias = 0;

    if(!isCaseSensitive){
        c = towlower(c);

        for(int i = 0; texto[i] != '\0'; i++)
        {
            if(towlower(texto[i]) == c) ++qtdOcorrencias;
        }
    }
    else if(isCaseSensitive){
        for(int i = 0; texto[i] != '\0'; i++)
        {
            if(texto[i] == c) ++qtdOcorrencias; 
        }
    }

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
int q4(wchar_t *strTexto, wchar_t *strBusca, int posicoes[30])
{
    int qtdOcorrencias = 0;
    removeAcento(strTexto);
    removeAcento(strBusca);

    int strBuscaLen = 0;
    int posicoesIndex = 0;
    for(int i = 0; strBusca[i] != '\0'; i++) {
        strBuscaLen++;
    }

    for(int i = 0; strTexto[i] != '\0'; i++)
    {
        int contador = 0;
        for(int j = 0; j < strBuscaLen + 1; j++)
        {
            if(strTexto[i + j] == strBusca[j]) contador++;
        }

        if(contador == strBuscaLen)
        {
            qtdOcorrencias++;
            posicoes[posicoesIndex] = i + 1;
            posicoes[posicoesIndex + 1] = i + strBuscaLen;
            posicoesIndex = posicoesIndex + 2;
        }
    }

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

int calcularPotencia(int expoente)
{
    int base = 10;
    for(int i = 0; i < expoente - 1; i++)
    {
        base *= 10;
    }

    return base;
}

void separarNumeros(int numero, int* array)
{
    if(numero < 10)
    {
        array[0] = numero;
        return;
    }
    else
    {
        int algarismo = 0;
        algarismo = numero % 10;
        array[0] = algarismo;
        numero = numero - algarismo;

        for(int i = 2; numero > 0; i++)
        {
            int potencia = calcularPotencia(i);
            algarismo = numero % (potencia);
            int potencia2 = calcularPotencia(i - 1);

            algarismo = algarismo / potencia2;

            array[i - 1] = algarismo;
            numero = numero - (algarismo * (potencia / 10));
        }
    }
}

int q5(int num)
{
    int numerosIsolados[50];
    for(int i = 0; i < 50; i++) numerosIsolados[i] = -1;

    separarNumeros(num, numerosIsolados);

    int quantidadeDeAlgarismos = 0;
    for(int i = 0; numerosIsolados[i] != -1; i++) ++quantidadeDeAlgarismos;
    quantidadeDeAlgarismos = quantidadeDeAlgarismos - 1;
    int numeroInvertido = 0;
    for(int j = quantidadeDeAlgarismos; j >= 0; j--)
    {
        int potencia = calcularPotencia(j);
        if(j != 0) numeroInvertido = numeroInvertido + (numerosIsolados[quantidadeDeAlgarismos - j] * potencia);

        if(j == 0) numeroInvertido = numeroInvertido + numerosIsolados[quantidadeDeAlgarismos - j];
    }

    return numeroInvertido;
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
    int numeroBaseIsolado[100];
    for(int i = 0; i < 100; i++) numeroBaseIsolado[i] = -1;

    int numeroBuscaIsolado[100];
    for(int i = 0; i < 100; i++) numeroBuscaIsolado[i] = -1;

    separarNumeros(numerobusca, numeroBuscaIsolado);
    separarNumeros(numerobase, numeroBaseIsolado);
    
    int numeroAlgarismosBusca = 0, numeroAlgarismosBase = 0;

    for(int i = 0; numeroBaseIsolado[i] != -1; i++) numeroAlgarismosBase++; 
    for(int i = 0; numeroBuscaIsolado[i] != -1; i++) numeroAlgarismosBusca++; 

    int qtdOcorrencias = 0;
    for(int i = 0; i < numeroAlgarismosBase; i++)
    {
        int contador = 0;
        for(int j = 0; j < numeroAlgarismosBusca; j++)
        {
            if(numeroBaseIsolado[i + j] == numeroBuscaIsolado[j]) ++contador;
        }

        if(contador == numeroAlgarismosBusca) { ++qtdOcorrencias; if(numeroAlgarismosBusca > 1) ++i; }
    }

    return qtdOcorrencias;
}
