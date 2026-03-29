#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

#include"minHeap.h"
#include"minPriorityQueue.h"

using namespace std;
int main(){
  MinPriorityQueue<int> myQueue;
  
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

    cout << "\nMinimum element: " << myQueue.queueMinimum();

    myQueue.queueDecreaseKey(2, 60);
    cout << "\nAfter decreasing key at index 2 to 40:";
    myQueue.printTree();
    myQueue.printAsciiTree();

    //int extractedMax = myQueue.queueExtractMax();
    cout << "\nExtracted min element: " << myQueue.queueExtractMin() << endl;
    cout << "\nHeap after extraction:";
    myQueue.printTree();
    myQueue.printAsciiTree();

}
