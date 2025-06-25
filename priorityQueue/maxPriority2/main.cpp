#include<iostream>
#include<vector>
#include "maxHeap.h"
#include "maxPriorityQueue.h"

using namespace std;
int main(){
  MaxPriorityQueue<int> priorityQueue;
  
  
  priorityQueue.queueInsert(20);
  priorityQueue.queueInsert(5);
  priorityQueue.queueInsert(15);
  priorityQueue.queueInsert(30);
  priorityQueue.queueInsert(10);
  
  priorityQueue.printTree();
  priorityQueue.printAsciiTree();
  
  cout<<"massimo elemento"<< priorityQueue.queueMaximum();
  
  priorityQueue.queueIncreasePriority(2,40);
  cout<<"after increasing key at index 2 to 40 ";
  priorityQueue.printTree();
  priorityQueue.printAsciiTree();
  
  cout<<"extract max element:"<<priorityQueue.queueExtractMax();
  cout<<"heap after extraction";
   priorityQueue.printTree();
  priorityQueue.printAsciiTree();
  
  return 0;
  
  
  

}
