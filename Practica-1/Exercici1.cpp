#include <iostream>
using namespace std;

void identificat(string &nom){
    cout << "Hola, com et dius? ";
    cin >> nom;
}
void menu(int &opcio, string nom){
    cout << "\nHola " << nom << ", que vols fer? " << endl;
    cout << "\n1. Sortir" << endl;
    cout << "2. Benvinguda" << endl;
    cout << "\nopcio: "; 
    cin >> opcio;

}
void benvinguda(string nom){
    cout << "\nBenvingut/da a l'assignatura d'estructura de dades " << nom << endl;
}
int mainExercici1(){
    string nom;
    string arrOptions = {"Sortir", "Benvinguda"};
    int opcio;
    bool sortir = false;

    identificat(nom);
    
    while ( !sortir ){
        menu(opcio, nom);
        switch (opcio){
            case 1: 
                sortir = true;
                break;
            case 2:
                benvinguda(nom);
                break;
            default:
                break;
        }
        
    }

    cout << "\nFins a la propera " << nom << endl << endl;

    return 0;
}