#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

#include"maxHeap.h"
#include"maxPriorityQueue.h"

using namespace std;
int main(){
  MaxPriorityQueue<int> myQueue;
  
  ifstream myFile("fileInput.txt");
  if(!myFile){
    cerr<<"errore di apertura"<<endl;
    return -1;
  }
  
  int num;
  while(myFile>> num){
    myQueue.queueInsert(num);
  }
  
  myFile.close();
  
  
    myQueue.printTree();
    myQueue.printAsciiTree();

    cout << "\nMaximum element: " << myQueue.queueMaximum();

    myQueue.queueIncreaseKey(2, 60);
    cout << "\nAfter increasing key at index 2 to 40:";
    myQueue.printTree();
    myQueue.printAsciiTree();

    //int extractedMax = myQueue.queueExtractMax();
    cout << "\nExtracted max element: " << myQueue.queueExtractMax() << endl;
    cout << "\nHeap after extraction:";
    myQueue.printTree();
    myQueue.printAsciiTree();

}
