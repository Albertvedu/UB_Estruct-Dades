#include <iostream>
#include <cstdlib>
#include <csignal>
#include "Llista.h"
#include "Posicio.h"
#include "Poco.h"
//#include "Clinica.h"
#include "Mascota.h"

using namespace std;

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
                throw invalid_argument( "Dades introduïdes incorrectes");
            compare(atoi(lectura), limitA, limitB );
            break;
        }catch(const std::exception& e){
            cerr << e.what() << '\n';
        }
    }

    return atoi(lectura);
}
void print(Llista<string>* l1) {
    try {
        for (Posicio<string> itr = l1->principi(); itr != l1->final().next(); itr = ++itr)
            cout << itr.element() << endl;

    }catch(const std::exception& e){
        cerr << e.what() << '\n';
        sleep(1);
    }
}
void menu(int &opcio, Llista<string>* opMenu){
    cout << "\n\e[1m############   MENU   ############\e[0m" << endl;
    cout << "\nHola " <<  ", que vols fer? " << endl;
    print(opMenu);
    opcio = llegirStringTOint("\nOpció: ", 0,opMenu->tamany()-1);
}
void llegirArxiu(){
//    Clinica c = new Clinica("Clinica");
//    c.afegirClientsArxiu("/home/albert/Projects_VS/UB_Estruct-Dades/practica-2/Exercici-3/clients4Gats.txt");
}
int main(){
    int opcio;

    Llista<string>* opMenu = new Llista<string> ( {"1. Afegir Client ","2. Eliminar Client","3. Afegir Mascota a un client",
                              "4. Eliminar Mascota d'un client","5. Imprimir clients clinica","6. Imprimir les mascotes d'un client",
                              "0. Sortir"});

    menu(opcio, opMenu);


    Llista<Client>* la;    // = new Llista<Client>();



//    l1->inserirPrincipi("gos");
//    l1->inserirFinal("gat");
//    l1->inserirFinal("LLORO");
//    l1->inserirFinal("serp");
//    Llista<string>* l2 = new Llista<string>(*l1);

//

    //llegirArxiu();
    return 0;
}