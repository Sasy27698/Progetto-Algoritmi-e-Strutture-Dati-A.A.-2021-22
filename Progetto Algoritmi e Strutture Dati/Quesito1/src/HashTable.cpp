#include "HashTable.h"

HashTable::HashTable(int n)
{
    this->dim=n;
    T=new vector<Nodo *>[dim];
}

HashTable::~HashTable()
{
    delete []T;
}
int HashTable::hashFunction(int k)
{
    return (k%dim);
}
void HashTable::hash_insert(int key) {
    int i = hashFunction(key);
    T[i].push_back(new Nodo(key));
}
Nodo *HashTable::get_cella(int x)
{
    int i = hashFunction(x);
    return T[i].front();
}
