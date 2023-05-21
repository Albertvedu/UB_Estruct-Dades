//
// Created by albert on 9/05/23.
//

#ifndef PRACTICA_3_CERCADORMOVIESHEAP_H
#define PRACTICA_3_CERCADORMOVIESHEAP_H

#include "MinHeap.h"
#include "Movie.h"


template < class Clau, class Valor>
class CercadorMoviesHeap: protected MinHeap<Clau, Valor> {
public:
    // CONSTRUCTORS
    CercadorMoviesHeap();
    CercadorMoviesHeap(const CercadorMoviesHeap &orig);

    // DESTRUCTOR
    virtual ~CercadorMoviesHeap();

    // CONSULTORS
    Movie buscarMovie(int movieID);
    float buscarRatingMovie(int movieID);
    int height() ;
    int profunditat();
    bool isNull() const;
    void mostrarArbre() ;
    string mostrarMovie(int movieID);

    // MODIFICADORS
    void appendMovies(string filename);
    void insertarMovie(int movieID, string title, float rating);
    void eliminarMinimaMovie(int n);

private:

};
#endif //PRACTICA_3_CERCADORMOVIESHEAP_H



/*########################################################
#####           .CPP                                 ###
########################################################*/

template <class Clau, class Valor>
CercadorMoviesHeap<Clau, Valor>::CercadorMoviesHeap(){
    //De fet fa dues cridas, una al hereda de MinHead() i l'altre aqui, quan jo crido al constructor Pare

    ::MinHeap<Clau, Valor>(); // És inncessari, al heredà de MinHead(), ja fa una crida automàtica al constructor MinHead()
}

template <class Clau, class Valor>
CercadorMoviesHeap<Clau, Valor>::CercadorMoviesHeap(const CercadorMoviesHeap & orig){

}

template <class Clau, class Valor>
CercadorMoviesHeap<Clau, Valor>::~CercadorMoviesHeap(){
    // Destructor innecessari. No hi ha memòria dinàmica utilitzada.
    cout << "Espai de memòria reinicialitzat automàticament" << endl;
}

template <class Clau, class Valor>
void CercadorMoviesHeap<Clau, Valor>::appendMovies(string filename){
    int id, pos1, pos2, repetits = 0;
    string nom;
    float rating;
    string delimitador = ":";
    string linea;
    if ( !this->esBuit())
        throw invalid_argument("Ja tens un arbre creat amb les dades del fitxer.\n Si vols un altre arbre has de sortir, per crear-ne un de nou");

    if ( ifstream arxiu{ filename}) {

        while (  !arxiu.eof() ) {
            getline(arxiu, linea);                      // Llegeix la linea del arxiu
            pos1 = linea.find_first_of(delimitador,0);   // Trobar posicio primer limitador ":"
            id = stoi(linea.substr(0, pos1));         // Asigna a ID els caràcters entre pos zero i Pos1
            pos2 = linea.find_first_of(delimitador, pos1+1);  // Trobar posicio segon limitador ":"
            nom = linea.substr(pos1+1, pos2-pos1-1);   // Asigna a NOM els caràcters entre pos pos1 i Pos2
            rating = stof(linea.substr(pos2+1));      // Asingna a RATING la resta caràcters de la linea

            try {
                insertarMovie(id, nom, rating);        // Pasa dades a mètode insertarMovie()
            }catch(const invalid_argument &e){
                cerr << e.what() << '\n';
                repetits ++;
            }
        }
        arxiu.close();
        cout << endl;
        cout << "S'han insertat " << this->tamany() << " elements." << endl;
        cout << "Elements repetits No insertats:  " << repetits << endl;
        // cout << "Alçada........... " << height() << endl;
    } else {
        throw invalid_argument ("\nNO S'HA POGUT OBRIR EL FITXER");
    }
}

template <class Clau, class Valor>
void CercadorMoviesHeap<Clau, Valor>::insertarMovie(int movieID, string title, float rating){
    Movie movie = Movie(movieID, title, rating);
    this->inserir(movieID, movie);
}
template <class Clau, class Valor>
string CercadorMoviesHeap<Clau, Valor>::mostrarMovie(int movieID){
    return  this->cerca(movieID).toString();   // usar mètodo toString() no lo veo práctico.
}

template <class Clau, class Valor>
Movie CercadorMoviesHeap<Clau, Valor>::buscarMovie(int movieID){
    return this->cerca(movieID);
}

template <class Clau, class Valor>
float CercadorMoviesHeap<Clau, Valor>::buscarRatingMovie(int movieID){
    return this->cerca(movieID).getRating();
}

template <class Clau, class Valor>
void CercadorMoviesHeap<Clau, Valor>::eliminarMinimaMovie(int n){

    if (n <= this->tamany()) {                      // Controla no eliminar més nodes dels que hi ha
        for (int i = 0; i < n; ++i)
            this->eliminaMinim();
        cout << n << " Nodes eliminats" << endl;
        if (this->tamany() == 0)                     // Si ja no queden nodes.. print missatge
            cout << "\n\e[1mHas eliminat tots el nodes. Arbre buit\e[0m" << endl;
    }
    else
        throw invalid_argument("Quantitat errónea, no hi ha aquest nombre de Pel·lícules en memòria.");
}

template <class Clau, class Valor>
int CercadorMoviesHeap<Clau, Valor>::height() {

    return this->altura();
}
template <class Clau, class Valor>
int CercadorMoviesHeap<Clau, Valor>::profunditat() {
    //Post: retorna alçada -1 és profunditat de l'arbre
    return this->height() -1;
}
template <class Clau, class Valor>
bool CercadorMoviesHeap<Clau, Valor>::isNull() const {
    return this->esBuit();
}
template <class Clau, class Valor>
void CercadorMoviesHeap<Clau, Valor>::mostrarArbre() {
    this->imprimir();
}
