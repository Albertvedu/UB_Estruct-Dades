
#ifndef ESTUDIANT_H
#define ESTUDIANT_H
#include <iostream>
//#pragma once
using namespace std;

class Estudiant{

public:
    Estudiant();
    Estudiant(string nom, int any, int nAssignatures);
    ~Estudiant();


    // CONSULTORS
    string getName() const;
    int getDataNaixement() const;
    int getAssignatures() const;
    int getEdat() const;
    void print() const;

    //MODIFICADORS
   



private:
    const int dataActual = 2023;
    string nom;
    int anyNeix;
    int n_assignatures;
    int edad;

    //METODES PRIVATS
    int getDataActual();
};

#endif