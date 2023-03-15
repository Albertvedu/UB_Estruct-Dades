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

    // METODES CREATS PER MI
    void setElement(Element l) ;  
   

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
    this->_element = "probando";
    this->_next = nullptr;
    this->_previous = nullptr;


}

template <class Element>
NodeLlista<Element>::NodeLlista(Element element){
    this->_element = element;
    this->_previous = _previous;
    this->_next = nullptr;
}

template <class Element>
NodeLlista<Element>::~NodeLlista(){

   /*  while (this->_next != nullptr)
        delete this->_next;
         */
}


template <class Element>
const Element& NodeLlista<Element>::getElement() const{
    return this->_element;
}

template <class Element>
NodeLlista<Element>* NodeLlista<Element>::getNext() const{
    return _next;
}
template <class Element>  //// METODE MEU
void NodeLlista<Element>::setElement(Element l) {
    this->_element = l;  // AIXO DONA ERROR NO SE PERQUÈ

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
