#include "HashGraph.h"

HashGraph::HashGraph(int n)
{
    this->hasht = new HashTable(n);
    this->dim = n;
}

HashGraph::~HashGraph()
{
    delete hasht;
}
void HashGraph::hash_display(){
    for (int i=0;i<dim;i++) {
        cout << i;
        Nodo *x = hasht->get_cella(i);
        cout << " ADJ LIST: " << x->getValue() << " ";
        x->printAdj();
  }
}
void HashGraph::filltable(int n)
{
    for(n=0;n<dim;n++)
        hasht->hash_insert(n);
}
void HashGraph::AddEdge(int i,int j)
{
    if (i < dim && i >= 0 && j >= 0 && j < dim && i!=j && !(this->FindEdge(i,j))){

        Nodo *nodo_i = hasht->get_cella(i);
        Nodo *nodo_j = hasht->get_cella(j);
        nodo_i->addEdge(nodo_j);
    }
    else
        cout << "Errore inserimento: i e j escono fuori dalle dimensioni (oppure inserito i = j) " << endl;
};

bool HashGraph::FindEdge(int i,int j)
{
    if (i < dim && i >= 0 && j >= 0 && j< dim && i!=j){
        Nodo *tmp= hasht->get_cella(i);
        return tmp->findEdge(j);
    }
    else
        cout << "Errore inserimento [2]: i e j escono fuori dalle dimensioni (oppure inserito i = j) " << endl;
    return false;

};
void HashGraph::RemoveEdge(int i,int j)
{
    if (i < dim && i >= 0 && j >= 0 && j< dim && i!=j){
        Nodo *tmp= hasht->get_cella(i);
        if(tmp->findEdge(j))
            tmp->removeEdge(j);
        else
            cout << "Errore" << endl;
    }
    else
    {
        cout << "Errore inserimento [3]: i e j escono fuori dalle dimensioni (oppure inserito i = j)" << endl;
    }
}
//0 = WHITE             1 = GRAY            2 = BLACK
void HashGraph::DFS(int s)
{
    for(int i=0;i<dim;i++) {
        Nodo *tmp = hasht->get_cella(i);
        tmp->setcolor(0);
        tmp->setparent(nullptr);
    }
    SetTime(0);
    Nodo *u = hasht->get_cella(s);
    cout<<"Nodo sorgente: "<< u->getValue() << endl;
    DFS_Visit(u);

    for(int i=0;i<dim;i++){
        u = hasht->get_cella(i);
        if(u->getcolor() == 0 && u->getValue() != s){
            cout<<"Radice:"<<endl;
            DFS_Visit(u);
        }
    }
}
void HashGraph::DFS_Visit(Nodo *u)
{
    cout << "Nodo:" << u->getValue() << endl;
    SetTime(GetTime()+1);
    u->setD(GetTime());
    u->setcolor(1);

    NodoLL * v = u->getadj();
    while(v != nullptr){
        auto color = v->getNodo()->getcolor();
        if(color == 0){
            v->getNodo()->setparent(u);
            DFS_Visit(v->getNodo());
        }
        v = v->getNext();
    }
    SetTime(GetTime()+1);
    u->setcolor(2);
    u->setF(GetTime());
}

int HashGraph::GetTime()
{
    return this->time;
}

void HashGraph::SetTime(int time)
{
    this->time=time;
}
