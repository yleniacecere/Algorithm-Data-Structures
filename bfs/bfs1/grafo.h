#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include "vertice.h"
#include "nodo.h"

using namespace std;

template <typename T>
class Grafo {
    private:
      vector<Nodo<T>> grafo;//contiene nodi del grafo(un nodo contiene un vertice e una lista)
      list<Vertice<T>*> getListAdj(Vertice<T>* vertice);//restituisce lista
    public:
      Grafo() {}//inizializza grafo vuoto
      
      void addNodo(Nodo<T> nodo){grafo.push_back(nodo);}//aggiunge un nodo al grafo
      void addArco(int i, Vertice<T>* vertice){grafo.at(i).append(vertice);}//aggiunge un arco tra il nodo in posizione i e un altro vertice
      
      void bfs(Vertice<T>* vertice);//esegue la bfs
      
      friend ostream& operator<<(ostream& out, Grafo<T>& obj){ //stampa tutti i nodi del grafo
          for(auto i: obj.grafo)
            out << i << endl;
          return out;
      }
};

//cerca il nodo che contiene vertice nel grafo, se lo trova ritorna la sua lista altrimenti ritorna la lista del primo nodo
template<typename T>
list<Vertice<T>*>Grafo<T>::getListAdj(Vertice<T>* vertice){
    for(auto i:grafo){
      if(i.getVertice() == vertice)
        return i.getList();
    }
    return grafo.at(0).getList();
}
template <typename T> //la bfs parte dal vertice sorgente
void Grafo<T>::bfs(Vertice<T>* sorgente) {
    for(auto u : grafo) {
        u.getVertice()->setColor(Color::WHITE);
        u.getVertice()->setPredecessore(nullptr);
        u.getVertice()->setDistanza(UINT16_MAX);
    }
    sorgente->setColor(Color::GRAY);
    sorgente->setPredecessore(nullptr);
    sorgente->setDistanza(0);

    queue<Vertice<T>*> q;

    q.push(sorgente);
     
     while(!q.empty()) {
        auto u = q.front(); //estrae vertice dalla coda
        q.pop();
        list<Vertice<T>*> adj = getListAdj(u);
        for(auto v : adj) {
            if(v->getColor() == Color::WHITE) { //visita i vicini
                v->setColor(Color::GRAY);
                v->setPredecessore(u);
                v->setDistanza(u->getDistanza()+1);
                q.push(v);
            }
        }
        u->setColor(Color::BLACK);
    }
}



#endif //GRAFO_H


