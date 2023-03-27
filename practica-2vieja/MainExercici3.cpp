#include <iostream>
#include "MainExercici3.h"
#include <cstdlib>
#include <csignal>
#include <stdexcept>
#include "Clinica.h"

using namespace std;


MainExercici3::MainExercici3(){
    int opcio;
    try {
        Clinica *clinica = new Clinica("Clínica Uno");
        Llista<string> *opMenu = new Llista<string>(
                {"1. Afegir Client ", "2. Eliminar Client", "3. Afegir Mascota a un client",
                 "4. Eliminar Mascota d'un client", "5. Imprimir clients clinica",
                 "6. Imprimir les mascotes d'un client",
                 "0. Sortir"});
        clinica->afegirClientsArxiu("/home/albert/Projects_VS/UB_Estruct-Dades/practica-2/Exercici-3/clients4Gats.txt");
        clinica->imprimir();
        do {  //Considero deixar el frond-end al Main i el back-end a les classes particulars.
            try {
                menu(opcio, opMenu);
                switch (opcio) {
                    case 1:
                        afegirClient(clinica);
                        break;
                    case 2:
                        eliminarClient(clinica);
                        break;
                    case 3:
                        afegirMascotaClient(clinica);
                        break;
                    case 4:
                        eliminarMascota(clinica);
                        break;
                    case 5:
                        clinica->mostraClients();
                        break;
                    case 6:
                        imprimirMascotesClient(clinica);
                        break;
                    default:
                        break;
                }
            }catch(const std::exception& e){
                cerr << e.what() << '\n';
                sleep(1);  // He posat sleep(), perquè sortia el següent missatge abans que el missatge d'error
            }
        } while (opcio != 0);
    }catch(const std::exception& e){
        cerr << e.what() << '\n';
        sleep(1);  // He posat sleep(), perquè sortia el següent missatge abans que el missatge de error
    }
    cout << "\nBye bye" << endl;
}
void MainExercici3::compare(int valor, int limitA, int limitB){
    if (valor < limitA || valor > limitB)
        throw invalid_argument( "Dades introduïdes incorrectes" );
}
bool MainExercici3::esNumero(char *lectura) {
    for( ; *lectura; ++lectura )
        if( !isdigit(*lectura) )
            return false;
    return true;
}

int MainExercici3::llegirStringTOint(string text, int limitA, int limitB) {
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
void MainExercici3::print(Llista<string>* l1) {
    try {
        for (Posicio<string> itr = l1->principi(); itr != l1->final().next(); itr = ++itr)
            cout << itr.element() << endl;

    }catch(const std::exception& e){
        cerr << e.what() << '\n';
        sleep(1);
    }
}
void MainExercici3::menu(int &opcio, Llista<string>* opMenu){
    cout << "\n\n\e[1m############   MENU   ############\e[0m" << endl;
    cout << "\nHola " <<  ", que vols fer? " << endl;
    print(opMenu);
    opcio = llegirStringTOint("\nOpció: ", 0,opMenu->tamany()-1);
}

char MainExercici3::inserirChar( string text){
    string opcio, op;
    do{
        try {
            cout << text;
            cin >> opcio;
            op = tolower(opcio[0]);
            if ((opcio.length() != 1) || ((op != "f") && (op != "m")))
                throw invalid_argument( "Dades introduïdes incorrectes" );
        }catch(const std::exception& e){
            cerr << e.what() << '\n';
            sleep(1);
        }
    }while ((opcio.length() != 1) || ((op != "f") && (op != "m")));

    return opcio[0];
}
Mascota MainExercici3::afegirMascota(){
    string nom, tipus;
    char genere;
    int edat;

    cout << "\n\e[1mInsireix una mascota\e[0m" << endl;
    cout << "Nom: "; cin >> nom;
    cout << "Tipus: "; cin >> tipus;
    genere = inserirChar( "gènere: ");
    edat = llegirStringTOint("Edat: ",0,100);
    Mascota mascota = Mascota(nom, tipus, genere,edat);
    return mascota;
}
void MainExercici3::afegirClient(Clinica *clinica) {
    string nom, poblacio, telefon;
    char x;
    try {
        cout << "\n\e[1mInsireix un nou client\e[0m" << endl;
        cout << "Nom: ";
        cin >> nom;
        cout << "poblacio: ";
        cin >> poblacio;
        cout << "telefon: ";
        cin >> telefon;

        Client client = Client(nom, poblacio, telefon);
        clinica->afegeixClient(client);
        Mascota mascota = afegirMascota();
        clinica->afegeixMascotaClient(telefon, mascota);
    }catch(const std::exception& e){
        cerr << e.what() << '\n';
        sleep(1);
    }
}
void MainExercici3::eliminarClient(Clinica *clinica){
    string telefon;
    cout << "\n\e[1mEliminar client\e[0m" << endl;
    cout << "Introdueix el teléfon del client a eliminar: ";
    cin >> telefon;
    clinica->eliminaClient(telefon);
}
void MainExercici3::afegirMascotaClient(Clinica *clinica){
    string telefon;
    cout << "\n\e[1mAfegir mascota\e[0m" << endl;
    cout << "Introdueix el teléfon del client: ";
    cin >> telefon;

    Mascota mascota = afegirMascota();
    clinica->afegeixMascotaClient(telefon, mascota);
}
void MainExercici3::eliminarMascota(Clinica *clinica){
    string telefon, nom;
    cout << "\n\e[1mEliminar mascota\e[0m" << endl;
    cout << "Introdueix el teléfon del client: ";
    cin >> telefon;
    cout << "Introdueix el _nom de la mascota: ";
    cin >> nom;
    clinica->eliminaMascotaClient(telefon, nom);
}
void MainExercici3::imprimirMascotesClient(Clinica *clinica){
    string telefon;
    cout << "\n\e[1mMostrar mascotes d'un client\e[0m" << endl;
    cout << "Introdueix el teléfon del client: ";
    cin >> telefon;
    clinica->mostraMascotesClient(telefon);
}
