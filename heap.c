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
    return NULL;
}



void heap_push(Heap* pq, void* data, int priority){

}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
  Heap* newHeap = (Heap*)malloc(sizeof(Heap));
  if (newHeap == NULL) {
    fprintf(stderr, "No se pudo asignar memoria para Heap\n");
    exit(1);
  }
  newHeap->heapArray = (heapElem*)malloc(3 * sizeof(heapElem));
  if (newHeap->heapArray == NULL) {
    fprintf(stderr, "No se pudo asignar memoria para heapArray\n");
    exit(1);
  }
  newHeap->size = 0;
  newHeap->capac = 3
  return newHeap;
}
