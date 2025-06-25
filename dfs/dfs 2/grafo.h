#ifndef GRAFO_H
#define GRAFO_H

#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include <cstdint>
#include "vertice.h"
#include "nodo.h"

using namespace std;

template<typename T>
class Grafo{
  private:
    vector<Nodo<T>> grafo;
    list<Vertice<T>*> getListAdj(Vertice<T>* vertice);
    
    int time;
    void dfsVisit(Vertice<T>* vertice);
  public:
    Grafo() {}
    
    void dfs();
    
    void addNodo(Nodo<T> nodo){grafo.push_back(nodo);}
    void addArco(int i, Vertice<T>* vertice){grafo.at(i).append(vertice);}
    
    friend ostream& operator<<(ostream& out, Grafo<T>& obj){
      for(auto i: obj.grafo){
        out<<i<<endl;
      }
      return out;
    }
    

};
template<typename T>
void Grafo<T>::dfs(){
  for(auto u: grafo){
    u.getVertice()->setColor(Color::WHITE);
    u.getVertice()->setPredecessore(nullptr);
    time=0;
  }
  for(auto u: grafo){
    if(u.getVertice()->getColor()== Color::WHITE){
      dfsVisit(u.getVertice());
    }
  }
}
template<typename T>
void Grafo<T>:: dfsVisit(Vertice<T>* vertice){
  vertice->setColor(Color::GREY);
  vertice->setTInizio(time++);
  list<Vertice<T>*> adj=getListAdj(vertice);
  for(auto v: adj){
    if(v->getColor()==Color::WHITE){
      v->setPredecessore(vertice);
      dfsVisit(v);
    }
  }
  vertice->setColor(Color::BLACK);
  vertice->setTFine(time++);
}

template<typename T>
list<Vertice<T>*> Grafo<T>::getListAdj(Vertice<T>* vertice){
 for(auto i: grafo){
  if(i.getVertice()== vertice){
    return i.getList();
  }
  
 }
  return grafo.at(0).getList();
}
#endif
