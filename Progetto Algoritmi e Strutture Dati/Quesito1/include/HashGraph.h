#ifndef HASHGRAPH_H
#define HASHGRAPH_H
#include "Mylibrary.h"
#include "HashTable.h"

class HashGraph
{
    private:
        int dim;
        int time;
        HashTable *hasht;
    public:
        HashGraph(int n);
        virtual ~HashGraph();
        void AddEdge(int i,int j);
        void RemoveEdge(int i,int j);
        bool FindEdge(int i,int j);
        void DFS(int s);
        void DFS_Visit(Nodo *u);
        void filltable(int n);
        void hash_display();
        int GetTime();
        void SetTime(int time);
};


#endif // HASHGRAPH_H
