//
// Created by albert on 9/03/23.
//
#ifndef NODELLISTA_H
#define NODELLISTA_H

#include <iostream>
#include "Client.h"
using namespace std;

template <class Element>
class NodeLlista{
public:
    NodeLlista();
    NodeLlista(Element element);
    ~NodeLlista();
    const Element& getElement() const;
    NodeLlista<Element>* getNext() const;
    void setNext(NodeLlista<Element>* node);
    NodeLlista<Element>* getPrevious() const;
    void setPrevious(NodeLlista<Element>* node);

private:
    Element _element;
    NodeLlista<Element>* _next;
    NodeLlista<Element>* _previous;
};

/*########################################################
  #####           .CPP                                 ###
  ########################################################*/

template <class Element>
NodeLlista<Element>::NodeLlista(){

    this->_element = new Client ("Centinella", "b", "a");
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
//
//        NodeLlista<Element>* aux = this->_next;
//        setNext(this->_next->_next);
//         if (_next == nullptr)
//             throw invalid_argument( "Punter és NULL" );
//        delete aux;
//    }
}


template <class Element>
const Element& NodeLlista<Element>::getElement() const{
    return this->_element;
}

template <class Element>
NodeLlista<Element>* NodeLlista<Element>::getNext() const{
    if (_next == nullptr)
        throw invalid_argument( "Punter és NULL" );
    return _next;
}

template <class Element>
void NodeLlista<Element>::setNext(NodeLlista<Element>* node){
    this->_next = node;
}

template <class Element>
NodeLlista<Element>* NodeLlista<Element>::getPrevious() const{
    if (_previous == nullptr)
        throw invalid_argument( "Punter és NULL" );
    return this->_previous;
}

template <class Element>
void NodeLlista<Element>::setPrevious(NodeLlista<Element>* node){
    this->_previous = node;
}
#endif
