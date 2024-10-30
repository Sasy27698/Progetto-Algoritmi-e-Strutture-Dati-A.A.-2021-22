#ifndef NODO_H
#define NODO_H
#include "Mylibrary.h"
class Nodo;

class NodoLL
{
    private:
        Nodo *nodo;
        NodoLL *next;
        NodoLL *bottom;

    public:
        NodoLL(Nodo *nodo);
        virtual ~NodoLL();
        void setNext(NodoLL *next);
        NodoLL *getNext();
        void removeNext();
        Nodo *getNodo();
        NodoLL* getBottom();
        void setBottom(NodoLL *bottom);
        void push(Nodo* nodo);

};

class Nodo
{
    public:
        Nodo(int val);
        virtual ~Nodo();
        void setValue(int val);
        int getValue();
        void addEdge(Nodo *nodo);
        void printAdj();
        bool findEdge(int j);
        void removeEdge(int j);
        void setD(int time);
        int getD();
        void setF(int time);
        int getF();
        void setcolor(short color);
        short getcolor();
        void setparent(Nodo *x);
        Nodo *getparent();
        NodoLL *getadj();

    private:
        NodoLL *adj = nullptr;
        int val;
        short color;
        Nodo *p;
        int D;
        int F;
};

#endif // NODO_H

