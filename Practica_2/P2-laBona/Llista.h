#ifndef LLISTA_H
#define LLISTA_H


#include <iostream>
#include <initializer_list>
#include "NodeLlista.h"
#include "Posicio.h"

using namespace std;

template <class Element>

class Llista{
public:
    //CONSTRUCTOR
    Llista();
    Llista(initializer_list<Element> elements);
    Llista(const Llista<Element> &origen);

    //DESTRUCTOR
    virtual ~Llista();

    //CONSULTORS
    int tamany() const;
    bool esBuida() const;
    Posicio<Element> principi() const; // return first position
    Posicio<Element> final() const;    // return last position
    // Reverse iteration
    Posicio<Element> rprincipi() const; // return first position
    Posicio<Element> rfinal() const;    // return last position

    //MODIFICADORS
    void inserirDespres(Posicio<Element> &position, const Element &element);
    void inserirAbans(Posicio<Element> &position, const Element &element);
    void inserirPrincipi(const Element &element);
    void inserirFinal(const Element &element);
    void elimina(Posicio<Element> &position);

private:
    NodeLlista<Element> *_cap;
    NodeLlista<Element> *_cua;
    int _tamany;

    // MÈTODES PRIVATS
    void crearCentinelles();
};



/*########################################################
#####           .CPP                                 ###
########################################################*/

template <class Element>
Llista<Element>::Llista(){
    crearCentinelles();
    this->_tamany = 0;
}

template <class Element>
Llista<Element>::Llista(initializer_list<Element> elements){
    if (elements.size() != 0) {
        crearCentinelles();
        for (Element v: elements)
            this->inserirFinal(v);
    }else
        throw invalid_argument ("\nInitializer_list és una llista buida");
}
template <class Element>
Llista<Element>::Llista(const Llista<Element> &origen){

    if (!origen.esBuida()){ // Si Llista origen no està buïda

        NodeLlista<Element> *nodeNou, *ant, *aux;
        crearCentinelles();

        // AUX = primer element de la llista a copiar
        aux = origen.principi().getNode(); // TODO error... getNode() NO EXISTEIX
        ant = this->_cap;

        // Bucle fins trobar final llista.
        while (aux->accedirSeguent() != nullptr){
            nodeNou = new NodeLlista<Element>(aux->accedirElement()); // Crea NODENOU
            nodeNou->fixarSeguent(this->_cua);                         // Enllaça NODENOU amb la CUA
            nodeNou->fixarAnterior(ant);                            // Enllaça NODENOU amb anterior
            this->_cua->fixarAnterior(nodeNou);                     // Enllaça CUA amb NODENOU
            ant->fixarSeguent(nodeNou);                                // Enllaça anterior amb NODENOU
            ant = nodeNou;                                        // Ara NODENOU pasa a ser ANTERIOR
            aux = aux->accedirSeguent();                                 // AUX pasa a ser el Node a copiar ara
            this->_tamany++;
        }
    }
    else
        throw invalid_argument("La llista d'entrada està buïda");
}

template <class Element>
Llista<Element>::~Llista(){
    // Pre: --; Post: esborra tots els elements
    this->_tamany += 2; // +2 per esborrar nodes de CAP i la CUA

    while (this->_cap != nullptr){
        NodeLlista<Element> *aux = this->_cap; // auxiliar = primer element
        this->_cap = this->_cap->accedirSeguent();
        delete aux; // esborra auxiliar
        this->_tamany--;
    }
}

template <class Element>
int Llista<Element>::tamany() const{
    return this->_tamany;
}

template <class Element>
bool Llista<Element>::esBuida() const{
    return this->_tamany == 0;
}

template <class Element>
Posicio<Element> Llista<Element>::principi() const{ // return first position
    if (esBuida())
        return this->_cap;
    return this->_cap->accedirSeguent();
}

template <class Element>
Posicio<Element> Llista<Element>::final() const{ // return last position
    return this->_cua->accedirAnterior();
}

template <class Element>
// Reverse iteration
Posicio<Element> Llista<Element>::rprincipi() const{    // return first position
    return this->_cua->accedirAnterior(); // Primer començant per l'ùltim
}

template <class Element>
Posicio<Element> Llista<Element>::rfinal() const{
    return this->_cap->accedirSeguent();
}

template <class Element>
void Llista<Element>::inserirDespres(Posicio<Element> &position, const Element &element){
    if (position == nullptr || position.next() == nullptr)
        throw invalid_argument( "Punter és NULL" );

    NodeLlista<Element> *nodeNou = new NodeLlista<Element>(element);

    // Al següent a position, posiciona com anterior el node nou
    position.next().fixarAnterior(nodeNou);

    // A posicio, posa com a NEXT al node nou
    position.fixarSeguent(nodeNou);
    this->_tamany++;
}

template <class Element>
void Llista<Element>::inserirAbans(Posicio<Element> &position, const Element &element){

    if (position == nullptr || position.anterior() == nullptr)
        throw invalid_argument( "Punter és NULL" );

    NodeLlista<Element> *nodeNou = new NodeLlista<Element>(element); // o Posicio per paràmetres o fer servir getNode()

    // Al anterior a position, posiciona com anterior el node nou
    position.anterior().fixarSeguent(nodeNou);

    // A posicio , posa com a ANTERIOR al node nou
    position.fixarAnterior(nodeNou);
    this->_tamany++;

}

template <class Element>
void Llista<Element>::inserirPrincipi(const Element &element){

    if (this->_cap == nullptr || this->_cua == nullptr)
        throw invalid_argument( "Punter és NULL" );

    NodeLlista<Element> *nodeNou = new NodeLlista<Element>(element);

    // Al node nou, li posiciona el anterior i posterior
    nodeNou->fixarSeguent(this->_cap->accedirSeguent());
    nodeNou->fixarAnterior(this->_cap);

    // Enllaço Cap i Cua amb el nodeNou
    this->_cap->accedirSeguent()->fixarAnterior(nodeNou);
    this->_cap->fixarSeguent(nodeNou);
    this->_tamany++;
}

template <class Element>
void Llista<Element>::inserirFinal(const Element &element){
    if (this->_cap == nullptr && this->_cua == nullptr)
        throw invalid_argument( "Punter és NULL" );
    NodeLlista<Element> *nodeNou = new NodeLlista<Element>(element);

    // Al node nou, li posiciona el anterior i posterior
    nodeNou->fixarSeguent(this->_cua);
    nodeNou->fixarAnterior(this->_cua->accedirAnterior());

    // Enllaço Cap i Cua amb el nodeNou
    this->_cua->accedirAnterior()->fixarSeguent(nodeNou);
    this->_cua->fixarAnterior(nodeNou);
    this->_tamany++;
}

template <class Element>
void Llista<Element>::elimina(Posicio<Element> &position){
    delete position.elimina();
    this->_tamany --;
    cout << "Node eliminat" << endl;
}

// MÈTODES PRIVATS
template <class Element>
void Llista<Element>::crearCentinelles(){
    this->_cap = new NodeLlista<Element>(); // sentinella front
    this->_cua = new NodeLlista<Element>(); // sentinella rear
    this->_cap->fixarSeguent(this->_cua);
    this->_cua->fixarAnterior(this->_cap);
}

#endif