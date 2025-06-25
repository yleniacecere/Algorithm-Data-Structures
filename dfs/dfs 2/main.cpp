#include<iostream>
#include<vector>
#include <list>
#include<queue>
#include<cstdint>

#include"nodo.h"
#include "vertice.h"
#include"grafo.h"

using namespace std;

int main(){
  Grafo<string> myGrafo;
  
  Vertice<string>a("A");
  Vertice<string>b("B");
  Vertice<string>c("C");
  Vertice<string>d("D");
  Vertice<string>e("E");
  Vertice<string>f("F");
  
  
  myGrafo.addNodo(Nodo<string>( &a));
  myGrafo.addNodo(Nodo<string>( &b));
  myGrafo.addNodo(Nodo<string>( &c));
  myGrafo.addNodo(Nodo<string>( &d));
  myGrafo.addNodo(Nodo<string>( &e));
  myGrafo.addNodo(Nodo<string>( &f));
  
  myGrafo.addArco(0, &a);
  myGrafo.addArco(0, &e);
  myGrafo.addArco(1, &f);
  myGrafo.addArco(1, &b);
  myGrafo.addArco(3, &c);
  myGrafo.addArco(4, &d);
  
  queue<Vertice<string>*> coda;
  coda.push(&a);
  cout<<"pre dfs"<<endl;
  cout<<myGrafo<<endl;
  
  cout<<"post dfs"<<endl;
  myGrafo.dfs();
  cout<<myGrafo<<endl;
  
  return 0;
}
