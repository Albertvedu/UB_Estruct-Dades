//
// Created by albert on 27/04/23.
//

#include "Movie.h"

//CONSTRUCTORS
Movie::Movie() {}
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

//CONSULTORS
void Movie::toString() const{

    cout << print() << endl;
}
string Movie::print() const {
    return "(" + to_string(this->_id) + "::"
    + this->_nom + "::"
    + to_string(this->getRating()).substr(0,4) + ")";
}
//MODIFICADORS