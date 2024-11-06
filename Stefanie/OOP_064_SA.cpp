#include <iostream>
#include <string>

using namespace std;

void meuCarimbo(void);
void mudaLinha(void);

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

class Dog : public Animal { // Herda da classe Animal
public:
    // Chama o construtor da classe base 'Animal', com o parâmetro 'name'
    Dog(string name) : Animal(name) {}

    void Bark() {
        cout << "au! au!" << endl;
    }
};


void meuCarimbo(void)
{
    time_t tempo_atual = time(NULL);
    struct tm *tempo_local = localtime(&tempo_atual);
    char data_hora[64];
    
    strftime(data_hora, sizeof(data_hora), "%d-%m-%Y %H:%M:%S", tempo_local);
    printf("\n[UFCD_U15] - [Stefanie Abreu] - [ %s ]", data_hora);

}
   
   void mudaLinha(void)
{
    printf("\n");
}	


int main() {
    
    Dog myDog("Loki");

    // Evoca o método da classe base.
    myDog.Eat();

    // Evoca o método da classe derivada.
    myDog.Bark();

    meuCarimbo();
    mudaLinha();    

    return 0;
}
