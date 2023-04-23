/*1. Has implementat la Llista amb templates? Sigui quina sigui la teva resposta, justifica el motiu pel
qual has pres aquesta decisió.

    . Per aprendre a fer-ho servir, ja que mai ho havia utilitzat i veig que el codi d'aquesta manera
    adapta a qualsevol mena de dada.

2. Has implementat el constructor amb l’initializer_list? Sigui quina sigui la teva resposta, justifica
el motiu pel qual has pres aquesta decisió.

    . Si, l'implementat. El trobo molt útil per crear ràpidament una llista de nodes, 
    partint d'una llista bàsica.

3. Tenint en compte la teva implementació del TAD Llista, indica per a cadascuna de les operacions
del TAD Llista quin és el seu cost computacional teòric. Justifica la resposta.

    - Llista():  cost O(1)
    - Llista(initializer_list<Element> elements): cost O(n)elements
    - Llista(const Llista<Element>& origen): cost O(n)
    - virtual ~Llista(): cost O(n)
    - int tamany(): cost O(1)
    - bool esBuida(): cost 0(1)
    - principi(): cost 0(1)
    - final(): cost 0(1) 
    - rprincipi(): cost 0(1)
    - rfinal(): : cost 0(1)
    - inserirDespres(): cost 0(1)
    - inserirAbans(): cost 0(1)
    - inserirPrincipi(): cost 0(1)
    - inserirFinal(): cost 0(1)
    - elimina(): cost 0(1)
    
4. Creieu que la classe NodeLlista hauria estat millor implementar-la amb encadenaments simples?
Justifica la teva resposta.

    - No, ja que amb encadenaments dobles permet moures per la llista en les dues direccions. Tan pots
    anar endavant com cap endarrera.

*/

#include <iostream>
#include <cstdlib>
#include <csignal>
#include <stdexcept>
#include "Posicio.h"
#include "Llista.h"
#include "NodeLlista.h"



using namespace std;



void compare(int valor, int limitA, int limitB){
    if (valor < limitA || valor > limitB)
        throw invalid_argument( "Dades introduïdes incorrectes" );
}
bool esNumero(char *lectura) {
    for( ; *lectura; ++lectura )
        if( !isdigit(*lectura) )
            return false;
    return true;
}

int llegirStringTOint(string text, int limitA, int limitB) {
    // Post: retorna lectura Integer o error si no és Integer

    char lectura[100];
    int numero;

    while(true){
        try{
            cout << text;
            cin >> lectura;
            if(!esNumero(lectura) )
                throw invalid_argument( "Dades introduïdes incorrectes" );
            compare(atoi(lectura), limitA, limitB );
            break;
        }catch(const std::exception& e){
            cerr << e.what() << '\n';
            sleep(1);
        }
    }

    return atoi(lectura);
}
template <class Element>
Posicio<Element> inserirEnUnaPosicio(int pos, const Llista<Element> *pLlista) {
    int contador = 0;
    bool trobat = false;
    Posicio<Element> itr = pLlista->principi();

    while( itr != pLlista->final() && !trobat){
        if ( contador == pos )
            trobat = true;
        else{
            itr = ++itr;
            contador ++;
        }
    }
    if (!trobat)
        throw invalid_argument( "Punter és NULL" );
    return itr;
}

void llegirParaula(string &paraula){
    cout << "\nIntrodueix una paraula: ";
    cin >> paraula;
}
bool inserirDades( string text){
    string opcio, op;
    while ((opcio.length() != 1) || ((op != "s") && (op != "n"))){
        try {
            cout << text;
            cin >> opcio;
            op = tolower(opcio[0]);
            if ((opcio.length() != 1) || ((op != "s") && (op != "n")))
                throw invalid_argument( "Dades introduïdes incorrectes" );
        }catch(const std::exception& e){
            cerr << e.what() << '\n';
            sleep(1);
        }
    }

    if (op == "s") return true;
    else
        return false;
}
int llegirPos(int tamany){
    int pos;
    try{
        cout << "A quina posició vols inserir?: ";
        cin >> pos;
      //  if (pos >= tamany)
         //   throw invalid_argument( "Els nodes van numerats començant per ZERO \nNombre indicat queda fora de rang" );
    }catch(const std::exception& e){
        cerr << e.what() << '\n';
        sleep(1);
    }

    return pos;
}
void print(Llista<string> *l1) {
    try {
        cout << ".............." << endl;
        for (Posicio<string> itr = l1->principi(); itr != l1->final().next(); itr = ++itr)
            cout << itr.element() << endl;
        cout << ".............." << endl;
    }catch(const std::exception& e){
        cerr << e.what() << '\n';
        sleep(1);
    }
}
void printReverse(Llista<string> *l1 ) {
    try{
        cout << ".............." << endl;
        for (Posicio<string> itr = l1->final(); itr != l1->principi().anterior(); itr = --itr)
            cout << itr.element() << endl;
        cout << ".............." << endl;
    }catch(const std::exception& e){
        cerr << e.what() << '\n';
        sleep(1);
    }
}
void primerNode(Llista<string> *l1, int &nParaules){
    string paraula;
    llegirParaula(paraula);
    l1->inserirPrincipi( paraula);
    cout << "\e[1mLa llista era buida. Paraula inserida en l'ùnic espai disponible.\e[0m" << endl;
    nParaules --;
}
int main(){
    Llista<string>* l1 = new Llista<string>();

    string paraula, opcio;
    int pos;

    try{
        int nParaules =llegirStringTOint("Introdueix quantes paraules vols inserir: ", 0, INT16_MAX);
        if (nParaules > 0) primerNode(l1, nParaules);

        while( nParaules > 0){
            try{
                llegirParaula(paraula);
                if(inserirDades("Inserir al principi? (s/n): "))
                    l1->inserirPrincipi( paraula);
                else{
                    if(inserirDades("Inserir al final? (s/n): "))
                        l1->inserirFinal(paraula);
                    else{
                        pos = llegirPos(l1->tamany());

                        if (pos >= l1->tamany())
                            throw invalid_argument( "Els nodes van numerats començant per ZERO \nNombre indicat queda fora de rang" );
                        if (inserirDades("Inserir abans de la posició? (s/n): ")) {
                            Posicio<string> p = inserirEnUnaPosicio(pos, l1);
                            l1->inserirAbans(p, paraula);
                        }
                        else{
                            Posicio<string> p1 = inserirEnUnaPosicio(pos, l1);
                            l1->inserirDespres(p1, paraula);
                        }
                    }
                }
                nParaules --;

                if (nParaules == 0){
                    cout << "Iteració (amb position) endavant: " << endl;
                    print(l1);
                    cout << "Iteració (amb position) endarrera: " << endl;
                    printReverse(l1);
                }
            }catch(const std::exception& e){
                cerr << e.what() << '\n';
                sleep(1);
            }
        }
        cout << "kllkllk" << endl;
         Llista<string>* l2 = new Llista<string>(*l1);
         //l2 = l1;
          cout << "kllkllk" << endl;
    }catch(const std::exception& e){
        cerr << e.what() << '\n';
        sleep(1);
    }
    cout << endl << endl;
    return 0;
}


