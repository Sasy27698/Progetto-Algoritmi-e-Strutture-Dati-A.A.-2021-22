#ifndef GRAFO_H
#define GRAFO_H
#include "MyLibrary.h"
#include "Nodo.h"

class Grafo
{
    private:
        int time;
        int n;
        vector<Nodo *>*T;

    public:
        Grafo(int n);
        void stampa_G();
        void DFS();
        void Visita_DFS(Nodo *u);
        int GetTime();
        void SetTime(int time);
        void fillgraph(int i);
        Nodo *getnodo(int i);
        void display();
        int getV();
        virtual ~Grafo(){}
};


#endif // GRAFO_H
