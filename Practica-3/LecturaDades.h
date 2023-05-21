//
// Created by albert on 18/05/23.
//

#ifndef PRACTICA_3_LECTURADADES_H
#define PRACTICA_3_LECTURADADES_H

#include <iostream>
using namespace std;

class LecturaDades{
public:
    void compare(int valor, int limitA, int limitB);
    bool esNumero(char *lectura);
    int llegirStringTOint(string text, int limitA, int limitB);

};

#endif //PRACTICA_3_LECTURADADES_H


/*########################################################
  #####           .CPP                                 ###
  ########################################################*/
void LecturaDades::compare(int valor, int limitA, int limitB){
    if (valor < limitA || valor > limitB)
        throw invalid_argument( "Dades introduïdes incorrectes" );
}
bool LecturaDades::esNumero(char *lectura) {
    //Post: booleà true si és un digit
    for( ; *lectura; ++lectura )
        if( !isdigit(*lectura) )
            return false;
    return true;
}
int LecturaDades::llegirStringTOint(string text, int limitA, int limitB) {
    // Post: retorna lectura Integer o error si no és Integer

    char lectura[100];

    while(true){
        try{
            cout << text;
            cin >> lectura;
            if(!esNumero(lectura) )
                throw invalid_argument( "Dades introduïdes incorrectes");
            compare(atoi(lectura), limitA, limitB );
            break;
        }catch(const invalid_argument &e){
            cerr << e.what() << '\n';
        }
    }
    return atoi(lectura);
}