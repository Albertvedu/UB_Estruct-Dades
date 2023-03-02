#include <iostream>
#include "vector"
#include "Estudiant.h"
#include "Professor.h"
#include <stdexcept>
#include <fstream>
#include <bits/stdc++.h>


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

void menu(int &opcio,  vector<string> menuOptions){
    cout << "\nHola " <<  ", que vols fer? " << endl;
    vector<string>::iterator it;

    for (it = menuOptions.begin(); it != menuOptions.end(); ++it)
        cout << "\n"
             << *it << endl;
    opcio = llegirStringTOint("\nOpció: ", 1,menuOptions.size());
}

Estudiant afegirEstudiant(int &nEstudiant){
    //Post: Estudiant insertat
    string nom;
    int anyNeix, nAssignatures;
    nEstudiant ++;

    cout << "\nEstudiant: " << nEstudiant << endl;
    cout << "\nNom?: "; cin >> nom;
    anyNeix = llegirStringTOint("\nAny neixament?: ", 0, 2023);
    nAssignatures = llegirStringTOint("\nAssignatures? (1..20): ",1, 20);
    Estudiant estudiant(nom, anyNeix, nAssignatures);

    return estudiant;
}
Professor afegirProfessor(int &nProfessor){
    nProfessor ++;
    string nom;
    int anyNeix;

    cout << "\nProfessor: " << nProfessor << endl;
    cout << "\nNom?: "; cin >> nom;
    anyNeix = llegirStringTOint("\nAny neixament?: ", 0, 2023);
    Professor professor(nom, anyNeix);
    return professor;

}
void llegirOpcioPersona(string &op){
    // Post: Retorna l'opció Persona

    do{
        cout << "\nPrem 'E' per crear un estudiant o 'P' per crear un professor? ";
        cin >> op;
        op = tolower(op[0]);

       if ( op != "e" && op != "p")
            cout << "Opció incorrecta: \n\n"
                 << endl;
    } while (op != "e" && op != "p");
}
void printProfessor(const Professor& professor) {
    cout << "\n\e[1mProfessor (Nom ==> " << professor.getName()
         << ", Naixement ==> " << professor.getDataNaixement() << ")" << endl;
    cout << "Edat del nou estudiant: " << professor.getEdat() << "\e[0m" << endl;
}
void printEstudiant( Estudiant estudiant) {
    cout << "\n\e[1mEstudiant (Nom ==> " << estudiant.getName()
         << ", Naixement ==> " << estudiant.getDataNaixement()
         << ", Assignatures ==> " << estudiant.getAssignatures() << ")" << endl;
    cout << "Edat del nou estudiant: " << estudiant.getEdat() << "\e[0m" << endl;
}
void afegirPersona(int &nEstudiant, int &nProfessor){
    string op;
    llegirOpcioPersona(op);

    if ( !op.compare("e") )
        printEstudiant(afegirEstudiant(nEstudiant));

    else
        printProfessor(afegirProfessor(nProfessor));
}
void resumPersonesHumanes(int nEstudiant, int nProfessor){
    cout << "\n\e[1mEstudiants creats: " << nEstudiant << " Professors creats: " << nProfessor << "\e[0m"<< endl;
}
void llegirFitxer(int &nEstudiant, int &nProfessor){

// Pre : entra el nom del fitxer a llegir
// Post: treu per pantalla contingut del fitxer

    string nom;
    string tipus;
    int any, assignatures;


    if ( ifstream arxiu{ "/home/albert/CLionProjects/BorrarProves/fitxer.txt" }) {

        while (  !arxiu.eof() ) {
            arxiu >> tipus;
            arxiu >> nom;
            arxiu >> any;
            
            if (tipus == "E"){
                arxiu >> assignatures;
                cout << "\nEstudiant(Nom ==> " << nom
                     << ", Naixement ==> " << any
                     << ", Assignatures ==> " << assignatures << ")";
                nEstudiant ++;
            }else{
                cout << "\nProfessor(Nom ==> " << nom
                     << ", Naixement ==> " << any << ")";
                nProfessor ++;
            }
        }
        arxiu.close();
        cout << endl;
    } else {
        cout << "NO S'HA POGUT OBRIR EL FITXER";

    }
}
int main(){

    int nEstudiant = 0;
    int nProfessor = 0;
    vector<string> menuOptions = {"1. Sortir", "2. Afegir persona", "3. Llegir fitxer", "4. Resum persones"};
    int opcio;

    do{
        menu(opcio, menuOptions);
        switch (opcio){
            case 2:
                afegirPersona(nEstudiant, nProfessor);
                break;
            case 3:
                llegirFitxer(nEstudiant, nProfessor);
                break;
            case 4:
                resumPersonesHumanes(nEstudiant, nProfessor);
                break;
            default:
                break;
        }
    } while (opcio != 1);
    cout << "\nFins a la propera\n" << endl;
}