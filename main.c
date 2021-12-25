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

// #define BUFF_SIZE 256

int main(int argc, char const *argv[])
{
    int flag = 1;
    char ch = 0;
    while (flag)
    {
        printf("A to create a graph\n");
        printf("B new Node\n");
        printf("D to delete node\n");
        printf("S for shortest path distance between two nodes\n");
        printf("T for TSP for n nodes\n");
        ch = getchar();
        ch = toupper(ch);
        system("clear");
        switch (ch)
        {
        case 'A':
            /* code */
            // graph_init();
            ch = getchar(); // clear newline
            break;
        case 'B':
            /* code */
            ch = getchar(); // clear newline
            break;
        case 'D':
            /* code */
            // int del_node = 0;
            // remove_node(del_node);
            ch = getchar(); // clear newline
            break;
        case 'S':
            // int src = 0, dest = 0;
            // shortest_path(src, dest);
            ch = getchar(); // clear newline
            break;
        case 'T':
            // int *nodes;
            // tsp(nodes);
            ch = getchar(); // clear newline
            break;

        default:
            printf("You have chosen %c.\n%c is not a valid option.\nPlease choose again...\n\n", ch, ch);
            ch = getchar(); // clear newline
            break;
        }
    }

    return 0;
}
