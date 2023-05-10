//
// Created by albert on 27/04/23.
//

#ifndef PRACTICA_3_MOVIE_H
#define PRACTICA_3_MOVIE_H

#include <iostream>
using namespace std;

class Movie {
public:
    //CONSTRUCTORS
    Movie();
    Movie(int id, const string &nom, float rating);
    Movie(const Movie* m);

    //DESTRUCTORS
    virtual ~Movie();

    //GETTERS
    int getId() const;
    const string &getNom() const;
    float getRating() const;

    //SETTERS
    void setId(int id);
    void setNom(const string &nom);
    void setRating(float rating);

    //CONSULTORS
    void toString(const Movie* movie) const;
    string print() const;
    //MODIFICADORS
private:
    int _id;
    string _nom;
    float _rating;
};


#endif //PRACTICA_3_MOVIE_H
