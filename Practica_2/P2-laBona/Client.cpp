#include <iostream>
#include "Client.h"

using namespace std;


Client::Client(){
    this->_nom = "test";
    this->_poblacio = "poblacio";
    this->_telefon = "telefon";
    this->_mascotesList =  new Llista<Mascota>();
}


Client::Client(const string &nom, const string &poblacio, const string &telefon){
    this->_nom = nom;
    this->_poblacio = poblacio;
    this->_telefon = telefon;
    this->_mascotesList = new Llista<Mascota>();
}
Client::~Client(){

}

//GETTER'S
const string &Client::getNom() const {
    return _nom;
}

const string &Client::getPoblacio() const {
    return _poblacio;
}

const string &Client::getTelefon() const {
    return _telefon;
}

Llista<Mascota>* Client::getMascotes() const{
    return this->_mascotesList;
}


//CONSULTORS
void Client::mostraClient() const {
    cout << "\nC ";
    cout << getNom() << " ";
    cout << getPoblacio() << " ";
    cout << getTelefon() << " ";
}


void Client::mostrarMascotes() const{
    Posicio<Mascota> itr = getMascotes()->principi();
    Mascota mascota;
    for (itr; itr != getMascotes()->final().next(); itr = ++itr) {
        mascota = itr.element();
        mascota.print();
    }
}

//MODIFICADORS
void Client::afegeixMascota(Mascota mascota){
    this->_mascotesList->inserirFinal(mascota);


}
//void Client::eliminarMascota(Llista<Client> &clientList){
//    int posMascota = this->buscarMascota();

//    if (posMascota != -1){
//        mascotes.erase(mascotes.begin() + posMascota);
//        cout << "\nMascota eliminada." << endl;
//    }
//    else{
//        cout << "\n\e[1mMascote inexistent a la base de dades\e[0m" << endl;
//    }
//}

//METODES PRIVATS
int Client::buscarMascota(){
    // Post: retorna posició de la mascota o -1 si no existeix
//    string _nom;
//    cout << "\nNom mascota: "; cin >> _nom;
//
//    for(int i = 0; i< getMascotes().size(); i++)
//        if (mascotes[i].getNom() == _nom)
//            return i;
//
    return -1;
}