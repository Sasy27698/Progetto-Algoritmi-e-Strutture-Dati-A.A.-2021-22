#include "Mylibrary.h"
#include "HashGraph.h"
int main()
{
    ifstream file;
    file.open("input.txt");
    string temp;

    int n_nodi,num_archi,m;
    int N,M,n;
    getline(file,temp,' ');
    n_nodi = stoi(temp);
    HashGraph g(n_nodi+1);
    if(n_nodi<0 || n_nodi>1000){
            cout << "Errore il file supera il limite consentito" << endl;
            return 0;
    }
    else{
        for(n=0;n<n_nodi;n++)
        {
            g.filltable(n);
        }
    }
    getline(file,temp);
    num_archi = stoi(temp);
    if(num_archi<0 || num_archi>1000){
        cout << "Errore (num_archi<0 || num_archi>10000)" << endl;
        return 0;
    }
    for(m=0;m<num_archi;m++)
    {
        getline(file,temp,' ');
        N = stoi(temp);
        getline(file,temp);
        M = stoi(temp);
        g.AddEdge(N,M);
    }
    g.hash_display();
    int operazione,i,j;
    cout << endl << "******QUESITO 1*******" << endl;
    cout << "Menu" << endl;
    cout << "[1]Aggiunta di un edge" << endl;
    cout << "[2]Rimozione di un edge" << endl;
    cout << "[3]Cerca un edge" << endl;
    cout << "[4]Stampa del DFS" << endl;
    cout << "[5]Esci" << endl;
    cout << "*************" << endl;

    while(1)
    {
        cin >> operazione;
        switch(operazione)
        {
            case 1:
                cout << "Inserisci il nodo sorgente-> ";
                cin >> i;
                if(i>n_nodi) {
                    cout << "ERRORE IL VALORE SUPERA LA GRANDEZZA DELLA TABELLA" << endl;
                    break;
                }
                cout << "Inserisci il nodo destinazione-> ";
                cin >> j;
                g.AddEdge(i,j);
                g.hash_display();
                break;

            case 2:
                cout << "Inserisci il nodo sorgente-> ";
                cin >> i;
                if(i>n_nodi)
                {
                    cout << "ERRORE IL VALORE SUPERA LA GRANDEZZA DELLA TABELLA" << endl;
                    break;
                }
                cout << "Inserisci il nodo destinazione-> ";
                cin >> j;
                g.RemoveEdge(i,j);
                g.hash_display();
                break;

            case 3:
                cout << "Inserisci il nodo sorgente-> ";
                cin >> i;
                if(i>n_nodi)
                {
                    cout << "ERRORE IL VALORE SUPERA LA GRANDEZZA DELLA TABELLA" << endl;
                    break;
                }
                cout << "Inserisci il nodo destinazione-> ";
                cin >> j;
                if(g.FindEdge(i,j))
                    cout << "Edge Trovato" << endl;
                else
                    cout << "Edge Non trovato" << endl;
                break;

            case 4:
                cout << "Sorgente:" << endl;
                int s;
                cin >> s;
                if(s>n_nodi || s<0)
                    cout << "Error: s>N o s<0!!";
                else
                    g.DFS(s);
                break;
            case 5:
                cout << "Arrivederci!";
                exit(0);

            default:
                cout << "Input non valido, riprova!" << endl;
                break;
        }

    }
	return 0;
}
