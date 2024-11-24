//Ana Carolina Coronel
//A00838713
//Tarea 4: Listas doblemente ligadas 

#ifndef DLIST_H
#define DLIST_H

#include <sstream>
#include <string>

// Declaración adelantada
template <class T> class DList;

template <class T>
class DLink {
private:
    T value;
    DLink<T> *previous;
    DLink<T> *next;

    DLink(T);
    DLink(T, DLink<T>*, DLink<T>*);
    DLink(const DLink<T>&);

    friend class DList<T>;
};

// Implementación de DLink
template <class T>
DLink<T>::DLink(T val) : value(val), previous(nullptr), next(nullptr) {}

template <class T>
DLink<T>::DLink(T val, DLink<T> *prev, DLink<T> *nxt)
    : value(val), previous(prev), next(nxt) {}

template <class T>
DLink<T>::DLink(const DLink<T> &source)
    : value(source.value), previous(source.previous), next(source.next) {}

template <class T>
class DList {
private:
    DLink<T> *head;
    DLink<T> *tail;
    int size;

public:
    DList();
    DList(const DList<T>&);
    ~DList();
 	std::string toStringForward() const;
    std::string toStringBackward() const;
    bool empty() const;
    void clear();
    void update(int, T);
    void deleteAt(int);
    void insertion(T);
    T search(T);
   
};


template <class T>
DList<T>::DList() : head(nullptr), tail(nullptr), size(0) {}

template <class T>
DList<T>::DList(const DList<T> &source) : head(nullptr), tail(nullptr), size(0) {
    DLink<T> *p, *q;
    if (!source.empty()) {
        p = source.head;
        head = new DLink<T>(p->value);
        q = head;

        p = p->next;
        while (p != nullptr) {
            q->next = new DLink<T>(p->value, q, nullptr);
            q = q->next;
            p = p->next;
        }
        tail = q;
        size = source.size;
    }
}

template <class T>
DList<T>::~DList() {
    clear();
}

template <class T>
void DList<T>::clear() {
    DLink<T> *p, *q;
    p = head;
    while (p != nullptr) {
        q = p->next;
        delete p;
        p = q;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <class T>
bool DList<T>::empty() const {
    return head == nullptr;
}

//Insertion
template <class T>
void DList<T>::insertion(T val) {
    DLink<T> *newLink = new DLink<T>(val);
    if (empty()) {
        head = newLink;
        tail = newLink;
    } else {
        tail->next = newLink;
        newLink->previous = tail;
        tail = newLink;
    }
    size++;
}

//Search
template <class T>
T DList<T>::search(T val) {
    DLink<T> *current = head;
    int index = 0;
    while (current) {
        if (current->value == val) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

//Update
template <class T>
void DList<T>::update(int index, T val) {
    DLink<T> *current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    current->value = val;
}

//Delete Position
template <class T>
void DList<T>::deleteAt(int index) {
    DLink<T> *p;
    if (index == 0) {
        p = head;
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            head->previous = nullptr;
        }
        delete p;
    } else {
        p = head;
        for (int i = 0; i < index; i++) {
            p = p->next;
        }
        p->previous->next = p->next;
        if (p->next != nullptr) {
            p->next->previous = p->previous;
        } else {
            tail = p->previous;
        }
        delete p;
    }
    size--;
}

template <class T>
std::string DList<T>::toStringForward() const {
    std::stringstream aux;
    DLink<T> *p = head;
    aux << "[";
    while (p != nullptr) {
        aux << p->value;
        if (p->next != nullptr) {
            aux << ", ";
        }
        p = p->next;
    }
    aux << "]";
    return aux.str();
}

template <class T>
std::string DList<T>::toStringBackward() const {
    std::stringstream aux;
    DLink<T> *p = tail;
    aux << "[";
    while (p != nullptr) {
        aux << p->value;
        if (p->previous != nullptr) {
            aux << ", ";
        }
        p = p->previous;
    }
    aux << "]";
    return aux.str();
}

#endif
