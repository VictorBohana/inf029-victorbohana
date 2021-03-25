struct Pessoa
{
    char matricula[12];
    char nome[21];
    char sexo;
    char dataNascimento[11];
    char cpf[15];
};

struct Disciplina
{
    char codigo[12];
    char nome[21];
    char semestre;
    struct Pessoa professor;
    struct Pessoa alunos[50];
};

void printMenu();
void printMenuAlunos();
void printMenuProfessores();
void printMenuDisciplinas();
void listarAlunos(struct Pessoa* alunos, int quantidadeAlunos);
void listarProfessores(struct Pessoa* professores, int quantidadeProfessores);
void listarDisciplinas(struct Disciplina* disciplinas, int quantidadeDisciplinas);
struct Pessoa cadastrarAluno();
struct Pessoa cadastrarProfessor();
struct Disciplina cadastrarDisciplina();