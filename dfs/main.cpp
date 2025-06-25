#include"vertice.h"
#include"nodo.h"
#include"grafo.h"

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

using namespace std;

int main() {

Grafo<int> myGrafo;

  ifstream file;
  string myFileInput="fileprova.txt";
  string line;
  ofstream output;
  string myFileOutput="fileOutput.txt";
  
  int i=0;
  int num_archi=0, num_vertici=0, vertice, arco;
  
  file.open(myFileInput);
  output.open(myFileOutput);
  
  while(getline(file,line)){
    stringstream lineIn(line);
    if(i==0){
      lineIn>>num_archi;
      lineIn>>num_vertici;
      i++;
    }else {
      lineIn>>arco;
      lineIn>>vertice;
      
      Vertice<int>* v1= new Vertice<int> (vertice);
      Vertice<int>* v2= new Vertice<int>(arco);
      
      
      if(myGrafo.searchIndirizzo(v1)==-1)
        myGrafo.addNodo(v1);
      if(myGrafo.searchIndirizzo(v2)==-1)
        myGrafo.addNodo(v2);
        
    myGrafo.addArco(myGrafo.getIndirizzoVertice(vertice),myGrafo.getIndirizzoVertice(arco));
    
    }
  
  }
  
  file.close();
  
  cout<<"grafo pre dfs"<<endl;
  cout<<myGrafo<<endl;
  
  cout<<"grafo post dfs"<<endl;
  myGrafo.dfs();
  cout<<myGrafo<<endl;
  
  auto u= myGrafo.getQueue();
  
  while(!u.empty()){
    output<<u.front()<<endl;
    u.pop();
  
  }
  output.close();
  return 0;
  
}

  
