#ifndef MASCOTA_H
#define MASCOTA_H
#include <iostream>
using namespace std;

//#pragma once

class Mascota
{
public:
    Mascota();
    Mascota(const string &name, const string &tipo, const string &rac, const char &gen, const string &colo, const int edad);
    ~Mascota();

    //GETTER'S SETTER'S
    
    const string &getNom() const;

    void setNom(const string &nom);

    const string &getTipus() const;

    void setTipus(const string &tipus);

    const string &getRaca() const;

    void setRaca(const string &raca);

    const string &getColor() const;

    void setColor(const string &color);

    char getGenere() const;

    void setGenere(char genere);

    int getEdat() const;

    void setEdat(int edat);

    // CONSULTORS
    void print();

private:
    string nom, tipus, raca, color;
    char genere;
    int edat;


};

#endif