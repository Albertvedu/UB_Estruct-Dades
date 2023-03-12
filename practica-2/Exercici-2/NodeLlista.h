//
// Created by albert on 9/03/23.
//
#ifndef NODELLISTA_H
#define NODELLISTA_H

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
    this->_element = "Centinella";
    this->_next = NULL;
    this->_previous = NULL;


}

template <class Element>
NodeLlista<Element>::NodeLlista(Element element){}

template <class Element>
NodeLlista<Element>::~NodeLlista(){}

template <class Element>
const Element& NodeLlista<Element>::getElement() const{
    return this->_element;
}

template <class Element>
NodeLlista<Element>* NodeLlista<Element>::getNext() const{
    return this->_next;
}

template <class Element>
void NodeLlista<Element>::setNext(NodeLlista<Element>* node){
    this->_next = node;
}

template <class Element>
NodeLlista<Element>* NodeLlista<Element>::getPrevious() const{
    return this->_previous;
}

template <class Element>
void NodeLlista<Element>::setPrevious(NodeLlista<Element>* node){
    this->_previous = node;
}
#endif
