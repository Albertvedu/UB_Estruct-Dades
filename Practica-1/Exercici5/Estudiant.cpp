#include "Estudiant.h"
#include "chrono"
#include <ctime>

using namespace std;

Estudiant::Estudiant(){}

Estudiant::Estudiant(string name, int any, int nAssignatures){
    nom = name;
    anyNeix = any;
    n_assignatures = nAssignatures;

}

Estudiant::~Estudiant()
{
}

//CONSULTORS
int Estudiant::getEdat() const{
    return (int)(dataActual - anyNeix);
}
int Estudiant::getDataNaixement() const{
    return anyNeix;
}
string Estudiant::getName() const{
    return nom;
}
int Estudiant::getAssignatures() const{
    return n_assignatures;
}
void Estudiant::print() const{}

//MODIFICADORS


//METODES PRIVATS
int Estudiant::getDataActual(){
    
    return 0;
}