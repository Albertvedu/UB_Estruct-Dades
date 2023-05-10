//
// Created by albert on 27/04/23.
//

#include "Movie.h"
#include <cmath>

//CONSTRUCTORS
Movie::Movie() {

}
Movie::Movie(int id, const string &nom, float rating){
    this->_id = id;
    this->_nom = nom;
    this->_rating = rating;
}
Movie::Movie(const Movie *m) {
    if ( m != nullptr){
        this->_id = m->_id;
        this->_nom = m->_nom;
        this->_rating = m->_rating;
    }
}
Movie::~Movie() {

}
//GETTERS
int Movie::getId() const {
    return _id;
}
float Movie::getRating() const {
    return _rating;
}
const string &Movie::getNom() const {
    return _nom;
}

//SETTERS
void Movie::setId(int id) {
    _id = id;
}
void Movie::setNom(const string &nom) {
    _nom = nom;
}
void Movie::setRating(float rating) {
    _rating = rating;
}

//CONSULTORS
void Movie::toString(const Movie *movie) const{
    cout << "(" << movie->_id << "::"
         << movie->_nom << "::"
         << movie->_rating << ")" << endl;
}
string Movie::print() const {
    return "(" + to_string(this->_id) + "::"
    + this->_nom + "::"
    + to_string(this->getRating()).substr(0,4) + ")";
}
//MODIFICADORS