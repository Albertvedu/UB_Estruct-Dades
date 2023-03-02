#ifndef CLIENT_H
#define CLIENT_H
#include <iostream>
#include <vector>
#include "Mascota.h"
using namespace std;

class Client{
public:
    Client();
    
    Client(const string &nom, const string &adreca, const string &poblacio, const string &telefon, const string &dni,
           int edat);
    ~Client();

    //GETTER'S
    const string &getNom() const;

    const string &getAdreca() const;

    const string &getPoblacio() const;

    const string &getTelefon() const;

    const string &getDni() const;

    const int getEdat() const;

    const vector<Mascota> getMascotes() const;


    //CONSULTORS
    void print(vector<Mascota> mascotes) const;
    void mostrarMascotes(vector<Client> clientList, int pos) const; 
    
    //MODIFICADORS
    vector<Mascota>  afegeixMascota(Mascota mascota);
    void eliminarMascota(vector<Client> &clientList);
    
private:
    string nom;
    string adreca;
    string poblacio;
    string telefon;
    string dni;
    int edat;
    vector<Mascota> mascotes; 

    // METODES PRIVATS
    int buscarMascota();
    
};

#endif