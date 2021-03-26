#include <stdio.h>
#include "funcionalidades.h"

void printMenu()
{ 
    system("clear");
    printf("1 - Cadastrar/excluir/atualizar um aluno\n2 - Cadastrar/excluir/atualizar um  professor\n3 - Cadastrar/excluir/atualizar uma disciplina\n4 - Listar alunos\n5 - Listar professores\n6 - Listar disciplinas\n7 - Matricular aluno numa disciplina\n8 - Sair do aplicativo.\n");
}

void printMenuCadastrarExcluirAluno(){
    system("clear");
    printf("Escolha o que deseja fazer:\n");
    printf("1 - Cadastrar um novo aluno\n2 - Excluir um aluno existente\n3 - Atualizar dados de um aluno existente\n4 - Voltar ao menu anterior\n");
}

void printMenuCadastrarExcluirProfessor(){
    system("clear");
    printf("Escolha o que deseja fazer:\n");
    printf("1 - Cadastrar um novo professor\n2 - Excluir um professor existente\n3 - Atualizar dados de um professor existente\n4 - Voltar ao menu anterior\n");
}

void printMenuCadastrarExcluirDisciplina(){
    system("clear");
    printf("Escolha o que deseja fazer:\n");
    printf("1 - Cadastrar uma nova disciplina\n2 - Excluir uma disciplina existente\n3 - Atualizar dados de uma disciplina existente\n4 - Voltar ao menu anterior\n");
}

void printMenuListarAlunos()
{
    system("clear");
    printf("Escolha como deseja listar os alunos:\n");
    printf("1 - Listar todos os alunos\n2 - Listar alunos por sexo\n3 - Listar alunos ordenados por nome\n4 - Listar alunos ordenados por data de nascimento\n5 - Voltar ao menu anterior\n");
}

void printMenuListarProfessores()
{
    system("clear");
    printf("Escolha como deseja listar os professores:\n");
    printf("1 - Listar todos os professores\n2 - Listar professores por sexo\n3 - Listar professores ordenados por nome\n4 - Listar professores ordenados por data de nascimento\n5 - Voltar ao menu anterior\n");
}

void printMenuListarDisciplinas()
{
    system("clear");
    printf("Escolha como deseja listar as disciplinas:\n");
    printf("1 - Listar todas as disciplinas\n2 - Listar disciplina e os dados dos alunos matriculados nela\n3 - Voltar ao menu anterior\n");
}

void listarAlunos(struct Pessoa* alunos, int quantidadeAlunos)
{
    system("clear");
    int func = 0, c;
    printMenuListarAlunos();

    if(quantidadeAlunos == 0)
    {
        printf("\nNenhum aluno cadastrado no sistema.\n\n");
        return;
    }

    scanf("%d", &func);
    while ( (c = getchar()) != '\n' && c != EOF );

    switch (func)
    {
        case 1:
            system("clear");
            printf("Nome de todos os alunos:\n");
            for(int i = 0; i < quantidadeAlunos; i++)
            {
                printf("======================\n");
                printf("Aluno %d: \n", i + 1);
                printf("Nome do aluno: %s", alunos[i].nome);
                printf("Matricula do aluno: %s\n", alunos[i].matricula);
                printf("CPF do aluno: %s", alunos[i].cpf);
                printf("Data de nascimento do aluno: %s", alunos[i].dataNascimento);
                printf("Sexo do aluno: %c\n", alunos[i].sexo);
                printf("Numero de Disciplinas: %d\n", alunos[i].numeroDeDisciplinas);
            }
            printf("Pressione enter para continuar...");
            getchar();
            system("clear");
            break;
        case 2:
            printf("===Alunos do sexo masculino=== \n");
            for(int i = 0; i < quantidadeAlunos; i++)
            {
                if(alunos[i].sexo == 'M' || alunos[i].sexo == 'm')
                {
                    printf("%s", alunos[i].nome);
                }
            }

            printf("\n===Alunas do sexo feminino=== \n");
            for(int i = 0; i < quantidadeAlunos; i++)
            {
                if(alunos[i].sexo == 'F' || alunos[i].sexo == 'f')
                {
                    printf("%s", alunos[i].nome);
                }
            }
            printf("Pressione enter para continuar...");
            getchar();
            system("clear");
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
    int func = 0, c;
    printMenuListarProfessores();

    if(quantidadeProfessores == 0)
    {
        printf("\nNenhum professor cadastrado no sistema.\n\n");
        return;
    }

    scanf("%d", &func);
    while ( (c = getchar()) != '\n' && c != EOF );

    switch (func)
    {
        case 1:
            system("clear");
            printf("Nome de todos os professores:\n");
            for(int i = 0; i < quantidadeProfessores; i++)
            {
                printf("======================\n");
                printf("Professor #%d: \n", i + 1);
                printf("Nome do professor: %s ", professores[i].nome);
                printf("Matricula do professor: %s", professores[i].matricula);
                printf("Data de nascimento do professor: %s", professores[i].dataNascimento);
                printf("Sexo do professor: %c\n", professores[i].sexo);                
            }
            printf("Pressione enter para continuar...");
            getchar();
            system("clear");
            break;
        case 2:
            printf("===Professores do sexo masculino=== \n");
            for(int i = 0; i < quantidadeProfessores; i++)
            {
                if(professores[i].sexo == 'M' || professores[i].sexo == 'm')
                {
                    printf("%s", professores[i].nome);
                }
            }

            printf("\n===Professoras do sexo feminino===\n");
            for(int i = 0; i < quantidadeProfessores; i++)
            {
                if(professores[i].sexo == 'F' || professores[i].sexo == 'f')
                {
                    printf("%s", professores[i].nome);
                }
            }
            printf("Pressione enter para continuar...");
            getchar();
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
    int func = 0, c;
    printMenuListarDisciplinas();
    if(quantidadeDisciplinas == 0)
    {
        printf("\nNenhuma disciplina cadastrada no sistema.\n\n");
        return;
    }
    scanf("%d", &func);
    while ( (c = getchar()) != '\n' && c != EOF );

    switch (func)
    {
        case 1: 
            system("clear");
            printf("Nome de todas as disciplinas:\n");
            for(int i = 0; i < quantidadeDisciplinas; i++)
            {
                printf("Disciplina #%d\n", i + 1);
                printf("Nome: %s", disciplinas[i].nome);
                printf("Nome do professor: %s", disciplinas[i].professor.nome);
                printf("Codigo da disciplina: %s", disciplinas[i].codigo);
                printf("Semestre: %c", disciplinas[i].semestre);
                printf("Numero de alunos inscritos: %d\n", disciplinas[i].numeroAlunosInscritos);
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

void cadastrarExcluirAluno(struct Pessoa *alunos, int* numeroAlunos){
    int func, c;
    printMenuCadastrarExcluirAluno();
    scanf("%d", &func);
    while ( (c = getchar()) != '\n' && c != EOF );

    switch (func)
    {
    case 1: ;
        struct Pessoa novoAluno = cadastrarAluno();
        alunos[*numeroAlunos] = novoAluno;
        *numeroAlunos = *numeroAlunos + 1;
        break;
    case 2:
        excluir(alunos, numeroAlunos);
        break;
    default:
        break;
    }

}

void cadastrarExcluirProfessor(struct Pessoa *professores, int* numeroProfessores){
    int func, c;
    printMenuCadastrarExcluirProfessor();
    scanf("%d", &func);
    while ( (c = getchar()) != '\n' && c != EOF );

    switch (func)
    {
    case 1: ;
        struct Pessoa novoProfessor = cadastrarProfessor();
        professores[*numeroProfessores] = novoProfessor;
        *numeroProfessores = *numeroProfessores + 1;
        break;
    case 2:
        excluir(professores, numeroProfessores);
        break;
    default:
        break;
    }
}

void cadastrarExcluirDisciplina(struct Disciplina *disciplinas, int* numeroDisciplinas){
    int func, c;
    printMenuCadastrarExcluirDisciplina();
    scanf("%d", &func);
    while ( (c = getchar()) != '\n' && c != EOF );

    switch (func)
    {
    case 1: ;
        struct Disciplina novaDisciplina = cadastrarDisciplina();
        disciplinas[*numeroDisciplinas] = novaDisciplina;
        *numeroDisciplinas = *numeroDisciplinas + 1;
        break;
    case 2:
        excluirDisciplina(disciplinas, numeroDisciplinas);
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

    novoAluno.numeroDeDisciplinas = 0;

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
    fgets(novaDisciplina.professor.nome, sizeof(novaDisciplina.professor.nome), stdin);

    printf("Digite o semestre da nova disciplina: ");
    scanf("%c", &novaDisciplina.semestre);
    while ( (c = getchar()) != '\n' && c != EOF );

    system("clear");
    novaDisciplina.numeroAlunosInscritos = 0;
    return novaDisciplina;
}

void excluir(struct Pessoa *individuos, int* numeroIndividuos)
{
    if(*numeroIndividuos == 0){
        printf("Nao existem individuos para serem excluidos.");
        return;
    }

    int c;
    printf("Digite o numero do individuo que deseja excluir: \n");
    for(int i = 0; i < *numeroIndividuos; i++)
    {
        printf("%d. %s\n", i + 1, individuos[i].nome);
    }

    int numIndividuo;
    scanf("%d", &numIndividuo);
    while ( (c = getchar()) != '\n' && c != EOF );

    if(numIndividuo <= 0 || numIndividuo > *numeroIndividuos)
    {
        printf("Erro! Codigo invalido.\n");
    } else
    {
        for(int i = numIndividuo - 1; i < *numeroIndividuos; i++) individuos[i] = individuos[i + 1];
        *numeroIndividuos = *numeroIndividuos - 1;
    }
}

void excluirDisciplina(struct Disciplina *disciplinas, int* numeroDisciplinas)
{
    int c;

    if(*numeroDisciplinas == 0)
    {
        printf("Nao existem disciplinas para excluir");
        return;
    }

    printf("Digite o numero da disciplina que deseja excluir: \n");
    for(int i = 0; i < *numeroDisciplinas; i++)
    {
        printf("%d. %s\n", i + 1, disciplinas[i].nome);
    }

    int numDisciplina;
    scanf("%d", &numDisciplina);
    while ( (c = getchar()) != '\n' && c != EOF );

    if(numDisciplina <= 0 || numDisciplina > *numeroDisciplinas)
    {
        printf("Erro! Numero invalido.\n");
    } else
    {
        for(int i = numDisciplina - 1; i < *numeroDisciplinas; i++) disciplinas[i] = disciplinas[i + 1];
        *numeroDisciplinas = *numeroDisciplinas - 1;
    }
}

void matricularAlunoNumaDisciplina(struct Pessoa *alunos, struct Disciplina *disciplinas, 
    int* numeroAlunos, int* numeroDisciplinas){
        printf("\nDigite o numero do aluno que voce deseja matricular numa disciplina: \n");
        for(int i = 0; i < *numeroAlunos; i++)
        {
            printf("%d. %s\n", i + 1, alunos[i].nome);
        }

        int numAluno, c;
        scanf("%d", &numAluno);
        while ( (c = getchar()) != '\n' && c != EOF );
        numAluno = numAluno - 1;

        printf("Digite o numero da disciplina em que voce deseja matricular o aluno: \n");
        for(int i = 0; i < *numeroDisciplinas; i++)
        {
            printf("%d. %s\n", i + 1, disciplinas[i].nome);
        }

        int numDisciplina;
        scanf("%d", &numDisciplina);
        while ( (c = getchar()) != '\n' && c != EOF );
        numDisciplina = numDisciplina - 1;
        
        int numeroAlunosInscritos = disciplinas[numDisciplina].numeroAlunosInscritos;

        if(numeroAlunosInscritos == 50)
        {
            printf("Nao ha vagas nessa disciplina.");
            return;
        }

        // copiar nome
        for(int i = 0; i < 20; i++)
        {
            disciplinas[numDisciplina].alunos[numeroAlunosInscritos].nome[i] = alunos[numAluno].nome[i];
        }

        // copiar matricula
        for(int j = 0; j < 11; j++)
        {   
            disciplinas[numDisciplina].alunos[numeroAlunosInscritos].matricula[j] = alunos[numAluno].matricula[j];
        }

        // copiar CPF
        for(int k = 0; k < 14; k++)
        {   
            disciplinas[numDisciplina].alunos[numeroAlunosInscritos].cpf[k] = alunos[numAluno].cpf[k];
        }

        // copiar data de nascimento
        for(int l = 0; l < 10; l++)
        {
            disciplinas[numDisciplina].alunos[numeroAlunosInscritos].dataNascimento[l] = alunos[numAluno].dataNascimento[l];
        }
        
        // copiar sexo
        disciplinas[numDisciplina].alunos[numeroAlunosInscritos].sexo = alunos[numAluno].sexo;

        // incrementar numero de disciplinas em que o aluno esta inscrito
        alunos[numAluno].numeroDeDisciplinas = alunos[numAluno].numeroDeDisciplinas + 1;

        // incrementar o numero de alunos inscritos em dada disciplina
        disciplinas[numDisciplina].numeroAlunosInscritos = disciplinas[numDisciplina].numeroAlunosInscritos + 1;
        printf("Aluno cadastrado com sucesso.\n");
        printf("Pressione enter para continuar...");
        getchar();
        system("clear");
}