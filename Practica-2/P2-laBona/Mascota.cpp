#include <iostream>
#include "Mascota.h"

using namespace std;

Mascota::Mascota(){
    this->_nom = "none";
    this->_tipus = "none";
    this->_genere = 'n';
    this->_edat = 0;
}
Mascota::Mascota(const string &name, const string &tipo, const char &gen, const int edad){
    this->_nom = name;
    this->_tipus = tipo;
    this->_genere = gen;
    this->_edat = edad;
}

Mascota::~Mascota()
{

}

// GETTER'S SETTER'S
const string &Mascota::getNom() const {
    return _nom;
}

void Mascota::setNom(const string &nom) {
    Mascota::_nom = nom;
}

const string &Mascota::getTipus() const {
    return _tipus;
}

void Mascota::setTipus(const string &tipus) {
    Mascota::_tipus = tipus;
}

char Mascota::getGenere() const {
    return _genere;
}

void Mascota::setGenere(char genere) {
    Mascota::_genere = genere;
}

int Mascota::getEdat() const {
    return _edat;
}

void Mascota::setEdat(int edat) {
    Mascota::_edat = edat;
}

// CONSULTORS
void Mascota::print(){
    cout << "M "
         << getNom() << " "
         << getTipus() << " "
         << getGenere() << " "
         << getEdat() << " ";
}