#ifndef MASCOTA_H
#define MASCOTA_H

#include <iostream>
using namespace std;


class Mascota
{
public:
    //CONSTRUCTORS
    Mascota();
    Mascota(const string &name, const string &tipo, const char &gen, const int edad);

    //DESTRUCTOR
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
    string _nom, _tipus;
    char _genere;
    int _edat;
};



/*########################################################
  #####           .CPP                                 ###
  ########################################################*/


#endif