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
    graph *g = NULL;

    while ((ch = getchar()) != '\n')
    {
        switch (ch)
        {
        case 'A':
            if (g)
            {
                free(g);
                g = malloc(sizeof(graph));
                graph_init(g);
            }
            else
            {
                g = malloc(sizeof(graph));
                graph_init(g);
            }
            break;
        case 'B':
            // add_node(g);
            break;
        case 'D':
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
}