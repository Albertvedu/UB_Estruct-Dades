#ifndef PROFESSOR_H
#define PROFESSOR_H
#include <iostream>
using namespace std;

//#pragma once

class Professor
{
public:
    Professor();
    Professor(string nom, int any);
    ~Professor();

    //CONSULTORS
    string getName() const;
    int getDataNaixement() const;
    int getEdat() const;
    void print() const;

private:
    const int dataActual = 2023;
    string nom;
    int anyNeix;
};

#endif