/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: mariasalamo
 *
 * Created on 24 de febrero de 2016, 11:43
 */

#include <cstdlib>
#include <iostream>

#include "Complexe.h"

using namespace std;

/*
 * 
 */
int main() {

    Complexe<float> c(2.5, 3.2);
    cout << "Part real " << c.real() << endl; 
    cout << "Part imaginaria " << c.imaginari() << endl; 
    
    Complexe<int> c2(2.5, 3.5);
    cout << "Part real " << c2.real() << endl; 
    cout << "Part imaginaria " << c2.imaginari() << endl; 
    
    Complexe<int> c3(1, 2);
    cout << "Part real " << c3.real() << endl; 
    cout << "Part imaginaria " << c3.imaginari() << endl; 
    
    
     Complexe<double> c4(12.54, 22.31);
    cout << "Part real " << c4.real() << endl; 
    cout << "Part  imaginaria " << c4.imaginari() << endl; 
    return 0;
}

