#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <iostream>
#include <vector>

#define vuoto 5

using namespace std;

template <typename T>
class MaxHeap {
    private:
        vector<T>* tree;
        int heapSize;

        int left(int i) { return (2*i)+1; }
        int right(int i) { return (2*i)+2; }

        void buildMaxHeap();
    protected:
        int parent(int i) { return (i-1)/2; }

        T getRoot() { return this->tree->at(0); }
        T getTail() { return this->tree->at(heapSize-1); }

        void setTree(int i, T key) { this->tree->at(i) = key; }
        vector<T>* getTree() { return this->tree; }

        void setHeapSize(int heapSize) { this->heapSize = heapSize; }
        int getHeapSize() { return this->heapSize; }

        void swap(T& a, T& b);
        void maxHeapify(int i);
    public:
        MaxHeap(vector<T>* tree);
        MaxHeap();
        ~MaxHeap();

        void insert(T x);

        void printTree();
        void inOrderAscii(int i, int spazio);
        void printAsciiTree();
};

template <typename T>
MaxHeap<T>::MaxHeap(vector<T>* tree) {
    this->tree = tree;
    this->heapSize = this->tree->size();
    buildMaxHeap();
}

template <typename T>
MaxHeap<T>::MaxHeap() {
    this->tree = new vector<T>;
    this->heapSize = 0;
}

template <typename T>
MaxHeap<T>::~MaxHeap() {
    delete tree;
}

template <typename T>
void MaxHeap<T>::swap(T& a, T& b) {
    int tmp; tmp = a; a = b; b = tmp;
}

template <typename T>
void MaxHeap<T>::maxHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int max = i;

    if(l < heapSize && this->tree->at(max) < this->tree->at(l))
        max = l;
    if(r < heapSize && this->tree->at(max) < this->tree->at(r))
        max = r;
    if(max != i) {
        swap(this->tree->at(i), this->tree->at(max));
        maxHeapify(max);
    }
}

template <typename T>
void MaxHeap<T>::buildMaxHeap() {
    for(int i = heapSize/2; i >= 0; i--)
        maxHeapify(i);
}

template <typename T>
void MaxHeap<T>::insert(T x) {
    heapSize++;
    this->tree->push_back(x);
    int i = heapSize-1;
    while(i != 0 && this->tree->at(parent(i)) < this->tree->at(i)) {
        swap(this->tree->at(i), this->tree->at(parent(i)));
        i = parent(i);
    }
}

template <typename T>
void MaxHeap<T>::printTree() {
    cout << "Printing Tree:" << endl;
    for(int i = 0; i < heapSize; i++)
        cout << this->tree->at(i) << "  ";
}

template <typename T>
void MaxHeap<T>::inOrderAscii(int i, int spazio) {
    if(i >= heapSize)
        return;
    spazio += vuoto;
    inOrderAscii(right(i), spazio);
    cout << endl;
    for(int i = vuoto; i < spazio; i++)
        cout << "  ";
    cout << this->tree->at(i) << endl;
    inOrderAscii(left(i), spazio);
}

template <typename T>
void MaxHeap<T>::printAsciiTree() {
    cout << "Printing Ascii Tree:" << endl;
    inOrderAscii(0, 0);
}

#endif //MAXHEAP_H
