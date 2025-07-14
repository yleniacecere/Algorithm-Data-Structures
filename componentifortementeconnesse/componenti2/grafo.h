#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <list>
#include <queue>

#include "nodo.h"
#include "vertice.h"

using namespace std;

template <typename T>
class Grafo {
  private:
    vector<Nodo<T>> grafo;
    list<Vertice<T>*> getListAdj(Vertice<T>* vertice);
    
    int time;
    queue<T> myQueue;
    void dfsVisit(Vertice<T>* vertice);
  public:  
    Grafo() { }
    
    queue<T> getMyQueue(){return this->myQueue;}
    void addNodo(Nodo<T> nodo){grafo.push_back(nodo);}
    void addArco(Vertice<T>* v1,Vertice<T>* v2);
    
    int searchIndirizzo(Vertice<T>* vertice);
    Vertice<T>* getIndirizzoVertice(T value);
    
    void dfs();
    
    friend ostream& operator<<(ostream& out, const Grafo<T>& obj){
      for(auto i: obj.grafo)
        out<<i<<endl;
      return out;
    }
    
    Grafo<T> trasposto();
    void dfsVisit2(Vertice<T>* vertice, vector<T>& componente);
    void trovaSCC();
};
template<typename T>
list<Vertice<T>*>Grafo<T>:: getListAdj(Vertice<T>* vertice){
  for(auto i: grafo){
    if(i.getVertice()== vertice)
      return i.getList();
  }
    return grafo.at(0).getList();
}
template<typename T>
 int Grafo<T>:: searchIndirizzo(Vertice<T>* vertice){
  for(int i=0;i< grafo.size();i++){
    if(grafo.at(i).getVertice()->getValue()==vertice->getValue())
    return i;
  }  
  return -1;
 }
template<typename T>
Vertice<T>* Grafo<T>:: getIndirizzoVertice(T value){
  for(auto i: grafo){
    if(i.getVertice()->getValue()==value)
      return i.getVertice();
  }
    return nullptr;
}
template<typename T>
void Grafo<T>::addArco(Vertice<T>* v1,Vertice<T>* v2){
  int vertice = searchIndirizzo(v1);
  grafo.at(vertice).append(v2);
}
template<typename T>
void Grafo<T>:: dfs(){
  for(auto u: grafo){
    u.getVertice()->setColor(Color::WHITE);
    u.getVertice()->setPredecessore(nullptr);
  }
  time=0;
  
  for(auto u: grafo){
    if(u.getVertice()->getColor()==Color::WHITE)
      dfsVisit(u.getVertice());
  }
}
template<typename T>
void Grafo<T>::dfsVisit(Vertice<T>* vertice){
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
  myQueue.push(vertice->getValue());
}
template<typename T>
Grafo<T> Grafo<T>::trasposto(){
  Grafo<T> GT;
  
  for(auto nodo: grafo){
    Vertice<T>* nuovoVertice= new Vertice<T>(nodo.getVertice()->getValue());
    GT.addNodo(Nodo<T>(nuovoVertice));
  }
  
  for(auto nodo: grafo){
    Vertice<T>* u= nodo.getVertice();
    list<Vertice<T>*> adiacenti= nodo.getList();
    for(auto v: adiacenti){
      Vertice<T>* from= GT.getIndirizzoVertice(v->getValue());
      Vertice<T>* to= GT.getIndirizzoVertice(u->getValue());
      GT.addArco(from, to);
    }
  }
  return GT;
}
template<typename T>
void Grafo<T>:: dfsVisit2(Vertice<T>* vertice, vector<T>& componente){
  vertice->setColor(Color::GREY);
  vertice->setTInizio(time++);
  
  componente.push_back(vertice->getValue());
  
  list<Vertice<T>*> adj=getListAdj(vertice);
  
  for(auto v: adj){
    if(v->getColor()==Color::WHITE){
      v->setPredecessore(vertice);
      dfsVisit2(v, componente);
    }
  }
  vertice->setColor(Color::BLACK);
  vertice->setTFine(time++);
}
template<typename T>
void Grafo<T>::trovaSCC(){
  this->dfs();
  
  Grafo<T> GT= this->trasposto();
  for(auto& nodo:GT.grafo){
    nodo.getVertice()->setColor(Color::WHITE);
    nodo.getVertice()->setPredecessore(nullptr);
  }
  GT.time=0;
  
  cout<<"componenti fortemente connesse :\n";
    while(!this->myQueue.empty()){
      T valore= this->myQueue.front();
      this->myQueue.pop();
      
      Vertice<T>* verticeGT =GT.getIndirizzoVertice(valore);
      
      if(verticeGT->getColor()==Color::WHITE){
        vector<T> componente;
        GT.dfsVisit2(verticeGT,componente);
        
        cout<<"{";
        for(T val: componente)
          cout<<val<<"";
        cout<<"} \n";
      }  
    }
}
#endif
