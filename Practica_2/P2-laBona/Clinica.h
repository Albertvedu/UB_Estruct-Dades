#ifndef CLINICA_H
#define CLINICA_H

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




#endif