#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <iostream>

//Ana Carolina Coronel 
//A00838713

class Funciones {

public: 
// Funcion Suma Iterativa
// O(n)  porque es lineal y usa un ciclo for
    long sumaIterativa(int n){
        long acum=0; 
        for (int i = 1; i <= n; i++) {
            acum += i;
        }
        return acum;
    }
// Funcion Suma Recursiva
// O(n)  porque de igual manera se llama a la función varias veces
    long sumaRecursiva(int n) {
        if (n <= 1) {
            return 1;
        } else {
            return n + sumaRecursiva(n - 1);
        }
    }

// Funcion  Suma Directa
// O(1)  porque   es una fórmula directa
    long sumaDirecta(int n) {
            if (n <= 0) {
                return 0;
            }
            return n * (n + 1) / 2;
    }
    };
    #endif