#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "abr.h"
#include "nodo.h"

using namespace std;

int main() {
  Abr<int> myAbr;
  
  ifstream myFile("fileInput.txt");
  if(!myFile){
    cerr<<"Errore apertura file"<<endl;
    return -1;
  }
  int num;
  while(myFile>>num){
    myAbr.insert(num);
  }
  myFile.close();
  
  myAbr.printAsciiTree();
  
  
    cout << "L'elemento radice è:  " << myAbr.getRoot()->getInfo() << endl;
    cout << "L'elemento massimo è:  " << myAbr.getMaximum(myAbr.getRoot())->getInfo() << endl;
    cout << "L'elemento minimo è:  " << myAbr.getMinimum(myAbr.getRoot())->getInfo() << endl;

    cout << "VISITA PRE-ORDER" << endl;
    myAbr.visitPreOrder(myAbr.getRoot());

    cout << endl;
    cout << "VISITA IN-ORDER" << endl;
    myAbr.visitInOrder(myAbr.getRoot());

    cout << endl;
    cout << "VISITA POST-ORDER" << endl;
    myAbr.visitPostOrder(myAbr.getRoot());
    
    cout<<endl;
    Nodo<int>* nodo= myAbr.treeSearch(myAbr.getRoot(),14);
    
    cout << "Il successore nell'ABR di [" << nodo->getInfo() << "] è:  " << myAbr.successor(nodo)->getInfo() << endl;
    cout << "Il predecessore nell'ABR di [" << nodo->getInfo() << "] è:  " << myAbr.predecessor(nodo)->getInfo() << endl;

    cout << "Elimino il nodo [" << nodo->getInfo() << "] .. " << endl;

    myAbr.treeDelete(nodo);
    
     myAbr.printAsciiTree();
  
  
    cout << "L'elemento radice è:  " << myAbr.getRoot()->getInfo() << endl;
    cout << "L'elemento massimo è:  " << myAbr.getMaximum(myAbr.getRoot())->getInfo() << endl;
    cout << "L'elemento minimo è:  " << myAbr.getMinimum(myAbr.getRoot())->getInfo() << endl;

    cout << "VISITA PRE-ORDER" << endl;
    myAbr.visitPreOrder(myAbr.getRoot());

    cout << endl;
    cout << "VISITA IN-ORDER" << endl;
    myAbr.visitInOrder(myAbr.getRoot());

    cout << endl;
    cout << "VISITA POST-ORDER" << endl;
    myAbr.visitPostOrder(myAbr.getRoot());
    
    return 0;
    

}
