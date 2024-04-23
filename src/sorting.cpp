//
// Created by Christian Betancourt on 4/20/24.
//
#include "sorting.h"


vector<pair<string, int>> heapSort(const vector<pair<string, int>> &companies) {
    //Create a heap object
    Heap h;
    //Create a pair placeholder to push into the heap
    pair<string, int> p;
    //for each element in the vector, push that into the heap
    for (auto company: companies){
        p = company;
        h.insert(p);
    }
    // res will hold the sorted vector of pairs, in descending order
    vector<pair<string, int>> res = {};
    // while the heap is not empty, keep extracting values
    while (!h.isEmpty()){
        res.push_back(h.extractMax());
    }
    return res;

}

// for main file, to check if user input contains anything that is not integers.
//This was done to then the number of elements they want to display can be turned into an int
bool isInteger(string s) {
    for (auto c: s){
        if (!isdigit(c))
            return false;
    }
    return true;
}

//Internal components for Heap. HeapifyUp is when inserting elements
void Heap::heapifyUp(int index) {
    int parent = (index - 1) / 2;
    // while the index is greater than 0 and the parent is less than child, swap em.
    while (index > 0 && heap[parent].second < heap[index].second){
        swap(heap[parent], heap[index]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

//For deleting elements
void Heap::heapifyDown(int index) {
    //taken directly from my programming quiz for heaps and adapted for project :)
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int size = heap.size();
    if (index >= heap.size())
        return;
    // if both children exist and the left child greater than right and parent, swap left w parent
    if (left <= size - 1 && right <= size - 1 && heap[left].second > heap[right].second
    && heap[left].second > heap[index].second){
        swap(heap[left], heap[index]);
        index = left;
        heapifyDown(index);
    }
    // if both children exist, and right is greater than left and parent, swap right w parent
    else if (left <= size - 1 && right <= size - 1 && heap[left].second < heap[right].second
    && heap[right].second > heap[index].second){
        swap(heap[right], heap[index]);
        index = right;
        heapifyDown(index);
    }
    // if only left child exists and is greater than parent, swap them
    else if (left<= size - 1 && right > size - 1 && heap[left].second > heap[index].second){
        swap(heap[left], heap[index]);
        return;
    }
    //else if only right child exists and is greater than parent, swap em
    else if (left > size - 1 && right <= size - 1 && heap[right].second > heap[index].second){
        swap(heap[right], heap[index]);
        return;
    }
    // else, either neither exists nor neither is greater, we are done here.
    else{
        return;
    }
}

//insert value into the heap
void Heap::insert(pair<string, int> p) {
    heap.push_back(p);
    //grab element and heapify it up
    heapifyUp(heap.size() - 1);
}

pair<string, int> Heap::extractMax() {
    //edge case in case the heap is empty
    if (heap.empty()){
        cout << "Heap is empty. No values to extract." << endl;
        return make_pair("", -1);
    }
    //grab the value
    pair<string, int> p = heap[0];
    //pass the last value to the top
    heap[0] = heap[heap.size() - 1];
    //delete the last one (since now there are two)
    heap.pop_back();
    //HEAPIFY IT DOWN BABY YEAH
    heapifyDown(0);
    return p;
}

bool Heap::isEmpty() {
    return heap.empty();
}

Heap::Heap() {
    heap = {};
}
