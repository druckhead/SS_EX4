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
} graph, *p_node;

void graph_init (p_node *head);
void del_init_graph(p_node *head);;

void add_node(p_node *head);
void del_node(p_node *head);

void shortest_path(p_node *head);
void tsp(p_node *head);

#endif