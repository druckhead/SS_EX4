#include "graph.h"

#ifndef __HEAP__
#define __HEAP__

typedef struct _minheap_
{
    int size;
    int capacity;
    pnode *vert_arr;
}min_heap;

typedef struct _minheap_ min_heap;
#endif

min_heap *create_heap(int capacity);
void add(min_heap *h, pnode *node);
void print(min_heap *h);
void heapify_bottom_top(min_heap *h, int index);
void heapify_top_bottom(min_heap *h, int parent_node);
pnode pop_min(min_heap *h);