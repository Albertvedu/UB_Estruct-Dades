
#include <iostream>
#include <initializer_list>
#include "NodeLlista.h"
#include "Posicio.h"

using  namespace std;

template <class Element>

class Llista{
public:

    Llista();
    Llista(initializer_list<Element> elements);
    Llista(const Llista<Element>& origen);
    virtual ~Llista();
    int tamany() const;
    bool esBuida() const;
    Posicio<Element> principi() const; // return first position
    Posicio<Element> nfinal() const; // return last position
    // Reverse iteration
    Posicio<Element> rprincipi() const; // return first position
    Posicio<Element> rfinal() const; // return last position
    void inserirDespres(Posicio<Element>& position, const Element& element);
    void inserirAbans(Posicio<Element>& position, const Element& element);
    void inserirPrincipi(const Element& element);
    void inserirFinal(const Element& element);

    void elimina(Posicio<Element>& position);
private:

    NodeLlista<Element>* _cap;
    NodeLlista<Element>* _cua;
    int _tamany{};
};

/*########################################################
#####           .CPP                                 ###
########################################################*/


template <class Element>
Llista<Element>::Llista(){
    //this->_cap = NULL;
    this->_cap = new NodeLlista<Element>(); // sentinella front
    this->_cua = new NodeLlista<Element>();// sentinella rear
    this->_cap->setNext(this->_cua);
    this->_cua->setPrevious(this->_cap);
    cout << "inicialitzat.................. " << endl;

}

template <class Element>
Llista<Element>::Llista(initializer_list<Element> elements){

}
template <class Element>
Llista<Element>::Llista(const Llista<Element>& origen){
    Posicio<Element> *nodeNou;
    Posicio<Element> *nodeAnterior; 

   /*  if ( !origen.esBuida()){                //Llista origen no està buïda
        nodeNou = new Posicio<Element>(new NodeLlista<Element>(origen.principi()));
        this->_cap->setNext(nodeNou);
        this->_cua->setPrevious(nodeNou);
        this->_tamany ++;
        nodeAnterior = nodeNou;

        while ((origen.nfinal()->getElement() != "Centinella")){

            nodeNou = new NodeLlista<Element>(origen.principi());
            nodeNou->_node->setPrevious(nodeAnterior);
            nodeNou->_node->setNext(this->_cua);
            this->_cua->setPrevious(nodeNou);
            this->_tamany ++;
            cout << "Copiat element: " << origen->principi()++ << endl;
        }
    }else 
        cout << "La llista d'entrada està buïda" << endl;*/
}

template <class Element>
Llista<Element>::~Llista(){
    //Pre: --; Post: esborra tots els elements
       while( this->principi() != nullptr ){

          Posicio<Element> *aux = this->principi();   // auxiliar = primer element
          elimina(aux);      // primer element = segon element
          delete aux;                                // esborra auxiliar
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
Posicio<Element> Llista<Element>::principi() const{// return first position
    Posicio<Element> *p;
    
    return p->_node;

} 

template <class Element>
Posicio<Element> Llista<Element>::nfinal() const{} // return last position

template <class Element>
// Reverse iteration
Posicio<Element> Llista<Element>::rprincipi() const{// return first position
    return this->_cap->getNext();
}

template <class Element>
Posicio<Element> Llista<Element>::rfinal() const{
    cout << "\nCUA PREVIOUS: " << this->_cua->getPrevious() << endl;
    return this->_cua->getPrevious() ;
}

template <class Element>
void Llista<Element>::inserirDespres(Posicio<Element>& position, const Element& element){
    //TODO falta asignar element

    //Al node nou, li posiciona el anterior i posterior
    position.fixarSeguent(this->_cua);
    position.fixarAnterior(this->_cua->getPrevious());  // rfinal() NO FUNCIONA, NO VEIG PERQUÈ
    //Al ultim node, posa com a NEXT al node nou
    this->_cua->getPrevious()->setNext(position.getNode());
    // Anterior a la cua, posiciona el node nou
    this->_cua->setPrevious(position.getNode());
    this->_tamany ++;
    cout << position.getNode() <<  "  ... NODE afegit en última posició" << endl;
}

template <class Element>
void Llista<Element>::inserirAbans(Posicio<Element>& position, const Element& element){
    //TODO falta asignar element

    //Al node nou, li posiciona el anterior i posterior
    position.fixarSeguent(this->_cap->getNext());
    position.fixarAnterior(this->_cap);
    //Al primer node, posa com a PREVIOUS al node nou
    this->_cap->getNext()->setPrevious(position.getNode());
    // Anterior a la cua, posiciona el node nou
    this->_cap->setNext(position.getNode());
    this->_tamany ++;
    cout << position.getNode() <<  "  ... NODE afegit en primera posició" << endl;

}

template <class Element>
void Llista<Element>::inserirPrincipi(const Element& element){}

template <class Element>
void Llista<Element>::inserirFinal(const Element& element){}

template <class Element>
void Llista<Element>::elimina(Posicio<Element>& position){
    position.next().fixarAnterior(position.anterior());
    position.anterior().fixarSeguent(position.next());
    cout << "Node eliminat" << endl;
}