#ifndef MASCOTA_H
#define MASCOTA_H
#include <iostream>
using namespace std;

//#pragma once

class Mascota
{
public:
    Mascota();
    Mascota(const string &name, const string &tipo, const char &gen, const int edad);
    ~Mascota();

    //GETTER'S SETTER'S

    const string &getNom() const;
    void setNom(const string &nom);
    const string &getTipus() const;
    void setTipus(const string &tipus);
    char getGenere() const;
    void setGenere(char genere);
    int getEdat() const;
    void setEdat(int edat);

    // CONSULTORS
    void print();

private:
    string nom, tipus;
    char genere;
    int edat;
};

Mascota::Mascota(){

}
Mascota::Mascota(const string &name, const string &tipo, const char &gen, const int edad){
    this->nom = name;
    this->tipus = tipo;
    this->genere = gen;
    this->edat = edad;
}

Mascota::~Mascota()
{

}

// GETTER'S SETTER'S
const string &Mascota::getNom() const {
    return nom;
}

void Mascota::setNom(const string &nom) {
    Mascota::nom = nom;
}

const string &Mascota::getTipus() const {
    return tipus;
}

void Mascota::setTipus(const string &tipus) {
    Mascota::tipus = tipus;
}

char Mascota::getGenere() const {
    return genere;
}

void Mascota::setGenere(char genere) {
    Mascota::genere = genere;
}

int Mascota::getEdat() const {
    return edat;
}

void Mascota::setEdat(int edat) {
    Mascota::edat = edat;
}

// CONSULTORS
void Mascota::print(){
    cout << "Tipus: " << tipus << " Nom: " << nom << endl;
}


#endif