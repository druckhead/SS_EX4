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
#include <ctype.h>

#include "graph.h"

void graph_init(pnode *head)
{
    /*
    *  head node is passed by reference
    *  if (*head) is null then allocate mem & init vals
    ?  TODO: add the allocation of the rest of the graph data
    ! DON'T FORGET TO FREE ALL ALLOCATED MEMORY
    */
    // int src = 0, dest = 0, weight = 0;
    // char ch = 0;
    if (*head == NULL)
    {
        int V = 0;
        scanf("%d", &V);
        *head = malloc(V * sizeof(*head));
        (*head)->neighbours = NULL;
        (*head)->next = NULL;
    }
    else
    {
        /*
        *   the graph exists, so delete it (free all mem assosiated with it)
        *   & create new graph
        ?   free memory and create new graph
        */
       pnode ptr = *head;
       while(ptr)
       {
        //    (*head)
        ptr=ptr->next;
       }
    }
}

// void add_edge(pnode *head, int src, int dest, int weight)
// {
//     if (*head != NULL)
//     {
//         pnode *curr = (*head);
//         while ((*curr)->next != NULL)
//         {
//             if ((*curr)->id == src)
//             {
//                 pedge *h = (*curr)->neighbours;
//                 pedge *tmp = (*curr)->neighbours->next;
//                 edge *e = (edge*)malloc(sizeof(sizeof(edge*)));
//             }
//         }

//     }
// }

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