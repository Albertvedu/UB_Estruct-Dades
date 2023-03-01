#include "Professor.h"

Professor::Professor()
{

}
Professor::Professor(string name, int any){
    nom = name;
    anyNeix = any;
}
Professor::~Professor()
{

}

//CONSULTORS
string Professor::getName() const{
    return nom;
}
int Professor::getDataNaixement() const{
    return anyNeix;
}
int Professor::getEdat() const{
   return (int)(dataActual - anyNeix);
}
void Professor::print() const{}