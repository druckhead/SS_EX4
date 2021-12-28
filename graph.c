/**
 * @file graph.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-12-28
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <stdlib.h>
#include <stdio.h>

#include "graph.h"
#include "nodes.h"
#include "edges.h"

#include <ctype.h>

void graph_init(graph *head)
{
    int V = 0;
    int src = 0, dest = 0, weight = 0;
    scanf("%d", &V);
    head->size = V;
    head->vertices = malloc(V * sizeof(edge_list));
    for (int i = 0; i < V; i++)
    {
        head->vertices[i].neighbors = NULL;
    }
    getchar(); getchar(); getchar();
    char ch = 0;
    int cnt = 0;

    while(ch !='\n'){
        if (ch == 'n')
        {
            cnt = 0;
        }
        
        if (cnt)
        {
            scanf("%c",&ch);
        }
        else{
            scanf("%d %d", &dest, &weight);
        }
        cnt++;
    }
    
}
// void del_init_graph(graph *head)
// {

// }

// void add_node(graph *head)
// {
// }
// void del_node(graph *head)
// {
// }

// void shortest_path(graph *head)
// {
// }
// void tsp(graph *head)
// {
// }