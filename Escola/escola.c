#include <stdio.h>
#include "funcionalidades.h"

int main()
{
    struct Pessoa alunos[100];
    struct Pessoa professores[100];
    struct Disciplina disciplinas[100];
    int func = 0, c;
    int numeroAtualAlunos = 0;
    int numeroAtualProfessores = 0;
    int numeroAtualDisciplinas = 0;
    int geradorDeMatriculas = 0;
    int geradorDeIdDisciplina = 0;
    while (func != 9 && func != EOF)
    {
        printf("Bem vindo ao Projeto Escola! Digite o que deseja fazer: \n");
        printMenu();
        scanf(" %d", &func);
        while ( (c = getchar()) != '\n' && c != EOF );
        
        switch (func)
        {
            case 1: 
                cadastrarExcluirAluno(alunos, &numeroAtualAlunos, &geradorDeMatriculas);
                break;
            case 2: 
                cadastrarExcluirProfessor(professores, &numeroAtualProfessores);
                break;
            case 3: 
                cadastrarExcluirDisciplina(disciplinas, &numeroAtualDisciplinas, professores, &numeroAtualProfessores, &geradorDeIdDisciplina);
                break;
            case 4:
                listarAlunos(alunos, numeroAtualAlunos);
                break;
            case 5:
                listarProfessores(professores, numeroAtualProfessores);
                break;
            case 6:
                listarDisciplinas(disciplinas, numeroAtualDisciplinas, alunos, numeroAtualAlunos);
                break;
            case 7:
                matricularAlunoNumaDisciplina(alunos, disciplinas, &numeroAtualAlunos, &numeroAtualDisciplinas);
                break;
            case 8:
                desmatricularAlunoDisciplina(alunos, disciplinas, &numeroAtualAlunos, &numeroAtualDisciplinas);
                break;
            case 9:
                printf("Tchau!\n");
                return 0;
            default:
                printf("Funcionalidade não reconhecida.\n");
                break;
        }
    }
    return 0;
}