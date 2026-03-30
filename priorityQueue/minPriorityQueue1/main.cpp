
#include <iostream>
#include <vector>

#include "minHeap.h"
#include "minPriorityQueue.h"

using namespace std;

int main() {
  MinPriorityQueue<int > priorityQueue;
  
  priorityQueue.queueInsert(20);
  priorityQueue.queueInsert(10);
  priorityQueue.queueInsert(15);
  priorityQueue.queueInsert(5);
  priorityQueue.queueInsert(30);
  
  priorityQueue.printTree();
  priorityQueue.printAsciiTree();

  cout<<"elemento minimo"<<priorityQueue.queueMinimum();

  
  priorityQueue.queueDecreaseKey(2, 6);
  cout << "\nAfter decreasing key at index 2 to 6:";
  priorityQueue.printTree();
  priorityQueue.printAsciiTree();

  cout<<"elemento minimo estratto"<<priorityQueue.queueExtractMin() << endl;
  cout << "\nHeap after extraction:";
  priorityQueue.printTree();
  priorityQueue.printAsciiTree();



}
