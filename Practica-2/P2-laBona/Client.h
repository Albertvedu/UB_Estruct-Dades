#ifndef CLIENT_H
#define CLIENT_H 

#include <iostream>
#include "Llista.h"
#include "Mascota.h"

using namespace std;

class Client{
public:
    //CONSTRUCTOR
    Client();
    Client(const string &nom, const string &poblacio, const string &telefon);

    //DESTRUCTOR
    ~Client();

    //GETTER'S
    const string &getNom() const;
    const string &getPoblacio() const;
    const string &getTelefon() const;
    Llista<Mascota>* getMascotes() const;


    //CONSULTORS
    void mostraClient() const;
    void mostrarMascotes() const;

    //MODIFICADORS
    void afegeixMascota(Mascota mascota);


private:
    string _nom;
    string _poblacio;
    string _telefon;
    Llista<Mascota>* _mascotesList;

    // METODES PRIVATS
    int buscarMascota();

};



/*########################################################
  #####           .CPP                                 ###
  ########################################################*/



#endif