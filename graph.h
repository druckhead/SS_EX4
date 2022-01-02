#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#ifndef __GRAPH__
#define __GRAPH__

#define INFINITY 99999999
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

char ch;
int num_vertex;
int num_edges;
int *visited;

typedef struct _node_ *pnode;

typedef struct _edge_
{
    int weight;
    pnode dest;
    struct _edge_ *next;
} edge, *pedge;

typedef struct _node_
{
    int id;
    int distance;
    pedge neighbours;
    struct _node_ *previous;
    struct _node_ *next;
} node, *pnode;

pnode head;
pnode tail;

#endif

void graph_init(pnode *head);
void add_node(pnode *head);
void del_node(pnode *head);
void unlink_neighbors(pnode *head, int nodeId);
void print_graph(pnode *head);
void delete_graph(pnode *head);
int dijkstra(pnode *head, int src, int dest);
void shortest_path(pnode *head);
void tsp(pnode *head);
void free_edges(pnode *head);