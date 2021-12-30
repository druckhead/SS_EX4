/**
 * @file graph.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __GRAPH_H__
#define __GRAPH_H__

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
    pedge neighbours;
    struct _node_ *next;
} node, *pnode;



void graph_init (pnode *head);
void del_init_graph(pnode *head);;

void add_node(pnode *head);
void del_node(pnode *head);

void add_edge(pnode *head, int src, int dest, int weight);
// int is_edge(pnode *head, int src, int dest);

void shortest_path(pnode *head);
void tsp(pnode *head);

#endif