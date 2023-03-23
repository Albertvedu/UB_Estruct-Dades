
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
    Posicio<Element> final() const; // return last position
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

    //MÈTODES PRIVATS
    void crearCentinelles();
};

/*########################################################
#####           .CPP                                 ###
########################################################*/


template <class Element>
Llista<Element>::Llista(){
    //this->_cap = NULL;
    crearCentinelles();
    cout << "Inicialitzats centinelles .................. " << endl;

}

template <class Element>
Llista<Element>::Llista(initializer_list<Element> elements){
    crearCentinelles();
    for(Element v: elements)
        this->inserirFinal(v);
    cout << "Llista creada" << endl;
}
template <class Element>
Llista<Element>::Llista(const Llista<Element>& origen){

    if ( !origen.esBuida()){                //Llista origen no està buïda
        try{
            NodeLlista<Element> *nodeNou, *ant, *aux;
            crearCentinelles();

            // AUX = primer element de la llista a copiar
            origen.
            aux = origen.principi().getNode();
            ant = this->_cap;

            // Bucle fins trobar centinella.
            // No he pogut fer (aux ->getNext() != nullptr), perquè a "getNext" ja un control d'excepcions. No retorna NULL
            while(aux->getElement() != "CENTINELLA"){
                nodeNou = new NodeLlista<Element>(aux->getElement());  // Crea NODENOU
                nodeNou->setNext(this->_cua);                     // Enllaça NODENOU amb la CUA
                nodeNou->setPrevious(ant);                        // Enllaça NODENOU amb anterior
                this->_cua->setPrevious(nodeNou);                      // Enllaça CUA amb NODENOU
                ant->setNext(nodeNou);                            // Enllaça anterior amb NODENOU
                ant = nodeNou;                                         // Ara NODENOU pasa a ser ANTERIOR
                aux = aux->getNext();                                  // AUX pasa a ser el Node a copiar ara
                this->_tamany ++;
            }
        }catch(const std::exception& e){
            cerr << e.what() << '\n';
            sleep(1);
        }
    }else
        cout << "La llista d'entrada està buïda" << endl;
}

template <class Element>
Llista<Element>::~Llista(){
    //Pre: --; Post: esborra tots els elements
    try{
        this->_tamany += 2; // +2 per esborrar nodes de CAP i la CUA

        while( this->_cap != nullptr ){
            NodeLlista<Element>* aux = this->_cap; // auxiliar = primer element
            if (this->_tamany > 1)                     // EVITAR LLANÇAR EXCEPCIÓ DEL getNext();
                this->_cap = this->_cap->getNext();
            else
                this->_cap = nullptr;
            delete aux;                                // esborra auxiliar
            this->_tamany --;
        }

        this->_cua = nullptr;


    }catch(const std::exception& e){
        cerr << e.what() << '\n';
        sleep(1);
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
    if ( esBuida())
        return this->_cap;
    return this->_cap->getNext();
}

template <class Element>
Posicio<Element> Llista<Element>::final() const{  // return last position
    return this->_cua->getPrevious();
}

template <class Element>
// Reverse iteration
Posicio<Element> Llista<Element>::rprincipi() const{// return first position
    return this->_cua->getPrevious();  // Primer començant per l'ùltim
}

template <class Element>
Posicio<Element> Llista<Element>::rfinal() const{
    cout << "\nRevers final: " << this->_cap->getNext() << endl;
    return this->_cap->getNext();
}

template <class Element>
void Llista<Element>::inserirDespres(Posicio<Element>& position, const Element& element){
    try{
        NodeLlista<Element>* nodeNou = new NodeLlista<Element>(element);

        //Al node nou, li posiciona el anterior i posterior
        nodeNou->setNext(position.next().getNode());
        nodeNou->setPrevious(position.getNode());

        // Al següent a position, posiciona com anterior el node nou
        position.next().fixarAnterior(nodeNou);

        //Al ultim node, posa com a NEXT al node nou
        position.fixarSeguent(nodeNou);

        this->_tamany ++;
    }catch(const std::exception& e){
        cerr << e.what() << '\n';
        sleep(1);
    }

}

template <class Element>
void Llista<Element>::inserirAbans(Posicio<Element>& position, const Element& element){
    try {
        if (position == nullptr)
            throw invalid_argument( "Posició es NULL" );

        NodeLlista<Element> *nodeNou = new NodeLlista<Element>(element);  // o Posicio per paràmetres o fer servir getNode()

        //Al node nou, li posiciona el anterior i posterior
        nodeNou->setNext(position.getNode());
        nodeNou->setPrevious(position.anterior().getNode());

        // Al següent a position, posiciona com anterior el node nou
        position.anterior().fixarSeguent(nodeNou);

        //Al ultim node, posa com a NEXT al node nou
        position.fixarAnterior(nodeNou);

        this->_tamany++;
    }catch(const std::exception& e){
        cerr << e.what() << '\n';
        sleep(1);
    }
}

template <class Element>
void Llista<Element>::inserirPrincipi(const Element& element){
    try{
        NodeLlista<string>* nodeNou = new NodeLlista<string>(element);

        //Al node nou, li posiciona el anterior i posterior
        nodeNou->setNext(this->_cap->getNext());
        nodeNou->setPrevious(this->_cap);

        //Enllaço Cap i Cua amb el nodeNou
        this->_cap->getNext()->setPrevious(nodeNou);
        this->_cap->setNext(nodeNou);
        this->_tamany ++;
    }catch(const std::exception& e){
        cerr << e.what() << '\n';
        sleep(1);
    }

}

template <class Element>
void Llista<Element>::inserirFinal(const Element& element){
    try{
        NodeLlista<string>* nodeNou = new NodeLlista<string>(element);

        //Al node nou, li posiciona el anterior i posterior
        nodeNou->setNext(this->_cua);
        nodeNou->setPrevious(this->_cua->getPrevious());

        //Enllaço Cap i Cua amb el nodeNou
        this->_cua->getPrevious()->setNext(nodeNou);
        this->_cua->setPrevious(nodeNou);
        this->_tamany ++;
    }catch(const std::exception& e){
        cerr << e.what() << '\n';
        sleep(1);
    }
}

template <class Element>
void Llista<Element>::elimina(Posicio<Element>& position){
    position.next().fixarAnterior(position.anterior());
    position.anterior().fixarSeguent(position.next());
    cout << "Node eliminat" << endl;
}

//MÈTODES PRIVATS
template <class Element>
void Llista<Element>::crearCentinelles(){
    this->_cap = new NodeLlista<Element>(); // sentinella front
    this->_cua = new NodeLlista<Element>();// sentinella rear
    this->_cap->setNext(this->_cua);
    this->_cua->setPrevious(this->_cap);
}
