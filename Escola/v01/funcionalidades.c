#include <stdio.h>
#include "funcionalidades.h"

void printMenu()
{   
    printf("1 - Cadastrar um novo aluno\n2 - Cadastrar um novo professor\n3 - Cadastrar uma nova disciplina\n4 - Listar alunos\n5 - Listar professores\n6 - Listar disciplinas\n7 - Sair do aplicativo.\n");
}

void printMenuAlunos()
{
    system("clear");
    printf("Escolha como deseja listar os alunos:\n");
    printf("1 - Listar todos os alunos\n2 - Listar alunos por sexo\n3 - Listar alunos ordenados por nome\n4 - Listar alunos ordenados por data de nascimento\n5 - Voltar ao menu anterior\n");
}

void printMenuProfessores()
{
    system("clear");
    printf("Escolha como deseja listar os professores:\n");
    printf("1 - Listar todos os professores\n2 - Listar professores por sexo\n3 - Listar professores ordenados por nome\n4 - Listar professores ordenados por data de nascimento\n5 - Voltar ao menu anterior\n");
}

void printMenuDisciplinas()
{
    system("clear");
    printf("Escolha como deseja listar as disciplinas:\n");
    printf("1 - Listar todas as disciplinas\n2 - Listar disciplina e os dados dos alunos matriculados nela\n3 - Voltar ao menu anterior\n");
}

void listarAlunos(struct Pessoa* alunos, int quantidadeAlunos)
{
    system("clear");
    int func = 0;
    printMenuAlunos();
    scanf("%d", &func);
    switch (func)
    {
        case 1:
            system("clear");
            printf("Nome de todos os alunos:\n");
            for(int i = 0; i < quantidadeAlunos; i++)
            {
                printf("Aluno %d: %s\n", i + 1, alunos[i].nome);
            }
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
    }
}

void listarProfessores(struct Pessoa* professores, int quantidadeProfessores)
{
    system("clear");
    int func = 0;
    printMenuProfessores();
    scanf("%d", &func);
    switch (func)
    {
        case 1:
            system("clear");
            printf("Nome de todos os professores:\n");
            for(int i = 0; i < quantidadeProfessores; i++)
            {
                printf("Professor #%d: %s\n", i + 1, professores[i].nome);
            }
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
    }
}

void listarDisciplinas(struct Disciplina* disciplinas, int quantidadeDisciplinas)
{
    system("clear");
    int func = 0;
    printMenuDisciplinas();
    scanf("%d", &func);
    switch (func)
    {
        case 1:
            system("clear");
            printf("Nome de todas as disciplinas:\n");
            for(int i = 0; i < quantidadeDisciplinas; i++)
            {
                printf("Disciplina #%d: %s\n", i + 1, disciplinas[i].nome);
            }
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
    }
}

struct Pessoa cadastrarAluno()
{
    system("clear");
    int c;
    struct Pessoa novoAluno;
    printf("Digite o nome do novo aluno: ");
    fgets(novoAluno.nome, sizeof(novoAluno.nome), stdin);

    printf("Digite a matricula do novo aluno: ");
    fgets(novoAluno.matricula, sizeof(novoAluno.matricula), stdin);

    printf("Digite o sexo do novo aluno: ");
    scanf(" %c", &novoAluno.sexo);
    while ( (c = getchar()) != '\n' && c != EOF );

    printf("Digite a data de nascimento do novo aluno: ");
    fgets(novoAluno.dataNascimento, sizeof(novoAluno.dataNascimento), stdin);

    printf("Digite o CPF do novo aluno: ");
    fgets(novoAluno.cpf, sizeof(novoAluno.cpf), stdin);

    system("clear");
    return novoAluno;
    
}

struct Pessoa cadastrarProfessor()
{
    system("clear");
    int c;
    struct Pessoa novoProfessor;
    printf("Digite o nome do novo professor: ");
    fgets(novoProfessor.nome, sizeof(novoProfessor.nome), stdin);

    printf("Digite a matricula do novo professor: ");
    fgets(novoProfessor.matricula, sizeof(novoProfessor.matricula), stdin);

    printf("Digite o sexo do novo professor: ");
    scanf("%c", &novoProfessor.sexo);
    while ( (c = getchar()) != '\n' && c != EOF );

    printf("Digite a data de nascimento do novo professor: ");
    fgets(novoProfessor.dataNascimento, sizeof(novoProfessor.dataNascimento), stdin);

    printf("Digite o CPF do novo professor: ");
    fgets(novoProfessor.cpf, sizeof(novoProfessor.cpf), stdin);

    system("clear");
    return novoProfessor;
}

struct Disciplina cadastrarDisciplina()
{
    system("clear");   
    int c;
    struct Disciplina novaDisciplina;
    printf("Digite o nome da nova disciplina: ");
    fgets(novaDisciplina.nome, sizeof(novaDisciplina.nome), stdin);

    printf("Digite o codigo da nova disciplina: ");
    fgets(novaDisciplina.codigo, sizeof(novaDisciplina.codigo), stdin);

    printf("Digite a matricula do professor da nova disciplina: ");
    fgets(novaDisciplina.professor.nome, sizeof(novaDisciplina.professor), stdin);

    printf("Digite o semestre da nova disciplina: ");
    scanf("%c", &novaDisciplina.semestre);
    while ( (c = getchar()) != '\n' && c != EOF );

    system("clear");
    return novaDisciplina;

}