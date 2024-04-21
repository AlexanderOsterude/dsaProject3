//
// Created by Christian Betancourt on 4/20/24.
//
#include "sorting.h"


vector<pair<string, int>> heapSort(const vector<pair<string, int>> &companies) {
    //vector for priority queue
    Heap h;
    pair<string, int> p;
    for (auto company: companies){
        p = company;
        h.insert(p);
    }
    vector<pair<string, int>> res = {};
    while (!h.isEmpty()){
        res.push_back(h.extractMax());
    }
    return res;

}

bool isInteger(string s) {
    for (auto c: s){
        if (!isdigit(c))
            return false;
    }
    return true;
}


void Heap::heapifyUp(int index) {
    int parent = (index - 1) / 2;
    // while the index is greater than 0 and the parent is less than child, swap em.
    while (index > 0 && heap[parent].second < heap[index].second){
        swap(heap[parent], heap[index]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

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

void Heap::insert(pair<string, int> p) {
    heap.push_back(p);
    heapifyUp(heap.size() - 1);
}

pair<string, int> Heap::extractMax() {
    if (heap.empty()){
        cout << "Heap is empty. No values to extract." << endl;
        return make_pair("", -1);
    }
    pair<string, int> p = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    heapifyDown(0);
    return p;
}

bool Heap::isEmpty() {
    return heap.empty();
}

Heap::Heap() {
    heap = {};
}
