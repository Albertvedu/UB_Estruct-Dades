#include <iostream>
#include "CuaString.h"

using namespace std;
int main() {
    CuaString	c;
    cout	<<	"ENTRA	TEXT	ACABAT	EN	#:"	<<	endl;
    string	s;	cin	>>	s;
    while	(	s!="#")	{c.encua(s);	cin	>>	s;	}
    CuaString	c1(c);		//	constructor	copia
    CuaString	c2;
    c2	=	c1;				//	assignació
    cout	<<	"TEXT	1:"	<<	endl;
    while	(!c.buida())	{	cout	<<	c.primer()	<<	"	";	c.desencua();	}
    cout	<<	endl;
    cout	<<	"TEXT	2:"	<<	endl;
    while	(!c1.buida())	{	cout	<<	c1.primer()	<<	"	";	c1.desencua();	}
    cout	<<	endl;
    cout	<<	"TEXT	3:"	<<	endl;
    while	(!c2.buida())	{	cout	<<	c2.primer()	<<	"	";	c2.desencua();	}
    cout	<<	endl;
    return	0;
}
