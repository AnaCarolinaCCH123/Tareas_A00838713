// Ana Carolina Coronel 
// A00838713
// Tarea 2: Algoritmos Busquedas y Ordenamiento

#ifndef SORTS_H_
#define SORTS_H_

#include <iostream>
#include <vector>

template <class T>
class Sorts {
public:

    void ordenaSeleccion(std::vector<T> &v) const;
    void ordenaBurbuja(std::vector<T> &v) const;
    void ordenaMerge(std::vector<T> &v) const;
    
    int busqSecuencial(const std::vector<T> &arr, T val) const;
    int busqBinaria(const std::vector<T> &arr, T val) const;

private:
    void swap(std::vector<T> &v, int i, int j) const;

    void mergeSplit(std::vector<T> &v, std::vector<T> &tmp, int left, int right) const;
    void mergeArray(std::vector<T> &A, std::vector<T> &B, int low, int mid, int high) const;

    int bs_ext(const std::vector<T> &arr, int low, int high, T val) const; 
};

// Swap para cambiar valores en un vector
template <class T>
void Sorts<T>::swap(std::vector<T> &v, int i, int j) const {
    T aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

// Selection Sort
// O(n^2)
template <class T>
void Sorts<T>::ordenaSeleccion(std::vector<T> &v) const {

    int pos;

    for (int i = v.size() - 1; i > 0; i--) {
        pos = 0;
        for (int j = 1; j <= i; j++) {
            if (v[j] > v[pos]) {
                pos = j;
            }
        }
        if (pos != i) {
            swap(v, i, pos);
        }
    }
}

// Bubble Sort
//O(n^2)
template <class T>
void Sorts<T>::ordenaBurbuja(std::vector<T> &v) const {
    for (int i = v.size() - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (v[j] > v[j + 1]) {
                swap(v, j, j + 1);
            }
        }
    }
}

// Merge Sort
//O(n log(n))
template <class T>
void Sorts<T>::ordenaMerge(std::vector<T> &v) const {
    std::vector<T> tmp(v.size());
    mergeSplit(v, tmp, 0, v.size() - 1);
}

// Merge Sort - Funcion Merge Split  
template <class T>
void Sorts<T>::mergeSplit(std::vector<T> &A, std::vector<T> &B, int low, int high) const {
    if ((high - low) < 1) {
        return;
    }

    int mid = (high + low) / 2;
    mergeSplit(A, B, low, mid);
    mergeSplit(A, B, mid + 1, high);
    mergeArray(A, B, low, mid, high);
}

// Merge Array
template <class T>
void Sorts<T>::mergeArray(std::vector<T> &A, std::vector<T> &B, int low, int mid, int high) const {
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high) {
        if (A[i] < A[j]) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }
    while (i <= mid) {
        B[k++] = A[i++];
    }
    while (j <= high) {
        B[k++] = A[j++];
    }
    for (i = low; i <= high; i++) {
        A[i] = B[i];
    }
}

// Busqueda Secuencial
template <class T>
int Sorts<T>::busqSecuencial(const std::vector<T> &arr, T val) const {
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] == val) {
            return i;
        }
    }
    return -1;
}

// Busqueda Binaria
////O(n log(n))
template <class T>
int Sorts<T>::bs_ext(const std::vector<T> &arr, int low, int high, T val) const {
    
    int mid;
    
    if (low <= high) {
        mid = (high + low) / 2;
        if (val == arr[mid]) {
            return mid;
        } else if (val < arr[mid]) {
            return bs_ext(arr, low, mid - 1, val);
        } else {
            return bs_ext(arr, mid + 1, high, val);
        }
    }
    return -1;

}
// Busqueda binaria 
template <class T>
int Sorts<T>::busqBinaria(const std::vector<T> &arr, T val) const {
    return bs_ext(arr, 0, arr.size() - 1, val);  
}

#endif  
