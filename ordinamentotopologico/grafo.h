#ifndef GRAFO_H 
#define GRAFO_H

#include<iostream>
#include <vector>
#include<list>
#include"vertice.h"
#include<queue>
#include<stack>

using namespace std;
template<typename T>
class Grafo{
  private:
    vector<Nodo<T>> grafo;
    list<Vertice<T>*> getListAdj(Vertice<T>* vertice);
    
    void dfsVisit(Vertice<T>* vertice);
    int time;
    stack<Vertice<T>*>L;
    int cicli;
  public:
    Grafo(){ }
    void addNodo(Nodo<T> nodo){grafo.push_back(nodo);}
    void addArco(Vertice<T>* v1,Vertice<T>* v2);
    
    int searchIndirizzo(Vertice<T>* vertice);
    Vertice<T>* getIndirizzoVertice(T value);
    
    bool dfs();
    
    void ordTopologico();
    void printOrdTopologico();
    
    friend ostream& operator<<(ostream& out,const Grafo<T>& obj){
  for(auto i:obj.grafo)
    out<<i<<endl;
  return out;
}
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
 int Grafo<T>::searchIndirizzo(Vertice<T>* vertice){
  for(int i=0;i<grafo.size();i++){
    if(this->grafo.at(i).getVertice()->getValue()==vertice->getValue())
      return i;
  }
  return -1;
 }
 template<typename T>
 Vertice<T>*Grafo<T>::getIndirizzoVertice(T value){
  for(auto i:grafo){
    if(i.getVertice()->getValue()==value)
      return i.getVertice();
  }
  return nullptr;
 }
 template<typename T>
void Grafo<T>::addArco(Vertice<T>* v1,Vertice<T>* v2){
  int vertice= searchIndirizzo(v1);
  grafo.at(vertice).append(v2);
}
template<typename T>
void Grafo<T>::dfsVisit(Vertice<T>* u){
  u->setColor(Color::GREY);
  u->setTInizio(time ++);
  
  auto adj=getListAdj(u);
  for(auto v:adj){
    if(v->getColor()==Color::WHITE){
      v->setPredecessore(nullptr);
        dfsVisit(v);
    }else if(v->getColor()==Color::GREY){
      cicli++;
    }
  }
  u->setColor(Color::BLACK);
  u->setTFine(time++);
  L.push(u);
}
template<typename T>
bool Grafo<T>::dfs(){
  cicli=0;
  for(auto u:grafo){
    u.getVertice()->setColor(Color::WHITE);
    u.getVertice()->setPredecessore(nullptr);
  }
  time=0;
  for(auto u:grafo){
    if(u.getVertice()->getColor()==Color::WHITE)
      dfsVisit(u.getVertice());
  }
  if(cicli>0)
    return true;
  else
    return false;
}
template<typename T>
void Grafo<T>::ordTopologico(){
  if(!dfs()){
    cout<<"ordinamento topologico"<<endl;
    printOrdTopologico();
  }else
    cout<<"sono presenti cicli"<<endl;
}
template<typename T>
void Grafo<T>::printOrdTopologico(){
  while(!L.empty()){
    cout<<*L.top()<<"--> ";
    L.pop();
  }
  cout<<"NULL";
}
#endif
