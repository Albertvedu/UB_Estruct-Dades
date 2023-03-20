#include <iostream>

using namespace std;

class Clinica{

public:
    Clinica (string nom);
    string getNom();
    void imprimir();
    void afegeixClient(Client);
    void eliminaClient(string telefon);
    void mostraClients();
    void afegeixMascotaClient(string telefon, Mascota mascota);
    void eliminaMascotaClient(string telefon, string nom_mascota);
    void mostraMascotesClient(string telefon);
    int seleccionaOpcioMenu();
    void afegirClientsArxiu(string ruta_arxiu);

 private:
    string nom;
    Llista<Client> clients;
};

/*########################################################
#####           .CPP                                 ###
########################################################*/


Clinica::Clinica (string nom){}
string Clinica::getNom(){

    return "";
}
void Clinica::imprimir(){}
void Clinica::afegeixClient(Client){}
void Clinica::eliminaClient(string telefon){}
void Clinica::mostraClients(){}
void Clinica::afegeixMascotaClient(string telefon, Mascota mascota){}
void Clinica::eliminaMascotaClient(string telefon, string nom_mascota){}
void Clinica::mostraMascotesClient(string telefon){}
int Clinica::seleccionaOpcioMenu(){

    return 0;
}
void Clinica::afegirClientsArxiu(string ruta_arxiu){}
