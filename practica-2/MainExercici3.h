#ifndef PRACTICA_2_MAINEXERCICI3_H
#define PRACTICA_2_MAINEXERCICI3_H

#include <iostream>
#include "Clinica.h"
#include "Llista.h"
#include "NodeLlista.h"
#include "Posicio.h"
#include "Clinica.h"

using namespace std;

class MainExercici3{
    public:
        MainExercici3();
    private:
        void compare(int valor, int limitA, int limitB);
        bool esNumero(char *lectura);

        int llegirStringTOint(string text, int limitA, int limitB);
        void print(Llista<string>* l1);
        void menu(int &opcio, Llista<string>* opMenu);
        char inserirChar( string text);
        Mascota afegirMascota();
        void afegirClient(Clinica *clinica);
        void eliminarClient(Clinica *clinica);
        void afegirMascotaClient(Clinica *clinica);
        void eliminarMascota(Clinica *clinica);
        void imprimirMascotesClient(Clinica *clinica);
};
#endif