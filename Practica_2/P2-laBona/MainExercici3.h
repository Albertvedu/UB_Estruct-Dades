#ifndef MAINEXERCICI3_H
#define MAINEXERCICI3_H

#include "Posicio.h"
#include "Llista.h"
#include "NodeLlista.h"
#include "Clinica.h"

class MainExercici3{
public:
    MainExercici3();
    ~MainExercici3();
    void inici();
    

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