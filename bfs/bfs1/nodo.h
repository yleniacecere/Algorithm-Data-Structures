#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <vector>
#include <list>
#include "vertice.h"

using namespace std;

template<typename T>
class Nodo {
    private:
      Vertice<T>* vertice;//puntatore al vertice principale del nodo
      list<Vertice<T>*> listaAdiacenza;// lista di puntatori ai vertici adiacenti
    public:
      Nodo(Vertice<T>* vertice) {this->vertice = vertice; } //inizializza un nodo con un vertice pòrincipale e la lista di adiacenza parte vuota
      Vertice<T>* getVertice(){return this ->vertice; } //ritorna il vertice principale
      list<Vertice<T>*> getList() {return this->listaAdiacenza; }//ritorna la lista adiace
      
      void append(Vertice<T>* vertice);//aggiunge vertice alla lista
      
      //permette di stampare un nodo e la sua lista di adiacenza
      friend ostream& operator<<(ostream& out, const Nodo<T>& obj){
          out << *obj.vertice << "-->";
          for(auto i : obj.listaAdiacenza)
            out << *i << "-->";
          out<<"NULL";
          return out;
          }
      
};
//implementazione di append
template<typename T>
void Nodo<T>::append(Vertice<T>* vertice){
    listaAdiacenza.push_back(vertice);
}

