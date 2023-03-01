//
// Created by albert on 1/03/23.
//
#include <iostream>
#include "Client.h"

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
        cout << "\n"
             << *it << endl;
    opcio = llegirStringTOint("\nOpció: ", 0,opMenu.size()-1);
}
bool existDNI(string dni, const vector<Client> &clientList){

    for ( Client c: clientList)
        if (c.getDni() == dni)
            return true;
    return false;
}
Mascota insertarMascota(){
    string nom, tipus, raca, color;
    char genere;
    int edat;

    cout << "\n\e[1mMascota: \e[0m" << endl;
    cout << "\nNom mascota: "; cin >> nom;
    cout << "\nTipus: "; cin >> tipus;
    cout << "\nRaça: "; cin >> raca;
    cout << "\nColor: "; cin >> color;
    cout << "\nGènere: "; cin >> genere;
    edat = llegirStringTOint("\nEdat: ", 0,150);

    Mascota mascota(nom, tipus, raca, genere, color, edat);
    return mascota;
}
void afegirClient(vector<Client> &clientList){
    string nom, adreca, poblacio, telefon, dni;
    int edat;

    cout << "\n\e[1mIntroduir client\e[0m\n";
    cout << "Nom: " ; cin >> nom;
    cout << "Adreça: "; cin >> adreca;
    cout << "Població: "; cin >> poblacio;
    cout << "Telèfon: "; cin >> telefon;
    cout << "DNI: "; cin >> dni;
    
    if ( !existDNI(dni, clientList)) {
        edat = llegirStringTOint("Edat (0 .. 150): ", 0, 150);

        Client client(nom, adreca, poblacio, telefon, dni, edat);
        clientList.push_back(client);
        cout << "\nVols afegir una mascota?: ";
        string x; cin >> x;
        x = tolower(x[0]);
        
        if ( x == "s")  // Aqui he intentat fer un cin.get()== 's' però donava error
            clientList[clientList.size()-1].afegeixMascota(insertarMascota());
    }
    else {
        cout << "\n\e[1mJa existeix un client amb aquest DNI" << endl;
        cout << "\nInserció client anul·lada\e[0m\n" << endl;
    }
}

bool eliminarClient( vector<Client> &clientList){
    string dni;
    int contador = 0;
    cout << "\n\t\t################################" << endl;
    cout << "\t\t###      Eliminar Client     ###" << endl;
    cout << "\t\t################################\n" << endl;
    cout << "Introdueix el DNI del client: ";
    cin >> dni;

    for(Client c: clientList){
        if (c.getDni() == dni){
            clientList.erase(clientList.begin()+ contador);
            cout << "\n\e[1mCLIENT ELIMINAT\e[0m" << endl;
            return true;
        }
        contador ++;
    }
    cout << "\nNo hi ha cap coincidència amb aquest DNI\n" << endl;
    return false;

}

int buscarClient(const vector<Client> &clientList, string dni){
    for(int i = 0; i< clientList.size(); i++){
        if (clientList[i].getDni() == dni)
            return i;
    }
    return -1;
}
int identificarClient(const vector<Client> &clientList, string text1, string text2){
    string dni;
    cout << "\n\e[1m" << text1 << "\e[0m\n";
    cout << "\n" << text2; cin >> dni;
    int pos = buscarClient(clientList, dni);
    return pos;
}
void afegirMascota(vector<Client> &clientList){

    int pos = identificarClient(clientList, "Afegir Mascota", "Introdueix DNI del client: ");

    if (pos != -1)
        clientList[pos].afegeixMascota(insertarMascota());
    else cout << "\n\e[1mClient inexistent a la base de dades\e[0m" << endl;
}

void eliminarMascota(vector<Client> &clientList){
    int pos = identificarClient(clientList, "ELIMINAR MASCOTA", "Introdueix DNI del client: ");

    if (pos != -1)
        clientList[pos].eliminarMascota(clientList);
    else cout << "\n\e[1mClient inexistent a la base de dades\e[0m" << endl;

}
void imprimirClients(const vector<Client> &clientList){
    cout << "\n\t\t################################" << endl;
    cout << "\t\t###      LLista Clients      ###" << endl;
    cout << "\t\t################################\n" << endl;

    if (clientList.size() == 0)
        cout << "\nLlista buïda.\n" << endl;
    else
        for(Client c: clientList)
            cout << "Nom: " << c.getNom() << " Adreça: " << c.getAdreca() << " Poblacio: " << c.getPoblacio()
                 << " Telefon: " << c.getTelefon() << " Dni: " << c.getDni() << " Edat: " << c.getEdat() << endl;
    cout << endl;

}

void imprimirMascotesClient(const vector<Client> &clientList){
    string dni;
    Client client;
    cout << "\n\t\t################################" << endl;
    cout << "\t\t###  LLista Mascotes Client  ###" << endl;
    cout << "\t\t################################" << endl;

    cout << "\n\e[1mLlistar mascotes: \e[0m" << endl;
    cout << "\nDNI del client: "; cin >> dni;
    int pos = buscarClient(clientList, dni);
    if (pos != -1)
        client.mostrarMascotes(clientList, pos);
    else
        cout << "\n\e[1mClient inexistent\e[0m\n" << endl;
}
void dadesInicials(vector<Client> &clientList){
    Mascota mascota("Gos",  "Pelut",  "Podrit",  'M',  "Negre", 12);
    Mascota mascota2("Brut",  "Pelut",  "Podrit",  'M',  "Blanc", 3);
    string nom = "Client-";

    for (int i= 1; i < 9; i++){
        Client client( nom + to_string(i), "blablabla", "Barcelona", "999666333", "99966644" + to_string(i), 21 + i);
        if (i > 1 && i < 8)
            if (i == 7)
                client.afegeixMascota(mascota2);    // Afegeix 2 mascotes al client 7
            client.afegeixMascota(mascota);    // Afegeix mascotes a els Clients 2 .. 7
    
        clientList.push_back(client);
    }
}
int main(){
    vector <string> opMenu = {"1. Afegir Client ","2. Eliminar Client","3. Afegir Mascota a un client",
                              "4. Eliminar Mascota d'un client","5. Imprimir clients clinica","6. Imprimir les mascotes d'un client",
                              "0. Sortir"};
    vector <Client> clientList;
    int opcio;
    dadesInicials(clientList);
    do{
        menu(opcio, opMenu);
        switch (opcio){
            case 1:
                afegirClient(clientList);
                break;
            case 2:
                eliminarClient(clientList);
                break;
            case 3:
                afegirMascota(clientList);
                break;
            case 4:
                eliminarMascota(clientList);
                break;
            case 5:
                imprimirClients(clientList);
                break;
            case 6:
                imprimirMascotesClient(clientList);
                break;
            default:
                break;
        }
    } while (opcio != 0);

}