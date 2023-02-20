//
// Created by alber on 01/04/2022.
//

#include "CuaString.h"

CuaString::CuaString()	{
//	Pre:	--;	Post:	cua	buida
    //	COST:	O(1)
    a_primer=a_darrer=	NULL;
}

CuaString::CuaString(const	CuaString&	o)	{
//	Pre:	--;	Post:	aquesta	cua	és	còpia	de	la	cua	o
    //	COST:	O(n)
    a_primer=a_darrer=	NULL;
    copia(o);	//	crida	a	mètode	privat
}

CuaString::~CuaString()	{
//	Pre:	--;	Post:	memòria	alliberada
    //	COST:	O(n)
    allibera();	//	crida	a	mètode	privat
}
//	CONSULTORS
bool	CuaString::buida()	const	{
//	Pre:	--	;	Post:	retorna	cert	si	la	cua	és	buida;	fals	en	c.c.
//	COST:	O(1)
    return	a_primer==NULL;
}

string	CuaString::primer()	const	{
//	Pre:	cua	no	buida;	Post:	retorna	còpia	del	primer	de	la	cua
//	COST:	O(1)
    return	a_primer->valor;
}
//	MODIFICADORS
void	CuaString::encua(string	s)	{
//	Pre:	--;	Post:	ha	afegit	s	al	final	de	la	cua
//	COST:	O(1)
    Node*	nou=	new	Node;
    nou->valor=	s;	nou->seg=	NULL;
    if	(buida())	//	this->buida()
        a_primer=a_darrer=	nou;
    else	{
        a_darrer->seg=	nou;	a_darrer=	nou;
    }
}

void	CuaString::desencua()	{
//	Pre:	cua	no	buida;	Post:	ha	eliminat	el	primer	de	la	cua
//	COST:	O(1)
    Node*	aux=	a_primer;
    if	(a_primer==a_darrer)		//	només	hi	ha	un	element
        a_primer=a_darrer=	NULL;
    else	a_primer=	a_primer->seg;
    delete	aux;
}
//	MÈTODES	PRIVATS
void	CuaString::copia(const	CuaString&	o)	{
//	Pre:	cua	buida;	Post:	aquesta	cua	és	còpia	de	o
    //	COST:	O(n)
    Node*	p	=	o.a_primer;
    while(p!=NULL){						//	recorrem	cua	o
        encua(p->valor);	//	this->encua(p->valor)
        p=p->seg;
    }
}

void	CuaString::allibera()	{
//	Pre:	--;	Post:	cua	buida
    //	COST:	O(n)
    while	(a_primer!=NULL)	{	//!buida()
        Node*	aux=	a_primer;
        a_primer=	a_primer->seg;
        delete	aux;
    }
    a_darrer=	NULL;
}
CuaString&	CuaString::operator=(const	CuaString&	o)	{
//	Pre:	--	;	Post:	aquesta	cua	és	còpia	de	o
//	COST:	O(n)
    if	(this	!=	&o){
        allibera();
        copia(o);
    }
    return	*this;
}
