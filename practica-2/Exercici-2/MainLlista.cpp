#include <iostream>
#include <cstdlib>

#include "Llista.h"
#include "Posicio.h"

using namespace std;


int main(){
    Llista<string> l1;
    Posicio<string> p0 (new NodeLlista<string>("node"));
    Posicio<string> p1(new NodeLlista<string>("node2"));
    Posicio<string> p2(new NodeLlista<string>("node2"));



    l1.inserirDespres(p0, "node1");

    l1.inserirDespres(p1,"Node-2");

    l1.inserirAbans(p0, "node1");

    l1.inserirAbans(p1,"Node-2");

  //Llista<string> l2(l1);
 
  

  return 0;
}