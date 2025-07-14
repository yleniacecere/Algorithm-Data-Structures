#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class HashElement{
  public:
    int value;
    char key;
    HashElement(char k, int v): key(k), value(v){}
};

class HashTable{
  private:
    vector<list<HashElement>> table;
    int size;
    int hash(char key)const {return static_cast<int>(key)% size; }
  public:
    explicit HashTable(int s): size(s){table.resize(size);}
    
    void insert(char key, int value){
      int index= hash(key);
      table[index].emplace_back(key, value);
    }
    
    void increase(char key){
    int index= hash(key) ;
      for( auto& element: table[index] ){
        if(element.key== key){
          element.value++;
          return ;
          }
      }
      insert(key,1);
    }
    
    void printToFile(const string& filename ){
      ofstream outputFile(filename);
      for(const auto& bucket: table){
        for(const auto element: bucket)
          outputFile<<"carattere"<<element.key
          <<"occorrenza"<<element.value<<endl;
      }
    outputFile.close();
    }
    
    int searchCharacter(char keyToSearch){
      int index= hash(keyToSearch);
      for(auto element: table[index]){
        if(element.key== keyToSearch){
          return element.value;
        }
      }
      return 0;
    }
    
    void removeCharacter(char keyToRemove){
      int index= hash(keyToRemove);
      auto& bucket= table[index];
      for(auto it=bucket.begin(); it!= bucket.end(); ++it){
        if(it->key==keyToRemove){
          bucket.erase(it);
          return;
        }  
      }
      }
        vector<list<HashElement>> getTable(){
        return table; 
    }
};

int main(){

  HashTable myHash(256);
  ifstream myFile("IN.txt");
  
  char ch;
  while(myFile.get(ch)){
    myHash.increase(ch);
  }
  myFile.close();
  
  myHash.printToFile("OUT.txt");
  
  cout<<"tabella hash"<<endl;
  for(const auto& bucket: myHash.getTable()){
    for(const auto& element: bucket)
      cout<<"carattere"<<element.key<<"occorrenza"<<element.value<<endl;
  }
  
  char searchChar; 
  cout<<"inserisci il carattere da cercare";
  cin>>searchChar;
  
  
  int occurrence=myHash.searchCharacter(searchChar);
  cout<<"occorrenza del carattere"<<searchChar<<":,"<<occurrence<<endl;  
  
  
  char removeChar; 
  cout<<"inserisci il carattere da rimuovere";
  cin>>removeChar;
  
  myHash.removeCharacter(removeChar);
  
  int occurrence1=myHash.searchCharacter(removeChar);
  if(occurrence1==0){
  cout<<"il carattere "<<removeChar<<"è stato rimosso"<<endl; 
  }else{
    cout<<"il carattere"<<removeChar<<"è ancora presente nella tabella con"<<occurrence1<<"occorrenza(e)"<<endl;
  }
  
    cout<<"tabella hash"<<endl;
  for(const auto& bucket: myHash.getTable()){
    for(const auto& element: bucket)
      cout<<"carattere"<<element.key<<"occorrenza"<<element.value<<endl;
  }
  
  return 0;
  
  


}
