#include <iostream>

using namespace std;

class outraClasse{
    public:
        int xInt;
        string sString;
};

class testeClasse{
    
};

int main(){
    outraClasse outroObjeto;

    cout << "Tamanho do Int: ";
    cout << sizeof(outroObjeto.xInt)<< endl;
    cout << "Tamanho da String ";
    cout << sizeof(outroObjeto.sString)<< endl;
    cout << "Tamanho da Classe: ";
    cout << sizeof(outroObjeto) << endl;

    cout << "Tamanho da Classe Vazia: ";
    cout << sizeof(testeClasse) << endl;

    return 0;
}