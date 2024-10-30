#include <iostream>
#include <string>

using namespace std;

void mudaLinha(void); 
void meuCarimbo(void);

class Animal {
public:
    string name;

    Animal(string name){
        this -> name = name;
    }

    void Eat() {
        cout << name << " is eating." << endl;
    }
};

class Dog : public Animal {
public:
    // Chama o construtor da classe base 'Animal', com o parâmetro 'name'
    Dog(string name) : Animal(name) {}

    void Bark() {
        cout << "au! au!" << endl;
    }
};

int main() {

    meuCarimbo();
	mudaLinha();
    
    Dog myDog("Loki");

    // Evoca o método da classe base.
    myDog.Eat();

    // Evoca o método da classe derivada.
    myDog.Bark();

    return 0;
}

// ------------------------------------------
// Fun��o que muda de linha quando necess�rio
	
	void mudaLinha(void)
	{
		printf("\n"); // muda de linha
	}	
	
// ------------------------------------------
// Fun��o que mostra (algumas) informa��es gerais
	
	void meuCarimbo(void)
	{
		time_t tempo_atual = time(NULL);
		struct tm *tempo_local = localtime(&tempo_atual);
		char data_hora[64];
		
		strftime(data_hora, sizeof(data_hora), "%d-%m-%Y %H:%M:%S", tempo_local);
		printf("\n[Samyra Lima] - [ %s ]", data_hora);
		mudaLinha();
	}

