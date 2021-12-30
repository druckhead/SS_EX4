/**
 * @file main.c
 * @author daniel raz (https://github.com/druckhead)
 * @brief
 * @version 0.1
 * @date 2021-12-21
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "nodes.h"
#include "edges.h"
#include "graph.h"

int main(void)
{
    char ch = 0;
    char ch2 = 0;
    // int n_cnt = 0;
    
    pnode graph;
    graph = NULL;
    while ((ch = getchar()) != '\n')
    {
        if (isupper(ch2))
        {
            ch = ch2;
            ch2 = 0;
        }
        switch (ch)
        {
        case 'A':
            ch2 = 0;
            graph_init(&graph);
            while (!isupper((ch2 = getchar())))
            {

            }
            break;
        case 'B':
        /*
        ?   TODO : check if node exists, if so delete all destinations
        ?       and update to new ones.
        !   DO NOT delete edges that are coming into node 
        */
            // add_node(g);
            break;
        case 'D':
        /*
        ! free incoming and outgoing edges
        */
            // del_node(g);
            break;
        case 'S':
            // shortest_path(g);
            break;
        case 'T':
            // tsp(g);
            break;
        }
    }
    if (graph)
    {
        free(graph);
    }
}