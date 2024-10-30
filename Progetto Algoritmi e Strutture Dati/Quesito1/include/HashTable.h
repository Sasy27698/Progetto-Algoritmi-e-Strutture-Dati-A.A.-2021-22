#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "Mylibrary.h"
#include "Nodo.h"
class HashTable
{
    private:
            int dim;
            vector<Nodo *>*T;
            int hashFunction(int k);

    public:
        HashTable(int n);
        virtual ~HashTable();
        void hash_insert(int key);
        Nodo * get_cella(int x);
};


#endif // HASHTABLE_H
