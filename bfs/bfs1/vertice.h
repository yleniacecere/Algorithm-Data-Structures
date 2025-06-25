#ifndef VERTICE_H //guardia d'incusione(impedisce la doppia inclusione)se vertice non è gia definito ,lo definisce ed esegue il codice sottostante
#define VERTICE_H

#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

//definisce enum per i colori
enum class Color {
    WHITE, GRAY, BLACK
};

template <typename T>
class Vertice { //classe per supportare qualsiasi tipo di valore T nel nodo
    private:
      T value; // valore del vertice
      Color color; //traccia dello stato del vertice
      Vertice<T>* predecessore; //puntatore al vertice precedente
      int distanza; //per visita bfs
    public:
      Vertice(T value);//dichiarazione costruttore che inizializza un vertice con valore T
      
      //modificano i valori delle variabili membro
      void setValue(T value) {this->value = value; }
      void setColor(Color color) {this->color = color; }
      void setDistanza(int distanza) {this->distanza = distanza; }
      void setPredecessore(Vertice<T>* predecessore) {this->predecessore = predecessore; }
      
      //restituiscono i valori delle variabili membro
      T getValue() {return this->value; }
      Color getColor() {return this ->color; }
      Vertice<T>* getPredecessore() {return this->predecessore; }
      int getDistanza() {return this->distanza; }
      
      //operatore di output
      // converte il colore da enum a una stringa leggibile
      //stampa il valore e colore del vertice
      friend ostream& operator<<(ostream& out, const Vertice<T>& obj){
          string c;
          switch(obj.color){
            case Color::WHITE: c = "WHITE"; break;
            case Color::GRAY: c = "GRAY"; break;
            case Color::BLACK: c = "BLACK"; break;
            default: break;
          }
          out << "Value ->" << obj.value << ", Color ->" << c << endl; 
          return out;
      }
      //due vertici sono considersti uguali se hanno lo stesso valore
      friend bool operator==(const Vertice<T>& a, const Vertice<T>& b){
        return a.value == b.value;
      }
};
template <typename T>
Vertice<T>::Vertice(T value) {
    this->value = value;
    this->color = Color::WHITE;
    this->predecessore = nullptr;
    this->distanza = UINT16_MAX; //rappresenta infinito
}

#endif //VERTICE_H



