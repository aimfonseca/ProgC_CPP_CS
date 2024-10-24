#include <iostream>
 
using namespace std;
 
//definição da classe
class nomeClasse{
    //declaração de membros privados desta classe
    private:
        int valorPrivado;
 
    //declaração de membros públicos desta classe
    public:
        int valorPublico;
 
        void funcaoPublica(){
            cout << "Esta é a minha primeira função" << endl;
        }
}; // Fim da classe 'nomeClasse', termina com ';'
 
int main(){
    //instanciando um objeto da classe 'nomeClasse'
    nomeClasse objetoNovo;
 
    //Podemos aceder e modificar os dados de um objeto público
    objetoNovo.valorPublico = 10;
 
    //Também podemos usar as funções públicas definidas dentro da classe
    objetoNovo.funcaoPublica();
}
 