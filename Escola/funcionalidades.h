struct DataNascimento
{
    int dia;
    int mes;
    int ano;
};

struct Pessoa
{
    int matricula;
    char nome[21];
    char sexo;
    struct DataNascimento dataNascimento;
    char cpf[15];
    int numeroDeDisciplinas;
    int cursando[5];
};

struct Disciplina
{
    int id;
    char codigo[12];
    char nome[21];
    char semestre;
    int numeroAlunosInscritos;
    struct Pessoa professor;
    int alunosMatriculados[50];
};

void printMenu();
void printMenuCadastrarExcluirAluno();
void printMenuCadastrarExcluirProfessor();
void printMenuCadastrarExcluirDisciplina();
void listarAlunos(struct Pessoa* alunos, int quantidadeAlunos);
void listarAlunosPorIdade(struct Pessoa* alunos, int quantidadeAlunos);
void listarProfessores(struct Pessoa* professores, int quantidadeProfessores);
void listarProfessoresPorIdade(struct Pessoa* professores, int quantidadeProfessores);
void listarDisciplinas(struct Disciplina* disciplinas, int quantidadeDisciplinas, struct Pessoa* alunos, int quantidadeAlunos);
struct Pessoa cadastrarAluno(int numAlunos);
void modificarAlunoExistente(struct Pessoa* alunos, int* numeroAlunos);
struct Pessoa cadastrarProfessor(int numProfessores);
void modificarProfessorExistente(struct Pessoa* professores, int* numeroProfessores);
struct Disciplina cadastrarDisciplina(struct Pessoa *professores, int numeroProfessores, int idDisciplina);
void cadastrarExcluirAluno(struct Pessoa *alunos, int* numeroAlunos, int* geradorDeMatriculas);
void cadastrarExcluirProfessor(struct Pessoa *professores, int* numeroProfessores);
void cadastrarExcluirDisciplina(struct Disciplina *disciplinas, int* numeroDisciplinas, struct Pessoa* professores, int* numeroProfessores, int* geradorDeIdDisciplina);
void excluir(struct Pessoa *individuos, int* numeroIndividuos);
void excluirDisciplina(struct Disciplina *disciplinas, int* numeroDisciplinas);
void matricularAlunoNumaDisciplina(struct Pessoa *alunos, struct Disciplina *disciplinas, 
    int* numeroAlunos, int* numeroDisciplinas);
void desmatricularAlunoDisciplina(struct Pessoa *alunos, struct Disciplina *disciplinas, 
    int* numeroAlunos, int* numeroDisciplinas);
void modificarDisciplinaExistente(struct Disciplina* disciplinas, int* numeroDisciplinas, struct Pessoa* professores, int numeroProfessores);