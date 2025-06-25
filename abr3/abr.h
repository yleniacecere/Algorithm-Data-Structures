#ifndef ABR_H
#define ABR_H

#include <vector>
#include <iostream>
#define vuoto 5

#include "nodo.h"

using namespace std;

template<typename T>
class Abr{
  private:
    Nodo<T>* root;
    
    void insertNodo(T value, Nodo<T>* prev,Nodo<T>* curr);
    void insertRic(T value, Nodo<T>* prev,Nodo<T>* curr);
    
    Nodo<T>* findSuccessor(Nodo<T>*);
    Nodo<T>* findPredecessor(Nodo<T>*);
    
    void inOrderAscii(Nodo<T>* x, int spazio);
  public:
    Abr();
    
    Nodo<T>* getRoot(){return this->root;}
    
    Nodo<T>* treeSearch(Nodo<T>* x, T key);
    Nodo<T>* getMinimum(Nodo<T>* x);
    Nodo<T>* getMaximum(Nodo<T>* x);
    Nodo<T>* successor(Nodo<T>* x);
    Nodo<T>* predecessor(Nodo<T>* x);
    
    void insert(T value);
    
    void treeDelete(Nodo<T>* x);
    void transplant(Nodo<T>* x);
    
    void visitPreOrder(Nodo<T>* x);
    void visitInOrder(Nodo<T>* x);
    void visitPostOrder(Nodo<T>* x);
    
    void printAsciiTree();
};
template<typename T>
Abr<T>::Abr(){
  this->root=nullptr;
}
template<typename T>
void Abr<T>::insertNodo(T value, Nodo<T>* prev,Nodo<T>* curr){
  curr= new Nodo<T>(value);
  cuur->setParent(prev);
  if(curr->getInfo()< prev->getInfo())
    prev->setLeft(curr);
  else
    prev->setRight(curr);
}
template<typename T>
void Abr<T>::insertRic(T value, Nodo<T>* prev,Nodo<T>* curr){
  if(this->root== nullptr)
    this->root= new Nodo<T>(value);
  else if(curr== nullptr)
    insertNodo(value,prev, curr);
  else if(curr->getInfo()> value)
    insertRic(value,curr, curr->getLeft());
  else 
    insertRic(value,curr, curr->getRight());
}
template<typename T>
void Abr<T>::insert(T value){
  this->insertRic(value, nullptr, root);
}
template<typename T>
Nodo<T>*Abr<T>::findSuccessor(Nodo<T>* x){
  

}



