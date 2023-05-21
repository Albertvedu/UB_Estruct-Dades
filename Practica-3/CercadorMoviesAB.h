//
// Created by albert on 27/04/23.
//

#ifndef PRACTICA_3_CERCADORMOVIESAB_H
#define PRACTICA_3_CERCADORMOVIESAB_H

#include "Movie.h"
#include "ArbreBinari.h"
#include "LecturaDades.h"
#include <fstream>


template < class Clau, class Valor>
class CercadorMoviesAB: protected ArbreBinari<Clau, Valor>{
public:
    //CONSTRUCTORS
    CercadorMoviesAB();
    CercadorMoviesAB(const CercadorMoviesAB & orig);

    //DESTRUCTOR
    virtual ~CercadorMoviesAB();

    // CONSULTORS
    string mostrarMovie(int movieID);                           // Cost O( log n )
    Movie buscarMovie(int movieID);                             // Cost O( log n )
    float buscarRatingMovie(int movieID);                       // Cost O( log n )
    int height() ;                                              // Cost O( n log n )
    int profunditat();                                          // Cost O( n log n )
    bool isNull() const;                                        // Cost O( 1 )
    void mostrarArbre() ;                                       // Cost O( n )

    // MODIFICADORS
    void appendMovies(string filename);                                 // Cost O( n log n )
    void insertarMovie(int movieID, string title, float rating);        // Cost O( log n )
    void eliminarMinimaMovie(int n);                                    // Cost O( log n )



};

/*########################################################
#####           .CPP                                 ###
########################################################*/

template <class Clau, class Valor>
CercadorMoviesAB<Clau, Valor>::CercadorMoviesAB(){
    //  ::ArbreBinari<Clau, Valor>();  // Innecesario, al heredar ya hace una llamada al constructor de ArbreBinari().
}

template <class Clau, class Valor>
CercadorMoviesAB<Clau, Valor>::CercadorMoviesAB(const CercadorMoviesAB & orig){

}

template <class Clau, class Valor>
CercadorMoviesAB<Clau, Valor>::~CercadorMoviesAB(){

}

template <class Clau, class Valor>
void CercadorMoviesAB<Clau, Valor>::appendMovies(string filename){
    int id, pos1, pos2, repetits = 0;
    string nom;
    float rating;
    string delimitador = ":";
    string linea;
    if ( !this->isEmpty())
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
        cout << "S'han insertat " << this->getSize() << " elements." << endl;
        cout << "Elements repetits No insertats:  " << repetits << endl;
       // cout << "Alçada........... " << height() << endl;
    } else {
        throw invalid_argument ("\nNO S'HA POGUT OBRIR EL FITXER");
    }
}

template <class Clau, class Valor>
void CercadorMoviesAB<Clau, Valor>::insertarMovie(int movieID, string title, float rating){
    Movie movie = Movie(movieID, title, rating);
    this->insert(movieID, movie);
}

template <class Clau, class Valor>
string CercadorMoviesAB<Clau, Valor>::mostrarMovie(int movieID){
    return this->search(movieID)->getValue().toString();   // usar mètodo toString() no lo veo práctico.
}

template <class Clau, class Valor>
Movie CercadorMoviesAB<Clau, Valor>::buscarMovie(int movieID){
        return this->search(movieID)->getValue();
}

template <class Clau, class Valor>
float CercadorMoviesAB<Clau, Valor>::buscarRatingMovie(int movieID){
    return this->search(movieID)->getValue().getRating();
}

template <class Clau, class Valor>
void CercadorMoviesAB<Clau, Valor>::eliminarMinimaMovie(int n){
   //Post: Executa 'n' vegades el mètode eliminarMinim()

    if (n <= this->getSize()) {
        for (int i = 0; i < n; ++i)
            this->eliminaMinim();
        cout << n << "  Nodes eliminats" << endl;
        if ( this->getSize() == 0)
            cout << "\n\e[1mHas eliminat tots el nodes. Arbre buit\e[0m" << endl;
    }
    else
        throw invalid_argument("Quantitat errónea, no hi ha aquest nombre de Pel·lícules en memòria.");
}

template <class Clau, class Valor>
int CercadorMoviesAB<Clau, Valor>::height() {
    this->setHeight(0);
    this->calcularHeightArbre(this->root);
    return this->getHeight();
}
template <class Clau, class Valor>
int CercadorMoviesAB<Clau, Valor>::profunditat() {
    return this->height() -1;
}
template <class Clau, class Valor>
bool CercadorMoviesAB<Clau, Valor>::isNull() const {
    return this->isEmpty();
}
template <class Clau, class Valor>
void CercadorMoviesAB<Clau, Valor>::mostrarArbre() {
    this->mostrarArbreOrdenat();
}
#endif //PRACTICA_3_CERCADORMOVIESAB_H
