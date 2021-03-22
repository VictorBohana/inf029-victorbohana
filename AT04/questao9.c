#include <stdio.h>
#include <stdlib.h>

struct Cliente{
    char nome[21];
    char dataNascimento[9];
    char cpf[12];
    char sexo;
};

void validarNome(char* nome){
    int i = 0;
    while(nome[i] != '\0')
    {
        i++;
    }

    if(i > 20)
    {
        printf("Nome possui mais de 20 caracteres.\n");
        exit(0);
    }
    
}

void validarNascimento(char* nascimento){
    for(int i = 0; i < 8; i++)
    {
        if(nascimento[i] != '0' && nascimento[i] != '1' && nascimento[i] != '2' && nascimento[i] != '3' 
            && nascimento[i] != '4' && nascimento[i] != '5' && nascimento[i] != '6' && nascimento[i] != '7' 
            && nascimento[i] != '8' && nascimento[i] != '9');
        {
            printf("Caractere invalido detectado na data.\n");
            exit(0);
        }
    }
    if(nascimento[0] != '0' && nascimento[0] != '1' && nascimento[0] != '2' && nascimento[0] != '3')
    {
        printf("Dia de nascimento invalido.\n");
        exit(0);
    }
    if(nascimento[0] == '3'){
        if(nascimento[1] != '0' && nascimento[1] != '1')
        {
            printf("Dia de nascimento invalido.\n");
            exit(0);
        }
    }
    if(nascimento[0] == '0'){
        if(nascimento[1] == '0')
        {
            printf("Dia de nascimento invalido.\n");
            exit(0);
        }
    }
    if(nascimento[2] != '0' && nascimento[2] != '1')
    {
        printf("Mes de nascimento invalido.\n");
        exit(0);
    }
    if(nascimento[2] == '1'){
        if(nascimento[3] != '0' && nascimento[3] != '1' && nascimento[3] != '2')
        {
            printf("Mes de nascimento invalido.\n");
            exit(0);
        }
    }
    if(nascimento[2] == '0'){
        if(nascimento[3] == '0')
        {
            printf("Mes de nascimento invalido.\n");
            exit(0);
        }
    }
}

void validarCPF(char* cpf){
    for(int i = 0; i < 12; i++)
    {
        if(cpf[i] != '0' && cpf[i] != '1' && cpf[i] != '2' && cpf[i] != '3' 
        && cpf[i] != '4' && cpf[i] != '5' && cpf[i] != '6' && cpf[i] != '7' 
        && cpf[i] != '8' && cpf[i] != '9')
        {
            printf("Caractere invalido detectado no CPF.\n");
            exit(0);
        }
    }
}

void validarSexo(char sexo){
    if(sexo != 'M' && sexo != 'm'&& sexo != 'F' && sexo != 'f')
    {
        printf("Sexo invalido. Digite M/m para masculino ou F/f para feminino.\n");
        exit(0);
    }
}

struct Cliente cadastrarCliente(char* nome, char* nascimento, char* cpf, char sexo){
    struct Cliente cliente;
    validarNome(nome);
    validarNascimento(nascimento);
    validarCPF(cpf);
    validarSexo(sexo);


    for(int i = 0; i < 21; i++)
    {
        cliente.nome[i] = nome[i];
    }

    for(int j = 0; j < 9; j++)
    {
        cliente.dataNascimento[j] = nascimento[j];
    }

    for(int k = 0; k < 12; k++)
    {
        cliente.cpf[k] = cpf[k];
    }

    cliente.sexo = sexo;

    return cliente;
}

int main(){
    char nome[21], nascimento[9], cpf[12], sexo;
    printf("Digite o nome do cliente: ");
    scanf(" %s", nome);

    printf("Digite a data de nascimento do cliente: ");
    scanf(" %s", nascimento);

    printf("Digite o CPF do cliente (XXXXXXXXXXX): ");
    scanf(" %s", cpf);

    printf("Digite o sexo do cliente(M/F): ");
    scanf(" %c", &sexo);

    struct Cliente novoCliente = cadastrarCliente(nome, nascimento, cpf, sexo);
    printf("%s\n%s\n%s\n%c\n", novoCliente.nome, novoCliente.dataNascimento, novoCliente.cpf, novoCliente.sexo);

    return 0;
}