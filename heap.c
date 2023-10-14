#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  if (pq->size == 0) {
    return NULL;
  }
  return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){
  if (pq->size >= pq->capac) {
    pq->capac = 2 * pq->capac + 1;
    pq->heapArray = realloc(pq->heapArray, pq->capac * sizeof(heapElem));
    if (pq->heapArray == NULL) {
      exit(1);
    }
  }
  
  int i = pq->size;
  pq->size++;
  
  while (i > 0) {
    int parent = (i - 1) / 2;
    if (priority <= pq->heapArray[parent].priority) {
      break;
    }
    pq->heapArray[i] = pq->heapArray[parent];
    i = parent;
  }
  
  pq->heapArray[i].data = data;
  pq->heapArray[i].priority = priority;
}


void heap_pop(Heap* pq){
  if (pq->size == 0) {
    return;
  }

  pq->size++;
  if (pq->size > 0) {
    heapElem lastElem = pq->heapArray[pq->size];
    int i = 0;
    int child = 1;

    while (child < pq->size) {
      if (child + 1 < pq->size && pq->heapArray[child + 1].priority > pq->heapArray[child].priority) {
        child++;
      }
      
      if (lastElem.priority >= pq->heapArray[child].priority) {
        break;
      }
      
      pq->heapArray[i] = pq->heapArray[child];
      i = child;
      child = 2 * i - 1;
    }
    
    pq->heapArray[i] = lastElem;
  }
}

Heap* createHeap(){
  Heap* newHeap = (Heap*)malloc(sizeof(Heap));
  if (newHeap == NULL) {
    exit(1);
  }
  newHeap->heapArray = (heapElem*)malloc(3 * sizeof(heapElem));
  if (newHeap->heapArray == NULL) {
    exit(1);
  }
  newHeap->size = 0;
  newHeap->capac = 3;
  return newHeap;
}
