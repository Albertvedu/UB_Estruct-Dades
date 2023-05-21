//
// Created by albert on 7/05/23.
//

#ifndef PRACTICA_3_MINHEAP_H
#define PRACTICA_3_MINHEAP_H

#include <iostream>
#include <vector>
#include "NodeHeap.h"

using namespace std;
template<class Clau, class Valor>
class MinHeap {


    /*  COMENTARIS:
     *
     * La implementació amb Heaps, és més senzilla, al no haver d'anar enllaçant nodes. Ja que és treballar amb un array.
     *
     * L'array emmagatzema nodes, però a l'inserir o moure nodes, no es treballa amb la classe NodeBinari(), ja que,
     * al moure nodes o inserir-los es fa amb el punter de l'array. LLavors els mètodes getPare(), getRight() i getLeft()
     * són mètodes d'aquesta mateixa classe MinHeap(), perquè són només un valor int de l'array d'aquesta pròpia classe.
     * No retornant cap node, per tant, no són de la classe NodeBinari().
     *
     *
     * La cerca d'un element, no és més ràpida, (cost O(n)), per la manera d'estar ordenat un Heap, (node Pare és de Key inferior,
     * però entre germans no hi ha ordre).
     * Això fa que, a l'hora de cercar, s'hagi de verificar costat esquerre i costat dret. I si 'k' és superior a tot
     * haurà de recorre tot l'array. Amb cost de (n).
     *
     * Per contra, en la cerca Binaria, només verifiquem un costat de la branca.
     *
     */
public:
    // CONSTRUCTOR
    MinHeap();

    //CONSTRUCTOR CÒPIA
    MinHeap<Clau,Valor> (const MinHeap<Clau,Valor>& copia);              // Cost O(n)


    int tamany();                                                       // Cost O(1)
    // retorna el nombre d'elements que hi ha al heap

    bool esBuit() const;                                                // Cost O(1)
    // retorna cert si és buit, fals en cas contrari

    void inserir(const Clau& clau, const Valor& valor);       // Cost (O) 1 log(n) fer unHeap
    // Insereix i reordena l'arbre si és necessari

    Clau minim();                                            // Cost O(1)
    // retorna la clau mínima

    Valor valorMinim();                                      // Cost O(1)
    // retorna el valor de la clau mínima

    void eliminaMinim();                                         //  cost O( log n)
    // elimina el node amb valor minim i reoderna l'arbre

    void imprimir();                                            // Cost O(n)
    // Imprimeix per pantalla tot el Heap, una línia per a cada _nivell de l'arbre

    Valor cerca(const Clau& clau);                              //  cost O( n )
    //Post: busca i retorna un heap amb la clau que arriba per paràmetres

    int altura();                                                  // Cost O(n log n)
    // retorna l'alçada del heap

private:
    vector< NodeHeap<Clau, Valor>> _data;
    int _mida;
    int _height;

// MÈTODES PRIVATS
    void upHeap(NodeHeap<Clau, Valor> node, int i);                         // Cost O(log n)
    void calcularAltura(int &altura, int i);                                // Cost O(n)
    int verificarAltura( int i);                                            // Cost O( log n)
    void reOrdenarArbre(int i);                                             //cost O(log n)
    int getPare(int i) const;                                               // Cost O(1)
    int getLeft(int i) const;                                               // Cost O(1)
    int getRight(int i) const;                                              // Cost O(1)
    void searchReacursiu(int i, const int k, int &trobat);                  // Cost O(n)
    bool isExternal(int i);                                                 // Cost O(1)



};

#endif //PRACTICA_3_MINHEAP_H


/*########################################################
#####           .CPP                                 ###
########################################################*/

template<class Clau, class Valor>
MinHeap<Clau, Valor>::MinHeap() {
    //Post: Inicialitza atributs
    this->_height = 0;
    this->_mida = 0;
}

template<class Clau, class Valor>
MinHeap<Clau, Valor>::MinHeap(const MinHeap<Clau,Valor>& copia){
    //Post: còpia del Heap que arribar per paràmetres
    for (int i = 0; i < copia._mida; ++i) {
        this->_data[i] = copia._data[i];
        this->_mida ++;
    }
}
template<class Clau, class Valor>
bool MinHeap<Clau, Valor>::esBuit() const{
    //Post: retorna booleà
    return this->_mida == 0;
}
template<class Clau, class Valor>
int MinHeap<Clau, Valor>::tamany(){
    return this->_mida;
}
template<class Clau, class Valor>
Clau MinHeap<Clau, Valor>::minim(){
    return this->_data[0].getKey();
}
template<class Clau, class Valor>
Valor MinHeap<Clau, Valor>::valorMinim(){
    return this->_data[0].getValue();
}
template <class Clau, class Valor >
int MinHeap<Clau, Valor>::getLeft(int i) const {
    return ( 2 * i) + 1;
}
template <class Clau, class Valor >
int MinHeap<Clau, Valor>::getRight(int i) const {
    return ( 2 * i) + 2;
}
template <class Clau, class Valor >
int MinHeap<Clau, Valor>::getPare(int i) const{
    return (i-1) /2;
}
template <class Clau, class Valor >
bool MinHeap<Clau, Valor>::isExternal(int i){
    //Post: retorna booleà
    return (this->getRight(i) > tamany() -1) && (this->getLeft(i) > tamany() -1);
}
template<class Clau, class Valor>
void MinHeap<Clau, Valor>::inserir(const Clau& clau, const Valor& valor){
    //Post: insereix un node nou i reordena l'arbre si és necessari
    auto node = NodeHeap<Clau, Valor>(clau, valor);             // Crea NodeHeap amb clau i valor
    this->_data.push_back(node);                               // afegeix el node al vector

    if (this->esBuit()) {
        this->_mida ++;
        this->_data[tamany()-1].setNivell(1);      // dona valor a la variable nivell
    }
    else {
        this->_mida ++;
        int nivellPare = this->_data[getPare(tamany() - 1)].getNivell();
        this->_data[tamany()-1].setNivell(nivellPare + 1);         // dona valor a la variable nivell
        node.setNivell(nivellPare + 1);         // dona valor a la variable nivell ... que va al upHeap()

        upHeap(node, tamany() -1);              // Actualitzar l'arbre, verificant ordre correcta
    }

    cout << "Insertat a l’arbre element " << node.getKey() <<  endl;
}
template<class Clau, class Valor>
void MinHeap<Clau, Valor>::upHeap(NodeHeap<Clau, Valor> node, int i){
    //Post: reordena l'arbre si és necessari
    int pare = getPare(i);         // posició Pare última inserció
    int pos = i;                 // posició última inserció

    while (this->_data[pare].getKey() > this->_data[pos].getKey()){ // Bucle que ascendeix de Pare a Pare, fins key menor
        this->_data[pos] = this->_data[pare];
        this->_data[pos].setNivell(this->_data[pos].getNivell() +1);     // dona valor a la variable nivell +1
        this->_data[pare] = node;                             // utilitzo el node com auxiliar
        this->_data[pare].setNivell( this->_data[pos].getNivell() -1 );   // dona valor a la variable nivell -1

        pos = pare;
        pare = getPare(pare);      // ascendeix per l'arbre
    }
}
template<class Clau, class Valor>
int MinHeap<Clau, Valor>::verificarAltura(int i){
    //Post: retorna alçada, començant a comptar des de una fulla fins l'arrel.
    int altura = 1;
    if ( i <= 0)                  // fins a posició zero del vector
        return altura;

    altura =  1 + verificarAltura(getPare(i));      // suman 1 a cada crida recursiva
    return  altura;
}
template<class Clau, class Valor>
void MinHeap<Clau, Valor>::calcularAltura(int &altura, int i){
    //Post: recorre l'arbre fins arriba a les fulles. Actualitzant l'atribut de classe _height
    if ( i >= 0 || i < tamany()) {
        if(isExternal(i)){
            altura = verificarAltura( i);       // verifica alçada des de aquesta fulla

            if (this->_height < altura)          // Es queda amb el valor més alt
                this->_height = altura;
        } else {
            calcularAltura( altura, getLeft(i));    // Recorre nodes esquerra
            calcularAltura(altura, getRight(i));    // Recorre nodes de la dreta
        }
    }else
        throw invalid_argument("Node és Nullptr");

}
template<class Clau, class Valor>
int MinHeap<Clau, Valor>::altura(){
    //Post: retorna atribut de classe _height, després d'actualitzar-se amb el mètode calcularAltura()
    int altura = 1;
    int i = 0;
    if (esBuit())
        throw invalid_argument("\e[1mL'arbre està buit\e[0m");
    else{
        calcularAltura( altura, i);       //Crida al mètode recursiu per calcula alçada
        return this->_height;
    }
}
template<class Clau, class Valor>
void MinHeap<Clau, Valor>::imprimir() {
    //Post: print per pantalla en forma d'arbre totes les keys del nodes
    int controlNivell = 3;
    cout << "(" << this->_data[0].getKey() << ")" << endl;                   // print KEY node arrel

    for (int i = 1; i < tamany(); i++) {                   // Bucle que recorre tot l'array
        if (this->_data[i].getNivell() == controlNivell){   // condicional per detectar canvi de nivell i fer un \n
            cout <<  endl;
            controlNivell = this->_data[i].getNivell() + 1;
        }
        cout << "(" << this->_data[i].getKey() << ")" << "   ";             // print KEY node
    }
    cout << endl;
    cout << "\n\e[1m" << this->_mida << " Nodes.\e[0m" << endl;
}
template<class Clau, class Valor>
void MinHeap<Clau, Valor>::reOrdenarArbre(int i){
    //Post: Mètode recursiu, reOrdena l'arbre després d'esborra un element

    NodeHeap<Clau, Valor> auxiliar = this->_data[i];
    if ( getLeft(i) < tamany() -1 || getRight(i) < tamany() -1) {      // Verificar que hi hagi element dret i esquerra
        if (this->_data[getLeft(i)].getKey() < this->_data[getRight(i)].getKey()) {  // verifica key més petita dels fills
            if (this->_data[getLeft(i)].getKey() < this->_data[i].getKey()) { //  Si fill és menor que Pare
                //intercamviar node
                this->_data[i] = this->_data[getLeft(i)];
                this->_data[getLeft(i)] = auxiliar;
                this->_data[i].setNivell(auxiliar.getNivell());
                this->_data[getLeft(i)].setNivell(this->_data[i].getNivell() + 1);
                reOrdenarArbre(getLeft(i));   // Crida recursiva fins l'arbre estigui ordenat
            }
        } else {       // Key Right és la més petita dels dos fills del node Pare
            if (this->_data[getRight(i)].getKey() < this->_data[i].getKey()) {  // Si fill és menor que Pare
                //intercamviar node
                this->_data[i] = this->_data[getRight(i)];
                this->_data[getRight(i)] = auxiliar;
                this->_data[i].setNivell(auxiliar.getNivell());
                this->_data[getRight(i)].setNivell(this->_data[i].getNivell() + 1);
                reOrdenarArbre(getRight(i));    // Crida recursiva fins l'arbre estigui ordenat
            }
        }
    }
    if (tamany() == 2){   // Hi ha només dos nodes i la rutina anterior no serveix quan no hi ha dos germans
        if (this->_data[0].getKey() > this->_data[1].getKey()) {   // Si segon node és inferior al primer
            this->_data[0] = this->_data[1];                     // intercanviar nodes
            this->_data[1] = auxiliar;
        }

    }
}
template<class Clau, class Valor>
void MinHeap<Clau, Valor>::eliminaMinim(){
    //Post: Eliminar node arrel, ja que és el node amb la key més petita.

    if (esBuit())
        throw invalid_argument("L'arbre està buit, no hi ha res a esborrar");
    cout << "(" << this->_data[0].getKey() << ")  Node eliminat" << endl;

    NodeHeap<Clau, Valor> auxiliar = this->_data[0];
    this->_data[0] = this->_data[tamany()-1];     // intercanvia l'ultim element de l'array amb el node arrel
    this->_data[0].setNivell(1);
    this->_data.pop_back();          // esborra del vector últim element
    this->_mida --;
    this->_height = 0;

    reOrdenarArbre(0);     // Va a reOrdenar l'arbre.
}

template<class Clau, class Valor>
void MinHeap<Clau, Valor>::searchReacursiu(int i, const int k, int &trobat)  {
    //Pre: int k key del node a buscar.
    //     int trobat: retorna la posició a l'array de l'element buscat
    // Post: Va recorren l'arbre mentres la 'k' sigui més gran que la key del node actual.
    //       Si la 'k' es menor, ja no segueix recorren l'arbre i surt amb trobat = -1. No trobat

    if ( i < tamany() && trobat == -1) {
        if (this->_data[i].getKey() != k ) {                 // Compra key() del nodo con 'k'
            if (k > this->_data[i].getKey()) {              // Si la 'k' és más grande sigue buscando
                searchReacursiu(getLeft(i), k, trobat);       // Sigue buscando por el lado izquierdo
                searchReacursiu(getRight(i), k, trobat);      // Sigue buscando por el lado derecho
            }
        } else
            trobat = i;
    }
}
template <class Clau, class Valor>
Valor MinHeap<Clau, Valor>::cerca(const Clau& k) {
    //Mètode ITERATIU per petició de l'anunciat
    //Post: Retorna el node amb la clau 'k' que arriba per paràmetres

    if (esBuit())
        throw invalid_argument("\e[1mL'arbre està buit\e[0m");       // Excepció Arbre buit
    else{
        int trobat = -1;
        searchReacursiu(0, k, trobat);
        if (trobat != -1) {                     // Si trobat diferent a "-1", retorna node. getValue()
            return this->_data[trobat].getValue();
        }
        else
            throw invalid_argument("Id no trobat");
    }
}