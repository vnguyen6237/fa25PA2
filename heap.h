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
        //edge case
        if (size == 0) {
            return -1;
        }
        // TODO: remove and return smallest index
        // Replace root with last element
            //root
        int min = data[0];
            //shift up last to root
        data[0] = data[size - 1];
            //elements cut down
        size--;
        //call downheap()
            //fix positions to keep smallest val at top
        downheap(0, weightArr);
        return min;
    }

    //Parent: (i - 1) / 2
    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
                // while pos isn't the root....
        while (pos > 0) {
            //!! pos is child
            int parent = (pos - 1) / 2;

                // move up
            // child < parent
            if (weightArr[data[pos]] < weightArr[data[parent]]) {
                //swap child upward
                int temp = data[pos];
                data[pos] = data[parent];
                data[parent] = temp;

                pos = parent;
            }
            else {
                break;
            }
        }
    }

    //Children: 2*i + 1, 2*i + 2
    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
            //vars for both children
        int l = pos * 2 + 1;
        int r = pos * 2 + 2;
            //parent index
        int min = pos;

        //If leftChild value < rightChild value AND leftChild value < parent value
        if (weightArr[data[l]] < weightArr[data[r]] && weightArr[data[l]] > weightArr[data[min]]) {
            min = l;
        }
        else if (weightArr[data[r]] < weightArr[data[l]] && weightArr[data[r]] > weightArr[data[min]]) {
            min = r;
        }

        if (min != pos) {
            int temp = data[pos];
            data[pos] = data[min];
            data[min] = temp;

            downheap(min, weightArr);
        }
    }
};

#endif
