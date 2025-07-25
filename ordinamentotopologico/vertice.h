#ifndef VERTICE_H 
#define VERTICE_H

#include<iostream>
#include <vector>
#include<list>


using namespace std;
enum class Color{
  WHITE,GREY,BLACK
};
template<typename T>
class Vertice{
  private:
    T value;
    Color color;
    Vertice<T>* predecessore;
    
    int tInizio;
    int tFine;
  public:
    Vertice(T value);
    
    void setValue(T value) { this->value = value; }
    void setColor(Color color) { this->color = color; }
    void setPredecessore(Vertice<T>* predecessore) { this->predecessore = predecessore; }
    void setTInizio(int tempoInizioVisita) { this->tInizio = tInizio; }
    void setTFine(int tempoFineVisita) { this->tFine= tFine; }

    T getValue() { return this->value; }
    Color getColor() { return this->color; }
    Vertice<T>* getPredecessore() { return this->predecessore; }
    int getTInizio() { return this->tInizio; }
    int getTFine() { return this->tFine; }
    
    friend ostream& operator<<(ostream& out, const Vertice<T>& obj) {
        string c;
        switch(obj.color) {
            case Color::WHITE: c = "WHITE"; break;
            case Color::GREY: c = "GRAY"; break;
            case Color::BLACK: c = "BLACK"; break;
        }
        out << "Valore ->  " << obj.value << ", Colore ->  " << c;
        return out;
    }

    friend bool operator==(const Vertice<T>& a, const Vertice<T>& b) {
        return a.value == b.value;
    }
};
template<typename T>
Vertice<T>::Vertice(T value){
  this->value=value;
  this->color=Color::WHITE;
  this->predecessore=nullptr;
  this->tInizio=0;
  this->tFine=0;
}
#endif
