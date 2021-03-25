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
    while (func != 7 && func != EOF)
    {
        printf("Bem vindo ao Projeto Escola! Digite o que deseja fazer: \n");
        printMenu();
        scanf(" %d", &func);
        while ( (c = getchar()) != '\n' && c != EOF );
        
        switch (func)
        {
            case 1: ;
                struct Pessoa novoAluno = cadastrarAluno();
                alunos[numeroAtualAlunos] = novoAluno;
                ++numeroAtualAlunos;
                break;
            case 2: ;
                struct Pessoa novoProfessor = cadastrarProfessor();
                professores[numeroAtualProfessores] = novoProfessor;
                ++numeroAtualProfessores;
                break;
            case 3: ;
                struct Disciplina novaDisciplina = cadastrarDisciplina();
                disciplinas[numeroAtualDisciplinas] = novaDisciplina;
                ++numeroAtualDisciplinas;
                break;
            case 4:
                listarAlunos(alunos, numeroAtualAlunos);
                break;
            case 5:
                listarProfessores(professores, numeroAtualProfessores);
                break;
            case 6:
                listarDisciplinas(disciplinas, numeroAtualDisciplinas);
                break;
            case 7:
                printf("Tchau!\n");
                return 0;
                break;
            default:
                printf("Funcionalidade não reconhecida.\n");
                break;
        }
    }
    return 0;
}

