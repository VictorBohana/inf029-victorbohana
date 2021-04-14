#include <stdio.h>
#include "funcionalidades.h"

void printMenu()
{ 
    system("clear");
    printf("1 - Cadastrar/excluir/atualizar um aluno\n2 - Cadastrar/excluir/atualizar um  professor\n3 - Cadastrar/excluir/atualizar uma disciplina\n4 - Listar alunos\n5 - Listar professores\n6 - Listar disciplinas\n7 - Matricular aluno numa disciplina\n8 - Desmatricular aluno duma disciplina\n9 - Sair\n");
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
    printf("1 - Listar todos os alunos\n2 - Listar alunos por sexo\n3 - Listar alunos ordenados por data de nascimento\n4 - Listar alunos matriculados em menos de 3 disciplinas\n5 - Voltar ao menu anterior\n");
}

void printMenuListarProfessores()
{
    system("clear");
    printf("Escolha como deseja listar os professores:\n");
    printf("1 - Listar todos os professores\n2 - Listar professores por sexo\n3 - Listar professores ordenados por data de nascimento\n4 - Voltar ao menu anterior\n");
}

void printMenuListarDisciplinas()
{
    system("clear");
    printf("Escolha como deseja listar as disciplinas:\n");
    printf("1 - Listar todas as disciplinas\n2 - Listar disciplinas e os dados dos alunos matriculados nela\n3 - Voltar ao menu anterior\n");
}

void listarAlunos(struct Pessoa* alunos, int quantidadeAlunos)
{
    system("clear");

    if(quantidadeAlunos == 0)
    {
        printf("Nenhum aluno cadastrado no sistema.\n");
        printf("Pressione enter para continuar...");
        getchar();
        return;
    }

    int func = 0, c;
    printMenuListarAlunos();

    scanf("%d", &func);
    while ( (c = getchar()) != '\n' && c != EOF );

    switch (func)
    {
        case 1:
            system("clear");
            printf("Nome de todos os alunos:\n");
            for(int i = 0; i < quantidadeAlunos; i++)
            {
                printf("=======Aluno %d======= \n", i + 1);
                printf("Nome do aluno: %s", alunos[i].nome);
                printf("Matricula do aluno: %d\n", alunos[i].matricula);
                printf("CPF do aluno: %s", alunos[i].cpf);
                printf("Data de nascimento do aluno: %d/%d/%d\n", alunos[i].dataNascimento.dia, alunos[i].dataNascimento.mes, alunos[i].dataNascimento.ano);
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
            listarAlunosPorIdade(alunos, quantidadeAlunos);
            break;
        case 4:
            for(int i = 0; i < quantidadeAlunos; i++)
            {
                if(alunos[i].numeroDeDisciplinas < 3)
                {
                    printf("%s", alunos[i].nome);
                }
            }
            break;
        case 5:
            break;
        default:
            break;
    }
}

void listarAlunosPorIdade(struct Pessoa* alunos, int quantidadeAlunos)
{
    int menorAno = 2021;
    int maiorAno = 1000;
    for(int i = 0; i < quantidadeAlunos; i++)
    {
        if(alunos[i].dataNascimento.ano < menorAno)
            menorAno = alunos[i].dataNascimento.ano;
        
        if(alunos[i].dataNascimento.ano > maiorAno)
            maiorAno = alunos[i].dataNascimento.ano;
    }

    for(int ano = menorAno; ano <= maiorAno; ano++)
    {
        for(int mes = 1; mes <= 12; mes++)
        {
            for(int dia = 1; dia <= 31; dia++)
            {
                for(int i = 0; i < quantidadeAlunos; i++)
                {
                    if(alunos[i].dataNascimento.ano == ano && alunos[i].dataNascimento.mes == mes 
                        && alunos[i].dataNascimento.dia == dia)
                    {
                        printf("%s%d/%d/%d\n", alunos[i].nome, alunos[i].dataNascimento.dia, alunos[i].dataNascimento.mes, alunos[i].dataNascimento.ano);
                        printf("========================\n");
                    }
                }
            }
        }
    }
    printf("Pressione enter para continuar...");
    getchar();
    system("clear");
}

void listarProfessores(struct Pessoa* professores, int quantidadeProfessores)
{
    system("clear");

    if(quantidadeProfessores == 0)
    {
        printf("Nenhum professor cadastrado no sistema.\n");
        printf("Pressione enter para continuar...");
        getchar();
        return;
    }

    int func = 0, c;
    printMenuListarProfessores();

    scanf("%d", &func);
    while ( (c = getchar()) != '\n' && c != EOF );

    switch (func)
    {
        case 1:
            system("clear");
            printf("Nome de todos os professores:\n");
            for(int i = 0; i < quantidadeProfessores; i++)
            {
                printf("===Professor #%d=== \n", i + 1);
                printf("Nome do professor: %s", professores[i].nome);
                printf("Matricula do professor: %d\n", professores[i].matricula);
                printf("Data de nascimento do professor: %d/%d/%d\n", professores[i].dataNascimento.dia, professores[i].dataNascimento.mes, professores[i].dataNascimento.ano);
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
            listarProfessoresPorIdade(professores, quantidadeProfessores);
            break;
        case 4:
            break;
        default:
            break;
    }
}

void listarProfessoresPorIdade(struct Pessoa* professores, int quantidadeProfessores)
{
    int menorAno = 2021;
    int maiorAno = 1000;
    for(int i = 0; i < quantidadeProfessores; i++)
    {
        if(professores[i].dataNascimento.ano < menorAno)
            menorAno = professores[i].dataNascimento.ano;
        
        if(professores[i].dataNascimento.ano > maiorAno)
            maiorAno = professores[i].dataNascimento.ano;
    }

    for(int ano = menorAno; ano <= maiorAno; ano++)
    {
        for(int mes = 1; mes <= 12; mes++)
        {
            for(int dia = 1; dia <= 31; dia++)
            {
                for(int i = 0; i < quantidadeProfessores; i++)
                {
                    if(professores[i].dataNascimento.ano == ano && professores[i].dataNascimento.mes == mes 
                        && professores[i].dataNascimento.dia == dia)
                    {
                        printf("%s%d/%d/%d\n", professores[i].nome, professores[i].dataNascimento.dia, professores[i].dataNascimento.mes, professores[i].dataNascimento.ano);
                        printf("========================\n");
                    }
                }
            }
        }
    }
    printf("Pressione enter para continuar...");
    getchar();
    system("clear");
}

void listarDisciplinas(struct Disciplina* disciplinas, int quantidadeDisciplinas, struct Pessoa* alunos, int quantidadeAlunos)
{
    system("clear");

    if(quantidadeDisciplinas == 0)
    {
        printf("Nenhuma disciplina cadastrada no sistema.\n");
        printf("Pressione enter para continuar...");
        getchar();
        return;
    }

    int func = 0, c;
    printMenuListarDisciplinas();
    
    scanf("%d", &func);
    while ( (c = getchar()) != '\n' && c != EOF );

    switch (func)
    {
        case 1: 
            printf("Nome de todas as disciplinas:\n");
            for(int i = 0; i < quantidadeDisciplinas; i++)
            {
                printf("===Disciplina #%d===\n", i + 1);
                printf("Nome: %s", disciplinas[i].nome);
                printf("Nome do professor: %s", disciplinas[i].professor.nome);
                printf("Codigo da disciplina: %s", disciplinas[i].codigo);
                printf("Semestre: %c\n", disciplinas[i].semestre);
                printf("Numero de alunos inscritos: %d\n", disciplinas[i].numeroAlunosInscritos);
                printf("ID: %d\n", disciplinas[i].id);
            }
            printf("Pressione enter para continuar...");
            getchar();
            system("clear");
            break;
        case 2:
            for(int i = 0; i < quantidadeDisciplinas; i++)
            {
                printf("===Disciplina #%d===\n", i + 1);
                printf("Nome: %s", disciplinas[i].nome);
                printf("Nome do professor: %s", disciplinas[i].professor.nome);
                printf("Codigo da disciplina: %s", disciplinas[i].codigo);
                printf("Semestre: %c\n", disciplinas[i].semestre);
                printf("Numero de alunos inscritos: %d\n", disciplinas[i].numeroAlunosInscritos);
                if(disciplinas[i].numeroAlunosInscritos == 0)
                {
                    printf("Nao ha alunos matriculados nessa disciplina.\n");
                }
                else
                {
                    for(int j = 0; j < disciplinas[i].numeroAlunosInscritos; j++)
                    {
                        for(int k = 0; k < quantidadeAlunos; k++)
                        {
                            if(disciplinas[i].alunosMatriculados[j] == alunos[k].matricula)
                            {
                                printf("%s",alunos[k].nome);
                            }
                        }
                    }
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

void cadastrarExcluirAluno(struct Pessoa *alunos, int* numeroAlunos, int* geradorDeMatriculas){
    int func, c;
    printMenuCadastrarExcluirAluno();
    scanf("%d", &func);
    while ( (c = getchar()) != '\n' && c != EOF );

    switch (func)
    {
    case 1: ;
        struct Pessoa novoAluno = cadastrarAluno(*geradorDeMatriculas);
        alunos[*numeroAlunos] = novoAluno;
        *numeroAlunos = *numeroAlunos + 1;
        *geradorDeMatriculas = *geradorDeMatriculas + 1;
        break;
    case 2:
        excluir(alunos, numeroAlunos);
        break;
    case 3:
        modificarAlunoExistente(alunos, numeroAlunos);
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
        struct Pessoa novoProfessor = cadastrarProfessor(*numeroProfessores);
        professores[*numeroProfessores] = novoProfessor;
        *numeroProfessores = *numeroProfessores + 1;
        break;
    case 2:
        excluir(professores, numeroProfessores);
        break;
    case 3:
        modificarProfessorExistente(professores, numeroProfessores);
        break;
    default:
        break;
    }
}

void cadastrarExcluirDisciplina(struct Disciplina *disciplinas, int* numeroDisciplinas, struct Pessoa* professores, int* numeroProfessores, int* idDisciplina){
    int func, c;
    printMenuCadastrarExcluirDisciplina();
    scanf("%d", &func);
    while ( (c = getchar()) != '\n' && c != EOF );

    switch (func)
    {
    case 1: ;
        
        struct Disciplina novaDisciplina = cadastrarDisciplina(professores, *numeroProfessores, *idDisciplina);
        disciplinas[*numeroDisciplinas] = novaDisciplina;
        *numeroDisciplinas = *numeroDisciplinas + 1;
        *idDisciplina = *idDisciplina + 1;
        break;
    case 2:
        excluirDisciplina(disciplinas, numeroDisciplinas);
        break;
    case 3:
        modificarDisciplinaExistente(disciplinas, &numeroDisciplinas, professores, *numeroProfessores);
    default:
        break;
    }
}

struct Pessoa cadastrarAluno(int geradorDeMatriculas)
{
    system("clear");
    int c;
    struct Pessoa novoAluno;
    printf("Digite o nome do novo aluno: ");
    fgets(novoAluno.nome, sizeof(novoAluno.nome), stdin);

    novoAluno.matricula = geradorDeMatriculas + 1;

    while(novoAluno.sexo != 'M' || novoAluno.sexo != 'm' || novoAluno.sexo != 'F' || novoAluno.sexo != 'f')
    {
        printf("Digite o sexo do novo aluno (M/F): ");
        scanf(" %c", &novoAluno.sexo);
    }
    while ( (c = getchar()) != '\n' && c != EOF );

    printf("Digite o dia (1-31) de nascimento do novo aluno: ");
    scanf("%d", &novoAluno.dataNascimento.dia);
    while ( (c = getchar()) != '\n' && c != EOF );

    if(novoAluno.dataNascimento.dia <= 0 || novoAluno.dataNascimento.dia > 31)
    {
        while(novoAluno.dataNascimento.dia <= 0 || novoAluno.dataNascimento.dia > 31)
        {
            printf("Digite um dia valido (1-31): ");
            scanf("%d", &novoAluno.dataNascimento.dia);
        }
        while ( (c = getchar()) != '\n' && c != EOF );
    }

    printf("Digite o mes (1-12) de nascimento do novo aluno: ");
    scanf("%d", &novoAluno.dataNascimento.mes);
    while ( (c = getchar()) != '\n' && c != EOF );

    if(novoAluno.dataNascimento.mes <= 0 || novoAluno.dataNascimento.mes > 12)
    {
        while(novoAluno.dataNascimento.mes <= 0 || novoAluno.dataNascimento.mes > 12)
        {
            printf("Digite um mes valido (1-12): ");
            scanf("%d", &novoAluno.dataNascimento.mes);
        }
        while ( (c = getchar()) != '\n' && c != EOF );
    }

    printf("Digite o ano de nascimento do novo aluno (1930-2020): ");
    scanf("%d", &novoAluno.dataNascimento.ano);
    while ( (c = getchar()) != '\n' && c != EOF );

    if(novoAluno.dataNascimento.ano < 1930 || novoAluno.dataNascimento.ano > 2020)
    {
        while(novoAluno.dataNascimento.ano < 1930 || novoAluno.dataNascimento.ano > 2020)
        {
            printf("Digite um ano valido (1930-2020): ");
            scanf("%d", &novoAluno.dataNascimento.ano);
        }
        while ( (c = getchar()) != '\n' && c != EOF );
    }

    printf("Digite o CPF do novo aluno: ");
    fgets(novoAluno.cpf, sizeof(novoAluno.cpf), stdin);

    novoAluno.numeroDeDisciplinas = 0;

    system("clear");
    return novoAluno;
    
}

void modificarAlunoExistente(struct Pessoa* alunos, int* numeroAlunos)
{

    if(*numeroAlunos == 0)
    {
        printf("Nao existem alunos para serem modificados.");
        printf("Pressione enter para continuar...");
        getchar();
        return;
    }

    system("clear");
    for(int i = 0; i < *numeroAlunos; i++)
    {
        printf("%d. %s", i + 1, alunos[i].nome);
    }
    int codigoAluno = 0, c;
    struct Pessoa novosDadosAluno;
    while(codigoAluno < 1 || codigoAluno > *numeroAlunos)
    {
        printf("Digite o codigo do aluno que deseja modificar: ");
        scanf("%d", &codigoAluno);
    }
    while ( (c = getchar()) != '\n' && c != EOF );
    codigoAluno -= 1;

    printf("Digite o nome do novo aluno: ");
    fgets(novosDadosAluno.nome, sizeof(novosDadosAluno.nome), stdin);

    while(novosDadosAluno.sexo != 'M'|| novosDadosAluno.sexo != 'm' || novosDadosAluno.sexo != 'F' || novosDadosAluno.sexo != 'f')
    {
        printf("Digite o sexo do aluno (M/F): ");
        scanf(" %c", &novosDadosAluno.sexo);
    }
    while ( (c = getchar()) != '\n' && c != EOF );

    printf("Digite a dia (1-31) de nascimento do aluno: ");
    scanf("%d", &novosDadosAluno.dataNascimento.dia);
    while ( (c = getchar()) != '\n' && c != EOF );

    if(novosDadosAluno.dataNascimento.dia <= 0 || novosDadosAluno.dataNascimento.dia > 31)
    {
        while(novosDadosAluno.dataNascimento.dia <= 0 || novosDadosAluno.dataNascimento.dia > 31)
        {
            printf("Digite um dia valido (1-31): ");
            scanf("%d", &novosDadosAluno.dataNascimento.dia);
        }
        while ( (c = getchar()) != '\n' && c != EOF );
    }

    printf("Digite o mes (1-12) de nascimento do aluno: ");
    scanf("%d", &novosDadosAluno.dataNascimento.mes);
    while ( (c = getchar()) != '\n' && c != EOF );

    if(novosDadosAluno.dataNascimento.mes <= 0 || novosDadosAluno.dataNascimento.mes > 12)
    {
        while(novosDadosAluno.dataNascimento.mes <= 0 || novosDadosAluno.dataNascimento.mes > 12)
        {
            printf("Digite um mes valido (1-12): ");
            scanf("%d", &novosDadosAluno.dataNascimento.mes);
        }
        while ( (c = getchar()) != '\n' && c != EOF );
    }

    printf("Digite o ano de nascimento do aluno (1930-2020): ");
    scanf("%d", &novosDadosAluno.dataNascimento.ano);
    while ( (c = getchar()) != '\n' && c != EOF );

    if(novosDadosAluno.dataNascimento.ano < 1930 || novosDadosAluno.dataNascimento.ano > 2020)
    {
        while(novosDadosAluno.dataNascimento.ano < 1930 || novosDadosAluno.dataNascimento.ano > 2020)
        {
            printf("Digite um ano valido (1930-2020): ");
            scanf("%d", &novosDadosAluno.dataNascimento.ano);
        }
        while ( (c = getchar()) != '\n' && c != EOF );
    }

    printf("Digite o CPF do aluno: ");
    fgets(novosDadosAluno.cpf, sizeof(novosDadosAluno.cpf), stdin);

    for(int i = 0; i < 21; i++)
    {
        alunos[codigoAluno].nome[i] = novosDadosAluno.nome[i];
    }

    for(int i = 0; i < 15; i++)
    {
        alunos[codigoAluno].cpf[i] = novosDadosAluno.cpf[i];
    }

    alunos[codigoAluno].sexo = novosDadosAluno.sexo;

    alunos[codigoAluno].dataNascimento.dia = novosDadosAluno.dataNascimento.dia;
    alunos[codigoAluno].dataNascimento.mes = novosDadosAluno.dataNascimento.mes;
    alunos[codigoAluno].dataNascimento.ano = novosDadosAluno.dataNascimento.ano;

    printf("Aluno atualizado com sucesso.\nPressione ENTER para continuar...");
    getchar();
}

struct Pessoa cadastrarProfessor(int numProfessores)
{
    system("clear");
    int c;
    struct Pessoa novoProfessor;
    printf("Digite o nome do novo professor: ");
    fgets(novoProfessor.nome, sizeof(novoProfessor.nome), stdin);

    novoProfessor.matricula = numProfessores + 1;

    while(novoProfessor.sexo != 'M' ||  novoProfessor.sexo != 'm' || novoProfessor.sexo != 'F' || novoProfessor.sexo != 'f')
    {
        printf("Digite o sexo do novo professor (M/F): ");
        scanf("%c", &novoProfessor.sexo);
    }
    while ( (c = getchar()) != '\n' && c != EOF );

    printf("Digite o dia de nascimento do novo professor (1-31): ");
    scanf("%d", &novoProfessor.dataNascimento.dia);
    while ( (c = getchar()) != '\n' && c != EOF );

    if(novoProfessor.dataNascimento.dia <= 0 || novoProfessor.dataNascimento.dia > 31)
    {
        while(novoProfessor.dataNascimento.dia <= 0 || novoProfessor.dataNascimento.dia > 31)
        {
            printf("Digite um dia valido (1-31): ");
            scanf("%d", &novoProfessor.dataNascimento.dia);
        }
        while ( (c = getchar()) != '\n' && c != EOF );
    }

    printf("Digite o mes de nascimento do novo professor (1-12): ");
    scanf("%d", &novoProfessor.dataNascimento.mes);
    while ( (c = getchar()) != '\n' && c != EOF );

    if(novoProfessor.dataNascimento.mes <= 0 || novoProfessor.dataNascimento.mes > 12)
    {
        while(novoProfessor.dataNascimento.mes <= 0 || novoProfessor.dataNascimento.mes > 12)
        {
            printf("Digite um mes valido (1-12): ");
            scanf("%d", &novoProfessor.dataNascimento.mes);
        }
        while ( (c = getchar()) != '\n' && c != EOF );
    }

    printf("Digite o ano de nascimento do novo professor (1930-2020): ");
    scanf("%d", &novoProfessor.dataNascimento.ano);
    while ( (c = getchar()) != '\n' && c != EOF );

    if(novoProfessor.dataNascimento.ano < 1930 || novoProfessor.dataNascimento.mes > 2020)
    {
        while(novoProfessor.dataNascimento.mes < 1930 || novoProfessor.dataNascimento.mes > 2020)
        {
            printf("Digite um ano valido (1930-2020): ");
            scanf("%d", &novoProfessor.dataNascimento.ano);
        }
        while ( (c = getchar()) != '\n' && c != EOF );
    }

    printf("Digite o CPF do novo professor: ");
    fgets(novoProfessor.cpf, sizeof(novoProfessor.cpf), stdin);

    system("clear");
    return novoProfessor;
}

void modificarProfessorExistente(struct Pessoa* professores, int* numeroProfessores)
{

    if(*numeroProfessores == 0)
    {
        printf("Nao existem professores para serem modificados.");
        printf("Pressione enter para continuar...");
        getchar();
        return;
    }

    system("clear");
    for(int i = 0; i < *numeroProfessores; i++)
    {
        printf("%d. %s", i + 1, professores[i].nome);
    }
    int codigoProfessor = 0, c;
    struct Pessoa novosDadosProfessor;
    while(codigoProfessor < 1 || codigoProfessor > *numeroProfessores)
    {
        printf("Digite o codigo do professor que deseja modificar: ");
        scanf("%d", &codigoProfessor);
    }
    while ( (c = getchar()) != '\n' && c != EOF );
    codigoProfessor -= 1;

    printf("Digite o nome do professor: ");
    fgets(novosDadosProfessor.nome, sizeof(novosDadosProfessor.nome), stdin);

    while(novosDadosProfessor.sexo != 'M' || novosDadosProfessor.sexo != 'm' || novosDadosProfessor.sexo != 'F' || novosDadosProfessor.sexo != 'f')
    {
        printf("Digite o sexo do professor (M/F): ");
        scanf(" %c", &novosDadosProfessor.sexo);
    }
    while ( (c = getchar()) != '\n' && c != EOF );

    printf("Digite o dia (1-31) de nascimento do professor: ");
    scanf("%d", &novosDadosProfessor.dataNascimento.dia);
    while ( (c = getchar()) != '\n' && c != EOF );

    if(novosDadosProfessor.dataNascimento.dia <= 0 || novosDadosProfessor.dataNascimento.dia > 31)
    {
        while(novosDadosProfessor.dataNascimento.dia <= 0 || novosDadosProfessor.dataNascimento.dia > 31)
        {
            printf("Digite um dia valido (1-31): ");
            scanf("%d", &novosDadosProfessor.dataNascimento.dia);
        }
        while ( (c = getchar()) != '\n' && c != EOF );
    }

    printf("Digite o mes (1-12) de nascimento do professor: ");
    scanf("%d", &novosDadosProfessor.dataNascimento.mes);
    while ( (c = getchar()) != '\n' && c != EOF );

    if(novosDadosProfessor.dataNascimento.mes <= 0 || novosDadosProfessor.dataNascimento.mes > 12)
    {
        while(novosDadosProfessor.dataNascimento.mes <= 0 || novosDadosProfessor.dataNascimento.mes > 12)
        {
            printf("Digite um mes valido (1-12): ");
            scanf("%d", &novosDadosProfessor.dataNascimento.mes);
        }
        while ( (c = getchar()) != '\n' && c != EOF );
    }

    printf("Digite o ano de nascimento do professor (1930-2020): ");
    scanf("%d", &novosDadosProfessor.dataNascimento.ano);
    while ( (c = getchar()) != '\n' && c != EOF );

    if(novosDadosProfessor.dataNascimento.ano < 1930 || novosDadosProfessor.dataNascimento.ano > 2020)
    {
        while(novosDadosProfessor.dataNascimento.ano < 1930 || novosDadosProfessor.dataNascimento.ano > 2020)
        {
            printf("Digite um ano valido (1930-2020): ");
            scanf("%d", &novosDadosProfessor.dataNascimento.ano);
        }
        while ( (c = getchar()) != '\n' && c != EOF );
    }

    printf("Digite o CPF do professor: ");
    fgets(novosDadosProfessor.cpf, sizeof(novosDadosProfessor.cpf), stdin);

    for(int i = 0; i < 21; i++)
    {
        professores[codigoProfessor].nome[i] = novosDadosProfessor.nome[i];
    }

    for(int i = 0; i < 15; i++)
    {
        professores[codigoProfessor].cpf[i] = novosDadosProfessor.cpf[i];
    }

    professores[codigoProfessor].sexo = novosDadosProfessor.sexo;

    professores[codigoProfessor].dataNascimento.dia = novosDadosProfessor.dataNascimento.dia;
    professores[codigoProfessor].dataNascimento.mes = novosDadosProfessor.dataNascimento.mes;
    professores[codigoProfessor].dataNascimento.ano = novosDadosProfessor.dataNascimento.ano;

    printf("Professor atualizado com sucesso.\nPressione ENTER para continuar...");
    getchar();
}

struct Disciplina cadastrarDisciplina(struct Pessoa* professores, int numeroProfessores, int idDisciplina)
{
    system("clear");

    if(numeroProfessores == 0)
    {   
        printf("Nao existem professores ainda para que a disciplina possa ser cadastrada.");
        printf("Pressione enter para continuar...");
        getchar();
        return;
    }

    int c;
    struct Disciplina novaDisciplina;
    int codigoProfessor = 0;
    printf("Digite o nome da nova disciplina: ");
    fgets(novaDisciplina.nome, sizeof(novaDisciplina.nome), stdin);

    printf("Digite o codigo da nova disciplina: ");
    fgets(novaDisciplina.codigo, sizeof(novaDisciplina.codigo), stdin);


    for(int i = 0; i < numeroProfessores; i++)
    {
        printf("%d. %s\n", i + 1, professores[i].nome);
    }

    while(codigoProfessor < 1 || codigoProfessor > numeroProfessores)
    {
        printf("\nDigite o codigo do professor da nova disciplina: ");
        scanf("%d", &codigoProfessor);
    }
    while ( (c = getchar()) != '\n' && c != EOF );

   for(int i = 0; i < 21; i++)
   {
       novaDisciplina.professor.nome[i] = professores[codigoProfessor - 1].nome[i];
   } 

    printf("Digite o semestre da nova disciplina: ");
    scanf("%c", &novaDisciplina.semestre);
    while ( (c = getchar()) != '\n' && c != EOF );

    novaDisciplina.id = idDisciplina + 1;

    system("clear");
    novaDisciplina.numeroAlunosInscritos = 0;
    return novaDisciplina;
}

void modificarDisciplinaExistente(struct Disciplina* disciplinas, int* numeroDisciplinas, struct Pessoa* professores, int numeroProfessores)
{

    if(*numeroDisciplinas == 0)
    {
        printf("Nao existem disciplinas para serem modificadas.");
        printf("Pressione enter para continuar...");
        getchar();
        return;
    }

    system("clear");
    for(int i = 0; i < *numeroDisciplinas; i++)
    {
        printf("%d. %s", i + 1, disciplinas[i].nome);
    }
    int codigoDisciplina = 0, c;
    struct Disciplina novosDadosDisciplina;
    while(codigoDisciplina < 1 || codigoDisciplina > *numeroDisciplinas)
    {
        printf("Digite o codigo da disciplina que deseja modificar: ");
        scanf("%d", &codigoDisciplina);
    }
    while ( (c = getchar()) != '\n' && c != EOF );
    codigoDisciplina -= 1;

    printf("Digite o nome da disciplina: ");
    fgets(novosDadosDisciplina.nome, sizeof(novosDadosDisciplina.nome), stdin);

    printf("Digite o codigo da disciplina: ");
    fgets(novosDadosDisciplina.codigo, sizeof(novosDadosDisciplina.codigo), stdin);

    printf("Digite o semestre da disciplina: ");
    scanf("%d", novosDadosDisciplina.semestre);
    while ( (c = getchar()) != '\n' && c != EOF );

    int codigoProfessor = 0;
    for(int i = 0; i < numeroProfessores; i++)
    {
        printf("%d. %s\n", i + 1, professores[i].nome);
    }

    while(codigoProfessor < 1 || codigoProfessor > numeroProfessores)
    {
        printf("\nDigite o codigo do professor da nova disciplina: ");
        scanf("%d", &codigoProfessor);
    }
    while ( (c = getchar()) != '\n' && c != EOF );

    disciplinas[codigoDisciplina].semestre = novosDadosDisciplina.semestre;

    for(int i = 0; i < 21; i++)
    {
       disciplinas[codigoDisciplina].professor.nome[i] = professores[codigoProfessor - 1].nome[i];
    }


    for(int i = 0; i < 21; i++)
    {
        disciplinas[codigoDisciplina].nome[i] = novosDadosDisciplina.nome[i];
    }

    for(int i = 0; i < 12; i++)
    {
        disciplinas[codigoDisciplina].codigo[i] = novosDadosDisciplina.codigo[i];
    }

    printf("Disciplina atualizada com sucesso.\nPressione ENTER para continuar...");
    getchar();
}

void excluir(struct Pessoa *individuos, int* numeroIndividuos)
{
    if(*numeroIndividuos == 0){
        printf("Nao existem individuos para serem excluidos.");
        printf("Pressione enter para continuar...");
        getchar();
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

    if(numIndividuo < 1 || numIndividuo > *numeroIndividuos)
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
        printf("Pressione enter para continuar...");
        getchar();
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

        system("clear");

        if(*numeroAlunos == 0)
        {
            printf("Nenhum aluno cadastrado no sistema.\n");
            printf("Pressione enter para continuar...");
            getchar();
            return;
        }

        if(*numeroDisciplinas == 0)
        {
            printf("Nenhuma disciplina cadastrada no sistema.\n");
            printf("Pressione enter para continuar...");
            getchar();
            return;
        }
        
        printf("Digite o numero do aluno que voce deseja matricular numa disciplina: \n");
        for(int i = 0; i < *numeroAlunos; i++)
        {
            printf("%d. %s\n", i + 1, alunos[i].nome);
        }
        int numAluno = 0, c;
        while(numAluno < 1 || numAluno > *numeroAlunos)
        {
            printf("Digite o numero do aluno que voce deseja matricular numa disciplina: ");
            scanf("%d", &numAluno);
        }

        while ( (c = getchar()) != '\n' && c != EOF );
        numAluno = numAluno - 1;
        
        for(int i = 0; i < *numeroDisciplinas; i++)
        {
            printf("%d. %s\n", i + 1, disciplinas[i].nome);
        }

        int numDisciplina = 0;
        while(numDisciplina < 1 || numDisciplina > *numeroDisciplinas)
        {
            printf("Digite o numero da disciplina em que voce deseja matricular o aluno: ");
            scanf("%d", &numDisciplina);
        }
        while ( (c = getchar()) != '\n' && c != EOF );

        numDisciplina = numDisciplina - 1;
        for(int i = 0; i < alunos[numAluno].numeroDeDisciplinas; i++)
        {
            if(alunos[numAluno].cursando[i] == disciplinas[numDisciplina].id)
            {
                printf("Aluno ja matriculado nessa disciplina.\nPressione ENTER para continuar...");
                getchar();
                return;
            }
        }
        
        int numeroAlunosInscritos = disciplinas[numDisciplina].numeroAlunosInscritos;

        if(numeroAlunosInscritos == 50)
        {
            printf("Nao ha vagas nessa disciplina.");
            return;
        }

        disciplinas[numDisciplina].alunosMatriculados[disciplinas[numDisciplina].numeroAlunosInscritos] = alunos[numAluno].matricula;
        alunos[numAluno].cursando[alunos[numAluno].numeroDeDisciplinas] = disciplinas[numDisciplina].id;

        // incrementar numero de disciplinas em que o aluno esta inscrito
        alunos[numAluno].numeroDeDisciplinas = alunos[numAluno].numeroDeDisciplinas + 1;

        // incrementar o numero de alunos inscritos em dada disciplina
        disciplinas[numDisciplina].numeroAlunosInscritos = disciplinas[numDisciplina].numeroAlunosInscritos + 1;

        printf("Aluno cadastrado com sucesso.\n");
        printf("Pressione enter para continuar...");
        getchar();
        system("clear");
}

void desmatricularAlunoDisciplina(struct Pessoa *alunos, struct Disciplina *disciplinas, 
    int* numeroAlunos, int* numeroDisciplinas){

    if(*numeroAlunos == 0)
    {
        printf("Nenhum aluno cadastrado no sistema.\n");
        printf("Pressione enter para continuar...");
        getchar();
        return;
    }

    if(*numeroDisciplinas == 0)
    {
        printf("Nenhuma disciplina cadastrada no sistema.\n");
        printf("Pressione enter para continuar...");
        getchar();
        return;
    }
    
    int codigoAluno = 0, c;

    for(int i = 0; i < *numeroAlunos; i++)
    {
        printf("%d. %s", i + 1, alunos[i].nome);
    }
    
    while(codigoAluno <= 0 || codigoAluno > *numeroAlunos)
    {
        printf("Digite o codigo do aluno que deseja desmatricular de uma disciplina: ");
        scanf("%d", &codigoAluno);
    }
    while ( (c = getchar()) != '\n' && c != EOF );

    codigoAluno = codigoAluno - 1;

    if(alunos[codigoAluno].numeroDeDisciplinas == 0)
    {
        printf("Aluno não esta matriculado em nenhuma disciplina.\nPressione ENTER para continuar...");
        getchar();
        system("clear");
        return;
    }

    int codigoDisciplina = 0;
    int codigosDisciplinasAluno[5];
    int contador = 0;
    for(int i = 0; i < alunos[codigoAluno].numeroDeDisciplinas; i++)
    {
        for(int j = 0; j < *numeroDisciplinas; j++)
        {
            if(disciplinas[j].id == alunos[codigoAluno].cursando[i])
            {
                codigosDisciplinasAluno[contador] = disciplinas[j].id;
                contador++;
                printf("%d. %s\n", contador, disciplinas[j].nome);
            }
        }
    }

    while(codigoDisciplina < 1 || codigoDisciplina > alunos[codigoAluno].numeroDeDisciplinas)
    {
        printf("Digite o codigo da disciplina que voce deseja desmatricular o aluno: ");
        scanf("%d", &codigoDisciplina);
    }
    while ( (c = getchar()) != '\n' && c != EOF );
    codigoDisciplina = codigoDisciplina - 1;

    for(int i = 0; i < *numeroDisciplinas; i++)
    {
        if(disciplinas[i].id == codigosDisciplinasAluno[codigoDisciplina])
        {
        for(int j = 0; j < disciplinas[i].numeroAlunosInscritos; j++)
        {
            if(disciplinas[i].alunosMatriculados[j] == alunos[codigoAluno].matricula)
            {
                for(int k = j; k < disciplinas[i].numeroAlunosInscritos; k++)
                {
                    disciplinas[i].alunosMatriculados[k] = disciplinas[i].alunosMatriculados[k + 1];
                }
                disciplinas[i].numeroAlunosInscritos = disciplinas[i].numeroAlunosInscritos - 1;
            }
        }
        }
    }

    for(int i = codigoDisciplina - 1; i < alunos[codigoAluno].numeroDeDisciplinas; i++)
    { 
        alunos[codigoAluno].cursando[i] = alunos[codigoAluno].cursando[i + 1];
    } 

    alunos[codigoAluno].numeroDeDisciplinas = alunos[codigoAluno].numeroDeDisciplinas - 1;

    printf("Aluno removido da disciplina com sucesso.\n");
    printf("Pressione enter para continuar...");
    getchar();
    system("clear");
}