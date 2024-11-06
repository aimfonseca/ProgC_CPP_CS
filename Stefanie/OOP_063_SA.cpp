#include <iostream>
using namespace std;

void meuCarimbo(void);
void mudaLinha(void);

class classeBase{
    public:
        int comissao = 10;
        void print() {
            cout << "funcao principal" << endl;
        }
};
class classeDerivada : public classeBase{
    public:
        void print() {
            cout << "funcao derivada" << endl;
        }
};


void mudaLinha(void)
{
    printf("\n");
}	

void meuCarimbo(void)
{
    time_t tempo_atual = time(NULL);
    struct tm *tempo_local = localtime(&tempo_atual);
    char data_hora[64];
    
    strftime(data_hora, sizeof(data_hora), "%d-%m-%Y %H:%M:%S", tempo_local);
    printf("\n[UFCD_U15] - [Stefanie Abreu] - [ %s ]", data_hora);
    mudaLinha();
}






int main() {
    classeDerivada exemploUm;
    exemploUm.print();
    cout << exemploUm.comissao << endl;

    meuCarimbo();
    mudaLinha();
    
    return 0;
}