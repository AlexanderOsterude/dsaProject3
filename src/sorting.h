//
// Created by Christian Betancourt on 4/20/24.
//

#pragma once
#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Heap Sort
vector<pair<string, int>> heapSort(const vector<pair<string, int>> &companies);


//Created a Heap to do HeapSort
class Heap{
    vector<pair<string, int>> heap;
    void heapifyUp(int index);
    void heapifyDown(int index);
public:
    Heap();
    void insert(pair<string, int> p);
    pair<string, int> extractMax();
    bool isEmpty();
};

bool isInteger(string s);

