 
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
    string myFileInput = "fileprova.txt";
    string line;
    ofstream output;
    string myFileOutput = "fileOutput.txt";

    int i = 0;
    int num_vertici=0, num_archi=0, vertice, arco;

    
    file.open(myFileInput);
    if(!file.is_open()){
      cerr<<"errore apertura file"<<endl;
        return 1;
    }
    output.open(myFileOutput);
    if (!output.is_open()) {
        cerr << "Errore apertura file output" << endl;
        return 1;
    }


    while(getline(file, line)) {
        stringstream lineIn(line);
        if(i == 0) {
            lineIn >> num_vertici;
            lineIn >> num_archi;
            i++;
        } else {
            lineIn >> vertice;
            lineIn >> arco;

              Vertice<int>* v1 = myGrafo.getIndirizzoVertice(vertice);
  if (v1 == nullptr) {
      v1 = new Vertice<int>(vertice);
      myGrafo.addNodo(Nodo<int>(v1));
  }

  Vertice<int>* v2 = myGrafo.getIndirizzoVertice(arco);
  if (v2 == nullptr) {
      v2 = new Vertice<int>(arco);
      myGrafo.addNodo(Nodo<int>(v2));
  }

  myGrafo.addArco(v1, v2);

            
            
        }
    }

    file.close();

    cout<<"Grafo caricato"<<myGrafo<<endl;
       
    //Applico la DFS
    cout << "eseguo ordinamento topololgico"<<endl ;
    
    if(!myGrafo.dfs()){
    
      streambuf* oldCout = cout.rdbuf();
      cout.rdbuf(output.rdbuf());
      
      myGrafo.printOrdTopologico();
      
      cout.rdbuf(oldCout);
    }else{
    
      cout<<"sono presenti cicli, impossibile ordinamento topologico"<<endl;
    }
    


    output.close();

    return 0;
}






