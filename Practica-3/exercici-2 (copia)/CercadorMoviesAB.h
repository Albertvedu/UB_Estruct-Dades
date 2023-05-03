//
// Created by albert on 27/04/23.
//

#ifndef PRACTICA_3_CERCADORMOVIESAB_H
#define PRACTICA_3_CERCADORMOVIESAB_H

#include "Movie.h"
#include "ArbreBinari.h"
#include <fstream>


template < class Clau, class Valor>
class CercadorMoviesAB: protected ArbreBinari<Clau, Valor>{
public:
    CercadorMoviesAB();
    CercadorMoviesAB(const CercadorMoviesAB & orig);
    virtual ~CercadorMoviesAB();
    void appendMovies(string filename);
    void insertarMovie(int movieID, string title, float rating);
    string mostrarMovie(int movieID);
    Movie buscarMovie(int movieID);
    float buscarRatingMovie(int movieID);
    void eliminarMinimaMovie(int n);
    int height() const;
private:
    ArbreBinari<int, Movie>* _tree;
};

/*########################################################
#####           .CPP                                 ###
########################################################*/

template <class Clau, class Valor>
CercadorMoviesAB<Clau, Valor>::CercadorMoviesAB(){
    this->_tree = new ArbreBinari<int, Movie>();
}

template <class Clau, class Valor>
CercadorMoviesAB<Clau, Valor>::CercadorMoviesAB(const CercadorMoviesAB & orig){}

template <class Clau, class Valor>
CercadorMoviesAB<Clau, Valor>::~CercadorMoviesAB(){}

template <class Clau, class Valor>
void CercadorMoviesAB<Clau, Valor>::appendMovies(string filename){
    int id, pos1, pos2;
    string nom;
    float rating;
    string delimitador = ":";
    string linea;

    if ( ifstream arxiu{ filename}) {

        while (  !arxiu.eof() ) {
            getline(arxiu, linea);                      // Llegeix la linea del arxiu
            pos1 = linea.find_first_of(delimitador,0);   // Trobar posicio primer limitador ":"
            id = stoi(linea.substr(0, pos1));         // Asigna a ID els caràcters entre pos zero i Pos1
            pos2 = linea.find_first_of(delimitador, pos1+1);  // Trobar posicio segon limitador ":"
            nom = linea.substr(pos1+1, pos2-pos1-1);   // Asigna a NOM els caràcters entre pos pos1 i Pos2
            rating = stof(linea.substr(pos2+1));      // Asingna a RATING la resta caràcters de la linea

            insertarMovie(id, nom, rating);        // Pasa dades a mètode insertarMovie()

        }
        arxiu.close();
        cout << endl;
    } else {
        throw invalid_argument ("\nNO S'HA POGUT OBRIR EL FITXER");
    }
}

template <class Clau, class Valor>
void CercadorMoviesAB<Clau, Valor>::insertarMovie(int movieID, string title, float rating){
    Movie movie = Movie(movieID, title, rating);
    this->_tree->insert(movieID, movie);
}

template <class Clau, class Valor>
string CercadorMoviesAB<Clau, Valor>::mostrarMovie(int movieID){
    NodeBinari<int, Movie>* movieNode = this->_tree->search(movieID);
    cout << "dd";
    return "x";//print();
}

template <class Clau, class Valor>
Movie CercadorMoviesAB<Clau, Valor>::buscarMovie(int movieID){
    return Movie();
}

template <class Clau, class Valor>
float CercadorMoviesAB<Clau, Valor>::buscarRatingMovie(int movieID){
    return 3.5;
}

template <class Clau, class Valor>
void CercadorMoviesAB<Clau, Valor>::eliminarMinimaMovie(int n){}

template <class Clau, class Valor>
int CercadorMoviesAB<Clau, Valor>::height() const{
    return 0;
}

#endif //PRACTICA_3_CERCADORMOVIESAB_H
