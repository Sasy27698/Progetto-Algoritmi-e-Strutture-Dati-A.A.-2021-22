#include "Grafo.h"

Grafo::Grafo(int n)
{
    this->n=n;
    T=new vector<Nodo *>[n];
}
int Grafo::GetTime()
{
    return this->time;
}

void Grafo::SetTime(int time)
{
    this->time=time;
}
void Grafo::fillgraph(int i)
{
    for(i=0;i<n;i++)
        T[i].push_back(new Nodo(i));
}
Nodo *Grafo::getnodo(int i)
{
    return T[i].front();
}
void Grafo::display(){
    for (int i=1;i<n;i++) {
        cout << i;
        Nodo *x = this->getnodo(i);
        cout << " ADJ LIST: " << x->getValue() << " ";
        x->printAdj();
  }
}
int Grafo::getV()
{
    return T->size();
}
//0 = WHITE             1 = GRAY            2 = BLACK
void Grafo::DFS()
{
    for(int i=0;i<n;i++) {
        Nodo *tmp = this->getnodo(i);
        tmp->setcolor(0);
        tmp->setparent(nullptr);
    }
    SetTime(0);
    for(int i=0;i<n;i++){
        Nodo *tmp = this->getnodo(i);
        if(tmp->getcolor()==0)
            {
                Visita_DFS(tmp);
            }
        }
}
void Grafo::Visita_DFS(Nodo *u)
{
    SetTime(GetTime()+1);
    u->setD(GetTime());
    u->setcolor(1);

    NodoLL * v = u->getadj();
    while(v != nullptr){
        auto color = v->getNodo()->getcolor();
        if(color == 0){
            v->getNodo()->setparent(u);
            Visita_DFS(v->getNodo());
        }
        else if(color==2)
        {
            v->getNodo()->setparent(u);
        }
        v = v->getNext();
    }
    SetTime(GetTime()+1);
    u->setcolor(2);
    u->setF(GetTime());
}

