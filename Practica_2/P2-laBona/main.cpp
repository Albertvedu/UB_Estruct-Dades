#include <iostream>
#include "MainExercici1.h"
#include "MainExercici2.h"
#include "MainExercici3.h"
//#include <cstdlib>
#include <csignal>

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
            sleep(1);
        }
    }

    return atoi(lectura);
}
void menu(int &opcio){
      cout << "\n\n\e[1m############   MENU   ############\e[0m" << endl;
    cout << "\nHola, quin exercici vols executar? " << endl;
    cout << "\n1. Exercici 1" << endl;
    cout << "2. Exercici 2" << endl;
    cout << "3. Exercici 3" << endl;
    cout << "0. Sortir" << endl;
    opcio = llegirStringTOint("\nOpció: ", 0, 3);
}
int main(){
    int opcio;
    MainExercici1 exercici1;
    MainExercici2 exercici2;
    MainExercici3 exercici3;
   
    do {  //Considero deixar el frond-end al Main i el back-end a les classes particulars.
        
            menu(opcio);
            switch (opcio) {
                case 1:
                    exercici1.inici();
                    break;
                case 2:
                    exercici2.inici();
                    break;
                case 3:
                    exercici3.inici();
                    break;
         
                default:
                    break;
            }
        
    } while (opcio != 0);
   
    cout << "\nBye bye" << endl;
    return 0;
}