#include "grafo.h"
#include "nodo.h"
#include "vertice.h"

#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int main() {
    Grafo<string> myGrafo;//crea un oggetto che conterrà nodi con etichette di tipo string
    
//crea 6 vertici(a,b,c..), ciascuna con un'etichetta(A,B..)rappresentano nodi del grafo
    Vertice<string> a("A");
    Vertice<string> b("B");
    Vertice<string> c("C");
    Vertice<string> d("D");
    Vertice<string> e("E");
    Vertice<string> f("F");
    
//ogni nodo contiene un vertice e una lista di adiacenza
//addnodo... crea un nodocon il vertice "a" e lo aggiunge al grafo
    myGrafo.addNodo(Nodo<string>(&a));
    myGrafo.addNodo(Nodo<string>(&b));
    myGrafo.addNodo(Nodo<string>(&c));
    myGrafo.addNodo(Nodo<string>(&d));
    myGrafo.addNodo(Nodo<string>(&e));
    myGrafo.addNodo(Nodo<string>(&f));

//il grafo ora ha 6 nodi isolati(non ancora collegati tra loro)
    
//connette i nodi tra loro creando archi diretti
//addArco.. aggiunge un arco dal nodo i esimo

    myGrafo.addArco(0, &b);
    myGrafo.addArco(0, &e);
    myGrafo.addArco(0, &c);
    myGrafo.addArco(0, &d);
    myGrafo.addArco(0, &e);
    myGrafo.addArco(0, &f);
    
    queue<Vertice<string>*> q;
    q.push(&a);
    myGrafo.bfs(&a);
    
    cout << endl << "BFS" <<endl;
    cout << myGrafo << endl;
    
    return 0;

}
