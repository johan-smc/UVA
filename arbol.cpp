#include "arbol.h"
#include <iostream>
template<class T>
bool Arbol<T> :: esVacio(){
    if(this->raiz==NULL){
        return true;
    }
    return false;
}
template <class T>
Nodo<T>* Arbol<T>::obtenerRaiz(){
    return this->raiz;
}
template <class T>
void Arbol<T>::fijarRaiz(Nodo<T>* nraiz){
    if(!esVacio()){
        nraiz->desc=raiz->desc;
        nraiz->dato=raiz->dato;
    }
    this->raiz=nraiz;
}
template <class T>
bool Arbol<T>:: insertarNodo(T& padre, T& n){

    return true;
}
template <class T>
Nodo<T>* buscaR(Nodo<T>* actual, T& padre){
    if(actual->dato==padre){
        return actual;
    }
    for(int i=0; i<actual->desc.size();i++){
    actual=actual->desc++;
    return buscaR(actual,padre);
    }
}
