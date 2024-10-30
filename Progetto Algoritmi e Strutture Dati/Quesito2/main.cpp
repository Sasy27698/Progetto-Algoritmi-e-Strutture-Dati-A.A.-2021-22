#include "Mylibrary.h"
#include "Grafo.h"
int MinCostruzione(Grafo g);
int main()
{
    ifstream file;
    file.open("input.txt");
    string temp;

    int n_nodi,num_archi,p;
    int N,P,n;
    getline(file,temp,' ');
    n_nodi = stoi(temp);
    Grafo g(n_nodi+1);
    if(n_nodi<1 || n_nodi>1000){
            cout << "Errore il file supera il limite consentito" << endl;
            return 0;
    }
    else{
        for(n=1;n<n_nodi+1;n++)
        {
            g.fillgraph(n);
        }
    }
    getline(file,temp);
    num_archi = stoi(temp);
    if(num_archi<0 || num_archi>10000){
        cout << "Errore (num_archi<0 || num_archi>10000)" << endl;
        return 0;
    }
    for(p=0;p<num_archi;p++)
    {
        getline(file,temp,' ');
        N = stoi(temp);
        getline(file,temp);
        P = stoi(temp);
        g.getnodo(N)->addEdge(g.getnodo(P));
    }
    g.DFS();
    cout << endl << "Il risultato e'->" << MinCostruzione(g) << endl;
	return 0;
}
int MinCostruzione(Grafo g)
{
    int mincounter=0;
    for(int i=1;i<g.getV()+1;i++)
    {
        {
            if(g.getnodo(i)->getparent()==nullptr)
            {
                mincounter++;
            }
        }
    }
    cout << "Per portare l'acqua nelle citta' bisogna costruire nei condotti" << endl;
    for(int i=1;i<g.getV()+1;i++)
    {
            if(g.getnodo(i)->getparent()==nullptr)
            {
                cout << "[" << g.getnodo(0)->getValue() << "]-" << "[" << g.getnodo(i)->getValue() << "]" << endl;
            }
    }
    return mincounter;
}
