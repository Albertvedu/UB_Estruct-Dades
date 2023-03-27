#ifndef PRACTICA_2_CLINICA_H
#define PRACTICA_2_CLINICA_H

#include <iostream>
#include <fstream>
#include "Client.h"
#include "Mascota.h"

using namespace std;

class Clinica{

public:
    //CONSTRUCTOR
    Clinica (string nom);

    //GETTER'S
    string getNom()const;

    //CONSULTORS
    void imprimir()const;
    void mostraClients()const;
    void mostraMascotesClient(string telefon)const;
    int seleccionaOpcioMenu(int i)const;

    //MODIFICADORS
    void afegeixClient(Client);
    void eliminaClient(string telefon);
    void afegeixMascotaClient(string telefon, Mascota mascota);
    void eliminaMascotaClient(string telefon, string nom_mascota);
    void afegirClientsArxiu(string ruta_arxiu);

private:
    string _nom;
    Llista<Client>* _clients;

    //MÈTODES PRIVATS
    bool existeix(const Client &client) const;
    Client buscarClient(string telefon) const;

};



/*########################################################
#####           .CPP                                 ###
########################################################*/


Clinica::Clinica (string nom){
    this->_nom = nom;
    this->_clients = new Llista<Client>();
}
string Clinica::getNom()const{

    return this->_nom;
}
void Clinica::imprimir()const{
    cout << "\e[1m###################################################\e[0m" << endl;
    cout << "\e[1m############       " << this->_nom << "          ###########\e[0m" << endl;
    cout << "\e[1m###################################################\e[0m" << endl;
}

void Clinica::eliminaClient(string telefon){
    if( !_clients->esBuida()) {
        Posicio<Client> itr = this->_clients->principi();
        bool trobat = false;

        while (itr != this->_clients->final().next() && !trobat) {
            if (itr.next() == nullptr)
                throw invalid_argument("Punter nullptr");
            if (itr.element().getTelefon() == telefon)
                trobat = true;
            else itr = ++itr;
        }
        if (trobat)
            this->_clients->elimina(itr);
        else
            throw invalid_argument("CLIENT NO EXISTEIX");
    }else
        throw invalid_argument("LLISTA CLIENTS ÉS BUIDA");
}

void Clinica::afegeixClient(Client client){
    if ( !existeix(client))
        this->_clients->inserirFinal(client);
    else
        throw invalid_argument("YA EXISTEIX AQUEST CLIENT");
}
void Clinica::afegeixMascotaClient(string telefon, Mascota mascota){
    Client client = buscarClient(telefon);
    if (client.getNom() != "test")
        client.afegeixMascota(mascota);
    else
        throw invalid_argument("NO EXISTEIX AQUEST CLIENT");
}
void Clinica::eliminaMascotaClient(string telefon, string nom_mascota){
    Client client = buscarClient(telefon);
    if (client.getNom() != "test"){
        Llista<Mascota> *llista = client.getMascotes();
        if( !llista->esBuida()){
            Posicio<Mascota> itr = llista->principi();
            bool trobat = false;

            while(itr != client.getMascotes()->final().next() && !trobat) {
                if (itr.element().getNom() == nom_mascota)
                    trobat = true;
                else itr = ++itr;
            }
            if (trobat)
                llista->elimina(itr);
            else
                throw invalid_argument("NO EXISTEIX AQUESTA MASCOTA");
        }else
            throw invalid_argument("LLISTA MASCOTES ÉS BUIDA");

    }else
        throw invalid_argument("NO EXISTEIX AQUEST CLIENT");

}
void Clinica::mostraClients()const{
    if( !_clients->esBuida()) {
        Posicio<Client> itr = this->_clients->principi();
        Client client;

        for (itr; itr != _clients->final().next(); itr = ++itr) {
            client = itr.element();
            if (itr.next() == nullptr)
                throw invalid_argument("Punter nullptr");
            client.mostraClient();
            client.mostrarMascotes();
        }
    }else
        throw invalid_argument("LLISTA CLIENTS ÉS BUIDA");
}
void Clinica::mostraMascotesClient(string telefon)const{
    Client client = buscarClient(telefon);

    if (client.getNom() != "test") {
        if( !client.getMascotes()->esBuida())
            client.mostrarMascotes();
        else
            throw invalid_argument("LLISTA DE MASCOTES ÉS BUIDA");
    }else
        throw invalid_argument("NO EXISTEIX AQUEST CLIENT");
    cout << endl;
}
int Clinica::seleccionaOpcioMenu(int i)const {
/*
 * No veig pràctic aquest mètode aquí, ja que hi varios mètodes que precisant interactuar per pantalla
 * i no és permés afegir mètodes a la classe Clinica.
 *
 * Considero deixar el frond-end al Main i el back-end a les classes particulars.
 *
 */

/*    switch (opcio){
        case 1:
            afegirClient(clinica);
            clinica->mostraClients();
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
            mostraClients();
            break;
        case 6:
            imprimirMascotesClient(clinica);
            break;
        default:
            break;
    }*/
    return i;
}
void Clinica::afegirClientsArxiu(string ruta_arxiu){
    string nom, poblacio, telefon, tipus;
    char genere;
    int edat;
    char x;
    //todo cambiar adreça
    if ( ifstream arxiu{ ruta_arxiu}) {

        while (  !arxiu.eof() ) {
            arxiu >> x;
            if ( x == 'C'){
                arxiu >> nom;
                arxiu >> poblacio;
                arxiu >> telefon;
                Client client = Client(nom, poblacio, telefon);
                afegeixClient(client);
            }else{
                arxiu >> nom;
                arxiu >> tipus;
                arxiu >> genere;
                arxiu >> edat;
                Mascota mascota = Mascota(nom, tipus, genere, edat);
                afegeixMascotaClient(telefon, mascota);
            }
        }
        arxiu.close();
        cout << endl;
    } else {
        throw invalid_argument ("\nNO S'HA POGUT OBRIR EL FITXER");
    }
}

//MÈTODES PRIVATS
bool Clinica::existeix(const Client &client) const{
    //    Pre:--;    Post: ens diu si eL client existeix a la llista
    bool trobat = false;
    Posicio<Client> itr = this->_clients->principi();

    while( itr != this->_clients->final().next() && !trobat){
        if ( itr.element().getTelefon() == client.getTelefon() )
            trobat = true;
        else
            itr = ++itr;
    }
    return trobat;
}

Client Clinica::buscarClient(string telefon)const{
    Posicio<Client> itr = this->_clients->principi();

    while(itr != this->_clients->final().next()) {
        if (itr.element().getTelefon() == telefon)
            return itr.element();
        else itr = ++itr;
    }
    return Client(); // Al no ser Punter, no he pogut tornar "nullptr"

}
#endif //PRACTICA_2_CLINICA_H