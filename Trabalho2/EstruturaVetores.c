#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

Elemento vetorPrincipal[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho tem inteiro maior ou igual a 1
*/

int criarEstruturaAuxiliar(int tamanho, int posicao){
    int retorno = 0;

    // se posição é um valor válido {entre 1 e 10}
    if(ehPosicaoValida(posicao) != SUCESSO)
        retorno = POSICAO_INVALIDA;

    // a posicao pode já existir estrutura auxiliar
    else if(vetorPrincipal[posicao - 1].vetor != NULL)
        retorno = JA_TEM_ESTRUTURA_AUXILIAR;

    // o tamanho nao pode ser menor que 1
    else if(tamanho < 1)
        retorno = TAMANHO_INVALIDO;

    // se os testes passarem sem problemas...    
    if(retorno == 0)
    {
        vetorPrincipal[posicao - 1].vetor = malloc(tamanho * sizeof(int));
        vetorPrincipal[posicao - 1].tamanho = tamanho;  
        retorno = SUCESSO;
    }
    
    return retorno;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int valor, int posicao){

    int retorno = 0;
    int existeEstruturaAuxiliar = 1;
    int temEspaco = 1;
    int posicaoInvalida = 0;

    if(ehPosicaoValida(posicao) != SUCESSO) posicaoInvalida = 1;

    if(vetorPrincipal[posicao - 1].vetor == NULL) existeEstruturaAuxiliar = 0;

    if(vetorPrincipal[posicao - 1].espacosOcupados == vetorPrincipal[posicao - 1].tamanho) temEspaco = 0;
    
    if(!posicaoInvalida)
    {
        if(existeEstruturaAuxiliar)
        {
            if(temEspaco)
            {
                //insere
                vetorPrincipal[posicao - 1].vetor[vetorPrincipal[posicao - 1].espacosOcupados] = valor;
                ++vetorPrincipal[posicao - 1].espacosOcupados;
                retorno = SUCESSO;
            }
            else retorno = SEM_ESPACO;
        }
        else retorno = SEM_ESTRUTURA_AUXILIAR;
    } else retorno = POSICAO_INVALIDA;
    
    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/

int excluirNumeroDoFinaldaEstrutura(int posicao){
    int retorno = 0;

    if(ehPosicaoValida(posicao) != SUCESSO) retorno = POSICAO_INVALIDA;
    else if(vetorPrincipal[posicao - 1].vetor == NULL) retorno = SEM_ESTRUTURA_AUXILIAR;
    else if(vetorPrincipal[posicao - 1].espacosOcupados == 0) retorno = ESTRUTURA_AUXILIAR_VAZIA;
    else{
        int posicaoUltimoElemento = vetorPrincipal[posicao - 1].espacosOcupados - 1;
        vetorPrincipal[posicao - 1].vetor[posicaoUltimoElemento] = 0;
        vetorPrincipal[posicao - 1].espacosOcupados--;
        retorno = SUCESSO;
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/

int excluirNumeroEspecificoDeEstrutura(int valor, int posicao){
    int retorno = 0;

    if(ehPosicaoValida(posicao) != SUCESSO) retorno = POSICAO_INVALIDA;
    else if(vetorPrincipal[posicao - 1].vetor == NULL) retorno = SEM_ESTRUTURA_AUXILIAR;
    else if(vetorPrincipal[posicao - 1].espacosOcupados == 0) retorno = ESTRUTURA_AUXILIAR_VAZIA;
    else
    {
        int numEspacosOcupados = vetorPrincipal[posicao - 1].espacosOcupados;
        int posicaoValor = -1;
        for(int i = 0; i < numEspacosOcupados; i++) 
            if(vetorPrincipal[posicao - 1].vetor[i] == valor) posicaoValor = i;

        if(posicaoValor == -1)
        {
            retorno = NUMERO_INEXISTENTE;
            return retorno;
        }

        for(int i = posicaoValor; i < vetorPrincipal[posicao - 1].espacosOcupados; i++) 
            vetorPrincipal[posicao - 1].vetor[i] = vetorPrincipal[posicao - 1].vetor[i + 1];

        vetorPrincipal[posicao - 1].espacosOcupados--;
        retorno = SUCESSO; 
    }
    return retorno;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao){
    int retorno = 0;
    if (posicao < 1 || posicao > 10){
        retorno = POSICAO_INVALIDA;
    }else retorno = SUCESSO;

    return retorno;
}

/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/

int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){
    int retorno = 0;

    if(ehPosicaoValida(posicao) != SUCESSO) retorno = POSICAO_INVALIDA;
    else if(vetorPrincipal[posicao - 1].vetor == NULL) retorno = SEM_ESTRUTURA_AUXILIAR;
    else
    {
        for(int i = 0; i < vetorPrincipal[posicao - 1].espacosOcupados; i++)
        {
            vetorAux[i] = vetorPrincipal[posicao - 1].vetor[i];
        }
        retorno = SUCESSO;
    }
    return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/

void trocar(int *x, int *y)
{
    int z = *x;
    *x = *y;
    *y = z;
}

int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]){
    int retorno = 0;

    if(ehPosicaoValida(posicao) != SUCESSO) retorno = POSICAO_INVALIDA;
    else if(vetorPrincipal[posicao - 1].vetor == NULL) retorno = SEM_ESTRUTURA_AUXILIAR;
    else
    {
        //copia array
        for(int i = 0; i < vetorPrincipal[posicao - 1].espacosOcupados; i++) vetorAux[i] = vetorPrincipal[posicao - 1].vetor[i];
        int tamanhoVetorAux = vetorPrincipal[posicao - 1].espacosOcupados;

        int indiceMenorNum;
        for(int i = 0; i < tamanhoVetorAux; i++)
        {
            indiceMenorNum = i;
            for(int j = i + 1; j < tamanhoVetorAux; j++)
            {
                if(vetorAux[j] < vetorAux[indiceMenorNum])
                    indiceMenorNum = j;

                trocar(&vetorAux[indiceMenorNum], &vetorAux[i]);
            }
        }
        retorno = SUCESSO;
    }

    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/

int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]){
    int retorno = 0;
    int pulo = 0;

    int numeroDeEstruturasVazias = 0;
    for(int i = 0; i < TAM; i++)
        if(vetorPrincipal[i].espacosOcupados == 0) ++numeroDeEstruturasVazias;

    if(numeroDeEstruturasVazias == TAM) retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    else 
    {
        for(int i = 0; i < TAM; i++)
        {
            if(vetorPrincipal[i].vetor != NULL)
            {
                for(int j = 0; j < vetorPrincipal[i].espacosOcupados; j++)
                {   
                    if(i == 0) 
                    {
                        vetorAux[j] = vetorPrincipal[i].vetor[j];
                        pulo = pulo + j;
                    }
                    else
                    {
                        vetorAux[pulo + j] = vetorPrincipal[i].vetor[j];
                    }
                }       
                if(i != 0) pulo = pulo + vetorPrincipal[i].espacosOcupados;
            }
        }
        retorno = SUCESSO;
    }

    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/

int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){
    int retorno = 0;
    int pulo = 0;

    int numeroDeEstruturasVazias = 0;
    for(int i = 0; i < TAM; i++)
        if(vetorPrincipal[i].espacosOcupados == 0) ++numeroDeEstruturasVazias;

    if(numeroDeEstruturasVazias == TAM) retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    else 
    {
        for(int i = 0; i < TAM; i++)
        {
            if(vetorPrincipal[i].vetor != NULL)
            {
                for(int j = 0; j < vetorPrincipal[i].espacosOcupados; j++)
                {   
                    if(i == 0) 
                    {
                        vetorAux[j] = vetorPrincipal[i].vetor[j];
                        pulo = pulo + j;
                    }
                    else
                    {
                        vetorAux[pulo + j] = vetorPrincipal[i].vetor[j];
                    }
                }       
                if(i != 0) pulo = pulo + vetorPrincipal[i].espacosOcupados;
            }
        }

        int indiceMenorNum;
        for(int i = 0; i < pulo; i++)
        {
            indiceMenorNum = i;
            for(int j = i + 1; j < pulo; j++)
            {
                if(vetorAux[j] < vetorAux[indiceMenorNum])
                    indiceMenorNum = j;

                trocar(&vetorAux[indiceMenorNum], &vetorAux[i]);
            }
        }

        retorno = SUCESSO;
    }

    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/

int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho){
    int retorno = 0;

    if(ehPosicaoValida(posicao) != SUCESSO) retorno = POSICAO_INVALIDA;
    else if(vetorPrincipal[posicao - 1].vetor == NULL) retorno = SEM_ESTRUTURA_AUXILIAR;
    else if(novoTamanho + vetorPrincipal[posicao - 1].tamanho < 1) retorno = NOVO_TAMANHO_INVALIDO;
    else
    {
        int tamanhoVelho = vetorPrincipal[posicao - 1].tamanho;
        if(novoTamanho < 0) vetorPrincipal[posicao - 1].espacosOcupados = vetorPrincipal[posicao - 1].espacosOcupados + novoTamanho;
        vetorPrincipal[posicao - 1].vetor = realloc(vetorPrincipal[posicao - 1].vetor, tamanhoVelho + novoTamanho);
        retorno = SUCESSO;
    }

    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/

int getQuantidadeElementosEstruturaAuxiliar(int posicao){

    int retorno = 0;

    if(ehPosicaoValida(posicao) != SUCESSO) retorno = POSICAO_INVALIDA;
    else if(vetorPrincipal[posicao - 1].vetor == NULL) retorno = SEM_ESTRUTURA_AUXILIAR;
    else if(vetorPrincipal[posicao - 1].espacosOcupados == 0) retorno = ESTRUTURA_AUXILIAR_VAZIA;
    else
    {
        retorno = vetorPrincipal[posicao - 1].espacosOcupados;
    }

    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/

No* montarListaEncadeadaComCabecote(){

    return NULL;

}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/

void getDadosListaEncadeadaComCabecote(No* inicio, int vetorAux[]){


}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/

void destruirListaEncadeadaComCabecote(No** inicio){
   

}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 
*/

void inicializar(){
    for(int i = 0; i < TAM; i++)
    {
        vetorPrincipal[i].vetor = NULL;
        vetorPrincipal[i].espacosOcupados = 0;
        vetorPrincipal[i].tamanho = 0;
    }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.
*/

void finalizar(){
    
    
}

