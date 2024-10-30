#include "Nodo.h"

NodoLL::NodoLL(Nodo *nodo)
{
    this->nodo = nodo;
    this->next=nullptr;
    this->bottom=this;
};
NodoLL::~NodoLL()
{
    delete next; delete bottom;
};
void NodoLL::push(Nodo *nodo){
    if (this->next == nullptr){
        this->next = new NodoLL(nodo);
        this->bottom = this->next;
    }
    else{
        this->bottom->setNext(new NodoLL(nodo));
        this->bottom = this->bottom->getNext();
    }
};
void NodoLL::setNext(NodoLL *next)
{
    this->next = next;
};
NodoLL *NodoLL::getNext()
{
    return this->next;
};
void NodoLL::removeNext()
{
    this->next=nullptr;
};
Nodo *NodoLL::getNodo()
{
    return nodo;
};
NodoLL *NodoLL::getBottom()
{
    return this->bottom;
};
void NodoLL::setBottom(NodoLL *bottom)
{
    this->bottom=bottom;
};
