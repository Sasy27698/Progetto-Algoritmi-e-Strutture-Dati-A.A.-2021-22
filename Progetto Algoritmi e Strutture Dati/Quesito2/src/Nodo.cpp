#include "Nodo.h"

Nodo::Nodo(int val)
{
    this->val=val;
}

Nodo::~Nodo()
{
    delete adj; delete p;
}
void Nodo::addEdge(Nodo *nodo){
    if (adj == nullptr)
        adj = new NodoLL(nodo);
    else{
        adj->push(nodo);
    }
};

void Nodo::printAdj(){
    NodoLL* tmp = adj;
    while(tmp!=nullptr){
        cout << " --> " << tmp->getNodo()->getValue();
        tmp = tmp->getNext();
    }
    cout << endl;
};

bool Nodo::findEdge(int j){
    NodoLL* tmp = adj;
    while (tmp !=nullptr && tmp->getNodo()->getValue()!=j){
        tmp = tmp->getNext();
    }
    if(tmp!=nullptr){
        return true;
    }
    else
        return false;
};

void Nodo::removeEdge(int i){
    NodoLL* tmp = adj;
    bool eliminato=false;
    if(adj->getNodo()->getValue() == i){
        if(adj->getBottom()->getNodo()->getValue() == adj->getNodo()->getValue())
            adj = nullptr;
        else{
            adj->getNext()->setBottom(adj->getBottom());
            adj = adj->getNext();
        }
    }
    else{
    while(eliminato==false){
        if(tmp->getNext()->getNodo()->getValue() == i){
            if(adj->getBottom()->getNodo()->getValue() == tmp->getNext()->getNodo()->getValue()){
                adj->setBottom(tmp);
                tmp->setNext(nullptr);
            }
            else
                tmp->setNext(tmp->getNext()->getNext());
           eliminato = true;
        }
        else{
            tmp = tmp->getNext();
        }

    }
    }

};
void Nodo::setValue(int val)
{
    this->val = val;
};
int Nodo::getValue()
{
    return this->val;
};
NodoLL *Nodo::getadj()
{
    return this->adj;
};
void Nodo::setcolor(short color)
{
    this->color=color;
};
short Nodo::getcolor()
{
    return color;
};
void Nodo::setparent(Nodo *x)
{
    this->p=x;
};
Nodo* Nodo::getparent()
{
    return p;
};
void Nodo::setD(int time)
{
    this->D=time;
};

int Nodo::getD()
{
    return D;
};

void Nodo::setF(int time)
{
    this->F=time;
};

int Nodo::getF()
{
    return this->F;
};
