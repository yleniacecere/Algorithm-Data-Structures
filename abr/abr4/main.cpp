#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "abr.h"
#include "nodo.h"

using namespace std;

int main(){

  Abr<int> myAbr;
  
  ifstream myFile("fileInput.txt");
  if(!myFile){
    cerr<<"errore apertura file"<<endl;
    return -1;
  }
  
  int num;
  while(myFile>>num){
    myAbr.insert(num);
  }
  myFile.close();
  myAbr.printAsciiTree();
  
  cout<<"la radice è"<<myAbr.getRoot()->getInfo()<<endl;
  cout<<"l'elemento massimo è" <<myAbr.getMaximum(myAbr.getRoot())->getInfo()<<endl;
  cout<<"l'elemento massimo è" <<myAbr.getMinimum(myAbr.getRoot())->getInfo()<<endl;
  
  cout<<"visita pre order"<<endl;
  myAbr.visitPreOrder(myAbr.getRoot());
  
  cout<<endl;
  cout<<"visita in order"<<endl;
  myAbr.visitInOrder(myAbr.getRoot());


  cout<<endl;
  cout<<"visita post order"<<endl;
  myAbr.visitPostOrder(myAbr.getRoot());
  
  cout<<endl;
  Nodo<int>* nodo = myAbr.treeSearch(myAbr.getRoot(),14);
  
  cout<<"il successore nell abr di ["<<nodo->getInfo()<<":]"<<myAbr.successor(nodo)->getInfo()<<endl;
  cout<<"il predecessore nell abr di ["<<nodo->getInfo()<<":]"<<myAbr.predecessor(nodo)->getInfo()<<endl;
  
  cout<<"elimino il nodo ["<<nodo->getInfo()<<"]"<<endl;
  myAbr.treeDelete(nodo);
  
  myAbr.printAsciiTree();
  
  cout<<"la radice è"<<myAbr.getRoot()->getInfo()<<endl;
  cout<<"l'elemento massimo è" <<myAbr.getMaximum(myAbr.getRoot())->getInfo()<<endl;
  cout<<"l'elemento massimo è" <<myAbr.getMinimum(myAbr.getRoot())->getInfo()<<endl;
  
  cout<<"visita pre order"<<endl;
  myAbr.visitPreOrder(myAbr.getRoot());
  
  cout<<endl;
  cout<<"visita in order"<<endl;
  myAbr.visitInOrder(myAbr.getRoot());

  cout<<endl;
  cout<<"visita post order"<<endl;
  myAbr.visitPostOrder(myAbr.getRoot());
  


return 0;








}
