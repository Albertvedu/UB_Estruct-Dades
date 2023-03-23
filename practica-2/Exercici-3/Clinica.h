//#include <iostream>
//#include <fstream>
//#include "Client.h"
//#include "Mascota.h"
//
//using namespace std;
//
//class Clinica{
//
//public:
//    Clinica (string nom);
//    string getNom();
//    void imprimir();
//    void afegeixClient(Client);
//    void eliminaClient(string telefon);
//    void mostraClients();
//    void afegeixMascotaClient(string telefon, Mascota mascota);
//    void eliminaMascotaClient(string telefon, string nom_mascota);
//    void mostraMascotesClient(string telefon);
//    int seleccionaOpcioMenu();
//    void afegirClientsArxiu(string ruta_arxiu);
//
// private:
//    string _nom;
//    Llista<Client> _clients;
//};
//
///*########################################################
//#####           .CPP                                 ###
//########################################################*/
//
//
//Clinica::Clinica (string nom){
//    this->_nom = nom;
//  //  this->_clients = new Llista<Client>();
//}
//string Clinica::getNom(){
//
//    return this->_nom;
//}
//void Clinica::imprimir(){}
//void Clinica::afegeixClient(Client client){
//
//
//  //  this->_clients.inserirPrincipi(client);
//}
//void Clinica::eliminaClient(string telefon){}
//void Clinica::mostraClients(){}
//void Clinica::afegeixMascotaClient(string telefon, Mascota mascota){}
//void Clinica::eliminaMascotaClient(string telefon, string nom_mascota){}
//void Clinica::mostraMascotesClient(string telefon){}
//int Clinica::seleccionaOpcioMenu(){
//
//    return 0;
//}
//void Clinica::afegirClientsArxiu(string ruta_arxiu){
//    string nom, poblacio, telefon, tipus;
//    char genere;
//    int edat;
//    char x;
//
//
//    if ( ifstream arxiu{ "/home/albert/Projects_VS/UB_Estruct-Dades/practica-2/Exercici-3/clients4Gats.txt"}) {
//
//        while (  !arxiu.eof() ) {
//            arxiu >> x;
//            if ( x == 'C'){
//                arxiu >> nom;
//                arxiu >> poblacio;
//                arxiu >> telefon;
//
//                Client client = Client(nom, poblacio, telefon);
//               // afegeixClient(client);
//
//            }else{
//                arxiu >> nom;
//                arxiu >> tipus;
//                arxiu >> genere;
//                arxiu >> edat;
//                Mascota mascota = Mascota(nom, tipus, genere, edat);
//             //   afegeixMascotaClient(telefon, mascota);
//            }
//
//        }
//        arxiu.close();
//        cout << endl;
//    } else {
//        cout << "NO S'HA POGUT OBRIR EL FITXER";
//
//    }
//}
