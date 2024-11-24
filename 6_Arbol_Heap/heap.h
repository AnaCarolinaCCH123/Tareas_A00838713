//Ana Carolina Coronel 
//A00838713
//Tarea 6:Heap


#ifndef HEAP_H_   
#define HEAP_H_

#include <string>
#include <sstream>
#include <iostream>

template <class T>
class Heap {
private:
    T *data;
    unsigned int cap;
    unsigned int count;     
    unsigned int parent(unsigned int) const;
    unsigned int left(unsigned int) const;
    unsigned int right(unsigned int) const;
    void heapify(unsigned int);
    void swap(unsigned int, unsigned int);

public:
    Heap(unsigned int);
    ~Heap();
    bool empty() const;
    bool full() const;
    void push(T);
    T pop();
    T top() const;
    unsigned int size() const;  
    void clear();
    std::string toString() const;
};

// Constructor
template <class T>
Heap<T>::Heap(unsigned int sze) : cap(sze), count(0) {
    data = new T[cap];
}

// Destructor
template <class T>
Heap<T>::~Heap() {
    delete[] data;
}

// Verifica si el heap está vacío
template <class T>
bool Heap<T>::empty() const {
    return (count == 0);
}

// Verifica si el heap está lleno
template <class T>
bool Heap<T>::full() const {
    return (count == cap);
}
//Parent
template <class T>
unsigned int Heap<T>::parent(unsigned int pos) const {
    return (pos - 1) / 2;
}
//Izquierdo
template <class T>
unsigned int Heap<T>::left(unsigned int pos) const {
    return (2 * pos) + 1;
}
//Derecho
template <class T>
unsigned int Heap<T>::right(unsigned int pos) const {
    return (2 * pos) + 2;
}

//Swap
template <class T>
void Heap<T>::swap(unsigned int i, unsigned int j) {
    T aux = data[i];
    data[i] = data[j];
    data[j] = aux;
}

// Heapify 
template <class T>
void Heap<T>::heapify(unsigned int pos) {
    unsigned int le = left(pos);
    unsigned int ri = right(pos);
    unsigned int min = pos;
    if (le < count && data[le] < data[min]) {
        min = le;
    }
    if (ri < count && data[ri] < data[min]) {
        min = ri;
    }
    if (min != pos) {
        swap(pos, min);
        heapify(min);
    }
}

//Push
template <class T>
void Heap<T>::push(T val) {
    
    unsigned int pos = count++;
    while (pos > 0 && val < data[parent(pos)]) {
        data[pos] = data[parent(pos)];
        pos = parent(pos);
    }
    data[pos] = val;
}

//Pop
template <class T>
T Heap<T>::pop() {
    T aux = data[0];
    data[0] = data[--count];
    heapify(0);
    return aux;
}
// Limpia 
template <class T>
void Heap<T>::clear() {
    count = 0;
}
//Top
template <class T>
T Heap<T>::top() const {
    return data[0];
}

// Size
template <class T>
unsigned int Heap<T>::size() const {
    return count;
}
// To string
template <class T>
std::string Heap<T>::toString() const {
    std::stringstream aux;
    aux << "[";
    for (unsigned int i = 0; i < count; i++) {
        if (i != 0) {
            aux << " ";
        }
        aux << data[i];
    }
    aux << "]";
    return aux.str();
}

#endif 

