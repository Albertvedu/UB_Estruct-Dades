
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
    cout << "bla: " << origen._cap->getNext()->getElement() << endl;
    if (origen._cap->getNext()->getElement() == "Centinella")
        cout << "lococo" << endl;
    else cout << "no ses cocso" << endl;
   // Llista<Element> *p = origen.principi();

/*   while( p != NULL ){
      encua( p->a_fitxa );
      p = p->a_seg;
  } */

}

template <class Element>
Llista<Element>::~Llista(){
    //Pre: --; Post: esborra tots els elements
    /*   while( a_primer != NULL ){


          Node *aux = a_primer;
          a_primer = a_primer->a_seg;
          delete aux;
      }
      a_darrer = NULL; */
}

template <class Element>
int Llista<Element>::tamany() const{
    return this->tamany;
}

template <class Element>
bool Llista<Element>::esBuida() const{
    return this->tamany == 0;
}

template <class Element>
Posicio<Element> Llista<Element>::principi() const{} // return first position

template <class Element>
Posicio<Element> Llista<Element>::nfinal() const{} // return last position

template <class Element>
// Reverse iteration
Posicio<Element> Llista<Element>::rprincipi() const{} // return first position

template <class Element>
Posicio<Element> Llista<Element>::rfinal() const{} // return last position

template <class Element>
void Llista<Element>::inserirDespres(Posicio<Element>& position, const Element& element){}

template <class Element>
void Llista<Element>::inserirAbans(Posicio<Element>& position, const Element& element){}

template <class Element>
void Llista<Element>::inserirPrincipi(const Element& element){}

template <class Element>
void Llista<Element>::inserirFinal(const Element& element){}

template <class Element>
void Llista<Element>::elimina(Posicio<Element>& position){}