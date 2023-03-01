#include "Mascota.h"

Mascota::Mascota(){

}
Mascota::Mascota(const string &name, const string &tipo, const string &rac, const char &gen, const string &colo, const int edad){
    this->nom = name;
    this->tipus = tipo;
    this->raca = rac;
    this->genere = gen;
    this->color = colo;
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

const string &Mascota::getRaca() const {
    return raca;
}

void Mascota::setRaca(const string &raca) {
    Mascota::raca = raca;
}

const string &Mascota::getColor() const {
    return color;
}

void Mascota::setColor(const string &color) {
    Mascota::color = color;
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
    cout << "Tipus: " << tipus << " Nom: " << nom << " Raça: " << raca << endl;
}