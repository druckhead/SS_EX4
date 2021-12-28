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

#include "nodes.h"
#include "edges.h"
typedef struct Graph
{
    int size;
    node_list vertices;
} graph;

void graph_init (graph *head);
void del_init_graph(graph *head);;

void add_node(graph *head);
void del_node(graph *head);

void shortest_path(graph *head);
void tsp(graph *head);

#endif