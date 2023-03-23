#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
//#include "Llista.h"
#include "Mascota.h"


using namespace std;

class Client{
public:
    Client();
    Client(const string &nom, const string &poblacio, const string &telefon);
    ~Client();

    //GETTER'S
    const string &getNom() const;
    const string &getPoblacio() const;
    const string &getTelefon() const;
    //const Llista<Mascota> getMascotes() const;


    //CONSULTORS
   // void print(const Llista<Mascota> &mascotesList) const;
  //  void mostrarMascotes(const Llista<Client> &clientList, int pos) const;

    //MODIFICADORS
//    void afegeixMascota(Mascota mascota);
//    void eliminarMascota(Llista<Client> &clientList);

private:
    string nom;
    string poblacio;
    string telefon;
  //  Llista<Mascota>* mascotesList;

    // METODES PRIVATS
    int buscarMascota();

};

/*########################################################
  #####           .CPP                                 ###
  ########################################################*/


Client::Client(){
    this->nom = "test";
    this->poblacio = "poblacio";
    this->telefon = "telefon";
    // this->mascotesList =  Llista<Mascota>();
}


Client::Client(const string &nom, const string &poblacio, const string &telefon){
    this->nom = nom;
    this->poblacio = poblacio;
    this->telefon = telefon;
}
Client::~Client(){

}

//GETTER'S
const string &Client::getNom() const {
    return nom;
}

const string &Client::getPoblacio() const {
    return poblacio;
}

const string &Client::getTelefon() const {
    return telefon;
}

//const Llista<Mascota> Client::getMascotes() const{
//    return mascotesList;
//}


//CONSULTORS
//void Client:: print(const Llista<Mascota> &mascotesList) const{
//    cout << "Nom:" << getNom()  << endl;
//  //  for(Mascota p: mascotesList)
//      //  cout << "Nom: " << p.getNom() << endl;
//}

//void Client::mostrarMascotes(Llista<Client> clientList, int pos) const{
//    if ( clientList[pos].mascotes.size() != 0){
//        for (Mascota m: clientList[pos].mascotes)
//            cout << "\nNom: " << m.getNom() << " Tipus: " << m.getTipus()
//            << " Gènere: " << m.getGenere() << " Edat: " << m.getEdat() << endl;
//
//    }else cout << "\n\e[1mLlista mascotes buïda\e[0m\n" << endl;
//}

//MODIFICADORS
//void Client::afegeixMascota(Mascota mascota){
//  //  mascotesList->inserirFinal(mascota);
//
//
//}
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
//    string nom;
//    cout << "\nNom mascota: "; cin >> nom;
//
//    for(int i = 0; i< getMascotes().size(); i++)
//        if (mascotes[i].getNom() == nom)
//            return i;
//
    return -1;
}

#endif