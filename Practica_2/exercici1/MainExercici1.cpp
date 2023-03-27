#include <iostream>
#include <vector>
#include <stdexcept>


using namespace std;

#include "PilaEstatica.h"

void compare(int valor, int limitA, int limitB){
    if (valor < limitA || valor > limitB)
        throw invalid_argument( "Dades introduïdes incorrectes" );
}
bool esNumero(char *lectura) {
    for( ; *lectura; ++lectura )
        if( !isdigit(*lectura) )
            return false;
    return true;
}

int llegirStringTOint(string text, int limitA, int limitB) {
    // Post: retorna lectura Integer o error si no és Integer

    char lectura[100];
    int numero;

    while(true){
        try{
            cout << text;
            cin >> lectura;
            if(!esNumero(lectura) )
                throw invalid_argument( "Dades introduïdes incorrectes" );
            compare(atoi(lectura), limitA, limitB );
            break;
        }catch(const std::exception& e){
            cerr << e.what() << '\n';
        }
    }

    return atoi(lectura);
}

void menu(int &opcio, vector<string> opMenu){
    
    cout << "\n\e[1m############   MENU   ############\e[0m" << endl;
    cout << "\nHola " <<  ", que vols fer? " << endl;
    vector<string>::iterator it;

    for (it = opMenu.begin(); it != opMenu.end(); ++it)
        cout << "\n" << *it << endl;
    opcio = llegirStringTOint("\nOpció: ", 1,opMenu.size());
}
void empilar(PilaEstatica &p){
    int nombre;
    nombre = llegirStringTOint("Insereix el nombre que vols afegir: ", INT8_MIN, INT8_MAX);
    try{
        p.afegirElement(nombre);
        cout << "\nElement " << nombre << " agregat" << endl;
    }catch( string e){
        cout << e << endl;
    }

}
void desempilar(PilaEstatica &p){
    try{
        int element = p.elementFront();
        p.treureElement();
        cout << "Element "<< element << " eliminat" << endl;
    }catch( string e){
        cout << e << endl;
    }
   
}
void veureCim(PilaEstatica &p){
    try{
       cout << "\nFront: " << p.elementFront() << endl;
    }catch( string e){
        cout << e << endl;
    }
    
}
void veurePila(PilaEstatica &p){
    try{
       p.imprimeix();
    }catch( string e){
        cout << e << endl;
    }
    
}
void posicioCim(PilaEstatica &p){
    cout << "La posició del cim és: " << p.tamany() -1;
}
void casProva1(PilaEstatica &p){
    //AFEGIR 10
    p.afegirElement(10);
    cout << "\nElement " << 10 << " agregat" << endl;
    // AFEGIR 11
    p.afegirElement(11);
    cout << "Element " << 11 << " agregat" << endl;
    // MOSTRAR FRONT
    cout << "Front: " << p.elementFront() << endl;
    // AFEGIR 12
    p.afegirElement(12);
    cout << "Element " << 12 << " agregat" << endl;
    // AFEGIR 13
     try{
        p.afegirElement(13);
        cout << "\nElement " << 13 << " agregat" << endl;
    }catch( string e){
        cout << e;
    }
    //MOSTRAR PILA
    p.imprimeix();
    cout << "Front: " << p.elementFront() << endl;
    // ELIMINAR ELEMENT
    int element = p.elementFront();
    p.treureElement();
    cout << "Element "<< element << " eliminat" << endl;
    // AFEGIR 14
    p.afegirElement(14);
    cout << "Element " << 14 << " agregat" << endl;
    // MOSTRAR PILA
    p.imprimeix();
    //MOSTRAR FRONT
    cout << "Front: " << p.elementFront() << endl;

    //ELIMINAR ELEMENT
    element = p.elementFront();
    p.treureElement();
    cout << "Element "<< element << " eliminat" << endl;

    //ELIMINAR ELEMENT
    element = p.elementFront();
    p.treureElement();
    cout << "Element "<< element << " eliminat" << endl;

    //ELIMINAR ELEMENT
    element = p.elementFront();
    p.treureElement();
    cout << "Element "<< element << " eliminat" << endl;
    
    //ELIMINAR ELEMENT
    try{
        element = p.elementFront();
        p.treureElement();
        cout << "Element "<< element << " eliminat" << endl;
    }catch( string e){
        cout << e << endl;
    }

}
int main(){
    //PilaEstatica p(23);  //Aqui utilitzo el constructor amb paràmetre (int tamany_maxim = TAMANY_MAXIM)
    PilaEstatica p;        // Aqui constructor per defecta. Que va al mateix lloc, no sé perquè.
    // El problema és que el primer no fa servir la constant TAMANY_MAXIM i llavors dins dels mètodes la cosa falla

    vector <string> opMenu = {"1. Inserir element a la pila ","2. Treure element de la pila","3. Consultar el top de la pila",
                              "4. Imprimir tot el contingut de la PilaEstàtica","5. Imprimir la posició del top de la pila",
                              "6. Sortir"};
    int opcio;
    casProva1(p);

    do{
        menu(opcio, opMenu);
        switch (opcio){
            case 1:
                empilar(p);
                break;
            case 2:
                desempilar(p);
                break;
            case 3:
                veureCim(p);
                break;
            case 4:
                veurePila(p);
                break;
            case 5:
                posicioCim(p);
                break;
            default:
                break;
        }
    } while (opcio != 6);

    cout << "\nPassiu bé...\n" << endl;
}