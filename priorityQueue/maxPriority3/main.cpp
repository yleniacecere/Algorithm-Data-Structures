#include <iostream>
#include <vector>
#include "maxHeap.h"
#include "maxPriorityQueue.h"

using namespace std;

int main() {
    MaxPriorityQueue<int> priorityQueue;

    priorityQueue.queueInsert(15);
    priorityQueue.queueInsert(10);
    priorityQueue.queueInsert(25);
    priorityQueue.queueInsert(5);
    priorityQueue.queueInsert(30);

    priorityQueue.printTree();
    priorityQueue.printAsciiTree();

    cout << "\nMaximum element: " << priorityQueue.queueMaximum();

    priorityQueue.queueIncreasePriority(2, 40);
    cout << "\nAfter increasing key at index 2 to 40:";
    priorityQueue.printTree();
    priorityQueue.printAsciiTree();

    //int extractedMax = priorityQueue.queueExtractMax();
    cout << "\nExtracted max element: " << priorityQueue.queueExtractMax() << endl;
    cout << "\nHeap after extraction:";
    priorityQueue.printTree();
    priorityQueue.printAsciiTree();


    return 0;
}

