struct Pessoa
{
    char matricula[12];
    char nome[21];
    char sexo;
    char dataNascimento[11];
    char cpf[15];
    int numeroDeDisciplinas;
};

struct Disciplina
{
    char codigo[12];
    char nome[21];
    char semestre;
    int numeroAlunosInscritos;
    struct Pessoa professor;
    struct Pessoa alunos[50];
};

void printMenu();
void printMenuCadastrarExcluirAluno();
void printMenuCadastrarExcluirProfessor();
void printMenuCadastrarExcluirDisciplina();
void listarAlunos(struct Pessoa* alunos, int quantidadeAlunos);
void listarProfessores(struct Pessoa* professores, int quantidadeProfessores);
void listarDisciplinas(struct Disciplina* disciplinas, int quantidadeDisciplinas);
struct Pessoa cadastrarAluno();
struct Pessoa cadastrarProfessor();
struct Disciplina cadastrarDisciplina();
void cadastrarExcluirAluno(struct Pessoa *alunos, int* numeroAlunos);
void cadastrarExcluirProfessor(struct Pessoa *professores, int* numeroProfessores);
void cadastrarExcluirDisciplina(struct Disciplina *disciplinas, int* numeroDisciplinas);
void excluir(struct Pessoa *individuos, int* numeroIndividuos);
void excluirDisciplina(struct Disciplina *disciplinas, int* numeroDisciplinas);
void matricularAlunoNumaDisciplina(struct Pessoa *alunos, struct Disciplina *disciplinas, 
    int* numeroAlunos, int* numeroDisciplinas);