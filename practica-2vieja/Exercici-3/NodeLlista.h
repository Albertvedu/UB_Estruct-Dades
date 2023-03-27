#ifndef NODELLISTA_H
#define NODELLISTA_H

#include <iostream>
using namespace std;

template <class Element>

class NodeLlista{
public:
    //CONSTRUCTOR
    NodeLlista();
    NodeLlista(Element element);

    //DESTRUCTOR
    ~NodeLlista();

    //CONSULTORS
    const Element& accedirElement() const;
    NodeLlista<Element>* accedirSeguent() const;
    NodeLlista<Element>* accedirAnterior() const;

    //MODIFICADORS
    void fixarSeguent(NodeLlista<Element>* node);
    void fixarAnterior(NodeLlista<Element>* node);

private:
    Element _element;
    NodeLlista<Element>* _next;
    NodeLlista<Element>* _previous;
};
#endif

/*########################################################
#####           .CPP                                 ###
########################################################*/

template <class Element>
NodeLlista<Element>::NodeLlista(){
   // this->_element = "CENTINELLA";
    this->_next = nullptr;
    this->_previous = nullptr;
}

template <class Element>
NodeLlista<Element>::NodeLlista(Element element){
    this->_element = element;
    this->_previous = nullptr;
    this->_next = nullptr;
}

template <class Element>
NodeLlista<Element>::~NodeLlista(){
    
//     while ( this->_next != nullptr){
//        NodeLlista<Element>* aux = this->_next;
//        fixarSeguent(this->_next->_next);
//         if (_next == nullptr)
//             throw invalid_argument( "Punter és NULL" );
//        delete aux;
//    }
}

template <class Element>
const Element& NodeLlista<Element>::accedirElement() const{
    return this->_element;
}

template <class Element>
NodeLlista<Element>* NodeLlista<Element>::accedirSeguent() const{
    return _next;
}

template <class Element>
NodeLlista<Element>* NodeLlista<Element>::accedirAnterior() const{
    return this->_previous;
}

template <class Element>
void NodeLlista<Element>::fixarSeguent(NodeLlista<Element>* node){
    this->_next = node;
}
template <class Element>
void NodeLlista<Element>::fixarAnterior(NodeLlista<Element>* node){
    this->_previous = node;
}
