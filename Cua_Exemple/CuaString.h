//
// Created by alber on 01/04/2022.
//

#ifndef CUA_EXEMPLE_CUASTRING_H
#define CUA_EXEMPLE_CUASTRING_H
#include <iostream>
using namespace std;

class CuaString {
//	Descripció:	una	cua	d’strings
public:
    //	CONSTRUCTORS	I	DESTRUCTOR	----------------------------------
    CuaString();
    //	Pre:	--;	Post:	cua	buida
    CuaString(const	CuaString&	o);		//	const.	de	còpia
    //	Pre:	--;	Post:	aquesta	cua	és	còpia	de	la	Cua	o
    ~CuaString();
    //	Pre:	--;	Post:	memòria	alliberada
    //	CONSULTORS	-------------------------------------------------
    bool	buida()	const;
    //	Pre:	--	;	Post:	retorna	cert	si	la	cua	és	buida;	fals	en	c.c.
    string	primer()	const;
    //	Pre:	cua	no	buida;	Post:	retorna	còpia	del	primer	string	de	la	cua
    //	MODIFICADORS	-----------------------------------------------
    void	encua(string	s);
    //	Pre:	--;	Post:	ha	afegit	s	al	final	de	la	cua
    void	desencua();
    //	Pre:	cua	no	buida;	Post:	ha	eliminat	el	primer	element	de	la	cua
    //	OPERADORS	REDEFINITS	--------------------------------------
    CuaString&	operator=(const	CuaString&	o);
    //	Pre:	--	;	Post:	aquesta	cua	és	còpia	de	o
private:
    struct	Node	{
        string	valor;
        Node*	seg;
    };

//	ATRIBUTS
    Node*	a_primer;	//	punter	al	primer	de	la	cua
    Node*	a_darrer;	//	punter	al	darrer	de	la	cua
    void	copia(const	CuaString&	o);
    //	Pre:	Cua	buida;	Post:	aquesta	cua	es	copia	de	o
    void	allibera();
    //	Pre:	--;	Post:	cua	buida

};


#endif //CUA_EXEMPLE_CUASTRING_H
