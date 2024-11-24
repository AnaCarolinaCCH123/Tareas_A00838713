
#ifndef LIST_H_
#define LIST_H_

#include <string>
#include <sstream>

template <class T> class List;

template <class T>
class Link {
private:
    Link(T val);
    Link(T val, Link<T>*);
    Link(const Link<T>&);

    T value;
    Link<T>* next;


    friend class List<T>; 
};


template <class T>
Link<T>::Link(T val) : value(val), next(0) {}

template <class T>
Link<T>::Link(T val, Link<T>* nxt) : value(val), next(nxt) {}

template <class T>
Link<T>::Link(const Link<T>& source) : value(source.value), next(source.next) {}

template <class T>
class List {
public:
    List();
    List(const List<T>&);
    ~List();

    void insertion(T val);
    int search(T val) const;
    void update(int index, T newValue);
    T deleteAt(int index);
    std::string toString() const;
    void clear();

private:
    Link<T>* head;
    int size;

};


template <class T>
List<T>::List() : head(0), size(0) {}

template <class T>
List<T>::~List() {
    clear();
}

//Insertion 
template <class T>
void List<T>::insertion(T val) {
    Link<T>* newLink = new Link<T>(val);
    if (newLink == 0) {
        return; 
    }

    if (head == 0) {
        head = newLink;
    } else {
        Link<T>* p = head;
        while (p->next != 0) {
            p = p->next;
        }
        p->next = newLink;
    }
    size++;
}

//Search
template <class T>
int List<T>::search(T val) const {
    Link<T>* p = head;
    int pos = 0;

    while (p != 0) {

        if (p->value == val) {
            return pos; 
        }
        p = p->next;
        pos++;
    }
    return -1;
}

//Update
template <class T>
void List<T>::update(int index, T newValue) {
    if (index < 0 || index >= size) {
        return; 
    }

    Link<T>* p = head;
    for (int i = 0; i < index; i++) {
        p = p->next;
    }
    p->value = newValue;
}

//deleteAt
template <class T>
T List<T>::deleteAt(int index) {
    if (index < 0 || index >= size) {
        return T(); 
    }

    Link<T>* p = head;
    T value;

    if (index == 0) {
        head = p->next;
        value = p->value;
        delete p;
    } else {
        Link<T>* prev = 0;
        for (int i = 0; i < index; i++) {
            prev = p;
            p = p->next;
        }
        prev->next = p->next;
        value = p->value;
        delete p;
    }
    size--;
    return value;
}

//TO STRING 
template <class T>
std::string List<T>::toString() const {
    std::stringstream aux;
    Link<T>* p = head;

    aux << "[";
    while (p != 0) {
        aux << p->value;
        if (p->next != 0) {
            aux << ", ";
        }
        p = p->next;
    }
    aux << "]";
    return aux.str();
}

//CLEAR
template <class T>
void List<T>::clear() {
    while (head != 0) {
        Link<T>* temp = head;
        head = head->next;
        delete temp;
    }
    size = 0;
}

#endif 