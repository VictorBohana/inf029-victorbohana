#include <stdio.h>

struct Cliente{
    char nome[21];
    char dataNascimento[11];
    char cpf[12];
    char sexo;
};

struct Cliente cadastrarCliente(char* nome, char* nascimento, char* cpf, char sexo){
    struct Cliente cliente;

    for(int i = 0; i < 21; i++){
        cliente.nome[i] = nome[i];
    }

    for(int j = 0; j < 11; j++){
        cliente.dataNascimento[j] = nascimento[j];
    }

    for(int k = 0; k < 12; k++){
        cliente.cpf[k] = cpf[k];
    }

    cliente.sexo = sexo;

    return cliente;
}

int main(){
    char nome[21], nascimento[11], cpf[12], sexo;
    printf("Digite o nome do cliente: ");
    scanf(" %s", nome);

    printf("Digite a data de nascimento do cliente(DD/MM/YYYY): ");
    scanf(" %s", nascimento);

    printf("Digite o CPF do cliente(XXXXXXXXXXX): ");
    scanf(" %s", cpf);

    printf("Digite o sexo do cliente(M/F): ");
    scanf(" %c", &sexo);

    struct Cliente novoCliente = cadastrarCliente(nome, nascimento, cpf, sexo);
    printf("%s\n%s\n%s\n%c\n", novoCliente.nome, novoCliente.dataNascimento, novoCliente.cpf, novoCliente.sexo);

    return 0;
}