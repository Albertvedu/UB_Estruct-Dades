#include <iostream>
#include "CuaStatica.h"
using namespace std;

int main(){

    CuaStatica q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.print();
    q.dequeue();
    q.print();
    q.dequeue();
    q.dequeue();
    q.print();

    try{
        q.dequeue();
    }catch( string e){
        cout << e << endl;
    }
    cout << "final " << endl;
};