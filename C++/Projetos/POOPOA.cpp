#include <iostream>
#include <string>
#include <functional>

using namespace std;

class Agenda { // Classe para marcar
private:
    string name;   // Nome(atributo) privado
public:
    // Construtor inicial
    Agenda(const string& p_name) : name(p_name) // Construtor marca o nome da pessoa
    {cout << "Marcado para a pessoa: " << name << endl;}
    // Destrutor ao final
    ~Agenda()   // Destrutor realiza uma mensagem de sucesso
    {cout << "Tudo realizado, estou indo embora" << name << endl;}
};


// Aplica o agendamento para ida e volta (função transversal)
void agendamento(const string& name, const string& texto){
    Agenda marcador(name);  // Imprimir a confirmação com o nome da pessoa
    cout << texto << endl;    // Texto de marcação
    // Aqui se supõe a colocação de um dia para ida e volta
}


// Atendimento e retorno médico
class Marcar {
private:
    string nome_do_paciente;
public:
    Marcar(const string& nome) : nome_do_paciente(nome) {}    // Construtor inicia atribuindo name a nome_paciente
    void atendimento() {agendamento(nome_do_paciente, "Chegar dia:");}   // Método para marcar atendimento
    void retorno() { agendamento(nome_do_paciente, "Retornar dia:");}  // Método para marcar retorno
};


int main() {
    string nome;
    cout << "Digite o nome do paciente" << endl;
    cin >> nome;
    Marcar paciente(nome);        // Objeto paciente do hospital
    paciente.atendimento(); // Marcar atendimento
    paciente.retorno();     // Marcar retorno
}
