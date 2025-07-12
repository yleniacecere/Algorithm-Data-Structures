#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include "nodo.h"
#include "vertice.h"

using namespace std;

template<typename T>
class Grafo{
private:
    vector<Nodo<T>> grafo;

    list<Vertice<T>*> getListAdj(Vertice<T>* vertice);
    int time;
    stack<Vertice<T>*> finishingStack;

    void dfsVisit(Vertice<T>* vertice);
    void dfsVisitCollect(Vertice<T>* vertice, vector<T>& component);

public:
    Grafo() {}

    int searchIndirizzo(Vertice<T>* vertice);
    Vertice<T>* getIndirizzoVertice(T value);
    void addNodo(Vertice<T>* vertice);
    void addArco(Vertice<T>* v1, Vertice<T>* v2);

    void dfs();
    vector<vector<T>> findSCCs();
    Grafo<T> getTrasposto();

    friend ostream& operator<<(ostream& out, const Grafo<T>& obj){
        for(auto i: obj.grafo)
            out << i << endl;
        return out;
    }
};

// Cerca indice nodo nel vettore
template<typename T>
int Grafo<T>::searchIndirizzo(Vertice<T>* vertice){
    for(int i=0; i<grafo.size(); i++){
        if(this->grafo.at(i).getVertice()->getValue() == vertice->getValue())
            return i;
    }
    return -1;
}

// Trova indirizzo vertice dato il valore
template<typename T>
Vertice<T>* Grafo<T>::getIndirizzoVertice(T value){
    for(auto i: grafo){
        if(i.getVertice()->getValue() == value)
            return i.getVertice();
    }
    return nullptr;
}

// Aggiunge un nodo se non esiste già
template<typename T>
void Grafo<T>::addNodo(Vertice<T>* vertice){
    if(searchIndirizzo(vertice) == -1)
        grafo.push_back(Nodo<T>(vertice));
}

// Aggiunge un arco
template<typename T>
void Grafo<T>::addArco(Vertice<T>* v1, Vertice<T>* v2){
    int idx = searchIndirizzo(v1);
    grafo.at(idx).append(v2);
}

// Ritorna lista adiacenza di un vertice
template<typename T>
list<Vertice<T>*> Grafo<T>::getListAdj(Vertice<T>* vertice){
    for(auto i: grafo){
        if(i.getVertice() == vertice)
            return i.getList();
    }
    return {};
}

// Prima DFS per ottenere finishing times
template<typename T>
void Grafo<T>::dfs(){
    for(auto u: grafo){
        u.getVertice()->setColor(Color::WHITE);
        u.getVertice()->setPredecessore(nullptr);
    }
    time=0;
    finishingStack = stack<Vertice<T>*>();
    for(auto u: grafo){
        if(u.getVertice()->getColor() == Color::WHITE)
            dfsVisit(u.getVertice());
    }
}

template<typename T>
void Grafo<T>::dfsVisit(Vertice<T>* vertice){
    vertice->setColor(Color::GREY);
    vertice->setTInizio(time++);
    for(auto v : getListAdj(vertice)){
        if(v->getColor() == Color::WHITE){
            v->setPredecessore(vertice);
            dfsVisit(v);
        }
    }
    vertice->setColor(Color::BLACK);
    vertice->setTFine(time++);
    finishingStack.push(vertice);
}

// Crea grafo trasposto
template<typename T>
Grafo<T> Grafo<T>::getTrasposto(){
    Grafo<T> trasposto;
    // Crea i nodi
    for(auto nodo : grafo){
        Vertice<T>* v = new Vertice<T>(nodo.getVertice()->getValue());
        trasposto.addNodo(v);
    }
    // Inverti archi
    for(auto nodo : grafo){
        Vertice<T>* from = nodo.getVertice();
        for(auto to : nodo.getList()){
            Vertice<T>* vFrom = trasposto.getIndirizzoVertice(to->getValue());
            Vertice<T>* vTo = trasposto.getIndirizzoVertice(from->getValue());
            trasposto.addArco(vFrom, vTo);
        }
    }
    return trasposto;
}

// Visita DFS che raccoglie i vertici in una componente
template<typename T>
void Grafo<T>::dfsVisitCollect(Vertice<T>* vertice, vector<T>& component){
    vertice->setColor(Color::GREY);
    component.push_back(vertice->getValue());
    for(auto v : getListAdj(vertice)){
        if(v->getColor() == Color::WHITE){
            dfsVisitCollect(v, component);
        }
    }
    vertice->setColor(Color::BLACK);
}

// Trova tutte le SCC
template<typename T>
vector<vector<T>> Grafo<T>::findSCCs(){
    vector<vector<T>> sccs;

    // 1. Prima DFS sul grafo originale
    dfs();

    // 2. Trasposto
    Grafo<T> trasposto = getTrasposto();

    // 3. Inizializza colori
    for(auto u: trasposto.grafo){
        u.getVertice()->setColor(Color::WHITE);
    }

    // 4. DFS sul trasposto in ordine decrescente finishing time
    while(!finishingStack.empty()){
        Vertice<T>* v = trasposto.getIndirizzoVertice(finishingStack.top()->getValue());
        finishingStack.pop();
        if(v->getColor() == Color::WHITE){
            vector<T> component;
            trasposto.dfsVisitCollect(v, component);
            sccs.push_back(component);
        }
    }

    return sccs;
}

#endif

