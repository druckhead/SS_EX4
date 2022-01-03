#include "graph.h"
#include <stdlib.h>

int main()
{
    while (ch != '\n')
    {
        switch (ch)
        {
        case 'A':
            ch = getchar();
            num_vertex = 0;
            num_edges = 0;
            scanf("%d", &num_vertex);
            graph_init(&head);
            // print_graph(&head);
            break;
        case 'B':
            add_node(&head);
            // printGraph_cmd(&head);
            break;
        case 'D':
            del_node(&head);
            // printGraph_cmd(&head);
            break;
        case 'T':
            tsp(&head);
            break;
        case 'S':
            shortest_path(&head);
            break;
        }
        if (isalpha(ch))
            continue;
        if (ch == '\n')
            break;
        ch = getchar();
    }
    delete_graph(&head);
    return 0;
}