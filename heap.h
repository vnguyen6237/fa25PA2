//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    //heap storage
    int data[64];
    //curr elements
    int size;

    MinHeap() {
        //starting with an empty heap
        size = 0;
    }

    void push(int idx, int weightArr[]) {
        // TODO:
        // insert index at end of heap
        data[size] = idx;
        //restore order using upheap()
        upheap(size, weightArr);
        size++;
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element

        //call downheap()
        return -1; // placeholder
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
    }
};

#endif
