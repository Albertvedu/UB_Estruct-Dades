#include <iostream>
#include "Client.h"
#include "Mascota.h"
#include <vector>
using namespace std;

Client::Client(){
    this->nom = "test";
    this->adreca = "adreca";
    this->poblacio = "poblacio";
    this->telefon = "telefon";
    this->dni = "dni";
    this->edat = 18;
}


Client::Client(const string &nom, const string &adreca, const string &poblacio, const string &telefon,
               const string &dni, int edat){
    this->nom = nom;
    this->adreca = adreca;
    this->poblacio = poblacio;
    this->telefon = telefon;
    this->dni = dni;
    this->edat = edat;
}
Client::~Client(){

}

//GETTER'S
const string &Client::getNom() const {
    return nom;
}

const string &Client::getAdreca() const {
    return adreca;
}

const string &Client::getPoblacio() const {
    return poblacio;
}

const string &Client::getTelefon() const {
    return telefon;
}

const string &Client::getDni() const {
    return dni;
}

const int Client::getEdat() const {
    return edat;
}

const vector<Mascota> Client::getMascotes() const{
    return mascotes;
}


//CONSULTORS
void Client:: print(vector<Mascota> mascotes){
    cout << "Nom:" << getNom() <<" Adreça: " << getAdreca() << " Dni: " << getDni() << endl;
    for(Mascota p: mascotes)
        cout << "Nom: " << p.getNom() << " Raça: " << p.getRaca() << endl; 
}

void Client::mostrarMascotes(vector<Client> clientList, int pos) const{
    if ( clientList[pos].mascotes.size() != 0){ 
        for (Mascota m: clientList[pos].mascotes)
            cout << "\nNom: " << m.getNom() << " Tipus: " << m.getTipus() << " Raça: " << m.getRaca()
                << " Color: " << m.getColor() << " Gènere: " << m.getGenere() << " Edat: " << m.getEdat() << endl;
                
    }else cout << "\n\e[1mLlista mascotes buïda\e[0m\n" << endl;
}

//MODIFICADORS
vector<Mascota> Client::afegeixMascota(Mascota mascota){
   
    mascotes.push_back(mascota);
    return mascotes;
}
void Client::eliminarMascota(vector<Client> &clientList){
    int posMascota = this->buscarMascota();

    if (posMascota != -1){
        mascotes.erase(mascotes.begin() + posMascota);
        cout << "\nMascota eliminada." << endl;
    }
    else{
        cout << "\n\e[1mMascote inexistent a la base de dades\e[0m" << endl; 
    }
}

//METODES PRIVATS
int Client::buscarMascota(){
    // Post: retorna posició de la mascota o -1 si no existeix
    string nom;
    cout << "\nNom mascota: "; cin >> nom;

    for(int i = 0; i< getMascotes().size(); i++) 
        if (mascotes[i].getNom() == nom)
            return i;
    
    return -1;
}

