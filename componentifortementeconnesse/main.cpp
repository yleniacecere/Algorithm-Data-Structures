#include "grafo.h"
#include "vertice.h"
#include "nodo.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>

using namespace std;

int main(){
    Grafo<int> g;

    ifstream file("input.txt");
    string line;
    int i=0;
    int nVertici=0, nArchi=0;
    int from, to;

    unordered_map<int, Vertice<int>*> verticiMap;

    while(getline(file, line)){
        stringstream ss(line);
        if(i==0){
            ss >> nVertici >> nArchi;
            i++;
        } else {
            ss >> from >> to;

            if(verticiMap.find(from) == verticiMap.end()){
                verticiMap[from] = new Vertice<int>(from);
                g.addNodo(verticiMap[from]);
            }
            if(verticiMap.find(to) == verticiMap.end()){
                verticiMap[to] = new Vertice<int>(to);
                g.addNodo(verticiMap[to]);
            }

            g.addArco(verticiMap[from], verticiMap[to]);
        }
    }
    file.close();

    auto sccs = g.findSCCs();

    ofstream out("output.txt");
    out << "Componenti fortemente connesse:\n";
    for(auto comp : sccs){
        for(auto v : comp)
            out << v << " ";
        out << endl;
    }
    out.close();

    cout << "Scritte componenti fortemente connesse su output.txt\n";
    return 0;
}

