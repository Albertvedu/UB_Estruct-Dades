//
// Created by albert on 22/03/23.
//

#ifndef EXERCICI_3_POCO_H
#define EXERCICI_3_POCO_H

#include <iostream>
using namespace std;
//#include "Llista.h"


class poco {
public:
    poco();
    void getSor();

private:
    string _sor;
    Llista<Mascota> llista;
};


#endif //EXERCICI_3_POCO_H
